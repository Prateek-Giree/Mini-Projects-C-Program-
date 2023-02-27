/* A program to perform following operation on two matrices
1. Matrix addition
2. Matrix subtraction
3. Matrix multiplication
4. Exit */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int i, j;                             // i,j for loop
int matrix1[10][10], matrix2[10][10]; // Global declaration of two matrices
int row1, col1, row2, col2;           // row1,col1 and row2,col2 for order of 1st and 2nd matrix

void addition();
void subtraction();
void multiplication();
void transpose();
void welcome();
void menu();
void calculation();

COORD coord;              // COORD is the structure which store the coodrinate of console cursor
void gotoxy(int x, int y) // This function  is used to display the output in the desired coodinate.
                          // I wrote this to display welcome and menu in the middle of the terminal
{
    coord.X = x; // column
    coord.Y = y; // row

    // SetConsoleCursorPosition function is used to set the console cursor position to specified coordinate
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void main()
{
    system("cls");
    welcome();
    menu();

    int n; // For taking choice

    printf("Enter your choice: ");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        system("cls");
        addition(); // calling function addition()
        break;

    case 2:
        system("cls");
        subtraction(); // calling function subtraction()
        break;

    case 3:
        system("cls");
        multiplication(); // calling function multiplication()
        break;

    case 4:
        transpose(); // calling function transpose()
        break;

    case 5:
        exit(0);
        break;

    default:
        printf("Invalid choice \n");
    }
}

void welcome()
{
    {
        char text1[] = "************** Welcome to the matrix calculator ************";
        char text2[] = "******** Perform calculation according to your need ********";

        gotoxy(50, 4); // Display above text1 in coordinate 50,4
        for (i = 0; text1[i] != '\0'; i++)
        {
            printf("%c", text1[i]);
            Sleep(35); // Here I used Sleep function to delay the printing of each character to simulate the animation.Take argument in milisecond
        }

        gotoxy(50, 6); // Display text2 in coordinate 50,6
        for (i = 0; text2[i] != '\0'; i++)
        {
            printf("%c", text2[i]);
            Sleep(35);
        }
    }
}

void menu()
{
    char text1[] = "1. Matrix addition\n";
    char text2[] = "2. Matrix subtraction\n";
    char text3[] = "3. Matrix multiplication\n";
    char text4[] = "4. Matrix transpose\n";
    char text5[] = "5. Exit\n\n";

    gotoxy(50, 10);
    // Displaying text1 in animation
    for (i = 0; text1[i] != '\0'; i++)
    {
        printf("%c", text1[i]);
        Sleep(30);
    }

    gotoxy(50, 11);
    // Displaying text2 in animation
    for (i = 0; text2[i] != '\0'; i++)
    {
        printf("%c", text2[i]);
        Sleep(30);
    }

    gotoxy(50, 12);
    // Displaying text3 in animation
    for (i = 0; text3[i] != '\0'; i++)
    {
        printf("%c", text3[i]);
        Sleep(30);
    }

    gotoxy(50, 13);
    /// displaying text4 in animation
    for (i = 0; text4[i] != '\0'; i++)
    {
        printf("%c", text4[i]);
        Sleep(30);
    }

    gotoxy(50, 14);
    // displaying text5 in animation
    for (i = 0; text5[i] != '\0'; i++)
    {
        printf("%c", text5[i]);
        Sleep(30);
    }
}

void calculation() // I made this function to display text in animation
{
    char text1[] = "\nPerforming calculation.................\n\n";
    char text2[] = "The result is\n\n";
    for (i = 0; text1[i] != '\0'; i++) // for text1
    {
        printf("%c", text1[i]);
        Sleep(30);
    }
    for (i = 0; text2[i] != '\0'; i++) // for text2
    {
        printf("%c", text2[i]);
        Sleep(30);
    }
}

