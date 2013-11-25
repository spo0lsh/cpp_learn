#include "FtpServer.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

/**
 * @brief One from two versions of human
 * @deprecated
 * @todo Fix port number
 */
CFtpServer::CFtpServer()
{
    host = "0.0.0.0";
    port = 8080;
    directory = "./";
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
    if(this->checkRootDirectory() != 0)
    {
        exit_status=1;
    }

    return exit_status;
}

int CFtpServer::getOptionsFromCommandLine(int argc, char *argv[])
{
    std::cout << "CFtpServer::getOptionsFromCommandLine" << std::endl;
    if (argc == 4)
    {
        host = argv[1];
        port = atoi(argv[2]);
        directory = argv[3];
    }
    return 0;
}

int CFtpServer::checkRootDirectory()
{
    string filename = this->directory+"ASTGATGAQGasfas.txt";

    std::cout << "CFtpServer::checkRootDirectory: " << this->directory << " filename: " << filename << std::endl;
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
            puts( "File successfully deleted" );
        }
    }
    else
    {
        std::cout << "Problem with work directory: " << this->directory << std::endl;
        exit_status=1;
    }
    return exit_status;
}

void CFtpServer::debugVariable()
{
    std::cout << "host: " << host << " port: " << port << " directory: " << directory << std::endl;
}

