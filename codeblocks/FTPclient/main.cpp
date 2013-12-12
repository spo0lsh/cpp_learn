#include <iostream>
#include "main.h"

using namespace std;
int main(int argc, char *argv[])
{
    int exit_status;
    exit_status=0;

    CFtpClient oFtpClient;
    if(oFtpClient.checkRequireOptions(argc, argv) != 0)
    {
        exit_status=1;
        std::cout << "main: oFtpClient.checkRequireOptions: " << exit_status << std::endl;
    }
    else
    {
        oFtpClient.parsingOptionsForCommand(argc, argv);
        std::cout << "main: oFtpClient.checkRequireOptions: " << exit_status << std::endl;
    }

    return exit_status;
}

//#include <iostream>
//#include <winsock2.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//
//#define DEFAULT_PORT        5150
//#define DEFAULT_BUFFER      2048
//
//using namespace std;
//
//class CgetCommandFromArgv
//{
//    string login, pass, host;
//    int port;
//public:
//    int checkRequireOptions(int , char **);
//    int parsingOptionsForCommand(int , char **);
//    int executeCommand(string, string );
//};
//
//
//int CgetCommandFromArgv::executeCommand(string command, string argument=0)
//{
//    cout << "command: " << command << " argument: " << argument << endl;
//    return 0;
//}
//
//// TODO:
//// generate doxy comments!
//// check for param of command is not commands
//int CgetCommandFromArgv::parsingOptionsForCommand(int argc, char *argv[])
//{
//    int exit_status=0;
//    int found=0;
//    string arg;
//    int i;
//    for(i = 1; i < argc; i++)
//        {
//            arg = argv[i];
//            if (arg == "dir")
//            {
//                cout << "dir" << endl;
//                CgetCommandFromArgv::executeCommand("dir","");
//                found=0;
//            }
//            else if (arg == "del")
//            {
//                if(argv[i+1] != 0)
//                {
//                    cout << "del: " << argv[i+1] << endl;
//                }
//                else
//                {
//                    cout << "del: wrong parameter, skipping" << endl;
//                }
//                found=1;
//            }
//            else if (arg == "put")
//            {
//                if(argv[i+1] != 0)
//                {
//                    cout << "put: " << argv[i+1] << endl;
//                }
//                else
//                {
//                    cout << "put: wrong parameter, skipping" << endl;
//                }
//                found=1;
//            }
//            else if (arg == "get")
//            {
//                if(argv[i+1] != 0)
//                {
//                    cout << "get: " << argv[i+1] << endl;
//                }
//                else
//                {
//                    cout << "get: wrong parameter, skipping" << endl;
//                }
//                found=1;
//            }
//            else if (arg == "login")
//            {
//                cout << "login" << endl;
//                found=1;
//            }
//            else if (arg == "pass")
//            {
//                cout << "pass" << endl;
//                found=1;
//            }
//            else if (arg == "host")
//            {
//                cout << "host" << endl;
//                found=1;
//            }
//            else if (arg == "port")
//            {
//                cout << "port" << endl;
//                found=1;
//            }
//            else
//            {
//                cout << "Unknow argument: " << arg <<  " ";
//                cout << endl;
//                found=0;
//            }
//            i=i+found;
//        }
//    return exit_status;
//}
//
//int CgetCommandFromArgv::checkRequireOptions(int argc, char *argv[])
//{
//    int exit_status=0;
//    int i=0;
//    string arg;
//    int needed=0;
//    for(i = 1; i < argc; i++)
//    {
//        arg = argv[i];
//        if (arg == "login")
//        {
//            if(argv[i+1] != 0)
//            {
//                cout << "login: " << argv[i+1] << endl;
//                needed=needed+4;
//            }
//        }
//        else if (arg == "pass")
//        {
//            if(argv[i+1] != 0)
//            {
//                cout << "pass: " << argv[i+1] << endl;
//                needed=needed+2;
//            }
//        }
//        else if (arg == "host")
//        {
//            if(argv[i+1] != 0)
//            {
//                cout << "host: " << argv[i+1] << endl;
//                needed=needed+1;
//            }
//        }
//        else
//        {
//        }
//    }
//    if(needed != 7)
//    {
//        cout << "Need login, pass and host" << endl;
//        cout << "Example" << argv[0] << " login your_login pass your_password host server_host" << endl;
//        exit_status=1;
//    }
//    else
//    {
//        exit_status=0;
//    }
//    return exit_status;
//}
//
//int main(int argc, char *argv[])
//{
//    int exit_status=0;
//    CgetCommandFromArgv *pCgetCommandFromArgv = new CgetCommandFromArgv;
//    if(pCgetCommandFromArgv->checkRequireOptions(argc, argv) != 0)
//    {
//        exit_status=1;
//    }
//    else
//    {
//        pCgetCommandFromArgv->parsingOptionsForCommand(argc, argv);
//        exit_status=0;
//    }
//    return exit_status;
//}
//


