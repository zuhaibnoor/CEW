/*Write a C program to add two matrices using pointers*/
#include <stdio.h>

void mat_add(int *mat1, int *mat2){
    int mat3[3][3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j <3; j++ ){
            mat3[i][j] = *mat1 + *mat2;
            mat1++;
            mat2++;
        }
    }
    printf("The resultant matrix is:\n");
    for (int i = 0; i < 3; i++){
        for(int j = 0; j <3; j++){
            printf(" %d ", mat3[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int matrix1[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
    int matrix2[3][3] = {{2,2,2},{2,2,2},{2,2,2}};    
    mat_add(matrix1,matrix2);

    
    return 0;
}