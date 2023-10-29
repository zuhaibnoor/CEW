/* Write a function to calculat the nth fibonacci  number and call it recursively to print the fibonacci series */

#include <stdio.h>

void printFibonacciSeries(int n, int a, int b) {
    if (n > 0) {
        printf("%d ", a);
        printFibonacciSeries(n - 1, b, a + b);
    }
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Fibonacci series up to %dth number: ", n - 1);
    
    if (n <= 1) {
        printf("0 ");
    }
    
    if (n > 1) {
        printFibonacciSeries(n , 0, 1);
    }

    return 0;
}
