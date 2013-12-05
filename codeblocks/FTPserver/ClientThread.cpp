#include "ClientThread.h"

CClientThread::CClientThread()
{

}

CClientThread::~CClientThread()
{

}

unsigned int __stdcall CClientThread::mainThread( void* a_pvThis)
{
	CClientThread *pThis = (CClientThread*)a_pvThis;
	while(1)
    {
        std::cout << "CClientThread::mainThread ID: " << pThis->getThreadID() << std::endl;
        //get task from queue

        /// IN LOOP?
        // reading socket

        // parsing

        // executing

        /// END LOOP?

        //going to sleep
        pThis->setThreadState(0);
        SuspendThread(GetCurrentThread());
    }
	return 0;
}

unsigned int CClientThread::getThreadID()
{
	return this->m_uiThreadID;
}

HANDLE CClientThread::getHandle()
{
	return this->m_hThreadHandle;
}

void CClientThread::setHandle( HANDLE a_Handle)
{
	this->m_hThreadHandle = a_Handle;
}

void CClientThread::setThreadID( unsigned int a_ThreadID)
{
	this->m_uiThreadID = a_ThreadID;
}

void CClientThread::setThreadState(int state)
{
    this->m_iThreadState = state;
}

int CClientThread::getThreadState()
{
    return this->m_iThreadState;
}

SOCKET CClientThread::getTaskFromQueue()
{
    std::cout << "CClientThread::getTaskFromQueue" << std::endl;
//    return this->vector.pop_back();
}
