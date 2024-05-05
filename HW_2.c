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
    
    return 0;
}