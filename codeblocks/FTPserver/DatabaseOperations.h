#ifndef DATABASEOPERATIONS_H_INCLUDED
#define DATABASEOPERATIONS_H_INCLUDED

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <vector>

class CDatabaseOperations
{
public:
    std::vector <std::vector<std::string> > * createDatabaseStructure();
    int compareLoginAndPassword(std::string, std::string );
    int addUserToDatabase(std::string, std::string );
    int readUsersFromFile(char * );
    void parseData(std::string );
    void debugPrint(std::vector <std::vector<std::string> > *DB);

    std::vector <std::vector<std::string> > *mpr_DB;
};

#endif // DATABASEOPERATIONS_H_INCLUDED
