#include <stdio.h>

#define NMAX 10

int input(int *buffer, int *length, int *shift);
void output(int *buffer, int length);
int shift_right(int *buffer, int length, int shift);
int shift_left(int *buffer, int length, int shift);

int main() {
    int buffer[NMAX];
    int length, shift;

    if (input(buffer, &length, &shift)) {
        if (shift > 0)
            shift_left(buffer, length, shift);
        else
            shift_right(buffer, length, shift);
        output(buffer, length);
    } else
        printf("n/a");
    return 0;
}

int shift_right(int *buffer, int length, int shift) {
    if (length > NMAX) return 0;
    if (shift < 0) shift = -shift;
    for (int x = 0; x < shift; x++) {
        int t = buffer[length - 1];
        for (int i = length - 2; i >= 0; i--)  // движемся вниз по массиву с предпоследнего элемента 8, 7, 6
            buffer[i + 1] = buffer[i];
        buffer[0] = t;
    }
    return 1;
}

int shift_left(int *buffer, int length, int shift) {
    if (length > NMAX) return 0;
    if (shift < 0) shift = -shift;
    for (int x = 0; x < shift; x++) {
        int t = buffer[0];
        for (int i = 1; i < length; i++) buffer[i - 1] = buffer[i];
        buffer[length - 1] = t;
    }
    return 1;
}

int input(int *buffer, int *length, int *shift) {
    int result = 1;
    if ((scanf("%d", length) == 0) || (*length > NMAX) || (*length <= 0)) {
        result = 0;
    }
    for (int i = 0; i < *length; i++) {
        if (scanf("%d", &buffer[i]) == 0) {
            result = 0;
        }
    }
    if ((scanf("%d", shift) != 1) || *shift > NMAX) {
        result = 0;
    }
    if (getchar() != '\n') {
        result = 0;
    }
    return result;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++)
        if (i < length - 1)
            printf("%d ", buffer[i]);
        else
            printf("%d", buffer[i]);
}
