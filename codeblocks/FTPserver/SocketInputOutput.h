#ifndef SOCKETINPUTOUTPUT_H_INCLUDED
#define SOCKETINPUTOUTPUT_H_INCLUDED

#include <iostream>
#include <string>
#include <winsock2.h>

class CSocketInputOutput
{
public:

    int openSocket(char* , int );
    int closeSocket();
    std::string readFromSocket();
    int writeToSocket(std::string );

    std::string m_data;
private:
    int m_mode;
    SOCKET m_ListenSocket = INVALID_SOCKET;
    SOCKET m_ClientSocket = INVALID_SOCKET;
};

#endif // SOCKETINPUTOUTPUT_H_INCLUDED
