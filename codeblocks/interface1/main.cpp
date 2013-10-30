#include <iostream>

using namespace std;

class CFileInputOutput
{
public:
    virtual void readFile()
    {
        std::cout << "FilereadStream" << std::endl;
    }
    virtual void writeFile()
    {
        std::cout << "FilewriteStream" << std::endl;
    }
    virtual void openFile()
    {
        std::cout << "FileopenStream" << std::endl;
    }
    virtual void closeFile()
    {
        std::cout << "FilecloseStream" << std::endl;
    }
};

class CSocketInputOutput
{
public:
    void readSocket()
    {
        std::cout << "SocketreadStream" << std::endl;
    }
    void writeSocket()
    {
        std::cout << "SocketwriteStream" << std::endl;
    }
    void openSocket()
    {
        std::cout << "SocketopenStream" << std::endl;
    }
    void closeSocket()
    {
        std::cout << "SocketcloseStream" << std::endl;
    }
};


class IAccessToData : public CFileInputOutput, public CSocketInputOutput
{
    public:
        virtual void readStream() = 0;
        virtual void writeStream() = 0;
        //virtual void openStream() = 0;
        //virtual void closeStream() = 0;

};

void IAccessToData::readStream()
{
    std::cout << "IAccsesToData::readStream()" << std::endl;
    openSocket();
    openFile();
}

void IAccessToData::writeStream()
{
    std::cout << "IAccsesToData::writeStream()" << std::endl;
}


class CExecuteCommand : public IAccessToData
{
public:
    void readStream()
    {
        IAccessToData::readStream();
    }
    void writeStream()
    {
        IAccessToData::writeStream();
    }
    void getFileFromServer()
    {
        std::cout << "CExecuteCommand::getFileFromServer" << std::endl;
        readStream();
    }
};

int main()
{
    CExecuteCommand *wsk = new CExecuteCommand;
    wsk->getFileFromServer();
    delete wsk;
    return 0;
}
