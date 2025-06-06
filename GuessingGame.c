#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void comment(int guesses);

int main () {
    int guesses, guess, num;
    char input;

    system ("cls");

    printf("\t\tWELCOME TO GUESSING GAME!\n");

    do {
        guesses = 1;

        // Generating random num
        srand(time(0));
        num = (rand() % 9) + 1;

        while (guess != num) {
            input = ' ';

            printf("\nPlease guess the number from 0 - 9: ");
            scanf("%d", &guess);

            if (guess == num) {
                printf("\nYou are right!\n\n");

                printf("----------------------\n");
                printf("Number: %d\n", num);
                printf("Number of Attempts: %d\n\n", guesses);
                comment(guesses);
                printf("----------------------\n");

                try: // label 
                printf("Do you want to continue?(Y or N): ");
                scanf(" %c", &input);

                if (input == 'Y' || input == 'y') {
                    break;
                }
                else if (input == 'N' || input == 'n') {
                    goto end;
                }
                else {
                    printf("Please only input 'Y' or 'N'!\n");
                    goto try;
                }
            }
            else {
                if (guess > num) {
                    printf("TOO HIGH! Try again!\n");
                    guesses++;
                }
                else {
                    printf("TOO LOW! Try again!\n");
                    guesses++;
                }
            }
        }
    }
    while (input != 'N' || input != 'n');

    end:

    printf("\nThank you for using this program!\n");
    return 0;
}

void comment (int guesses) {
    if (guesses == 1) {
        printf("WOW! You got that on first try, you lucky bastard!\n");
    }
    else if (guesses > 1 && guesses <= 5) {
        printf("Not bad, you've got it within %d tries only.\n", guesses);
    }
    else {
        printf("Dang bro, you down bad at guessing. That's a massive skill issue right there, you might wanna go outside and touch some grass before playing again XD!\n");
    }
}