#ifndef CLIENTTHREAD_H_INCLUDED
#define CLIENTTHREAD_H_INCLUDED

#include <iostream>

class CClientThread
{
public:
    CClientThread();
    ~CClientThread();
//    void mainThread();
    static unsigned int __stdcall staticThreadFunction( void *a_pvThis);
    static unsigned int __stdcall mainThread( void *);
    friend class CThreadPool;
};

#endif // CLIENTTHREAD_H_INCLUDED
