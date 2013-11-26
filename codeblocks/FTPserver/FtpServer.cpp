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
    m_dbFile = "database.txt";
    std::cout << "Default constructor of CFtpServer" << std::endl;
}

CFtpServer::~CFtpServer()
{
    std::cout << "Default destructor of CFtpServer" << std::endl;
}

int CFtpServer::startServer(int argc, char *argv[])
{
    int exit_status;
    exit_status=0;
    this->getOptionsFromCommandLine(argc, argv);

    // database
    this->mpr_DB=m_pDatabaseOperations->createDatabaseStructure();
    // debug
    m_pDatabaseOperations->debugPrint(this->mpr_DB);

    // thread pool
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
    if (argc == 5)
    {
        m_host = argv[1];
        m_port = atoi(argv[2]);
        m_directory = argv[3];
        m_dbFile = argv[4];
    }
    return 0;
}

int CFtpServer::checkRootDirectory()
{
    string filename = this->m_directory+"ASTGATGAQGasfas.txt";

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
            perror( "Error deleting file" );
            exit_status=1;
        }
        else
        {
            std::cout << "File successfully deleted" << std::endl;
        }
    }
    else
    {
        std::cout << "Problem with work directory: " << this->m_directory << std::endl;
        exit_status=1;
    }
    return exit_status;
}

void CFtpServer::debugVariable()
{
    std::cout << "host: " << m_host << " port: " << m_port << " directory: " << m_directory << std::endl;
}

