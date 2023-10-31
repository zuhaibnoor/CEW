/* Print an inverted pyramid of asterisks. Take number of lines of pyramid as input from user.*/

#include <stdio.h>

void main(){

    int lines, asterisks, spaces = 0;

    printf("Enter the number of lines: ");
    scanf("%d", &lines);

    asterisks = lines;
    
    for (int i = 1; i <= lines; i++){
        
        for(int j = 1; j <= spaces; j ++){
            printf(" ");
        }
        
        for (int k = 1; k <= asterisks; k++){
            printf("* ");
        }
        
        printf("\n");
        asterisks --;
        spaces ++;
    }
}