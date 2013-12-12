#include "ExecuteCommand.h"

CExecuteCommand::CExecuteCommand()
{

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

void CExecuteCommand::getFileSizeFromServer(char *a_filename)
{
    std::cout << "CExecuteCommand::getFileSizeFromServer: " << std::endl;
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

void CExecuteCommand::setLoginStatus()
{
    std::cout << "CExecuteCommand::setLoginStatus" << std::endl;
}

int CExecuteCommand::getLoginStatus()
{
    int exit_status=0;
    std::cout << "CExecuteCommand::getLoginStatus" << std::endl;
    return exit_status;
}
