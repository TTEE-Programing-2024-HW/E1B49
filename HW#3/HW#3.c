#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>

#define ROWS 9
#define COLS 9

// Function prototypes
int checkPassword();
void showMainMenu();
void initializeSeats(int seats[ROWS][COLS]);
void showSeats(int seats[ROWS][COLS]);
void pressAnyKeyToContinue();
int exitConfirmation();
int suggestSeats(int seats[ROWS][COLS], int numSeats);
void chooseSeats(int seats[ROWS][COLS]);
void acceptSuggestedSeats(int seats[ROWS][COLS]);
void revertSuggestedSeats(int seats[ROWS][COLS]);
int findFourSeats(int seats[ROWS][COLS]);

int main()
{
    int keepRunning = 1;

    if (checkPassword())
    {
        do
        {
            showMainMenu();
        } while (keepRunning);
    }
    else
    {
        printf("\nPassword input error three times, the program will end soon.");
    }
    

    return 0;
}

int checkPassword()
{
    int password, attempts = 0, correctPassword = 2024;

    printf("****************************************\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*         Welcome to My System         *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("*                                      *\n");
    printf("****************************************\n");

    while (attempts < 3)
    {
        printf("Please enter password¡G");
        fflush(stdin);
        scanf("%d", &password);
        if (password == correctPassword)
        {
            return 1;
        }
        else
        {
            printf("\nPassword incorrect¡IYou have %d attempts left.\n", 2 - attempts);
            attempts++;
        }
    }
    return 0;
}

void showMainMenu()
{
    system("cls");
    printf(" -------------[Booking System]-------------\n");
    printf("|            a. Available seats            |\n");
    printf("|            b. Arrange for you            |\n");
    printf("|           c. Choose by yourself          |\n");
    printf("|                  d. Exit                 |\n");
    printf(" ------------------------------------------\n");
    printf("Please choose one of the options¡G");
}