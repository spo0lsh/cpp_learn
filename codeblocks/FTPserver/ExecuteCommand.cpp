#include "ExecuteCommand.h"
#include <dirent.h>

CExecuteCommand::CExecuteCommand()
{
    m_opFileInputOutput = new CFileInputOutput;
    m_opCSocketInputOutput = new CSocketInputOutput;
}

CExecuteCommand::~CExecuteCommand()
{
    delete m_opFileInputOutput;
    delete m_opCSocketInputOutput;
}

int CExecuteCommand::getLoginStatus()
{
    return this->m_iLoginStatus;
}

void CExecuteCommand::setLoginStatus(int a_iLoginStatus)
{
    std::cout << "CExecuteCommand::setLoginStatus to " << a_iLoginStatus << std::endl;
    this->m_iLoginStatus=a_iLoginStatus;
}

// change logic of parse and execute -> return;
void CExecuteCommand::parseData(std::string a_data) // const char, disable new alloc  (ref -> &) ->>> validate command and argv
{
    std::cout << "CExecuteCommand::parseData: " << a_data << std::endl;
    std::string command;
    std::string parameter;
    char str2[] = " ";
    char * pnt;
    pnt=strtok( const_cast<char *>(a_data.c_str())," ");
    int i=0;
    while( pnt!= NULL )
    {
        if(i==0)
        {
            command=pnt;
        }
        else if(i==1)
        {
            parameter=pnt;
        }
        pnt = strtok( NULL, str2 );
        ++i;
    }
    std::cout << "CExecuteCommand::parseData command: " << command << " parameter " << parameter << std::endl;
    this->executeCommand(command, parameter);
}

void CExecuteCommand::executeCommand(std::string command, std::string parameter)
{
    this->m_opCSocketInputOutput->m_sClientSocket=m_sClientSocket; //todo: opensocket for this
    std::cout << "CExecuteCommand::executeCommand try: " << command <<  " " << parameter << std::endl;
    if(this->getLoginStatus() != 0 )
    {
        if(command.compare("USER") == 0 )
        {
            this->login = parameter;
            this->m_opCSocketInputOutput->writeToSocket("OK");
        }
        else if(command.compare("PASS") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute PASS: " << parameter << std::endl;
            this->password = parameter;
            if(this->login.empty())
            {
                std::cout << "CExecuteCommand::executeCommand PASS login is empty" << std::endl;
                this->m_opCSocketInputOutput->writeToSocket("KO");
            }
            else
            {
                std::cout << "CExecuteCommand::executeCommand need execute loginToServer" << std::endl;
                if(this->loginToServer(this->login, this->password) != 0)
                {
                    std::cout << "CExecuteCommand::executeCommand.loginToServer fail" << std::endl;
                    this->m_opCSocketInputOutput->writeToSocket("KO");
                    this->setLoginStatus(1);
                }
                else
                {
                    std::cout << "CExecuteCommand::executeCommand.loginToServer OK." << std::endl;
                    this->m_opCSocketInputOutput->writeToSocket("OK");
                    this->setLoginStatus(0);
                }
            }
        }
        else
        {
            std::cout << "CExecuteCommand::executeCommand fail, user not logged and command not found" << std::endl;
            this->m_opCSocketInputOutput->writeToSocket("KO");
            // exit status 1
        }
    }
    else
    {
        if(command.compare("QUIT") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute QUIT" << std::endl;
            this->m_opCSocketInputOutput->writeToSocket("OK");
        }
        else if(command.compare("RETR") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute RETR" << std::endl;
            this->getFileFromServer(parameter);
        }
        else if(command.compare("SIZE") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute SIZE" << std::endl;
            this->checkFileSize(parameter);
        }
        else if(command.compare("STOR") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute STOR" << std::endl;
            this->putFileToServer(parameter); // fix size!
        }
        else if(command.compare("DELE") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute DELE" << std::endl;
            this->deleteFileOnServer(parameter);
        }
        else if(command.compare("LIST") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute LIST" << std::endl;
            this->showFilesOnServer();
        }
        else if(command.compare("NOOP") == 0 )
        {
            std::cout << "CExecuteCommand::executeCommand need execute NOOP" << std::endl;
            this->m_opCSocketInputOutput->writeToSocket("OK");
        }
        else
        {
            std::cout << "CExecuteCommand::executeCommand Unsupported command: " << command << std::endl;
        }
    }
}

