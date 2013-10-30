#include <iostream>

using namespace std;

/*
class CClientFTP;
class CExecuteCommand;
class IAccessToData;
class CFileInputOutput;
class CSocketInputOutput;
*/

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


class CExecuteCommand
{
public:
    void getFileFromServer()
    {
        std::cout << "CExecuteCommand::getFileFromServer" << endl;
        CFileInputOutput *wsk1 = new CFileInputOutput;
        wsk1->openStream();
        delete wsk1;
        CSocketInputOutput *wsk2 = new CSocketInputOutput;
        wsk2->openStream();
        delete wsk2;
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
};

class CClientFTP
{
public:
    void getOptionsFromCommandLine()
    {
        std::cout << "CClientFTP::getOptionsFromCommandLine" << endl;
    }
    void parseCommand()
    {
        std::cout << "CClientFTP::parseCommand" << endl;
        CExecuteCommand *wsk = new CExecuteCommand;
        wsk->getFileFromServer();
        delete wsk;
    }
};

int main()
{
    CClientFTP *wsk = new CClientFTP;
    wsk->getOptionsFromCommandLine();
    wsk->parseCommand();
    delete wsk;

    return 0;
}
