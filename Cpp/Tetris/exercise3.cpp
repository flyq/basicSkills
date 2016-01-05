例题2.6     编写一个具有1个子线程的多线程的程序

#include<iostream>
using namespace std;
#include<Windows.h>
DWORD WINAPI WriteThread(LPVOID lpParam);
CRITICAL_SECTION cs;
int testNumber;

void main()
{
                InitializeCriticalSection(&cs);
                 DWORD dwThreadId;
                 HANDLE hThread = CreateThread(NULL , 0, WriteThread, NULL, 0, &dwThreadId);
                 while (1)
                {
                                EnterCriticalSection(&cs);
                                cout << testNumber << endl;
                                LeaveCriticalSection(&cs);
                                Sleep(1000);
                }
}

DWORD WINAPI WriteThread(LPVOID lpParam)
{
                 while (1)
                {
                                EnterCriticalSection(&cs);
                                testNumber++;
                                LeaveCriticalSection(&cs);
                                Sleep(230);
                }
}
