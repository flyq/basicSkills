#include<Windows.h>

void main()
{
        HANDLE hOut;
       hOut = GetStdHandle( STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO bInfo;
       GetConsoleScreenBufferInfo(hOut, &bInfo);

        SetConsoleTitle("控制台窗口操作" );
        COORD size = { 80, 25 };
       SetConsoleScreenBufferSize(hOut, size);
        SMALL_RECT rc = { 10, 10, 80 - 1, 25 - 1 };
       SetConsoleWindowInfo(hOut, true, &rc);
       CloseHandle(hOut);

}
