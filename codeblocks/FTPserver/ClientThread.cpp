#include "ClientThread.h"

HANDLE CClientThread::m_QueueMutex = NULL;

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

        pThis->m_QueueMutex = CreateMutex( NULL, FALSE, NULL); // probably get return exit
        WaitForSingleObject(pThis->m_QueueMutex,INFINITE);
        pThis->getTaskFromQueue();
        ReleaseMutex(pThis->m_QueueMutex);
        pThis->oExecuteCommand.setLoginStatus(1);
        pThis->oExecuteCommand.m_sClientSocket = pThis->m_sClientSocket;
        pThis->oExecuteCommand.mp_DB = pThis->mp_DB;

        /// IN LOOP?
        // read
        while(pThis->ReadFromSocket() > 0)
        {
            std::cout << "CClientThread::mainThread: while(pThis->ReadFromSocket() login status: " << pThis->oExecuteCommand.getLoginStatus() << std::endl;
            pThis->oExecuteCommand.parseData(pThis->sBuffer);
            Sleep(2000); // for debug
        }
        /// END LOOP?
        // close socket
        std::cout << "CClientThread::mainThread: after while(pThis->ReadFromSocket() > 0)" << std::endl;
        pThis->oExecuteCommand.setLoginStatus(1);
        pThis->closeSocket();

        //going to sleep
        pThis->goSleep();
    }
	return 0;
}

int CClientThread::ReadFromSocket()
{
    int ret=0;
    ret=this->oExecuteCommand.m_opCSocketInputOutput->readFromSocket(m_sClientSocket);
    strcpy(this->sBuffer,this->oExecuteCommand.m_opCSocketInputOutput->sBuffer);
    std::cout << "CClientThread::ReadFromSocket: " << this->sBuffer << std::endl;
    return ret;
}

void CClientThread::closeSocket()
{
    std::cout << "CClientThread::closeSocket" << std::endl;
    closesocket(m_sClientSocket);
}

void CClientThread::goSleep()
{
    this->setThreadState(0);
    SuspendThread(GetCurrentThread());
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
    std::cout << "CClientThread::setThreadState " << this->getThreadID() << " to: " << state << std::endl;
    this->m_iThreadState = state;
}

int CClientThread::getThreadState()
{
    return this->m_iThreadState;
}

void CClientThread::wakeUpThread(std::vector <SOCKET>* a_Queue, std::vector <std::vector<std::string> > *mp_DB)
{
    std::cout << "CClientThread::wakeUp " << this->getThreadID() << std::endl;
    this->mp_Queue = a_Queue;
    this->mp_DB = mp_DB;
    ResumeThread(this->getHandle());
}

void CClientThread::getTaskFromQueue()
{
    std::cout << "CClientThread::getTaskFromQueue" << std::endl;
    std::cout << "CClientThread::getTaskFromQueue: queue size: " << mp_Queue->size() << std::endl;
    this->m_sClientSocket=(*mp_Queue)[this->mp_Queue->size() - 1];
    this->mp_Queue->pop_back();
}

void CClientThread::debugSocket()
{
    int ret;
    char szBuffer[2048];
    ret = recv(m_sClientSocket, szBuffer, 2048, 0);
    if (ret == SOCKET_ERROR)
    {
    printf("recv() failed: %d\n", WSAGetLastError());

    }
    szBuffer[ret] = '\0';
    printf("RECV [%d bytes]: '%s'\n", ret, szBuffer);
}
