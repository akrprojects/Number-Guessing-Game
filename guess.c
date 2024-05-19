#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int random(int lower, int upper, int count);

int main(void)
{
    bool restart = false;

    while (! restart)
    {
        printf("Welcome to the Number Guessing Game!\n");

        int start = get_int("Enter starting number: ");
        int end = get_int("Enter ending number: ");

        while (end < start)
        {
            printf("Ending number should not be less than starting number");
            end = get_int("Enter ending number: ");
        }

        srand(time(0));

        int random_number = random(start,end,1);
        // printf("Test number is %i\n", random_number);

        bool has_won = false;
        int attempts = 1;

        while (! has_won)
        {
            int guess;
            guess = get_int ("Enter your guess: ");

            if (guess < start || guess > end)
            {
                printf("Invalid. Guess the number between %i and %i (inclusive).\n", start, end);
            }

            else if (guess > random_number)
            {
                printf("Too high! Try again.\n");
            }

            else if (guess < random_number)
            {
                printf("Too low! Try again.\n");
            }

            else
            {
                printf("Congratulations! You guessed the correct number in %i attempts.\n", attempts);
                has_won = true;

                char play_again = tolower(get_char("Do you want to play again?(y/n): "));
                if (play_again == 'y')
                {
                    printf("Starting new game.\n");
                }
                else
                {
                    printf("Exiting the game.\n");
                    restart = true;
                }
            }
            attempts ++;
        }
    }

    return 0;
}

int random(int lower, int upper, int count)
{
    int num;
    for (int i = 0; i < count; i++)
    {
        num = (rand()% (upper - lower + 1)) + lower;
    }

    return num;
}
