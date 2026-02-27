#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE 5
#define CATS 13

int dice[DICE];
int scores[CATS] = {0};
int used[CATS] = {0};

char *categories[CATS] = {
    "Ones", "Twos", "Threes", "Fours", "Fives", "Sixes",
    "Three of a kind", "Four of a kind", "Full House",
    "Small Straight", "Large Straight", "Chance", "YAHTZEE"
};

/* Roll dice */
void rollDice() {
    int i;
    for (i = 0; i < DICE; i++)
        dice[i] = rand() % 6 + 1;
}

/* Print dice */
void printDice() {
    int i;
    printf("\nDice: ");
    for (i = 0; i < DICE; i++)
        printf("[%d] ", dice[i]);
    printf("\n");
}



/* Count dice */
int count(int num) {
    int i, c = 0;
    for (i = 0; i < DICE; i++)
        if (dice[i] == num) c++;
    return c;
}

/* Sum of dice */
int sumDice() {
    int i, s = 0;
    for (i = 0; i < DICE; i++)
        s += dice[i];
    return s;
}

/* Calculate score */
int calculateScore(int choice) {
    int i;

    /* Ones to Sixes */
    if (choice >= 1 && choice <= 6)
        return count(choice) * choice;

    /* Three of a kind */
    if (choice == 7) {
        for (i = 1; i <= 6; i++)
            if (count(i) >= 3) return sumDice();
        return 0;
    }

    /* Four of a kind */
    if (choice == 8) {
        for (i = 1; i <= 6; i++)
            if (count(i) >= 4) return sumDice();
        return 0;
    }

    /* Full house */
    if (choice == 9) {
        int two = 0, three = 0;
        for (i = 1; i <= 6; i++) {
            if (count(i) == 2) two = 1;
            if (count(i) == 3) three = 1;
        }
        return (two && three) ? 25 : 0;
    }

    /* Chance */
    if (choice == 12)
        return sumDice();

    /* YAHTZEE */
    if (choice == 13) {
        for (i = 1; i <= 6; i++)
            if (count(i) == 5) return 50;
        return 0;
    }

    return 0;
}

int main() {
    int turns = 0, choice;

    srand(time(NULL));

    while (turns < CATS) {
        rollDice();
        printDice();

        printf("\nSelect category number (1 to 13): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 13 || used[choice - 1]) {
            printf(" Invalid choice! Try again.\n");
            continue;
        }

        scores[choice - 1] = calculateScore(choice);
        used[choice - 1] = 1;
        turns++;
    }

    printf("\n GAME OVER \n");

    getchar();
    getchar();
    return 0;
}