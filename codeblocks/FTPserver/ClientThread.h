#ifndef CLIENTTHREAD_H_INCLUDED
#define CLIENTTHREAD_H_INCLUDED

#include <iostream>
#include <winsock2.h>
#include <process.h>
#include <vector>
#include <windows.h>

#include "DatabaseOperations.h"
#include "ExecuteCommand.h"

class CClientThread
{
public:
    CClientThread();
    ~CClientThread();
    static unsigned int __stdcall mainThread( void *);

    void setHandle( HANDLE a_Handle);
    void setThreadID( unsigned int a_ThreadID);
    unsigned int getThreadID();
    HANDLE getHandle();
    void setThreadState(int );
    int getThreadState();
    void getTaskFromQueue();
    void debugSocket();
    void wakeUpThread(std::vector <SOCKET>*,std::vector <std::vector<std::string> > * );
    void goSleep();

    int ReadFromSocket();
    void closeSocket();

    CExecuteCommand oExecuteCommand;


private:
    HANDLE m_hThreadHandle;
	unsigned int m_uiThreadID;
	int m_iThreadState;
	char sBuffer[2048];

    SOCKET m_sClientSocket;
	std::vector <std::vector<std::string> > *mp_DB;
	std::vector <SOCKET> *mp_Queue;

	static HANDLE m_QueueMutex;
};

#endif // CLIENTTHREAD_H_INCLUDED
