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
        virtual void openStream() = 0;
        virtual void closeStream() = 0;

};

class CExecuteCommand
{
public:
    void getFileFromServer()
    {
        //IAccessToData *wsk = new IAccessToData;
        //wsk->readStream();
        //delete wsk;
    }
};

int main()
{
    CExecuteCommand *wsk = new CExecuteCommand;
    //wsk->getFileFromServer();
    delete wsk;
    return 0;
}