///*******************************************************
//*     MYCPLUS Sample Code - http://www.mycplus.com     *
//*                                                     *
//*   This code is made available as a service to our   *
//*      visitors and is provided strictly for the      *
//*               purpose of illustration.              *
//*                                                     *
//* Please direct all inquiries to saqib at mycplus.com *
//*******************************************************/
//
//// Module Name: Client.c
////
//// Description:
////    This sample is the echo client. It connects to the TCP server,
////    sends data, and reads data back from the server.
////
//// Compile:
////    cl -o Client Client.c ws2_32.lib
////
//// Command Line Options:
////    client [-p:x] [-s:IP] [-n:x] [-o]
////           -p:x      Remote port to send to
////           -s:IP     Server's IP address or hostname
////           -n:x      Number of times to send message
////           -o        Send messages only; don't receive
////
//#include <winsock2.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <iostream>
//
//#define DEFAULT_COUNT       20
//#define DEFAULT_PORT        5150
//#define DEFAULT_BUFFER      2048
//
//
//#define DEFAULT_MESSAGE      "AAaaaaa"
//#define DEFAULT_MESSAGE1     "USER login3"
//#define DEFAULT_MESSAGE2     "PASS password3"
//#define DEFAULT_MESSAGE3     "QUIT"
//#define DEFAULT_MESSAGE4     "RETR dupa.txt"
//#define DEFAULT_MESSAGE5     "SIZE dupa.txt"
//#define DEFAULT_MESSAGE6     "STOR dupa.txt"
//#define DEFAULT_MESSAGE7     "DELE dupa2.txt"
//#define DEFAULT_MESSAGE8     "LIST"
//#define DEFAULT_MESSAGE9     "NOOP"
//
//
//char  szServer[128],          // Server to connect to
//      szMessage[1024];        // Message to send to sever
//int   iPort     = DEFAULT_PORT;  // Port on server to connect to
//DWORD dwCount   = DEFAULT_COUNT; // Number of times to send message
//BOOL  bSendOnly = FALSE;         // Send data only; don't receive
//
////
//// Function: usage:
////
//// Description:
////    Print usage information and exit
////
//void usage()
//{
//    printf("usage: client [-p:x] [-s:IP] [-n:x] [-o]\n\n");
//    printf("       -p:x      Remote port to send to\n");
//    printf("       -s:IP     Server's IP address or hostname\n");
//    printf("       -n:x      Number of times to send message\n");
//    printf("       -o        Send messages only; don't receive\n");
//    ExitProcess(1);
//}
//
////
//// Function: ValidateArgs
////
//// Description:
////    Parse the command line arguments, and set some global flags
////    to indicate what actions to perform
////
//void ValidateArgs(int argc, char **argv)
//{
//    int                i;
//
//    for(i = 1; i < argc; i++)
//    {
//        if ((argv[i][0] == '-') || (argv[i][0] == '/'))
//        {
//            switch (tolower(argv[i][1]))
//            {
//                case 'p':        // Remote port
//                    if (strlen(argv[i]) > 3)
//                        iPort = atoi(&argv[i][3]);
//                    break;
//                case 's':       // Server
//                    if (strlen(argv[i]) > 3)
//                        strcpy(szServer, &argv[i][3]);
//                    break;
//                case 'n':       // Number of times to send message
//                    if (strlen(argv[i]) > 3)
//                        dwCount = atol(&argv[i][3]);
//                    break;
//                case 'o':       // Only send message; don't receive
//                    bSendOnly = TRUE;
//                    break;
//                default:
//                    usage();
//                    break;
//            }
//        }
//    }
//}
//
////
//// Function: main
////
//// Description:
////    Main thread of execution. Initialize Winsock, parse the
////    command line arguments, create a socket, connect to the
////    server, and then send and receive data.
////
//int main(int argc, char **argv)
//{
//    WSADATA       wsd;
//    SOCKET        sClient;
//    char          szBuffer[DEFAULT_BUFFER];
//    int           ret;
//    unsigned int  i;
//    struct sockaddr_in server;
//    struct hostent    *host = NULL;
//
//    // Parse the command line and load Winsock
//    //
//    ValidateArgs(argc, argv);
//    if (WSAStartup(MAKEWORD(2,2), &wsd) != 0)
//    {
//        printf("Failed to load Winsock library!\n");
//        return 1;
//    }
//    /// !!!
////    strcpy(szMessage, DEFAULT_MESSAGE); /// 1-9
//    //
//    // Create the socket, and attempt to connect to the server
//    //
//    sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//    if (sClient == INVALID_SOCKET)
//    {
//        printf("socket() failed: %d\n", WSAGetLastError());
//        return 1;
//    }
//    server.sin_family = AF_INET;
//    server.sin_port = htons(iPort);
//    server.sin_addr.s_addr = inet_addr(szServer);
//    //
//    // If the supplied server address wasn't in the form
//    // "aaa.bbb.ccc.ddd" it's a hostname, so try to resolve it
//    //
//    if (server.sin_addr.s_addr == INADDR_NONE)
//    {
//        host = gethostbyname(szServer);
//        if (host == NULL)
//        {
//            printf("Unable to resolve server: %s\n", szServer);
//            return 1;
//        }
//        CopyMemory(&server.sin_addr, host->h_addr_list[0],
//            host->h_length);
//    }
//    if (connect(sClient, (struct sockaddr *)&server,
//        sizeof(server)) == SOCKET_ERROR)
//    {
//        printf("connect() failed: %d\n", WSAGetLastError());
//        return 1;
//    }
//    // Send and receive data
//    //
//    dwCount=1;
//    for(i = 0; i < dwCount; i++)
//    {
//        strcpy(szMessage, DEFAULT_MESSAGE1); /// 1-9
//        ret = send(sClient, szMessage, strlen(szMessage), 0);
//        if (ret == 0)
//            break;
//        else if (ret == SOCKET_ERROR)
//        {
//            printf("send() failed: %d\n", WSAGetLastError());
//            break;
//        }
////        std::cout << "[SEND] " << ret << " bytes: " << DEFAULT_MESSAGE1 << std::endl;
//        std::cout << "[SEND] " << ret << " bytes: " << DEFAULT_MESSAGE1 << std::endl;
//        //
//        if (!bSendOnly)
//        {
//            ret = recv(sClient, szBuffer, DEFAULT_BUFFER, 0);
//            if (ret == 0)        // Graceful close
//                break;
//            else if (ret == SOCKET_ERROR)
//            {
//                printf("recv() failed: %d\n", WSAGetLastError());
//                break;
//            }
//            szBuffer[ret] = '\0';
//            printf("RECV [%d bytes]: '%s'\n", ret, szBuffer);
//           }
////}
//    }
//
//    for(i = 0; i < dwCount; i++)
//    {
//        strcpy(szMessage, DEFAULT_MESSAGE2); /// 1-9
//        ret = send(sClient, szMessage, strlen(szMessage), 0);
//        if (ret == 0)
//            break;
//        else if (ret == SOCKET_ERROR)
//        {
//            printf("send() failed: %d\n", WSAGetLastError());
//            break;
//        }
//        std::cout << "[SEND] " << ret << " bytes: " << DEFAULT_MESSAGE2 << std::endl;
//        //
//        if (!bSendOnly)
//        {
//            ret = recv(sClient, szBuffer, DEFAULT_BUFFER, 0);
//            if (ret == 0)        // Graceful close
//                break;
//            else if (ret == SOCKET_ERROR)
//            {
//                printf("recv() failed: %d\n", WSAGetLastError());
//                break;
//            }
//            szBuffer[ret] = '\0';
//            printf("RECV [%d bytes]: '%s'\n", ret, szBuffer);
//           }
////}
//    }
////    for(i = 0; i < dwCount; i++)
////    {
////        strcpy(szMessage, DEFAULT_MESSAGE3); /// 1-9
////        ret = send(sClient, szMessage, strlen(szMessage), 0);
////        if (ret == 0)
////            break;
////        else if (ret == SOCKET_ERROR)
////        {
////            printf("send() failed: %d\n", WSAGetLastError());
////            break;
////        }
////        std::cout << "[SEND] " << ret << " bytes: " << DEFAULT_MESSAGE3 << std::endl;
////        //
////        if (!bSendOnly)
////        {
////            ret = recv(sClient, szBuffer, DEFAULT_BUFFER, 0);
////            if (ret == 0)        // Graceful close
////                break;
////            else if (ret == SOCKET_ERROR)
////            {
////                printf("recv() failed: %d\n", WSAGetLastError());
////                break;
////            }
////            szBuffer[ret] = '\0';
////            printf("RECV [%d bytes]: '%s'\n", ret, szBuffer);
////           }
//////}
////    }
//    for(i = 0; i < dwCount; i++)
//    {
//        strcpy(szMessage, DEFAULT_MESSAGE4); /// 1-9
//        ret = send(sClient, szMessage, strlen(szMessage), 0);
//        if (ret == 0)
//            break;
//        else if (ret == SOCKET_ERROR)
//        {
//            printf("send() failed: %d\n", WSAGetLastError());
//            break;
//        }
//        std::cout << "[SEND] " << ret << " bytes: " << DEFAULT_MESSAGE4 << std::endl;
//        //
//        if (!bSendOnly)
//        {
//            ret = recv(sClient, szBuffer, DEFAULT_BUFFER, 0);
//            if (ret == 0)        // Graceful close
//                break;
//            else if (ret == SOCKET_ERROR)
//            {
//                printf("recv() failed: %d\n", WSAGetLastError());
//                break;
//            }
//            szBuffer[ret] = '\0';
//            printf("RECV [%d bytes]: '%s'\n", ret, szBuffer);
//           }
////}
//    }
//    for(i = 0; i < dwCount; i++)
//    {
//        strcpy(szMessage, DEFAULT_MESSAGE5); /// 1-9
//        ret = send(sClient, szMessage, strlen(szMessage), 0);
//        if (ret == 0)
//            break;
//        else if (ret == SOCKET_ERROR)
//        {
//            printf("send() failed: %d\n", WSAGetLastError());
//            break;
//        }
//        std::cout << "[SEND] " << ret << " bytes: " << DEFAULT_MESSAGE5 << std::endl;
//        //
//        if (!bSendOnly)
//        {
//            ret = recv(sClient, szBuffer, DEFAULT_BUFFER, 0);
//            if (ret == 0)        // Graceful close
//                break;
//            else if (ret == SOCKET_ERROR)
//            {
//                printf("recv() failed: %d\n", WSAGetLastError());
//                break;
//            }
//            szBuffer[ret] = '\0';
//            printf("RECV [%d bytes]: '%s'\n", ret, szBuffer);
//           }
////}
//    }
//    for(i = 0; i < dwCount; i++)
//    {
//        strcpy(szMessage, DEFAULT_MESSAGE6); /// 1-9
//        ret = send(sClient, szMessage, strlen(szMessage), 0);
//        if (ret == 0)
//            break;
//        else if (ret == SOCKET_ERROR)
//        {
//            printf("send() failed: %d\n", WSAGetLastError());
//            break;
//        }
//        std::cout << "[SEND] " << ret << " bytes: " << DEFAULT_MESSAGE6 << std::endl;
//        //
//        if (!bSendOnly)
//        {
//            ret = recv(sClient, szBuffer, DEFAULT_BUFFER, 0);
//            if (ret == 0)        // Graceful close
//                break;
//            else if (ret == SOCKET_ERROR)
//            {
//                printf("recv() failed: %d\n", WSAGetLastError());
//                break;
//            }
//            szBuffer[ret] = '\0';
//            printf("RECV [%d bytes]: '%s'\n", ret, szBuffer);
//           }
////}
//    }
//    for(i = 0; i < dwCount; i++)
//    {
//        strcpy(szMessage, DEFAULT_MESSAGE7); /// 1-9
//        ret = send(sClient, szMessage, strlen(szMessage), 0);
//        if (ret == 0)
//            break;
//        else if (ret == SOCKET_ERROR)
//        {
//            printf("send() failed: %d\n", WSAGetLastError());
//            break;
//        }
//        std::cout << "[SEND] " << ret << " bytes: " << DEFAULT_MESSAGE7 << std::endl;
//        //
//        if (!bSendOnly)
//        {
//            ret = recv(sClient, szBuffer, DEFAULT_BUFFER, 0);
//            if (ret == 0)        // Graceful close
//                break;
//            else if (ret == SOCKET_ERROR)
//            {
//                printf("recv() failed: %d\n", WSAGetLastError());
//                break;
//            }
//            szBuffer[ret] = '\0';
//            printf("RECV [%d bytes]: '%s'\n", ret, szBuffer);
//           }
////}
//    }
//    for(i = 0; i < dwCount; i++)
//    {
//        strcpy(szMessage, DEFAULT_MESSAGE8); /// 1-9
//        ret = send(sClient, szMessage, strlen(szMessage), 0);
//        if (ret == 0)
//            break;
//        else if (ret == SOCKET_ERROR)
//        {
//            printf("send() failed: %d\n", WSAGetLastError());
//            break;
//        }
//        std::cout << "[SEND] " << ret << " bytes: " << DEFAULT_MESSAGE8 << std::endl;
//        //
//        if (!bSendOnly)
//        {
//            ret = recv(sClient, szBuffer, DEFAULT_BUFFER, 0);
//            if (ret == 0)        // Graceful close
//                break;
//            else if (ret == SOCKET_ERROR)
//            {
//                printf("recv() failed: %d\n", WSAGetLastError());
//                break;
//            }
//            szBuffer[ret] = '\0';
//            printf("RECV [%d bytes]: '%s'\n", ret, szBuffer);
//           }
////}
//    }
//    for(i = 0; i < dwCount; i++)
//    {
//        strcpy(szMessage, DEFAULT_MESSAGE9); /// 1-9
//        ret = send(sClient, szMessage, strlen(szMessage), 0);
//        if (ret == 0)
//            break;
//        else if (ret == SOCKET_ERROR)
//        {
//            printf("send() failed: %d\n", WSAGetLastError());
//            break;
//        }
//        std::cout << "[SEND] " << ret << " bytes: " << DEFAULT_MESSAGE9 << std::endl;
//        //
//        if (!bSendOnly)
//        {
//            ret = recv(sClient, szBuffer, DEFAULT_BUFFER, 0);
//            if (ret == 0)        // Graceful close
//                break;
//            else if (ret == SOCKET_ERROR)
//            {
//                printf("recv() failed: %d\n", WSAGetLastError());
//                break;
//            }
//            szBuffer[ret] = '\0';
//            printf("RECV [%d bytes]: '%s'\n", ret, szBuffer);
//           }
////}
//    }
//    for(i = 0; i < dwCount; i++)
//    {
//        strcpy(szMessage, DEFAULT_MESSAGE3); /// 1-9
//        ret = send(sClient, szMessage, strlen(szMessage), 0);
//        if (ret == 0)
//            break;
//        else if (ret == SOCKET_ERROR)
//        {
//            printf("send() failed: %d\n", WSAGetLastError());
//            break;
//        }
//        std::cout << "[SEND] " << ret << " bytes: " << DEFAULT_MESSAGE3 << std::endl;
//        //
//        if (!bSendOnly)
//        {
//            ret = recv(sClient, szBuffer, DEFAULT_BUFFER, 0);
//            if (ret == 0)        // Graceful close
//                break;
//            else if (ret == SOCKET_ERROR)
//            {
//                printf("recv() failed: %d\n", WSAGetLastError());
//                break;
//            }
//            szBuffer[ret] = '\0';
//            printf("RECV [%d bytes]: '%s'\n", ret, szBuffer);
//           }
////}
//    }
//
//    closesocket(sClient);
//
//    WSACleanup();
//    return 0;
//}
///************************ End of Client ********************/
