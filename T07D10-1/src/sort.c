#include <stdio.h>
#include <stdlib.h>

int input(int *arr, int length);
void sort(int *arr, int length);
void output(int *arr, int length);
void swap(int *x, int *y);

int main() {
    int length;
    int error = 1;

    if (scanf("%d", &length) == 1 && length > 0) {
        int *arr = malloc(length * sizeof(int));
        if (NULL != arr) {
            if (input(arr, length)) {
                sort(arr, length);
                output(arr, length);
                error = 0;
            }
            free(arr);  // освободить динамическую память
        }
    }

    if (error) printf("n/a");

    return 0;
}

int input(int *arr, int length) {
    int result = 1;

    for (int i = 0; i < length; i++)
        if (scanf("%d", &arr[i]) != 1) result = 0;

    if (getchar() != '\n') result = 0;

    return result;
}

void output(int *arr, int length) {
    for (int i = 0; i < length; i++)
        if (i < length - 1)
            printf("%d ", arr[i]);
        else
            printf("%d", arr[i]);
}

void sort(int *arr, int length) {
    for (int i = 0; i < length - 1; i++)
        for (int j = 0; j < length - 1 - i; j++)
            if (arr[j] > arr[j + 1]) swap(arr + j, arr + j + 1);
}

void swap(int *x, int *y) {
    int t;
    t = *x;
    *x = *y;
    *y = t;
}