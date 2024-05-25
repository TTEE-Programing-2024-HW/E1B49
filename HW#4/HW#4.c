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

// �ǥ͸�Ƶ��c��
typedef struct
{
    char name[NAME_LEN];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

// ����n��
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

    // �����i��K�X�ˬd
    showmain();
    checkPassword();

    while (1)
    {
        clearScreen();
        displayMenu();
        printf("�п�ܿﶵ�A�����j�p�g�G");
        fflush(stdin);
        scanf("%c", &choice);
        choice = tolower(choice);

        switch (choice)
        {
        case 'a':
            enterStudentGrades(students, &studentCount);
            break;
        case 'b':
            displayStudentGrades(students, studentCount);
            break;
        case 'c':
            searchStudentGrades(students, studentCount);
            break;
        case 'd':
            gradeRanking(students, studentCount);
            break;
        case 'e':
            exitConfirmation();
            break;
        default:
            printf("\n�L�Ŀﶵ�A�Э��s��ܡC\n\n");
            system("pause");
            break;
        }
    }

    return 0;
}

void clearScreen()
{
    system("cls");
}

// ��ܭӤH�e�������
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

// �ˬd�K�X�����
void checkPassword()
{
    char input[5];
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS)
    {
        printf("�п�J�|��ƪ��K�X�G");
        scanf("%4s", input);

        if (strcmp(input, PASSWORD) == 0)
        {
            printf("\n�K�X���T�A�w��I");
            system("pause");
            return;
        }
        else
        {
            printf("\n�K�X���~�A�ЦA�դ@���C\n\n");
            attempts++;
        }
    }

    if (attempts == MAX_ATTEMPTS)
    {
        printf("�w�s����~�T���A�{�������C");
        exit(1);
    }
}

// ��ܥD��檺���
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

// ��J�ǥͦ��Z�����
void enterStudentGrades(Student students[], int *n)
{
    clearScreen();
    while (1)
    {
        printf("�п�J�ǥͤH�� (5~10)�G");
        fflush(stdin);
        scanf("%d", n);
        if (*n >= MIN_STUDENTS && *n <= MAX_STUDENTS)
        {
            break;
        }
        else
        {
            printf("\n��J���~�A�п�J 5 �� 10 ��������ơC\n\n");
        }
    }

    for (int i = 0; i < *n; i++)
    {
        printf("\n�п�J�� %d ��ǥ͸��\n", i + 1);

        printf("�m�W�G");
        fflush(stdin);
        scanf("%s", students[i].name);

        printf("�Ǹ� (6����)�G");
        while (scanf("%d", &students[i].id) != 1 || students[i].id < 100000 || students[i].id > 999999)
        {
            printf("\n�Ǹ���J���~�A�п�J 6 ���ƾǸ��G");
            while (getchar() != '\n')
                ; // �M���w�İ�
        }

        printf("�ƾǦ��Z (0~100)�G");
        while (scanf("%d", &students[i].math) != 1 || students[i].math < 0 || students[i].math > 100)
        {
            printf("\n�ƾǦ��Z��J���~�A�п�J 0 �� 100 ���������ơG");
            while (getchar() != '\n')
                ; // �M���w�İ�
        }

        printf("���z���Z (0~100)�G");
        while (scanf("%d", &students[i].physics) != 1 || students[i].physics < 0 || students[i].physics > 100)
        {
            printf("\n���z���Z��J���~�A�п�J 0 �� 100 ���������ơG");
            while (getchar() != '\n')
                ; // �M���w�İ�
        }

        printf("�^�妨�Z (0~100)�G");
        while (scanf("%d", &students[i].english) != 1 || students[i].english < 0 || students[i].english > 100)
        {
            printf("\n�^�妨�Z��J���~�A�п�J 0 �� 100 ���������ơG");
            while (getchar() != '\n')
                ; // �M���w�İ�
        }

        // �p�⥭�����Z
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }

    printf("\n�Ҧ��ǥ͸�Ƥw��J�����A�Ы��U���@��H��^�D���C");
    getch(); // ���ݥΤ����
}

// ��ܾǥͦ��Z�����
void displayStudentGrades(Student students[], int n)
{
    clearScreen();
    printf("�ǥͩm�W\t�Ǹ�\t�ƾ�\t���z\t�^��\t�������Z\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t%d\t%d\t%d\t%.1f\n", students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
    }

    printf("\n�Ы��U���@��H��^�D���...");
    getch(); // ���ݥΤ����
}

