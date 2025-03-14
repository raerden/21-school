#include <math.h>
#include <stdio.h>

int remainder_from_division(int x, int y);
int divider(int x, int y);
int is_prime(int x);
int max_prime_divider(int num);

int main() {
    int num;

    if (scanf("%d", &num) != 1) {
        printf("Введите целое число\n");
        return 1;
    }

    if (num < 0) num = -num;

    int max_prime = max_prime_divider(num);
    if (max_prime > 0)
        printf("%d\n", max_prime);
    else
        printf("n/a\n");

    return 0;
}

int max_prime_divider(int num) {
    if (is_prime(num)) return num;
    int i;
    for (i = num - 1; i > 0; i--) {
        if (remainder_from_division(num, i) == 0)
            if (is_prime(i)) return i;
    }
    return 0;
}

// Функция проверки является ли число в аргументе простым
int is_prime(int x) {
    if (x <= 1) return 0;
    int i;
    for (i = 2; i < (int)sqrt(x) + 1; i++)
        if (divider(x, i) > 0) return 0;
    return 1;
}

// Поиск делителя без оператора деления.
int divider(int x, int y) {
    // ПРоверить деление на 0
    if (y == 0) return 0;
    // Проверка что число делится нацело
    if (remainder_from_division(x, y) != 0) return 0;
    // Вычитаем циклом делитель из числа пока число не станет меньше делителя
    // счетчик количества проходов цикла вычитания делителя до нуля
    // он и будет являться делителем числа
    int count = 0;
    while (x >= y) {
        x = x - y;
        count++;
    }
    return count;
}

// Поиск остатка от деления без
int remainder_from_division(int x, int y) {
    // Вычитаем делитель от числа пока число больше или равно делителю
    while (x >= y) x = x - y;
    return x;
}