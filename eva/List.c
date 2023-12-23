#include<stdio.h>
#include<stdlib.h>
#include "List.h" 

bool IntList_IsEnpty(IntList* p_list) {
	return p_list->size == 0;
}

IntNode* IntNode_CreateRef(int value) {
	IntNode* p_node = (IntNode*)malloc(sizeof(IntNode));

	if (!p_node) {
		printf("Failed to allocate new NewNode!!");
		return ;
	}

	p_node->value = value;
	p_node->next = NULL;
	return p_node;
}


void IntNode_Print(IntNode* p_node) {
	printf("IntNode (value=%i ,next=%p) ,at %p\n", p_node->value, p_node->next, p_node);
}


IntList IntList_Create() {
	IntList p_list = { NULL,0 };
	return p_list;
}


IntList IntList_CreateWithArray(const int* a, unsigned int size) {
	IntList list = IntList_Create();
	for (unsigned int i = 0; i < size; i++) {
		IntList_Add(&list, a[i]);
	}
	return list;
}


void IntList_Add(IntList* p_list, int value) {
	IntNode* p_newNode = IntNode_CreateRef(value);  

	if (IntList_IsEnpty(p_list) ){
		p_list->head = p_newNode;
	} 

	/* //�۷��W��
	if (p_list->size == 0) {
		p_list->head = p_newNode;
	}*/

	else {
		/*IntNode* p_lastNode = IntList_GetLastRef(p_list);
		p_lastNode->next = p_newNode; �۷��U��*/
		IntList_GetLastRef(p_list)->next = p_newNode;

	}
	p_list->size += 1; 
}


void IntList_AddWithArr(IntList* p_list, const int* arr, unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		IntList_Add(p_list, arr[i]);
	}
}


// Get�Ocall by value
int IntList_Get(const IntList* p_list, unsigned int index) {
	if (index >= p_list->size) {
		printf("index out of range!\n");
		return;
	}
	IntNode* p_node = p_list->head;
	for (unsigned int i = 0; i < index; i++) {
		p_node = p_node->next;
	}
	
	return p_node->value;
}


//GetRef�Ocall by reference�A�b�ݭn�ק�Ȫ��ɭԦAcall�A�w���ʪ����D
IntNode* IntList_GetRef(const IntList* p_list, unsigned int index) {
	if (index >= p_list->size) {    //size=3�ɡAindex=0~2�A���tindex 3
		printf("index out of range!\n");
		return NULL;
	}

	IntNode* p_node = p_list->head;
	for (unsigned int i = 0; i < index; i++) {  //index=2�N�O���Ӧ�m�A<index��ܶ]0~1
		p_node = p_node->next;
	}
	return p_node;
}


IntNode* IntList_GetLastRef(const IntList* p_list) {
	return IntList_GetRef(p_list, p_list->size - 1); ////size�O3�Aindex�O0~2�A�ҥH�n-1
}


void IntList_Insert(IntList* p_list, unsigned int index, int value) {
	if (index == 0) {
		IntNode* p_nextNode = IntList_GetRef(p_list, index);
		p_list->head = IntNode_CreateRef(value);
		p_list->head->next = p_nextNode;
	}

	else
	{
		IntNode* p_node = IntList_GetRef(p_list, index - 1);
		IntNode* p_ori_nextNode = p_node->next;
		p_node->next = IntNode_CreateRef(value);
		p_node->next->next = p_ori_nextNode;
	}
	p_list->size += 1;  //�n�۰ʧ�ssize
}


void IntList_Remove(IntList* p_list, unsigned int index) {
	//method1
	IntNode* p_prev = IntList_GetRef(p_list, index - 1);
	IntNode* p_newnode = p_prev->next->next;
	free(p_prev->next);
	p_prev->next = p_newnode;

	//method2
	/*intnode* p_prev = intlist_getref(p_list, index - 1);
	const intnode* p_node = p_prev->next;
	p_prev->next = p_node->next;
	free(p_node); */

	p_list->size -= 1;
}


void IntList_Copy(IntList* p_from, IntList* p_to) {
	//list copy to list2. list2�Y���F��n���M��
	if (! IntList_IsEnpty(p_to)) {  //�۷��if (p_to->size != 0) {
		IntList_Destroy(p_to);
		*p_to = IntList_Create(); //lsit2�M�ū�A�n�Хߪ�list
	}

	for (unsigned int i = 0; i < p_from->size; i++) {
		IntList_Add(p_to, IntList_Get(p_from,i));
	}
}


void IntList_Print(const IntList* p_list) {
	if (p_list->size == 0) { //�۷�� if (IntList_IsEnpty(p_list) ){
		printf("[Empty!!]\n");
		return;
	}

	const IntNode* p_node = p_list->head;

	printf("[");
	for (unsigned int i = 0; i < p_list->size; i++) {
		printf("%i ", p_node->value);
		p_node = p_node->next;
	}
	printf("]\n");
}


void IntList_Destroy(IntList* p_list) {
	//method1
	IntNode* p_node = p_list->head;
	for (unsigned int i = 0; i < p_list->size; i++) {
		IntNode* next_node = p_node->next;
		free(p_node);
		p_node = next_node;
	}

	//method2
	/*IntNode* ptr = p_list->head;
	while (ptr) {
		IntNode* prev = ptr;
		ptr = ptr->next;
		free(prev);
	}*/

	p_list->head = NULL;
	p_list->size = 0;
}



