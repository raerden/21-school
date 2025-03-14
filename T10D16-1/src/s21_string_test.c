#include "s21_string.h"

#include "s21_string_test.h"

void s21_strlen_test() {
    // Нормальное значение
    char *str_test = "Hello world!";
    int len_rnd = 12;
    printf("%s\n%d\n", str_test, len_rnd);
    printf("%s\n", len_rnd == (int)s21_strlen(str_test) ? "SUCCESS" : "FAIL");

    // Ненормальное значение
    char *str_test2 = "Hello world! He He he";
    len_rnd = 7;
    printf("%s\n%d\n", str_test2, len_rnd);
    printf("%s\n", len_rnd == (int)s21_strlen(str_test2) ? "SUCCESS" : "FAIL");

    // Краевое значение
    char *str_test3 = "";
    len_rnd = 5;
    printf("%s\n%d\n", str_test3, len_rnd);
    printf("%s", len_rnd == (int)s21_strlen(str_test3) ? "SUCCESS" : "FAIL");
}

void s21_strcmp_test() {
    int expected, result;
    // Нормальные значения
    char *str1 = "hello";
    char *str2 = "hello";
    expected = 0;
    result = s21_strcmp(str1, str2);
    printf("%s\n%s\n%d\n%s\n", str1, str2, expected, (result == expected) ? "SUCCESS" : "FAIL");

    // Ненормальные значения
    char *str3 = "abc";
    char *str4 = "abcd";
    expected = -1;
    result = s21_strcmp(str3, str4);
    printf("%s\n%s\n%d\n%s\n", str3, str4, expected, (result == expected) ? "SUCCESS" : "FAIL");

    // Краевые значения
    char *str5 = "";
    char *str6 = "";
    expected = 0;
    result = s21_strcmp(str5, str6);
    printf("%s\n%s\n%d\n%s\n", str5, str6, expected, (result == expected) ? "SUCCESS" : "FAIL");
}

void s21_strcpy_test() {
    // Нормальные значения
    char str1[20] = "hello";
    char *str2 = "all";
    printf("%s\n%s\n", str1, str2);
    char *result = s21_strcpy(str1, str2);
    printf("%s\n%s\n", result, (s21_strcmp(result, "all") == 0) ? "SUCCESS" : "FAIL");

    // Ненормальные значения
    char str3[20] = "short";
    char *str4 = "Longtexthere";
    printf("%s\n%s\n", str3, str4);
    result = s21_strcpy(str3, str4);
    printf("%s\n%s\n", result, (s21_strcmp(result, "Longt") == 0) ? "SUCCESS" : "FAIL");

    // // Краевые значения
    char str5[20] = "sometext";
    char *str6 = "12345678";
    printf("%s\n%s\n", str5, str6);
    result = s21_strcpy(str5, str6);
    printf("%s\n%s", result, (s21_strcmp(result, "12345678") == 0) ? "SUCCESS" : "FAIL");
}

void s21_strcat_test() {
    // Нормальные значения
    char str1[20] = "hello";
    char *str2 = "all";
    printf("%s\n%s\n", str1, str2);
    char *result = s21_strcat(str1, str2);
    printf("%s\n%s\n", result, (s21_strcmp(result, "helloall") == 0) ? "SUCCESS" : "FAIL");

    // Ненормальные значения
    char str3[20] = "short";
    char *str4 = "Longtexthere";
    printf("%s\n%s\n", str3, str4);
    result = s21_strcat(str3, str4);
    printf("%s\n%s\n", result, (s21_strcmp(result, "shortLongtexthere") == 0) ? "SUCCESS" : "FAIL");

    // Краевые значения
    char str5[20] = "sometext";
    char *str6 = "12345678";
    printf("%s\n%s\n", str5, str6);
    result = s21_strcat(str5, str6);
    printf("%s\n%s", result, (s21_strcmp(result, "sometext12345678") == 0) ? "SUCCESS" : "FAIL");
}

void s21_strchr_test() {
    // Нормальные значения
    char str1[20] = "hello";
    char ch = 'l';
    printf("%s\n%c\n", str1, ch);
    char *result = s21_strchr(str1, ch);
    printf("%s\n%s\n", result, (s21_strcmp(result, "llo") == 0) ? "SUCCESS" : "FAIL");

    // Ненормальные значения
    char str2[20] = "short";
    ch = 't';
    printf("%s\n%c\n", str2, ch);
    result = s21_strchr(str2, ch);
    printf("%s\n%s\n", result, (s21_strcmp(result, "t") == 0) ? "SUCCESS" : "FAIL");

    // // Краевые значения
    char str3[20] = "sometext";
    ch = '4';
    printf("%s\n%c\n", str3, ch);
    result = s21_strchr(str3, ch);
    // printf("%s\n%s", result, (s21_strcmp(result, NULL) == 0) ? "SUCCESS" : "FAIL");
    printf("%s\n%s", result, (result == NULL) ? "SUCCESS" : "FAIL");
}

int main() {
#ifdef STRLEN
    s21_strlen_test();
#endif
#ifdef STRCMP
    s21_strcmp_test();
#endif
#ifdef STRCPY
    s21_strcpy_test();
#endif
#ifdef STRCAT
    s21_strcat_test();
#endif
#ifdef STRCHR
    s21_strchr_test();
#endif

    return 0;
}