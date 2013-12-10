#ifndef SOCKETINPUTOUTPUT_H_INCLUDED
#define SOCKETINPUTOUTPUT_H_INCLUDED

#include <iostream>
#include <string>
#include <winsock2.h>

class CSocketInputOutput
{
public:
    CSocketInputOutput();
    ~CSocketInputOutput();
//    int openSocket(char* , int , SOCKET *);
    SOCKET openSocket(char* , int );
    int closeSocket();
    int readFromSocket();
    int writeToSocket(std::string );

    std::string m_data;
    SOCKET m_sClientSocket = INVALID_SOCKET;

private:
    int m_mode;
    SOCKET mp_ListenSocket = INVALID_SOCKET;
    int ret; // ?!
    char sBuffer[2048];

};

#endif // SOCKETINPUTOUTPUT_H_INCLUDED
