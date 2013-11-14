#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <process.h>

#define MAX_THREADS 3

using namespace std;

static unsigned __stdcall threadMain(void *args)
{
    while(1)
    {
        cout << "threadMain(): " << *(int *) args << endl; // casting for int;
        SuspendThread(GetCurrentThread());
    }
    return 0;
}

int main()
{
    string Text = "test";
    int i;
    HANDLE h_thread;
    h_thread = (HANDLE)_beginthreadex(NULL, 0, threadMain, &i, CREATE_SUSPENDED, NULL);
    i = 10;
    ResumeThread(h_thread);
    WaitForSingleObject( h_thread, 5000 );
    i = 20;
    ResumeThread(h_thread);
    WaitForSingleObject( h_thread, 5000 );
    i = 30;
    ResumeThread(h_thread);
    WaitForSingleObject( h_thread, 5000 );
    i = 40;
    ResumeThread(h_thread);
    DWORD res = WaitForSingleObject(h_thread, 0);
    switch (res)
    {
        case WAIT_OBJECT_0:
            printf("The thread has finished\n");
            break;
        case WAIT_TIMEOUT:
            printf("The thread is still running\n");
            break;
        default:
            printf("Unknown error (shouldn't happen)\n");
            break;

    }
    return 0;
}
