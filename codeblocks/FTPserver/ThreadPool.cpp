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
    for(int i=0;i<poolSize;++i)
    {
        std::cout << "CThreadPool::initThreadPool addThread()" << std::endl;

    }

// tmp
	HANDLE hThreadHandler = 0;
	unsigned int uiThreadID = 0;
	for (int i = 0; i < poolSize; i++)
	{
		CClientThread newThread;
		this->m_vThreads.push_back( newThread);
	}
	for(int i = 0; i < poolSize; i++)
	{
		hThreadHandler = (HANDLE)_beginthreadex( NULL, 0, CClientThread::mainThread, (void*)&this->m_vThreads[i], CREATE_SUSPENDED, &uiThreadID);
//		hThreadHandler = (HANDLE)_beginthreadex( NULL, 0, CClientThread::mainThread, (void*)&this->m_vThreads[i], 0, &uiThreadID);
	}
// end tmp


    return exit_status;
}

int CThreadPool::addThread()
{
    int exit_status=0;

	HANDLE hThreadHandler = 0;
	unsigned int uiThreadID = 0;
	for (int i = 0; i < poolSize; i++)
	{
		CClientThread newThread;
		this->m_vThreads.push_back( newThread);
	}
	for(int i = 0; i < poolSize; i++)
	{
		hThreadHandler = (HANDLE)_beginthreadex( NULL, 0, CClientThread::mainThread, (void*)&this->m_vThreads[i], CREATE_SUSPENDED, &uiThreadID);
//		hThreadHandler = (HANDLE)_beginthreadex( NULL, 0, CClientThread::staticThreadFunction, (void*)&this->m_vThreads[i], CREATE_SUSPENDED, &uiThreadID);
	}

    return exit_status;
}

int CThreadPool::createQueue(std::vector <SOCKET>* a_Queue)
{
    std::cout << "CThreadPool::createQueue " << std::endl;
    this->mp_Queue = new std::vector <SOCKET>();
    return 0;
}

int CThreadPool::setPoolSize(int a_maxPoolSize)
{
    this->poolSize=a_maxPoolSize;
    return 0;
}
