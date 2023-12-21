#include<stdio.h>
#include<stdlib.h>
#include "List.h"

int main(void) {
	IntList list = IntList_Create();
	int arr[3] = {0,1,2};
	IntList_AddWithArr(&list,arr,3);
	IntList_Add(&list, 3);
	IntList_Print(&list);

	IntList_Insert(&list, 3, 4);
	IntList_Print(&list);

	IntList_Insert(&list, 1, 5);
	IntList_Print(&list);

	IntList_Remove(&list, 1);
	IntList_Print(&list);

	IntList list2 = IntList_Create();
	IntList_Add(&list2, 2);
	IntList_Add(&list2, 3);

	IntList_Copy(&list, &list2);
	IntList_Print(&list2);


	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	IntList list3 = IntList_CreateWithArray(arr, 10);
	IntList_Print(&list3);


	IntList_Destroy(&list);
	IntList_Destroy(&list2);

}