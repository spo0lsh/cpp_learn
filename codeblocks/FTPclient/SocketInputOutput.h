#ifndef SOCKETINPUTOUTPUT_H_INCLUDED
#define SOCKETINPUTOUTPUT_H_INCLUDED

#define DEFAULT_BUFFER      2048

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

    std::string m_data;
    SOCKET m_sServerSocket; //= INVALID_SOCKET;
//    int ret; // ?!
//    char sBuffer[2048];
//    SOCKET mp_ListenSocket; //= INVALID_SOCKET;
private:
    int m_mode;
    int m_iPort;
//    std::string m_cHost;
    char m_cHost[128];
//    unsigned int  i;
//    struct sockaddr_in server;
//    struct hostent *host;// = NULL;
};

#endif // SOCKETINPUTOUTPUT_H_INCLUDED
