#include "SocketInputOutput.h"

CSocketInputOutput::CSocketInputOutput()
{

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
    if (this->mp_ListenSocket == SOCKET_ERROR)
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

int CSocketInputOutput::readFromSocket()
{
    std::cout << "CSocketInputOutput::readFromSocket" << std::endl;
    return 0;
}
int CSocketInputOutput::writeToSocket(std::string a_data)
{
//                std::cout << "CExecuteCommand::executeCommand need execute USER: " << parameter << std::endl;
//            this->login = parameter;
//            int ret;
//            char szBuffer[2048];
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

//    std::cout << "CSocketInputOutput::writeToSocket" << std::endl;
    return 0;
}
