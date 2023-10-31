/* Write a C program to compare two strings without using string library functions.  */

#include <stdio.h>

int main(){

    char string1[50], string2[50];

    printf("Enter strings of not more than 50 characters.\n");
    printf("Enter string 1: ");
    scanf("%s", &string1);

    printf("Enter string 2: ");
    scanf("%s", &string2);



    int i = 0;
    int result = 1; // considering 1 as true and 0 as false. we can use stdbool.h header to declare bool variables.
    while (string1[i] != '\0' && string2[i] != '\0'){
        if (string1[i] != string2[i]){
            result = 0;
            break;
        }
        i++;
    }
    if (result == 1){
        printf("The two strings are equal.");
    }
    else{
        printf("The two strings are not equal.");
    }
    return 0;
}
