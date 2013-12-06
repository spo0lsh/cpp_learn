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
	while(1)
    {
        std::cout << "CClientThread::mainThread ID: " << pThis->getThreadID() << std::endl;
        //get task from queue

        /// IN LOOP?
        // reading socket

        // parsing

        // executing

        /// END LOOP?
        //

//        m_pDatabaseOperations->debugPrint(pThis->mp_DB);

//        pThis->debugPrint(pThis->mp_DB); // database works

        //going to sleep
        pThis->setThreadState(0);
        SuspendThread(GetCurrentThread());
    }
//    delete m_pDatabaseOperations; // need?!
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

void CClientThread::getTaskFromQueue(SOCKET *a_sClientSocket)
{
    std::cout << "CClientThread::getTaskFromQueue" << std::endl;
    this->m_sClientSocket = a_sClientSocket;
//    return this->vector.pop_back();
}

void CClientThread::writeDB(std::vector <std::vector<std::string> > *a_pvDB)
{
    this->mp_DB = a_pvDB;
}

//void CClientThread::debugPrint(std::vector <std::vector<std::string> > *a_DB)
//{
//    std::cout << "CClientThread::debugPrintt DB size: " << (*a_DB).size() << std::endl;
//    unsigned int i;
//    for(i=0; i<(*a_DB).size(); ++i)
//    {
//        std::cout << "CClientThread::debugPrint User " << " " << (*a_DB)[i][0] << " password " << (*a_DB)[i][1] << std::endl;
//    }
//}
