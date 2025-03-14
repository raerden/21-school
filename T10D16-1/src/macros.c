#include "macros.h"

#include <stdio.h>
/*
Флаг -D в компиляторе gcc используется для определения макроса препроцессора.
Он позволяет вам устанавливать макросы, которые могут быть использованы в коде,
чтобы управлять процессом компиляции, часто в целях условной компиляции.
Это означает, что вы можете включать или исключать определенные части кода в
зависимости от того, определен ли макрос или нет.

gcc -DFS macros.c - скомпилирует файл a.out который будет выводить 10
gcc -DFM macros.c - a.out > 25
gcc macros.c - a.out > - ничего не выведет
*/

size_t s21_strlen(const char *str) {
    size_t len = 0;
    while (*str) {
        len++;
        str++;
    }
    return len;
}

int main() {
#ifdef FS
    func_sum(5, 5);
#endif
#ifdef FM
    func_mul(5, 5);
#endif
    return 0;
}

void func_sum(int x, int y) { printf("%d\n", x + y); }
void func_mul(int x, int y) { printf("%d\n", x * y); }