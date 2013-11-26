#include "ThreadPool.h"

int CThreadPool::initThreadPool(int maxPoolSize)
{
    // database
    this->mpr_DB=m_pDatabaseOperations->createDatabaseStructure();
    // debug
    m_pDatabaseOperations->debugPrint(this->mpr_DB);

    delete m_pDatabaseOperations; // need?!

    return 0;
}
