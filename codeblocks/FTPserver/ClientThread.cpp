#include "ClientThread.h"

CClientThread::CClientThread()
{

}

CClientThread::~CClientThread()
{

}

unsigned int __stdcall CClientThread::staticThreadFunction( void* a_pvThis)
{
	CClientThread *pThis = (CClientThread*)a_pvThis;
	std::cout << "CClientThread::staticThreadFunction" << std::endl;
//	pThis->serviceTask();
	return 1;
}

unsigned int __stdcall CClientThread::mainThread( void* a_pvThis)
{
	CClientThread *pThis = (CClientThread*)a_pvThis;
	std::cout << "CClientThread::mainThread" << std::endl;
//	pThis->serviceTask();
	return 1;
}
