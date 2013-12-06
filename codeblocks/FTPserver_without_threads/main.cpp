#include <iostream>
#include "main.h"
//#include "ClientThread.h"
//#include "DatabaseOperations.h"
//#include "ExecuteCommand.h"
//#include "FileInputOutput.h"
#include "FtpServer.h"
//#include "SocketInputOutput.h"
//#include "ThreadPool.h"

using namespace std;

int main(int argc, char *argv[])
{
    int exit_status;
    exit_status=0;

    // Create my object
    CFtpServer *m_pFtpServer = new CFtpServer;

    //
    if(m_pFtpServer->startServer(argc, argv) != 0)
    {
        std::cout << "main: m_pFtpServer->startServer fail!" << std::endl;
        exit_status=1;
    }
    else
    {
        std::cout << "main: m_pFtpServer->startServer successfull!" << std::endl;
        m_pFtpServer->debugVariable();
    }

    while(1)
    {
        m_pFtpServer->acceptConnection();
    }



    // Destroy object
    delete m_pFtpServer;
    return exit_status;
}
