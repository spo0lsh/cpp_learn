#include <iostream>

using namespace std;

class CgetCommandFromArgv
{
    string login, pass, host;
    int port;
public:
    int checkRequireOptions(int , char **);
    int parsingOptionsForCommand(int , char **);
    int executeCommand(string, string );
};


int CgetCommandFromArgv::executeCommand(string command, string argument=0)
{
    cout << "command: " << command << " argument: " << argument << endl;
    return 0;
}

// TODO:
// generate doxy comments!
// check for param of command is not commands
int CgetCommandFromArgv::parsingOptionsForCommand(int argc, char *argv[])
{
    int exit_status=0;
    int found=0;
    string arg;
    int i;
    for(i = 1; i < argc; i++)
        {
            arg = argv[i];
            if (arg == "dir")
            {
                cout << "dir" << endl;
                CgetCommandFromArgv::executeCommand("dir","");
                found=0;
            }
            else if (arg == "del")
            {
                if(argv[i+1] != 0)
                {
                    cout << "del: " << argv[i+1] << endl;
                }
                else
                {
                    cout << "del: wrong parameter, skipping" << endl;
                }
                found=1;
            }
            else if (arg == "put")
            {
                if(argv[i+1] != 0)
                {
                    cout << "put: " << argv[i+1] << endl;
                }
                else
                {
                    cout << "put: wrong parameter, skipping" << endl;
                }
                found=1;
            }
            else if (arg == "get")
            {
                if(argv[i+1] != 0)
                {
                    cout << "get: " << argv[i+1] << endl;
                }
                else
                {
                    cout << "get: wrong parameter, skipping" << endl;
                }
                found=1;
            }
            else if (arg == "login")
            {
                cout << "login" << endl;
                found=1;
            }
            else if (arg == "pass")
            {
                cout << "pass" << endl;
                found=1;
            }
            else if (arg == "host")
            {
                cout << "host" << endl;
                found=1;
            }
            else if (arg == "port")
            {
                cout << "port" << endl;
                found=1;
            }
            else
            {
                cout << "Unknow argument: " << arg <<  " ";
                cout << endl;
                found=0;
            }
            i=i+found;
        }
    return exit_status;
}

int CgetCommandFromArgv::checkRequireOptions(int argc, char *argv[])
{
    int exit_status=0;
    int i=0;
    string arg;
    int needed=0;
    for(i = 1; i < argc; i++)
    {
        arg = argv[i];
        if (arg == "login")
        {
            if(argv[i+1] != 0)
            {
                cout << "login: " << argv[i+1] << endl;
                needed=needed+4;
            }
        }
        else if (arg == "pass")
        {
            if(argv[i+1] != 0)
            {
                cout << "pass: " << argv[i+1] << endl;
                needed=needed+2;
            }
        }
        else if (arg == "host")
        {
            if(argv[i+1] != 0)
            {
                cout << "host: " << argv[i+1] << endl;
                needed=needed+1;
            }
        }
        else
        {
        }
    }
    if(needed != 7)
    {
        cout << "Need login, pass and host" << endl;
        cout << "Example" << argv[0] << " login your_login pass your_password host server_host" << endl;
        exit_status=1;
    }
    else
    {
        exit_status=0;
    }
    return exit_status;
}

int main(int argc, char *argv[])
{
    int exit_status=0;
    CgetCommandFromArgv *pCgetCommandFromArgv = new CgetCommandFromArgv;
    if(pCgetCommandFromArgv->checkRequireOptions(argc, argv) != 0)
    {
        exit_status=1;
    }
    else
    {
        pCgetCommandFromArgv->parsingOptionsForCommand(argc, argv);
        exit_status=0;
    }
    return exit_status;
}
