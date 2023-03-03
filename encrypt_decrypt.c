// Data encryption/decryption. Caesar chipher implementation
// shift value by 4 i.e a = d
#include <stdio.h>
#include <string.h>
#include <windows.h>

void welcome();
void encrypt(char message[]);
void decrypt(char message[]);

int i, c;
void main()
{
    system("cls");
    welcome();
    char message[100];
    printf("Enter a message: ");
    gets(message);

    encrypt(message);
    decrypt(message);
}

void welcome()
{
    char text1[] = " \n\n\e[1m\e[4m******* Welcome to this program *******\n\n";
    char text2[] = "\e[1m\e[4mThis program is focused on encrypting the user given message...\n";
    char text3[] = "\e[1m\e[4m...and again decrypting it\n\n";
    char text4[] = "\e[1m\e[4mLets have a demo......\n\n\e[0m";
    // In above line \e[1m and \e[4m are used to make text bold and draw underline and again
    //\e[0m at the end of text4 is used to make text normal
    for (i = 0; text1[i] != '\0'; i++)
    {
        printf("%c", text1[i]);
        Sleep(25); // it is used to delay the execution of each letter by 25 miliseconds to simulate the animation
    }
    for (i = 0; text2[i] != '\0'; i++)
    {
        printf("%c", text2[i]);
        Sleep(25);
    }
    for (i = 0; text3[i] != '\0'; i++)
    {
        printf("%c", text3[i]);
        Sleep(25);
    }
    for (i = 0; text4[i] != '\0'; i++)
    {
        printf("%c", text4[i]);
        Sleep(25);
    }
}
void encrypt(char text[]) // Encryption
{
    for (i = 0; text[i] != '\0'; ++i)
    {
        char c = text[i];
        if (c >= 'a' && c <= 'z')
        {
            c = 'a' + (c - 'a' + 4) % 26;
            /*here %26 is used to handle the edge case. Suppose we have letter z and shift value is 4 ,
            without %26 we would get invalid letter so %26 ensures that the value always falls within 0-25.*/
        }
        else if (c >= 'A' && c <= 'Z')
        {
            c = 'A' + (c - 'A' + 4) % 26;
        }
        text[i] = c;
    }

    char message[] = "\nDisplaying Encrypted message.........\n";
    for (i = 0; message[i] != '\0'; i++)
    {
        printf("%c", message[i]);
        Sleep(25);
    }
    printf("%s\n", text);
}

void decrypt(char text[]) // Decryption
{

    for (i = 0; text[i] != '\0'; ++i)
    {
        char c = text[i];
        if (c >= 'a' && c <= 'z')
        {
            c = 'a' + (c - 'a' - 4 + 26) % 26;
            /*here I did +26, sometimes the shift value(4) might be larger than the position of the starting
            letter in the alphabet .Then simply subtracting the shift value from the shifted letter will not
            give the correct result.For example, suppose we have the letter 'c' and the shift value is 3. During encryption,
            'c' + 3 = 'f'. But during decryption, 'f' - 3 = 'c' only works if we assume that 'a' has a position of 0 in the
            alphabet. However, if we assume that 'a' has a position of 1 (as we do in the %26 calculation during encryption),
            then we need to add 26 to the result to ensure that we get a positive value within the range of 0-25. */
        }
        else if (c >= 'A' && c <= 'Z')
        {
            c = 'A' + (c - 'A' - 4 + 26) % 26;
        }
        text[i] = c;
    }
    char message[] = "\nDisplaying Decrypted message.........\n";
    for (i = 0; message[i] != '\0'; i++)
    {
        printf("%c", message[i]);
        Sleep(25);
    }
    printf("%s\n", text);
}

/*Breaking down the expression "c = 'a' + (c - 'a' + 4) % 26:- 'a' is the ASCII value of the lowercase letter a. This value is used
as a reference point to shift the input character c.  (c - 'a' + 4) calculates the index of the shifted character in the alphabet.
To do this, it first subtracts the ASCII value of a from the ASCII value of the input character c. This gives the index of the
input character in the alphabet (e.g., if c is 'c', then (c - 'a') will be 2, because 'c' is the third letter in the alphabet,
and a is the first letter). The expression then adds the shift value shift to this index to get the index of the shifted character in the alphabet."*/