int CExecuteCommand::getFileFromServer(std::string a_filename)
{
//    int fileSize;
    std::cout << "CExecuteCommand::getFileFromServer" << std::endl;
    int mode=0;
    int bytes=DEFAULT_BUFFER - 1;
    if(m_opFileInputOutput->openFile(&a_filename[0], mode) != 0)
    {
        this->m_opCSocketInputOutput->writeToSocket("KO");
    }
    else
    {
        int fileSize = m_opFileInputOutput->checkFileSize();
        if(fileSize != -1)
        {
            std::cout << "CExecuteCommand::getFileFromServer size: " << fileSize << std::endl;
            this->m_opCSocketInputOutput->writeToSocket("OK");
            if(fileSize < bytes)
            {
                std::cout << "CExecuteCommand::getFileFromServer read: " << m_opFileInputOutput->readFile(bytes) << std::endl;
                memcpy( m_opCSocketInputOutput->sBuffer, m_opFileInputOutput->sBuffer, sizeof(m_opCSocketInputOutput->sBuffer) );
                m_opCSocketInputOutput->writeToSocket(m_opFileInputOutput->bytesReaded);
                if(m_opCSocketInputOutput->readFromSocket() > 0)
                {
                    std::cout << "CExecuteCommand::getFileFromServer.readFromSocket() RETR status: " << m_opCSocketInputOutput->sBuffer << std::endl;
                }
                std::cout << "CExecuteCommand::putFileToServer send NOOP" << std::endl;
                m_opCSocketInputOutput->writeToSocket("NOOP"); // wrong!
                if(m_opCSocketInputOutput->readFromSocket() > 0)
                {
                    std::cout << "CExecuteCommand::getFileFromServer.readFromSocket() RETR status: " << m_opCSocketInputOutput->sBuffer << std::endl;
                }
            }
            else
            {
			// double -> and module (%)
                int blocks=ceil((double)fileSize/(bytes));
                std::cout << "CExecuteCommand::getFileFromServer size > bytes, number of packages: " << blocks << std::endl;
                for(int i=0;i<blocks;++i)
                {
                    m_opFileInputOutput->readFile(bytes);
                    // need be fixed
                    memcpy( m_opCSocketInputOutput->sBuffer, m_opFileInputOutput->sBuffer, sizeof(m_opCSocketInputOutput->sBuffer) );
                    std::cout << "CExecuteCommand::getFileFromServer bytes to write: " << m_opFileInputOutput->bytesReaded << std::endl;
                    std::cout << "CExecuteCommand::getFileFromServer: " << i+1 << "/" << blocks << std::endl;
                    m_opCSocketInputOutput->writeToSocket(m_opFileInputOutput->bytesReaded);
                    if(m_opCSocketInputOutput->readFromSocket() > 0)
                    {
                        std::cout << "CExecuteCommand::getFileFromServer.readFromSocket() RETR status: " << m_opCSocketInputOutput->sBuffer << std::endl;
                    }
                    else
                    {
                        std::cout << "CExecuteCommand::getFileFromServer.readFromSocket() WITH BREAK RETR status: " << m_opCSocketInputOutput->sBuffer << std::endl;
                        break;
                    }
                }
                std::cout << "CExecuteCommand::getFileFromServer send NOOP" << std::endl;
                m_opCSocketInputOutput->writeToSocket("NOOP");
                if(m_opCSocketInputOutput->readFromSocket() > 0)
                {
                    std::cout << "CExecuteCommand::getFileFromServer.readFromSocket() NOOP status: " << m_opCSocketInputOutput->sBuffer << std::endl;
                }
            }
        }
        else
        {
            std::cout << "CExecuteCommand::getFileFromServer get file size fail! " << std::endl;
            this->m_opCSocketInputOutput->writeToSocket("KO");
        }
        this->m_opFileInputOutput->closeFile();
    }
    return 0;
}

