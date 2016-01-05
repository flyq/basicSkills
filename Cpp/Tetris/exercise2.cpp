/*************************例题2-3、2-4都是2-2改编过来的****************/

例题     2-3、
#include<Windows.h>
unsigned long num_written = 0;

void main()
{
        HANDLE hOut;
       hOut = GetStdHandle( STD_OUTPUT_HANDLE);

        char* str = "Display a shadow Window!";
        WORD att0 = BACKGROUND_INTENSITY;
        WORD att1 = FOREGROUND_RED | FOREGROUND_GREEN
              | FOREGROUND_BLUE | FOREGROUND_INTENSITY
              | BACKGROUND_RED | BACKGROUND_BLUE ;
        COORD posShadow = { 9, 9 }, posText = { 8, 8 };
        for ( int i = 0; i < 5; i++)
       {
              FillConsoleOutputAttribute(hOut, att0, 30, posShadow, &num_written);
              FillConsoleOutputAttribute(hOut, att1, 30, posText, &num_written);
              posShadow.Y++;
              posText.Y++;
       }
       posText.X = 9;
       posText.Y = 10;



        char *sEmpty = "                        " ;
        while (1)
       {
               WriteConsoleOutputCharacter(hOut, str, strlen(str), posText, &num_written);
              Sleep(200);
               WriteConsoleOutputCharacter(hOut, sEmpty, strlen(sEmpty), posText, &num_written);
              Sleep(100);
       }



       CloseHandle(hOut);
}


例题     2-4、
必须是调试，并且单击，双击退出。

#include<Windows.h>
unsigned long num_written = 0;

void main()
{
        HANDLE hOut;
       hOut = GetStdHandle( STD_OUTPUT_HANDLE);

        char* str = "Display a shadow Window!";
        WORD att0 = BACKGROUND_INTENSITY;
        WORD att1 = FOREGROUND_RED | FOREGROUND_GREEN
              | FOREGROUND_BLUE | FOREGROUND_INTENSITY
              | BACKGROUND_RED | BACKGROUND_BLUE ;
        COORD posShadow = { 9, 9 }, posText = { 8, 8 };
        for ( int i = 0; i < 5; i++)
       {
              FillConsoleOutputAttribute(hOut, att0, 30, posShadow, &num_written);
              FillConsoleOutputAttribute(hOut, att1, 30, posText, &num_written);
              posShadow.Y++;
              posText.Y++;
       }
       posText.X = 9;
       posText.Y = 10;



        char *sEmpty = "                        " ;
        int len = strlen(str);
        while (1)
       {
               WriteConsoleOutputCharacter(hOut, str, len, posText, &num_written);
              Sleep(200);
               WriteConsoleOutputCharacter(hOut, sEmpty, len, posText, &num_written);
              posText.X++;
              len--;
               if (len == 0)
              {
                     posText.X = 9;
                     len = strlen(str);
              }
       }



       CloseHandle(hOut);
}






例题     2-5、
#include<Windows.h>
#include<stdio.h>

unsigned long num_written = 0;
void DispMousePos(COORD pos);

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);


void main()
{
       INPUT_RECORD mouseRec;
       DWORD state =0, res;
       COORD pos = { 0, 0 };
        while (1)
       {
              ReadConsoleInput(hIn, &mouseRec, 1, &res);

               if (mouseRec.EventType == MOUSE_EVENT)
              {
                      if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
                            break;
                     pos = mouseRec.Event.MouseEvent.dwMousePosition;
                     DispMousePos(pos);
                      if (mouseRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                           FillConsoleOutputCharacter(hOut, 'A', 1, pos, &num_written);
              }
       }
       pos.X = pos.Y = 0;
       SetConsoleCursorPosition(hOut, pos);
       CloseHandle(hOut);
       CloseHandle(hIn);
}

void DispMousePos(COORD pos)
{
       CONSOLE_SCREEN_BUFFER_INFO bInfo;
       GetConsoleScreenBufferInfo( hOut, &bInfo);
       COORD home = { 0, 24 };
       WORD att0 = BACKGROUND_INTENSITY;
       FillConsoleOutputAttribute(hOut, att0, bInfo.dwSize.X, home, &num_written);
       FillConsoleOutputCharacter(hOut, ' ', bInfo.dwSize.X, home, &num_written);
        char s[20];
       sprintf(s, "X = %2lu, Y = %2lu", pos.X, pos.Y);
       SetConsoleTextAttribute(hOut, att0);
       SetConsoleCursorPosition(hOut, home);
       WriteConsole(hOut, s, strlen(s), NULL, NULL);
       SetConsoleTextAttribute(hOut, bInfo.wAttributes);
       SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition);

}


  

