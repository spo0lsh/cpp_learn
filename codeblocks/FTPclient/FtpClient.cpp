#include "FtpClient.h"

CFtpClient::CFtpClient()
{

}

CFtpClient::~CFtpClient()
{

}

int CFtpClient::checkRequireOptions(int argc, char *argv[])
{
    int exit_status=0;
    int i=0;
    std::string arg;
    int needed=0;
    for(i = 1; i < argc; i++)
    {
        arg = argv[i];
        if (arg == "login")
        {
            if(argv[i+1] != 0)
            {
                std::cout << "login: " << argv[i+1] << std::endl;
                needed=needed+4;
            }
        }
        else if (arg == "pass")
        {
            if(argv[i+1] != 0)
            {
                std::cout << "pass: " << argv[i+1] << std::endl;
                needed=needed+2;
            }
        }
        else if (arg == "host")
        {
            if(argv[i+1] != 0)
            {
                std::cout << "host: " << argv[i+1] << std::endl;
                needed=needed+1;
            }
        }
        else
        {
        }
    }
    if(needed != 7)
    {
        std::cout << "Need login, pass and host" << std::endl;
        std::cout << "Example" << argv[0] << " login your_login pass your_password host server_host" << std::endl;
        exit_status=1;
    }
    else
    {
        exit_status=0;
    }
    return exit_status;
}

int CFtpClient::parsingOptionsForCommand(int argc, char *argv[])
{
    int exit_status=0;
    int found=0;
    std::string arg;
    int i;
    for(i = 1; i < argc; i++)
        {
            arg = argv[i];
            if (arg == "dir")
            {
                std::cout << "CFtpClient::parsingOptionsForCommand: ";
                std::cout << "dir" << std::endl;
                oExecuteCommand.showFilesOnServer();
//                CgetCommandFromArgv::executeCommand("dir","");
                found=0;
            }
            else if (arg == "del")
            {
                if(argv[i+1] != 0)
                {
                    std::cout << "CFtpClient::parsingOptionsForCommand: ";
                    std::cout << "del: " << argv[i+1] << std::endl;
                    oExecuteCommand.deleteFileOnServer(argv[i+1]);
                }
                else
                {
                    std::cout << "CFtpClient::parsingOptionsForCommand: ";
                    std::cout << "del: wrong parameter, skipping" << std::endl;
                }
                found=1;
            }
            else if (arg == "put")
            {
                if(argv[i+1] != 0)
                {
                    std::cout << "CFtpClient::parsingOptionsForCommand: ";
                    std::cout << "put: " << argv[i+1] << std::endl;
                    oExecuteCommand.putFileToServer(argv[i+1]);
                }
                else
                {
                    std::cout << "CFtpClient::parsingOptionsForCommand: ";
                    std::cout << "put: wrong parameter, skipping" << std::endl;
                }
                found=1;
            }
            else if (arg == "size")
            {
                if(argv[i+1] != 0)
                {
                    std::cout << "CFtpClient::parsingOptionsForCommand: ";
                    std::cout << "size: " << argv[i+1] << std::endl;
                    oExecuteCommand.getFileSizeFromServer(argv[i+1]);
                }
                else
                {
                    std::cout << "CFtpClient::parsingOptionsForCommand: ";
                    std::cout << "put: wrong parameter, skipping" << std::endl;
                }
                found=1;
            }
            else if (arg == "get")
            {
                if(argv[i+1] != 0)
                {
                    std::cout << "CFtpClient::parsingOptionsForCommand: ";
                    std::cout << "get: " << argv[i+1] << std::endl;
                    oExecuteCommand.getFileFromServer(argv[i+1]);
                }
                else
                {
                    std::cout << "CFtpClient::parsingOptionsForCommand: ";
                    std::cout << "get: wrong parameter, skipping" <<std::endl;
                }
                found=1;
            }
            else if (arg == "login")
            {
                std::cout << "CFtpClient::parsingOptionsForCommand: ";
                std::cout << "login " << argv[i+1] << std::endl;
                oExecuteCommand.setLogin(argv[i+1]);
                found=1;
            }
            else if (arg == "pass")
            {
                std::cout << "CFtpClient::parsingOptionsForCommand: ";
                std::cout << "pass " << argv[i+1] << std::endl;
                oExecuteCommand.setPassword(argv[i+1]);
                found=1;
            }
            else if (arg == "host")
            {
                std::cout << "CFtpClient::parsingOptionsForCommand: ";
                std::cout << "host " << argv[i+1] << std::endl;
                oExecuteCommand.setHost(argv[i+1]);
                found=1;
            }
            else if (arg == "port")
            {
                std::cout << "CFtpClient::parsingOptionsForCommand: ";
                std::cout << "port " << argv[i+1] << std::endl;
                oExecuteCommand.setPort(atoi(argv[i+1]));
                found=1;
            }
            else
            {
                std::cout << "Unknow argument: " << arg <<  " ";
                std::cout << std::endl;
                found=0;
            }
            i=i+found;
        }
    return exit_status;
}

int CFtpClient::executeCommand(std::string, std::string )
{
    return 0;
}
