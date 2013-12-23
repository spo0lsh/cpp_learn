#ifndef SOCKETINPUTOUTPUT_H_INCLUDED
#define SOCKETINPUTOUTPUT_H_INCLUDED

//#include <iostream>
#include <string>
#include <winsock2.h>
#define DEFAULT_BUFFER      2048
#define TIMEOUT             300000 // 300 seconds

class CSocketInputOutput
{
public:
    CSocketInputOutput();
    ~CSocketInputOutput();
    SOCKET openSocket(char* , int );
    int closeSocket();
    int readFromSocket();
    int readFromSocket(SOCKET );
    int writeToSocket(std::string );
    int writeToSocket(int );
    std::string m_data;
    SOCKET m_sClientSocket; //= INVALID_SOCKET;
    int ret; // ?!
    char sBuffer[2048];
    SOCKET mp_ListenSocket; //= INVALID_SOCKET;
private:
    int m_mode;
};

#endif // SOCKETINPUTOUTPUT_H_INCLUDED
