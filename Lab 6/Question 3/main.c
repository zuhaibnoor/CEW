#include <stdio.h>
#include "matrix.c"

int main() {
    int rows = 3;
    int cols = 3;

    int** mat1 = createMatrix(rows, cols);
    int** mat2 = createMatrix(rows, cols);

    for (int i =0; i< cols; i++)
    {
        for (int j = 0; j<rows; j++)
        {
            mat1[i][j] = i+j;
            mat2[i][j] = i+j;
        }
    }


    int** addResult = Addition(mat1, mat2, rows, cols);
    printf("Matrix Addition Result:\n");
    printMatrix(addResult, rows, cols);
    freeMatrix(addResult, rows);


    int** subResult = Subtraction(mat1, mat2, rows, cols);
    printf("Matrix Subtraction Result:\n");
    printMatrix(subResult, rows, cols);
    freeMatrix(subResult, rows);





    int** multResult = MatrixMultiplication(mat1, mat2, rows, cols, rows, cols);
    printf("Matrix Multiplication Result:\n");
    printMatrix(multResult, rows, cols);
    freeMatrix(multResult, rows);


    int** transResult = Transpose(mat1, rows, cols);
    printf("Matrix Transposition Result:\n");
    printMatrix(transResult, cols, rows);
    freeMatrix(transResult, cols);


    int detResult = determinant3x3(mat1);
    printf("Determinant of 3x3 Matrix: %d\n", detResult);


    freeMatrix(mat1, rows);
    freeMatrix(mat2, rows);


    return 0;
}
