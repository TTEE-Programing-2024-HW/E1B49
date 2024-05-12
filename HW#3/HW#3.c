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
    int seats[ROWS][COLS];
    char choice;
    int keepRunning = 1;

    if (checkPassword())
    {
        initializeSeats(seats);
        do
        {
            showMainMenu();
            fflush(stdin);
            scanf(" %c", &choice);
            choice = tolower(choice);

            switch (choice)
            {
                case 'a':
                    showSeats(seats);
                    pressAnyKeyToContinue();
                    system("cls"); // Clear screen and return to main menu
                    break;

                case 'b':
                    printf("\nHow many seats do you need¡]1-4¡^¡H ");
                    int numSeats;
                    fflush(stdin);
                    scanf("%d", &numSeats);
                    if (numSeats < 1 || numSeats > 4)
                    {
                        printf("\nInput error, please enter a number between 1-4.\n");
                        pressAnyKeyToContinue();
                    }
                    else if (suggestSeats(seats, numSeats))
                    {
                        showSeats(seats);
                        printf("\nAre you satisfied with this seat arrangement¡H¡]y/n¡^: ");
                        char response;
                        fflush(stdin);
                        scanf(" %c", &response);
                        if (tolower(response) == 'y')
                        {
                            acceptSuggestedSeats(seats);
                            system("cls"); // Clear screen and return to main menu
                        }
                        else if (tolower(response) == 'n')
                        {
                            revertSuggestedSeats(seats); // Cancel the suggested seats
                            system("cls");               // Clear screen and return to main menu
                        }
                        else
						{
							printf("\nInvalid input, please re-enter.\n");
							revertSuggestedSeats(seats);
							pressAnyKeyToContinue();
							system("cls");
						}
                    }
                    else
                    {
                        printf("\nNot enough seats available.\n");
                        pressAnyKeyToContinue();
                    }
                    break;
                    
                case 'c':
                    chooseSeats(seats);
                    break;

                case 'd':
                    keepRunning = exitConfirmation();
                    break;

                default:
                    printf("\nInvalid input, please re-enter.\n");
                    pressAnyKeyToContinue();
                    break;
            }
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

void pressAnyKeyToContinue()
{
    printf("\nPress any key to continue...");
    getch();
}

void initializeSeats(int seats[ROWS][COLS])
{
    srand(time(NULL)); // Initialize random seed
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            seats[i][j] = 0; // Initialize all seats as empty
        }
    }

    int booked = 0;
    while (booked < 10)
    { // Pre-book some seats randomly
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == 0)
        {
            seats[r][c] = 1; // Mark seat as booked
            booked++;
        }
    }
}

void showSeats(int seats[ROWS][COLS])
{
    printf("\nSeat map¡G\n");
    printf("\n");
    printf("  123456789\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", seats[i][j] == 1 ? '*' : (seats[i][j] == 2 ? '@' : '-')); // Display seat status
        }
        printf("\n");
    }
}

int suggestSeats(int seats[ROWS][COLS], int numSeats)
{
    int found = 0;

    if (numSeats >= 1 && numSeats <= 3)
    {
        // Try to find numSeats in a single row
        for (int i = 0; i < ROWS && !found; i++)
        {
            for (int j = 0; j <= COLS - numSeats; j++)
            {
                int valid = 1;
                for (int k = 0; k < numSeats; k++)
                {
                    if (seats[i][j + k] != 0)
                    {
                        valid = 0;
                        break;
                    }
                }
                if (valid)
                {
                    for (int k = 0; k < numSeats; k++)
                    {
                        seats[i][j + k] = 2; // Suggest these seats
                    }
                    found = 1;
                    break;
                }
            }
        }
    }
    else if (numSeats == 4)
    {
        // Try to find 4 seats in one row or two consecutive rows with 2 seats each
        found = findFourSeats(seats);
    }

    return found; // 1 if seats suggested successfully, 0 otherwise
}

