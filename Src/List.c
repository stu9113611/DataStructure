#include "List.h"
#include <stdio.h>
#include <stdlib.h>

IntNode* IntNode_CreateRef(int value) {
	IntNode* p_node = (IntNode*)malloc(sizeof(IntNode));
	if (!p_node) {
		printf("Failed to allocate new IntNode!");
		return;
	}
	p_node->value = value;
	p_node->next = NULL;
	return p_node;
}

void IntNode_Print(IntNode* p_node) {
	printf("IntNode(value=%d, next=%p) at %p\n", p_node->value, p_node->next, p_node);
}

IntList IntList_Create() {
	IntList list = { NULL, 0 };
	return list;
}

IntList IntList_CreateWithArray(const int* arr, unsigned int size) {
	IntList list = IntList_Create();
	for (unsigned int i = 0; i < size; i++) {
		IntList_Add(&list, arr[i]);
	}
	return list;
}

void IntList_Destroy(IntList* p_list) {
	IntNode* ptr = p_list->head;
	while (ptr) {
		IntNode* prev = ptr;
		ptr = ptr->next;
		free(prev);
	}
	p_list->head = NULL;
	p_list->size = 0;
}

bool IntList_IsEmpty(IntList list) {
	return list.size == 0;
}

void IntList_Print(IntList list) {
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

int IntList_Get(const IntList* p_list, unsigned int index) {
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

IntNode* IntList_GetRef(const IntList* p_list, unsigned int index) {
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

IntNode* IntList_GetLastRef(const IntList* p_list) {
	return IntList_GetRef(p_list, p_list->size - 1);
}

void IntList_Add(IntList* p_list, int value) {
	IntNode* p_newNode = IntNode_CreateRef(value);

	if (p_list->size == 0)
		p_list->head = p_newNode;
	else
		IntList_GetLastRef(p_list)->next = p_newNode;
	p_list->size += 1;
}

void IntList_AddWithArr(IntList* p_list, const int* arr, unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		IntList_Add(p_list, arr[i]);
	}
}

void IntList_Insert(IntList* p_list, unsigned int index, int value) {
	if (index == 0) {
		IntNode* p_node = IntList_GetRef(p_list, 0);
		p_list->head = IntNode_CreateRef(value);
		p_list->head->next = p_node;
	}
	else {
		IntNode* p_node = IntList_GetRef(p_list, index - 1);
		const IntNode* p_next = p_node->next;
		p_node->next = IntNode_CreateRef(value);
		p_node->next->next = p_next;
	}
	p_list->size += 1;
}

void IntList_Remove(IntList* p_list, unsigned int index) {
	IntNode* p_prev = IntList_GetRef(p_list, index - 1);
	const IntNode* p_node = p_prev->next;
	p_prev->next = p_node->next;
	free(p_node);
	p_list->size -= 1;
}

void IntList_Copy(const IntList* p_from, IntList* p_to) {
	if (p_to->size != 0) {
		IntList_Destroy(p_to);
		*p_to = IntList_Create();
	}

	for (unsigned int i = 0; i < p_from->size; i++) {
		IntList_Add(p_to, IntList_Get(p_from, i));
	}
}
