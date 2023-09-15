
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

unsigned int roll_die( void );
unsigned int throw_dice( void );
bool play_again(int);

unsigned int total;
unsigned int point;

enum Status {CONTINUE, WON, LOST};


int main ( void ) 
{
        bool in_play = true;
        int money = 5;
        srand(time(NULL));

        enum Status gameStatus;
        gameStatus = WON;

        while (gameStatus == WON || gameStatus == CONTINUE)
        {

                int roll = throw_dice();
                printf("You rolled: %d\n", roll);

                if (gameStatus == CONTINUE)
                {
                        if (roll == 7) {
                                gameStatus == LOST;
                                printf("You Lose!\n");
                                break;
                        }
                        if (roll == point){
                                gameStatus == WON;
                                money = money * 2;
                                gameStatus = play_again(money);
                        }
                }

                else if (gameStatus == WON)
                {
                        switch (roll) {
                                case 7:
                                case 11:
                                        gameStatus = WON;
                                        money = money * 2;
                                        gameStatus = play_again(money);
                                        roll = throw_dice();
                                        break;

                                case 2:
                                case 3:
                                case 12:
                                        gameStatus = LOST;
                                        in_play = false;
                                        puts("Ya lost!");
                                        break;

                                case 4:
                                case 5:
                                case 6:
                                case 8:
                                case 9:
                                case 10:
                                        gameStatus = CONTINUE;
                                        point = roll;
                                        printf("Point is %d\n", point);
                        }
                }
        }
}

unsigned int roll_die()
{
        int face = 1 + rand() % 6;
        return face;
}

unsigned int throw_dice()
{
        unsigned int d1 = roll_die();
        unsigned int d2 = roll_die();
        unsigned int total = d1 + d2;

        return total;
}


bool play_again(cash)
{
        char cash_out[3]; 

        puts("You won!");
        printf("You currently have: %d\n", cash);
        puts("Do you want to cash out?");
        scanf("%s", &cash_out);
        if (cash_out == "yes")
                return LOST;
        if (cash_out == "no")
                return WON;
}

