#include "ExecuteCommand.h"

CExecuteCommand::CExecuteCommand()
{

}

CExecuteCommand::~CExecuteCommand()
{

}

int CExecuteCommand::getLoginStatus()
{
    return this->m_iLoginStatus;
}

void CExecuteCommand::setLoginStatus(int a_iLoginStatus)
{
    this->m_iLoginStatus=a_iLoginStatus;
}

void CExecuteCommand::parseData(std::string a_data)
{
    std::cout << "CExecuteCommand::parseData: " << a_data << std::endl;
    std::string command;
    std::string parameter;
    char str2[] = " ";
    char * pnt;
    pnt=strtok( const_cast<char *>(a_data.c_str())," ");
    int i=0;
    while( pnt!= NULL )
    {
        if(i==0)
        {
            command=pnt;
        }
        else if(i==1)
        {
            parameter=pnt;
        }
        pnt = strtok( NULL, str2 );
        ++i;
    }
    std::cout << "CExecuteCommand::parseData command: " << command << " parameter " << parameter << std::endl;
    this->executeCommand(command, parameter);
}

void CExecuteCommand::executeCommand(std::string command, std::string parameter)
{
    std::cout << "CExecuteCommand::executeCommand" << std::endl;
    this->setLoginStatus(0); // for debug!
    if(this->getLoginStatus() != 0 )
    {
        if(command.compare("USER") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute USER" << std::endl;
        }
        else if(command.compare("PASS") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute PASS" << std::endl;
        }
        else
        {
            std::cout << "CExecuteCommand::executeCommand fail, user not logged" << std::endl;
            // exit status 1
        }
    }
    else
    {
        if(command.compare("QUIT") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute QUIT" << std::endl;
        }
        else if(command.compare("RETR") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute RETR" << std::endl;
        }
        else if(command.compare("SIZE") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute SIZE" << std::endl;
            this->checkFileSize( parameter );
        }
        else if(command.compare("STOR") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute STOR" << std::endl;
        }
        else if(command.compare("DELE") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute DELE" << std::endl;
        }
        else if(command.compare("LIST") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute LIST" << std::endl;
        }
        else if(command.compare("NOOP") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute NOOP" << std::endl;
        }
        else
        {
            std::cout << "CExecuteCommand::executeCommand Unsupported command: " << command << std::endl;
        }
    }
}

int CExecuteCommand::getFileFromServer(std::string filename)
{
    std::cout << "CExecuteCommand::getFileFromServer" << std::endl;
    return 0;
}

int CExecuteCommand::putFileToServer(std::string filename)
{
    std::cout << "CExecuteCommand::putFileToServer" << std::endl;
    return 0;
}

int CExecuteCommand::showFilesOnServer(std::string filename)
{
    std::cout << "CExecuteCommand::showFilesOnServer" << std::endl;
    return 0;
}

int CExecuteCommand::deleteFileOnServer(std::string filename)
{
    std::cout << "CExecuteCommand::deleteFileOnServer" << std::endl;
    return 0;
}

int CExecuteCommand::loginToServer(std::string login, std::string password)
{
    std::cout << "CExecuteCommand::loginToServer" << std::endl;
    return 0;
}

int CExecuteCommand::logoutFromServer()
{
    std::cout << "CExecuteCommand::logoutFromServer" << std::endl;
    return 0;
}

int CExecuteCommand::checkFileSize(std::string filename)
{
    std::cout << "CExecuteCommand::checkFileSize: " << filename << std::endl;
//    if(file exist != true)
//        write NOK
//    else
//        size=sizeof filename
//        write OK size
    return 0;
}


//
//int CExecuteCommand::getFileFromServer(SOCKET a_clientSocket, char *filename)
//{
//    std::cout << "CExecuteCommand::getFileFromServer" << std::endl;
//    return 0;
//}
//
//int CExecuteCommand::putFileToServer(SOCKET a_clientSocket, char *filename)
//{
//    std::cout << "CExecuteCommand::putFileToServer" << std::endl;
//    return 0;
//}
//
//int CExecuteCommand::showFilesOnServer(SOCKET a_clientSocket, char *filename)
//{
//    std::cout << "CExecuteCommand::showFilesOnServer" << std::endl;
//    return 0;
//}
//
//int CExecuteCommand::deleteFileOnServer(SOCKET a_clientSocket, char *filename)
//{
//    std::cout << "CExecuteCommand::deleteFileOnServer" << std::endl;
//    return 0;
//}
//
//int CExecuteCommand::loginToServer(SOCKET a_clientSocket, char *login, char *password)
//{
//    std::cout << "CExecuteCommand::loginToServer" << std::endl;
//    return 0;
//}
//
//int CExecuteCommand::logoutFromServer(SOCKET a_clientSocket)
//{
//    std::cout << "CExecuteCommand::logoutFromServer" << std::endl;
//    return 0;
//}
//
//int CExecuteCommand::checkFileSize(SOCKET a_clientSocket, char *filename)
//{
//    std::cout << "CExecuteCommand::checkFileSize" << std::endl;
//    return 0;
//}
