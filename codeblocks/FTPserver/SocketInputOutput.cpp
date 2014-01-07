#include <iostream>
#include "SocketInputOutput.h"

CSocketInputOutput::CSocketInputOutput()
{
    m_sClientSocket = INVALID_SOCKET;
    mp_ListenSocket = INVALID_SOCKET;
}

CSocketInputOutput::~CSocketInputOutput()
{

}

// bind and listen, not only open socket ... FIX!
SOCKET CSocketInputOutput::openSocket(char* a_host, int &a_port)
{
    std::cout << "SocketInputOutput::openSocket " << a_host <<  " " << a_port << std::endl;

    WSADATA       wsd;
    struct sockaddr_in local;


    if (WSAStartup(MAKEWORD(2,2), &wsd) != 0)
    {
        std::cout << "CSocketInputOutput::openSocket socket() Failed to load Winsock!" << std::endl;
        this->mp_ListenSocket=1;
    }

    this->mp_ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (this->mp_ListenSocket == (unsigned int)SOCKET_ERROR) //(unsigned int)
    {
        //printf("socket() failed: %d\n", WSAGetLastError());
        std::cout << "CSocketInputOutput::openSocket socket() failed: " << WSAGetLastError() << std::endl;
        this->mp_ListenSocket=1;
    }

    local.sin_addr.s_addr = htonl(INADDR_ANY);
    local.sin_family = AF_INET;
    local.sin_port = htons(a_port);

    if (bind(mp_ListenSocket, (struct sockaddr *)&local,
            sizeof(local)) == SOCKET_ERROR)
    {
        std::cout << "bind() failed: " << WSAGetLastError()  << std::endl;
        this->mp_ListenSocket=1;
    }
    listen(mp_ListenSocket, 8);

    return mp_ListenSocket;
}

int CSocketInputOutput::readFromSocket(SOCKET &a_sClientSocket)
{
    std::cout << "CSocketInputOutput::readFromSocket(SOCKET)" << std::endl;
    ret=0;
    int timeout = TIMEOUT; //
    std::cout << "CClientThread::ReadFromSocket(SOCKET) timeout: " << TIMEOUT / 1000 << std::endl;
    memset(sBuffer, 0, sizeof(sBuffer));
    setsockopt(a_sClientSocket,SOL_SOCKET,SO_RCVTIMEO,(char *)&timeout,sizeof(int)); //setting the receive timeout
    ret = recv(a_sClientSocket, sBuffer, 2048, 0);
    if (ret == SOCKET_ERROR)
    {
        std::cout << "CClientThread::ReadFromSocket(SOCKET).recv() failed: " << WSAGetLastError() << std::endl;
    }
    else
    {
        std::cout << "CClientThread::ReadFromSocket(SOCKET) ret: " << ret << std::endl;
//        sBuffer[ret] = '\0'; //problem with binary
    }
    return ret;
}

int CSocketInputOutput::readFromSocket()
{
    std::cout << "CSocketInputOutput::readFromSocket()" << std::endl;
//    int ret=0;
    int timeout = 10000; //in milliseconds. this is 10 seconds
    std::cout << "CClientThread::ReadFromSocket() timeout: " << timeout / 1000 << std::endl;
    memset(sBuffer, 0, sizeof(sBuffer));
    setsockopt(this->m_sClientSocket,SOL_SOCKET,SO_RCVTIMEO,(char *)&timeout,sizeof(int)); //setting the receive timeout
    ret = recv(this->m_sClientSocket, sBuffer, 2048, 0);
    if (ret == SOCKET_ERROR)
    {
        std::cout << "CClientThread::ReadFromSocket().recv() failed: " << WSAGetLastError() << std::endl;
    }
    else
    {
        std::cout << "CClientThread::ReadFromSocket() ret: " << ret << std::endl;
//        sBuffer[ret] = '\0'; //problem with binary
    }
    return ret;
}
// todo: return code!
int CSocketInputOutput::writeToSocket(std::string a_data)
{
    int exit_status=0;
    memset(sBuffer, 0, sizeof(sBuffer)); //
    a_data[a_data.size()] = '\0'; //TO FIX
    std::cout << "CSocketInputOutput::writeToSocket size: " << a_data.size() << std::endl;
    strcpy(sBuffer, a_data.c_str()); // wrong, need fix
//    ret = send(m_sClientSocket, sBuffer, sizeof(sBuffer), 0);
    ret = send(m_sClientSocket, sBuffer, a_data.size(), 0);
    if (ret != SOCKET_ERROR)
    {
        std::cout << "CSocketInputOutput::writeToSocket send: " << a_data << " bytes: " << ret << std::endl;
    }
    else
    {
        std::cout << "CSocketInputOutput::writeToSocket: " << WSAGetLastError() << std::endl;
        exit_status=1;
    }
    return exit_status;
}

int CSocketInputOutput::writeToSocket(int &a_bytes)
{
//    memset(sBuffer, 0, sizeof(sBuffer)); // fix?
//    strcpy(sBuffer, a_data);
//    ret = send(m_sClientSocket, sBuffer, strlen(sBuffer), 0);
    int exit_status=0;
    ret = send(m_sClientSocket, sBuffer, a_bytes, 0);
//    std::cout << "CSocketInputOutput::writeToSocket string: " << sBuffer << std::endl;
    if (ret != SOCKET_ERROR)
    {
        std::cout << "CSocketInputOutput::writeToSocket send bytes: " << a_bytes << std::endl;
    }
    else
    {
        std::cout << "CSocketInputOutput::writeToSocket: " << WSAGetLastError() << std::endl;
        exit_status=1;
    }
    return exit_status;
}
