/** Write a C program that takes the height and width of a rectangle as an input from user
and compute the perimeter and area of a rectangle. **/

#include <stdio.h>

int main() {

    float height, width, area, perimeter;

    printf("Enter height of the rectangle: ");
    scanf("%f", &height);

    printf("Enter width of the rectangle: ");
    scanf("%f", &width);

    area = height * width;
    perimeter = 2 * (height + width);

    printf("Area of the rectangle: %.2f\n", area);
    printf("Perimeter of the rectangle: %.2f", perimeter);

    return 0;
}


