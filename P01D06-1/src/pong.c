// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI
#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25

int Ball_x = WIDTH / 2;  // Стартовое положение мяча по центру игрового поля
int Ball_y = HEIGHT / 2;
int Ball_Speed_x = 1;
int Ball_Speed_y = 1;
int Player1_Score = 0;
int Player2_Score = 0;
int Player1_Pad = HEIGHT / 2 - 1;  // Стартовое положение ракетки по середине вертикали
int Player2_Pad = HEIGHT / 2 - 1;

void draw_game();
void new_round();
void calculate_movies();

int main() {
    draw_game();
    while (Player1_Score < 21 && Player2_Score < 21) {
        char key = getchar();

        if (key == ' ') calculate_movies();

        if ((key == 'a' || key == 'A') && Player1_Pad > 1)  // Передвинуть левую ракетку вверх
        {
            Player1_Pad--;
            calculate_movies();
        }

        if ((key == 'z' || key == 'Z') && Player1_Pad < HEIGHT - 4)  // Передвинуть левую ракетку вниз
        {
            Player1_Pad++;
            calculate_movies();
        }

        if ((key == 'k' || key == 'K') && Player2_Pad > 1)  // Передвинуть правую ракетку вверх
        {
            Player2_Pad--;
            calculate_movies();
        }

        if ((key == 'm' || key == 'M') && Player2_Pad < HEIGHT - 4)  // Передвинуть правую ракетку вниз
        {
            Player2_Pad++;
            calculate_movies();
        }

        draw_game();
    }

    if (Player1_Score > Player2_Score)
        printf("        Player 1 win!       ");
    else
        printf("        Player 2 win!       ");

    return 0;
}

void calculate_movies() {
    // Отражение мяча от верхней или нижней стенки
    if (Ball_y == 1 || Ball_y == HEIGHT - 2) Ball_Speed_y = -Ball_Speed_y;

    // Если положение мяча больше ширины экрана. Движение вправо ->.
    //  Проверить положение правой ракетки в точке X мяча.
    if (Ball_x == WIDTH - 1) {
        if (Ball_y >= Player2_Pad && Ball_y <= Player2_Pad + 2) {
            // Удар в ракетку
            // меняем направление движения мяча и смещаем обратно. чтобы не залез на ракетку
            Ball_Speed_x = -Ball_Speed_x;
        } else {  // Гол!
            Player1_Score++;
            new_round();
        }
    }

    // Если положение мяча меньше ширины экрана. Движение влево <-
    //  Проверить положение левой ракетки в точке X мяча.
    if (Ball_x == 1) {
        if (Ball_y >= Player1_Pad && Ball_y <= Player1_Pad + 2) {  // Удар в ракетку
            // меняем направление движения мяча
            Ball_Speed_x = -Ball_Speed_x;
        } else {  // Гол!
            Player2_Score++;
            new_round();
        }
    }

    // Меняем положение мяча
    Ball_x += Ball_Speed_x;
    Ball_y += Ball_Speed_y;
}

void new_round() {
    Ball_x = WIDTH / 2;  // Стартовое положение мяча по центру игрового поля
    Ball_y = HEIGHT / 2;
    Player1_Pad = HEIGHT / 2 - 1;  // Стартовое положение ракетки по середине вертикали
    Player2_Pad = HEIGHT / 2 - 1;
}

void draw_game() {
    int x, y;
    printf("\033[H");
    printf("                 Score %d", Player1_Score);
    printf("                  ");
    printf("                 Score %d\n", Player2_Score);
    for (x = 0; x <= WIDTH; x++) printf("-");
    printf("\n");

    for (y = 1; y <= HEIGHT - 2; y++) {
        for (x = 0; x <= WIDTH; x++) {
            if (x == Ball_x && y == Ball_y)
                printf("•");
            else if (x == 0 && (y >= Player1_Pad && y < Player1_Pad + 3))
                printf("]");
            else if (x == WIDTH && (y >= Player2_Pad && y < Player2_Pad + 3))
                printf("[");
            else if (x == 40)
                printf("|");  // середина поля
            else
                printf(" ");
        }
        printf("\n");
    }
    for (x = 0; x <= WIDTH; x++) printf("-");
    printf("\n");
}
