#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 顯示個性化歡迎畫面
    printf("**********************************************\n");
    printf("*                                            *\n");
    printf("*       Welcome to My Unique Program！       *\n");
    printf("*      A Journey into the World of Code      *\n");
    printf("*                                            *\n");
    printf("*   H   H   EEEEE   L       L       OOOOO    *\n");
    printf("*   H   H   E       L       L      O     O   *\n");
    printf("*   HHHHH   EEEEE   L       L      O     O   *\n");
    printf("*   H   H   E       L       L      O     O   *\n");
    printf("*   H   H   EEEEE   LLLLL   LLLLL   OOOOO    *\n");
    printf("*                                            *\n");
    printf("*     Coding is like magic - full of         *\n");
    printf("*     surprises, challenges, and endless     *\n");
    printf("*     possibilities. Let's unravel the       *\n");
    printf("*     mysteries of programming together！    *\n");
    printf("*                                            *\n");
    printf("*     Here, creativity meets logic, and      *\n");
    printf("*     dreams transform into reality.         *\n");
    printf("*                                            *\n");
    printf("*     Ready to start？Press any key to       *\n");
    printf("*     dive into the adventure！              *\n");
    printf("*                                            *\n");
    printf("**********************************************\n");
    
    getchar(); // 等待用戶按鍵以繼續

    system("cls"); // 清除螢幕，為下一步做準備

    // 步驟2：要求用戶輸入密碼
    int password = 2024; // 預設的密碼值
    int input; // 用戶輸入的密碼
    
    printf("Please enter the 4-digit password："); // 提示用戶輸入4位密碼
    scanf("%d", &input);
    
    while (getchar() != '\n'); // 清空輸入緩衝區，準備下一次輸入

    if (input == password) 
    {
        // 密碼正確，顯示歡迎訊息
        printf("\nWelcome！You have entered the correct password.");
        getchar(); // 等待用戶按鍵以繼續
        system("cls"); // 清除螢幕

        // 步驟3：字符類型檢查
        char ch;
        do {
            // 顯示字符類型檢查指南
            printf("╔══════════════════════════════════════╗\n");
            printf("║       Analyze the characters         ║\n");
            printf("╠══════════════════════════════════════╣\n");
            printf("║       'A' ... 'Z' : Uppercase        ║\n");
            printf("║       'a' ... 'z' : Lowercase        ║\n");
            printf("║       '0' ... '9' : Digit            ║\n");
            printf("║        Otherwise  : Your Name        ║\n");
            printf("╚══════════════════════════════════════╝\n");
            printf("\nCharacter type checking. Type '!' to exit.\n");
            printf("\nEnter a character：");

            ch = getchar(); // 讀取用戶輸入的字符

            while (getchar() != '\n'); // 清空輸入緩衝區

            if (ch == '!') // 若輸入'!'則退出程序
            {
                break;
            }

            // 根據輸入的字符類型給出反饋
            switch (ch) 
            {
                case 'A' ... 'Z': // 大寫字母
                    printf("\nUppercase");
                    break;

                case 'a' ... 'z': // 小寫字母
                    printf("\nLowercase");
                    break;

                case '0' ... '9': // 數字
                    printf("\nDigit");
                    break;

                default: // 其他字符
                    printf("\nE1B 49 戴淳文"); //班級 座號 姓名 
            }

            getchar(); // 等待用戶按鍵以繼續
            system("cls"); // 清除螢幕，為再次輸入做準備

        } while (1); // 無限循環直到用戶輸入'!'退出

        printf("\nYou have exited the character analysis.\n"); // 提示用戶已退出字符分析
    } 
    else 
    {
        printf("\nIncorrect password. Access denied.\n");// 密碼輸入錯誤，顯示錯誤訊息並結束程式
    }

    printf("\nPress any key to exit.");
    getchar(); // 等待用戶按鍵以退出程式
    
    return 0;
}

//透過這個練習，可以看到，好的註解可以大幅度提高代碼的可讀性。註解應該清晰地解釋代碼的目的、如何運行，以及期望的輸入輸出。
//代碼的結構清晰，將程序劃分為多個步驟，每一步都有明確的目的和輸出，這有助於理解整體的程序流程和各部分如何協同工作。
//用戶互動是許多程序的關鍵部分，這個程式碼展示了如何使用基本的輸入和輸出函數來實現這一點，同時也展示了一些處理用戶輸入的技巧，比如如何清空輸入緩衝區以避免不必要的錯誤。
//最後，還展示了如何根據用戶輸入做出決策和反應，這是編程中一個非常重要的概念。通過實踐這些基礎概念，可以為學習更覆雜的編程技術打下堅實的基礎。
