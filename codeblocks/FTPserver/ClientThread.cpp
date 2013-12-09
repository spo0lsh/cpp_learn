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

//    CDatabaseOperations *m_pDatabaseOperations = new CDatabaseOperations;
//	while(1)
//    {
        std::cout << "CClientThread::mainThread ID: " << pThis->getThreadID() << std::endl;
        //get task from queue
//        pThis->getTaskFromQueue();

        /// IN LOOP?
        // reading socket
//        pThis->debugSocket();
        // parsing

        // executing

        /// END LOOP?
        //

        //going to sleep
//        pThis->setThreadState(0);
//        SuspendThread(GetCurrentThread());
//        pThis->goSleep();
//    }
//    delete m_pDatabaseOperations; // need?!
	return 0;
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
//    this->m_sClientSocket=(*mp_Queue)[this->mp_Queue->size() - 1];
//    this->mp_Queue->pop_back();
}

//void CClientThread::getTaskFromQueue(SOCKET a_sClientSocket)
//{
//    std::cout << "CClientThread::getTaskFromQueue" << std::endl;
//    this->m_sClientSocket = a_sClientSocket;
//
//
////    int ret;
////    char szBuffer[2048];
////    ret = recv(this->m_sClientSocket, szBuffer, 2048, 0);
////    if (ret == SOCKET_ERROR)
////    {
////    printf("recv() failed: %d\n", WSAGetLastError());
////
////    }
////    szBuffer[ret] = '\0';
////    printf("RECV [%d bytes]: '%s'\n", ret, szBuffer);
////    closesocket(this->m_sClientSocket);
//}

//void CClientThread::writeDB(std::vector <std::vector<std::string> > *a_pvDB)
//{
//    this->mp_DB = a_pvDB;
//}


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
    closesocket(m_sClientSocket);
}