int findFourSeats(int seats[ROWS][COLS])
{
    int found = 0;
    // First, try to find 4 continuous seats in one row
    for (int i = 0; i < ROWS && !found; i++)
    {
        for (int j = 0; j <= COLS - 4; j++)
        {
            if (seats[i][j] == 0 && seats[i][j + 1] == 0 && seats[i][j + 2] == 0 && seats[i][j + 3] == 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    seats[i][j + k] = 2;
                }
                found = 1;
                break;
            }
        }
    }

    // If not found, try two consecutive rows with 2 seats each
    if (!found)
    {
        for (int i = 0; i < ROWS - 1 && !found; i++)
        {
            for (int j = 0; j <= COLS - 2; j++)
            {
                if (seats[i][j] == 0 && seats[i][j + 1] == 0 &&
                    seats[i + 1][j] == 0 && seats[i + 1][j + 1] == 0)
                {
                    seats[i][j] = 2;
                    seats[i][j + 1] = 2;
                    seats[i + 1][j] = 2;
                    seats[i + 1][j + 1] = 2;
                    found = 1;
                    break;
                }
            }
        }
    }

    return found;
}

void acceptSuggestedSeats(int seats[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (seats[i][j] == 2)
            {
                seats[i][j] = 1; // Confirm the seat selection by marking it reserved
            }
        }
    }
}

void revertSuggestedSeats(int seats[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (seats[i][j] == 2)
            {
                seats[i][j] = 0; // Revert suggested seats back to empty
            }
        }
    }
}

void chooseSeats(int seats[ROWS][COLS])
{
    int row, col;
    char input[10];
    char response;
    int totalSeats = 0; // Count the number of seats chosen

    while (1)
    {
        printf("\nPlease enter seat choice (format like 1-2 for Row 1, Column 2) or enter 'Q'¡B'q' to finish choosing¡G");
        fflush(stdin);
        scanf("%s", input);

        if (tolower(input[0]) == 'q')
        { // If 'q' or 'Q' is entered, end choosing
            break;
        }

        if (sscanf(input, "%d-%d", &row, &col) == 2 && row >= 1 && row <= ROWS && col >= 1 && col <= COLS)
        {
            if (seats[row - 1][col - 1] == 0)
            {
                seats[row - 1][col - 1] = 2; // Mark the seat as chosen temporarily
                totalSeats++;
            }
            else
            {
                printf("Error¡GThe seat is already booked or unavailable.\n");
            }
        }
        else
        {
            printf("Error¡GIncorrect input format.\n");
        }
    }

    if (totalSeats > 0)
    {
        showSeats(seats);
        printf("\nAre you satisfied with the seat choices¡H¡]y/n¡^: ");
        fflush(stdin);
        scanf(" %c", &response);
        if (tolower(response) == 'y')
        {
            for (int i = 0; i < ROWS; i++)
            { // Confirm choices, convert '@' to '*'
                for (int j = 0; j < COLS; j++)
                {
                    if (seats[i][j] == 2)
                    {
                        seats[i][j] = 1; // Confirm choice
                    }
                }
            }
            printf("Selection confirmed.\n");
        }
        else
        {
            revertSuggestedSeats(seats); // Revert unconfirmed choices
            printf("Selection reverted.\n");
        }
        pressAnyKeyToContinue();
    }

    system("cls"); // Clear the screen
}

int exitConfirmation()
{
    char response;
    printf("\nContinue¡H(Y/N)¡G");
    while (1)
    {
        fflush(stdin);
        scanf(" %c", &response);
        response = tolower(response);

        if (response == 'y')
        {
        	printf("\nReturn to main menu.\n");
        	printf("\nPress any key to continue...");
        	getch();
            return 1; // Return to main menu
        }
        else if (response == 'n')
        {
        	printf("\nThe program will end soon.\n");
        	printf("\nPress any key to continue...");
        	getch();
            return 0; // End program
        }
        else
        {
            printf("Invalid input, please re-enter.\n");
        }
    }
}