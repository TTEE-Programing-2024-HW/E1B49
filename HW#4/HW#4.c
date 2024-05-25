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