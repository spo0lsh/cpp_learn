#ifndef FTPCLIENT_H_INCLUDED
#define FTPCLIENT_H_INCLUDED

#include <string>
#include <iostream>
#include "ExecuteCommand.h"

class CFtpClient
{
public:
    CFtpClient();
    ~CFtpClient();
    int checkRequireOptions(int , char **);
    int parsingOptionsForCommand(int , char **);
    int executeCommand(std::string, std::string );
protected:

private:
    CExecuteCommand oExecuteCommand;

};

#endif // FTPCLIENT_H_INCLUDED
