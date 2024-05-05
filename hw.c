#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // 引入標頭檔以使用 getch() 函數，實現按鍵即時響應

// 函數宣告
void showTriangle(char c);
void printMultiplicationTable(int n);
int handleExitOption();
void handleTriangleOption();
void handleMultiplicationTableOption();

int main()
{
    int password = 2024; // 預設的密碼
    int input;           // 用戶輸入的密碼
    int attempt = 0;     // 嘗試輸入密碼的次數
    int choice;
    const int max_attempts = 3; // 最大嘗試次數

    // 顯示個人風格的畫面
    system("cls");
    printf("**************************************************\n");
    printf("*                歡迎使用安全系統                *\n");
    printf("*                 請依照提示操作                 *\n");
    printf("*                                                *\n");
	printf("*                                                *\n");
	printf("*                                                *\n");
	printf("*                                                *\n");
	printf("*                                                *\n");
	printf("*                                                *\n");
    printf("*                                                *\n");
	printf("+       H   H  EEEEE   L      L       OOO        *\n");
    printf("*       H   H  E       L      L      O   O       *\n");
    printf("*       HHHHH  EEEEE   L      L      O   O       *\n");
    printf("*       H   H  E       L      L      O   O       *\n");
    printf("*       H   H  EEEEE   LLLLL  LLLLL   OOO        *\n");
	printf("*                                                *\n");
	printf("*                                                *\n");
	printf("*                                                *\n");
	printf("*                                                *\n");
	printf("*                                                *\n");
	printf("*                                                *\n");
	printf("*                                                *\n");
	printf("*                                                *\n");
	printf("*                                                *\n");
	printf("**************************************************\n");

while (attempt < max_attempts)
    {
        printf("請輸入四位數字的密碼：");
        fflush(stdin);
        scanf("%d", &input);
        
        if (input == password)
        {
            while (1)
            {
                system("cls");
                printf(" -----------------------------------------\n");
                printf("|            a. 畫出直角三角形            |\n");
                printf("|                                         |\n");
				printf("|             b. 顯示乘法表               |\n");
                printf("|                                         |\n");
				printf("|                c. 結束                  |\n");
                printf(" -----------------------------------------\n");
                
                printf("輸入A、B、C以繼續，不分大小寫：");
                choice = getche();

                switch (choice)
                {
                    case 'a':
                    case 'A':
                        handleTriangleOption();
                        break;
                        
                    case 'b':
                    case 'B':
                        handleMultiplicationTableOption();
                        break;
                        
                    case 'c':
                    case 'C':
                        if (handleExitOption() == 1)
                        {
                            return 0;  // 如果選擇結束，退出程式
                        }
                        break;
                        
                    default:
                    	printf("\n");
                        printf("\n無效的選項！");
                        getch();
                        break;
                }
            }
        }
        else
        {
            attempt++;
            printf("\n密碼錯誤！這是第 %d 次嘗試，還剩 %d 次機會。\n", attempt, max_attempts - attempt);
            
            if (attempt == max_attempts)
            {
                printf("\n連續三次密碼錯誤，程式即將結束。");
                
                return 1; // 結束程式
            }
        }
    }
    
    return 0;
}

void handleTriangleOption()
{
    char character;
    
    printf("\n");
    printf("\n請輸入一個字元（a 到 n）：");
    fflush(stdin);
    scanf(" %c", &character);
    
    if (character < 'a' || character > 'n')
    {
        printf("\n錯誤的輸入！請重新輸入。");
        getch();  // 等待任意鍵再次輸入
    }
    else
    {
        system("cls");
        showTriangle(character);
    }
    
    getch();  // 等待任意鍵回到主選單
}

void showTriangle(char c)
{
    int height = c - 'a' + 1;  // 計算三角形的高度
    
    for (int row = 1; row <= height; row++)
    {
        // 打印空格，對齊三角形的右側
        for (int space = 1; space <= height - row; space++)
        {
            printf(" ");
        }
        // 打印從字母開始到輸入字母的字符
        for (char col = c - row + 1; col <= c; col++)
        {
            printf("%c", col);
        }
        printf("\n");
    }
}