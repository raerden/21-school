#include <stdio.h>



int main() {
    int x , y;

    if (scanf("%d%d", &x, &y) != 2) {
        printf("Не корректный ввод\n");
        return 1;
    }


    int sum_xy, diff_xy, mult_xy, priv_xy;

    sum_xy = x + y;
    diff_xy = x - y;
    mult_xy = x * y;
    

    if ( y == 0 ) 
        printf("%d %d %d n/a", sum_xy, diff_xy, mult_xy);
    else  {
        priv_xy = x / y;
        printf("%d %d %d %d", sum_xy, diff_xy, mult_xy, priv_xy);
    }

   
    
    return 0;
}