#include "ThreadPool.h"

int CThreadPool::initThreadPool(int maxPoolSize, std::string dbFile)
{
    int exit_status=0;

    // setpoolsize
    this->setPoolSize(maxPoolSize);

    // create queue
    this->createQueue();

    // create database
    CDatabaseOperations *m_pDatabaseOperations = new CDatabaseOperations;
    mpr_DB=m_pDatabaseOperations->createDatabaseStructure(dbFile);
    if(mpr_DB == 0)
    {
        exit_status=1;
    }
    std::cout << "CThreadPool::initThreadPool m_pDatabaseOperations->createDatabaseStructure status: " << exit_status << std::endl;
    delete m_pDatabaseOperations; // need?!

    // addThread


    return exit_status;
}

int CThreadPool::createQueue()
{
    std::cout << "CThreadPool::createQueue " << std::endl;

    return 0;
}

int CThreadPool::setPoolSize(int maxPoolSize)
{
    this->poolSize=maxPoolSize;
    return 0;
}
