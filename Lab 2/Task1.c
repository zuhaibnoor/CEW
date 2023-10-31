/* Take an integer from user as input and print odd numbers from 1 to that number. */

#include <stdio.h>

int main(){

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The odd numbers from 1 to %d are: ",num);
    for (int i = 1; i <= num; i++){
        if (i % 2 != 0){
            printf("%d ", i);
        }
    }

    return 0;
}