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

	/* //相當於上面
	if (p_list->size == 0) {
		p_list->head = p_newNode;
	}*/

	else {
		/*IntNode* p_lastNode = IntList_GetLastRef(p_list);
		p_lastNode->next = p_newNode; 相當於下面*/
		IntList_GetLastRef(p_list)->next = p_newNode;

	}
	p_list->size += 1; 
}


void IntList_AddWithArr(IntList* p_list, const int* arr, unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		IntList_Add(p_list, arr[i]);
	}
}


// Get是call by value
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


//GetRef是call by reference，在需要修改值的時候再call，安全性的問題
IntNode* IntList_GetRef(const IntList* p_list, unsigned int index) {
	if (index >= p_list->size) {    //size=3時，index=0~2，不含index 3
		printf("index out of range!\n");
		return NULL;
	}

	IntNode* p_node = p_list->head;
	for (unsigned int i = 0; i < index; i++) {  //index=2就是那個位置，<index表示跑0~1
		p_node = p_node->next;
	}
	return p_node;
}


IntNode* IntList_GetLastRef(const IntList* p_list) {
	return IntList_GetRef(p_list, p_list->size - 1); ////size是3，index是0~2，所以要-1
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
	p_list->size += 1;  //要自動更新size
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
	//list copy to list2. list2若有東西要先清除
	if (! IntList_IsEnpty(p_to)) {  //相當於if (p_to->size != 0) {
		IntList_Destroy(p_to);
		*p_to = IntList_Create(); //lsit2清空後，要創立空list
	}

	for (unsigned int i = 0; i < p_from->size; i++) {
		IntList_Add(p_to, IntList_Get(p_from,i));
	}
}


void IntList_Print(const IntList* p_list) {
	if (p_list->size == 0) { //相當於 if (IntList_IsEnpty(p_list) ){
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



