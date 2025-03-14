#include <math.h>
#include <stdio.h>

// Уравнение окружности замка обычно выглядит так: x^2 + y^2 = 25. 
void do_check(double x, double y) {
    if ((pow(x, 2) + pow(y, 2)) <= 25)
        printf("GOTCHA\n");
    else
        printf("MISS\n");
}

int main() {
    double x, y;
    int count = 0;
    count = scanf("%lf %lf", &x, &y);
    if (count != 2) {
        printf("n/a\n");
        return 0;
    }
    do_check(x, y);
    return 0;
}