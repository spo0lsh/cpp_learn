#include "FtpServer.h"


using namespace std;

/**
 * @brief One from two versions of human
 * @deprecated
 * @todo Fix port number
 */
CFtpServer::CFtpServer()
{
    m_host = "0.0.0.0";
    m_port = 8080;
    m_directory = "./";
    m_poolSize = 5;
    m_dbFile = "database.txt";
    std::cout << "CFtpServer::CFtpServer Default constructor of CFtpServer" << std::endl;
}

CFtpServer::~CFtpServer()
{
    std::cout << "CFtpServer::~CFtpServerDefault destructor of CFtpServer" << std::endl;
}

int CFtpServer::startServer(int argc, char *argv[])
{
    int exit_status;
    exit_status=0;
    this->getOptionsFromCommandLine(argc, argv);

    // thread pool
//    std::cout << "CFtpServer::startServer initTrheadPool status " << m_pCThreadPool->initThreadPool(m_poolSize,m_dbFile) << std::endl;
    if(m_pCThreadPool->initThreadPool(m_poolSize,m_dbFile) != 0)
    {
        std::cout << "CFtpServer::startServer m_pCThreadPool->initThreadPool problem" << std::endl;
        exit_status=1;
    }

    // check root directory
    if(this->checkRootDirectory() != 0)
    {
        exit_status=1;
    }

    // socket

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
    }
    return 0;
}

int CFtpServer::checkRootDirectory()
{
    string filename = this->m_directory+"ASTGATGAQGasfas.txt"; // random filename like Sony

    std::cout << "CFtpServer::checkRootDirectory: " << this->m_directory << " filename: " << filename << std::endl;
    int exit_status;
    exit_status=0;
    /* Add check write procedure with "random" filename
    */
    std::ofstream myfile(filename.c_str());
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

void CFtpServer::debugVariable()
{
    std::cout << "CFtpServer::debugVariable host: " << m_host << " port: " << m_port << " directory: " << m_directory << std::endl;
}

