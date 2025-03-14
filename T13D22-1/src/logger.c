#include "logger.h"

FILE *log_init(char *filename) {
    FILE *log_file = fopen(filename, "a");
    return log_file;
}

void logcat(FILE *log_file, enum log_level level, char *message) {
    char status[10] = "";
    switch (level) {
        case debug:
            strcpy(status, "DEBUG");
            break;
        case info:
            strcpy(status, "INFO");
            break;
        case warning:
            strcpy(status, "WARNING");
            break;
        case error:
            strcpy(status, "ERROR");
            break;
    }
    time_t rawtime;
    time(&rawtime);
    struct tm *timeinfo = localtime(&rawtime);  // локальное представление
    char buffer[80];
    // Форматируем дату и время с помощью strftime
    strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y", timeinfo);
    fprintf(log_file, "%s %s %s\n", status, buffer, message);
}

void log_close(FILE *log_file) { fclose(log_file); }
