#pragma once


#include "NtlPacketEncoder_RandKey.h"
#include "NtlFile.h"
#include "Memoryhandle.h"


#include "NtlPacketUG.h"
#include "NtlPacketGU.h"
#include "ResultCode.h"

#include "GsFunctions.h"
#include "QueryClass.h"

#include "NtlItem.h"
#include "Battle.h"
// LOAD TABLES
#include "DragonBallRewardTable.h"
#include "DragonBallTable.h"
#include "Table.h"
#include "NPCTable.h"
#include "TableContainer.h"
#include "WorldTable.h"
#include "MobTable.h"
#include "PCTable.h"
#include "SkillTable.h"
#include "HTBSetTable.h"
#include "TableFileNameList.h"
#include "WorldMapTable.h"
#include "WorldPathTable.h"
#include "ObjectTable.h"
#include "PortalTable.h"
#include "MerchantTable.h"
#include "ItemTable.h"
#include "FormulaTable.h"
// END TABLES
#include "PlayerInfos.h"
#include "MobActivity.h"
#include "NtlBitFlagManager.h"
#include "PlayerParty.h"
#include <MMSystem.h>
#include <iostream>
#include <map>

enum APP_LOG
{
	PRINT_APP = 2,
};
enum GAME_SESSION
{
	SESSION_CLIENT,
};
struct sSERVERCONFIG
{
	CNtlString		strClientAcceptAddr;
	WORD			wClientAcceptPort;
};

const DWORD					MAX_NUMOF_GAME_CLIENT = 5;
const DWORD					MAX_NUMOF_SERVER = 1;
const DWORD					MAX_NUMOF_SESSION = MAX_NUMOF_GAME_CLIENT + MAX_NUMOF_SERVER;

class CGameServer;
class CTableContainer;
class CTableFileNameList;
class CNtlBitFlagManager;

//---------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------//
class CClientSession : public CNtlSession
{
public:

	CClientSession(bool bAliveCheck = false, bool bOpcodeCheck = false)
		:CNtlSession( SESSION_CLIENT )
	{
		SetControlFlag( CONTROL_FLAG_USE_SEND_QUEUE );

		if( bAliveCheck )
		{
			SetControlFlag( CONTROL_FLAG_CHECK_ALIVE );
		}

		if( bOpcodeCheck )
		{
			SetControlFlag( CONTROL_FLAG_CHECK_OPCODE );
		}

		SetPacketEncoder( &m_packetEncoder );
	}

	~CClientSession();


public:
	int							OnAccept();
	void						OnClose();
	int							OnDispatch(CNtlPacket * pPacket);

	//
	RwUInt32					GetavatarHandle() { return avatarHandle; }
	RwUInt32					GetTargetSerialId() { return m_uiTargetSerialId; }

	//
	//Client Packet functions
	void						SendGameEnterReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendAvatarCharInfo(CNtlPacket * pPacket, CGameServer * app);
	void						CheckPlayerStat(CGameServer * app, sPC_TBLDAT *pTblData);
	void						SendAvatarItemInfo(CNtlPacket * pPacket, CGameServer * app);
	void						SendAvatarSkillInfo(CNtlPacket * pPacket, CGameServer * app);
	void						SendAvatarInfoEnd(CNtlPacket * pPacket);
	void						SendAuthCommunityServer(CNtlPacket * pPacket, CGameServer * app);

	void						SendWorldEnterReq(CNtlPacket * pPacket, CGameServer * app);
//	void						SendPlayerCreate(CNtlPacket * pPacket, CGameServer * app);
	void						SendNpcCreate(CNtlPacket * pPacket, CGameServer * app);
	void						SendMonsterCreate(CNtlPacket * pPacket, CGameServer * app);
	void						SendEnterWorldComplete(CNtlPacket * pPacket);

