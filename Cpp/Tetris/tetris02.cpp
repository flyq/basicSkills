/*******************这版改进了界面出现的乱码等问题，还有消行等问题没有解决***************/



#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>

#include<iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define MAPW 12
#define MAPH 20

HANDLE handle;
int b[7][4][4] = { { { 1 }, { 1, 1, 1 } },
{ { 0, 2 }, { 2, 2, 2 } },
{ { 3, 3 }, { 0, 3, 3 } },
{ { 0, 0, 4 }, { 4, 4, 4 } },
{ { 0, 5, 5 }, { 5, 5 } },
{ { 6, 6, 6, 6 } },
{ { 7, 7 }, { 7, 7 } } };

WORD SQUARE_COLOR[7] = { FOREGROUND_RED | FOREGROUND_INTENSITY,
FOREGROUND_GREEN | FOREGROUND_INTENSITY,
FOREGROUND_BLUE | FOREGROUND_INTENSITY ,

FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY };

int map[MAPH ][MAPW] = { 0 };
int dx = 24;
int dy = 3;

void Init();
void Turn(int a[][4], int w, int h, int *x, int y);
bool IsAvailable(int a[], int x, int y, int w, int h);
void DrawBlocks(int a[], int w, int h, int x, int y, WORD wColors[], int nColors);
void ClearSquare(int a[], int w, int h, int x, int y);
void GameOver();
void DeleteLine(int m[][MAPW], int row);
BOOL textout(HANDLE hOutput, int x, int y, WORD wColors[], int nColors, LPTSTR lpszString);


//初始化函数void Init()的实现

void Init()
{
                handle = GetStdHandle( STD_OUTPUT_HANDLE);
                srand(time( NULL));
                 for (int i = 0; i < 20; i++)
                {
                                map[i][0] = -2;
                                map[i][11] = -2;
                }
                 for (int i = 0; i < 12; i++)
                {
                                map[0][i] = -1;
                                map[19][i] = -1;
                }
                map[0][0] = -3;
                map[0][11] = -3;
                map[19][0] = -3;
                map[19][11] = -3;


            
