#ifndef STR_FUN
#define STR_FUN
#include <stdlib.h>

size_t s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *dest, const char *source);
char *s21_strcat(char *dest, const char *source);
char *s21_strchr(char *dest, char ch);

#endif