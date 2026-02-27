// EXAMPLE 1:
#include <stdio.h>
int main() 
{
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age < 13) 
    {
        printf("You are child\n");
    } 
    else if (age >= 13 && age < 20) 
    {
        printf("You are teenager.\n");
    } else 
    {
        printf("You are adult.\n");
    }

    return 0;
}

// EXAMPLE 2:
#include <stdio.h>
int main() 
{
    int age;
    char citizen;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Are you a citizen? (Y/N): ");
    scanf(" %c", &citizen);

    if(age >= 18 && (citizen == 'Y' || citizen == 'y')) 
    {
        printf("You are eligible to vote.\n");
    } 
    else if(age < 18) 
    {
        printf("You are not eligible to vote: Underage.\n");
    } else 
    {
        printf("You are not eligible to vote: Not a citizen.\n");
    }

    return 0;
}