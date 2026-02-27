// Q1
/*#include <stdio.h>
#include <ctype.h>
int main()
{
    char name[100];
    char letter;
    int i, count = 0, constants = 0;

    printf("Enter your full name: ");
    fgets(name, 100, stdin);

    printf("Enter a letter to count: ");
    scanf(" %c", &letter);

    letter = tolower(letter);
    name[0] = toupper(name[0]);

    for (i = 0; name[i] != '\0'; i++)
    {
        char ch = tolower(name[i]);

        if (ch==letter)
        {
            count++;
        }

        if (name[i] == ' ' && name[i+1] != '\0')
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

    printf("\nLetter '%c' appears %d times. \n", letter, count);
    printf("Name with capital letters: %s", name);
    printf("Total constants: %d\n", constants);

    getchar();
    getchar();

    return 0;
}*/

// Q2:
#include <stdio.h>
#include <ctype.h>

// function declarations
void charFrequency(char str[]);
void reverseWords(char str[]);
void removeVowels(char str[]);

int main()
{
    char title[100];
    char letter;
    int i;
    int count = 0, vowels = 0, consonants = 0, chars = 0;

    printf("Enter course title: ");
    fgets(title, 100, stdin);

    printf("Enter a letter: ");
    scanf(" %c", &letter);
    letter = tolower(letter);

    // Capitalize first letter
    title[0] = toupper(title[0]);

    for (i = 0; title[i] != '\0'; i++)
    {
        char ch = tolower(title[i]);

        // count total characters (excluding newline)
        if (title[i] != '\n')
            chars++;

        // count user-specified letter
        if (ch == letter)
            count++;

        // capitalize after space
        if (title[i] == ' ')
            title[i + 1] = toupper(title[i + 1]);

        // count vowels and consonants
        if (isalpha(ch))
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    // outputs
    printf("\nLetter count: %d\n", count);
    printf("Capitalized Title: %s", title);

    // extract first letter of each word
    printf("First letters of each word: ");
    printf("%c ", title[0]);
    for (i = 0; title[i] != '\0'; i++)
        if (title[i] == ' ')
            printf("%c ", title[i + 1]);
    printf("\n");

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Total Characters: %d\n", chars);

    // function calls
    charFrequency(title);
    reverseWords(title);
    removeVowels(title);

    getchar();
    getchar();
    return 0;
}

// ---------------- FUNCTIONS ----------------

void charFrequency(char str[])
{
    int i, j, count;

    printf("\nCharacter Frequency:\n");

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\n')
            continue;

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

    printf("\nReversed Words: ");

    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            start = i;
            while (str[i] != ' ' && str[i] != '\0')
                i++;
            end = i - 1;

            while (end >= start)
                printf("%c", str[end--]);

            printf(" ");
        }
        i++;
    }
    printf("\n");
}

