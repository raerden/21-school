#include "data_stat.h"

double max(const double *data, int n) {
    double max = *data;
    for (int i = 0; i < n; i++)
        if (data[i] > max) max = data[i];
    return max;
}

double min(const double *data, int n) {
    double min = *data;
    for (int i = 0; i < n; i++)
        if (data[i] < min) min = data[i];
    return min;
}

// математическое ожидание. Среднее значение суммы элементов массива
double mean(const double *data, int n) {  //
    double sum = 0;
    for (int i = 0; i < n; i++) sum += data[i];
    return sum / (double)n;
}

// Дисперсия. Вычислить общее среднее. От каждого элемента отнять среднее, затем возвести в квадрат.
// суммировать и разделить на количество элементов
double variance(const double *data, int n) {
    double mean_s = 0, square_mean = 0, var = 0;
    double probability = 1 / (double)n;
    for (int i = 0; i < n; i++) {
        mean_s += data[i] * probability;
        square_mean += data[i] * data[i] * probability;
    }
    var = square_mean - mean_s * mean_s;
    return var;
}