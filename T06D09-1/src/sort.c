#include <stdio.h>

#define LEN 10

int input(int *arr);
void sort(int *arr);
void output(int *arr);
void swap(int *x, int *y);

int main() {
    int arr[LEN] = {};
    if (input(arr)) {
        sort(arr);
        output(arr);
    } else
        printf("n/a");
}

void sort(int *arr) {
    for (int i = 0; i < LEN - 1; i++)
        for (int j = 0; j < LEN - 1 - i; j++)
            if (arr[j] > arr[j + 1]) swap(arr + j, arr + j + 1);
}

void swap(int *x, int *y) {
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

int input(int *arr) {
    for (int i = 0; i < LEN; i++) {
        char c;
        if (i < LEN - 1) {
            if (scanf("%d%c", &arr[i], &c) != 2 || (c != ' ')) return 0;
        } else if (scanf("%d%c", &arr[i], &c) != 2 || (c != '\n'))
            return 0;
    }
    return 1;
}

void output(int *arr) {
    for (int i = 0; i < LEN; i++)
        if (i < LEN - 1)
            printf("%d ", arr[i]);
        else
            printf("%d", arr[i]);
}