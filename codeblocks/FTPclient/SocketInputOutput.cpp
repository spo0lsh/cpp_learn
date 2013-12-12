#include "SocketInputOutput.h"

CSocketInputOutput::CSocketInputOutput()
{
    m_sClientSocket = INVALID_SOCKET;
    mp_ListenSocket = INVALID_SOCKET;
}

CSocketInputOutput::~CSocketInputOutput()
{

}
