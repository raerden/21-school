#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define HEIGHT 25
#define WIDTH 80
#define MAX_DELAY 400000
#define MIN_DELAY 20000

void set_terminal(void);
int key_listener();
void startField(int field[HEIGHT][WIDTH]);
int sosedNum(int field[HEIGHT][WIDTH], int x, int y);
void newField(int now[HEIGHT][WIDTH], int next[HEIGHT][WIDTH]);
void printField(int field[HEIGHT][WIDTH], int genereation, int speed);

int main() {
    int nowField[HEIGHT][WIDTH] = {0};
    int nextField[HEIGHT][WIDTH] = {0};
    int speed = 100000;
    int generation = 0;

    startField(nowField);
    printField(nowField, generation, speed);

    struct termios stored_settings;
    if (tcgetattr(STDIN_FILENO, &stored_settings) == -1) {
        exit(1);
    }

    set_terminal();

    while (1) {
        generation++;
        printField(nowField, generation, speed);
        newField(nowField, nextField);

        if (key_listener()) {
            char c = getchar();
            if (c == 'q' || c == 'Q') {
                break;
            }
            if (c == 'z' && speed > MIN_DELAY) {
                speed -= 20000;
            }
            if (c == 'x' && speed < MAX_DELAY) {
                speed += 20000;
            }
        }

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                nowField[i][j] = nextField[i][j];
            }
        }

        usleep(speed);
    }

    // Восстанавливаем старые настройки терминала
    if (tcsetattr(STDIN_FILENO, TCSANOW, &stored_settings) == -1) {
        exit(1);
    }

    // Очищаем буфер ввода
    while (getchar() != '\n' && !feof(stdin)) {
    }

    return 0;
}

void set_terminal(void) {
    struct termios new_settings;
    tcgetattr(STDIN_FILENO, &new_settings);
    new_settings.c_lflag &= (~ICANON & ~ECHO);
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
}

int key_listener() {
    fd_set rfds;
    struct timeval tv;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    return select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv);
}

void startField(int field[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            field[i][j] = 0;
        }
    }
    char line[WIDTH + 1];
    for (int i = 0; i < HEIGHT; i++) {
        if (fgets(line, sizeof(line), stdin)) {
            for (int j = 0; j < WIDTH && line[j] != '\n'; j++) {
                if (line[j] == '*') {
                    field[i][j] = 1;
                } else {
                    field[i][j] = 0;
                }
            }
        } else {
            for (int j = 0; j < WIDTH; j++) {
                field[i][j] = 0;
            }
        }
    }
    if (freopen("/dev/tty", "r", stdin) == NULL) {
        return;
    };
}

int sosedNum(int field[HEIGHT][WIDTH], int x, int y) {
    int num = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int sosedX = (x + i + HEIGHT) % HEIGHT;
            int sosedY = (y + j + WIDTH) % WIDTH;
            if (field[sosedX][sosedY]) {
                num++;
            }
        }
    }
    return num;
}

void newField(int now[HEIGHT][WIDTH], int next[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int sosed = sosedNum(now, i, j);
            if (now[i][j]) {
                if (sosed < 2 || sosed > 3) {
                    next[i][j] = 0;
                } else {
                    next[i][j] = 1;
                }
            } else {
                if (sosed == 3) {
                    next[i][j] = 1;
                } else {
                    next[i][j] = 0;
                }
            }
        }
    }
}

void printField(int field[HEIGHT][WIDTH], int genereation, int speed) {
    printf("\033[H\033[J");  // очистка экрана
    printf("\t\tGeneration = %d.  Speed delay = %d\n", genereation, speed);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (field[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\t\tKeys: 'q + enter' - quit. 'z' - speed++ 'x' - speed--\n");
}