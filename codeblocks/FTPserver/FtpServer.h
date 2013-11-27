/**
 * @file
 *          EngModeWrapper.h
 * @brief
 *          Class used for communication between engineering screen
 *			and engineering wrapper
 * @par CM-Info:
 *          - %name: EngModeWrapper.h %
 *          - %full_filespec: EngModeWrapper.h-3:incl:Fiat_WZ#2 %
 *          - %date_created: Wed Nov  6 12:12:03 2013 %
 *          - %derived_by: uidv9117 %
 * @par Responsible Developer:
 *          - Pavel Vlasanek
 *          - Tieto
 * @par PL:
 *          - Thorsten Fix
 *          - Continental Automotive GmbH
 * @par Responsible Architect:
 *          - Jens Walther
 *          - Continental Automotive GmbH
 * @par Project:
 *          Fiat VP2, HS
 * @par SW-Component:
 *          HMI
 * @par Description:
 *          Wrapper for Eng interface.
 * @note
 *
 *
 * @par Module-History (last 10 changes):
 * @verbatim
 *  Date        Author                  Reason
 *  06.11.2013  Barbara Gluska          Add new functions for incremental model (CR Fiat_WZ#17040)
 *  04.11.2011  Pavel Vlasanek          Notify support added
 *  06.10.2011  Pavel Vlasanek          Initial commit
 * @endverbatim
 *
 * @par Copyright Notice:
 * Copyright (C) Continental Automotive GmbH 2011
 * Continental Automotive GmbH
 * Alle Rechte vorbehalten. All Rights Reserved.
 *
 * The reproduction, transmission or use of this document or its contents is
 * not permitted without express written authority.
 * Offenders will be liable for damages. All rights, including rights created
 * by patent grant or registration of a utility model or design, are reserved.
 */

#ifndef FTPSERVER_H_INCLUDED
#define FTPSERVER_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

#include "ThreadPool.h"

class CFtpServer
{
public:
    CFtpServer();
    ~CFtpServer();

    CThreadPool *m_pCThreadPool = new CThreadPool;

    void acceptConnection();
    void bindAndListen();
    int startServer(int argc, char *argv[]);
    void stopServer();
    void debugVariable();

private:
    int m_status;
    std::string m_host;
    std::string m_directory;
    std::string m_dbFile;
    int m_port;
    int m_poolSize;

    int checkRootDirectory();
    int getOptionsFromCommandLine(int , char **);
};

#endif // FTPSERVER_H_INCLUDED
