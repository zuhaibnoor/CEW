#ifndef MATRIXFN_H_INCLUDED
#define MATRIXFN_H_INCLUDED
int** createMatrix(int rows, int cols);
void printMatrix(int** matrix, int rows, int cols);
int** Addition(int** mat1, int** mat2, int Size1, int Size2);
void freeMatrix(int** matrix, int rows);
int** Subtraction(int** mat1, int** mat2, int Size1, int Size2);
int** MatrixMultiplication(int** mat1, int** mat2, int rows1, int cols1, int rows2, int cols2);
int** Transpose(int** matrix, int rows, int cols);
int determinant3x3(int** mat);
#endif // MATRIXFN_H_INCLUDED
