/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

#define LEN 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(const int *buffer, int length);
int find_numbers(const int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int arr[LEN] = {};
    int length;
   
    if (input(arr, &length)) {
        int sum = sum_numbers(arr, length);
        if (sum == 0)
            printf("n/a");
        else {
            int numbers[LEN] = {0};
            printf("%d\n", sum);
            output(numbers, find_numbers(arr, length, sum, numbers));
        }
    } else
        printf("n/a");
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(const int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(const int *buffer, int length, int number, int *numbers) {
    int index = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] == 0)
            continue;
        else if (number % buffer[i] == 0) {
            numbers[index] = buffer[i];
            index++;
        }
    }
    return index;
}

int input(int *buffer, int *length) {
    char c;
    if (scanf("%d", length) != 1 || *length == 0 || *length > LEN) return 0;

    for (int i = 0; i < *length; i++) {
        if (i < *length - 1) {
            if (scanf("%d%c", &buffer[i], &c) != 2 || (c != ' ')) return 0;
        } else {
            if (scanf("%d%c", &buffer[i], &c) != 2 || (c != '\n')) {
                return 0;
            }
        }
    }
    return 1;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++)
        if (i < length - 1)
            printf("%d ", buffer[i]);
        else
            printf("%d", buffer[i]);
}