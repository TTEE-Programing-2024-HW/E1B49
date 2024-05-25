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

// 輸入學生成績的函數
void enterStudentGrades(Student students[], int *n)
{
    clearScreen();
    while (1)
    {
        printf("請輸入學生人數 (5~10)：");
        fflush(stdin);
        scanf("%d", n);
        if (*n >= MIN_STUDENTS && *n <= MAX_STUDENTS)
        {
            break;
        }
        else
        {
            printf("\n輸入錯誤，請輸入 5 到 10 之間的整數。\n\n");
        }
    }

    for (int i = 0; i < *n; i++)
    {
        printf("\n請輸入第 %d 位學生資料\n", i + 1);

        printf("姓名：");
        fflush(stdin);
        scanf("%s", students[i].name);

        printf("學號 (6位整數)：");
        while (scanf("%d", &students[i].id) != 1 || students[i].id < 100000 || students[i].id > 999999)
        {
            printf("\n學號輸入錯誤，請輸入 6 位整數學號：");
            while (getchar() != '\n')
                ; // 清除緩衝區
        }

        printf("數學成績 (0~100)：");
        while (scanf("%d", &students[i].math) != 1 || students[i].math < 0 || students[i].math > 100)
        {
            printf("\n數學成績輸入錯誤，請輸入 0 到 100 之間的分數：");
            while (getchar() != '\n')
                ; // 清除緩衝區
        }

        printf("物理成績 (0~100)：");
        while (scanf("%d", &students[i].physics) != 1 || students[i].physics < 0 || students[i].physics > 100)
        {
            printf("\n物理成績輸入錯誤，請輸入 0 到 100 之間的分數：");
            while (getchar() != '\n')
                ; // 清除緩衝區
        }

        printf("英文成績 (0~100)：");
        while (scanf("%d", &students[i].english) != 1 || students[i].english < 0 || students[i].english > 100)
        {
            printf("\n英文成績輸入錯誤，請輸入 0 到 100 之間的分數：");
            while (getchar() != '\n')
                ; // 清除緩衝區
        }

        // 計算平均成績
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }

    printf("\n所有學生資料已輸入完畢，請按下任一鍵以返回主選單。");
    getch(); // 等待用戶按鍵
}

// 顯示學生成績的函數
void displayStudentGrades(Student students[], int n)
{
    clearScreen();
    printf("學生姓名\t學號\t數學\t物理\t英文\t平均成績\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t%d\t%d\t%d\t%.1f\n", students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
    }

    printf("\n請按下任一鍵以返回主選單...");
    getch(); // 等待用戶按鍵
}

// 搜尋學生成績的函數
void searchStudentGrades(Student students[], int n)
{
    char searchName[NAME_LEN];
    int found = 0;

    clearScreen();
    printf("請輸入要搜尋的學生姓名，英文不分大小寫：");
    scanf("%s", searchName);

    // 將搜尋姓名轉換為小寫
    for (int i = 0; searchName[i]; i++)
    {
        searchName[i] = tolower(searchName[i]);
    }

    for (int i = 0; i < n; i++)
    {
        char tempName[NAME_LEN];
        strcpy(tempName, students[i].name);

        // 將學生姓名轉換為小寫
        for (int j = 0; tempName[j]; j++)
        {
            tempName[j] = tolower(tempName[j]);
        }

        if (strcmp(tempName, searchName) == 0)
        {
            printf("\n學生資料：\n");
            printf("姓名：%s\n", students[i].name);
            printf("學號：%d\n", students[i].id);
            printf("數學成績：%d\n", students[i].math);
            printf("物理成績：%d\n", students[i].physics);
            printf("英文成績：%d\n", students[i].english);
            printf("平均成績：%.1f\n", students[i].average);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\n資料不存在。\n");
    }

    printf("\n請按下任一鍵以返回主選單...");
    getch(); // 等待用戶按鍵
}

// 成績排名的函數
void gradeRanking(Student students[], int n)
{
    clearScreen();

    // 使用泡沫排序法排序成績
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].average < students[j + 1].average)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("成績排名，由高到低：\n\n");
    printf("學生姓名\t學號\t平均成績\n");
    printf("--------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
    }

    printf("\n請按下任一鍵以返回主選單...");
    getch(); // 等待用戶按鍵
}

// 確認離開的函數
void exitConfirmation()
{
    char choice;

    while (1)
    {
        printf("\n確定離開？(Y/N)，不分大小寫：");
        fflush(stdin);
        scanf("%c", &choice);
        choice = tolower(choice);

        if (choice == 'y')
        {
            printf("\n程式即將結束。");
            exit(0);
        }
        else if (choice == 'n')
        {
            return;
        }
        else
        {
            printf("\n無效選項，請輸入 Y 或 N，不分大小寫。\n");
        }
    }
}