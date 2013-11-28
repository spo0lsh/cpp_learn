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
