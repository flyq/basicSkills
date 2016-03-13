/*
 *1st version
 */

#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>

//#pragma comment( lib, "opencv_highgui231d.lib")
//#pragma comment( lib, "opencv_core231d.lib")
/*
#include<gdi32.lib>
#include<wingdi.h>
*/
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


                 //初始化屏幕右边的信息显示区
                 WORD wColors[1] = { FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY };
                textout(handle, 26 + dx, 3 + dy, wColors, 1, "SCORE");
                textout(handle, 26 + dx, 7 + dy, wColors, 1, "LEVEL");
                textout(handle, 26 + dx, 11 + dy, wColors, 1, "NEXT");

                wColors[0] = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
                DrawBlocks(&map[0][0], 12, 20, 0, 0, wColors, 1);
                textout(handle, dx, dy, wColors, 1, "♦==========♦" );

                wColors[0] = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
                textout(handle, dx - 16, dy, wColors, 1, "按任意键开始" );
                 int ch = _getch();
                textout(handle, dx - 16, dy, wColors, 1, "            " );
}


//基本显示函数textout()的实现

BOOL textout(HANDLE hOutput, int x , int y, WORD wColors[], int nColors , LPTSTR lpszString)
{
                 DWORD cWritten;
                 COORD coord = { x , y };

                 //设置输出字符
                 BOOL fSuccess = WriteConsoleOutputCharacter (hOutput, lpszString, lstrlen (lpszString), coord, &cWritten);
                 if (!fSuccess)
                                cout << "error: WriteConsoleOutputCharacter" << endl;
                 for (; fSuccess && coord.X < lstrlen( lpszString) + x ; coord.X += nColors)
                {
                                 //设置每一个字符的属性
                                fSuccess = WriteConsoleOutputAttribute( hOutput, wColors , nColors, coord, &cWritten);
                }
                 if (!fSuccess)
                                cout << "error: WriteConsoleOutputAttribute" << endl;
                 return 0;
}


//显示方块和边界算法DrawBlocks()

void DrawBlocks(int a[], int w, int h, int x, int y, WORD wColors[], int nColors )
{
                 int temp;
                 for (int i = 0; i < h; i++)
                {
                                 for (int j = 0; j < w; j++)
                                {
                                                 if ((temp = a [i*w + j]) && y + i>0)
                                                {
                                                                 if (temp == -3)
                                                                                textout(handle, 2 * (x + j) + dx, y + i + dy, wColors, nColors, "♦");
                                                                 else if (temp == -2)
                                                                                textout(handle, 2 * (x + j) + dx, y + j + dy, wColors, nColors, "||");
                                                                 else if (temp == -1)
                                                                                textout(handle, 2 * (x + j) + dx, y + j + dy, wColors, nColors, "==");
                                                                 else if (temp >= 1)
                                                                                textout(handle, 2 * (x + j) + dx, y + i + dy, wColors, nColors, "■");
                                                }
                                }
                }
                
}

//擦除方块ClearSquare()的实现

void ClearSquare(int a[], int w, int h, int x, int y)
{
                 int nColors = 1;                                                      //有bug！！
                 WORD wColors[1] = { 0 };
                 for (int i = 0; i < h; i++)
                {
                                 for (int j = 0; j < w; j++)
                                {
                                                 if (a [i * w + j] > 0)
                                                                textout(handle, 2 * (x + j) + dx, y + i + dy, wColors, nColors, "  ");
                                }
                }
}

//旋转算法Turn()的实现

void Turn(int a[][4], int w , int h, int *x, int y)
{
                 int b[4][4] = { 0 };
                 int sign = 0;
                 int line = 0;
                 for (int i = h - 1; i >= 0; i--)
                {
                                 for (int j = 0; j < w; j++)
                                {
                                                 if (a [i][j])
                                                {
                                                                b[j][line] = a[i][j];
                                                                sign = 1;
                                                }
                                }
                                 if (sign)
                                {
                                                line++;
                                                sign = 0;
                                }
                }
                 for (int i = 0; i < 4; i++)
                {
                                 if (IsAvailable(b[0], *x - i, y, w, h))
                                {
                                                * x -= i;
                                                 for (int k = 0; k < h; k++)
                                                {
                                                                 for (int j = 0; j < w; j++)
                                                                {
                                                                                 a[k][j] = b[k][j];
                                                                }
                                                }
                                                 break;
                                }
                }
                
}

//判断方块是否可移动算法

bool IsAvailable(int a[], int x, int y, int w, int h)
{
                 for (int i = y; i < y + h ; i++)
                {
                                 for (int j = x; j < x + w ; j++)
                                {
                                                 if (map[i][j] && a [w*(i - y) + j - x ])
                                                                 return false ;
                                }
                }
                 return true ;
}

//方块满一行后消行 DeleteLine()的实现

void DeleteLine(int m[][MAPW], int row )
{
                 WORD wColors[1] = { FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY };
                textout(handle, 2 + dx, row + dy, wColors, 1, "========================" );
                Sleep (100);
                 for (int i = row; i > 1; i--)
                {
                                ClearSquare(& m[i][1], MAPW - 2, 1, 1, i);
                                 for (int j = 1; j < MAPW - 1; j++)
                                {
                                                 m[i][j] = m [i - 1][i];
                                                 if (m [i][j] == 0)
                                                                wColors[0] = 0;
                                                 else
                                                                wColors[0] = SQUARE_COLOR[m[i][j] - 1];
                                                DrawBlocks(& m[i][j], 1, 1, j, i, wColors, 1);
                                }
                }
                 for (int i = 1; i < MAPW - 1; i++)
                {
                                 m[1][i] = 0;
                }
}

