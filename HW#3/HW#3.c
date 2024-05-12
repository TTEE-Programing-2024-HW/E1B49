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