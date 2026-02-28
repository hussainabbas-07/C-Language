/*
Task 1: number guessing game
Author: Hussain Abbas
Description: Simple number guessing game using while loop.
Concepts: while loop, condition checking, counter
*/

#include <stdio.h>
int main() 
{
    int secret = 7;   // predefined number
    int guess = 0;
    int attempts = 0;

    while(guess != secret) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if(guess > secret)
            printf("Too high!\n");
        else if(guess < secret)
            printf("Too low!\n");
        else
            printf("Correct! You guessed in %d attempts.\n", attempts);
    }

    return 0;
}



/*
Task 2: sum of digits
Author: Hussain Abbas
Description: This program calculates the sum of digits of a given number using a while loop.
Concepts: while loop, modulus operator, integer division
*/

#include <stdio.h>
int main() 
{
    int number;
    int sum = 0;
    int digit;

    printf("Enter a number: ");
    scanf("%d", &number);
    // While loop runs until number becomes 0
    while(number > 0) {

        digit = number % 10;    // Extract last digit
        sum = sum + digit;       // Add digit to sum
        number = number / 10;  // Remove last digit

    }

    printf("Sum of digits: %d\n", sum);

    return 0;
}