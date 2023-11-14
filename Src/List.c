#include "List.h"
#include <stdio.h>
#include <stdlib.h>

IntNode* IntNode_createRef(int value) {
    IntNode* p_node = (IntNode*)malloc(sizeof(IntNode));
    if (!p_node) {
        printf("Failed to allocate new IntNode!");
        return;
    }
    p_node->value = value;
    p_node->next = NULL;
    return p_node;
}

void IntNode_print(IntNode* p_node) {
    printf("IntNode(value=%d, next=%p) at %p\n", p_node->value, p_node->next, p_node);
}

IntList IntList_create() {
    IntList list = { NULL, 0 };
    return list;
}

IntList IntList_createWithArray(const int* arr, unsigned int size) {
    IntList list = IntList_create();
    for (unsigned int i = 0; i < size; i++) {
        IntList_add(&list, arr[i]);
    }
    return list;
}

void IntList_destroy(IntList* p_list) {
    IntNode* ptr = p_list->head;
    while (ptr) {
        IntNode* prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
    p_list->head = NULL;
    p_list->size = 0;
}

bool IntList_isEmpty(IntList list) {
    return list.size == 0;
}

void IntList_print(IntList list) {
    if (list.size == 0) {
        printf("[ Empty ]\n");
        return;
    }

    const IntNode* p_node = list.head;
    printf("[ ");
    for (unsigned int i = 0; i < list.size; i++) {
        printf("%i ", p_node->value);
        p_node = p_node->next;
    }
    printf("]\n");
}

int IntList_get(const IntList* p_list, unsigned int index) {
    if (index >= p_list->size) {
        printf("Index out of range!\n");
        return -1;
    }
    unsigned int i = 0;
    IntNode* node = p_list->head;
    while (i++ < index) {
        node = node->next;
    }
    return node->value;
}

IntNode* IntList_getRef(const IntList* p_list, unsigned int index) {
    if (index >= p_list->size) {
        printf("Index out of range!\n");
        return NULL;
    }
    IntNode* p_node = p_list->head;
    for (unsigned int i = 0; i < index; i++) {
        p_node = p_node->next;
    }
    return p_node;
}

IntNode* IntList_getLastRef(const IntList* p_list) {
    return IntList_getRef(p_list, p_list->size - 1);
}

void IntList_add(IntList* p_list, int value) {
    IntNode* p_newNode = IntNode_createRef(value);

    if (p_list->size == 0) 
        p_list->head = p_newNode;
    else
        IntList_getLastRef(p_list)->next = p_newNode;
    p_list->size += 1;
}

void IntList_addWithArr(IntList* p_list, const int* arr, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        IntList_add(p_list, arr[i]);
    }
}

void IntList_insert(IntList* p_list, unsigned int index, int value) {
    IntNode* p_node = IntList_getRef(p_list, index);
    const IntNode* p_next = p_node->next;
    p_node->next = IntNode_createRef(value);
    p_node->next->next = p_next;
    p_list->size += 1;
}

void IntList_remove(IntList* p_list, unsigned int index) {
    IntNode* p_prev = IntList_getRef(p_list, index - 1);
    const IntNode* p_node = p_prev->next;
    p_prev->next = p_node->next;
    free(p_node);
    p_list->size -= 1;
}

void IntList_copy(const IntList* p_from, IntList* p_to) {
    if (p_to->size != 0) {
        IntList_destroy(p_to);
        *p_to = IntList_create();
    }

    for (unsigned int i = 0; i < p_from->size; i++) {
        IntList_add(p_to, IntList_get(p_from, i));
    }
}
