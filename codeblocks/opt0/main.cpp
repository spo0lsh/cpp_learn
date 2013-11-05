#include <iostream>

using namespace std;

int command(string );

int main(int argc, char *argv[])
{
    int needed=0;
    int found=0;
    string arg;
    cout << "Nazwa programu: " << argv[0] << endl;
    cout << "Ilosc argumentow: " << argc << endl;
    for(int i = 1; i < argc; i++)
    {
        cout << i << ". Argument to: " << argv[i];// << endl;
        //i=i+command(argv[i]);
        arg = argv[i];
        if (arg == "dir")
        {
            cout << endl;
            found=0;
        }
        else if (arg == "del")
        {
            cout << endl;
            found=1;
        }
        else if (arg == "put")
        {
            cout << endl;
            found=1;
        }
        else if (arg == "get")
        {
            cout << endl;
            found=1;
        }
        else if (arg == "login")
        {
            cout << endl;
            found=1;
            needed=needed+4;
        }
        else if (arg == "pass")
        {
            cout << endl;
            found=1;
            needed=needed+2;
        }
        else if (arg == "host")
        {
            cout << endl;
            found=1;
            needed=needed+1;
        }
        else if (arg == "port")
        {
            cout << endl;
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
    if(needed != 7)
    {
        cout << "Need login, pass and host" << endl;
        cout << "Example" << argv[0] << " login your_login pass your_password host server_host" << endl;
    }
    return 0;
}


int command(string arg)
{
    int found=0;
    //cout << arg << endl;
    if (arg == "dir")
    {
        cout << endl;
        found=0;
    }
    else if (arg == "del")
    {
        cout << endl;
        found=1;
    }
    else if (arg == "put")
    {
        cout << endl;
        found=1;
    }
    else if (arg == "get")
    {
        cout << endl;
        found=1;
    }
    else if (arg == "login")
    {
        cout << endl;
        found=1;
    }
    else if (arg == "pass")
    {
        cout << endl;
        found=1;
    }
    else if (arg == "host")
    {
        cout << endl;
        found=1;
    }
    else if (arg == "port")
    {
        cout << endl;
        found=1;
    }
    else
    {
        cout << "Unknow argument: " << arg <<  " ";
        cout << endl;
        found=0;
    }
    return found;
}
