#include "FileInputOutput.h"

int CFileInputOutput::openStream(char* filename, int mode=0)
{
    int exit_status;
    exit_status=0;
    m_file.open(filename);
    if(! m_file.is_open())
    {
        std::cout << "Unable to open file" << std::endl;
        exit_status=1;
    }
    return exit_status;
}

int CFileInputOutput::closeStream()
{
    m_file.close();
    return 0;
}

std::string CFileInputOutput::readStream()
{
    std::string data;
    getline(m_file,data);
    return data;
}
