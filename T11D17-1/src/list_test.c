#include "list.h"
// #include "list.c"
// #include <stdio.h>
// #include <stdlib.h>

void add_door_test() {
    struct door door = {1, 1};
    struct node* door_list = init(&door);
    struct node* ptr = door_list;

    for (int i = 2; i < 6; i++) {
        door.id = i;
        door.status = rand() % 2;
        ptr = add_door(ptr, &door);
    }
    printf("Генерируем односвязный список с элементами структуры door\n");
    output(door_list);
    // #ifdef ADD_DOOR
    printf("\nПроверка функции add_door.\n");
    printf("1 Добавить новый элемент c id=11 после первого\n");
    door.id = 11;
    door.status = 0;
    add_door(door_list, &door);
    output(door_list);

    printf("\n2 Добавить новый элемент c id=21 в середину списка\n");
    door.id = 21;
    door.status = 1;
    struct node* find_elem = find_door(3, door_list);
    add_door(find_elem, &door);
    output(door_list);

    printf("\n3 Добавить новый элемент c id=31 в конец списка\n");
    door.id = 31;
    door.status = 1;
    ptr = door_list;
    while (ptr->next != NULL) ptr = ptr->next;

    add_door(ptr, &door);
    output(door_list);
    destroy(door_list);
    printf("\nКонец проверки. Очищаем список из памяти\n\n");
}

void remove_door_test() {
    struct door door = {1, 1};
    struct node* door_list = init(&door);
    struct node* ptr = door_list;

    for (int i = 2; i < 6; i++) {
        door.id = i;
        door.status = rand() % 2;
        ptr = add_door(ptr, &door);
    }
    printf("Генерируем односвязный список с элементами структуры door\n");
    output(door_list);

    // #ifdef ADD_DOOR
    printf("\nПроверка функции remove_door.\n");
    printf("1 Удалить первый элемент\n");

    remove_door(door_list, door_list);  // первый элемент равен началу списка
    output(door_list);

    printf("\n2 Удалить элемент c id=3\n");

    struct node* find_elem = find_door(3, door_list);
    remove_door(find_elem, door_list);
    output(door_list);

    printf("\n3 Удалить последний элемент\n");
    ptr = door_list;
    while (ptr->next != NULL) ptr = ptr->next;

    remove_door(ptr, door_list);
    output(door_list);

    destroy(door_list);
    printf("\nКонец проверки. Очищаем список из памяти\n\n");
}

int main() {
    add_door_test();
    remove_door_test();
    return 1;
}
