#ifndef SOCKETINPUTOUTPUT_H_INCLUDED
#define SOCKETINPUTOUTPUT_H_INCLUDED

#define DEFAULT_BUFFER      2048
#define TIMEOUT             120000 // 120 seconds

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
    int writeToSocket(int );
    char sBuffer[DEFAULT_BUFFER];
    std::string m_data;
    int ret;
private:
    int m_mode;
    SOCKET m_sServerSocket; //= INVALID_SOCKET;
    struct sockaddr_in server;
    struct hostent *host;// = NULL;
    WSADATA wsd;
};

#endif // SOCKETINPUTOUTPUT_H_INCLUDED
