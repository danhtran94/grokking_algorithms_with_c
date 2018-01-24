#include <stdio.h>
#include <stdlib.h>

// O(n * n)

int findSmallest(int arr[], int arr_size) {
    int smallest = arr[0];
    int smallest_index = 0;
    int i;
    for (i = 0; i < arr_size; i++)
    {
        if (arr[i] < smallest) {
            smallest = arr[i];
            smallest_index = i;
        }
    }
    return smallest_index;
}

int popFromArray(int arr[], int index, int arr_size) {
    int temp = arr[index];
    for (; index < arr_size; index++)
    {
        arr[index] = arr[index + 1];
    }
    return temp;
}

int * selectionSort(int arr[], int arr_size) {
    int *new_arr = malloc(sizeof(int) * arr_size);
    int i;
    for (i = 0; i < arr_size; i++) {
        int smallest_index = findSmallest(arr, arr_size);
        int smallest = popFromArray(arr, smallest_index, arr_size);
        new_arr[i] = smallest;
    }
    return new_arr;
}

int main() {
    int items[] = {9, 4, 2, 1, 10};
    int items_size = (int)sizeof(items) / sizeof(int);
    int *sorted_items = selectionSort(items, items_size);
    int i;
    for (i = 0; i < items_size; i++) {
        printf("%d ", sorted_items[i]);
    }
    return 0;
}

