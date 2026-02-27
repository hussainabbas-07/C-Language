/*#include <stdio.h>

void change(int x)
{
    x = 10;
}

int main()
{
    int a = 5;
    change(a);

    printf("%d", a);

    getchar();
    return 0;
}


#include <stdio.h>

void change(int *x)
{
    *x = 10;
}

int main()
{
    int a = 5;
    change(&a);
    printf("%d", a);
    return 0;
}*/


/*#include <stdio.h>

void changebyref(int *x)
{
    *x = 20;
}

int main()
{
    int a = 15;
    changebyref(&a);
    printf("%d", a);

    getchar();
    return 0;
}*/

#include <stdio.h>

void change(int *a)
{
    *a = 100;
}

int main()
{
    int x = 250;
    change(&x);
    printf("x = %d",x);

    getchar();
    return 0;
}