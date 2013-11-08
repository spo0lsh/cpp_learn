#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;


DWORD WINAPI watek_1(PVOID pvParam)
{
     cout << "To jest watek numer 1\n";
     return 0;
}


DWORD WINAPI watek_2(PVOID pvParam)
{
     cout << "To jest watek numer 2\n";
     return 0;
}


int main()
{
   HANDLE proces = GetCurrentProcess();
   SetPriorityClass(proces, ABOVE_NORMAL_PRIORITY_CLASS);

   DWORD watek1;
   HANDLE hWatek_1 = CreateThread(NULL, 0, watek_1, NULL, 0, &watek1);

   SuspendThread(hWatek_1);
        SetThreadPriority(hWatek_1, THREAD_PRIORITY_NORMAL); //10
   ResumeThread(hWatek_1);


   DWORD watek2;
   HANDLE hWatek_2 = CreateThread(NULL, 0, watek_2, NULL, 0, &watek2);
   SuspendThread(hWatek_2);
        SetThreadPriority(hWatek_2, THREAD_PRIORITY_TIME_CRITICAL);  //15
   ResumeThread(hWatek_2);

   HANDLE watek_glowny = GetCurrentThread();
   SetThreadPriority(watek_glowny, THREAD_PRIORITY_LOWEST);

   cout << "To jest watek glowny\n";

   getch();

   return 0;

}
