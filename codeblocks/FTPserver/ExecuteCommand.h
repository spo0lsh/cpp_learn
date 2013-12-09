#ifndef EXECUTECOMMAND_H_INCLUDED
#define EXECUTECOMMAND_H_INCLUDED

#include <iostream>
#include <winsock2.h>
#include <string>

class CExecuteCommand
{
public:
    CExecuteCommand();
    ~CExecuteCommand();

    void parseData(std::string );
    void executeCommand(std::string , std::string );
    void setLoginStatus(int);

    SOCKET m_sClientSocket;

private:
    int getLoginStatus();
//    int getFileFromServer(SOCKET, char *);      // RETR filename
//    int putFileToServer(SOCKET, char *);        // STOR filename size
//    int showFilesOnServer(SOCKET, char *);      // LIST
//    int deleteFileOnServer(SOCKET, char *);     // DELETE fielname
//    int loginToServer(SOCKET, char*, char *);   // USER, PASS
//    int logoutFromServer(SOCKET);               // logout //missed in design!
//    int checkFileSize(SOCKET, char *);          // SIZE filename
    int getFileFromServer(std::string );      // RETR filename
    int putFileToServer(std::string );        // STOR filename size
    int showFilesOnServer(std::string );      // LIST
    int deleteFileOnServer(std::string );     // DELETE fielname
    int loginToServer(std::string, std::string );   // USER, PASS
    int logoutFromServer();               // logout //missed in design!
    int checkFileSize(std::string );          // SIZE filename

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
