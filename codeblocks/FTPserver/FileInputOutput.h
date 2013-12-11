#ifndef FILEINPUTOUTPUT_H_INCLUDED
#define FILEINPUTOUTPUT_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>

class CFileInputOutput
{
public:
    CFileInputOutput();
    ~CFileInputOutput();
    int openFile(char* , int );
    int closeFile();
    std::string readLineFromFile();
    int writeToFile(std::string );
    int checkFileSize();

    std::string m_data;
private:
    int m_mode;
    std::fstream m_file;

};

#endif // FILEINPUTOUTPUT_H_INCLUDED
