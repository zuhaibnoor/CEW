/* Write a C program to add two distances in inch-feet system using structures. */

#include <stdio.h>

struct Distance {
    int feet;
    float inches;
};

struct Distance addDistances(struct Distance d1, struct Distance d2) {
    struct Distance result;

    result.feet = d1.feet + d2.feet;
    result.inches = d1.inches + d2.inches;

    while (result.inches >= 12.0) {
        result.inches -= 12.0;
        result.feet++;
    }

    return result;
}

int main() {
    struct Distance distance1, distance2, sum;

    printf("Enter first distance:\n");
    printf("Feet: ");
    scanf("%d", &distance1.feet);
    printf("Inches: ");
    scanf("%f", &distance1.inches);

    printf("Enter second distance:\n");
    printf("Feet: ");
    scanf("%d", &distance2.feet);
    printf("Inches: ");
    scanf("%f", &distance2.inches);

    sum = addDistances(distance1, distance2);

    printf("Sum of distances: %d feet %.2f inches", sum.feet, sum.inches);

    return 0;
}
