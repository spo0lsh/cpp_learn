#include <iostream>
#include "main.h"

using namespace std;
int main(int argc, char *argv[])
{
    int exit_status;
    exit_status=0;

    CFtpClient oFtpClient;
    if(oFtpClient.checkRequireOptions(argc, argv) != 0)
    {
        exit_status=1;
        std::cout << "main: oFtpClient.checkRequireOptions: " << exit_status << std::endl;
    }
    else
    {
        std::cout << "main: oFtpClient.checkRequireOptions: " << exit_status << std::endl;
        oFtpClient.parsingOptionsForCommand(argc, argv);
    }

    return exit_status;
}
