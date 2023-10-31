/* Write a C program to make the following pattern as a pyramid with an asterisk.
   *
  * *
 * * *
* * * *
 
 
 */

#include <stdio.h>
int main(){

    int spaces = 3;
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= spaces; j++){
            printf(" ");
        }
        spaces --;
        for(int k = 1; k <= i; k++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}