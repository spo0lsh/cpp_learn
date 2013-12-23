#include <iostream>
#include "main.h"
#include "FtpServer.h"


using namespace std;

int main(int argc, char *argv[])
{
    int exit_status;
    exit_status=0;

    // Create my object
    CFtpServer oFtpServer;

    //
    if(oFtpServer.startServer(argc, argv) != 0)
    {
        std::cout << "main: oFtpServer.startServer fail!" << std::endl;
        exit_status=1;
    }
    else
    {
        std::cout << "main: oFtpServer.startServer successfull!" << std::endl;
    }
    if(exit_status != 1)
    {
        while(1) // catch key for quit
        {
            oFtpServer.acceptConnection();
        }
    }
    return exit_status;
}
