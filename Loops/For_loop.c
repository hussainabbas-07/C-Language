/*
Task 1: Write a C program using a for loop to display all prime numbers
from 1 up to a user-defined limit.
Author: Hussain Abbas
Description: This program prints all prime numbers up to a given limit.
Concepts: for loop, nested loop, logical condition, break statement
*/

#include <stdio.h>
int main() 
{
    int limit;
    int isPrime;

    printf("Enter the upper limit: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d are:\n", limit);
    for(int num = 2; num <= limit; num++) {

        isPrime = 1;   // assume number is prime

        for(int i = 2; i <= num / 2; i++) {
            if(num % i == 0) {
                isPrime = 0;   // not prime
                break;
            }
        }

        if(isPrime == 1) {
            printf("%d ", num);
        }
    }

    return 0;
}



/*
Task 2: result checking
Author: Hussain Abbas
Description: This program calculates average marks and determines pass/fail status.
Concepts: for loop, accumulation, condition checking
*/

#include <stdio.h>
int main() 
{
    int subjects;
    float marks, total = 0, average;

    printf("Enter number of subjects: ");
    scanf("%d", &subjects);

    for(int i = 1; i <= subjects; i++) {
        printf("Enter marks for subject %d: ", i);
        scanf("%f", &marks);

        total += marks;
    }

    average = total / subjects;

    printf("Average Marks: %.2f\n", average);

    if(average >= 50)
        printf("Status: Passed\n");
    else
        printf("Status: Failed\n");

    return 0;
}