/*
Task: password verification
Author: Hussain Abbas
Description: Verifies password with maximum 3 attempts using do-while loop.
Concepts: do-while loop, counter, condition checking
*/

#include <stdio.h>
int main() 
{
    int password;
    int attempts = 0;
    const int correctPassword = 1234;

    do {
        printf("Enter password: ");
        scanf("%d", &password);

        attempts++;

        if(password == correctPassword) {
            printf("Access Granted.\n");
            break;
        } else {
            printf("Incorrect Password.\n");
        }

    } while(attempts < 3);

    if(attempts == 3 && password != correctPassword) {
        printf("Access Denied. Maximum attempts reached.\n");
    }
    return 0;
}