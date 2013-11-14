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
        cout << "threadMain(): " << *(int *) args << " GetCurrentThread(): " << GetCurrentThread << endl; // casting for int;
        SuspendThread(GetCurrentThread());
    }
    return 0;
}

static unsigned __stdcall threadMain2(void* msg) // print text
{
    while(1)
    {
        std::string str = *reinterpret_cast<std::string*>(msg);
        cout << "threadMain2(): " << str << " GetCurrentThread(): " << GetCurrentThread << endl; // casting for int;
        SuspendThread(GetCurrentThread());
    }
    return 0;
}

int main()
{
    string Text = "test";
    int i;
    HANDLE h_thread;
    //h_thread = (HANDLE)_beginthreadex(NULL, 0, threadMain, &i, CREATE_SUSPENDED, NULL);
    h_thread = (HANDLE)_beginthreadex(NULL, 0, threadMain2, &Text, CREATE_SUSPENDED, NULL);
    i = 10;
    DWORD res = ResumeThread(h_thread);
    //cout << "res = " << res << endl;
    DWORD res2 = WaitForSingleObject( h_thread, 5000 );

    return 0;
}
