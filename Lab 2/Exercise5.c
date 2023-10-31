/* Write a C program to print all unique elements of an array. */

#include <stdio.h>

void main(){
    int array[7] = {0,1,2,2,1,1,3};
    int element;
    int occurence = 0;

    for (int  i = 0; i < ( sizeof(array)/sizeof(array[0]) ); i++) {
        
        element = array[i];
        
        for (int j = 0; j < sizeof(array)/ sizeof(array[0]); j++) {
            if ( array[i] == array[j] ) {
                occurence ++ ;
            }
        }
        if (occurence == 1){
                printf("%d ", array[i]);
        }
        occurence = 0;
    }
}