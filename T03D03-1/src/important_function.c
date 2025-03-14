#include <stdio.h>
#include <math.h>


int main() {
    double x, y;

    if (scanf("%f", &x) != 1) {
        printf("Не корректный ввод\n");
        return 1;
    }
// 7e-3 * x^4 + ((22.8 * x^⅓ - 1e3) * x + 3) / (x * x / 2) - x * (10 + x)^(2/x) - 1.01. 

    y = 7e-3 * pow(x,4) + ((22.8 * pow(x, 1 / 3) - 1e3) * x + 3) / (x * x / 2) - x * 
    pow(10 + x, 2/x) - 1.01;

    printf("%.1f\n", y);
   
    
    return 0;
}
