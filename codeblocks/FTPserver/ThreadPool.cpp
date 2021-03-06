#include "ThreadPool.h"

CThreadPool::CThreadPool()
{
    // probably never use
//    poolSize=4;
//    std::cout << "CThreadPool::CThreadPool(): " << poolSize << std::endl;
//	HANDLE hThreadHandler = 0;
//	unsigned int uiThreadID = 0;
//	for (int i = 0; i < poolSize; i++)
//	{
//		CClientThread newThread;
//		this->m_vThreads.push_back( newThread);
//	}
//	for(int i = 0; i < poolSize; i++)
//	{
//		hThreadHandler = (HANDLE)_beginthreadex( NULL, 0, CClientThread::mainThread, (void*)&this->m_vThreads[i], CREATE_SUSPENDED, &uiThreadID);
//		this->m_vThreads[i].setHandle( hThreadHandler);
//		this->m_vThreads[i].setThreadID( uiThreadID);
//		this->m_vThreads[i].setThreadState(0);
//        std::cout << "CThreadPool::addThread: " << m_vThreads[i].getHandle() << " ID: " << m_vThreads[i].getThreadID() << " Address: " << (void*)&this->m_vThreads[i] << " State: " << m_vThreads[i].getThreadState() << std::endl;
//	}
}

CThreadPool::CThreadPool(int &a_poolSize)
{
    int state=0;
    std::cout << "CThreadPool::CThreadPool(int ) " << a_poolSize << std::cout;
	HANDLE hThreadHandler = 0;
	unsigned int uiThreadID = 0;
	for (int i = 0; i < a_poolSize; ++i)
	{
		CClientThread newThread;
		this->m_vThreads.push_back( newThread);
	}
	for(int i = 0; i < a_poolSize; ++i)
	{
		hThreadHandler = (HANDLE)_beginthreadex( NULL, 0, CClientThread::mainThread, (void*)&this->m_vThreads[i], CREATE_SUSPENDED, &uiThreadID);
		this->m_vThreads[i].setHandle( hThreadHandler);
		this->m_vThreads[i].setThreadID( uiThreadID);
		this->m_vThreads[i].setThreadState(state);
        std::cout << "CThreadPool::addThread: " << m_vThreads[i].getHandle() << " ID: " << m_vThreads[i].getThreadID() << " Address: " << (void*)&this->m_vThreads[i] << " State: " << m_vThreads[i].getThreadState() << std::endl;
	}
}

CThreadPool::~CThreadPool()
{
    this->removeQueue();
}

int CThreadPool::initThreadPool(int &a_maxPoolSize, std::string &a_dbFile)
{
    int exit_status=0;

    // setpoolsize
//    this->setPoolSize(a_maxPoolSize);

    // create queue
    this->createQueue(mp_Queue);

    // create database
    CDatabaseOperations *poDatabaseOperations = new CDatabaseOperations;
    this->mp_DB=poDatabaseOperations->createDatabaseStructure(a_dbFile);
    if(this->mp_DB != 0)
    {
        // do nothing
    }
    else
    {
        exit_status=1;
    }
    std::cout << "CThreadPool::initThreadPool poDatabaseOperations->createDatabaseStructure status: " << exit_status << std::endl;
    delete poDatabaseOperations; // need?!

    return exit_status;
}

int CThreadPool::createQueue(std::vector <SOCKET>* a_Queue)
{
    std::cout << "CThreadPool::createQueue " << std::endl;
    // TODO: pessimistic version for return code
    this->mp_Queue = new std::vector <SOCKET>();
    return 0;
}

void CThreadPool::removeQueue()
{
    delete this->mp_Queue;
}

int CThreadPool::addTaskToQueue(SOCKET &a_Socket)
{
    int exit_status=0;
    //
//    if(this->mp_Queue->size() < (unsigned int)this->poolSize) //(unsigned int)
    if(this->checkFreeThread() == 0)
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

//int CThreadPool::setPoolSize(int &a_maxPoolSize)
//{
//    this->poolSize=a_maxPoolSize;
//    this->maxPoolSize=a_maxPoolSize;
//    return 0;
//}

int CThreadPool::checkFreeThread()
{
    int exit_status;
//    int iPoolSize = this->m_vThreads.size();
    for(unsigned int i=0; i<this->m_vThreads.size();++i)
    {
        if(this->m_vThreads[i].getThreadState() != 0)
        {
            std::cout << "CThreadPool::checkFreeThread not found." << std::endl;
            exit_status=1;
        }
        else
        {
            std::cout << "CThreadPool::checkFreeThread found." << std::endl;
            exit_status=0;
            break;
        }
    }
    return exit_status;
}

int CThreadPool::WakeUpFreeThread()
{
    std::cout << "CThreadPool::WakeUpFreeThread: " << this->m_vThreads.size() << std::endl;
    int iPoolSize = this->m_vThreads.size();
    int exit_status=0;
    for( int i = 0; i < iPoolSize; ++i)
    {
        if(this->m_vThreads[i].getThreadState() != 0)
        {
            std::cout << "CThreadPool::WakeUpFreeThread getThreadState(): " << this->m_vThreads[i].getThreadState() << " " << m_vThreads[i].getHandle() << std::endl;
            exit_status=1;
        }
        else
        {
            int state=1;
            std::cout << "CThreadPool::WakeUpFreeThread getThreadState(): " << this->m_vThreads[i].getThreadState() << " ID: " << m_vThreads[i].getThreadID() << " " << m_vThreads[i].getHandle() << std::endl;
            this->m_vThreads[i].setThreadState(state);
            this->m_vThreads[i].wakeUpThread(this->mp_Queue, this->mp_DB);
            exit_status=0;
            break;
        }
    }
    return exit_status;
}
