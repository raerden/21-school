#include <stdio.h>

int max(int a, int b);

int main() {
    int x , y;

    if (scanf("%d%d", &x, &y) != 2) {
        printf("Не корректный ввод\n");
        return 1;
    }

    printf("%d\n", max(x, y));
   
    
    return 0;
}

int max(int a, int b) {
    int m = a;
    if (b > a)
        m = b;
    return m;
}