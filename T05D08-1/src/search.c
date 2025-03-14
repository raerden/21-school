/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int is_even(int num);
int num_search(int *a, int n);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 0) {
        printf("%d", num_search(data, n));
    } else
        printf("n/a");

    return 0;
}

int input(int *a, int *n) {
    char c;
    int result = 0;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n == 0 || *n > NMAX)
        result = -1;
    else
        for (int *p = a; p - a < *n; p++)  // перебор по адресу указателя
            if (p - a < *n - 1) {
                if (scanf("%d%c", p, &c) != 2 || c != ' ') {
                    result = -1;
                    break;
                }
            } else {
                if (scanf("%d%c", p, &c) != 2 ||
                    c != '\n') {  // после крайнего целого значения последний символ только \n
                    result = -1;
                }
            }
    return result;
}

// математическое ожидание. Среднее значение суммы элементов массива
double mean(int *a, int n) {
    double sum = 0;
    for (int *p = a; p - a < n; p++) sum = sum + *p;
    return sum / n;
}

// Дисперсия. Вычислить среднее. От каждого элемента отнять среднее, затем возвести в квадрат.
// суммировать и разделить на количество элементов
double variance(int *a, int n) {
    double mean_value = mean(a, n);
    double var = 0;
    for (int *p = a; p - a < n; p++) {
        double x = *p - mean_value;
        var = var + x * x;
    }
    return var / n;
}

int is_even(int num) {
    if (num % 2 == 0) return 1;
    return 0;
}

int num_search(int *a, int n) {
    double mean_val = mean(a, n);
    double variance_val = variance(a, n);
    for (int i = 0; i < n; i++)
        if (is_even(a[i]) && a[i] != 0 && a[i] >= mean_val && a[i] <= mean_val + 3 * sqrt(variance_val))
            return a[i];
    return 0;  // вернет ноль если в цикле не найдет нужное число
}
