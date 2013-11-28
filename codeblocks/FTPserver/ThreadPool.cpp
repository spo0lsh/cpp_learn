#include "ThreadPool.h"

CThreadPool::CThreadPool()
{

}

CThreadPool::~CThreadPool()
{

}

int CThreadPool::initThreadPool(int maxPoolSize, std::string dbFile)
{
    int exit_status=0;

    // setpoolsize
    this->setPoolSize(maxPoolSize);

    // create queue
    this->createQueue(mp_Queue);

    // create database
    CDatabaseOperations *m_pDatabaseOperations = new CDatabaseOperations;
    mp_DB=m_pDatabaseOperations->createDatabaseStructure(dbFile);
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

int CThreadPool::createQueue(std::vector <SOCKET>* mp_Queue)
{
    std::cout << "CThreadPool::createQueue " << std::endl;
    this->mp_Queue = new std::vector <SOCKET>();
    return 0;
}

int CThreadPool::setPoolSize(int maxPoolSize)
{
    this->poolSize=maxPoolSize;
    return 0;
}
