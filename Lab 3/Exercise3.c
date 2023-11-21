/*Write a C program to input and print array elements using pointers*/

#include <stdio.h>

void input_arr(int *arr, int size){
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++){
        int element;
        scanf("%d", arr+i);
        
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *arr);
        arr++;
    }
}

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];

    input_arr(arr, size);

    return 0;
}