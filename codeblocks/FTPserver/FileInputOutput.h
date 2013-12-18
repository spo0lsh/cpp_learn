#ifndef FILEINPUTOUTPUT_H_INCLUDED
#define FILEINPUTOUTPUT_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include <share.h>
#include <memory.h>
#include <dirent.h>
#include "SocketInputOutput.h"

class CFileInputOutput
{
public:
    CFileInputOutput();
    ~CFileInputOutput();
    int openFile(char* );
    int openFile(char* , int );
    int closeFile();
    int closeFileNG();
    std::string readLineFromFile();
    int readFile(int );
    void writeToFile(char* );
    void writeToFile(char*,int );
    int checkFileSize();

    std::string m_data;
    char *m_pData;
    char sBuffer[DEFAULT_BUFFER];
    int bytesReaded;
private:
    int m_mode;
    std::fstream m_file;
    FILE *m_fStream;

};

#endif // FILEINPUTOUTPUT_H_INCLUDED
