#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

#define ROWS 9
#define COLS 9
#define PASSWORD 2024

// Function to print the welcome screen
void print_welcome_screen()
{
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
}

// Function to prompt for password
int password_prompt()
{
    int input, attempts = 0;

    // User gets three attempts to enter the correct password
    while (attempts < 3)
    {
        printf("Please enter your 4-digit password: ");
        scanf("%d", &input);
        if (input == PASSWORD)
        {
            return 1; // Password correct
        }
        else
        {
            printf("Incorrect password. Please try again.\n");
            attempts++;
        }
    }

    printf("Incorrect password entered three times. Exiting...\n");
    return 0; // Password failed
}

// Function to print the main menu
void print_menu()
{
    printf(" -------------[Booking System]-------------\n");
    printf("|            a. Available seats            |\n");
    printf("|                                          |\n");
    printf("|            b. Arrange for you            |\n");
    printf("|                                          |\n");
    printf("|           c. Choose by yourself          |\n");
    printf("|                                          |\n");
    printf("|                  d. Exit                 |\n");
    printf(" ------------------------------------------\n");
}

// Function to print the seating chart
void print_seats(char seats[ROWS][COLS])
{
    printf("   123456789\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("%d  ", i + 1);
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    return 0;
}