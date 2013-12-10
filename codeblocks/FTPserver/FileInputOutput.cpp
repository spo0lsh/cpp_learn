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

std::string CFileInputOutput::readLineFromFile()
{
    std::string data;
    getline(m_file,data);
    return data;
}

int CFileInputOutput::checkFileSize()
{
    int exit_status=-1;
    long begin;
    long end;
//    fseek( &m_file, 0, SEEK_END ); //std::fstream m_file;
    begin = m_file.tellg();
    m_file.seekg (0, std::ios::end);
    end = m_file.tellg();
    exit_status = end-begin;
    return exit_status;
}
