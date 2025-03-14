#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main() {
    double *data = NULL;
    int n = input_size();
    int error = 0;

    printf("LOAD DATA...\n");

    if (n < 1) error = 1;
    if (error == 0) {
        data = malloc(n * sizeof(double));
        if (data == NULL)
            error = 1;
        else
            error = input(data, n);  // Возврат ошибки если были проблемы с вводом
    }

    if (error == 0) {
        printf("RAW DATA:\n\t");
        output(data, n);

        printf("\nNORMALIZED DATA:\n\t");
        normalization(data, n);
        output(data, n);

        printf("\nSORTED NORMALIZED DATA:\n\t");
        sort(data, n);
        output(data, n);

        printf("\nFINAL DECISION:\n\t");
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
