//-----------------------------------------------------------------------------------
//		Char Server by Daneos @ Ragezone 
//-----------------------------------------------------------------------------------

#include "stdafx.h"
#include "CharServer.h"

#include "NtlSfx.h"
#include "NtlFile.h"

#include "NtlPacketUC.h"
#include "NtlPacketCU.h"
#include "ResultCode.h"

#include <iostream>
#include <map>
#include <list>

using namespace std;

//-----------------------------------------------------------------------------------


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
	CCharServer * app = (CCharServer*)NtlSfxGetApp();
}


int CClientSession::OnDispatch(CNtlPacket * pPacket)
{
	CCharServer * app = (CCharServer*) NtlSfxGetApp();
	sNTLPACKETHEADER * pHeader = (sNTLPACKETHEADER *)pPacket->GetPacketData();
	printf("~~~ opcode %i received ~~~ \n", pHeader->wOpCode);

	switch( pHeader->wOpCode )
	{
	case UC_LOGIN_REQ:
	{
		CClientSession::SendCharServerReq(pPacket);
	}
		break;
	case UC_CHARACTER_SERVERLIST_ONE_REQ:
	{
		CClientSession::SendServerListOneReq(pPacket);
	}
		break;
	case UC_CHARACTER_LOAD_REQ:
	{
		CClientSession::SendCharLoadReq(pPacket, app);
	}
		break;
	case UC_CHARACTER_ADD_REQ:
	{
		CClientSession::SendCharCreateReq(pPacket, app);
	}
		break;
	case UC_CHARACTER_DEL_REQ:
	{
		CClientSession::SendCharDeleteReq(pPacket, app);
	}
		break;
	case UC_CHARACTER_EXIT_REQ:
	{										
		CClientSession::SendCharExitReq(pPacket);
	}
		break;
	case UC_CONNECT_WAIT_CHECK_REQ:
	{
		CClientSession::SendCharWaitCheckReq(pPacket);
	}
		break;
	case UC_CHARACTER_SELECT_REQ:
	{
		CClientSession::SendCharSelectReq(pPacket);
	}
		break;
	case UC_CHARACTER_RENAME_REQ:
	{
		CClientSession::SendCharRenameReq(pPacket, app);
	}
		break;
	case UC_CONNECT_WAIT_CANCEL_REQ:
	{
		CClientSession::SendCancelWaitReq(pPacket);
	}
		break;
	default:
		return CNtlSession::OnDispatch( pPacket );
	}

	return NTL_SUCCESS;
}


//-----------------------------------------------------------------------------------
//		CharServerMain
//-----------------------------------------------------------------------------------
int CharServerMain(int argc, _TCHAR* argv[])
{
	CNtlFileStream traceFileStream;
	CCharServer app;

// CONNECT  MYSQL
	app.db = new MySQLConnWrapper;
	app.db->connect();
	app.db->switchDb("dbo");
	app.db2 = new MySQLConnWrapper;
	app.db2->connect();
	app.db2->switchDb("dbo");

// LOG FILE
	
	int rc = traceFileStream.Create( "charlog" );
	if( NTL_SUCCESS != rc )
	{
		NTL_PRINT(PRINT_APP, "log file CreateFile error %d(%s)", rc, NtlGetErrorMessage( rc ) );
		return rc;
	}

// CHECK INT FILE
	NtlSetPrintStream( traceFileStream.GetFilePtr() );
	NtlSetPrintFlag( PRINT_APP | PRINT_SYSTEM );


	rc = app.Create(argc, argv, ".\\CharServer.ini");
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
