//Tasguzen

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_a_dice();
int play_computer(int);
int play_user(int);
void scoresheet(int, int, int);
int calculate_score(int, int, int, int, int);

int main()
{
    int rounds, player_score = 0, computer_score = 0, isPlayerStart = 0;
    srand(time(0));
    printf("Welcome to Generala game.\nLet's get started!\n\n");

    printf("How many rounds would you like to play?");
    scanf("%d", &rounds);
    while (rounds <= 0)
    {
        printf("Round number should be positive integers.\n");
        printf("How many rounds would you like to play?");
        scanf("%d", &rounds);
    }

    int start1 = roll_a_dice(), start2 = roll_a_dice();
    int startbot1 = roll_a_dice(), startbot2 = roll_a_dice();
    printf("I have rolled the dice and got %d and %d!\n", start1, start2);
    printf("I have rolled the dice for you and you got %d and %d!\n", startbot1, startbot2);
    while((start1 + start2) == (startbot1 + startbot2))
    {
        printf("\nIt's a tie! Rolling again...\n");
        start1 = roll_a_dice();
        start2 = roll_a_dice();
        startbot1 = roll_a_dice();
        startbot2 = roll_a_dice();

        printf("I have rolled the dice and got %d and %d!\n", start1, start2);
        printf("I have rolled the dice for you and you got %d and %d!\n", startbot1, startbot2);
    }
    if ((start1 + start2) > (startbot1 + startbot2))
        isPlayerStart = 1;
    else
        isPlayerStart = 0;

    for(int currentround = 1; currentround <= rounds; currentround++)
    {
        if(isPlayerStart)
        {
            player_score = player_score + play_user(currentround);
            computer_score = computer_score + play_computer(currentround);
        }
        else
        {
            computer_score = computer_score + play_computer(currentround);
            player_score = player_score + play_user(currentround);
        }

        scoresheet(currentround, player_score, computer_score);
    }

    if(computer_score > player_score)
    {
        printf("\n\nI AM THE WINNER!\n");
    }
    else if(player_score > computer_score)
    {
        printf("\n\nYOU WIN!\n");
    }
    else
    {
        printf("\n\nIT IS TIE!\n");
    }

    return 0;
}

int roll_a_dice()
{
    return (rand() % 6) + 1;
}

int play_computer(int round)
{
    int d1 = roll_a_dice(), d2 = roll_a_dice(), d3 = roll_a_dice(), d4 = roll_a_dice(), d5 = roll_a_dice();
    int score = calculate_score(d1, d2, d3, d4, d5), rollagain = 2;

    printf("\n\nRound %d -- My Turn:\n", round);
    printf("I rolled them and I got\n[Dice 1]:%d [Dice 2]:%d [Dice 3]:%d [Dice 4]:%d [Dice 5]:%d\n", d1, d2, d3, d4, d5);
    printf("My score: %d\n", score);
    if (score==50)
        printf("GENERALA!\n");
    else if (score==40)
        printf("Four of a Kind!\n");
    else if (score==30)
        printf("Full House!\n");
    else if (score==20)
        printf("Straight!\n");

    if((d1==d2 && d2==d3 && d3==d4) || (d2==d3 && d3==d4 && d4==d5) || (d3==d4 && d4==d5 && d5==d1) || (d4==d5 && d5==d1 && d1==d2) || (d5==d1 && d1==d2 && d2==d3)) //If 4 dices are same, computer will roll again for generala.
    {
        while (rollagain  > 0)
        {
            if(d1==d2 && d2==d3 && d3==d4)
                d5 = roll_a_dice();
            else if(d2==d3 && d3==d4 && d4==d5)
                d1 = roll_a_dice();
            else if(d3==d4 && d4==d5 && d5==d1)
                d2 = roll_a_dice();
            else if(d4==d5 && d5==d1 && d1==d2)
                d3 = roll_a_dice();
            else if(d5==d1 && d1==d2 && d2==d3)
                d4 = roll_a_dice();

            printf("\nI rolled them again and I got\n[Dice 1]:%d [Dice 2]:%d [Dice 3]:%d [Dice 4]:%d [Dice 5]:%d\n", d1, d2, d3, d4, d5);
            score = calculate_score(d1, d2, d3, d4, d5);
            printf("My score: %d\n", score);
            if (score==50)
                printf("GENERALA!\n");
            else if (score==40)
                printf("Four of a Kind!\n");
            else if (score==30)
                printf("Full House!\n");
            else if (score==20)
                printf("Straight!\n");

            if(d1==d2 && d2==d3 && d3==d4 && d4==d5)
                rollagain=0;
            else
                rollagain--;
        }
    }

    return score;
}

