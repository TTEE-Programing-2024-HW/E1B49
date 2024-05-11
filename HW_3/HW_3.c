#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <string.h> 

#define ROWS 9
#define COLS 9
#define PASSWORD 2024

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

int password_prompt()
{
    int input, attempts = 0;
    while (attempts < 3)
    {
        printf("Please enter your 4-digit password: ");
        if (scanf("%d", &input) == 1 && input == PASSWORD)
        {
            return 1;
        }
        else
        {
            printf("Incorrect password. Please try again.\n");
            fflush(stdin); // Clear input buffer
            attempts++;
        }
    }
    printf("Incorrect password entered three times. Exiting...\n");
    return 0;
}

void print_menu()
{
    printf(" -------------[Booking System]-------------\n");
    printf("|            a. Available seats            |\n");
    printf("|            b. Arrange for you            |\n");
    printf("|           c. Choose by yourself          |\n");
    printf("|                  d. Exit                 |\n");
    printf(" ------------------------------------------\n");
}

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

void initialize_seats(char seats[ROWS][COLS])
{
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            seats[i][j] = '-';
        }
    }

    for (int k = 0; k < 10; k++) // Now initializing only 10 random seats
    {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '*')
        {
            k--; // Avoid duplicating the seat assignment
        }
        else
        {
            seats[r][c] = '*';
        }
    }
}

int check_seats(char seats[ROWS][COLS], int row, int start_col, int num_seats)
{
    for (int i = 0; i < num_seats; i++)
    {
        if (seats[row][start_col + i] != '-')
        {
            return 0; // Seat is already booked
        }
    }
    return 1; // Seats are available
}

void mark_seats(char seats[ROWS][COLS], int row, int col, int num_seats, char mark)
{
    for (int i = 0; i < num_seats; i++)
    {
        seats[row][col + i] = mark;
    }
}

int try_assign_seats(char seats[ROWS][COLS], int num_seats)
{
    if (num_seats == 4)
    {
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col <= COLS - num_seats; col++)
            {
                if (check_seats(seats, row, col, num_seats))
                {
                    mark_seats(seats, row, col, num_seats, '@');
                    return 1;
                }
            }
        }
        for (int row = 0; row < ROWS - 1; row++)
        {
            for (int col = 0; col <= COLS - 2; col++)
            {
                if (check_seats(seats, row, col, 2) && check_seats(seats, row + 1, col, 2))
                {
                    mark_seats(seats, row, col, 2, '@');
                    mark_seats(seats, row + 1, col, 2, '@');
                    return 1;
                }
            }
        }
    }
    else
    {
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col <= COLS - num_seats; col++)
            {
                if (check_seats(seats, row, col, num_seats))
                {
                    mark_seats(seats, row, col, num_seats, '@');
                    return 1;
                }
            }
        }
    }
    return 0;
}

void ask_for_satisfaction(char seats[ROWS][COLS], int num_seats)
{
    char response;
    print_seats(seats);
    printf("Do you like these seats? (Y/N): ");
    fflush(stdin);
    scanf(" %c", &response);
    response = toupper(response);
    if (response == 'Y')
    {
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLS; col++)
            {
                if (seats[row][col] == '@')
                {
                    seats[row][col] = '*'; // Finalize the booking
                }
            }
        }
    }
    else
    {
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLS; col++)
            {
                if (seats[row][col] == '@')
                {
                    seats[row][col] = '-'; // Reset the proposed seats
                }
            }
        }
    }
}

void exit_sequence()
{
    printf("Exiting program.\n");
    exit(0);
}

int main()
{
    char seats[ROWS][COLS];
    char command;
    int num_seats;

    system("cls");
    print_welcome_screen();
    if (!password_prompt())
    {
        return 0;
    }

    initialize_seats(seats);

    while (1)
    {
        system("cls");
        print_menu();
        printf("Choose an option: ");
        fflush(stdin);
        if (scanf(" %c", &command) != 1 || !strchr("abcd", tolower(command)))
        {
            printf("Invalid command. Please try again.\n");
            fflush(stdin); // Clear input buffer
            continue; // Skip the rest of the loop
        }

        command = tolower(command);

        switch (command)
        {
            case 'a':
                print_seats(seats);
                printf("Press any key to return to the main menu...\n");
                getch();
                break;
            case 'b':
                printf("How many seats do you need (1-4)? ");
                if (scanf("%d", &num_seats) != 1 || num_seats < 1 || num_seats > 4)
                {
                    printf("Invalid number of seats. Please enter a number between 1 and 4.\n");
                    fflush(stdin); // Clear input buffer
                    break;
                }
                if (try_assign_seats(seats, num_seats))
                {
                    ask_for_satisfaction(seats, num_seats);
                }
                else
                {
                    printf("Unable to assign the requested number of seats. Please try again.\n");
                }
                break;
            case 'c':
                // Here you would have your manual seat selection function logic
                break;
            case 'd':
                exit_sequence();
                break;
        }
    }

    return 0;
}
