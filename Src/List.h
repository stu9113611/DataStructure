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
IntNode* IntNode_createRef(int value);

// Print an IntNode in details.
void IntNode_print(IntNode* p_node);

// ----------------------------- IntList ---------------------------------

struct IntList {
    IntNode* head;
    unsigned int size;
};
// A list which only contains integers.
typedef struct IntList IntList;

IntList     IntList_create();
IntList     IntList_createWithArray(const int* arr, unsigned int size);
void        IntList_destroy(IntList* p_list);
bool        IntList_isEmpty(IntList list);
void        IntList_print(IntList list);
int         IntList_get(const IntList* p_list, unsigned int index);
void        IntList_add(IntList* p_list, int value);
void        IntList_addWithArr(IntList* p_list, const int* arr, unsigned int size);
void        IntList_insert(IntList* p_list, unsigned int index, int value);
void        IntList_remove(IntList* p_list, unsigned int index);
void        IntList_copy(IntList* p_from, IntList* p_to);

IntNode*    IntList_getRef(const IntList* p_list, unsigned int index);
IntNode*    IntList_getLastRef(const IntList* p_list);