#ifndef DATABASEOPERATIONS_H_INCLUDED
#define DATABASEOPERATIONS_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

class CDatabaseOperations
{
public:
    void createDatabaseStructure();
    int compareLoginAndPassword(std::string, std::string );
    int addUserToDatabase(std::string, std::string );
    std::string readUsersFromFile(std::string );
    void parseData(std::string );
};

#endif // DATABASEOPERATIONS_H_INCLUDED
