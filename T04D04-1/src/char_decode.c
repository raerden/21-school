#include <stdio.h>
#include <stdlib.h>

void decoding();
void encoding();

int main(int argc, char *argv[]) {
    // Проверка, что передан ровно один аргумент
    if (argc != 2) {
        printf("Использование: %s <параметр>\n", argv[0]);
        return 1;  // Завершаем программу с кодом ошибки
    }

    int parameter = atoi(argv[1]);  // Переводим символ в целое число
    if (parameter == 0) {
        // Декодирование W O R L D > 57 4F 52 4C 44
        decoding();
    } else if (parameter == 1) {
        // Кодировние 48 45 4C 4C 4F > H E L L O
        encoding();
    } else {
        printf("Использование: %s <параметр>\n", argv[0]);
        printf("0 - кодирование; 1 - декодиривание\n");
    }

    return 0;  // Успешное завершение программы
}

void encoding() {
    int letter = 4 * 16 + 8 * 1;
    //   letter = 48;
    printf("%c", letter);
}

// Функция читает ввод с клавиатуры по одному символу через пробел
// декодирует заглавные буквы и цифры в ASCII код и выводит через пробел
void decoding() {
    /*
    Бесконечный цикл считывает ввод с клавиатуры.
    проверка введеного символа в диапазоне A-Z 0-9 - выводим его код со спецификатором %X
    пробел - выводим пробел
    конец строки (ввод) - выходим из функции
    иное - выводим ошибку n/a
    */
    char symbol;
    while (1) {
        symbol = getchar();
        if ((symbol > 64 && symbol < 91) || (symbol > 47 && symbol < 58))
            printf("%X", symbol);
        else if (symbol == ' ')
            printf(" ");
        else if (symbol == '\n')
            return;
        else {
            printf("n/a");
            return;
        }
    }
}