void removeVowels(char str[])
{
    int i;

    printf("\nWithout Vowels: ");

    for (i = 0; str[i] != '\0'; i++)
    {
        char ch = tolower(str[i]);
        if (!(ch == 'a' || ch == 'e' || ch == 'i' ||
              ch == 'o' || ch == 'u'))
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

//Q3:
/*#include <stdio.h>
#include <ctype.h>

// function declarations
void charFrequency(char name[]);
void toTitleCase(char name[]);
void firstLetters(char name[]);

int main()
{
    char name[100];
    int i, vowels = 0;
    int firstLen = 0, lastLen = 0;

    printf("Enter full name: ");
    fgets(name, 100, stdin);

    // count vowels
    for (i = 0; name[i] != '\0'; i++)
    {
        char ch = tolower(name[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u')
        {
            vowels++;
        }
    }

    // length of first name
    i = 0;
    while (name[i] != ' ' && name[i] != '\0')
    {
        firstLen++;
        i++;
    }

    // length of last name
    if (name[i] == ' ')
        i++;
    while (name[i] != '\n' && name[i] != '\0')
    {
        lastLen++;
        i++;
    }

    printf("\nTotal Vowels: %d\n", vowels);
    printf("First Name Length: %d\n", firstLen);
    printf("Last Name Length: %d\n", lastLen);

    printf("First letters: ");
    firstLetters(name);

    toTitleCase(name);
    printf("\nTitle Case Name: %s", name);

    charFrequency(name);

    return 0;
}

// ---------------- FUNCTIONS ----------------

void charFrequency(char name[])
{
    int i, j, count;

    printf("\nCharacter Frequency:\n");

    for (i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == ' ' || name[i] == '\n')
            continue;

        count = 1;

        for (j = i + 1; name[j] != '\0'; j++)
        {
            if (name[i] == name[j])
            {
                count++;
                name[j] = ' ';
            }
        }
        printf("%c = %d\n", name[i], count);
    }
}

void toTitleCase(char name[])
{
    int i;
    name[0] = toupper(name[0]);

    for (i = 1; name[i] != '\0'; i++)
    {
        if (name[i - 1] == ' ')
            name[i] = toupper(name[i]);
    }
}

void firstLetters(char name[])
{
    int i;
    printf("%c ", name[0]);

    for (i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == ' ')
            printf("%c ", name[i + 1]);
    }
    printf("\n");
}*/

// Q4:
/*#include <stdio.h>
#include <ctype.h>

// function declarations
void reverseWords(char name[]);
void nameLengths(char name[]);
void removeVowels(char name[]);

int main()
{
    char name[100];

    printf("Enter full name: ");
    fgets(name, 100, stdin);

    reverseWords(name);
    nameLengths(name);
    removeVowels(name);

    getchar();
    getchar();
    return 0;
}

void reverseWords(char name[])
{
    int i = 0, start, end;

    printf("\nReversed Words: ");

    while (name[i] != '\0')
    {
        if (name[i] != ' ')
        {
            start = i;

            while (name[i] != ' ' && name[i] != '\0')
                i++;

            end = i - 1;

            while (end >= start)
                printf("%c", name[end--]);

            printf(" ");
        }
        i++;
    }
    printf("\n");
}

void nameLengths(char name[])
{
    int i = 0;
    int first = 0, last = 0;

    while (name[i] != ' ' && name[i] != '\0')
    {
        first++;
        i++;
    }

    if (name[i] == ' ')
        i++;

    while (name[i] != '\n' && name[i] != '\0')
    {
        last++;
        i++;
    }

    printf("\nFirst Name Length: %d", first);
    printf("\nLast Name Length: %d\n", last);
}

void removeVowels(char name[])
{
    int i;

    printf("\nWithout Vowels: ");

    for (i = 0; name[i] != '\0'; i++)
    {
        char ch = tolower(name[i]);

        if (!(ch == 'a' || ch == 'e' || ch == 'i' ||
              ch == 'o' || ch == 'u'))
        {
            printf("%c", name[i]);
        }
    }
    printf("\n");
}*/

// Q5:
/*#include <stdio.h>
#include <ctype.h>

void charFrequency(char title[]);

int main()
{
    char title[100];
    int i, chars = 0;

    printf("Enter book title: ");
    fgets(title, 100, stdin);

    // Capitalize first letter of each word
    title[0] = toupper(title[0]);

    for (i = 0; title[i] != '\0'; i++)
    {
        if (title[i] != '\n')
            chars++;

        if (title[i] == ' ')
            title[i + 1] = toupper(title[i + 1]);
    }

    printf("\nCapitalized Title: %s", title);

    printf("First letters: ");
    printf("%c ", title[0]);
    for (i = 0; title[i] != '\0'; i++)
        if (title[i] == ' ')
            printf("%c ", title[i + 1]);

    printf("\nTotal Characters: %d\n", chars);

    charFrequency(title);

    getchar();
    getchar();
    return 0;
}

void charFrequency(char title[])
{
    int count[256] = {0};
    int i;

    printf("\nCharacter Frequency:\n");

    for (i = 0; title[i] != '\0'; i++)
        count[(int)title[i]]++;

    for (i = 0; i < 256; i++)
        if (count[i] > 0 && i != '\n')
            printf("%c = %d\n", i, count[i]);
}*/

 // Q6:
/*#include <stdio.h>
#include <ctype.h>

//function declarations
void charFrequency(char str[]);
void toTitleCase(char str[]);
void reverseWords(char str[]);
void removeVowels(char str[]);

int main()
{
    char movie[100];
    char ch;
    int i, count = 0;
    int vowels = 0, consonants = 0, characters = 0;

    printf("Enter movie title: ");
    fgets(movie, 100, stdin);

    printf("Enter a character to search: ");
    scanf(" %c", &ch);
    ch = tolower(ch);

    //count characters, vowels, consonants, and given character 
    for (i = 0; movie[i] != '\0'; i++)
    {
        char c = tolower(movie[i]);

        if (movie[i] != '\n')
            characters++;

        if (c == ch)
            count++;

        if (isalpha(c))
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    toTitleCase(movie);

    printf("\nTitle Case: %s", movie);

    printf("First letters: ");
    printf("%c ", movie[0]);
    for (i = 0; movie[i] != '\0'; i++)
        if (movie[i] == ' ')
            printf("%c ", movie[i + 1]);

    printf("\nCharacter '%c' count: %d\n", ch, count);
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Total Characters: %d\n", characters);

    charFrequency(movie);
    reverseWords(movie);
    removeVowels(movie);

    getchar();
    getchar();
    return 0;
}*/

/* ---------- FUNCTIONS ---------- */

/*void toTitleCase(char str[])
{
    int i;
    str[0] = toupper(str[0]);

    for (i = 1; str[i] != '\0'; i++)
        if (str[i - 1] == ' ')
            str[i] = toupper(str[i]);
}

void charFrequency(char str[])
{
    int freq[256] = {0};
    int i;

    printf("\nCharacter Frequency:\n");

    for (i = 0; str[i] != '\0'; i++)
        freq[(int)str[i]]++;

    for (i = 0; i < 256; i++)
        if (freq[i] > 0 && i != '\n')
            printf("%c = %d\n", i, freq[i]);
}

void reverseWords(char str[])
{
    int i = 0, start, end;

    printf("\nReversed Words: ");

    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            start = i;

            while (str[i] != ' ' && str[i] != '\0')
                i++;

            end = i - 1;

            while (end >= start)
                printf("%c", str[end--]);

            printf(" ");
        }
        i++;
    }
    printf("\n");
}

void removeVowels(char str[])
{
    int i;
    printf("Without Vowels: ");

    for (i = 0; str[i] != '\0'; i++)
    {
        char c = tolower(str[i]);
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
            printf("%c", str[i]);
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

    // Input distances
    for (i = 0; i < 7; i++)
    {
        printf("Enter distance for day %d (km): ", i + 1);
        scanf("%f", &distance[i]);
    }

    // Initialize minimum
    min = distance[0];
    minDay = 1;

    // Calculate total and find minimum
    for (i = 0; i < 7; i++)
    {
        total += distance[i];

        if (distance[i] < min)
        {
            min = distance[i];
            minDay = i + 1;
        }
    }

    // Output
    printf("\nTotal distance covered: %.2f km", total);
    printf("\nShortest distance on Day %d: %.2f km\n", minDay, min);

    return 0;
}*/

// Q9:
/*#include <stdio.h>

int main()
{
    int customers[7];
    int total = 0;
    int max, maxDay;
    int i;

    // Input customer visits
    for (i = 0; i < 7; i++)
    {
        printf("Enter customers for day %d: ", i + 1);
        scanf("%d", &customers[i]);
    }

    // Assume first day has maximum customers
    max = customers[0];
    maxDay = 1;

    // Calculate total and find maximum
    for (i = 0; i < 7; i++)
    {
        total += customers[i];

        if (customers[i] > max)
        {
            max = customers[i];
            maxDay = i + 1;
        }
    }

    // Output results
    printf("\nTotal customers in the week: %d", total);
    printf("\nMaximum customers on Day %d: %d\n", maxDay, max);

    getchar();
    getchar();
    return 0;
}*/

// Q10:
/*#include <stdio.h>

// Function to calculate average temperature
float calculateAverage(int temp[], int size)
{
    int sum = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        sum += temp[i];
    }

    return (float)sum / size;
}

// Function to find highest & lowest temperature
void findExtremes(int temp[], int size)
{
    int i;
    int max = temp[0], min = temp[0];
    int maxDay = 1, minDay = 1;

    for (i = 1; i < size; i++)
    {
        if (temp[i] > max)
        {
            max = temp[i];
            maxDay = i + 1;
        }

        if (temp[i] < min)
        {
            min = temp[i];
            minDay = i + 1;
        }
    }

    printf("\nHighest Temperature: %d on Day %d", max, maxDay);
    printf("\nLowest Temperature: %d on Day %d\n", min, minDay);
}

int main()
{
    int temperature[7];
    int i;
    float avg;

    for (i = 0; i < 7; i++)
    {
        printf("Enter temperature for Day %d: ", i + 1);
        scanf("%d", &temperature[i]);
    }

    avg = calculateAverage(temperature, 7);
    printf("\nAverage Temperature: %.2f", avg);

    findExtremes(temperature, 7);

    getchar();
    getchar();
    return 0;
}*/

// Q11:
/*#include <stdio.h>

int main()
{
    float distance[7];
    float total = 0, min;
    int i, minDay;

    // input distances
    for (i = 0; i < 7; i++)
    {
        printf("Enter distance for day %d (km): ", i + 1);
        scanf("%f", &distance[i]);
    }

    // assume first day is minimum
    min = distance[0];
    minDay = 1;

    // calculate total and find minimum
    for (i = 0; i < 7; i++)
    {
        total = total + distance[i];

        if (distance[i] < min)
        {
            min = distance[i];
            minDay = i + 1;
        }
    }

    printf("\nTotal distance covered = %.2f km\n", total);
    printf("Shortest distance was on Day %d (%.2f km)\n", minDay, min);

    return 0;
}*/

// Q12:
/*#include <stdio.h>

int main()
{
    int minutes[7];
    int total = 0, max;
    int i, maxDay;

    // input exercise minutes
    for (i = 0; i < 7; i++)
    {
        printf("Enter exercise minutes for day %d: ", i + 1);
        scanf("%d", &minutes[i]);
    }

    // assume first day has maximum exercise
    max = minutes[0];
    maxDay = 1;

    // calculate total and find maximum
    for (i = 0; i < 7; i++)
    {
        total = total + minutes[i];

        if (minutes[i] > max)
        {
            max = minutes[i];
            maxDay = i + 1;
        }
    }

    printf("\nTotal exercise minutes = %d minutes\n", total);
    printf("Longest exercise was on Day %d (%d minutes)\n", maxDay, max);

    return 0;
}*/

// Q13:
/*#include <stdio.h>

int main()
{
    float sales[7];
    float total = 0, max;
    int i, maxDay;

    // input sales amounts
    for (i = 0; i < 7; i++)
    {
        printf("Enter sales amount for day %d: ", i + 1);
        scanf("%f", &sales[i]);
    }

    // assume first day has highest sales
    max = sales[0];
    maxDay = 1;

    // calculate total sales and find maximum
    for (i = 0; i < 7; i++)
    {
        total = total + sales[i];

        if (sales[i] > max)
        {
            max = sales[i];
            maxDay = i + 1;
        }
    }

    printf("\nTotal Sales = %.2f\n", total);
    printf("Highest Sales were on Day %d (%.2f)\n", maxDay, max);

    return 0;
}*/

// Q14:
/*#include <stdio.h>

int main()
{
    int parcels[7];
    int total = 0, max;
    int i, maxDay;

    // input parcels delivered
    for (i = 0; i < 7; i++)
    {
        printf("Enter parcels delivered on day %d: ", i + 1);
        scanf("%d", &parcels[i]);
    }

    // assume first day has maximum parcels
    max = parcels[0];
    maxDay = 1;

    // calculate total and find maximum
    for (i = 0; i < 7; i++)
    {
        total = total + parcels[i];

        if (parcels[i] > max)
        {
            max = parcels[i];
            maxDay = i + 1;
        }
    }

    printf("\nTotal parcels delivered = %d\n", total);
    printf("Maximum parcels delivered on Day %d (%d parcels)\n", maxDay, max);

    return 0;
}*/

// Q15:
/*#include <stdio.h>

void checkCard(int attempts)
{
    int card;

    // agar attempts khatam
    if (attempts == 0)
    {
        printf("Card blocked due to multiple incorrect attempts!\n");
        return;
    }

    printf("Enter ATM card number: ");
    scanf("%d", &card);

    // correct card number assume kar lo
    if (card == 1234)
    {
        printf("Card verified. You can proceed with transactions!\n");
    }
    else
    {
        printf("Incorrect card number. Attempts left: %d\n", attempts - 1);
        checkCard(attempts - 1);   // recursion
    }
}

int main()
{
    checkCard(3);   // 3 attempts
    return 0;
}*/

// Q16:
/*#include <stdio.h>

void checkRoll(int attempts)
{
    int roll;
    char name[50];

    // base case
    if (attempts == 0)
    {
        printf("Incorrect credentials\n");
        return;
    }

    printf("Enter your name: ");
    scanf(" %[^\n]", name);

    printf("Enter roll number: ");
    scanf("%d", &roll);

    // predefined correct roll number
    if (roll == 101)
    {
        printf("%s, access provided\n", name);
    }
    else
    {
        printf("Wrong roll number. Attempts left: %d\n", attempts - 1);
        checkRoll(attempts - 1);   // recursion
    }
}

int main()
{
    checkRoll(3);   // 3 attempts
    return 0;
}*/

// Q17:
/*#include <stdio.h>

void checkPIN(int attempts)
{
    int pin;

    // base case
    if (attempts == 0)
    {
        printf("Access denied!\n");
        return;
    }

    printf("Enter PIN: ");
    scanf("%d", &pin);

    // correct PIN
    if (pin == 1234)
    {
        printf("Access granted!\n");
    }
    else
    {
        printf("Incorrect PIN. Attempts left: %d\n", attempts - 1);
        checkPIN(attempts - 1);   // recursion
    }
}

int main()
{
    checkPIN(3);   // 3 attempts
    return 0;
}*/

// Q18:
/*#include <stdio.h>
#include <string.h>

void checkWiFi(int attempts)
{
    char password[20];

    // base case
    if (attempts == 0)
    {
        printf("Unable to connect to Wi-Fi. Try again later.\n");
        return;
    }

    printf("Enter Wi-Fi password: ");
    scanf("%s", password);

    // correct password
    if (strcmp(password, "wifi123") == 0)
    {
        printf("Wi-Fi connected successfully!\n");
    }
    else
    {
        printf("Incorrect password. Attempts left: %d\n", attempts - 1);
        checkWiFi(attempts - 1);   // recursion
    }
}

int main()
{
    checkWiFi(3);   // 3 attempts
    return 0;
}*/

// Q19:
/*void membershipID(int attempts)
{
    int id;

    if (attempts == 0)
    {
        printf("Wrong id you cant borrow a book.\n");
        return;
    }

    printf("Enter an id:");
    scanf("%d", &id);

    if  (id == 6969)
    {
        printf("Membership verified. You can borrow the book!");
    }

    else
    {
        printf("Access denied. Cannot borrow the book!. Attempts left: %d\n", attempts - 1);
        membershipID(attempts - 1);
    }
}

int main()
{
    membershipID(3);
    getchar();
    getchar();
    return 0;
}*/

// Q20:
/*void licenseKey(int attempts)
{
    int key;

    if (attempts == 0)
    {
        printf("Activation failed. Contact support.");
        return;
    }

    printf("Enter a key:");
    scanf("%d", &key);

    if (key == 6969)
    {
        printf("License verified. Software activated!");
    }

    else
    {
        printf("Activation failed. Contact support. Attempts left: %d\n", attempts - 1);
        licenseKey(attempts - 1);
    }
}

int main()
{
    licenseKey(3);

    getchar();
    getchar();
    return 0;
}*/






