#ifndef CLIENTTHREAD_H_INCLUDED
#define CLIENTTHREAD_H_INCLUDED

#include <iostream>
#include <winsock2.h>
#include <process.h>

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

    friend class CThreadPool;


private:
    HANDLE m_hThreadHandle;
	unsigned int m_uiThreadID;
};

#endif // CLIENTTHREAD_H_INCLUDED
