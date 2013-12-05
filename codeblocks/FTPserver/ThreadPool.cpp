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
		this->m_vThreads[i].setHandle( hThreadHandler);
		this->m_vThreads[i].setThreadID( uiThreadID);
        std::cout << "CThreadPool::initThreadPool TMP: " << m_vThreads[i].getHandle() << " ID: " << m_vThreads[i].getThreadID() << " Address: " << (void*)&this->m_vThreads[i] << std::endl;
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
		std::cout << "CThreadPool | _beginthreadex | Handler: " << m_vThreads[i].getHandle() << " ID: " << m_vThreads[i].getThreadID() << " Address: " << (void*)&this->m_vThreads[i] << std::endl;
	}

    return exit_status;
}

int CThreadPool::createQueue(std::vector <SOCKET>* a_Queue)
{
    std::cout << "CThreadPool::createQueue " << std::endl;
    this->mp_Queue = new std::vector <SOCKET>();
    return 0;
}

int CThreadPool::addTaskToQueue(SOCKET a_Socket)
{
    std::cout << "CThreadPool::addTaskToQueue" << std::endl;
    this->mp_Queue->push_back(a_Socket);
    return 0;
}

int CThreadPool::setPoolSize(int a_maxPoolSize)
{
    this->poolSize=a_maxPoolSize;
    return 0;
}

int CThreadPool::findFreeThread()
{
    std::cout << "CThreadPool::findFreeThread" << std::endl;
    return 0;
}
