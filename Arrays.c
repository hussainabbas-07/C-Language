#include<stdio.h>
int main()
{
    int i;
    int array [20,25,30,50];
    printf("sum of array elements");
    for(i=0; i<4; i++)
    {
       i= array[0]+array[1]+array[2]+array[3];
    }
    printf("sum= %d", i);

    return 0;
}