#include <stdio.h>

int fibonachi(int x);

int main() {
    int num;

    if (scanf("%d", &num) == 1) printf("%d", fibonachi(num));

    return 0;
}

// формула фибоначи f(n) = f(n-1) + f(n-2).
int fibonachi(int x) {
    if (x == 1 || x == 2) return 1;
    return fibonachi(x - 2) + fibonachi(x - 1);
}
