#include "data_process.h"

#include <math.h>

#include "../data_libs/data_stat.h"

int normalization(double *data, int n) {
    int result = 1;
    double max_value = max(data, n);
    double min_value = min(data, n);
    double size = max_value - min_value;

    if (fabs(size) >= EPS)  // 0.0000001
    {
        for (int i = 0; i < n; i++) {
            data[i] = data[i] / size - min_value / size;
        }
    } else {
        result = 0;
    }

    return result;
}

void sort(double *data, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (data[j] > data[j + 1]) {
                double tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
}