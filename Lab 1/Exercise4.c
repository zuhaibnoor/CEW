/* Write a C program to convert a decimal number into binary number. s*/

#include <stdio.h>

int main() {
    int decimalNumber, binaryNumber = 0, remainder, base = 1;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    while (decimalNumber > 0) {
        remainder = decimalNumber % 2;
        binaryNumber = binaryNumber + remainder * base;
        decimalNumber = decimalNumber / 2;
        base = base * 10;
    }

    printf("Binary representation: %d\n", binaryNumber);

    return 0;
}
