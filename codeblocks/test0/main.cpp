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
    quit,
    put,
    get,
    del,
    dir,
    help,
    connect,
    disconnect,
    unknow
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
public:
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
public:
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
            ECMD = help;
        }
        else if (sCMD == "connect")
        {
            std::cout << "showMenu::connect" << std::endl;
            ECMD = connect;
        }
        else if (sCMD == "quit")
        {
            std::cout << "showMenu::quit" << std::endl;
            ECMD = quit;
        }
        else
        {
            std::cout << "showMenu::WTF?" << std::endl;
            ECMD = unknow;
        }
        return ECMD;
    }
    void executeCommand(int iCMD)
    {
        std::cout << "executeCommand::iCMD " << iCMD << std::endl;
        std::cout << "executeCommand::ECMD " << ECMD << std::endl;
        if ( ECMD == help)
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
        else if (ECMD == connect)
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
            iLogged=1;
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
