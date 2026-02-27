#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int dice;
    int player1score=0;
    int player2score=0;
    int player1rolls=0;
    int player2rolls=0;
    int player1max=0;
    int player2max=0;
    char userinput;

    srand(time(NULL));       // random number generator

    printf("Player 1 Turn:\n");
    printf("write enter to roll a dice");
    
    do {
        scanf("%c", &userinput);    
        dice = (rand () % 6) + 1;    //generate number b/w 1-6
        printf("Player 1 rolls: %d\n", dice);
    
        player1rolls++;   // roll count increasing
        if(dice > player1max)
        {
            player1max = dice;    // recording greatest roll
        }

        if(dice != 1)
        {
            player1score += dice;
        }
    } while (dice != 1); // loop will end when dice value comes 1
    
    printf("Player 1 total score: %d\n", player1score);
    printf("Player 1 total rolls: %d\n", player1rolls);
    printf("player 1 greatest roll: %d\n", player1max);

    printf("\nPlayer 2 turn:\n");
    printf("write enter to roll a dice");

    do {
        scanf("%c", &userinput); 
        dice = (rand () % 6) + 1;    //generate number b/w 1-6
        printf("Player 2 rolls: %d\n", dice);

        player2rolls++;   // roll count increasing
        if(dice > player2max)
        {
            player2max = dice;    // recording greatest roll
        }

        if(dice != 1)
        {
            player2score += dice;
        }
    } while (dice != 1);          // loop will end when dice value comes 1
    
    printf("Player 2 total score: %d\n", player2score);
    printf("Player 2 total rolls: %d\n", player2rolls);
    printf("player 2 greatest roll: %d\n", player2max);

    // WINNER DECLARATION
    if (player1score > player2score)
    {
        printf("Winner: Player 1\n");
    }
    else
    {
        printf("Winner: Player 2\n");
    }

    getchar();
    return 0;
} 