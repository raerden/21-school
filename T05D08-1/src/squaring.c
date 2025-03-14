#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        squaring(data, n);
        output(data, n);
    } else
        printf("n/a");

    return 0;
}

int input(int *a, int *n) {
    char c;
    int result = 0;
    if (scanf("%d%c", n, &c) != 2 || c != '\n' || *n == 0 || *n > 10)
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
            printf("%d", a[i]);
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) a[i] = a[i] * a[i];
}
