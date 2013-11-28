#include "SocketInputOutput.h"

//int CSocketInputOutput::openSocket(char* host, int port, SOCKET *p_ListenSocket)
SOCKET CSocketInputOutput::openSocket(char* host, int port)
{
    std::cout << "SocketInputOutput::openSocket " << host <<  " " << port << std::endl;

    WSADATA       wsd;
    struct sockaddr_in local;


    if (WSAStartup(MAKEWORD(2,2), &wsd) != 0)
    {
        std::cout << "CSocketInputOutput::openSocket socket() Failed to load Winsock!" << std::endl;
        this->mp_ListenSocket=1;
    }

    this->mp_ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (this->mp_ListenSocket == SOCKET_ERROR)
    {
        //printf("socket() failed: %d\n", WSAGetLastError());
        std::cout << "CSocketInputOutput::openSocket socket() failed: " << WSAGetLastError() << std::endl;
        this->mp_ListenSocket=1;
    }

    local.sin_addr.s_addr = htonl(INADDR_ANY);
    local.sin_family = AF_INET;
    local.sin_port = htons(port);

    if (bind(mp_ListenSocket, (struct sockaddr *)&local,
            sizeof(local)) == SOCKET_ERROR)
    {
        std::cout << "bind() failed: " << WSAGetLastError()  << std::endl;
        this->mp_ListenSocket=1;
    }
    listen(mp_ListenSocket, 8);

    return mp_ListenSocket;
}
