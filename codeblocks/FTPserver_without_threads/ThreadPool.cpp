#include "ThreadPool.h"

CThreadPool::CThreadPool()
{

}

CThreadPool::~CThreadPool()
{

}

int CThreadPool::initThreadPool(int a_maxPoolSize, std::string a_dbFile)
{
    int exit_status=0;

    // setpoolsize
    this->setPoolSize(a_maxPoolSize);

    // create queue
    this->createQueue(mp_Queue);

    // create database
    CDatabaseOperations *m_pDatabaseOperations = new CDatabaseOperations;
    mp_DB=m_pDatabaseOperations->createDatabaseStructure(a_dbFile);
    if(mp_DB == 0)
    {
        exit_status=1;
    }
    std::cout << "CThreadPool::initThreadPool m_pDatabaseOperations->createDatabaseStructure status: " << exit_status << std::endl;
    delete m_pDatabaseOperations; // need?!

    // addThread

//	for (int i = 0; i < poolSize; i++)
//	{
//		CClientThread newThread;
//		this->m_vThreads.push_back( newThread);
//		this->addThread(i);
//	}

    return exit_status;
}

//int CThreadPool::addThread(int i)
//{
//    int exit_status=0;
////    std::cout << "CThreadPool::addThread: " << i << std::endl;
//
//	HANDLE hThreadHandler = 0;
//	unsigned int uiThreadID = 0;
//	hThreadHandler = (HANDLE)_beginthreadex( NULL, 0, CClientThread::mainThread, (void*)&this->m_vThreads[i], CREATE_SUSPENDED, &uiThreadID);
////	hThreadHandler = (HANDLE)_beginthreadex( NULL, 0, CClientThread::mainThread, (void*)&this->m_vThreads[i], 0, &uiThreadID);
//	this->m_vThreads[i].setHandle(hThreadHandler);
//	this->m_vThreads[i].setThreadID(uiThreadID);
//	this->m_vThreads[i].writeDB(this->mp_DB);
//	this->m_vThreads[i].setThreadState(0);
//    std::cout << "CThreadPool::addThread: " << m_vThreads[i].getHandle() << " ID: " << m_vThreads[i].getThreadID() << " Address: " << (void*)&this->m_vThreads[i] << " State: " << m_vThreads[i].getThreadState() << std::endl;
//    return exit_status;
//}

int CThreadPool::createQueue(std::vector <SOCKET>* a_Queue)
{
    std::cout << "CThreadPool::createQueue " << std::endl;
    this->mp_Queue = new std::vector <SOCKET>();
    return 0;
}

int CThreadPool::addTaskToQueue(SOCKET a_Socket)
{
    int exit_status=0;
//    std::cout << "CThreadPool::addTaskToQueue: size: " << this->mp_Queue->size() << std::endl;
    if(this->mp_Queue->size() < this->poolSize)
    {
        this->mp_Queue->push_back(a_Socket);
        std::cout << "CThreadPool::addTaskToQueue: OK size: " << this->mp_Queue->size() << std::endl;
    }
    else
    {
        std::cout << "CThreadPool::addTaskToQueue: KO size: " << this->mp_Queue->size() << std::endl;
        exit_status=1;
    }
    return exit_status;
}

int CThreadPool::setPoolSize(int a_maxPoolSize)
{
    this->poolSize=a_maxPoolSize;
    this->maxPoolSize=a_maxPoolSize;
    return 0;
}

int CThreadPool::findFreeThread()
{
    SOCKET clientSocket;
    std::cout << "CThreadPool::findFreeThread" << std::endl;
//	for (int i = 0; i < poolSize; i++)
//	{
//        if(this->m_vThreads[i].getThreadState() != 0)
//        {
//            std::cout << "CThreadPool::findFreeThread getThreadState(): " << this->m_vThreads[i].getThreadState() << std::endl;
//        }
//        else
//        {
//            std::cout << "CThreadPool::findFreeThread getThreadState(): " << this->m_vThreads[i].getThreadState() << std::endl;
//            this->m_vThreads[i].setThreadState(1);
            clientSocket=(*mp_Queue)[this->mp_Queue->size() - 1];
            m_poClientThread->getTaskFromQueue(clientSocket);
            m_poClientThread->mainThread((void*)&m_poClientThread);
//            this->m_vThreads[i].getTaskFromQueue(clientSocket);
//            this->mp_Queue->pop_back();
//            ResumeThread(this->m_vThreads[i].getHandle());
//            break;
//        }
//	}
	std::cout << "CThreadPool::findFreeThread after if" << std::endl;
    return 0;
}
