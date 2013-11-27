#ifndef THREADPOOL_H_INCLUDED
#define THREADPOOL_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

#include "DatabaseOperations.h"
#include "ClientThread.h"

class CThreadPool
{
public:
    int addThread();
    int removeThread();
    void findFreeThread();
    int setPoolSize(int );
    int getPoolSize();
    int createQueue();
    //void addTaskToQueue();
    void semaphoreUp();
    void semaphoreDown();
    int initThreadPool(int , std::string);

//    CDatabaseOperations *m_pDatabaseOperations = new CDatabaseOperations;
private:
    std::vector <std::vector<std::string> > *mpr_DB;
    std::vector <std::string> *mp_Queue;
    int poolSize;
};



#endif // THREADPOOL_H_INCLUDED
