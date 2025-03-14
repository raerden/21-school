#include <stdio.h>

int sq_rect(int width, int height)
{
         return width * height;
}

int main() {
    int (*ptr_func) (int, int);
    ptr_func = sq_rect;
    int res = ptr_func(2,3);
    printf("sq_rect = %d\n", res);
    return 0;

}