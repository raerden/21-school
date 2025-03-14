#include "list.h"

#include <stdio.h>
#include <stdlib.h>

void output(struct node* root) {
    if (root) {
        struct node* ptr = root;
        while (ptr != NULL) {
            printf("id=%d, status=%d\n", ptr->door.id, ptr->door.status);
            ptr = ptr->next;
        }
    }
}

struct node* init(const struct door* door) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->door = *door;
    new_node->next = NULL;
    return new_node;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* new_node = init(door);
    new_node->next = elem->next;
    elem->next = new_node;
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* ptr = root;
    struct node* result = NULL;
    while (ptr != NULL) {
        if (ptr->door.id == door_id) {
            result = ptr;
            break;
        }
        ptr = ptr->next;
    }
    return result;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* ptr = root;
    struct node* result = NULL;
    if (elem) {
        if (root->next == NULL) {  // Если список состоит из одного элемента
            free(elem);
        } else if (root == elem) {  // Удаление первого элемента связанного списка
            ptr = root->next;
            *root = *(root->next);
            free(ptr);
        } else {  // Удаление из середины или последнего элемента
            while (ptr->next != elem) ptr = ptr->next;
            // Найден указатель на предыдущий элемент перед удаляемым

            ptr->next = elem->next;
            result = ptr;
            free(elem);
        }
    }
    return result;
}

void destroy(struct node* root) {
    struct node* ptr = root;
    while (ptr != NULL) {
        struct node* next = ptr->next;
        free(ptr);
        ptr = next;
    }
}