#ifndef THREADPOOL_H_INCLUDED
#define THREADPOOL_H_INCLUDED

//#include <iostream>
//#include <string>
//#include <cstdlib>
//#include <fstream>
#include <vector>
//
//#include <winsock2.h>
//#include <windows.h>
//#include <process.h>
//
//#include "DatabaseOperations.h"
#include "ClientThread.h"

class CThreadPool
{
public:
    CThreadPool();
    CThreadPool(int &);
    ~CThreadPool();
//    int addThread(int );
//    int removeThread();
    int WakeUpFreeThread();
    int checkFreeThread();
    int setPoolSize(int &);
    int getPoolSize();
    int createQueue(std::vector <SOCKET>*);
    int addTaskToQueue(SOCKET &);
    void semaphoreUp();
    void semaphoreDown();
    int initThreadPool(int &, std::string &);

private:
    std::vector <std::vector<std::string> > *mp_DB;
    std::vector <SOCKET> *mp_Queue;
    int poolSize;
    int maxPoolSize;
	std::vector<CClientThread> m_vThreads;
};



#endif // THREADPOOL_H_INCLUDED
