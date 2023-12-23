#include<stdbool.h>


struct IntNode {
	int value;
	struct IntNode* next;
};

typedef struct IntNode IntNode;
IntNode* IntNode_CreateRef(int value);
void IntNode_Print(IntNode* p_node);


struct IntList {
	IntNode* head;
	unsigned int size;
};

typedef struct IntList IntList;


IntList IntList_Create(); //�o��IntList���Ϋ��СA�]�����Ϊ��D���w��}�A�o��O�t�s�A�Ө�L�|�Ψ���ЬO�]���n�Ψ�o�Ӧ�}
IntList IntList_CreateWithArray(const int* arr, unsigned int size);
void IntList_Add(IntList* p_list, int value);
void IntList_AddWithArr(IntList* p_list, const int* arr, unsigned int size);
int IntList_Get(const IntList* p_list, unsigned int index); //get���|�ܰʨ�list�A�ҥH��const
IntNode* IntList_GetRef(const IntList* p_list, unsigned int index);
IntNode* IntList_GetLastRef(const IntList* p_list); 
bool IntList_IsEnpty(IntList* p_list);
void IntList_Remove(IntList* p_list, unsigned int index);
void IntList_Insert(IntList* p_list, unsigned int index, int value);
void IntList_Copy(IntList* p_from, IntList* p_to);
void IntList_Print(const IntList* p_list);
void IntList_Destroy(IntList* p_list);


