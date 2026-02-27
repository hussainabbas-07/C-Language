/*#include <stdio.h>

// Function to find maximum element
int findMaximum(int data[], int n)
{
    int max = data[0];

    for(int i = 1; i < n; i++)
    {
        if(data[i] > max)
        {
            max = data[i];
        }
    }

    return max;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int data[n];

    // Input array
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    // Find Maximum
    int maximum = findMaximum(data, n);
    printf("Maximum element = %d\n", maximum);

    // Left Rotation
    int temp = data[0];

    for(int i = 0; i < n - 1; i++)
    {
        data[i] = data[i + 1];
    }

    data[n - 1] = temp;

    // Print rotated array
    printf("Array after left rotation:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }

    getchar();
    getchar();
    return 0;
}*/

/*#include <stdio.h>

int findmax(int data[], int n)
{
    int max = data[0];

    for(int i = 1; i < n; i++)
    {
        if(data[i] > max)
        {
            max = data[i];
        }
    }
    
    return max;
}

int main()
{
    int n;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    int data[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    int maximun = findmax(data, n);
    printf("Maximum element = %d\n", maximun);

    int temp = data[0];

    for(int i = 1; i < n - 1; i++)
    {
        data[0] = data[i+1];
    }
    
    data[n - 1] = temp;

    printf("Array after left rotation:\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d", data[i]);
    }

    getchar();
    getchar();
    return 0;
}*/


/*#include <stdio.h>
#include <string.h>

struct employee
{
    int employeeID;
    char Name[20];
    char Designation[25];
    int Salary;
    char task[70];
};

int main()
{
    struct employee Hussain;
    Hussain . employeeID = 1591;
    strcpy(Hussain . Name , "Hussain Abbas");
    strcpy(Hussain . Designation , "Vice President");
    Hussain . Salary = 350000;
    strcpy(Hussain . task , "steering strategic initiatives, managing major departments");

    printf("Employee ID: %d\n", Hussain . employeeID);
    printf("Employee Name: %s\n", Hussain . Name);
    printf("Designation: %s\n", Hussain . Designation);
    printf("Salary: %d\n", Hussain . Salary);
    printf("Task: %s\n", Hussain . task);

    getchar();
    getchar();
    return 0;
}*/

/*#include <stdio.h>

int main()
{
    int matrix[2][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };

    int i, j;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");

    }

    getchar();
    getchar();
    return 0;
}*/

/*#include <stdio.h>
int main()
{
    int matrix[2][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };

    int i, j;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    getchar();
    getchar();
    return 0;
}*/

/*#include <stdio.h>

void updateValue(int *num)
{
    *num = *num + 10;
}

int main()
{
    int value = 20;

    printf("Value before function call: %d\n", value);

    updateValue(&value);

    printf("Value after function call: %d\n", value);

    getchar();
    getchar();
    return 0;
}*/

#include <stdio.h>

int findmaximum(int data[], int n)
{
    int max = data[0];

    for(int i = 1; i < n; i++)
    {
        if(data[i] > max)
        {
            max = data[i];
        }
    }

    return max;
}

int main()
{
    int n;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    int data[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    int maximum = findmaximum(data, n);
    printf("maximum value = %d\n", maximum);

    int temp = data[0];

    for (int )
}