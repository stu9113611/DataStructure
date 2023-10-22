#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "List.h"

int main(void)
{
    while (1) {
        IntList list = IntList_create();
        int nums[3] = { 0, 1, 2 };
        IntList_addWithArr(&list, nums, 3);
        IntList_add(&list, 3);
        IntList_print(list);

        printf("%d %d %d %d\n", IntList_get(&list, 0), IntList_get(&list, 1), IntList_get(&list, 2), IntList_get(&list, 3));

        IntList_insert(&list, 3, 4);
        IntList_print(list);

        IntList_insert(&list, 1, 5);
        IntList_print(list);

        IntList_remove(&list, 2);
        IntList_print(list);

        IntList list2 = IntList_create();
        IntList_add(&list2, 2);
        IntList_add(&list2, 3);
        IntList_print(list2);

        IntList_copy(&list, &list2);

        IntList_print(list2);

        int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        IntList list3 = IntList_createWithArray(arr, 10);
        IntList_print(list3);

        IntList_destroy(&list);
        IntList_destroy(&list2);
        IntList_destroy(&list3);
    }

    
    return 0;
}