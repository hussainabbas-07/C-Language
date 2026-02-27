// EXAMPLE 1:
/*#include <stdio.h>

int main() {
    int marks[5] = {89, 65, 87, 80, 70};

    printf("Marks for Subject 1: %d\n", marks[0]);
    printf("Marks for Subject 2: %d\n", marks[1]);
    printf("Marks for Subject 3: %d\n", marks[2]);
    printf("Marks for Subject 4: %d\n", marks[3]);
    printf("Marks for Subject 5: %d\n", marks[4]);

    getchar(); 
    return 0;
}*/

// EXAMPLE 2A:
// Program to find the average of n (n < 10) numbers using arrays
/*#include <stdio.h>

int main()
{
    int marks[10], i, n, sum = 0, average;

    printf("Enter n: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &marks[i]);
        sum = sum + marks[i];
    }

    average = sum / n;
    printf("Average = %d\n", average);


    getchar();
    getchar();
    return 0;
}*/

//EXAMPLE 2B:
/*#include <stdio.h>

int main()
{
    int array[5];
    int square[5];
    int i;

    // Input values
    for(i = 0; i < 5; i++)
    {
        printf("Enter the value for array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    // Calculate and print squares
    for(i = 0; i < 5; i++)
    {
        square[i] = array[i] * array[i];
        printf("Square of array element %d is \t %d\n", array[i], square[i]);
    }

    getchar ();
    getchar ();
    return 0;
}*/

// EXAMPLE 03:
/*#include<stdio.h>
int main()
{
  int array [10];
  int i = 0;
  for(i=0; i<6; i++)
  { 
    printf("Enter the Value for Array:");
    scanf("%d",&array[i]);
  }

  for(i=0; i<6; i++)
  {
    if (array[i]%2==0)
    {
      printf("\n %d is Even Number in an Array", array[i]);
    }
    else
    {
      printf("\n %d is Odd Number in an Array", array[i]);
    }
  }

  getchar ();
  getchar ();

  return 0;
}*/


//EXAMPLE 04:
/*#include<stdio.h>
float getAverage (int array[], int arraysize);
int main()
{
  int marks [5] = {0,0,0,0,0};
  int i=0;
  float average = 0.0;
  for(i=0; i<5; i++)
  {
    scanf("%d",&marks[i]);
  }

  average = getAverage (marks, 5);
  printf("An Average marks of the student in the first semester is: %.2f", average);

  getchar();
  getchar ();
  return 0;
}

float getAverage (int array[], int arraysize)
{
    int i;
    int sum = 0;
    float average;

    for(i = 0; i < arraysize; i++)
    {
        sum = sum + array[i];
    }

    average = (float)sum / arraysize;
    return average;
}*/

// TASK 01:
/*#include <stdio.h>
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
}*/


//TASK 02:
/*#include <stdio.h>
int main() 
{
    int arr[5];
    int i, sum = 0;
    float average;

    printf("Enter 5 numbers:\n");
    for(i = 0; i < 5; i++) 
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = sum / 5.0;
    
    printf("Average = %.2f", average);

    getchar();
    getchar();
    return 0;
}*/


//TASK 03:
/*#include <stdio.h>
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
}*/


//TASK 04:
#include <stdio.h>
float calculateAverage(int temp[]) {
    int i, sum = 0;

    for(i = 0; i < 7; i++) {
        sum = sum + temp[i];
    }

    return sum / 7.0;
}
int main() 
{
    int temp[7];
    int i;
    float avg;
  
    printf("Enter temperature for 7 days:\n");
    for(i = 0; i < 7; i++) 
    {
        printf("Day %d: ", i + 1);
        scanf("%d", &temp[i]);
    }

    avg = calculateAverage(temp);
  
    printf("\nAverage temperature of the week = %.2f", avg);

    getchar();
    getchar();
    return 0;
}