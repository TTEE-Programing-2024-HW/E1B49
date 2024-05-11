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

// Function to initialize the seating chart with random bookings
void initialize_seats(char seats[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            seats[i][j] = '-';
        }
    }

    srand(time(NULL));
    for (int k = 0; k < 10; k++)
    {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '*')
        {
            k--; // If already booked, retry
        }
        else
        {
            seats[r][c] = '*';
        }
    }
}

// Function to check and assign seats for automatic arrangement
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

void assign_seats(char seats[ROWS][COLS], int num_seats) 
{
    int assigned = 0;
    while (!assigned) 
    {
        int row = rand() % ROWS;
        int col = rand() % (COLS - num_seats + 1); // Ensure there are enough contiguous seats

        if (check_seats(seats, row, col, num_seats)) 
        {
            for (int i = 0; i < num_seats; i++) 
            {
                seats[row][col + i] = '@'; // Mark the recommended seats
            }
            assigned = 1;
        }
    }
}

// Function to allow users to choose their own seats
void process_seat_selection(char seats[ROWS][COLS])
{
    char input[10];
    int row, col;
    char response;

    printf("Enter seat (e.g., 1-2 for row 1, column 2): ");
    while (scanf("%s", input) == 1) 
    {
        if (sscanf(input, "%d-%d", &row, &col) == 2 && row > 0 && col > 0 && row <= ROWS && col <= COLS && seats[row-1][col-1] == '-') 
        {
            seats[row-1][col-1] = '@';  // Mark the selected seat
            print_seats(seats);
            printf("Are you satisfied with this seat (y/n)? ");
            scanf(" %c", &response);

            if (toupper(response) == 'Y') 
            {
                seats[row-1][col-1] = '*';  // Finalize the booking
                return; // Exit after booking
            }
            else 
            {
                seats[row-1][col-1] = '-'; // Reset if not satisfied
                printf("Please re-enter your seat choice: ");
            }
        }
        else 
        {
            printf("Invalid seat or already booked. Please try again: ");
        }
    }
}

// Function to handle exit sequence
void exit_sequence() 
{
    char response;
    do
    {
        printf("Continue? (Y/N): ");
        scanf(" %c", &response);
        response = toupper(response);

        if (response == 'Y') 
        {
            system("clear"); // Clear the screen and return to the main menu
            return;
        } 
        else if (response == 'N') 
        {
            printf("Exiting program.\n");
            exit(0);
        } 
        else 
        {
            printf("Invalid input. Please enter 'Y' for Yes or 'N' for No.\n");
        }
    } while (response != 'Y' && response != 'N');
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
        print_seats(seats);
        print_menu();
        printf("Choose an option: ");
        scanf(" %c", &command);
        command = tolower(command);

        switch (command)
        {
            case 'a':
            {
                print_seats(seats);
                printf("Press any key to return to the main menu...\n");
                getchar(); getchar();
                break;
            }
            case 'b':
            {
                printf("How many seats do you need (1-4)? ");
                scanf("%d", &num_seats);
                if (num_seats >= 1 && num_seats <= 4)
                {
                    assign_seats(seats, num_seats);
                    print_seats(seats);
                    printf("Press any key to return to the main menu...\n");
                    getchar(); getchar();
                }
                break;
            }
            case 'c':
            {
                process_seat_selection(seats);
                printf("Press any key to return to the main menu...\n");
                getchar(); getchar();
                break;
            }
            case 'd':
            {
                exit_sequence();
                break;
            }
            default:
            {
                printf("Invalid command. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}