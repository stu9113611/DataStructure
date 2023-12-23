#include<stdio.h>
#include<stdlib.h>
#include "List.h"

int main(void) {
	IntList list = IntList_Create();
	int arr[3] = { 0,1,2 };
	IntList_AddWithArr(&list, arr, 3);
	IntList_Add(&list, 3);
	printf("list add 3: ");
	IntList_Print(&list);

	IntList_Insert(&list, 3, 4);
	printf("list insert value 4 in index3: ");
	IntList_Print(&list);

	IntList_Insert(&list, 1, 5);
	printf("list insert value 5 in index1: ");
	IntList_Print(&list);

	IntList_Remove(&list, 1);
	printf("list remove index1's value: ");
	IntList_Print(&list);


	IntList list2 = IntList_Create();
	IntList_Add(&list2, 2);
	IntList_Add(&list2, 3);
	printf("list2 value: ");
	IntList_Print(&list2);

	IntList_Copy(&list, &list2);
	printf("list2 copy list: ");
	IntList_Print(&list2);


	int a[5] = { 9, 8, 7, 6, 5 };
	IntList list3 = IntList_CreateWithArray(a, 5);
	printf("list3 value: ");
	IntList_Print(&list3);


	IntList_Destroy(&list);
	IntList_Destroy(&list2);
	IntList_Destroy(&list3);

}