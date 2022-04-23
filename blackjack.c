#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

int payout(int num)
{
    if (num <= 14)
    {
        return 0;
    }
    else if (num > 14 && num < 21)
    {
        // using formula output = output_start + ((output_end - output_start) / (input_end - input_start)) * (input - input_start) to map one range to another
        return (110 + ((190 - 110) / (20 - 15)) * (num - 15));
    }
    else if (num == 21)
    {
        return 100;
    }
    else if (num > 21)
    {
        return 0;
    }
}

int game(int total_score)
{
game:
    total_score -= 100;
    int num;
    // using formula rand() % (max_number + 1 - minimum_number) + minimum_number to get a random number between the minimum and maximum
    srand(time(NULL));
    num = (rand() % 10) + 1;
turn:

    system("cls");
    printf("                       Score: %d\n", total_score);
    printf("                       Payout: %d\n", payout(num));
    printf("\n\n        Number:%d\n\n\n", num);

    if (num == 21)
    {
        printf("Blackjack!\n");
        delay(1);
        total_score += payout(num);
        printf("congratulations you won %d\n", payout(num));
        printf("total score: %d\n", total_score);
        delay(1);
        char again;
        printf("play again? (y/n) :");
        scanf(" %c", &again);
        if (again == 'y' || again == 'Y')
        {
            if (total_score >= 100)
            {
                goto game;
            }
            else
            {
                printf("you don't have enough points to play\n");
            }
        }
        else
        {
            return 0;
        }
    }
    else if (num > 21)
    {
        printf("Game over!\n");
        delay(1);
        printf("total score: %d\n", total_score);
        char again;
        printf("play again? (y/n) :");
        scanf(" %c", &again);
        if (again == 'y' || again == 'Y')
        {
            if (total_score >= 100)
            {
                goto game;
            }
            else
            {
                printf("you don't have enough points to play\n");
            }
        }
        else
        {
            return 0;
        }
    }

    printf("press: \n\nA for 1-8\nB for 4-7\nC for payout\n");
    char choice;
    scanf(" %c", &choice);
    switch (choice)
    {
    case 'A':
    case 'a':
        // using formula rand() % (max_number + 1 - minimum_number) + minimum_number to get a random number between the minimum and maximum
        srand(time(NULL));
        num += ((rand() % 8) + 1);
        break;
    case 'B':
    case 'b':
        // using formula rand() % (max_number + 1 - minimum_number) + minimum_number to get a random number between the minimum and maximum
        srand(time(NULL));
        num += ((rand() % 4) + 4);
        break;
    case 'C':
    case 'c':
        total_score += payout(num);
        printf("congratulations you won %d\n", payout(num));
        printf("total score: %d\n", total_score);
        delay(1);
        char again;
        printf("play again? (y/n) :");
        scanf(" %c", &again);
        if (again == 'y' || again == 'Y')
        {
            if (total_score >= 100)
            {
                goto game;
            }
            else
            {
                printf("you don't have enough points to play\n");
                delay(1);
                return 0;
            }
        }
        else
        {
            return 0;
        }
    default:
        printf("Invalid input\n");
        delay(1);
        break;
    }

    goto turn;
}

int main()
{
    int total_score = 300;
    char *instruction = "Instructions: \n\nThis is a game where your goal is to get the \nnumber as close to 21 as possible without going over. \nYou will be given two sets of numbers to choose from and an option to payout \nif you select any set of numbers a random number from the set will be added to the existing number \nif you select payout your score will be calculated and added to your total score hence ending the game\nyour score is calculated based on how close you are to 21 if you go above 21 you will lose and your score will be subtracted from the total score";
    char *scores_inst = "Scores: \n\nTo play one round of blackjack 100 points will be deducted from your total score \nif you get exactly 21, 200 points in total will be rewarded \nif you payout before 14 no points will be added to your score hence levaing you in loss of 100 points \nif you get between 14 and 21 then the score will be calculated accordingly";
start:
    printf("Welcome to Blackjack! (single player)\npress 1 for instructions\npress 2 for score payout\npress 3 to start the game\npress 4 to exit\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf(instruction);
        printf("\n\n\n\n");
        goto start;
    }
    else if (choice == 2)
    {
        printf(scores_inst);
        printf("\n\n\n\n");
        goto start;
    }
    else if (choice == 3)
    {
        game(total_score);
    }
    else if (choice == 4)
    {
        return 0;
    }
    else
    {
        printf("Invalid input\n");
        printf("\n\n\n\n");
    }
    return 0;
}
