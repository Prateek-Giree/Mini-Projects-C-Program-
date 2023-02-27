// WAP to generate random number a let the user guess the number
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()

{
    system("cls");
    int num, guess, nguess = 1;
    srand(time(0));
    num = rand() % 100 + 1;
    // printf("the number is %d \n", num);
    printf("please guess the number between 1 to 100 \n");
    do
    {

        scanf("%d", &guess);
        if (guess > num)
        {
            printf("You guessed the higher number.please guess the lower number\n");
        }
        else if (guess < num)
        {
            printf("You guessed the lower number . please guess the higher number\n");
        }
        else
        {
            printf("you've guessed the number in %d attempts\n", nguess);
        }
        nguess++;

    } while (num != guess);

    return 0;
}