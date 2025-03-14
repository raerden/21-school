#include <stdio.h>

#include "print_module.h"

char print_char(char ch) 
{
    return putchar(ch);
}

void print_log(char (*print) (char), char* message) {
    printf("%d --%c -%d\n", sizeof(message) / sizeof(*message), *message, sizeof(message));
    for (int i =0; i < sizeof(message) / sizeof(*message); i++)
        print(message[i]);
}

int main() {
    //char mess[6] = {'m','e','s','a','g','e'};
    char mess[] = "Message_tets";
    print_log(print_char, mess);
}