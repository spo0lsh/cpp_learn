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
//    std::cout << "CExecuteCommand::showFilesOnServer" << std::endl;
    if(this->getLoginStatus() != 0)
    {
        std::cout << "CExecuteCommand::showFilesOnServer: not logged" << std::endl;
    }
    else
    {
        std::cout << "CExecuteCommand::showFilesOnServer" << std::endl;
        oSocketInputOutput.writeToSocket("LIST");
        if(oSocketInputOutput.readFromSocket() > 0)
        {
            std::cout << "CExecuteCommand::showFilesOnServer.readFromSocket() RETR: " << oSocketInputOutput.sBuffer << std::endl;
        }
    }
}

void CExecuteCommand::deleteFileOnServer(std::string a_filename)
{
//    std::cout << "CExecuteCommand::deleteFileOnServer: " << std::endl;
    if(this->getLoginStatus() != 0)
    {
        std::cout << "CExecuteCommand::deleteFileOnServer: not logged" << std::endl;
    }
    else
    {
        std::cout << "CExecuteCommand::deleteFileOnServer: " << a_filename << std::endl;
        oSocketInputOutput.writeToSocket("DELE " + a_filename);
        if(oSocketInputOutput.readFromSocket() > 0)
        {
            std::cout << "CExecuteCommand::deleteFileOnServer.readFromSocket() RETR: " << oSocketInputOutput.sBuffer << std::endl;
            if(strcmp(oSocketInputOutput.sBuffer, "KO") != 0)
            {
                std::cout << "Delete file: " << a_filename << " successfull." << std::endl;
            }
            else
            {
                std::cout << "Delete file: " << a_filename << " fail." << std::endl;
            }
        }
    }
}


void CExecuteCommand::putFileToServer(std::string a_filename)
{
//    std::cout << "CExecuteCommand::putFileToServer: " << std::endl;
    if(this->getLoginStatus() != 0)
    {
        std::cout << "CExecuteCommand::putFileToServer: not logged" << std::endl;
    }
    else
    {
        std::cout << "CExecuteCommand::putFileToServer: " << a_filename << std::endl;
        if(this->oFileInputOutput.openFile(&a_filename[0], 0) != 0)
        {
            std::cout << "CExecuteCommand::putFileToServer->oFileInputOutput.openFile" << std::endl;
            int size=this->oFileInputOutput.checkFileSize();
            std::cout << "CExecuteCommand::putFileToServer->oFileInputOutput.checkFileSize(): " << size << std::endl;
            this->oFileInputOutput.closeFile();
        }
        else
        {
            std::cout << "CExecuteCommand::putFileToServer.openFile: " << a_filename << " fail." << std::endl;
        }
        // if(file exist)
        //   size=checksize(a_filename)
        //   openfile
        //   if(size > maxbuffor)
        //      segmentation of file
        //   else
        //      data=read(file)
        //      socketsend(data)
        //      wait for OK
        oSocketInputOutput.writeToSocket("STOR " + a_filename);
        if(oSocketInputOutput.readFromSocket() > 0)
        {
            std::cout << "CExecuteCommand::putFileToServer.readFromSocket() RETR: " << oSocketInputOutput.sBuffer << std::endl;
        }
    }
}

void CExecuteCommand::getFileFromServer(std::string a_filename)
{
//    std::cout << "CExecuteCommand::getFileFromServer: " << std::endl;
    if(this->getLoginStatus() != 0)
    {
        std::cout << "CExecuteCommand::getFileFromServer: not logged" << std::endl;
    }
    else
    {
        std::cout << "CExecuteCommand::getFileFromServer: " << a_filename << std::endl;
        oSocketInputOutput.writeToSocket("RETR " + a_filename);
        if(oSocketInputOutput.readFromSocket() > 0)
        {
            std::cout << "CExecuteCommand::getFileFromServer.readFromSocket() RETR: " << oSocketInputOutput.sBuffer << std::endl;
        }
    }
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
            std::cout << "CExecuteCommand::getFileSizeFromServer.readFromSocket() SIZE: " << oSocketInputOutput.sBuffer << std::endl;
            if(strcmp(oSocketInputOutput.sBuffer, "KO") != 0)
            {
                std::cout << "Size of: " << a_filename << " is " << oSocketInputOutput.sBuffer << " bytes." << std::endl;
            }
            else
            {
                std::cout << "Size of: " << a_filename << " fail. " << std::endl;
            }
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