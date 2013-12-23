#include <iostream>
#include <string>
#include <share.h>
#include "FileInputOutput.h"

CFileInputOutput::CFileInputOutput()
{
    m_fStream=NULL;
}

CFileInputOutput::~CFileInputOutput()
{

}

int CFileInputOutput::openFile(char* a_filename, int a_mode=0)
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
            std::cout << "CFileInputOutput::OpenFileNG OK rb _SH_DENYWR : " << a_filename << std::endl;
        }
        else
        {
            std::cout << "CFileInputOutput::OpenFileNG KO rb _SH_DENYWR : " << a_filename << std::endl;
            exit_status=1;
        }
        break;
    case 1:
        if( (m_fStream = _fsopen( a_filename, "wb", _SH_DENYRD )) != NULL )
        {
            std::cout << "CFileInputOutput::OpenFileNG OK wb _SH_DENYRD : " << a_filename << std::endl;
        }
        else
        {
            std::cout << "CFileInputOutput::OpenFileNG KO wb _SH_DENYRD : " << a_filename << std::endl;
            exit_status=1;
        }
        break;
    case 2:
        if( (m_fStream = _fsopen( a_filename, "rb", _SH_DENYWR )) != NULL )
        {
            std::cout << "CFileInputOutput::OpenFileNG OK rb _SH_DENYWR : " << a_filename << std::endl;
        }
        else
        {
            std::cout << "CFileInputOutput::OpenFileNG KO rb _SH_DENYWR : " << a_filename << std::endl;
            exit_status=1;
        }
        break;
     case 3:
        if( (m_fStream = _fsopen( a_filename, "wb", _SH_DENYWR )) != NULL )
        {
            std::cout << "CFileInputOutput::OpenFileNG OK wb _SH_DENYWR : " << a_filename << std::endl;
        }
        else
        {
            std::cout << "CFileInputOutput::OpenFileNG KO wb _SH_DENYWR : " << a_filename << std::endl;
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

int CFileInputOutput::openFile(char* a_filename)
{
    std::cout << "CFileInputOutput::openFile(char *)" << std::endl;
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

//int CFileInputOutput::closeFile()
//{
//    m_file.close();
//    return 0;
//}

int CFileInputOutput::closeFile()
{
    std::cout << "CFileInputOutput::closeFile ";
    if(m_fStream != 0)
    {
        std::cout << "m_fStream " << m_fStream << std::endl;
        fclose(m_fStream);
        m_fStream=NULL;
    }
    else if(m_file != 0)
    {
        std::cout << "m_file " << m_file << std::endl;
        m_file.close();
//        m_file=NULL;
    }
    else
    {
        std::cout << "all handle are NULL" << std::endl;
    }
//    fclose(m_fStream);
//    m_file.close();
    return 0;
}

//void CFileInputOutput::readFile(int a_bytes)
//{
//    fgets(m_pData, a_bytes, m_fStream);
//}

int CFileInputOutput::readFile(int a_bytes)
{
//    int size;
    memset(sBuffer, 0, sizeof(sBuffer));
    this->bytesReaded=fread(sBuffer,sizeof(char),a_bytes,this->m_fStream);
//    this->bytesReaded=size;
    return this->bytesReaded;
}

void CFileInputOutput::writeToFile(int a_bytes)
{
    std::cout << "CFileInputOutput::writeToFile(int) bytes: " << a_bytes << std::endl;
    fwrite(this->sBuffer , sizeof(char), a_bytes, this->m_fStream);
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

std::string CFileInputOutput::readLineFromFile()
{
    std::string data;
    getline(m_file,data);
    return data;
}

int CFileInputOutput::checkFileSize()
{
    int exit_status=-1;
//    long begin;
//    long end;
////    fseek( &m_file, 0, SEEK_END ); //std::fstream m_file;
//    begin = m_file.tellg();
//    m_file.seekg (0, std::ios::end);
//    end = m_file.tellg();
//    exit_status = end-begin;
    fseek(m_fStream, 0, SEEK_END); // seek to end of file
    int size = ftell(m_fStream); // get current file pointer
    fseek(m_fStream, 0, SEEK_SET); // seek back to beginning of file
    // proceed with allocating memory and reading the file
    std::cout << "CFileInputOutput::checkFileSize: " << size << std::endl;
    exit_status=size;
    return exit_status;
}
