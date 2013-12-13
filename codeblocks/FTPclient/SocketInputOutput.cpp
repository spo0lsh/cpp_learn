#include "SocketInputOutput.h"

CSocketInputOutput::CSocketInputOutput()
{
    m_sServerSocket = INVALID_SOCKET;
//    host = NULL;
}

CSocketInputOutput::~CSocketInputOutput()
{

}

int CSocketInputOutput::openSocket(char* a_host, int a_port)
{
//    int exit_status=0;
//    WSADATA wsd;
//    strcpy(m_cHost, a_host);
//    if (WSAStartup(MAKEWORD(2,2), &wsd) != 0)
//    {
//        std::cout << "Failed to load Winsock library!\n";
//        exit_status=1;
//    }
//    m_sServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//    if (m_sServerSocket == INVALID_SOCKET)
//    {
//        std::cout << "socket() failed: " << WSAGetLastError() << std::endl;
//        exit_status=1;
//    }
//    else
//    {
//        server.sin_family = AF_INET;
//        server.sin_port = htons(this->m_iPort);
//        server.sin_addr.s_addr = inet_addr(this->m_cHost);
//        if (server.sin_addr.s_addr == INADDR_NONE)
//        {
//            host = gethostbyname(this->m_cHost);
//            if (host == NULL)
//            {
//                std::cout << "Unable to resolve server: " << this->m_cHost << std::endl;
//                exit_status=1;
//            }
//            CopyMemory(&server.sin_addr, host->h_addr_list[0], host->h_length);
//        }
//        if (connect(m_sServerSocket, (struct sockaddr *)&server,
//            sizeof(server)) == SOCKET_ERROR)
//        {
//            std::cout << "connect() failed: " <<  WSAGetLastError() << std::endl;
//            return 1;
//        }
//    }
char  szServer[128],          // Server to connect to
      szMessage[1024];        // Message to send to sever
int   iPort     = 5150;  // Port on server to connect to
    WSADATA       wsd;
    SOCKET        sClient;
//    char          szBuffer[DEFAULT_BUFFER];
//    int           ret, i;
    struct sockaddr_in server;
    struct hostent    *host = NULL;
    // Parse the command line and load Winsock
//    ValidateArgs(argc, argv);
    if (WSAStartup(MAKEWORD(2,2), &wsd) != 0)
    {
        printf("Failed to load Winsock library!\n");
        return 1;
    }
    strcpy(szMessage, "dupa");
    sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sClient == INVALID_SOCKET)
    {
        printf("socket() failed: %d\n", WSAGetLastError());
        return 1;
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(iPort);
    server.sin_addr.s_addr = inet_addr(szServer);
    // If the supplied server address wasn't in the form
    // "aaa.bbb.ccc.ddd" it's a hostname, so try to resolve it
    if (server.sin_addr.s_addr == INADDR_NONE)
    {
        host = gethostbyname(szServer);
        if (host == NULL)
        {
            printf("Unable to resolve server: %s\n", szServer);
            return 1;
        }
        CopyMemory(&server.sin_addr, host->h_addr_list[0], host->h_length);
    }
    if (connect(sClient, (struct sockaddr *)&server,
        sizeof(server)) == SOCKET_ERROR)
    {
        printf("connect() failed: %d\n", WSAGetLastError());
        return 1;
    }
// send
// recv
closesocket(sClient);
WSACleanup();
return 0;
//    return exit_status;
}
