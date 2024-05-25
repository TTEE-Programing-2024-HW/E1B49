#include <stdio.h>
#include <stdlib.h>

int main()
{
    // ��ܭөʤ��w��e��
    printf("**********************************************\n");
    printf("*                                            *\n");
    printf("*       Welcome to My Unique Program�I       *\n");
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
    printf("*     mysteries of programming together�I    *\n");
    printf("*                                            *\n");
    printf("*     Here, creativity meets logic, and      *\n");
    printf("*     dreams transform into reality.         *\n");
    printf("*                                            *\n");
    printf("*     Ready to start�HPress any key to       *\n");
    printf("*     dive into the adventure�I              *\n");
    printf("*                                            *\n");
    printf("**********************************************\n");
    
    getchar(); // ���ݥΤ����H�~��

    system("cls"); // �M���ù��A���U�@�B���ǳ�

    // �B�J2�G�n�D�Τ��J�K�X
    int password = 2024; // �w�]���K�X��
    int input; // �Τ��J���K�X
    
    printf("Please enter the 4-digit password�G"); // ���ܥΤ��J4��K�X
    scanf("%d", &input);
    
    while (getchar() != '\n'); // �M�ſ�J�w�İϡA�ǳƤU�@����J

    if (input == password) 
    {
        // �K�X���T�A����w��T��
        printf("\nWelcome�IYou have entered the correct password.");
        getchar(); // ���ݥΤ����H�~��
        system("cls"); // �M���ù�

        // �B�J3�G�r�������ˬd
        char ch;
        do {
            // ��ܦr�������ˬd���n
            printf("��������������������������������������������������������������������������������\n");
            printf("��       Analyze the characters         ��\n");
            printf("��������������������������������������������������������������������������������\n");
            printf("��       'A' ... 'Z' : Uppercase        ��\n");
            printf("��       'a' ... 'z' : Lowercase        ��\n");
            printf("��       '0' ... '9' : Digit            ��\n");
            printf("��        Otherwise  : Your Name        ��\n");
            printf("��������������������������������������������������������������������������������\n");
            printf("\nCharacter type checking. Type '!' to exit.\n");
            printf("\nEnter a character�G");

            ch = getchar(); // Ū���Τ��J���r��

            while (getchar() != '\n'); // �M�ſ�J�w�İ�

            if (ch == '!') // �Y��J'!'�h�h�X�{��
            {
                break;
            }

            // �ھڿ�J���r���������X���X
            switch (ch) 
            {
                case 'A' ... 'Z': // �j�g�r��
                    printf("\nUppercase");
                    break;

                case 'a' ... 'z': // �p�g�r��
                    printf("\nLowercase");
                    break;

                case '0' ... '9': // �Ʀr
                    printf("\nDigit");
                    break;

                default: // ��L�r��
                    printf("\nE1B 49 ���E��"); //�Z�� �y�� �m�W 
            }

            getchar(); // ���ݥΤ����H�~��
            system("cls"); // �M���ù��A���A����J���ǳ�

        } while (1); // �L���`������Τ��J'!'�h�X

        printf("\nYou have exited the character analysis.\n"); // ���ܥΤ�w�h�X�r�Ť��R
    } 
    else 
    {
        printf("\nIncorrect password. Access denied.\n");// �K�X��J���~�A��ܿ��~�T���õ����{��
    }

    printf("\nPress any key to exit.");
    getchar(); // ���ݥΤ����H�h�X�{��
    
    return 0;
}

//�z�L�o�ӽm�ߡA�i�H�ݨ�A�n�����ѥi�H�j�T�״����N�X���iŪ�ʡC�������ӲM���a�����N�X���ت��B�p��B��A�H�δ��檺��J��X�C
//�N�X�����c�M���A�N�{�ǹ������h�ӨB�J�A�C�@�B�������T���ت��M��X�A�o���U��z�Ѿ��骺�{�Ǭy�{�M�U�����p���P�u�@�C
//�Τ᤬�ʬO�\�h�{�Ǫ����䳡���A�o�ӵ{���X�i�ܤF�p��ϥΰ򥻪���J�M��X��ƨӹ�{�o�@�I�A�P�ɤ]�i�ܤF�@�ǳB�z�Τ��J���ޥ��A��p�p��M�ſ�J�w�İϥH�קK�����n�����~�C
//�̫�A�ٮi�ܤF�p��ھڥΤ��J���X�M���M�����A�o�O�s�{���@�ӫD�`���n�������C�q�L���o�ǰ�¦�����A�i�H���ǲߧ��������s�{�޳N���U��ꪺ��¦�C
