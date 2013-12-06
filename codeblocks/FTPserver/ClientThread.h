#ifndef CLIENTTHREAD_H_INCLUDED
#define CLIENTTHREAD_H_INCLUDED

#include <iostream>
#include <winsock2.h>
#include <process.h>
#include <vector>

#include "DatabaseOperations.h"

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
    void getTaskFromQueue(SOCKET );
    void debugSocket();
    void wakeUpThread(std::vector <SOCKET>*,std::vector <std::vector<std::string> > * );
    void goSleep();

//    void debugPrint(std::vector <std::vector<std::string> > *);

//    friend class CThreadPool;


private:
    HANDLE m_hThreadHandle;
	unsigned int m_uiThreadID;
	int m_iThreadState;

	std::vector <std::vector<std::string> > *mp_DB;
	std::vector <SOCKET> *mp_Queue;

//	SOCKET m_sClientSocket;
};

#endif // CLIENTTHREAD_H_INCLUDED
