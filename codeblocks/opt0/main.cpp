#include <iostream>

using namespace std;

class CgetCommandFromArgv
{
public:
    int checkCommand(int argc, char *argv[]);
};

int CgetCommandFromArgv::checkCommand(int argc, char *argv[])
{
    int exit_status=0;
    int i=0;
    string arg;
    cout << "Program name: " << argv[0] << endl;
    cout << "Argv : " << argc << endl;
    int needed=0;
    for(i = 1; i < argc; i++)
    {
        arg = argv[i];
        if (arg == "login")
        {
            //cout << endl;
            needed=needed+4;
        }
        else if (arg == "pass")
        {
            //cout << endl;
            needed=needed+2;
        }
        else if (arg == "host")
        {
            //cout << endl;
            needed=needed+1;
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
    if(pCgetCommandFromArgv->checkCommand(argc, argv) != 0)
    {
        exit_status=1;
    }
    else
    {
        exit_status=0;
    }
    return exit_status;
}
