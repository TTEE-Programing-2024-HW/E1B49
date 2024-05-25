#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define MAX_STUDENTS 10
#define MIN_STUDENTS 5
#define NAME_LEN 50
#define ID_LEN 6
#define PASSWORD "2024"
#define MAX_ATTEMPTS 3

// 學生資料結構體
typedef struct
{
    char name[NAME_LEN];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

// 函數聲明
void clearScreen();
void displayMenu();
void enterStudentGrades(Student students[], int *n);
void displayStudentGrades(Student students[], int n);
void searchStudentGrades(Student students[], int n);
void gradeRanking(Student students[], int n);
void exitConfirmation();
void checkPassword();
void showMain();

int main()
{
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    char choice;
}

void clearScreen()
{
    system("cls");
}

// 顯示個人畫面的函數
void showMain()
{
    printf("      ______________\n");
    printf("     /              \\\n");
    printf("    /                \\\n");
    printf("   /                  \\\n");
    printf("  /                    \\\n");
    printf(" /                      \\\n");
    printf("|                        |\n");
    printf("|                        |\n");
    printf("|                        |\n");
    printf("|       _________        |\n");
    printf("|      /         \\       |\n");
    printf("|     /  R  I  P  \\      |\n");
    printf("|    /             \\     |\n");
    printf("|   /_______________\\    |\n");
    printf("|                        |\n");
    printf("|                        |\n");
    printf("|                        |\n");
    printf("|                        |\n");
    printf("|                        |\n");
    printf("|                        |\n");
    printf("|                        |\n");
    printf("|                        |\n");
    printf("|                        |\n");
    printf("|                        |\n");
    printf("|________________________|\n");
}

// 檢查密碼的函數
void checkPassword()
{
    char input[5];
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS)
    {
        printf("請輸入四位數的密碼：");
        scanf("%4s", input);

        if (strcmp(input, PASSWORD) == 0)
        {
            printf("\n密碼正確，歡迎！");
            system("pause");
            return;
        }
        else
        {
            printf("\n密碼錯誤，請再試一次。\n\n");
            attempts++;
        }
    }

    if (attempts == MAX_ATTEMPTS)
    {
        printf("已連續錯誤三次，程式結束。");
        exit(1);
    }
}

// 顯示主選單的函數
void displayMenu()
{
    printf(" ------------[Grade System]-----------\n");
    printf("|     a. Enter student grades         |\n");
    printf("|     b. Display student grades       |\n");
    printf("|     c. Search for student grades    |\n");
    printf("|     d. Grade ranking                |\n");
    printf("|     e. Exit system                  |\n");
    printf(" -------------------------------------\n");
}