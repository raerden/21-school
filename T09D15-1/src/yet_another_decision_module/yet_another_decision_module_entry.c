#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    double *data = NULL;
    int n = input_size();
    int error = 0;

    if (n < 1) error = 1;
    // Don`t forget to allocate memory !
    if (error == 0) {
        data = malloc(n * sizeof(double));
        if (data == NULL)
            error = 1;
        else
            error = input(data, n);  // Возврат ошибки если были проблемы с вводом
    }

    if (error == 0) {
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
    } else {
        printf("n/a");
    }

    if (data != NULL) free(data);
    return 0;
}
