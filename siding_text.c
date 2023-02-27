#include <stdio.h>

void main()
{
    int x;
    double y;
    char text1[] = "\n************** Hi welcome to my program  ***************\n\n ";
    char text2[] = "\tThis program simulate sliding text animation";

    printf("\n\n");
    for (x = 0; text1[x] != '\0'; x++)
    {
        printf("%c", text1[x]);
        for (y = 0; y <= 9000000; y++)
        {
        }
    }

    for (x = 0; text2[x] != '\0'; x++)
    {
        printf("%c", text2[x]);
        for (y = 0; y <= 9000000; y++)
        {
        }
    }
}

/*A nested for loop is used to introduce a delay between each character.
This delay is controlled by the y variable, which is incremented in each
iteration of the inner loop. The loop runs 8888888 times in each iteration
of the outer loop, causing a delay before the next character is printed.*/

 