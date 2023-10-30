/* Write a C program to display the first n odd natural numbers and their sum using for, while and
do-while loop. */

#include <stdio.h>

int main(){

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The %d odd  numbers are:\n", num);

    printf("\'Using for loop\'\n");
    for (int i =1; i<=num; i++){
        printf("%d ", (2*i)-1);
    }

    int iter = 1;
    printf("\n\'Using while loop\'\n");
    while (iter <= num){
        printf("%d ", (2*iter)-1);
        iter++ ;
    }

    int a  = 1;   
    printf("\n\'Using do while loop\'\n");
    do {
    printf("%d ", (2*a)-1);
    a++;
    }while ( a <= num );
}
