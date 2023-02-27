// stop watch
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void welcome();
void timer();

COORD coord;              // COORD is a structure that store the coordinate
void gotoxy(int x, int y) // This function display the output in x,y coordinate in terminal
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // sets cursor position to the specified coordinate in terminal
}

int main()
{
    welcome();
    timer();
}

void welcome()
{
    int i;
    char text1[] = "\e[1m\e[4m*********** Welcome To My Program ************"; // \e[1m is used to make text bold \e[4m is used to draw underline
    char text2[] = "This is a simple C Program to Simulate a timer";
    char text3[] = "Starting Timer.............";

    gotoxy(50, 5); // Display text in 50,5 coodrinate in terminal
    for (i = 0; text1[i] != 0; i++)
    {
        printf("%c", text1[i]);
        Sleep(35);
    }
    gotoxy(50, 7);
    for (i = 0; text2[i] != 0; i++)
    {
        printf("%c", text2[i]);
        Sleep(35);
    }
    gotoxy(50, 9);
    for (i = 0; text3[i] != 0; i++)
    {
        printf("%c", text3[i]);
        Sleep(35);
    }
}

void timer()
{
    int hours = 0, minutes = 0, seconds = 0;

    // Loop until timer is stopped
    while (1)
    {
        gotoxy(50, 11);
        printf("\e[1m%02d:%02d:%02d\n", hours, minutes, seconds);
        Sleep(1000);

        // Increment seconds and minutes if necessary
        seconds++;
        if (seconds == 60)
        {
            seconds = 0;
            minutes++;
            if (minutes == 60)
            {
                minutes = 0;
                hours++;
            }
        }
    }
}
