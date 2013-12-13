#include "ExecuteCommand.h"

CExecuteCommand::CExecuteCommand()
{
    this->setLoginStatus(1);
    this->setPort(5150);
}

CExecuteCommand::~CExecuteCommand()
{

}

void CExecuteCommand::showFilesOnServer()
{
    std::cout << "CExecuteCommand::showFilesOnServer" << std::endl;
}

void CExecuteCommand::deleteFileOnServer(char *a_filename)
{
    std::cout << "CExecuteCommand::deleteFileOnServer: " << std::endl;
}

void CExecuteCommand::putFileToServer(char *a_filename)
{
    std::cout << "CExecuteCommand::putFileToServer: " << std::endl;
}

void CExecuteCommand::getFileFromServer(char *a_filename)
{
    std::cout << "CExecuteCommand::getFileFromServer: " << std::endl;
}

void CExecuteCommand::getFileSizeFromServer(std::string a_filename)
{
    if(this->getLoginStatus() != 0)
    {
        std::cout << "CExecuteCommand::getFileSizeFromServer: not logged" << std::endl;
    }
    else
    {
        std::cout << "CExecuteCommand::getFileSizeFromServer: " << a_filename << std::endl;
        oSocketInputOutput.writeToSocket("SIZE " + a_filename);
        if(oSocketInputOutput.readFromSocket() > 0)
        {
            std::cout << "CExecuteCommand::connectToServer.readFromSocket(): " << oSocketInputOutput.sBuffer << std::endl;
//            if(strcmp("OK",oSocketInputOutput.sBuffer) != 0)
//            {
//                exit_status=1;
//            }
//            else
//            {
//
//            }
        }
    }
}

void CExecuteCommand::setLogin(char *a_login)
{
    this->login=a_login;
    std::cout << "CExecuteCommand::setLogin: " << this->login << std::endl;
}

void CExecuteCommand::setPassword(char *a_password)
{
    this->password=a_password;
    std::cout << "CExecuteCommand::setPassword: " << this->password << std::endl;
}

void CExecuteCommand::setHost(char *a_host)
{
    this->host=a_host;
    std::cout << "CExecuteCommand::setHost: " << this->host << std::endl;
}

void CExecuteCommand::setPort(int a_port)
{
    this->port=a_port;
    std::cout << "CExecuteCommand::setPort: " << this->port << std::endl;
}

void CExecuteCommand::setLoginStatus(int a_status)
{
    this->loginStatus=a_status;
    std::cout << "CExecuteCommand::setLoginStatus: " << this->loginStatus << std::endl;
}

int CExecuteCommand::getLoginStatus()
{
    std::cout << "CExecuteCommand::getLoginStatus: " << this->loginStatus << std::endl;
    return this->loginStatus;
}

int CExecuteCommand::connectToServer()
{
    int exit_status=0;
    std::cout << "CExecuteCommand::connectToServer: " << exit_status << std::endl;
    oSocketInputOutput.openSocket(&this->host[0], this->port);
    oSocketInputOutput.writeToSocket("USER " + this->login);
    if(oSocketInputOutput.readFromSocket() > 0)
    {
        std::cout << "CExecuteCommand::connectToServer.readFromSocket(): " << oSocketInputOutput.sBuffer << std::endl;
        if(strcmp("OK",oSocketInputOutput.sBuffer) != 0)
        {
            exit_status=1;
        }
        else
        {

        }
    }
    else
    {
        exit_status=1;
    }
    if(exit_status !=1)
    {
        oSocketInputOutput.writeToSocket("PASS " + this->password);
    }
    if(oSocketInputOutput.readFromSocket() > 0)
    {
        std::cout << "CExecuteCommand::connectToServer.readFromSocket(): " << oSocketInputOutput.sBuffer << std::endl;
        if(strcmp("OK",oSocketInputOutput.sBuffer) != 0)
        {
            exit_status=1;
        }
        else
        {
            this->setLoginStatus(0);
        }
    }
    else
    {
        exit_status=1;
    }
    return exit_status;
}

void CExecuteCommand::disconnectFromServer()
{
    std::cout << "CExecuteCommand::disconnectFromServer: " << std::endl;
}
