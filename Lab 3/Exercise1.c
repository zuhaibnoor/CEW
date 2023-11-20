/* Write a program in C to swap elements using call by reference.*/

#include <stdio.h>
#include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main () {
    int arr[] = {10,20,30,40};
    swap(&arr[1], &arr[2]);
    for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++ ){
        printf("%d\n", arr[i]);
    }
 return 0;
}

