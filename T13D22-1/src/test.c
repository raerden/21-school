#include <stdio.h>
#include <string.h>
#include <time.h>

#include "logger.h"

int main() {
    FILE *ff = fopen("test.txt", "a");
    char message[256] = "Try to append file: ";
    char dirname[20] = "testdir";
    strcat(message, dirname);
    logcat(ff, info, message);
    fclose(ff);
}
