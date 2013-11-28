#include "DatabaseOperations.h"

using namespace std;

CDatabaseOperations::CDatabaseOperations()
{

}

CDatabaseOperations::~CDatabaseOperations()
{

}

vector <vector<string> > * CDatabaseOperations::createDatabaseStructure(std::string dbFile)
{
    vector <vector<string> > *pr_DB = new vector <vector<string> >();
    this->mp_DB = pr_DB;
    std::cout << "CDatabaseOperations::createDatabaseStructure: " << dbFile << std::endl;
    //this->readUsersFromFile((char*)"database.txt");
    if(this->readUsersFromFile((char *)dbFile.c_str()) != 0)
    {
        std::cout << "CDatabaseOperations::createDatabaseStructure: fail!" << std::endl;
        pr_DB=0;
    }
    return pr_DB;
}

int CDatabaseOperations::addUserToDatabase(std::string login, std::string password)
{
    std::cout << "CDatabaseOperations::addUserToDatabase: " << login << " password: " << password << std::endl;
    vector<string> user;
    user.push_back(login);
    user.push_back(password);
    this->mp_DB->push_back(user);
    user.clear();
    return 0;
}

int CDatabaseOperations::readUsersFromFile(char* filename)
{
    std::string line;
    int exit_status=0;
    CFileInputOutput *po_FileInputOutput = new CFileInputOutput;
    if(po_FileInputOutput->openFile(filename,0) != 0)
    {
        std::cout << "CDatabaseOperations::readUsersFromFile Problem with open file: " << filename << std::endl;
        exit_status=1;
    }
    else
    {
        std::cout << "CDatabaseOperations::readUsersFromFile reading file" << std::endl;
        do
        {
            line=po_FileInputOutput->readFromFile();
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

void CDatabaseOperations::debugPrint(vector <vector<string> > *DB)
{
    std::cout << "CDatabaseOperations::debugPrint DB size: " << (*DB).size() << std::endl;
    unsigned int i;
    for(i=0; i<(*DB).size(); ++i)
    {
        std::cout << "CDatabaseOperations::debugPrint User " << " " << (*DB)[i][0] << " password " << (*DB)[i][1] << std::endl;
    }
}

void CDatabaseOperations::parseData(std::string data)
{
    string login;
    string password;
    // TODO: fix this procedure
    std::cout << "CDatabaseOperations::parseData: " << data << std::endl;
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
