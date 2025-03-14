#include "s21_string.h"

size_t s21_strlen(const char *str) {
    size_t len = 0;
    while (*str) {
        len++;
        str++;
    }
    return len;
}

int s21_strcmp(const char *str1, const char *str2) {
    int res;
    for (; *str1 && *str1 == *str2; str1++, str2++);
    if ((*str1 - *str2) > 0) {  // первая строка больше второй
        res = 1;  // т.к. последний символ первой строки больше символа второй строки
    } else if ((*str1 - *str2) < 0) {  // вторая строка больше
        res = -1;
    } else {  // строки равны
        res = 0;
    }
    return res;
}

char *s21_strcpy(char *dest, const char *source) {
    char *ptr = dest;  // запомнить начало указателя
    int len1 = s21_strlen(dest);
    int len2 = s21_strlen(source);
    int min = len1;

    if (len2 < len1) min = len2;
    int i = 0;
    for (i = 0; i < min; i++) dest[i] = source[i];
    dest[i] = '\0';
    return ptr;
}

char *s21_strcat(char *dest, const char *source) {
    char *ptr = dest;  // запомнить начало указателя
    int len1 = s21_strlen(dest);
    int len2 = s21_strlen(source);
    int i;
    for (i = 0; i < len2; i++) dest[len1 + i] = source[i];
    dest[len1 + i] = '\0';
    return ptr;
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