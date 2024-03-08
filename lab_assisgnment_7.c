#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element{
    int data;
    int numSwaps;
} Element;

/*
precondition: unsorted array is passed to the function along with the size
postcondition: A copy array is dynamically allocated, and the contents of the first array is copied into array copy. An element is dynamically allocated for the number of elements in the array,
and the bubble sort algorithm is executed in the function upon the mirror array. The number of swaps are counted
and returned.*/
Element *numSwapsBubbleSort(int *arr, int size){
    int *copy = malloc(sizeof(int) * size);
    memcpy(copy, arr, sizeof(int) * size);

    Element *swaps = (Element*)malloc(sizeof(Element) * size);
    for(int i = 0; i < size; i++) {
        swaps[i].data = arr[i];
        swaps[i].numSwaps = 0;
    }

    //bubbleSort algorithm
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(copy[j] > copy[j + 1]) {
                swaps[j].numSwaps++;
                swaps[j + 1].numSwaps++;
                int temp = copy[j];
                copy[j] = copy[j + 1];
                copy[j + 1] = temp;
            }
        }
    }

    free(copy);
    return swaps;
}
/*
Precondiiton: pointer to the array and the size of it is passed to the function, unsorted.
Postcondition: Another copy array is dynamically allocated from the array passed to the function. An element for the swaps is dynamically allocated 
and the contents of the element is initialized.  The selection sort algorithm is then executed upon the copy array,  and with that
the number of swaps is counted. The element is returned at the end of execution.
*/
Element *numSwapsSelectionSort(int *arr, int size){
    int *copy = malloc(sizeof(int) * size);
    memcpy(copy, arr, sizeof(int) * size);

    Element *swaps = (Element*)malloc(sizeof(Element) * size);
    for(int i = 0; i < size; i++){
        swaps[i].data = arr[i];
        swaps[i].numSwaps = 0;
    }

    // selectionSort algo
    for(int i = 0; i < size - 1; i++){
        int min_index = i;
        for(int j = i + 1; j < size; j++){
            if(copy[j] < copy[min_index]){
                min_index = j;
            }
        }
        if(min_index != i){
            swaps[min_index].numSwaps++;
            swaps[i].numSwaps++;
            int temp = copy[i];
            copy[i] = copy[min_index];
            copy[min_index] = temp;
        }
    }

    free(copy);
    return swaps;
}

int main(void){
    //declaring both arrays
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    //finding the size of the arrays
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    //counting swaps with bubbleSort on array1
    printf("First array with bubbleSort:\n");
    Element *bubbleSwaps1 = numSwapsBubbleSort(array1, size1);     //initializing the element to the return value of the function call
    int totalSwaps1 = 0;
    for(int i = 0; i < size1; i++) {
        printf("%d: %d swaps\n", bubbleSwaps1[i].data, bubbleSwaps1[i].numSwaps);
        totalSwaps1 += bubbleSwaps1[i].numSwaps;
    }
    printf("Total number of swaps in first array bubbleSort: %d\n", totalSwaps1);

    //counting swaps with selectionSort on array1
    printf("\nFirst array with selectionSort:\n");
    Element *selectionSwaps1 = numSwapsSelectionSort(array1, size1);
    int totalSwapsSelection1 = 0;
    for(int i = 0; i < size1; i++) {
        printf("%d: %d swaps\n", selectionSwaps1[i].data, selectionSwaps1[i].numSwaps);
        totalSwapsSelection1 += selectionSwaps1[i].numSwaps;
    }
    printf("Total number of swaps in first array with selectionSort: %d\n", totalSwapsSelection1);

    //counting swaps with bubbleSort on array2
    printf("\nSecond array with bubbleSort:\n");
    Element *bubbleSwaps2 = numSwapsBubbleSort(array2, size2);
    int totalSwaps2 = 0;
    for(int i = 0; i < size2; i++) {
        printf("%d: %d swaps\n", bubbleSwaps2[i].data, bubbleSwaps2[i].numSwaps);
        totalSwaps2 += bubbleSwaps2[i].numSwaps;
    }
    printf("Total number of swaps in second array with bubbleSort: %d\n", totalSwaps2);

    //counting swaps with selectionSort on array2
    printf("\nSecond array with selection sort:\n");
    Element *selectionSwaps2 = numSwapsSelectionSort(array2, size2);
    int totalSwapsSelection2 = 0;
    for(int i = 0; i < size2; i++) {
        printf("%d: %d swaps\n", selectionSwaps2[i].data, selectionSwaps2[i].numSwaps);
        totalSwapsSelection2 += selectionSwaps2[i].numSwaps;
    }
    printf("Total number of swaps in second array with selectionSort: %d\n", totalSwapsSelection2);

    free(bubbleSwaps1);
    free(selectionSwaps1);
    free(bubbleSwaps2);
    free(selectionSwaps2);

}
