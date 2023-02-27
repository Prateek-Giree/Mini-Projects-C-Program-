// moving and blinking text
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    char text[] = "Hello world"; // the text to be displayed
    int len = strlen(text); // get the length of the text
    int pos = 0;            // initial position of the text

    // loop forever
    while (1)
    {
        printf("\033[2J");                     // clear the screen
        printf("\033[%d;%dH%s", 0, pos, text); // print the text at the current position
        fflush(stdout);                        // flush the output stream to update the screen
        pos++;                                 // move the position of the text by 1

        if (pos > 80 - len) // if the text reaches the end of the screen
        {
            pos = 0; // reset the position to 0
        }
        // sleep (1); //Delay execution job by 1 second
        usleep(100000); // sleep for 100 milliseconds. Delays execution of job
    }

    return 0;
}
