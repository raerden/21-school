#include <math.h>
#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(const char *str) {
    size_t len = 0;
    while (*str) {
        len++;
        str++;
    }
    return len;
}

char *s21_strchr(char *dest, char ch) {
    char *ptr = NULL;
    while (*dest != '\0') {
        if (*dest == ch) {
            ptr = dest;
            break;
        }
        dest++;
    }
    return ptr;
}

int main() {
    // char txt1[200];
    char txt1[20] = "hello";
    char *txt2 = "all";
    // printf("%s\n%s\n", txt1, txt2);
    char *res = s21_strchr(txt1, 'o');
    printf("%s\n", res);

    //    printf("str1=\nstr2=%s\nres=%s\n", txt2, s21_strcpy(txt1, txt2));

    return 0;
}