	void						SendCharReadyReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendTutorialHintReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharReady(CNtlPacket * pPacket);
	void						SendCharMove(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharDestMove(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharMoveSync(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharChangeHeading(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharJump(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharChangeDirOnFloating(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharFalling(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharExitReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendGameLeaveReq(CNtlPacket * pPacket, CGameServer * app);
	void						RecvServerCommand(CNtlPacket * pPacket, CGameServer * app);
	void						SendUpdateCharSpeed(float fSpeed, CGameServer * app);
	void						SendCharTargetSelect(CNtlPacket * pPacket);
	void						SendCharTargetFacing(CNtlPacket * pPacket);
	void						SendCharTargetInfo(CNtlPacket * pPacket);
	void						SendCharSitDown(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharStandUp(CNtlPacket * pPacket, CGameServer * app);
	
	void						SendCharFollowMove(CNtlPacket * pPacket, CGameServer * app);
	void						SendExcuteTriggerObject(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharBindReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendPortalStartReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendPortalAddReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendPortalTelReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendAttackBegin(CNtlPacket * pPacket, CGameServer * app);
	void						SendAttackEnd(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharToggleFighting(CNtlPacket * pPacket, CGameServer * app);
	void						AddAttackBegin(RwUInt32 uiSerialId, RwUInt32 m_uiTargetSerialId);
	void						RemoveAttackBegin(RwUInt32 uiSerialId, RwUInt32 m_uiTargetSerialId);
	void						SendCharActionAttack(RwUInt32 uiSerialId, RwUInt32 m_uiTargetSerialId, CNtlPacket * pPacket);
	void						SendCharUpdateFaintingState(CNtlPacket * pPacket, CGameServer * app, RwUInt32 uiSerialId, RwUInt32 m_uiTargetSerialId);
	void						SendCharUpdateLp(CNtlPacket * pPacket, CGameServer * app, RwUInt16 wLp, RwUInt32 m_uiTargetSerialId);

	void						SendGuildCreateReq(CNtlPacket * pPacket, CGameServer * app);

	void						SendPartyInviteReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendCreatePartyReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendDisbandPartyReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendPartyLeaveReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendPartyResponse(CNtlPacket * pPacket, CGameServer * app);

	void						SendCharMailStart(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharMailLoadReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharMailReloadReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharMailReadReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharMailSendReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharMailDelReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharMailItemReceiveReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharMailMultiDelReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharMailLockReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharMailReturnReq(CNtlPacket * pPacket, CGameServer * app);

	void						SendCharAwayReq(CNtlPacket * pPacket, CGameServer * app);

	void						SendShopStartReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendShopBuyReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendShopEndReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendShopSellReq(CNtlPacket * pPacket, CGameServer * app);


	void						SendShopSkillReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharLearnSkillReq(CNtlPacket * pPacket, CGameServer * app);

	void						SendItemMoveReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendItemDeleteReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendItemStackReq(CNtlPacket * pPacket, CGameServer * app);

	void						SendRollDice(CNtlPacket * pPacket, CGameServer * app);

	// SCOUTER
	void						SendScouterIndicatorReq(CNtlPacket * pPacket, CGameServer * app);
	// DRAGON BALL
	void						SendDragonBallCheckReq(CNtlPacket * pPacket, CGameServer * app);
	void						SendDragonBallRewardReq(CNtlPacket * pPacket, CGameServer * app);
	// SKILL
	void						SendCharSkillAction(CNtlPacket * pPacket, CGameServer * app);
	void						SendCharSkillRes(CNtlPacket * pPacket, CGameServer * app);
	//Game Server functions
	sGU_OBJECT_CREATE			characterspawnInfo;
	//
	PlayerInfos					*plr;
	GsFunctionsClass			*gsf;
private:
	CNtlPacketEncoder_RandKey	m_packetEncoder;
	RwUInt32					avatarHandle;


public:
	int		IsMonsterIDInsideList(TBLIDX MonsterSpawnID)
	{
		MyMonsterList * mymonsterlist;
		for( MYMONSTERLISTIT it = my_monsterList.begin(); it != my_monsterList.end(); it++ )
		{
			mymonsterlist = (*it);
			if(mymonsterlist->MonsterID == MonsterSpawnID)
			{
				return mymonsterlist->MobTBLIDX;
			}
		}
		return 0;
	}
	bool		IsMonsterInsideList(TBLIDX MonsterSpawnID)
	{
		MyMonsterList * mymonsterlist;
		for( MYMONSTERLISTIT it = my_monsterList.begin(); it != my_monsterList.end(); it++ )
		{
			mymonsterlist = (*it);
			if(mymonsterlist->MonsterID == MonsterSpawnID)
			{
				return true;
			}
		}
		return false;
	}
	void		InsertIntoMyMonsterList(TBLIDX MonsterSpawnID, CNtlVector Position, TBLIDX mobid)
	{
		MyMonsterList * myml = new MyMonsterList;

		myml->MonsterID = MonsterSpawnID;
		myml->Position = Position;
		myml->MobTBLIDX = mobid;

		my_monsterList.push_back(myml);
	}
	bool		RemoveFromMyMonsterList(TBLIDX MonsterSpawnID)
	{
		MyMonsterList * mymonsterlist;
		for( MYMONSTERLISTIT it = my_monsterList.begin(); it != my_monsterList.end(); it++ )
		{
			mymonsterlist = (*it);
			if(mymonsterlist->MonsterID == MonsterSpawnID)
			{
				it = my_monsterList.erase(it);
				return true;
			}
		}
		return true;
	}
typedef struct _MyMonsterList
{
	TBLIDX			MonsterID;
	CNtlVector		Position;
	TBLIDX			MobTBLIDX;

}MyMonsterList;
typedef std::list<MyMonsterList*> MYMONSTERLIST;
typedef MYMONSTERLIST::iterator MYMONSTERLISTIT;
MYMONSTERLIST					my_monsterList;


	void		InsertIntoMyNpcList(TBLIDX NpcSpawnID, CNtlVector Position)
	{
		MyNpcList * mynl = new MyNpcList;

		mynl->NpcID = NpcSpawnID;
		mynl->Position = Position;

		my_npcList.push_back(mynl);
	}
	bool		IsNpcInsideList(TBLIDX NpcSpawnID)
	{
		MyNpcList * mynpclist;
		for( MYNPCLISTIT it = my_npcList.begin(); it != my_npcList.end(); it++ )
		{
			mynpclist = (*it);
			if(mynpclist->NpcID == NpcSpawnID)
			{
				return true;
			}
		}
		return false;
	}
typedef struct _MyNpcList
{
	TBLIDX			NpcID;
	CNtlVector		Position;

}MyNpcList;
typedef std::list<MyNpcList*> MYNPCLIST;
typedef MYNPCLIST::iterator MYNPCLISTIT;
MYNPCLIST					my_npcList;

};
//---------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------//

class CGameSessionFactory : public CNtlSessionFactory
{
public:

	CNtlSession * CreateSession(SESSIONTYPE sessionType)
	{
		CNtlSession * pSession = NULL;
		switch( sessionType )
		{
		case SESSION_CLIENT: 
			{
				pSession = new CClientSession;
			}
			break;

		default:
			break;
		}

		return pSession;
	}
};

//---------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------//

class CGameServer : public CNtlServerApp
{

public:

	int					OnInitApp()
	{
		m_nMaxSessionCount = MAX_NUMOF_SESSION;
		m_pSessionFactory = new CGameSessionFactory;
		if( NULL == m_pSessionFactory )
		{
			return NTL_ERR_SYS_MEMORY_ALLOC_FAIL;
		}
		return NTL_SUCCESS;
	}
	int					OnCreate()
	{
		int rc = NTL_SUCCESS;
		rc = m_clientAcceptor.Create(	m_config.strClientAcceptAddr.c_str(), m_config.wClientAcceptPort, SESSION_CLIENT,MAX_NUMOF_GAME_CLIENT, 5, 2, MAX_NUMOF_GAME_CLIENT );
		if ( NTL_SUCCESS != rc )
		{
			return rc;
		}
		rc = m_network.Associate( &m_clientAcceptor, true );
		if( NTL_SUCCESS != rc )
		{
			return rc;
		}
		return NTL_SUCCESS;
	}
	void				OnDestroy()
	{
	}
	int					OnCommandArgument(int argc, _TCHAR* argv[])
	{
		return NTL_SUCCESS;
	}
	int					OnConfiguration(const char * lpszConfigFile)
	{
		CNtlIniFile file;
		int rc = file.Create( lpszConfigFile );
		if( NTL_SUCCESS != rc )
		{
			return rc;
		}
		if( !file.Read("Game Server", "Address", m_config.strClientAcceptAddr) )
		{
			return NTL_ERR_SYS_CONFIG_FILE_READ_FAIL;
		}
		if( !file.Read("Game Server", "Port",  m_config.wClientAcceptPort) )
		{
			return NTL_ERR_SYS_CONFIG_FILE_READ_FAIL;
		}
		return NTL_SUCCESS;
	}
	int					OnAppStart()
	{

		if(CreateTableContainer(1))
		{
			return NTL_SUCCESS;
		}else{
		printf("FAILED LOADING TABLES !!! \n");
		return NTL_SUCCESS;
		}
	}

private:
	CNtlAcceptor				m_clientAcceptor;
	CNtlLog  					m_log;
	sSERVERCONFIG				m_config;
public:
	MySQLConnWrapper			*db;
	MobActivity					*mob;
	QueryClass					*qry;
public:
	void						UpdateClient(CNtlPacket * pPacket, CClientSession *	pSession);
	CNtlPacket *				pPacket;
	CClientSession *			pSession;
	CTableContainer	*			g_pTableContainer;
	bool						CreateTableContainer(int byLoadMethod);

	void						Run()
	{
		DWORD dwTickCur, dwTickOld = ::GetTickCount();

		while( IsRunnable() )
		{		
			dwTickCur = ::GetTickCount();
			if( dwTickCur - dwTickOld >= 1000 )
			{
				UpdateClient(pPacket,pSession);
				dwTickOld = dwTickCur;
			}
		Sleep(100);
		}
	}

	bool						AddUser(const char * lpszUserID, CClientSession * pSession)
	{
		if( false == m_userList.insert( USERVAL(CNtlString(lpszUserID), pSession)).second )
		{
			return false;
		}
		return true;		
	}
	void						RemoveUser(const char * lpszUserID)
	{
		m_userList.erase( CNtlString(lpszUserID) );
	}
	bool						FindUser(const char * lpszUserID)
	{
		USERIT it = m_userList.find( CNtlString(lpszUserID) );
		if( it == m_userList.end() )
			return false;

		return true;
	}
	void						UserBroadcast(CNtlPacket * pPacket)
	{
		for( USERIT it = m_userList.begin(); it != m_userList.end(); it++ )
		{
			it->second->PushPacket( pPacket );
		}
	}

	void						UserBroadcastothers(CNtlPacket * pPacket, CClientSession * pSession)
	{
		for( USERIT it = m_userList.begin(); it != m_userList.end(); it++ )
		{
			if(pSession->GetavatarHandle() != it->second->GetavatarHandle())
			it->second->PushPacket( pPacket );
		}
	}
	void						UserBroadcasFromOthers(eOPCODE_GU opcode, CClientSession * pSession)
	{
		if(opcode == GU_OBJECT_CREATE)
		{
			for( USERIT it = m_userList.begin(); it != m_userList.end(); it++ )
			{
				if(pSession->GetavatarHandle() != it->second->GetavatarHandle())
				{
					CNtlPacket packet(sizeof(sGU_OBJECT_CREATE));
					sGU_OBJECT_CREATE * sPacket = (sGU_OBJECT_CREATE *)packet.GetPacketData();
					memcpy(sPacket, &it->second->characterspawnInfo, sizeof(sGU_OBJECT_CREATE));
					sPacket->handle = it->second->GetavatarHandle();

					packet.SetPacketLen( sizeof(sGU_OBJECT_CREATE) );
					pSession->PushPacket(&packet);
					//g_pApp->Send( this->GetHandle(), &packet );

				//it->second->PushPacket( pPacket );
				}
			}
		}
	}



void		InsertMonsterIntoAllMyMonsterLists(CNtlPacket * pPacket, TBLIDX MonsterSpawnID, CNtlVector Position, TBLIDX MonsterID)
{

	for( USERIT it = m_userList.begin(); it != m_userList.end(); it++ )
	{
		it->second->InsertIntoMyMonsterList(MonsterSpawnID, Position, MonsterID);
	}
}
void		RemoveMonsterFromAllMyMonsterLists(TBLIDX MonsterSpawnID)
{

	for( USERIT it = m_userList.begin(); it != m_userList.end(); it++ )
	{
		it->second->RemoveFromMyMonsterList(MonsterSpawnID);
	}
}






	typedef std::map<CNtlString, CClientSession*> USERLIST;
	typedef USERLIST::value_type USERVAL;
	typedef USERLIST::iterator USERIT;

	USERLIST					m_userList;
};

