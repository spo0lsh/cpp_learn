#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class IAccessToData;
class CFileInputOutput;
class CSocketInputOutput;
class CExecuteCommand;
class CFtpClient;

enum ECommand
{
    QUIT,
    PUT,
    GET,
    DEL,
    DIR,
    HELP,
    CONNECT,
    DISCONNECT,
    OK,
    NOK,
    LOGIN,
    UNKNOW
};

class IAccessToData
{
public:
    virtual void readStream()=0;
    virtual void writeStream()=0;
    virtual void openStream()=0;
    virtual void closeStream()=0;
};

class CFileInputOutput : public IAccessToData
{
private:
    void readStream()
    {
        std::cout << "CFileInputOutput::readStream" << endl;
    }
    void writeStream()
    {
        std::cout << "CFileInputOutput::writeStream" << endl;
    }
    void openStream()
    {
        std::cout << "CFileInputOutput::openStream" << endl;
    }
    void closeStream()
    {
        std::cout << "CFileInputOutput::closeStream" << endl;
    }
};

class CSocketInputOutput : public IAccessToData
{
private:
    void readStream()
    {
        std::cout << "CSocketInputOutput::readStream" << endl;
    }
    void writeStream()
    {
        std::cout << "CSocketInputOutput::writeStream" << endl;
    }
    void openStream()
    {
        std::cout << "CSocketInputOutput::openStream" << endl;
    }
    void closeStream()
    {
        std::cout << "CSocketInputOutput::closeStream" << endl;
    }
};

class CExecuteCommand
{
public:
    void getFileFromServer(string sLogin, string sPassword, string sHost, int iPort)
    {
        std::cout << "CExecuteCommand::getFileFromServer" << endl;
        IAccessToData *pSocket = new CSocketInputOutput;
        pSocket->openStream();
        pSocket->readStream();
        pSocket->closeStream();
        delete pSocket;
        IAccessToData *pFile = new CFileInputOutput;
        pFile->openStream();
        pFile->writeStream();
        pFile->closeStream();
        delete pFile;
    }
    void putFileFromServer()
    {
        std::cout << "CExecuteCommand::putFileFromServer" << endl;
    }
    void showFilesOnServer()
    {
        std::cout << "CExecuteCommand::showFilesOnServer" << endl;
    }
    void deleteFileOnServer()
    {
        std::cout << "CExecuteCommand::deleteFileOnServer" << endl;
    }
    int connectToServer()
    {
        IAccessToData *wsk1 = new CSocketInputOutput;
        wsk1->openStream();
        wsk1->readStream();
        wsk1->closeStream();
        delete wsk1;
        std::cout << "CExecuteCommand::connectToServer" << endl;
        return 0; // true
    }
    void disconnectFromServer()
    {
        IAccessToData *wsk1 = new CSocketInputOutput;
        wsk1->openStream();
        wsk1->readStream();
        wsk1->closeStream();
        delete wsk1;
        std::cout << "CExecuteCommand::disconnectFromServer" << endl;
    }
};

class CFtpClient
{
public:
    int showMenu()
    {
        string sCMD;
        if(iLogged != 1)
        {
            std::cout << "Jestes nie zalogowany" << std::endl;
        }
        else if(iLogged != 0)
        {
            std::cout << "Jestes zalogowany" << std::endl;
        }
        else
        {
            std::cout << "Nie wiem, czy jestes zalogowany czy nie" << std::endl;
        }
        std::cout << "Podaj CMD: ";
        cin >> sCMD;
        std::cout << "Musze wykonac: " << sCMD << std::endl;

        if (sCMD == "help")
        {
            std::cout << "showMenu::help" << std::endl;
            ECMD = HELP;
        }
        else if (sCMD == "connect")
        {
            std::cout << "showMenu::connect" << std::endl;
            ECMD = CONNECT;
        }
        else if (sCMD == "quit")
        {
            std::cout << "showMenu::quit" << std::endl;
            ECMD = QUIT;
        }
        else
        {
            std::cout << "showMenu::WTF?" << std::endl;
            ECMD = UNKNOW;
        }
        return ECMD;
    }
    void executeCommand(int iCMD)
    {
        std::cout << "executeCommand::iCMD " << iCMD << std::endl;
        std::cout << "executeCommand::ECMD " << ECMD << std::endl;
        if ( ECMD == HELP)
        {
            std::cout << "executeCommand::help " << std::endl;
            std::cout << "help - show this help" << std::endl;
            std::cout << "connect - connect to server" << std::endl;
            std::cout << "disconnect - disconnect from server" << std::endl;
            std::cout << "get" << std::endl;
            std::cout << "put" << std::endl;
            std::cout << "dir" << std::endl;
            std::cout << "del" << std::endl;
        }
        else if (ECMD == CONNECT)
        {
            std::cout << "executeCommand::connect " << std::endl;

            std::cout << "Enter login: ";
            std::cin >> sLogin;
            std::cout << "Enter password: ";
            std::cin >> sPassword;
            std::cout << "Enter host: ";
            std::cin >> sHost;
            std::cout << "Enter port: ";
            std::cin >> sPort;
            // if connect success full
            CExecuteCommand *wsk = new CExecuteCommand;
            //std::cout << "status of command: " << wsk->connectToServer() << endl;
            if(wsk->connectToServer() != 1)
            {
                iLogged=1;
            }
            else
            {
                iLogged=0;
            }
            delete wsk;
        }
        else
        {
            std::cout << "executeCommand::else " << std::endl;
        }
    }
private:
    ECommand ECMD;
    int iLogged;
    string sLogin;
    string sPassword;
    string sHost;
    int sPort;
};


int main(int argc, char *argv[])
{
    int iTmp;
    iTmp = -1;
    CFtpClient oCFtpClient;
    while(iTmp != 0)
    {
        iTmp=oCFtpClient.showMenu();
        std::cout << "main::execute " << iTmp << std::endl;
        oCFtpClient.executeCommand(iTmp);
    }
    return 0;
}
