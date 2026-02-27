#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int dice[]) 
{
    for (int i = 0; i < 5; i++)
    {
        dice[i] = rand() % 6 + 1;
    }
        
}

void showDice(int dice[]) 
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", dice[i]);
    }
    printf("\n");
}

void countFreq(int dice[], int freq[]) 
{
    for (int i = 0; i < 7; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < 5; i++)
    {
        freq[dice[i]]++;
    }
}

int sumDice(int dice[]) 
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += dice[i];
    }
    return sum;
}

int upperScore(int dice[], int num) 
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
         if (dice[i] == num)
         {
            sum += num;
         }
    }
    return sum;
}

int threeOfKind(int dice[]) 
{
    int freq[7];
    countFreq(dice, freq);
    for (int i = 1; i <= 6; i++)
    {
        if (freq[i] >= 3)
        {
             return sumDice(dice);
        }
    }
    return 0;
}

int fourOfKind(int dice[]) 
{
    int freq[7];
    countFreq(dice, freq);
    for (int i = 1; i <= 6; i++)
    {
        if (freq[i] >= 4)
        {
            return sumDice(dice);
        }
    }
    return 0;
}

int fullHouse(int dice[]) 
{
    int freq[7], three = 0, two = 0;
    countFreq(dice, freq);
    for (int i = 1; i <= 6; i++) 
    {
        if (freq[i] == 3) three = 1;
        if (freq[i] == 2) two = 1;
    }
    if (three && two) return 25;
    return 0;
}

int yahtzee(int dice[]) 
{
    int freq[7];
    countFreq(dice, freq);
    for (int i = 1; i <= 6; i++)
    {
        if (freq[i] == 5)
        {
            return 50;
        }
    }
    return 0;
}

int calculateScore(int dice[], int choice) 
{
    if (choice >= 0 && choice <= 5)
    {
        return upperScore(dice, choice + 1);
    }
    if (choice == 6)
    {
        return threeOfKind(dice);
    }
    if (choice == 7)
    {
        return fourOfKind(dice);
    }
    if (choice == 8)
    {
        return fullHouse(dice);
    }
    if (choice == 9)
    {
        return yahtzee(dice);
    }
    if (choice == 10)
    {
        return sumDice(dice);
    }

    return 0;
}

int main() 
{
    srand(time(0));

    int dice[5];
    int score[2][11];

    for (int p = 0; p < 2; p++)
    {
        for (int c = 0; c < 11; c++)
        {
            score[p][c] = -1;
        }
    }

    for (int round = 0; round < 11; round++) 
    {
        for (int player = 0; player < 2; player++) 
        {
            printf("\nPLAYER %d TURN\n", player + 1);
            rollDice(dice);
            showDice(dice);

            printf("Select Category:\n");
            printf("0 Ones  1 Twos  2 Threes  3 Fours  4 Fives  5 Sixes\n");
            printf("6 ThreeKind 7 FourKind 8 FullHouse 9 Yahtzee 10 Chance\n");

            int choice;
            scanf("%d", &choice);

            if (choice < 0 || choice > 10 || score[player][choice] != -1) 
            {
                printf("Invalid choice! Score = 0\n");
                score[player][choice] = 0;
            } 
            else 
            {
                score[player][choice] = calculateScore(dice, choice);
            }

            printf("Score Saved: %d\n", score[player][choice]);
        }
    }

    int total1 = 0, total2 = 0;

    for (int i = 0; i < 11; i++) 
    {
        total1 += score[0][i];
        total2 += score[1][i];
    }

    printf("\nFINAL SCORES\n");
    printf("Player 1: %d\n", total1);
    printf("Player 2: %d\n", total2);

    if (total1 > total2)
    {
         printf("Player 1 Wins!\n");
    }
    else if (total2 > total1)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Match Draw!\n");
    }

        getchar ();
        getchar();
        
        return 0;
}