void addition() // This function perform addition
{
    char text[] = "Calculation of matrix addition...........\n\n";
    for (i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        Sleep(30);
    }

    printf("Enter order of 1st matrix: ");
    scanf("%d%d", &row1, &col1);
    printf("Enter order of 2nd matrix: ");
    scanf("%d%d", &row2, &col2);

    if (row1 == row2 && col1 == col2) // order of the matrix must be same
    {

        printf("For 1st matrix\n");
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < col1; j++)
            {
                printf("Enter element of matrix1[%d][%d]: ", i, j);
                scanf("%d", &matrix1[i][j]);
            }
        }

        printf("\nFor 2nd matrix\n");
        for (i = 0; i < row2; i++)
        {
            for (j = 0; j < col2; j++)
            {
                printf("Enter element of matrix2[%d][%d]: ", i, j);
                scanf("%d", &matrix2[i][j]);
            }
        }

        calculation();

        for (i = 0; i < row1; i++) /*it doesnt matter wheather you write row1/col1 or
       row2/column2 in iteration because both matrix are of same size*/
        {
            for (j = 0; j < col2; j++)
            {
                printf("%d\t", matrix1[i][j] + matrix2[i][j]);
            }
            printf("\n");
        }
    }

    else
    {
        printf("Addition cannot be performed. The order of two matrices must be same");
    }
}

void subtraction() // This function perform subtraction
{
    char text[] = "Calculation of matrix subtraction............\n\n";
    for (i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        Sleep(30);
    }

    printf("Enter order of 1st matrix: ");
    scanf("%d%d", &row1, &col1);
    printf("Enter order of 2nd matrix: ");
    scanf("%d%d", &row2, &col2);

    if (row1 == row2 && col1 == col2)
    {

        printf("For 1st matrix\n");
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < col1; j++)
            {
                printf("Enter element of matrix1[%d][%d]: ", i, j);
                scanf("%d", &matrix1[i][j]);
            }
        }

        printf("\nFor 2nd matrix\n");
        for (i = 0; i < row2; i++)
        {
            for (j = 0; j < col2; j++)
            {
                printf("Enter element of matrix2[%d][%d]: ", i, j);
                scanf("%d", &matrix2[i][j]);
            }
        }

        calculation();

        for (i = 0; i < row1; i++) /*it doesnt matter wheather you write row1/col1 or
       row2/column2 in iteration because both matrix are of same size*/
        {
            for (j = 0; j < col2; j++)
            {
                printf("%d\t", matrix1[i][j] - matrix2[i][j]);
            }
            printf("\n");
        }
    }

    else
    {
        printf("Subtraction cannot be performed. The order of two matrices must be same");
    }
}

void multiplication() // This function perform multiplication
{
    char text[] = "Calculation of matrix multiplication...............\n\n";
    for (i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        Sleep(30);
    }

    printf("Enter order of 1st matrix: ");
    scanf("%d%d", &row1, &col1);
    printf("Enter order of 2nd matrix: ");
    scanf("%d%d", &row2, &col2);

    if (col1 == row2) // column of 1st matrix must be equal to row of 2nd matrix to perform multiplication
    {
        printf("\nFor 1st matrix\n");
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < col1; j++)
            {
                printf("Enter element of matrix1[%d][%d]: ",i,j);
                scanf("%d", &matrix1[i][j]);
            }
        }

        printf("\nFor 2nd matrix\n");
        for (i = 0; i < row2; i++)
        {
            for (j = 0; j < col2; j++)
            {
                printf("Enter element of matrix2[%d][%d]: ", i, j);
                scanf("%d", &matrix2[i][j]);
            }
        }

        calculation();

        int prod[10][10], k;
        for (i = 0; i < row1; i++) // resulting matrix has row equal to 1st matrix
        {
            for (j = 0; j < col2; j++) // resulting matrix has column equal to 2nd matrix
            {
                prod[i][j] = 0;
                for (k = 0; k < row2; k++) // column1=row2 so you can write column1 insetad of row2
                {
                    prod[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        printf("\n");
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < col2; j++)
            {
                printf("%d\t", prod[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Multiplication cannot be performed. column of 1st matrix must be equal to row of 2nd matrix to perform multiplication");
    }
}

void transpose() // This function perform transpose
{
    // displaying text in animation
    char text[] = "Calculation of Transpose...........\n\n";
    for (i = 0; text[i] != '\0'; i++)
    {
        printf("%c", text[i]);
        Sleep(30);
    }

    printf("Enter row and column of the matrix: ");
    scanf("%d%d", &row1, &col1);

    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            printf("Enter element of matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    calculation();
    for (j = 0; j < col1; j++)
    {
        for (i = 0; i < row1; i++)
        {
            printf("%d\t", matrix1[i][j]);
        }
        printf("\n");
    }
}
