#include "ThreadPool.h"

int CThreadPool::initThreadPool(int maxPoolSize, std::string dbFile)
{
    int exit_status=0;
    // database
    CDatabaseOperations *m_pDatabaseOperations = new CDatabaseOperations;
    std::cout << "CThreadPool::initThreadPool: " << m_pDatabaseOperations->createDatabaseStructure(dbFile) << std::endl;
    if(m_pDatabaseOperations->createDatabaseStructure(dbFile) != 0)
    {
        exit_status=1;
    }
    delete m_pDatabaseOperations; // need?!
    return exit_status;
}
