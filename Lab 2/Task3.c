/* Print a pyramid of asterisks. Taking number of lines from user as input. */

#include <stdio.h>

void main(){

    int lines, spaces, asterisks = 1;
     
    printf("Enter the number of lines: ");
    scanf("%d", &lines);
    spaces = lines-1;

    for (int i = 1; i <= lines; i++){       
        
        for (int j = 1; j <= spaces; j ++){
            printf(" ");
        }
        for (int k = 1; k <= asterisks; k ++){
            printf("* ");
        }
        
        printf("\n");
        spaces --;
        asterisks ++;
    }
}