int play_user(int round)
{
    int d1 = roll_a_dice(), d2 = roll_a_dice(), d3 = roll_a_dice(), d4 = roll_a_dice(), d5 = roll_a_dice();
    char YorN;
    int score = calculate_score(d1, d2, d3, d4, d5), rollagain = 2;

    printf("\n\nRound %d -- Your Turn:\n", round);
    printf("You got\n[Dice 1]:%d [Dice 2]:%d [Dice 3]:%d [Dice 4]:%d [Dice 5]:%d\n", d1, d2, d3, d4, d5);
    printf("Your score: %d\n", score);
    if (score==50)
        printf("GENERALA!\n");
    else if (score==40)
        printf("Four of a Kind!\n");
    else if (score==30)
        printf("Full House!\n");
    else if (score==20)
        printf("Straight!\n");

    while(rollagain > 0)
    {
        printf("Shall I roll for you (Y/N)?");
        scanf(" %c", &YorN);

        while(YorN != 'Y' && YorN != 'y' && YorN != 'N' && YorN != 'n')
        {
            printf("Invalid input, Try Y[yes] or N[no]:");
            scanf(" %c", &YorN);
        }

        if(YorN == 'N' || YorN == 'n')
            break;

        int keep1, keep2;
        int input_valid = 0; //To enter or exit the loop
        while(input_valid == 0)
        {
            printf("Which ones do you want to keep? ");
            scanf("%d %d", &keep1, &keep2);

            if(keep1 >= 1 && keep1 <= 5 && keep2 >= 1 && keep2 <= 5 && keep1 != keep2) //Dice must be between 1 and 5 and unequal.
                input_valid = 1;
            else
                printf("Invalid input, enter two different numbers between 1-5:\n");
        }

        if(keep1 != 1 && keep2 != 1) d1 = roll_a_dice();
        if(keep1 != 2 && keep2 != 2) d2 = roll_a_dice();
        if(keep1 != 3 && keep2 != 3) d3 = roll_a_dice();
        if(keep1 != 4 && keep2 != 4) d4 = roll_a_dice();
        if(keep1 != 5 && keep2 != 5) d5 = roll_a_dice();

        printf("You got: [Dice 1]:%d [Dice 2]:%d [Dice 3]:%d [Dice 4]:%d [Dice 5]:%d\n", d1, d2, d3, d4, d5);
        score = calculate_score(d1, d2, d3, d4, d5);
        printf("Your score: %d\n", score);
        if (score==50)
            printf("GENERALA!\n");
        else if (score==40)
            printf("Four of a Kind!\n");
        else if (score==30)
            printf("Full House!\n");
        else if (score==20)
            printf("Straight!\n");
        rollagain--;
    }

    return score;
}

void scoresheet(int currentround, int player_score, int computer_score)
{
    printf("\nOur scoresheet after round %d:\n",currentround);
    printf("=============================\n");
    printf("My score\tYour score\n%d\t\t%d",computer_score, player_score);
}

int calculate_score(int d1, int d2, int d3, int d4, int d5)
{
    if(d1 == d2 && d2 == d3 && d3 == d4 && d4 == d5)
        return 50;//Generala

    else if((d1==d2 && d2==d3 && d3==d4) || (d2==d3 && d3==d4 && d4==d5) || (d3==d4 && d4==d5 && d5==d1) || (d4==d5 && d5==d1 && d1==d2) || (d5==d1 && d1==d2 && d2==d3))
        return 40;//Four of a kind

    else if((d1==d2 && d2==d3 && d4==d5) || (d2==d3 && d3==d4 && d5==d1 ) || (d3==d4 && d4==d5 && d1==d2) || (d4==d5 && d5==d1 && d2==d3) || (d5==d1 && d1==d2 && d3==d4))
        return 30;//Full house

    else if((d1==1 && d2==2 && d3==3 && d4==4 && d5==5) || (d1==2 && d2==3 && d3==4 && d4==5 && d5==6))
        return 20;//Straight

    else
    {
        int sixes=0, fives=0, fours=0, threes=0, twos=0, ones=0;

        if(d1 == 6)
            sixes++;
        else if(d1 == 5)
            fives++;
        else if(d1 == 4)
            fours++;
        else if(d1 == 3)
            threes++;
        else if(d1 == 2)
            twos++;
        else if(d1 == 1)
            ones++;

        if(d2 == 6)
            sixes++;
        else if(d2 == 5)
            fives++;
        else if(d2 == 4)
            fours++;
        else if(d2 == 3)
            threes++;
        else if(d2 == 2)
            twos++;
        else if(d2 == 1)
            ones++;

        if(d3 == 6)
            sixes++;
        else if(d3 == 5)
            fives++;
        else if(d3 == 4)
            fours++;
        else if(d3 == 3)
            threes++;
        else if(d3 == 2)
            twos++;
        else if(d3 == 1)
            ones++;

        if(d4 == 6)
            sixes++;
        else if(d4 == 5)
            fives++;
        else if(d4 == 4)
            fours++;
        else if(d4 == 3)
            threes++;
        else if(d4 == 2)
            twos++;
        else if(d4 == 1)
            ones++;

        if(d5 == 6)
            sixes++;
        else if(d5 == 5)
            fives++;
        else if(d5 == 4)
            fours++;
        else if(d5 == 3)
            threes++;
        else if(d5 == 2)
            twos++;
        else if(d5 == 1)
            ones++;

        int finalscore = 1;
        if(sixes >= 2)
            finalscore = sixes * 6;
        if(fives >= 2 && fives*5 > finalscore)
            finalscore = fives*5;
        if(fours >= 2 && fours*4 > finalscore)
            finalscore = fours*4;
        if(threes >= 2 && threes*3 > finalscore)
            finalscore = threes*3;
        if(twos >= 2 && twos*2 > finalscore)
            finalscore = twos*2;
        if(ones >= 2 && ones*1 > finalscore)
            finalscore = ones*1;

        return finalscore;
    }
}