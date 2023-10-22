/** 
Write a C program that accepts an employee's ID, total worked hours in a month and
the amount received per hour. Print the ID and salary (with two decimal places) of the
employee for a particular month.  **/

#include <stdio.h>

int main() {

    int employee_ID;
    float total_hours, hourly_rate, salary;

    printf("Enter employee's ID: ");
    scanf("%d", &employee_ID);

    printf("Enter total worked hours in a month: ");
    scanf("%f", &total_hours);

    printf("Enter the amount received per hour: ");
    scanf("%f", &hourly_rate);

    salary = total_hours * hourly_rate;

    printf("Employee ID: %d\n", employee_ID);
    printf("Salary for the month: %.2f\n", salary);

    return 0;
}
