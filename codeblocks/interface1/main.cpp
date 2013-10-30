#include <iostream>

using namespace std;

class IAccessToData
{
    public:
        virtual void readStream() = 0;
        virtual void writeStream() = 0;
        virtual void openStream() = 0;
        virtual void closeStream() = 0;

};

class CFileInputOutput : public IAccessToData
{
public:
    virtual void readStream()
    {
        std::cout << "FilereadStream" << std::endl;
    }
    virtual void writeStream()
    {
        std::cout << "FilewriteStream" << std::endl;
    }
    virtual void openStream()
    {
        std::cout << "FileopenStream" << std::endl;
    }
    virtual void closeStream()
    {
        std::cout << "FilecloseStream" << std::endl;
    }
};

class CSocketInputOutput : public IAccessToData
{
public:
    void readStream()
    {
        std::cout << "SocketreadStream" << std::endl;
    }
    void writeStream()
    {
        std::cout << "SocketwriteStream" << std::endl;
    }
    void openStream()
    {
        std::cout << "SocketopenStream" << std::endl;
    }
    void closeStream()
    {
        std::cout << "SocketcloseStream" << std::endl;
    }
};

class CExecuteCommand
{
public:
    /*
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
    */
};

int main()
{
    //CExecuteCommand *wsk = new CExecuteCommand;
    //wsk->getFileFromServer();
    //delete wsk;
    return 0;
}
