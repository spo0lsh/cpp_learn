#include <iostream>

using namespace std;

class CFileInputOutput
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

class CSocketInputOutput
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


class IAccessToData : public CFileInputOutput, public CSocketInputOutput
{
    public:
        void readStream(int TYPE)
        {
            if (TYPE == 1)
            {
                CFileInputOutput::openStream();
            }
            else if (TYPE == 2)
            {
                CSocketInputOutput::openStream();
            }
            else
            {
                std::cout << "error" << endl;
            }
        }
};

class CExecuteCommand
{
public:
    void getFileFromServer()
    {
        IAccessToData test;
        test.readStream(1);
        test.readStream(2);
        test.readStream(3);
    }
};

int main()
{
    CExecuteCommand *wsk = new CExecuteCommand;
    wsk->getFileFromServer();
    return 0;
}