//游戏结束GameOver()的实现

void GameOver()
{
                 WORD wColors[1] = { FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY };
                textout(handle, 7 + dx, 10 + dy, wColors, 1, "GAME OVER");
                exit( EXIT_SUCCESS);
}

//程序的主程序main()的实现
int main()
{
                Init();
                 int score = 0;
                 int level = 0;
                 int Num = rand() % 7;
                 int nextNum = Num;
                 int blank;
                 int x = 0;
                 int y = 0;
                 int a[4][4] = { 0 };
                 while (1)
                {
                                 for (int i = 0; i < 4; i++)
                                {
                                                 for (int j = 0; j < 4; j++)
                                                {
                                                                 if (a[i][j] = b[nextNum][i][j])
                                                                                blank = i;
                                                }
                                }

                                y = 1 - blank;
                                x = 4;

                                 //创建下一个方块
                                Num = nextNum;
                                ClearSquare(b[Num][0], 4, 4, 13, 13);
                                nextNum = rand() % 7;
                                 WORD wColors[1] = { SQUARE_COLOR[nextNum] };
                                DrawBlocks(b[nextNum][0], 4, 4, 13, 13, wColors, 1);

                                 //显示分数信息

                                 char string[5];
                                wColors[0] = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY ;
                                textout(handle, 26 + dx, 5 + dy, wColors, 1, _itoa(score, string, 10));
                                textout(handle, 26 + dx, 9 + dy, wColors, 1, _itoa(level, string, 10));
                                 int max_delay = 100 - 10 * level;

                                 while (1)
                                {
                                                 int delay = 0;
                                                 while (delay < max_delay)
                                                {
                                                                 if (_kbhit())
                                                                {
                                                                                 int key = _getch();
                                                                                 switch (key)
                                                                                {
                                                                                 case KEY_UP :{
                                                                                                                                                ClearSquare(&a[0][0], 4, 4, x, y);
                                                                                                                                                Turn(a, 4, 4, &x, y);
                                                                                                                                                wColors[0] = SQUARE_COLOR[Num];
                                                                                                                                                DrawBlocks(&a[0][0], 4, 4, x, y, wColors, 1);
                                                                                }
                                                                                                 break;
                                                                                 case KEY_DOWN :delay = max_delay;
                                                                                                 break;
                                                                                 case KEY_LEFT :{
                                                                                                                                                  if (IsAvailable(&a[0][0], x - 1, y, 4, 4))
                                                                                                                                                  {
                                                                                                                                                                  ClearSquare(&a[0][0], 4, 4, x, y);
                                                                                                                                                                  x--;
                                                                                                                                                                  wColors[0] = SQUARE_COLOR[Num];
                                                                                                                                                                  DrawBlocks(&a[0][0], 4, 4, x, y, wColors, 1);
                                                                                                                                                  }
                                                                                }
                                                                                                 break;
                                                                                 case KEY_RIGHT :{
                                                                                                                                                   if (IsAvailable(&a[0][0], x + 1, y, 4, 4))
                                                                                                                                                   {
                                                                                                                                                                   ClearSquare(&a[0][0], 4, 4, x, y);
                                                                                                                                                                   x++;
                                                                                                                                                                   wColors[0] = SQUARE_COLOR[Num];
                                                                                                                                                                   DrawBlocks(&a[0][0], 4, 4, x, y, wColors, 1);
                                                                                                                                                   }
                                                                                }
                                                                                                 break;
                                                                                 case KEY_ESC : exit(EXIT_SUCCESS);
                                                                                                 break;
                                                                                }
                                                                }
                                                                Sleep(8);
                                                                delay++;
                                                }
                                                 if (IsAvailable(&a[0][0], x, y + 1, 4, 4))
                                                {
                                                                ClearSquare(&a[0][0], 4, 4, x, y);
                                                                y++;
                                                                wColors[0] = SQUARE_COLOR[Num];
                                                                DrawBlocks(&a[0][0], 4, 4, x, y, wColors, 1);
                                                }
                                                 else
                                                {
                                                                 if (y <= 1)
                                                                                GameOver();
                                                                 for (int i = 0; i < 4; i++)
                                                                {
                                                                                 for (int j = 0; j < 4; j++)
                                                                                {
                                                                                                 if (a[i][j] && ((i + y) < MAPH - 1) && ((j + x) < MAPW - 1))
                                                                                                                map[i + y][j + x] = a[i][j];
                                                                                }
                                                                }
                                                                 int full, k = 0;
                                                                 for (int i = y; i < min(y + 4, MAPH - 1);i++)
                                                                {
                                                                                full = 1;
                                                                                 for (int j = 1; j < 11; j++)
                                                                                                 if (!map[i][j]) full = 0;
                                                                                
                                                                                 if (full)
                                                                                {
                                                                                                DeleteLine(map, i);
                                                                                                k++;
                                                                                                score = score + k;
                                                                                                level = min(score / 30, 9);
                                                                                                max_delay = 100 - 10 * level;
                                                                                }
                                                                }
                                                                 break;
                                                }
                                }
                }
                 return EXIT_SUCCESS ;
}
