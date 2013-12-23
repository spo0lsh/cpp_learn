#include "DatabaseOperations.h"

using namespace std;

CDatabaseOperations::CDatabaseOperations()
{

}

CDatabaseOperations::~CDatabaseOperations()
{

}

vector <vector<string> > * CDatabaseOperations::createDatabaseStructure(std::string &a_dbFile)
{
    vector <vector<string> > *pr_DB = new vector <vector<string> >();
    this->mp_DB = pr_DB;
    std::cout << "CDatabaseOperations::createDatabaseStructure: " << a_dbFile << std::endl;
    //this->readUsersFromFile((char*)"database.txt");
    if(this->readUsersFromFile((char *)a_dbFile.c_str()) != 0)
    {
        std::cout << "CDatabaseOperations::createDatabaseStructure: fail!" << std::endl;
        pr_DB=0;
    }
    else
    {
        // do nothing
    }
    delete pr_DB;
    return this->mp_DB;
}

void CDatabaseOperations::destroyDatabaseStructure()
{
//    delete this->mp_DB;
}

int CDatabaseOperations::addUserToDatabase(std::string &a_login, std::string &a_password)
{
    std::cout << "CDatabaseOperations::addUserToDatabase: " << a_login << " password: " << a_password << std::endl;
    vector<string> user;
    user.push_back(a_login);
    user.push_back(a_password);
    this->mp_DB->push_back(user);
    user.clear();
    return 0; // TODO: fix
}

int CDatabaseOperations::readUsersFromFile(char* a_filename)
{
    std::string line;
    int exit_status=0;
    CFileInputOutput *po_FileInputOutput = new CFileInputOutput;
    if(po_FileInputOutput->openFile(a_filename) != 0)
    {
        std::cout << "CDatabaseOperations::readUsersFromFile Problem with open file: " << a_filename << std::endl;
        exit_status=1;
    }
    else
    {
        std::cout << "CDatabaseOperations::readUsersFromFile reading file" << std::endl;
        do
        {
            line=po_FileInputOutput->readLineFromFile();
            if(! line.empty())
            {
                this->parseData(line);
            }
//            std::cout << line << std::endl;
        }
        while (!line.empty());
    }
    po_FileInputOutput->closeFile();
    delete po_FileInputOutput;
    return exit_status;
}

void CDatabaseOperations::debugPrint(vector <vector<string> > *a_DB)
{
    std::cout << "CDatabaseOperations::debugPrint DB size: " << (*a_DB).size() << std::endl;
    unsigned int i;
    for(i=0; i<(*a_DB).size(); ++i)
    {
        std::cout << "CDatabaseOperations::debugPrint User " << " " << (*a_DB)[i][0] << " password " << (*a_DB)[i][1] << std::endl;
    }
}

void CDatabaseOperations::parseData(std::string &a_data)
{
    string login;
    string password;
    // TODO: fix this procedure
    std::cout << "CDatabaseOperations::parseData: " << a_data << std::endl;
    char str2[] = ":";
    char * pnt;
    pnt=strtok( const_cast<char *>(a_data.c_str()),":");
    int i=0;
    while( pnt!= NULL )
    {
        if(i==0)
        {
            login=pnt;
        }
        else if(i==1)
        {
            password=pnt;
        }
        pnt = strtok( NULL, str2 );
        ++i;
    }
    std::cout << "CDatabaseOperations::parseData: " << login << " " << password << std::endl;
    this->addUserToDatabase(login,password);
}

int CDatabaseOperations::compareLoginAndPassword(std::string &login, std::string &password)
{
    int exit_status=0;
    for(unsigned int i=0; i<(*mp_DB).size(); ++i)
    {
        std::cout << "CDatabaseOperations::compareLoginAndPassword User " << (*mp_DB)[i][0] << "=" << login << " password " << (*mp_DB)[i][1] << "=" << password;
        if((*mp_DB)[i][0].compare(login) == 0 && (*mp_DB)[i][1].compare(password) == 0)
        {
            std::cout << " OK. Grant access." << std::endl;
            exit_status=0;
            break;
        }
        else
        {
            std::cout << " fail." << std::endl;
            exit_status=1;
        }
    }
    return exit_status;
}
