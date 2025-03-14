#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 0) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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

void output(int *a, int n) {
    for (int i = 0; i < n; i++)
        if (i < n - 1)
            printf("%d ", a[i]);
        else
            printf("%d\n", a[i]);
}

int max(int *a, int n) {
    int max = a[0];  // предполагаю первый элемент за максимальный
    for (int *p = a; p - a < n; p++)
        if (max < *p) max = *p;
    return max;
}

int min(int *a, int n) {
    int min = a[0];
    for (int *p = a; p - a < n; p++)
        if (min > *p) min = *p;
    return min;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}