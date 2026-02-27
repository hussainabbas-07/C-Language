 // Q1 self test
/*#include <stdio.h>
#include <ctype.h>
int main()
{
    char name[100];
    char letter;
    int i, count = 0, constants = 0;

    printf("Enter your ful name: ");
    fgets(name, 100, stdin);

    printf("Enter a letter: ");
    scanf(" %c", &letter);

    letter = tolower(letter);
    name[0] = toupper(name[0]);

    for (i = 0; name[i] != '\0'; i++)
    {
        char ch = tolower(name[i]);

        if (ch == letter)
        {
            count++;
        }

        if (name[i]== ' ' && name[i+1] != '\0')
        {
            name[i+1] = toupper(name[i+1]);
        }

        if (isalpha(ch))
        {
            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
            {
                constants++;
            }

        }
    }

    printf("%d times letter '%c' appears. \n", count, letter);
    printf("Name with capital letters: %s", name);
    printf("Total constants: %d\n", constants);

    getchar();
    getchar();    // prog runs successfully 

    return 0;
}*/

// Q2 self test
/*#include <stdio.h>
#include <ctype.h>

void charFrequency(char str[]);
void reverseWords(char str[]);
void removeVowels(char str[]);

int main()
{
    char title[100];
    char letter;
    int i, count = 0, vowels = 0, consonants = 0, chars = 0;

    printf("Enter course title: ");
    fgets(title, 100, stdin);

    printf("Enter a letter: ");
    scanf(" %c", &letter);
    letter = tolower(letter);

    title[0] = toupper(title[0]);

    for (i = 0; title[i] != '\0'; i++)
    {
        char ch = tolower(title[i]);

        if (title[i] != '\n')
        {
            chars++;
        }

        if (ch == letter)
        {
            count++;
        }

        if (title[i] == ' ')
        {
            title[i+1] = toupper(title[i+1]);
        }

        if (isalpha(ch))
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
    }

    printf("Letter count: %d\n", count);
    printf("Capitalized Title: %s", title);

    printf("First letter of each words: ");
    printf("%c ", title[0]);

    for (i = 0; title[i] != '\0'; i++)
    {
        if (title[i] == ' ')
        {
            printf("%c ", title[i+1]);
        }
    }

    printf("\n");

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    charFrequency(title);
    reverseWords(title);
    removeVowels(title);

    getchar();
    getchar();

    return 0;
}

void charFrequency(char str[])
{
    int i, j, count;

    printf("\nCharacter Frequency:\n");

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\n')
        {
            continue;
        }

        count = 1;

        for (j = i + 1; str[j] != '\0'; j++)
        {
            if (str[i] == str[j])
            {
                count++;
                str[j] = ' ';
            }
        }

        printf("%c = %d\n", str[i], count);
    }
}

void reverseWords(char str[])
{
    int i = 0, start, end;

    printf("\nReversed Words:\n");

    while (str[i] != '\0')
    {
        if (str[i != ' '])
        {
            start = i;

            while(str[i] != ' ' && str[i] != '\0')
            {
                i++;
                end = i - 1;
            }

            while (end >= start)
            {
                printf("%c", str[end--]);
            }

            printf(" ");
        }
        i++;
    }
    printf("\n");
}

void removeVowels(char str[])
{
    int i;

    printf("\nWithout Vowels:\n");

    for (i = 0; str[i] != '\0'; i++)
    {
        char ch = tolower(str[i]);
        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'))
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}*/

// Q8:
/*#include <stdio.h>
int main()
{
    float distance[7];
    float total = 0, min;
    int i, minDay;

    for (i = 0; i < 7; i++)
    {
        printf("Enter distance for day %d (km): ", i + 1);
        scanf("%f", &distance[i]);
    }

    min = distance[0];
    minDay = 1;

    for (i = 0; i < 7; i++)
    {
        total += distance[i];

        if (distance[i] < min)
        {
            min = distance[i];
            minDay = i + 1;
        }
    }

    printf("\nTotal distance covered: %.2f km", total);
    printf("\nShortest distance on Day %d: %.2f km\n", minDay, min);

    getchar();
    getchar();
    return 0;
}*/

/*void checkPin(int attempts)
{
    int pin;

    if (attempts == 0)
    {
        printf("Access denied!");
    }

    printf("Enter a pin:");
    scanf("%d", &pin);

    if (pin == 6969)
    {
        printf("Access granted!");
    }

    else
    {
        printf("Access denied!. %d attempts left", attempts - 1);
        checkPin(attempts - 1);
    }
}

int main()
{
    checkPin(3);

    getchar();
    getchar();

    return 0;
}*/

// Q12:
/*#include <stdio.h>
int main()
{
    int minutes[7];
    int total = 0, max;
    int i, maxDay;

    for (i = 0; i < 7; i++)
    {
        printf("Enter excercise minutes for day %d:", i + 1);
        scanf("%d", &minutes[i]);
    }

    max = minutes[0];
    maxDay = 1;

    for (i = 0; i < 7; i++)
    {
        total = total + minutes[i];

        if (minutes[i] > max)
        {
            max = minutes[i];
            maxDay = i + 1;
        }
    }

    printf("Total minutes spent excercising: %d", total);
    printf("longest excercise was on day %d (%d minutes)\n", maxDay, max);

    getchar();
    getchar();

    return 0;

}*/

// Q13:
/*#include <stdio.h>
int main()
{
    float sales[7];
    float total = 0;
    int max, maxDay;
    int i;

    for (i = 0; i < 7; i++)
    {
        printf("Enter number of sales for day %d: ", i + 1);
        scanf("%d", &sales[i]);
    }

    max = sales[0];
    maxDay = 1;

    for (i = 0; i < 7; i++)
    {
        total = total + sales[i];

        if (sales[i] > max)
        {
            max = sales[i];
            maxDay = i + 1;
        }
    }

    printf("total sales = %.2f\n", total);
    printf("Highest sales on day %d: %.2f", maxDay, max);
}*/


/*void charFrequency(char str[])
{
    int i, j, count;

    printf("Character Frequency:\n ");

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\n')
        {
            continue;
            count = 1;
        }

        for (j = i + 1; str[j] != '\0'; j++)
        {
            if (str[i] == str[j])
            {
                count++;
                str[j] = ' ';
            }
        }
        printf("%c = %d\n", str[i], count);
    }
}


void charFrequency(char str[])
{
    int i, j, count;

    printf("Character Frequency: ");

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\n')
        {
            continue;
            count = 1;
        }

        for (j = i + 1; str[j] != '\0'; j++)
        {
            if (str[i] == str[j])
            {
                count++;
                str[j] = ' ';
            }
        }
        printf("%c = %d", str[i], count);
    }
}*/

void reverseVowels(char str[])
{
    int i = 0, start, end;

    printf("Reverse words: \n");

    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            start = 1;
        }

        while (str[i] != ' ' && str[i] != '\0')
        {
            i++;
            end = i - 1;
        }
        while (end >= start)
        {
            printf("%c", str{end--});

            printf(" ");
        }
        i++;
    }
    printf("\n");
    
}