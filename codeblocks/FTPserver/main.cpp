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
    // Create my object
    CFtpServer *m_pFtpServer = new CFtpServer;

    //
    if(m_pFtpServer->startServer(argc, argv) != 0)
    {
        std::cout << "startServer fail!" << std::endl;
    }

    //
    m_pFtpServer->debugVariable();

    // Destroy object
    delete m_pFtpServer;
    return 0;
}
