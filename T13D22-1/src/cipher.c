#include "cipher.h"
#ifdef LOG
#include "logger.h"
#endif

int main() {
    char ch;
    int menu_option = 0;
    char filename[256];
    FILE *log_file = NULL;
#ifdef LOG
    log_file = log_init("log_file.txt");
    logcat(log_file, info, "Starting programm");
#endif

    while (menu_option != -1) {
        if (scanf("%d", &menu_option) != 1) {
            clear_input_buffer();
            printf("n/a\n");
#ifdef LOG
            logcat(log_file, error, "Incorrect menu option. Only 1,2,3,-1 accepted");
#endif
            continue;
        }
        ch = getchar();
        if (ch != '\n' && ch != ' ') {
            printf("n/a\n");
#ifdef LOG
            logcat(log_file, error, "Incorrect menu option. End char");
#endif
            continue;
        }
        switch_menu_option(menu_option, filename, log_file);
    }

#ifdef LOG
    logcat(log_file, info, "End programm");
    if (log_file != NULL) log_close(log_file);
#endif
}

void encode_caesar_cfile(char *fname, int shift) {
    FILE *encodefile = fopen(fname, "r");
    FILE *tempfile = fopen("tempfile", "w");
    char ch;
    while ((ch = fgetc(encodefile)) != EOF) {
        fputc(caesar_encode_char(ch, shift), tempfile);
    }

    fclose(tempfile);
    fclose(encodefile);
    remove(fname);
    rename("tempfile", fname);
}

void caesar_encode(char *dirname, int shift, FILE *log_file) {
#ifdef LOG
    logcat(log_file, info, "Start Caesar encode files");
#endif
    if (dirname[strlen(dirname) - 1] != '/') strcat(dirname, "/");  // folder/fnma.c
    DIR *dr;
    // Открываем директорию
    dr = opendir(dirname);
    if (dr == NULL) {
        printf("n/a\n");
#ifdef LOG
        logcat(log_file, error, "Cant open dir for caesar encode");
#endif
    } else {
        struct dirent *de;
        while ((de = readdir(dr)) != NULL) {
            if (de->d_name[0] != '.' && strstr(de->d_name, ".c")) {
                char full_filepath[256] = "";
                strcat(full_filepath, dirname);
                strcat(full_filepath, de->d_name);  // folder/fn1.c
                encode_caesar_cfile(full_filepath, shift);
            }
        }
        closedir(dr);
#ifdef LOG
        logcat(log_file, info, "Caesar encode files is done");
#else
        if (log_file) log_file = NULL;
#endif
    }
}

void clean_files(char *dirname, char *mask) {
    if (dirname[strlen(dirname) - 1] != '/') strcat(dirname, "/");
    DIR *dr;
    // Открываем директорию
    dr = opendir(dirname);
    if (dr == NULL) {
        printf("n/a\n");
    } else {
        struct dirent *de;
        while ((de = readdir(dr)) != NULL) {
            if (de->d_name[0] != '.' && strstr(de->d_name, mask)) {
                char full_filepath[256] = "";
                strcat(full_filepath, dirname);
                strcat(full_filepath, de->d_name);
                FILE *file = fopen(full_filepath, "w");
                fclose(file);
            }
        }
        closedir(dr);
    }
}

void switch_menu_option(int menu_option, char *fname, FILE *log_file) {
    int shift;
    char ch;
    switch (menu_option) {
        case 1:
#ifdef LOG
            logcat(log_file, info, "Select menu option 1 - print file");
#endif
            scanf("%255s", fname);
            print_file(fname);
            break;

        case 2:
#ifdef LOG
            logcat(log_file, info, "Select menu option 2 - append to file");
#endif
            append_to_file(fname, log_file);
            break;

        case 3:
#ifdef LOG
            logcat(log_file, info, "Select menu option 3 - Caesar encode *.c files");
#endif
            printf("Enter directory path: ");
            scanf("%255s", fname);
            printf("Enter Caesar encode shift: ");
            if (scanf("%d%c", &shift, &ch) != 2 || (ch != ' ' && ch != '\n')) {
                printf("n/a\n");
            } else {
                caesar_encode(fname, shift, log_file);
                clean_files(fname, ".h");
            }
            break;

        case -1:
#ifdef LOG
            logcat(log_file, info, "Select menu option -1 - Exit from programm");
#endif
            break;

        default:
           // clear_input_buffer();
            printf("n/a\n");
            break;
    }
}

void clear_input_buffer() {  // очистить из буфера stdin весь мусор
    char ch;
    while ((ch = getchar()) != 10) {
    }
}

void print_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("n/a");
    } else {
        char ch;
        int empty_file = 1;
        while ((ch = fgetc(file)) != EOF) {  // читаю из файла по одному символу до символа конца файла
            putchar(ch);
            empty_file = 0;
        }
        fclose(file);
        if (empty_file) {
            printf("n/a");
        }
    }
    printf("\n");
}

void append_to_file(char *filename, FILE *log_file) {
#ifdef LOG
    logcat(log_file, info, "Try to append file");
#endif
    char buffer[1000] = "";
    char ch;
    int index = 0;
    while ((ch = getchar()) != '\n' && index < 1000) {  // набираем строку
        buffer[index] = ch;
        index++;
    }

    FILE *filestream = fopen(filename, "r");
    if (NULL == filestream) {
        printf("n/a\n");
#ifdef LOG
        logcat(log_file, error, "File not exists!");
#endif
    } else {
        fseek(filestream, 0, SEEK_END);  // переместиться на конец файла
        long file_size = ftell(filestream);
        if (file_size > 0) {
            fseek(filestream, -1, SEEK_END);
            ch = fgetc(filestream);  // считать последний символ файла.
        }
        fclose(filestream);
        FILE *filestream2 = fopen(filename, "a");
        if (ch != 10) fputc('\n', filestream2);  // Если последний символ не перенос строки до добавляем его
        for (int i = 0; i < index; i++) fputc(buffer[i], filestream2);

        fclose(filestream2);
        print_file(filename);
#ifdef LOG
        logcat(log_file, info, "Append to file is done");
#else
        if (log_file) log_file = NULL;
#endif
    }
}

char caesar_encode_char(char ch, int shift) {
    if (ch >= 'A' && ch <= 'Z') {
        ch = 'A' + (ch - 'A' + shift + 26) % 26;
        // ascii A - 101.
        // ch = 101 + (101 - 101 + 1 + 26) % 26
        //          101 + 27 % 26 = 101 + 1 = 102 (A shifted to B)
    } else if (ch >= 'a' && ch <= 'z') {
        ch = 'a' + (ch - 'a' + shift + 26) % 26;
    }
    return ch;
}