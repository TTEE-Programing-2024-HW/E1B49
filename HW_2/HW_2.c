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

void handleMultiplicationTableOption()
{
    int n;
    
    printf("\n");
    printf("\n請輸入一個整數（1至9）：");
    fflush(stdin);
    scanf("%d", &n);
    
    if (n < 1 || n > 9)
    {
        printf("\n錯誤的輸入！請輸入1至9之間的整數。");
        getch();  // 等待任意鍵再次輸入
    }
    else
    {
        system("cls");
        printMultiplicationTable(n);
    }
    
    getch();  // 等待任意鍵回到主選單
}

void printMultiplicationTable(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d＊%d＝%2d  ", i, j, i * j);
        }
        printf("\n");
    }
}

int handleExitOption()
{
    char choice;
    
    printf("\n");
    printf("\nContinue？（y/n）");
    choice = getch();
    
    if (choice == 'y' || choice == 'Y')
    {
    	return 0;
    }
    else if (choice == 'n' || choice == 'N')
    {
    	printf("\n");
        printf("\n程式結束，回到作業系統。");
        
        return 1;
    }
    else
    {
    	printf("\n");
        printf("\n錯誤的輸入！請輸入 y 或 n，重新輸入。");
        getch();
        
        return 0;
    }
}

//心得：

//在開發這個程式的過程中，
//我學到如何利用基本的控制台輸入/輸出，實現與用戶互動。
//透過使用 getch() 和 getche() 函數，
//我能夠捕捉用戶的即時輸入，
//對於建立交互式應用程序來說是非常實用的技能。

//為了提升程式的安全性，
//我實現了一個簡單的密碼保護機制。
//這讓我了解在更大的應用範圍中，
//如何處理和保護敏感資訊的重要性。
//雖然這個機制還很基本，
//但它提供了一個很好的學習基礎。

//在這個程式中，
//我練習了將不同的功能模塊化，
//例如畫三角形和顯示乘法表的功能。
//這不僅使程式結構更清晰，
//也使得每個部分更容易維護和擴展。
//學習如何有效地組織代碼，
//是進行更大規模開發的一個重要步驟。

//我意識到，
//良好的錯誤處理是任何程式必不可少的一部分。
//在這個程式中，
//我處理了一些基本輸入錯誤，
//這有助於保護程式免受不正確輸入的干擾。
//這讓我更加熟悉如何在用戶輸入有誤時給予反饋，
//並促使用戶重新輸入。

//使用conio.h這個非標準庫讓我了解跨平台兼容性的重要性。
//這是一個學習機會，
//讓我意識到為了使程式更加通用，
//尋找或開發可跨平台的解決方案是必要的。
//總之，
//這個程式不僅提高了我的C語言編程能力，
//也加深了我對軟體開發中一些關鍵概念的理解，
//如用戶交互、安全性、模塊化設計和錯誤處理。
//我期待將這些經驗應用到未來更複雜的項目中。