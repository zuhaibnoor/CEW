#include "matrixFn.h"

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    return matrix;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** Addition(int** mat1, int** mat2, int Size1, int Size2)
{
    if (Size1 != Size2) {
        printf("Error: Matrices must have the same size for addition.\n");
        return NULL;
    }

    int** mat3 = malloc(Size1 * sizeof(int*));

    for (int i = 0; i < Size1; i++)
    {
        mat3[i] = malloc(Size2 * sizeof(int));

        for (int j = 0; j < Size2; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return mat3;
}

int** Subtraction(int** mat1, int** mat2, int Size1, int Size2) {
    if (Size1 != Size2) {
        printf("Error: Matrices must have the same size for subtraction.\n");
        return NULL;
    }

    int** result = malloc(Size1 * sizeof(int*));

    for (int i = 0; i < Size1; i++) {
        result[i] = malloc(Size2 * sizeof(int));

        for (int j = 0; j < Size2; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }

    return result;
}


int** MatrixMultiplication(int** mat1, int** mat2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication.\n");
        return NULL;
    }

    int** result = malloc(rows1 * sizeof(int*));

    for (int i = 0; i < rows1; i++) {
        result[i] = malloc(cols2 * sizeof(int));

        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;

            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}

int** Transpose(int** matrix, int rows, int cols) {
    int** result = malloc(cols * sizeof(int*));

    for (int i = 0; i < cols; i++) {
        result[i] = malloc(rows * sizeof(int));

        for (int j = 0; j < rows; j++) {
            result[i][j] = matrix[j][i];
        }
    }

    return result;
}
int determinant3x3(int** mat) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
           mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
           mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}
