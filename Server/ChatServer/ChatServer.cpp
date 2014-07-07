//-----------------------------------------------------------------------------------
//		Chat Server by Daneos @ Ragezone 
//-----------------------------------------------------------------------------------

#include "stdafx.h"
#include "ChatServer.h"


using namespace std;

RwUInt32 AcquireSerialId(void)
{
	if(m_uiSerialId++)
	{
		if(m_uiSerialId == 0xffffffff)//INVALID_SERIAL_ID)
			m_uiSerialId = 0;
	}

	return m_uiSerialId;
}

//-----------------------------------------------------------------------------------
CClientSession::~CClientSession()
{
	NTL_PRINT(PRINT_APP, "CClientSession Destructor Called");
}


int CClientSession::OnAccept()
{
	NTL_PRINT( PRINT_APP, "%s", __FUNCTION__ );
	avatarHandle = AcquireSerialId();
	return NTL_SUCCESS;
}


void CClientSession::OnClose()
{
	NTL_PRINT( PRINT_APP, "%s", __FUNCTION__ );
	CChatServer * app = (CChatServer*) NtlSfxGetApp();
	app->RemoveUser(this->GetCharName().c_str());
}

int CClientSession::OnDispatch(CNtlPacket * pPacket)
{
	CChatServer * app = (CChatServer*) NtlSfxGetApp();

	sNTLPACKETHEADER * pHeader = (sNTLPACKETHEADER *)pPacket->GetPacketData();
	if(pHeader->wOpCode > 1) {
		printf("~~~ opcode %i received ~~~ \n", pHeader->wOpCode);
	}
	switch( pHeader->wOpCode )
	{
	case UT_ENTER_CHAT:
	{
		CClientSession::SendEnterChat(pPacket, app);
		CClientSession::SendLoadGuildInfo(pPacket, app);
		CClientSession::SendLoadGuildMember(pPacket, app);
	}
		break;
	case UT_CHAT_MESSAGE_SAY:
	{
		CClientSession::SendChatReq(pPacket, app);
	}
		break;
	case UT_CHAT_MESSAGE_SHOUT:
	{
		printf("UT_CHAT_MESSAGE_SHOUT");
	}
		break;
	case UT_CHAT_MESSAGE_WHISPER:
	{
		printf("UT_CHAT_MESSAGE_WHISPER");
	}
		break;
	case UT_CHAT_MESSAGE_PARTY:
	{
		printf("UT_CHAT_MESSAGE_PARTY");
	}
		break;
	case UT_CHAT_MESSAGE_GUILD:
	{
		printf("UT_CHAT_MESSAGE_GUILD");
	}
		break;
	case UT_GUILD_DISBAND_REQ:
	{
		CClientSession::SendDisbandGuild(pPacket, app);
	}
		break;
	case UT_GUILD_DISBAND_CANCEL_REQ:
	{
		printf("UT_GUILD_DISBAND_CANCEL_REQ");
	}
		break;
	case UT_GUILD_RESPONSE_INVITATION:
	{
		printf("UT_GUILD_RESPONSE_INVITATION");
	}
		break;
	case UT_GUILD_LEAVE_REQ:
	{
		CClientSession::SendLeaveGuildReq(pPacket, app);
	}
		break;
	case UT_GUILD_KICK_OUT_REQ:
	{
		CClientSession::SendKickFromGuildReq(pPacket, app);
	}
		break;
	case UT_GUILD_APPOINT_SECOND_MASTER_REQ:
	{
		CClientSession::SendNewSecondGuildMaster(pPacket, app);
	}
		break;
	case UT_GUILD_DISMISS_SECOND_MASTER_REQ:
	{
		CClientSession::SendRemoveSecondGuildMaster(pPacket, app);
	}
		break;
	case UT_GUILD_CHANGE_GUILD_MASTER_REQ:
	{
		CClientSession::SendUpdateGuildMaster(pPacket, app);
	}
		break;
	case UT_CHAT_MESSAGE_PRIVATESHOP_BUSINESS:
	{
		printf("UT_CHAT_MESSAGE_PRIVATESHOP_BUSINESS");
	}
		break;
	case UT_FRIEND_ADD_REQ:
	{
		printf("UT_FRIEND_ADD_REQ");
	}
		break;
	case UT_FRIEND_DEL_REQ:
	{
		printf("UT_FRIEND_DEL_REQ");
	}
		break;
	case UT_FRIEND_MOVE_REQ:
	{
		printf("UT_FRIEND_MOVE_REQ");
	}
		break;
	case UT_FRIEND_BLACK_ADD_REQ:
	{
		printf("UT_FRIEND_BLACK_ADD_REQ");
	}
		break;
	case UT_FRIEND_BLACK_DEL_REQ:
	{
		printf("UT_FRIEND_BLACK_DEL_REQ");
	}
		break;
	case UT_RANKBATTLE_RANK_LIST_REQ:
	{
		printf("UT_RANKBATTLE_RANK_LIST_REQ");
	}
		break;
	case UT_RANKBATTLE_RANK_FIND_CHARACTER_REQ:
	{
		printf("UT_RANKBATTLE_RANK_FIND_CHARACTER_REQ");
	}
		break;
	case UT_RANKBATTLE_RANK_COMPARE_DAY_REQ:
	{
		printf("UT_RANKBATTLE_RANK_COMPARE_DAY_REQ");
	}
		break;
	case UT_GUILD_CHANGE_NOTICE_REQ:
	{
		CClientSession::SendGuildChangeNotice(pPacket, app);
	}
		break;
	case UT_TMQ_RECORD_LIST_REQ:
	{
		printf("UT_TMQ_RECORD_LIST_REQ");
	}
		break;
	case UT_TMQ_MEMBER_LIST_REQ:
	{
		printf("UT_TMQ_MEMBER_LIST_REQ");
	}
		break;
	case UT_BUDOKAI_TOURNAMENT_INDIVIDUAL_LIST_REQ:
	{
		printf("UT_BUDOKAI_TOURNAMENT_INDIVIDUAL_LIST_REQ");
	}
		break;
	case UT_BUDOKAI_TOURNAMENT_INDIVIDUAL_INFO_REQ:
	{
		printf("UT_BUDOKAI_TOURNAMENT_INDIVIDUAL_INFO_REQ");
	}
		break;
	case UT_BUDOKAI_TOURNAMENT_TEAM_LIST_REQ:
	{
		printf("UT_BUDOKAI_TOURNAMENT_TEAM_LIST_REQ");
	}
		break;
	case UT_BUDOKAI_TOURNAMENT_TEAM_INFO_REQ:
	{
		printf("UT_BUDOKAI_TOURNAMENT_TEAM_INFO_REQ");
	}
		break;
	case UT_PETITION_CHAT_START_RES:
	{
		printf("UT_PETITION_CHAT_START_RES");
	}
		break;
	case UT_PETITION_CHAT_USER_SAY_REQ:
	{
		printf("UT_PETITION_CHAT_USER_SAY_REQ");
	}
		break;
	case UT_PETITION_CHAT_USER_END_NFY:
	{
		printf("UT_PETITION_CHAT_USER_END_NFY");
	}
		break;
	case UT_PETITION_CHAT_GM_SAY_RES:
	{
		printf("UT_PETITION_CHAT_GM_SAY_RES");
	}
		break;
	case UT_PETITION_USER_INSERT_REQ:
	{
		printf("UT_PETITION_USER_INSERT_REQ");
	}
		break;
	case UT_PETITION_CONTENT_MODIFY_REQ:
	{
		printf("UT_PETITION_CONTENT_MODIFY_REQ");
	}
		break;
	case UT_PETITION_SATISFACTION_NFY:
	{
		printf("UT_PETITION_SATISFACTION_NFY");
	}
		break;
	case UT_PETITION_USER_CANCEL_REQ:
	{
		printf("UT_PETITION_USER_CANCEL_REQ");
	}
		break;
	case UT_DOJO_BUDOKAI_SEED_ADD_REQ:
	{
		printf("UT_DOJO_BUDOKAI_SEED_ADD_REQ");
	}
		break;
	case UT_DOJO_BUDOKAI_SEED_DEL_REQ:
	{
		printf("UT_DOJO_BUDOKAI_SEED_DEL_REQ");
	}
		break;
	case UT_DOJO_NOTICE_CHANGE_REQ:
	{
		printf("UT_DOJO_NOTICE_CHANGE_REQ");
	}
		break;



	default:
		return CNtlSession::OnDispatch( pPacket );
	}

	return NTL_SUCCESS;
}



//-----------------------------------------------------------------------------------
//		ChatServerMain
//-----------------------------------------------------------------------------------
int ChatServerMain(int argc, _TCHAR* argv[])
{
	CChatServer app;
	CNtlFileStream traceFileStream;

// LOG FILE
	int rc = traceFileStream.Create( "chatlog" );
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

	rc = app.Create(argc, argv, ".\\ChatServer.ini");
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