// �j�M�ǥͦ��Z�����
void searchStudentGrades(Student students[], int n)
{
    char searchName[NAME_LEN];
    int found = 0;

    clearScreen();
    printf("�п�J�n�j�M���ǥͩm�W�A�^�夣���j�p�g�G");
    scanf("%s", searchName);

    // �N�j�M�m�W�ഫ���p�g
    for (int i = 0; searchName[i]; i++)
    {
        searchName[i] = tolower(searchName[i]);
    }

    for (int i = 0; i < n; i++)
    {
        char tempName[NAME_LEN];
        strcpy(tempName, students[i].name);

        // �N�ǥͩm�W�ഫ���p�g
        for (int j = 0; tempName[j]; j++)
        {
            tempName[j] = tolower(tempName[j]);
        }

        if (strcmp(tempName, searchName) == 0)
        {
            printf("\n�ǥ͸�ơG\n");
            printf("�m�W�G%s\n", students[i].name);
            printf("�Ǹ��G%d\n", students[i].id);
            printf("�ƾǦ��Z�G%d\n", students[i].math);
            printf("���z���Z�G%d\n", students[i].physics);
            printf("�^�妨�Z�G%d\n", students[i].english);
            printf("�������Z�G%.1f\n", students[i].average);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\n��Ƥ��s�b�C\n");
    }

    printf("\n�Ы��U���@��H��^�D���...");
    getch(); // ���ݥΤ����
}

// ���Z�ƦW�����
void gradeRanking(Student students[], int n)
{
    clearScreen();

    // �ϥΪw�j�ƧǪk�ƧǦ��Z
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

    printf("���Z�ƦW�A�Ѱ���C�G\n\n");
    printf("�ǥͩm�W\t�Ǹ�\t�������Z\n");
    printf("--------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t%.1f\n", students[i].name, students[i].id, students[i].average);
    }

    printf("\n�Ы��U���@��H��^�D���...");
    getch(); // ���ݥΤ����
}

// �T�{���}�����
void exitConfirmation()
{
    char choice;

    while (1)
    {
        printf("\n�T�w���}�H(Y/N)�A�����j�p�g�G");
        fflush(stdin);
        scanf("%c", &choice);
        choice = tolower(choice);

        if (choice == 'y')
        {
            printf("\n�{���Y�N�����C");
            exit(0);
        }
        else if (choice == 'n')
        {
            return;
        }
        else
        {
            printf("\n�L�Ŀﶵ�A�п�J Y �� N�A�����j�p�g�C\n");
        }
    }
}

/*
�K�X�ˬd�\��O�t�Φw�����Ĥ@�D���u�C�o�����n�D�Τ�b�T�����դ���J���T���K�X�A
�_�h�{���N�۰ʰh�X�C�o�ӥ\�ണ�ɤF�t�Ϊ��w���ʡA���ڲ`�J�z�Ѧr�����M�j�鱱��ϥΡC

�b�����ܩM��ܹL�{���A�ϥ�switch�y�y�ӹ�{���P�ﶵ���B�z�A
���{�����c²��B������@�M�X�i�C�o�������ڧ���x�зǿ�J��X��ƪ��ϥΩM���ɥΤᤶ���]�p����O�C

�ϥε��c��޲z�ǥ͸�ơA����Ʋ�´��[������ǡC�ϥΰ}�C�x�s�h����ơA
�ðʺA�ˬd��ƬO�_���ġC�o�������ڲ`����|�쵲�c��b��ƺ޲z�����@�ΡA
�ô��ɤF���Ƶ��c���z�ѡC

��ܾǥͦ��Z�M�j�M�ǥ͸�ƬO�t�Ϊ��֤ߥ\�ध�@�C�q�L�o�ǥ\��A�ھǷ|�b��Ƶ��c���i��ֳt�j�M�A
�ñN���G��ܵ��Τ�C�j�M�\�त�A��{�^�夣���j�p�g���j�M�A�n���Τ�ާ@��[�F���C

���Z�ƦW�\�ೡ���A�Ϊw�j�ƧǪk��{�A�ھڥ������Z��ǥͶi��ƧǩM��ܡC
�o�������ڲz�ѱƧǺt��k���򥻭�z�M��@��k�A�z�Ѹ�ƱƧǦb������Τ������n�ʡC

�T�{�h�X�\��A�z�L���ܥΤ�T�{�O�_���}�A�ϵ{����[�͵��C�o�����з|�ڦp��B�z�h���Τ��J�A
�îھڿ�J���G��������ާ@�C

�`���A�}�o�o�Ӿǥͦ��Z�޲z�t�Ϊ��L�{�O�@�ӫD�`�_�Q���ǲ߸g���A�d�T�F�ڹ��C�y������¦���ѡA
���ɹ�ڰ��D�ѨM��O�M�{���]�p�ޥ��C�z�L�ҲդƳ]�p�A�ϵ{�����c�M���B������@�M�X�i�C
*/