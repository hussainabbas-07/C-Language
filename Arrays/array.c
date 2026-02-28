/*
Task 1: Print temperature of whole week by using array
Author: Hussain Abbas
*/

#include <stdio.h>
int main() 
{
    int temp[7];
    int i;

    printf("Enter temperature for 7 days:\n");
    for(i = 0; i < 7; i++) {
        printf("Day %d: ", i + 1);
        scanf("%d", &temp[i]);
    }

    printf("\nTemperatures of the whole week:\n");
    for(i = 0; i < 7; i++) {
        printf("Day %d temperature: %d\n", i + 1, temp[i]);
    }

    getchar();
    getchar();
    return 0;
}



/*
Task 2: Find the maximum value among the given numbers 
Author: Hussain Abbas
*/

#include <stdio.h>
int main() 
{
    int arr[10];
    int i, max;

    printf("Enter 10 numbers:\n");
    for(i = 0; i < 10; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    max = arr[0];
    
    for(i = 1; i < 10; i++) 
    {
        if(arr[i] > max) 
        {
            max = arr[i];
        }
    }

    printf("Maximum value = %d", max);

    getchar();
    getchar();
    return 0;
}
