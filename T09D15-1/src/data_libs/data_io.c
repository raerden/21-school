#include "data_io.h"

#include <stdio.h>

int input_size() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    return n;
}

int input(double *data, int n) {
    int error = 0;
    char c;
    for (int i = 0; i < n; i++)
        if (scanf("%lf", &(data[i])) != 1) {
            error = 1;
            break;
        }
    if ((scanf("%c", &c) != 0) && (c != '\n')) error = 1;
    return error;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i != n - 1) printf(" ");
    }
}