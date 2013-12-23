#ifndef EXECUTECOMMAND_H_INCLUDED
#define EXECUTECOMMAND_H_INCLUDED

#include <iostream>
#include <winsock2.h>
#include <string>
#include <cmath>
#include "FileInputOutput.h"
#include "SocketInputOutput.h"
#include "DatabaseOperations.h"

class CExecuteCommand
{
public:
    CExecuteCommand();
    ~CExecuteCommand();

    void parseData(std::string );
    void executeCommand(std::string , std::string );
    void setLoginStatus(int);
    int getLoginStatus();
    SOCKET m_sClientSocket;

    std::vector <std::vector<std::string> > *mp_DB;

    CFileInputOutput *m_opFileInputOutput; // need change to without pointer
    CSocketInputOutput *m_opCSocketInputOutput; // need change to without pointer

private:
    int getFileFromServer(std::string );      // RETR filename
    int putFileToServer(std::string );        // STOR filename size
    int showFilesOnServer();      // LIST
    int deleteFileOnServer(std::string );     // DELETE fielname
    int loginToServer(std::string, std::string );   // USER, PASS
    int logoutFromServer();               // logout //missed in design!
    int checkFileSize(std::string );          // SIZE filename

    std::string login;
    std::string password;
    int m_iLoginStatus;
};

enum ECommand
{
	cUSER,
	cPASS,
	cQUIT,
	cRETR,
	cSIZE,
	cSTOR,
	cDELE,
	cLIST,
	cNOOP,
	cFAIL, // wrong command
};

enum EResponse
{
    rOK,
    rNOK,
    rFAIL, // wrong response
};

#endif // EXECUTECOMMAND_H_INCLUDED
