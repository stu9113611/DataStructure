#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "List.h"

int main(void)
{
    while (1) {
        IntList list = IntList_Create();
        int nums[3] = { 0, 1, 2 };
        IntList_AddWithArr(&list, nums, 3);
        IntList_Add(&list, 3);
        IntList_Print(list);

        printf("%d %d %d %d\n", IntList_Get(&list, 0), IntList_Get(&list, 1), IntList_Get(&list, 2), IntList_Get(&list, 3));

        IntList_Insert(&list, 3, 4);
        IntList_Print(list);

        IntList_Insert(&list, 1, 5);
        IntList_Print(list);

        IntList_Remove(&list, 2);
        IntList_Print(list);

        IntList list2 = IntList_Create();
        IntList_Add(&list2, 2);
        IntList_Add(&list2, 3);
        IntList_Print(list2);

        IntList_Copy(&list, &list2);

        IntList_Print(list2);

        int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        IntList list3 = IntList_CreateWithArray(arr, 10);
        IntList_Print(list3);

        IntList_Destroy(&list);
        IntList_Destroy(&list2);
        IntList_Destroy(&list3);
    }

    
    return 0;
}
