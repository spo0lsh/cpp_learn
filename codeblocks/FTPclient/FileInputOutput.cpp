#include "FileInputOutput.h"

CFileInputOutput::CFileInputOutput()
{

}

CFileInputOutput::~CFileInputOutput()
{

}

int CFileInputOutput::openFile(char* a_filename, int a_mode)
{
    int exit_status=0;
    if( (m_fStream = _fsopen( a_filename, "rb", _SH_DENYWR )) != NULL )
    {
        std::cout << "CFileInputOutput::openFile OK rt _SH_DENYWR : " << a_filename << std::endl;
    }
    else
    {
        std::cout << "CFileInputOutput::openFile KO rt _SH_DENYWR : " << a_filename << std::endl;
        exit_status=1;
    }
    return exit_status;
}

int CFileInputOutput::closeFile()
{
    fclose(m_fStream);;
    return 0;
}

int CFileInputOutput::checkFileSize()
{
    fseek(m_fStream, 0, SEEK_END); // seek to end of file
    int size = ftell(m_fStream); // get current file pointer
    fseek(m_fStream, 0, SEEK_SET); // seek back to beginning of file
    // proceed with allocating memory and reading the file
    return size;
}

int CFileInputOutput::readFile(int a_bytes)
{
    int size;
    memset(sBuffer, 0, sizeof(sBuffer));
    size=fread(sBuffer,sizeof(char),a_bytes,this->m_fStream);
    return size;
}
