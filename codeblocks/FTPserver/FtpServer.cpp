#include "FtpServer.h"


using namespace std;

/**
 * @brief One from two versions of human
 * @deprecated
 * @todo Fix port number
 */
CFtpServer::CFtpServer()
{
    mp_ListenSocket = INVALID_SOCKET;
    mp_ClientSocket = INVALID_SOCKET;
    // default settings
    m_host = (char*)"0.0.0.0";
    m_port = 5150;
    m_directory = "./";
    m_poolSize = 4;
    m_dbFile = "database.txt";
//    m_ThreadPool = new CThreadPool(m_poolSize);
}
// double alloc cftpserver
CFtpServer::CFtpServer(int a_poolSize)
{
    mp_ListenSocket = INVALID_SOCKET;
    mp_ClientSocket = INVALID_SOCKET;
    // default settings
    m_host = (char*)"0.0.0.0";
    m_port = 5150;
    m_directory = "./";
    m_poolSize = 4; //a_poolSize;
    m_dbFile = "database.txt";
//    m_ThreadPool = new CThreadPool(a_poolSize);
}

CFtpServer::~CFtpServer()
{
	delete m_ThreadPool; // added
}

int CFtpServer::startServer(int argc, char *argv[])
{
    int exit_status;
    exit_status=0;
    this->getOptionsFromCommandLine(argc, argv);

    // create threads
    m_ThreadPool = new CThreadPool(m_poolSize);


    // thread pool
    if(m_ThreadPool->initThreadPool(m_poolSize,m_dbFile) != 0)
    {
        std::cout << "CFtpServer::startServer m_ThreadPool.initThreadPool problem" << std::endl;
        exit_status=1;
    }

    // check root directory
    if(exit_status != 1)
    {
        if(this->checkRootDirectory() != 0)
        {
            exit_status=1;
        }
        else
        {
//added
        }
    }
    else
    {

    }

    // socket
    mp_ListenSocket = INVALID_SOCKET;
    CSocketInputOutput *po_SocketInputOutput = new CSocketInputOutput; //delete
    mp_ListenSocket=po_SocketInputOutput->openSocket(m_host, m_port);
    if(mp_ListenSocket == 1)
    {
        exit_status = 1;
    }
    else
    {

    }

    return exit_status;
}

int CFtpServer::getOptionsFromCommandLine(int argc, char *argv[])
{
    std::cout << "CFtpServer::getOptionsFromCommandLine" << std::endl;
    if (argc == 6)
    {
        try
        {
            m_host = argv[1];
            m_port = atoi(argv[2]);
            m_directory = argv[3];
            m_poolSize = atoi(argv[4]);
            m_dbFile = argv[5];
//            m_ThreadPool = new CThreadPool(m_poolSize);
        }
        catch(...) {
            //cout << "Error: " << e.what() << endl;
            std::cout << "Example: " << argv[0] << " 0.0.0.0 6667 c:\\temp 10 c:\\temp\\database.txt" << std::endl;
        }
    }
    else
    {
        std::cout << "CFtpServer::getOptionsFromCommandLine FtpServer using default settings!" << std::endl;
        std::cout << "CFtpServer::getOptionsFromCommandLine Example: " << argv[0] << " 0.0.0.0 6667 c:\\temp 10 c:\\temp\\database.txt" << std::endl;
//        m_ThreadPool = new CThreadPool; //need fix
    }
    return 0;
}

int CFtpServer::checkRootDirectory()
{
    string filename = this->m_directory+"ASTGATGAQGasfas.txt"; // random filename like Sony

    std::cout << "CFtpServer::checkRootDirectory: " << this->m_directory << " filename: " << filename << std::endl;
    int exit_status; // =0;
    exit_status=0;
    /* Add check write procedure with "random" filename
    */
    std::ofstream myfile(filename.c_str()); //design miss
    if (myfile.is_open())
    {
        myfile << "This is a line.\n";
        myfile.close();
        if( remove(filename.c_str()) != 0 )
        {
            perror( "CFtpServer::checkRootDirectory Error deleting file" );
            exit_status=1;
        }
        else
        {
            std::cout << "CFtpServer::checkRootDirectory File successfully deleted" << std::endl;
        }
    }
    else
    {
        std::cout << "CFtpServer::checkRootDirectory Problem with work directory: " << this->m_directory << std::endl;
        exit_status=1;
    }
    return exit_status;
}

void CFtpServer::acceptConnection()
{
    std::cout << "CFtpServer::acceptConnection waiting for client" << std::endl;
    struct sockaddr_in client;
    int iAddrSize = sizeof(client);
    mp_ClientSocket = accept(mp_ListenSocket, (struct sockaddr *)&client, &iAddrSize);
    if (mp_ClientSocket == INVALID_SOCKET)
    {
        std::cout << "CFtpServer::acceptConnection accept() failed: " << WSAGetLastError() << std::endl;
    }
    else
    {
        std::cout << "CFtpServer::acceptConnection Accepted client: " << inet_ntoa(client.sin_addr) << ":" << ntohs(client.sin_port) << std::endl;
        if(m_ThreadPool->addTaskToQueue(mp_ClientSocket) != 0)
        {
            std::cout << "CFtpServer::acceptConnection->addTaskToQueue problem." << std::endl;
            closesocket(mp_ClientSocket); // close connection (need socket class!)
        }
        else
        {
            m_ThreadPool->WakeUpFreeThread();
        }
    }
}

void CFtpServer::debugVariable()
{
    std::cout << "CFtpServer::debugVariable host: " << m_host << " port: " << m_port << " directory: " << m_directory << std::endl;
}

