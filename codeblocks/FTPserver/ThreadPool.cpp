#include "ThreadPool.h"

int CThreadPool::initThreadPool(int maxPoolSize)
{
    // database
    CDatabaseOperations *m_pDatabaseOperations = new CDatabaseOperations;
    this->mpr_DB=m_pDatabaseOperations->createDatabaseStructure();
    // debug
    m_pDatabaseOperations->debugPrint(this->mpr_DB);

    delete m_pDatabaseOperations; // need?!

    return 0;
}
