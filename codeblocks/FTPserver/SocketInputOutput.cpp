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
SOCKET CSocketInputOutput::openSocket(char* a_host, int a_port)
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

int CSocketInputOutput::readFromSocket(SOCKET a_sClientSocket)
{
    std::cout << "CSocketInputOutput::readFromSocket" << std::endl;
    int ret=0;
    int timeout = 10000; //in milliseconds. this is 10 seconds
    std::cout << "CClientThread::ReadFromSocketTest timeout: " << timeout / 1000 << std::endl;
    memset(sBuffer, 0, sizeof(sBuffer));
    setsockopt(a_sClientSocket,SOL_SOCKET,SO_RCVTIMEO,(char *)&timeout,sizeof(int)); //setting the receive timeout
    ret = recv(a_sClientSocket, sBuffer, 2048, 0);
    if (ret == SOCKET_ERROR)
    {
        std::cout << "CClientThread::ReadFromSocket.recv() failed: " << WSAGetLastError() << std::endl;
    }
    else
    {
        std::cout << "CClientThread::ReadFromSocket ret: " << ret << std::endl;
        sBuffer[ret] = '\0';
    }
    return ret;
}

int CSocketInputOutput::readFromSocket()
{
    std::cout << "CSocketInputOutput::readFromSocket" << std::endl;
    int ret=0;
    int timeout = 10000; //in milliseconds. this is 10 seconds
    std::cout << "CClientThread::ReadFromSocketTest timeout: " << timeout / 1000 << std::endl;
    memset(sBuffer, 0, sizeof(sBuffer));
    setsockopt(this->m_sClientSocket,SOL_SOCKET,SO_RCVTIMEO,(char *)&timeout,sizeof(int)); //setting the receive timeout
    ret = recv(this->m_sClientSocket, sBuffer, 2048, 0);
    if (ret == SOCKET_ERROR)
    {
        std::cout << "CClientThread::ReadFromSocket.recv() failed: " << WSAGetLastError() << std::endl;
    }
    else
    {
        std::cout << "CClientThread::ReadFromSocket ret: " << ret << std::endl;
        sBuffer[ret] = '\0';
    }
    return ret;
}
int CSocketInputOutput::writeToSocket(std::string a_data)
{
    strcpy(sBuffer, a_data.c_str());
    ret = send(m_sClientSocket, sBuffer, strlen(sBuffer), 0);
    if (ret != SOCKET_ERROR)
    {
        std::cout << "CSocketInputOutput::writeToSocket send: " << sBuffer << std::endl;
    }
    else
    {
        std::cout << "CSocketInputOutput::writeToSocket: " << WSAGetLastError() << std::endl;
    }
    return 0;
}
