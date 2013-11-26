#include "DatabaseOperations.h"

using namespace std;

vector <vector<string> > * CDatabaseOperations::createDatabaseStructure()
{
    vector <vector<string> > *pr_DB = new vector <vector<string> >();
    this->mpr_DB = pr_DB;
    this->readUsersFromFile((char*)"database.txt");
    return pr_DB;
}

int CDatabaseOperations::addUserToDatabase(std::string login, std::string password)
{
    std::cout << "Try add user: " << login << " password: " << password << std::endl;
    vector<string> user;
    user.push_back(login);
    user.push_back(password);
    this->mpr_DB->push_back(user);
    user.clear();
    return 0;
}

int CDatabaseOperations::readUsersFromFile(char* filename)
{
    std::string line;
    std::cout << "Starting reading file: " << filename << std::endl;
    std::ifstream myfile (filename);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            std::cout << "CDatabaseOperations::readUsersFromFile: " << line << endl;
            this->parseData(line);
        }
    }
    else
    {
        std::cout << "Unable to open file";
    }
    return 0;
}

void CDatabaseOperations::debugPrint(vector <vector<string> > *DB)
{
    std::cout << "DB size: " << (*DB).size() << std::endl;
    unsigned int i;
    for(i=0; i<(*DB).size(); ++i)
    {
        std::cout << "User " << " " << (*DB)[i][0] << " password " << (*DB)[i][1] << std::endl;
    }
}

void CDatabaseOperations::parseData(std::string data)
{
    string login;
    string password;
    std::cout << "CDatabaseOperations::parseData: " << data << endl;
    char str2[] = ":";
    char * pnt;
    pnt=strtok( const_cast<char *>(data.c_str()),":");
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