int CExecuteCommand::putFileToServer(std::string a_filename)
{
//    int size;
    int mode=3;
//    int bytes;
    std::cout << "CExecuteCommand::putFileToServer: " << a_filename << std::endl;
    if(m_opFileInputOutput->openFile(&a_filename[0], mode) != 0)
    {
        this->m_opCSocketInputOutput->writeToSocket("KO");
    }
    else
    {
        this->m_opCSocketInputOutput->writeToSocket("OK");
        while(m_opCSocketInputOutput->readFromSocket() > 0)
        {
            if(strcmp(m_opCSocketInputOutput->sBuffer, "NOOP") != 0)
//                    if(strncmp(oSocketInputOutput.sBuffer, "NOOP",4) != 0)
            {
                std::cout << "CExecuteCommand::putFileToServer read from socket bytes: " << m_opCSocketInputOutput->ret << std::endl;
                memcpy(m_opFileInputOutput->sBuffer, m_opCSocketInputOutput->sBuffer, sizeof(m_opFileInputOutput->sBuffer) );
                m_opFileInputOutput->writeToFile(m_opCSocketInputOutput->ret);
                m_opCSocketInputOutput->writeToSocket("OK");
            }
            else
            {
                std::cout << "CExecuteCommand::putFileToServer Read from socket bytes NOOP: " << m_opCSocketInputOutput->ret << " " << m_opCSocketInputOutput->sBuffer << std::endl;
                m_opCSocketInputOutput->writeToSocket("OK");
                std::cout << "CExecuteCommand::putFileToServer BREAK" << std::endl;
                break;
            }
        }
    }
    this->m_opFileInputOutput->closeFile();
    std::cout << "CExecuteCommand::putFileToServer: done" << std::endl;
    return 0;
}

int CExecuteCommand::showFilesOnServer()
{
    std::cout << "CExecuteCommand::showFilesOnServer" << std::endl;
    //should be fixed, but works!
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("./")) != NULL) {
        this->m_opCSocketInputOutput->writeToSocket("OK");
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            this->m_opCSocketInputOutput->writeToSocket(ent->d_name);
            m_opCSocketInputOutput->readFromSocket();
            this->m_opCSocketInputOutput->writeToSocket("\n");
            m_opCSocketInputOutput->readFromSocket();
        }
        closedir (dir);
        this->m_opCSocketInputOutput->writeToSocket("NOOP");
        m_opCSocketInputOutput->readFromSocket();
    } else {
        this->m_opCSocketInputOutput->writeToSocket("KO");
    }
    return 0;
}

int CExecuteCommand::deleteFileOnServer(std::string filename)
{
    std::cout << "CExecuteCommand::deleteFileOnServer ";
    if(std::remove(filename.c_str()) != 0)
    {
        std::cerr << "Error during the deletion: " << std::endl;
        this->m_opCSocketInputOutput->writeToSocket("KO");
    }
    else
    {
        std::cout << "File was successfully deleted" << std::endl;
        this->m_opCSocketInputOutput->writeToSocket("OK");
    }
    return 0;
}

int CExecuteCommand::loginToServer(std::string login, std::string password)
{
    int exit_status=0;
    std::cout << "CExecuteCommand::loginToServer" << std::endl;
    CDatabaseOperations *opDatabaseOperations = new CDatabaseOperations;
    opDatabaseOperations->mp_DB=this->mp_DB;
    exit_status = opDatabaseOperations->compareLoginAndPassword(login, password);
    delete opDatabaseOperations;
    std::cout << "CExecuteCommand::loginToServer exit_status: " << exit_status << std::endl;
    return exit_status;
}

int CExecuteCommand::logoutFromServer()
{
    std::cout << "CExecuteCommand::logoutFromServer" << std::endl;
    this->m_opCSocketInputOutput->writeToSocket("KO");
    return 0;
}

int CExecuteCommand::checkFileSize(std::string a_filename)
{
    int mode=0;
    int exit_status=0;
    char *filename = &a_filename[0]; //cast
    char szBuffer[2048];

    std::cout << "CExecuteCommand::checkFileSize: " << a_filename << std::endl;
    if(m_opFileInputOutput->openFile(filename,mode) != 0)
    {
        std::cout << "CExecuteCommand::checkFileSize Problem with open file: " << a_filename << std::endl;
        this->m_opCSocketInputOutput->writeToSocket("KO");
        exit_status=1;
    }
    else
    {
        int fileSize = m_opFileInputOutput->checkFileSize();
        if(fileSize != -1)
        {
            std::cout << "CExecuteCommand::checkFileSize size: " << fileSize << std::endl;
            this->m_opCSocketInputOutput->writeToSocket(itoa (fileSize, szBuffer,10));
        }
        else
        {
            std::cout << "CExecuteCommand::checkFileSize get file size fail! " << std::endl;
            this->m_opCSocketInputOutput->writeToSocket("KO");
        }
        m_opFileInputOutput->closeFile();
    }
    return exit_status;
}
