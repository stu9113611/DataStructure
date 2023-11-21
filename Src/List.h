#pragma once
#include <stdbool.h>

// ----------------------------- IntNode ---------------------------------

struct IntNode
{
	int value;
	struct IntNode* next;
};
// Basic unit of an IntList.
typedef struct IntNode IntNode;

// Allocate an IntNode, which needs to be freed explicitly.
IntNode* IntNode_CreateRef(int value);

// Print an IntNode in details.
void IntNode_Print(IntNode* p_node);

// ----------------------------- IntList ---------------------------------

struct IntList {
	IntNode* head;
	unsigned int size;
};
// A list which only contains integers.
typedef struct IntList IntList;

IntList     IntList_Create();
IntList     IntList_CreateWithArray(const int* arr, unsigned int size);
void        IntList_Destroy(IntList* p_list);
bool        IntList_IsEmpty(IntList list);
void        IntList_Print(IntList list);
int         IntList_Get(const IntList* p_list, unsigned int index);
void        IntList_Add(IntList* p_list, int value);
void        IntList_AddWithArr(IntList* p_list, const int* arr, unsigned int size);
void        IntList_Insert(IntList* p_list, unsigned int index, int value);
void        IntList_Remove(IntList* p_list, unsigned int index);
void        IntList_Copy(IntList* p_from, IntList* p_to);

IntNode* IntList_GetRef(const IntList* p_list, unsigned int index);
IntNode* IntList_GetLastRef(const IntList* p_list);
