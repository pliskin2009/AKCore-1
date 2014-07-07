//-----------------------------------------------------------------------------------
//		Auth Server by Daneos @ Ragezone 
//-----------------------------------------------------------------------------------

#include "stdafx.h"
#include "AuthServer.h"

#include "NtlSfx.h"
#include "NtlFile.h"

#include "NtlPacketUA.h"
#include "NtlPacketAU.h"
#include "ResultCode.h"

#include <iostream>
#include <map>
#include <list>

using namespace std;


//-----------------------------------------------------------------------------------
CClientSession::~CClientSession()
{
	NTL_PRINT(PRINT_APP, "CClientSession Destructor Called");
}


int CClientSession::OnAccept()
{
	NTL_PRINT( PRINT_APP, "%s", __FUNCTION__ );

	return NTL_SUCCESS;
}


void CClientSession::OnClose()
{
	NTL_PRINT( PRINT_APP, "%s", __FUNCTION__ );
	CAuthServer * app = (CAuthServer*) NtlSfxGetApp();
}

int CClientSession::OnDispatch(CNtlPacket * pPacket)
{
	CAuthServer * app = (CAuthServer*) NtlSfxGetApp();

	sNTLPACKETHEADER * pHeader = (sNTLPACKETHEADER *)pPacket->GetPacketData();
	printf("~~~ opcode %i received ~~~ \n", pHeader->wOpCode);
	switch( pHeader->wOpCode )
	{
	case UA_LOGIN_REQ:
	{
		CClientSession::SendCharLogInReq(pPacket, app);
	}
		break;
	case UA_LOGIN_DISCONNECT_REQ:
	{
		CClientSession::SendLoginDcReq(pPacket);
	}
		break;

	default:
		return CNtlSession::OnDispatch( pPacket );
	}

	return NTL_SUCCESS;
}



//-----------------------------------------------------------------------------------
//		AuthServerMain
//-----------------------------------------------------------------------------------
int AuthServerMain(int argc, _TCHAR* argv[])
{
	CAuthServer app;
	CNtlFileStream traceFileStream;

// LOG FILE
	int rc = traceFileStream.Create( "authlog" );
	if( NTL_SUCCESS != rc )
	{
		printf( "log file CreateFile error %d(%s)", rc, NtlGetErrorMessage( rc ) );
		return rc;
	}

// CONNECT TO MYSQL
	app.db = new MySQLConnWrapper;
	app.db->connect();
	app.db->switchDb("dbo");


// CHECK INI FILE AND START PROGRAM
	NtlSetPrintStream( traceFileStream.GetFilePtr() );
	NtlSetPrintFlag( PRINT_APP | PRINT_SYSTEM );

	rc = app.Create(argc, argv, ".\\Server.ini");
	if( NTL_SUCCESS != rc )
	{
		NTL_PRINT(PRINT_APP, "Server Application Create Fail %d(%s)", rc, NtlGetErrorMessage(rc) );
		return rc;
	}

	app.Start();
	Sleep(500);
	std::cout << "\n\n" << std::endl;
	std::cout << "\t  ____                              ____        _ _ " << std::endl;
	std::cout << "\t |  _ \\ _ __ __ _  __ _  ___  _ __ | __ )  __ _| | |" << std::endl;
	std::cout << "\t | | | | '__/ _` |/ _` |/ _ \\| '_ \\|  _ \\ / _` | | |" << std::endl;
	std::cout << "\t | |_| | | | (_| | (_| | (_) | | | | |_) | (_| | | |" << std::endl;
	std::cout << "\t |____/|_|  \\__,_|\\__, |\\___/|_| |_|____/ \\__,_|_|_|" << std::endl;
	std::cout << "\t                  |___/                             " << std::endl;
	std::cout << "\t______           AKCore :O 2014					______\n\n" << std::endl;
	app.WaitForTerminate();
	

	return 0;
}
