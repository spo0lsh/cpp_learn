#ifndef SOCKETINPUTOUTPUT_H_INCLUDED
#define SOCKETINPUTOUTPUT_H_INCLUDED

#define DEFAULT_BUFFER      2048
#define TIMEOUT             300000 // 300 seconds

#include <iostream>
#include <string>
#include <winsock2.h>
#include <stdio.h>

class CSocketInputOutput
{
public:
    CSocketInputOutput();
    ~CSocketInputOutput();
    int openSocket(char* , int );
    int closeSocket();
    int readFromSocket();
    int readFromSocket(SOCKET );
    int writeToSocket(std::string );
    char sBuffer[2048];
    std::string m_data;
private:
    int m_mode;
    SOCKET m_sServerSocket; //= INVALID_SOCKET;
    struct sockaddr_in server;
    struct hostent *host;// = NULL;
    WSADATA wsd;
};

#endif // SOCKETINPUTOUTPUT_H_INCLUDED
