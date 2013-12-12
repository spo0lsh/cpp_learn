#include "FileInputOutput.h"

CFileInputOutput::CFileInputOutput()
{

}

CFileInputOutput::~CFileInputOutput()
{

}

int CFileInputOutput::openFileNG(char* a_filename, int a_mode=0)
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
        if( (m_fStream = _fsopen( a_filename, "rt", _SH_DENYWR )) != NULL )
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
        if( (m_fStream = _fsopen( a_filename, "wt", _SH_DENYRD )) != NULL )
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
        if( (m_fStream = _fsopen( a_filename, "rt", _SH_DENYWR )) != NULL )
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
        if( (m_fStream = _fsopen( a_filename, "wt", _SH_DENYWR )) != NULL )
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
    return exit_status;
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

int CFileInputOutput::closeFileNG()
{
    fclose(m_fStream);;
    return 0;
}

void CFileInputOutput::readFile(int a_bytes)
{
    fgets(m_pData, a_bytes, m_fStream);
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
