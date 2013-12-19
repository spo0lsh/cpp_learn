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
//            std::cout << "CExecuteCommand::showFilesOnServer.readFromSocket() RETR: " << oSocketInputOutput.sBuffer << std::endl;
            std::cout << "Files on server: " << std::endl;
            while(oSocketInputOutput.readFromSocket() > 0)
            {
        //            std::cout << "Read from socket: " << m_opCSocketInputOutput->sBuffer << std::endl;
                std::cout << oSocketInputOutput.sBuffer << std::endl;
//                oFileInputOutput.writeToFile(oSocketInputOutput.sBuffer);
//                oSocketInputOutput.writeToSocket("OK");
            }
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
        if(this->oFileInputOutput.openFile(&a_filename[0], 2) != 0)
        {
            std::cout << "CExecuteCommand::putFileToServer.openFile: " << a_filename << " fail." << std::endl;
        }
        else
        {
            std::cout << "CExecuteCommand::putFileToServer->oFileInputOutput.openFile" << std::endl;
            int size=this->oFileInputOutput.checkFileSize();
            std::cout << "CExecuteCommand::putFileToServer->oFileInputOutput.checkFileSize(): " << size << std::endl;
            oSocketInputOutput.writeToSocket("STOR " + a_filename);
            if(oSocketInputOutput.readFromSocket() > 0)
            {
                if(strcmp(oSocketInputOutput.sBuffer, "KO") != 0)
                {
                    if(size < DEFAULT_BUFFER)
                    {
                        std::cout << "CExecuteCommand::putFileToServe read: " << oFileInputOutput.readFile(DEFAULT_BUFFER - 1) << std::endl;
                        oSocketInputOutput.writeToSocket(oFileInputOutput.sBuffer);
                        if(oSocketInputOutput.readFromSocket() > 0)
                        {
                            std::cout << "CExecuteCommand::putFileToServer.readFromSocket() RETR status: " << oSocketInputOutput.sBuffer << std::endl;
                        }
                    }
                    else
                    {
                        int blocks=ceil((double)size/(DEFAULT_BUFFER-1));
                        std::cout << "CExecuteCommand::putFileToServer size > DEFAULT_BUFFER, number of packages: " << blocks << std::endl;
                        for(int i=0;i<blocks;++i)
                        {
                            oFileInputOutput.readFile(DEFAULT_BUFFER - 1);
                            oSocketInputOutput.writeToSocket(oFileInputOutput.sBuffer);
                            if(oSocketInputOutput.readFromSocket() > 0)
                            {
                                std::cout << "CExecuteCommand::putFileToServer.readFromSocket() RETR status: " << oSocketInputOutput.sBuffer << std::endl;
                            }
                        }
                    }
                }
                else
                {
                    std::cout << "Can not send file: " << a_filename << " to server." << std::endl;
                }
            }
        }
        std::cout << "CExecuteCommand::putFileToServer done." << std::endl;
        this->oFileInputOutput.closeFile();
    }
}

void CExecuteCommand::getFileFromServer(std::string a_filename)
{
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
            if(oFileInputOutput.openFile(&a_filename[0], 3) != 0)
            {

            }
            else
            {
                while(oSocketInputOutput.readFromSocket() > 0)
                {
                    if(strcmp(oSocketInputOutput.sBuffer, "NOOP") != 0)
//                    if(strncmp(oSocketInputOutput.sBuffer, "NOOP",4) != 0)
                    {
                        std::cout << "CExecuteCommand::getFileFromServer read from socket bytes: " << oSocketInputOutput.ret << std::endl;
                        memcpy(oFileInputOutput.sBuffer, oSocketInputOutput.sBuffer, sizeof(oFileInputOutput.sBuffer) );
                        oFileInputOutput.writeToFile(oSocketInputOutput.ret);
                        oSocketInputOutput.writeToSocket("OK");
                    }
                    else
                    {
                        std::cout << "CExecuteCommand::getFileFromServer Read from socket bytes NOOP: " << oSocketInputOutput.ret << " " << oSocketInputOutput.sBuffer << std::endl;
                        oSocketInputOutput.writeToSocket("OK");
                        std::cout << "CExecuteCommand::getFileFromServer BREAK" << std::endl;
                        break;
                    }
                }
            }
            oFileInputOutput.closeFile();
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
    oSocketInputOutput.closeSocket();
}
