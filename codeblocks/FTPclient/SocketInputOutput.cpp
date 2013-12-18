#include "SocketInputOutput.h"

CSocketInputOutput::CSocketInputOutput()
{
    m_sServerSocket = INVALID_SOCKET;
    host = NULL;
}

CSocketInputOutput::~CSocketInputOutput()
{

}

int CSocketInputOutput::openSocket(char* a_host, int a_port)
{
    int exit_status=0;
//    WSADATA       wsd;
    if (WSAStartup(MAKEWORD(2,2), &wsd) != 0)
    {
        printf("Failed to load Winsock library!\n");
        exit_status=1;
    }
//    strcpy(szMessage, "dupa");
    m_sServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_sServerSocket == INVALID_SOCKET)
    {
        printf("socket() failed: %d\n", WSAGetLastError());
        exit_status=1;
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(a_port);
    server.sin_addr.s_addr = inet_addr(a_host);
    // If the supplied server address wasn't in the form
    // "aaa.bbb.ccc.ddd" it's a hostname, so try to resolve it
    if (server.sin_addr.s_addr == INADDR_NONE)
    {
        host = gethostbyname(a_host);
        if (host == NULL)
        {
            printf("Unable to resolve server: %s\n", a_host);
            exit_status=1;
        }
        CopyMemory(&server.sin_addr, host->h_addr_list[0], host->h_length);
    }
    if (connect(m_sServerSocket, (struct sockaddr *)&server,
        sizeof(server)) == SOCKET_ERROR)
    {
        printf("connect() failed: %d\n", WSAGetLastError());
        exit_status=1;
    }
// send
// recv
//closesocket(m_sServerSocket);
//WSACleanup();
return exit_status;
}

int CSocketInputOutput::closeSocket()
{
    std::cout << "CSocketInputOutput::closeSocket" << std::endl;
    closesocket(m_sServerSocket);
    m_sServerSocket = INVALID_SOCKET;
    return 0;
}

int CSocketInputOutput::readFromSocket()
{
    std::cout << "CSocketInputOutput::readFromSocket" << std::endl;
//    int ret=0;
    int timeout = TIMEOUT; //
    ret=0;
    std::cout << "CClientThread::ReadFromSocketTest timeout: " << timeout / 1000 << std::endl;
    memset(sBuffer, 0, sizeof(sBuffer));
    setsockopt(this->m_sServerSocket,SOL_SOCKET,SO_RCVTIMEO,(char *)&timeout,sizeof(int)); //setting the receive timeout
    ret = recv(this->m_sServerSocket, sBuffer, DEFAULT_BUFFER, 0);
    if (ret == SOCKET_ERROR)
    {
        std::cout << "CClientThread::ReadFromSocket.recv() failed: " << WSAGetLastError() << std::endl;
    }
    else
    {
        std::cout << "CClientThread::ReadFromSocket ret: " << ret << std::endl;
        std::cout << "CClientThread::ReadFromSocket string " << sBuffer << std::endl;
//        sBuffer[ret] = '\0'; //problem with binary
    }
    return ret;
}

int CSocketInputOutput::writeToSocket(std::string a_data)
{
//    std::cout << "CSocketInputOutput::writeToSocket try send: " << a_data << std::endl;
    memset(sBuffer, 0, sizeof(sBuffer)); // fix?!
    strcpy(sBuffer, a_data.c_str());
//    int ret = send(this->m_sServerSocket, sBuffer, strlen(sBuffer), 0);
    int ret = send(this->m_sServerSocket, sBuffer, sizeof(sBuffer), 0);
    if (ret != SOCKET_ERROR)
    {
//        std::cout << "CSocketInputOutput::writeToSocket send: " << sBuffer << std::endl;
        std::cout << "CSocketInputOutput::writeToSocket send: " << std::endl;
    }
    else
    {
        std::cout << "CSocketInputOutput::writeToSocket error: " << WSAGetLastError() << std::endl;
    }
    return 0;
}
