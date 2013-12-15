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
    // mode
    // 0 - _SH_DENYWR - Denies write access to the file.
    // 1 - _SH_DENYRD - Denies read access to the file.
    // 2 - _SH_DENYRW - Denies read and write access to the file. READ
    // 3 - _SH_DENYRW - Denies read and write access to the file. WRITE

    switch(a_mode)
    {
    case 0:
        if( (m_fStream = _fsopen( a_filename, "rb", _SH_DENYWR )) != NULL )
        {
            std::cout << "CFileInputOutput::OpenFileNG OK rt _SH_DENYWR : " << a_filename << std::endl;
        }
        else
        {
            std::cout << "CFileInputOutput::OpenFileNG KO rt _SH_DENYWR : " << a_filename << std::endl;
            exit_status=1;
        }
        break;
    case 1:
        if( (m_fStream = _fsopen( a_filename, "wb", _SH_DENYRD )) != NULL )
        {
            std::cout << "CFileInputOutput::OpenFileNG OK wt _SH_DENYRD : " << a_filename << std::endl;
        }
        else
        {
            std::cout << "CFileInputOutput::OpenFileNG KO wt _SH_DENYRD : " << a_filename << std::endl;
            exit_status=1;
        }
        break;
    case 2:
        if( (m_fStream = _fsopen( a_filename, "rb", _SH_DENYWR )) != NULL )
        {
            std::cout << "CFileInputOutput::OpenFileNG OK rt _SH_DENYWR : " << a_filename << std::endl;
        }
        else
        {
            std::cout << "CFileInputOutput::OpenFileNG KO rt _SH_DENYWR : " << a_filename << std::endl;
            exit_status=1;
        }
        break;
     case 3:
        if( (m_fStream = _fsopen( a_filename, "wb", _SH_DENYWR )) != NULL )
        {
            std::cout << "CFileInputOutput::OpenFileNG OK wt _SH_DENYWR : " << a_filename << std::endl;
        }
        else
        {
            std::cout << "CFileInputOutput::OpenFileNG KO wt _SH_DENYWR : " << a_filename << std::endl;
            exit_status=1;
        }
        break;
    default:
        std::cout << "CFileInputOutput::OpenFileNG - unsupported open mode" << std::endl;
        exit_status=1;
        break;
    }
//    if( (m_fStream = _fsopen( a_filename, "rb", _SH_DENYWR )) != NULL )
//    {
//        std::cout << "CFileInputOutput::openFile OK rt _SH_DENYWR : " << a_filename << std::endl;
//    }
//    else
//    {
//        std::cout << "CFileInputOutput::openFile KO rt _SH_DENYWR : " << a_filename << std::endl;
//        exit_status=1;
//    }
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

void CFileInputOutput::writeToFile(char *a_sBuffor)
{
//    fputs(a_sBuffor,m_fStream);
    fprintf (m_fStream, "%s",a_sBuffor);
//    std::cout << "CFileInputOutput::writeToFile " << a_sBuffor << " " << a_bufsize << std::endl;
//    fwrite (a_sBuffor , sizeof(char), a_bufsize, m_fStream);
}

void CFileInputOutput::writeToFile(char *a_sBuffor, int a_bufsize)
{
//    fputs(a_sBuffor,m_fStream);
    std::cout << "CFileInputOutput::writeToFile " << a_sBuffor << " " << a_bufsize << std::endl;
    fwrite (a_sBuffor , sizeof(char), a_bufsize, m_fStream);
}
