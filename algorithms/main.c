#include <stdio.h>
#include "bubble-sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"

int main() {
    int arr[] = {0, 5, 1, 0, 2};
    int length = 5;
    selection_sort(arr, length);

    for(int i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}