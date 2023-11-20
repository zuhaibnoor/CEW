/* Write a program in C to print a string in reverse using pointers.*/
#include <stdio.h>

void rev_print(char *str){
    int length = 0;
    while (*str != '\0'){
        length++;
        str++;
    }
    
    printf("The reversed string is:\n");
    while(length >= 0){
        printf("%c", *str);
        length--;
        str--;
    }
}

int main(){

    char arr[] = "Programming";
    rev_print(arr);
    return 0;
}