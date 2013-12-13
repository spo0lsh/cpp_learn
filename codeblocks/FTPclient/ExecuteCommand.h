#ifndef EXECUTECOMMAND_H_INCLUDED
#define EXECUTECOMMAND_H_INCLUDED

#include <string>
#include <iostream>
#include <cstdlib>
#include "SocketInputOutput.h"
#include "FileInputOutput.h"

class CExecuteCommand
{
public:
    CExecuteCommand();
    ~CExecuteCommand();

    void showFilesOnServer();
    void deleteFileOnServer(std::string);
    void putFileToServer(std::string);
    void getFileFromServer(std::string);
    void getFileSizeFromServer(std::string);
    void setLogin(char *);
    void setPassword(char *);
    void setHost(char *);
    void setPort(int);
    void setLoginStatus(int);
    int getLoginStatus();

    int connectToServer();
    void disconnectFromServer();
protected:

private:
    std::string login;
    std::string password;
    std::string host;
    int port;
    int loginStatus;
    CSocketInputOutput oSocketInputOutput;
    CFileInputOutput oFileInputOutput;
};

#endif // EXECUTECOMMAND_H_INCLUDED
