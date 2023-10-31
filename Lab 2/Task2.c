/* Take an integer from user inside while loop and print its table of odd numbers, break the loop if the user enters negative number.*/

#include <stdio.h>

void main (){

    int num;

    while(1){
        printf("Enter an integer, to terminate the program enter a negative integer: ");
        scanf("%d", &num);
        if ( num < 0){
            break;
        }
        for (int i = 0; i <= 10; i++){
            if( i % 2 != 0 ){
                printf("%d x %d = %d\n", num, i, num*i);
            }
        }
    }
}