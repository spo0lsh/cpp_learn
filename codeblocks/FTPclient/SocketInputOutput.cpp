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
//    memset(m_cHost, 0, sizeof(m_cHost)); //
//    int   iPort     = 5150;  // Port on server to connect to
    WSADATA       wsd;
//    SOCKET        sClient;
//    char          szBuffer[DEFAULT_BUFFER];
//    int           ret, i;
//    struct sockaddr_in server;
//    struct hostent    *host = NULL;
    // Parse the command line and load Winsock
//    ValidateArgs(argc, argv);
    if (WSAStartup(MAKEWORD(2,2), &wsd) != 0)
    {
        printf("Failed to load Winsock library!\n");
        return 1;
    }
//    strcpy(szMessage, "dupa");
    m_sServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_sServerSocket == INVALID_SOCKET)
    {
        printf("socket() failed: %d\n", WSAGetLastError());
        return 1;
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
            return 1;
        }
        CopyMemory(&server.sin_addr, host->h_addr_list[0], host->h_length);
    }
    if (connect(m_sServerSocket, (struct sockaddr *)&server,
        sizeof(server)) == SOCKET_ERROR)
    {
        printf("connect() failed: %d\n", WSAGetLastError());
        return 1;
    }
// send
// recv
closesocket(m_sServerSocket);
WSACleanup();
return 0;
//    return exit_status;
}
