/* Write a C program to search for an element in an array using pointers. */
#include <stdio.h>

void search(int *array, int target, int size){
    for (int i = 0; i < size; i++){
        if (target == *array){
            printf("Target found at index: %d", i);
            return;
        }
        array++;
    }
    printf("Target not found!");
}

int main(){
    int arr[] = {1,2,4,8};
    search(arr, 4, 4);
}