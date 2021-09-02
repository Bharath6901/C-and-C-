//rock, paper & scissors -
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}
int greater(char c1, char c2)
{
    if (c1 == c2)
    {
        return -1;
    }
    else if (c1 == 'r' && c2 == 's')
    {
        return 1;
    }
    else if (c2 == 'r' && c1 == 's')
    {
        return 0;
    }
    else if (c1 == 'p' && c2 == 'r')
    {
        return 1;
    }
    else if (c2 == 'p' && c1 == 'r')
    {
        return 0;
    }
    else if (c1 == 's' && c2 == 'p')
    {
        return 1;
    }
    else if (c2 == 's' && c1 == 'p')
    {
        return 0;
    }
}
int main()
{
    int playerScore = 0, compScore = 0, temp;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'};
    printf("\tWelcome to the Rock Paper Scissors\n");

    for (int i = 0; i < 3; i++)
    {
        // Take player input
        printf("Press 1 for Rock, Press 2 for Paper, Press 3 for Scissors\n\n");
        printf("\tPlayer's turn: ");
        scanf("%d", &temp);
        getchar();
        playerChar = dict[temp - 1];

        printf("| You choose: %c   |\n", playerChar);

        //computer generate
        printf("Press 1 for Rock, Press 2 for Paper, Press 3 for Scissors\n\n");
        printf("\tComputer's turn\n");
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];

        printf("| Computer choose: %c |\n", compChar);

        // compater character and increment the score
        if (greater(compChar, playerChar) == 1)
        {
            compScore++;
            printf("\t\tComputer Got It!\n\n");
        }
        else if (greater(compChar, playerChar) == -1)
        {
            compScore++;
            playerScore++;
            printf("\t\tIt's a draw. Both got 1 point!\n\n");
        }
        else
        {
            playerScore++;
            printf("\t\tYou Got It!\n\n");
        }

        printf("| You: %d      |\n", playerScore);
        printf("| Computer: %d |\n", compScore);

    }

    printf("|   Final Score   |\n");

    printf("|  You | Computer |\n");

    printf("|   %d  |    %d     |\n", playerScore, compScore);

    // compare score
    if (playerScore > compScore)
    {
        printf("\t| You Win the match |\n");

    }
    else if (playerScore < compScore)
    {

        printf("\t| Computer Won the match |\n");

    }
    else
    {

        printf("\t| It's a draw |\n");

    }
    return 0;
}
