#ifndef FILEINPUTOUTPUT_H_INCLUDED
#define FILEINPUTOUTPUT_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>

class CFileInputOutput
{
public:

    int openStream(char* , int );
    int closeStream();
    std::string readStream();
    int writeStream(std::string );

    std::string m_data;
    //std::ifstream *m_file;
private:
    int m_mode;
    std::fstream m_file;

};

#endif // FILEINPUTOUTPUT_H_INCLUDED
