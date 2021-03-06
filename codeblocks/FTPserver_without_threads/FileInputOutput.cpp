#include "FileInputOutput.h"

CFileInputOutput::CFileInputOutput()
{

}

CFileInputOutput::~CFileInputOutput()
{

}

int CFileInputOutput::openFile(char* a_filename, int a_mode=0)
{
    int exit_status;
    exit_status=0;
    m_file.open(a_filename);
    if(! m_file.is_open())
    {
        std::cout << "CFileInputOutput::openStream Unable to open file" << std::endl;
        exit_status=1;
    }
    return exit_status;
}

int CFileInputOutput::closeFile()
{
    m_file.close();
    return 0;
}

std::string CFileInputOutput::readFromFile()
{
    std::string data;
    getline(m_file,data);
    return data;
}
