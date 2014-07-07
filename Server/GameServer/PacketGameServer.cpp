#include "stdafx.h"
#include "NtlTokenizer.h"

#include "PacketGameServer.h"

#include "NtlPacketTU.h"
#include "NtlPacketUT.h"
#include "GameServer.h"


typedef std::list<SBattleData*> ListAttackBegin;
typedef ListAttackBegin::iterator BATTLEIT;
ListAttackBegin				m_listAttackBegin;


//--------------------------------------------------------------------------------------//
//		Log into Game Server
//--------------------------------------------------------------------------------------//
void CClientSession::SendGameEnterReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- LOAD CHAT SERVER --- \n");
	sUG_GAME_ENTER_REQ * req = (sUG_GAME_ENTER_REQ *)pPacket->GetPacketData();

	this->plr = new PlayerInfos();
	
	this->plr->SetcharID(req->charId);
	this->plr->SetAccountID(req->accountId);
	this->plr->SetAccountID(req->accountId);

	CNtlPacket packet(sizeof(sGU_GAME_ENTER_RES));
	sGU_GAME_ENTER_RES * res = (sGU_GAME_ENTER_RES *)packet.GetPacketData();

	res->wOpCode = GU_GAME_ENTER_RES;
	res->wResultCode = GAME_SUCCESS;
	strcpy_s(res->achCommunityServerIP, sizeof(res->achCommunityServerIP), "127.0.0.1");
	res->wCommunityServerPort = 20400;

	packet.SetPacketLen( sizeof(sGU_GAME_ENTER_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );
}
//--------------------------------------------------------------------------------------//
//		Send avatar char info
//--------------------------------------------------------------------------------------//
void CClientSession::SendAvatarCharInfo(CNtlPacket * pPacket, CGameServer * app)
{
	avatarHandle = AcquireSerialId();

	printf("--- LOAD CHARACTER INFO FOR GAMESERVER --- \n");
	CNtlPacket packet(sizeof(sGU_AVATAR_CHAR_INFO));
	sGU_AVATAR_CHAR_INFO * res = (sGU_AVATAR_CHAR_INFO *)packet.GetPacketData();

	app->db->prepare("UPDATE characters SET OnlineID = ? WHERE CharID = ?");
	app->db->setInt(1, avatarHandle);
	app->db->setInt(2,  this->plr->GetCharID());
	app->db->execute();

	app->db->prepare("SELECT * FROM characters WHERE CharID = ?");
	app->db->setInt(1,  this->plr->GetCharID());
	app->db->execute();
	app->db->fetch();

	this->plr->SetLevel(app->db->getInt("Level"));
	this->plr->SetMoney(app->db->getInt("Money"));
	this->plr->SetSpPoint(app->db->getInt("SpPoint"));

	CPCTable *pPcTable = app->g_pTableContainer->GetPcTable();
	sPC_TBLDAT *pTblData = (sPC_TBLDAT*)pPcTable->GetPcTbldat(app->db->getInt("Race"),app->db->getInt("Class"),app->db->getInt("Gender"));
	
	res->wOpCode = GU_AVATAR_CHAR_INFO;
	res->handle = avatarHandle;
	res->sPcProfile.tblidx = pTblData->tblidx;
	res->sPcProfile.bIsAdult = app->db->getBoolean("Adult");
	res->sPcProfile.charId = app->db->getInt("CharID");
	wcscpy_s(res->sPcProfile.awchName, NTL_MAX_SIZE_CHAR_NAME_UNICODE, s2ws(app->db->getString("CharName")).c_str() );
	//PC Shape
	res->sPcProfile.sPcShape.byFace = app->db->getInt("Face");
	res->sPcProfile.sPcShape.byHair = app->db->getInt("Hair");
	res->sPcProfile.sPcShape.byHairColor = app->db->getInt("HairColor");
	res->sPcProfile.sPcShape.bySkinColor = app->db->getInt("SkinColor");
	//Character Attribute
	res->sPcProfile.avatarAttribute.byBaseStr = app->db->getInt("BaseStr");
	res->sPcProfile.avatarAttribute.byLastStr = app->db->getInt("LastStr");
	res->sPcProfile.avatarAttribute.byBaseCon = app->db->getInt("BaseCon");
	res->sPcProfile.avatarAttribute.byLastCon = app->db->getInt("LastCon");
	res->sPcProfile.avatarAttribute.byBaseFoc = app->db->getInt("BaseFoc");
	res->sPcProfile.avatarAttribute.byLastFoc = app->db->getInt("LastFoc");
	res->sPcProfile.avatarAttribute.byBaseDex = app->db->getInt("BaseDex");
	res->sPcProfile.avatarAttribute.byLastDex = app->db->getInt("LastDex");
	res->sPcProfile.avatarAttribute.byBaseSol = app->db->getInt("BaseSol");
	res->sPcProfile.avatarAttribute.byLastSol = app->db->getInt("LastSol");
	res->sPcProfile.avatarAttribute.byBaseEng = app->db->getInt("BaseEng");
	res->sPcProfile.avatarAttribute.byLastEng = app->db->getInt("LastEng");
	res->sPcProfile.avatarAttribute.wBaseMaxLP = app->db->getInt("BaseMaxLP");
	res->sPcProfile.avatarAttribute.wLastMaxLP = app->db->getInt("BaseMaxLP");
	res->sPcProfile.avatarAttribute.wBaseMaxEP = app->db->getInt("BaseMaxEP");
	res->sPcProfile.avatarAttribute.wLastMaxEP = app->db->getInt("BaseMaxEP");
	res->sPcProfile.avatarAttribute.wBaseMaxRP = app->db->getInt("BaseMaxRP");
	res->sPcProfile.avatarAttribute.wLastMaxRP = app->db->getInt("BaseMaxRP");
	res->sPcProfile.avatarAttribute.wBasePhysicalOffence = app->db->getInt("BasePhysicalOffence");
	res->sPcProfile.avatarAttribute.wLastPhysicalOffence = app->db->getInt("LastPhysicalOffence");
	res->sPcProfile.avatarAttribute.wBasePhysicalDefence = app->db->getInt("BasePhysicalDefence");
	res->sPcProfile.avatarAttribute.wLastPhysicalDefence = app->db->getInt("LastPhysicalDefence");
	res->sPcProfile.avatarAttribute.wBaseEnergyOffence = app->db->getInt("BaseEnergyOffence");
	res->sPcProfile.avatarAttribute.wLastEnergyOffence = app->db->getInt("LastEnergyOffence");
	res->sPcProfile.avatarAttribute.wBaseEnergyDefence = app->db->getInt("BaseEnergyDefence");
	res->sPcProfile.avatarAttribute.wLastEnergyDefence = app->db->getInt("LastEnergyDefence");
	res->sPcProfile.avatarAttribute.wBaseAttackRate = app->db->getInt("BaseAttackRate");
	res->sPcProfile.avatarAttribute.wLastAttackRate = app->db->getInt("LastAttackRate");
	res->sPcProfile.avatarAttribute.wBaseDodgeRate = app->db->getInt("BaseDodgeRate");
	res->sPcProfile.avatarAttribute.wLastDodgeRate = app->db->getInt("LastDodgeRate");
	res->sPcProfile.avatarAttribute.wBaseBlockRate = app->db->getInt("BaseBlockRate");
	res->sPcProfile.avatarAttribute.wLastBlockRate = app->db->getInt("LastBlockRate");
	res->sPcProfile.avatarAttribute.wLastPhysicalCriticalRate = app->db->getInt("LastPhysicalCriticalRate");
	res->sPcProfile.avatarAttribute.wLastEnergyCriticalRate = app->db->getInt("LastEnergyCriticalRate");
	res->sPcProfile.avatarAttribute.fLastRunSpeed = (float)app->db->getDouble("LastRunSpeed");
	res->sPcProfile.wCurLP = app->db->getInt("CurLP");
	res->sPcProfile.wCurEP = app->db->getInt("CurEP");
	res->sPcProfile.wCurRP = app->db->getInt("CurRP");
	res->sPcProfile.byLevel = app->db->getInt("Level");
	res->sPcProfile.dwCurExp = app->db->getInt("Exp");
	res->sPcProfile.dwMaxExpInThisLevel = app->db->getInt("MaxExpInThisLevel");
	res->sPcProfile.dwZenny = app->db->getInt("Money");
	res->sPcProfile.dwTutorialHint = 0;
	res->sPcProfile.dwReputation = app->db->getInt("Reputation");
	res->sPcProfile.dwMudosaPoint = app->db->getInt("MudosaPoint");
	res->sPcProfile.dwSpPoint = app->db->getInt("SpPoint");

	// Character State
	res->sCharState.sCharStateBase.vCurLoc.x = (float)app->db->getDouble("CurLocX");
	res->sCharState.sCharStateBase.vCurLoc.y = (float)app->db->getDouble("CurLocY");
	res->sCharState.sCharStateBase.vCurLoc.z = (float)app->db->getDouble("CurLocZ");
	res->sCharState.sCharStateBase.vCurDir.x = (float)app->db->getDouble("CurDirX");
	res->sCharState.sCharStateBase.vCurDir.y = (float)app->db->getDouble("CurDirY");
	res->sCharState.sCharStateBase.vCurDir.z = (float)app->db->getDouble("CurDirZ");
	res->sCharState.sCharStateBase.dwConditionFlag = 0;
	res->sCharState.sCharStateBase.byStateID = 0;
	res->sCharState.sCharStateBase.aspectState.sAspectStateBase.byAspectStateId = 255;
	res->sCharState.sCharStateBase.aspectState.sAspectStateDetail.sGreatNamek.bySourceGrade = 0;
	res->sCharState.sCharStateBase.aspectState.sAspectStateDetail.sKaioken.bySourceGrade = 0;
	res->sCharState.sCharStateBase.aspectState.sAspectStateDetail.sPureMajin.bySourceGrade = 0;
	res->sCharState.sCharStateBase.aspectState.sAspectStateDetail.sSuperSaiyan.bySourceGrade = 0;
	res->sCharState.sCharStateBase.aspectState.sAspectStateDetail.sVehicle.idVehicleTblidx = 0;
	res->wCharStateSize = sizeof(sCHARSTATE_BASE);

	res->sPcProfile.bIsGameMaster = app->db->getBoolean("GameMaster");
	this->plr->SetName(app->db->getString("CharName"));
	this->plr->SetPosition(res->sCharState.sCharStateBase.vCurLoc, res->sCharState.sCharStateBase.vCurDir);
	this->plr->SetCurEp(res->sPcProfile.wCurEP);
	this->plr->SetCurLp(res->sPcProfile.wCurLP);
	this->plr->SetCurRp(res->sPcProfile.wCurRP);
	this->plr->SetLevel(res->sPcProfile.byLevel);
	this->plr->SetCurExp(res->sPcProfile.dwCurExp);
	this->plr->SetReputation(res->sPcProfile.dwReputation);
	this->plr->SetMoney(res->sPcProfile.dwZenny);
	this->plr->SetMudosaPoint(res->sPcProfile.dwMudosaPoint);
	this->plr->SetSpPoint(res->sPcProfile.dwSpPoint);
	this->plr->SetBaseStr(res->sPcProfile.avatarAttribute.byBaseStr);
	this->plr->SetLastStr(res->sPcProfile.avatarAttribute.byLastStr);
	this->plr->SetBaseCon(res->sPcProfile.avatarAttribute.byBaseCon);
	this->plr->SetLastCon(res->sPcProfile.avatarAttribute.byLastCon);
	this->plr->SetBaseFoc(res->sPcProfile.avatarAttribute.byBaseFoc);
	this->plr->SetLastFoc(res->sPcProfile.avatarAttribute.byLastFoc);
	this->plr->SetBaseDex(res->sPcProfile.avatarAttribute.byBaseDex);
	this->plr->SetLastDex(res->sPcProfile.avatarAttribute.byLastDex);
	this->plr->SetBaseSol(res->sPcProfile.avatarAttribute.byBaseSol);
	this->plr->SetLastSol(res->sPcProfile.avatarAttribute.byLastSol);
	this->plr->SetBaseEng(res->sPcProfile.avatarAttribute.byBaseEng);
	this->plr->SetLastEng(res->sPcProfile.avatarAttribute.byLastEng);
	this->plr->SetBaseMaxLp(res->sPcProfile.avatarAttribute.wBaseMaxLP);
	this->plr->SetLastMaxLp(res->sPcProfile.avatarAttribute.wLastMaxLP);
	this->plr->SetBaseMaxEp(res->sPcProfile.avatarAttribute.wBaseMaxEP);
	this->plr->SetLastMaxEp(res->sPcProfile.avatarAttribute.wLastMaxEP);
	this->plr->SetBaseMaxRp(res->sPcProfile.avatarAttribute.wBaseMaxRP);
	this->plr->SetLastMaxRp(res->sPcProfile.avatarAttribute.wLastMaxRP);
	this->plr->SetBasePhysicalOffence(res->sPcProfile.avatarAttribute.wBasePhysicalOffence);
	this->plr->SetLastPhysicalOffence(res->sPcProfile.avatarAttribute.wLastPhysicalOffence);
	this->plr->SetBasePhysicalDefence(res->sPcProfile.avatarAttribute.wBasePhysicalDefence);
	this->plr->SetLastPhysicalDefence(res->sPcProfile.avatarAttribute.wLastPhysicalDefence);
	this->plr->SetBaseEnergyOffence(res->sPcProfile.avatarAttribute.wBaseEnergyOffence);
	this->plr->SetLastEnergyOffence(res->sPcProfile.avatarAttribute.wLastEnergyOffence);
	this->plr->SetBaseEnergyDefence(res->sPcProfile.avatarAttribute.wBaseEnergyDefence);
	this->plr->SetLastEnergyDefence(res->sPcProfile.avatarAttribute.wLastEnergyDefence);
	this->plr->SetBaseAttackRate(res->sPcProfile.avatarAttribute.wBaseAttackRate);
	this->plr->SetLastAttackRate(res->sPcProfile.avatarAttribute.wLastAttackRate);
	this->plr->SetBaseDodgeRate(res->sPcProfile.avatarAttribute.wBaseDodgeRate);
	this->plr->SetLastDodgeRate(res->sPcProfile.avatarAttribute.wLastDodgeRate);
	this->plr->SetBaseBlockRate(res->sPcProfile.avatarAttribute.wBaseBlockRate);
	this->plr->SetLastBlockRate(res->sPcProfile.avatarAttribute.wLastBlockRate);
	this->plr->SetLastPhysicalCriticalRate(res->sPcProfile.avatarAttribute.wLastPhysicalCriticalRate);
	this->plr->SetLastEnergyCriticalRate(res->sPcProfile.avatarAttribute.wLastEnergyCriticalRate);
	this->plr->SetLastRunSpeed(res->sPcProfile.avatarAttribute.fLastRunSpeed);

	packet.SetPacketLen( sizeof(sGU_AVATAR_CHAR_INFO) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );
}

//--------------------------------------------------------------------------------------//
//		Send Avatar Iteminfo
//--------------------------------------------------------------------------------------//
void CClientSession::SendAvatarItemInfo(CNtlPacket * pPacket, CGameServer * app)
{
	size_t i = 0;

	app->db->prepare("SELECT * FROM items WHERE owner_id = ?");
	app->db->setInt(1, this->plr->GetCharID());
	app->db->execute();

	CNtlPacket packet(sizeof(sGU_AVATAR_ITEM_INFO));
	sGU_AVATAR_ITEM_INFO * res = (sGU_AVATAR_ITEM_INFO *)packet.GetPacketData();

	res->wOpCode = GU_AVATAR_ITEM_INFO;
	res->byBeginCount = 0;
	res->byItemCount = app->db->rowsCount();

	printf("count rows: %d \n", app->db->rowsCount());
	while( app->db->fetch() )
	{
		res->aItemProfile[i].handle = app->db->getInt("id");
		res->aItemProfile[i].tblidx = app->db->getInt("tblidx");
		res->aItemProfile[i].byPlace = app->db->getInt("place");
		res->aItemProfile[i].byPos = app->db->getInt("pos");
		res->aItemProfile[i].byStackcount = app->db->getInt("count");
		res->aItemProfile[i].byRank = app->db->getInt("rank");
		res->aItemProfile[i].byCurDur = app->db->getInt("durability");

		packet.AdjustPacketLen(sizeof(sNTLPACKETHEADER)+(2 * sizeof(BYTE)) + (res->byItemCount * sizeof(sITEM_PROFILE)));
		g_pApp->Send( this->GetHandle() , &packet );

		i++;
	}
}

//--------------------------------------------------------------------------------------//
//		Send Avatar Skillinfo
//--------------------------------------------------------------------------------------//
void CClientSession::SendAvatarSkillInfo(CNtlPacket * pPacket, CGameServer * app)
{
	size_t i = 0;

	app->db->prepare("SELECT * FROM skills WHERE owner_id = ?");
	app->db->setInt(1, this->plr->GetCharID());
	app->db->execute();

	CNtlPacket packet(sizeof(sGU_AVATAR_SKILL_INFO));
	sGU_AVATAR_SKILL_INFO * res = (sGU_AVATAR_SKILL_INFO *)packet.GetPacketData();

	res->wOpCode = GU_AVATAR_SKILL_INFO;
	res->bySkillCount = app->db->rowsCount();

	printf("count rows: %d \n", app->db->rowsCount());
	while( app->db->fetch() )
	{
		res->aSkillInfo[i].bIsRpBonusAuto = app->db->getBoolean("RpBonusAuto");
		res->aSkillInfo[i].byRpBonusType = app->db->getInt("RpBonusType");
		res->aSkillInfo[i].bySlotId = app->db->getInt("SlotID");
		res->aSkillInfo[i].dwTimeRemaining = app->db->getInt("TimeRemaining");
		res->aSkillInfo[i].nExp = app->db->getInt("Exp");
		res->aSkillInfo[i].tblidx = app->db->getInt("skill_id");

		packet.AdjustPacketLen(sizeof(sNTLPACKETHEADER)+(2 * sizeof(BYTE)) + (res->bySkillCount * sizeof(sITEM_PROFILE)));
		g_pApp->Send( this->GetHandle() , &packet );

		i++;
	}

}


//--------------------------------------------------------------------------------------//
//		SendAvatarInfoEnd
//--------------------------------------------------------------------------------------//
void CClientSession::SendAvatarInfoEnd(CNtlPacket * pPacket)
{
	printf("--- SendAvatarInfoEnd --- \n");
	CNtlPacket packet(sizeof(sGU_AVATAR_INFO_END));
	sGU_AVATAR_INFO_END * res = (sGU_AVATAR_INFO_END *)packet.GetPacketData();

	res->wOpCode = GU_AVATAR_INFO_END;

	packet.SetPacketLen( sizeof(sGU_AVATAR_INFO_END) );
	g_pApp->Send( this->GetHandle(), &packet );
}

//--------------------------------------------------------------------------------------//
//		Login into World
//--------------------------------------------------------------------------------------//
void CClientSession::SendWorldEnterReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- sGU_AVATAR_WORLD_INFO --- \n");

	CNtlPacket packet(sizeof(sGU_AVATAR_WORLD_INFO));
	sGU_AVATAR_WORLD_INFO * res = (sGU_AVATAR_WORLD_INFO *)packet.GetPacketData();

	app->db->prepare("SELECT * FROM characters WHERE CharID = ?");
	app->db->setInt(1, this->plr->GetCharID());
	app->db->execute();
	app->db->fetch();

	res->wOpCode = GU_AVATAR_WORLD_INFO;
	res->worldInfo.tblidx = app->db->getInt("WorldTable");
	res->worldInfo.worldID = app->db->getInt("WorldID");
	res->worldInfo.hTriggerObjectOffset = 100000;
	res->worldInfo.sRuleInfo.byRuleType = GAMERULE_NORMAL;
	res->vCurLoc.x = this->plr->GetPosition().x;
	res->vCurLoc.y = this->plr->GetPosition().y;
	res->vCurLoc.z = this->plr->GetPosition().z;
	res->vCurDir.x = this->plr->GetDirection().x;
	res->vCurDir.y = this->plr->GetDirection().y;
	res->vCurDir.z = this->plr->GetDirection().z;

	this->plr->SetWorldID(app->db->getInt("WorldID"));
	this->plr->SetWorldTableID(app->db->getInt("WorldTable"));

	packet.SetPacketLen( sizeof(sGU_AVATAR_WORLD_INFO) );
	g_pApp->Send( this->GetHandle(), &packet );

}
//--------------------------------------------------------------------------------------//
//		Character ready request
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharReadyReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- sGU_OBJECT_CREATE --- \n");


//SPAWN PLAYERS
	CNtlPacket packet(sizeof(sGU_OBJECT_CREATE));
	sGU_OBJECT_CREATE * res = (sGU_OBJECT_CREATE *)packet.GetPacketData();

	app->db->prepare("SELECT * FROM characters WHERE CharID = ?");
	app->db->setInt(1, this->plr->GetCharID());
	app->db->execute();
	app->db->fetch();

	this->plr->SetName(app->db->getString("CharName").c_str());

	CPCTable *pPcTable = app->g_pTableContainer->GetPcTable();
	sPC_TBLDAT *pTblData = (sPC_TBLDAT*)pPcTable->GetPcTbldat(app->db->getInt("Race"),app->db->getInt("Class"),app->db->getInt("Gender"));

	res->wOpCode = GU_OBJECT_CREATE;
	res->handle = this->GetavatarHandle();
	res->sObjectInfo.objType = OBJTYPE_PC;
	res->sObjectInfo.pcBrief.tblidx = pTblData->tblidx;
	res->sObjectInfo.pcBrief.bIsAdult = app->db->getBoolean("Adult");
	wcscpy_s(res->sObjectInfo.pcBrief.awchName, NTL_MAX_SIZE_CHAR_NAME_UNICODE, s2ws(app->db->getString("CharName")).c_str() );
	wcscpy_s(res->sObjectInfo.pcBrief.wszGuildName, NTL_MAX_SIZE_GUILD_NAME_IN_UNICODE, s2ws(app->db->getString("GuildName")).c_str() );
	res->sObjectInfo.pcBrief.sPcShape.byFace = app->db->getInt("Face");
	res->sObjectInfo.pcBrief.sPcShape.byHair = app->db->getInt("Hair");
	res->sObjectInfo.pcBrief.sPcShape.byHairColor = app->db->getInt("HairColor");
	res->sObjectInfo.pcBrief.sPcShape.bySkinColor = app->db->getInt("SkinColor");
	res->sObjectInfo.pcBrief.wCurLP = app->db->getInt("CurLP");
	res->sObjectInfo.pcBrief.wMaxLP = app->db->getInt("BaseMaxLP");
	res->sObjectInfo.pcBrief.wCurEP = app->db->getInt("CurEP");
	res->sObjectInfo.pcBrief.wMaxEP = app->db->getInt("BaseMaxEP");
	res->sObjectInfo.pcBrief.byLevel = app->db->getInt("Level");
	res->sObjectInfo.pcBrief.fSpeed = (float)app->db->getDouble("LastRunSpeed");
	res->sObjectInfo.pcBrief.wAttackSpeedRate = app->db->getInt("BaseAttackSpeedRate");
	res->sObjectInfo.pcState.sCharStateBase.vCurLoc.x = this->plr->GetPosition().x;
	res->sObjectInfo.pcState.sCharStateBase.vCurLoc.y = this->plr->GetPosition().y;
	res->sObjectInfo.pcState.sCharStateBase.vCurLoc.z = this->plr->GetPosition().z;
	res->sObjectInfo.pcState.sCharStateBase.vCurDir.x = this->plr->GetDirection().x;
	res->sObjectInfo.pcState.sCharStateBase.vCurDir.y = this->plr->GetDirection().y;
	res->sObjectInfo.pcState.sCharStateBase.vCurDir.z = this->plr->GetDirection().z;
	res->sObjectInfo.pcState.sCharStateBase.dwConditionFlag = 0;
	res->sObjectInfo.pcState.sCharStateBase.byStateID = 0;
	res->sObjectInfo.pcState.sCharStateBase.aspectState.sAspectStateBase.byAspectStateId = 255;
	res->sObjectInfo.pcState.sCharStateBase.aspectState.sAspectStateDetail.sGreatNamek.bySourceGrade = 0;
	res->sObjectInfo.pcState.sCharStateBase.aspectState.sAspectStateDetail.sKaioken.bySourceGrade = 0;
	res->sObjectInfo.pcState.sCharStateBase.aspectState.sAspectStateDetail.sPureMajin.bySourceGrade = 0;
	res->sObjectInfo.pcState.sCharStateBase.aspectState.sAspectStateDetail.sSuperSaiyan.bySourceGrade = 0;
	res->sObjectInfo.pcState.sCharStateBase.aspectState.sAspectStateDetail.sVehicle.idVehicleTblidx = 0;
	this->plr->SetGuildName(app->db->getString("GuildName"));

	for(int i = 0; i < NTL_MAX_EQUIP_ITEM_SLOT; i++)
	{
	app->db->prepare("select * from items WHERE place=7 AND pos=? AND owner_id=?");
	app->db->setInt(1, i);
	app->db->setInt(2, this->plr->GetCharID());
	app->db->execute();
	app->db->fetch();
	if(app->db->rowsCount() == 0)
		{
			res->sObjectInfo.pcBrief.sItemBrief[i].tblidx =  INVALID_TBLIDX;
		}
		else
		{
			
		res->sObjectInfo.pcBrief.sItemBrief[i].tblidx = app->db->getInt("tblidx");
		}

	}

	memcpy(&this->characterspawnInfo, res, sizeof(sGU_OBJECT_CREATE) );
	packet.SetPacketLen( sizeof(sGU_OBJECT_CREATE) );

	app->UserBroadcastothers(&packet, this);
	app->UserBroadcasFromOthers(GU_OBJECT_CREATE, this);
	app->AddUser(this->plr->GetName().c_str(), this);

}

//--------------------------------------------------------------------------------------//
//		Auth community Server
//--------------------------------------------------------------------------------------//
void CClientSession::SendAuthCommunityServer(CNtlPacket * pPacket, CGameServer * app)
{

	CNtlPacket packet(sizeof(sGU_AUTH_KEY_FOR_COMMUNITY_SERVER_RES));
	sGU_AUTH_KEY_FOR_COMMUNITY_SERVER_RES * res = (sGU_AUTH_KEY_FOR_COMMUNITY_SERVER_RES *)packet.GetPacketData();

	res->wOpCode = GU_AUTH_KEY_FOR_COMMUNITY_SERVER_RES;
	res->wResultCode = GAME_SUCCESS;
	strcpy_s((char*)res->abyAuthKey, NTL_MAX_SIZE_AUTH_KEY, "ChatCon");
	packet.SetPacketLen( sizeof(sGU_AUTH_KEY_FOR_COMMUNITY_SERVER_RES) );
	g_pApp->Send( this->GetHandle(), &packet );

}

//--------------------------------------------------------------------------------------//
//		SPAWN NPC
//--------------------------------------------------------------------------------------//
void CClientSession::SendNpcCreate(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- CREATE NPCS --- \n");
	app->mob->SpawnNpcAtLogin(pPacket, this);
}
//--------------------------------------------------------------------------------------//
//		SPAWN MOBS
//--------------------------------------------------------------------------------------//
void CClientSession::SendMonsterCreate(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- CREATE MOBS --- \n");

	app->mob->SpawnMonsterAtLogin(pPacket, this);

}
//--------------------------------------------------------------------------------------//
//		SendEnterWorldComplete
//--------------------------------------------------------------------------------------//
void CClientSession::SendEnterWorldComplete(CNtlPacket * pPacket)
{
	printf("--- SendEnterWorldComplete --- \n");

	CNtlPacket packet(sizeof(sGU_ENTER_WORLD_COMPLETE));
	sGU_ENTER_WORLD_COMPLETE * res = (sGU_ENTER_WORLD_COMPLETE *)packet.GetPacketData();

	res->wOpCode = GU_ENTER_WORLD_COMPLETE;

	packet.SetPacketLen( sizeof(sGU_ENTER_WORLD_COMPLETE) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );
}

//--------------------------------------------------------------------------------------//
//		Tutorial Hint request
//--------------------------------------------------------------------------------------//
void CClientSession::SendTutorialHintReq(CNtlPacket * pPacket, CGameServer * app)
{
	sUG_TUTORIAL_HINT_UPDATE_REQ * req = (sUG_TUTORIAL_HINT_UPDATE_REQ *)pPacket->GetPacketData();
	//req->dwTutorialHint;
	printf("--- TUTORIAL HINT REQUEST %i --- \n", req->dwTutorialHint);

	CNtlPacket packet(sizeof(sGU_TUTORIAL_HINT_UPDATE_RES));
	sGU_TUTORIAL_HINT_UPDATE_RES * res = (sGU_TUTORIAL_HINT_UPDATE_RES *)packet.GetPacketData();

	//app->db->prepare("SELECT * FROM characters WHERE CharID = ?");
	//app->db->setInt(1, this->characterID);
	//app->db->execute();
	//app->db->fetch();
	res->wOpCode = GU_TUTORIAL_HINT_UPDATE_RES;
	res->wResultCode = GAME_SUCCESS;
	res->dwTutorialHint = req->dwTutorialHint;

	packet.SetPacketLen( sizeof(sGU_TUTORIAL_HINT_UPDATE_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );
}

//--------------------------------------------------------------------------------------//
//		Char Ready
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharReady(CNtlPacket * pPacket)
{
	printf("--- SEND CHAR READY --- \n");

	CNtlPacket packet(sizeof(sUG_CHAR_READY));
	sUG_CHAR_READY * res = (sUG_CHAR_READY *)packet.GetPacketData();

	res->wOpCode = UG_CHAR_READY;
	res->byAvatarType = 0;

	packet.SetPacketLen( sizeof(sUG_CHAR_READY) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );

}

//--------------------------------------------------------------------------------------//
//		Char Move
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharMove(CNtlPacket * pPacket, CGameServer * app)
{
	//printf("--- SEND CHAR MOVE --- \n");

	sUG_CHAR_MOVE * req = (sUG_CHAR_MOVE*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_CHAR_MOVE));
	sGU_CHAR_MOVE * res = (sGU_CHAR_MOVE *)packet.GetPacketData();

	res->wOpCode = GU_CHAR_MOVE;
	res->handle = this->GetavatarHandle();
	res->dwTimeStamp = req->dwTimeStamp;
	res->vCurLoc.x = req->vCurLoc.x;
	res->vCurLoc.y = req->vCurLoc.y;
	res->vCurLoc.z = req->vCurLoc.z;
	res->vCurDir.x = req->vCurDir.x;
	res->vCurDir.y = 0;
	res->vCurDir.z = req->vCurDir.z;
	res->byMoveDirection = req->byMoveDirection;
	res->byMoveFlag = NTL_MOVE_FIRST;

	this->plr->SetPosition(res->vCurLoc, res->vCurDir);

	packet.SetPacketLen( sizeof(sGU_CHAR_MOVE) );
	app->UserBroadcastothers(&packet, this);

}
//--------------------------------------------------------------------------------------//
//		Char Destination Move
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharDestMove(CNtlPacket * pPacket, CGameServer * app)
{
	//printf("--- CHARACTER REQUEST DEST MOVE --- \n");

	sUG_CHAR_DEST_MOVE * req = (sUG_CHAR_DEST_MOVE*)pPacket->GetPacketData();
	
	CNtlPacket packet(sizeof(sGU_CHAR_DEST_MOVE));
	sGU_CHAR_DEST_MOVE * res = (sGU_CHAR_DEST_MOVE *)packet.GetPacketData();
	
	res->wOpCode = GU_CHAR_DEST_MOVE;
	res->handle = this->GetavatarHandle();
	res->dwTimeStamp = req->dwTimeStamp;
	res->vCurLoc.x = req->vCurLoc.x;
	res->vCurLoc.y = req->vCurLoc.y;
	res->vCurLoc.z = req->vCurLoc.z;
	res->byMoveFlag = NTL_MOVE_MOUSE_MOVEMENT;
	res->bHaveSecondDestLoc = false;
	res->byDestLocCount = 1;
	res->avDestLoc[0].x = req->vDestLoc.x;
	res->avDestLoc[0].y = req->vDestLoc.y;
	res->avDestLoc[0].z = req->vDestLoc.z;

	packet.SetPacketLen( sizeof(sGU_CHAR_DEST_MOVE) );
	app->UserBroadcastothers(&packet, this);


	if(timeGetTime() - this->plr->Getmob_SpawnTime() >= MONSTER_SPAWN_UPDATE_TICK)
	{
		app->mob->RunSpawnCheck(&packet, this->plr->GetPosition(), this);
		this->plr->Setmob_SpawnTime(timeGetTime());
	}

}
//--------------------------------------------------------------------------------------//
//		Char Move Sync
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharMoveSync(CNtlPacket * pPacket, CGameServer * app)
{
	//printf("--- CHARACTER MOVE SYNC --- \n");
	sUG_CHAR_MOVE_SYNC * req = (sUG_CHAR_MOVE_SYNC*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_CHAR_MOVE_SYNC));
	sGU_CHAR_MOVE_SYNC * res = (sGU_CHAR_MOVE_SYNC *)packet.GetPacketData();

	res->wOpCode = GU_CHAR_MOVE_SYNC;
	res->handle = this->GetavatarHandle();
	res->vCurLoc.x = req->vCurLoc.x;
	res->vCurLoc.y = req->vCurLoc.y;
	res->vCurLoc.z = req->vCurLoc.z;
	res->vCurDir.x = req->vCurDir.x;
	res->vCurDir.y = req->vCurDir.y;
	res->vCurDir.z = req->vCurDir.z;

	packet.SetPacketLen( sizeof(sGU_CHAR_MOVE_SYNC) );
	app->UserBroadcastothers(&packet, this);

	if(timeGetTime() - this->plr->Getmob_SpawnTime() >= MONSTER_SPAWN_UPDATE_TICK)
	{
		app->mob->RunSpawnCheck(&packet, this->plr->GetPosition(), this);
		this->plr->Setmob_SpawnTime(timeGetTime());
	}
}
//--------------------------------------------------------------------------------------//
//		Char Change Heading
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharChangeHeading(CNtlPacket * pPacket, CGameServer * app)
{
	//printf("--- CHARACTER CHANGE HEADING --- \n");
	sUG_CHAR_CHANGE_HEADING * req = (sUG_CHAR_CHANGE_HEADING*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_CHAR_CHANGE_HEADING));
	sGU_CHAR_CHANGE_HEADING * res = (sGU_CHAR_CHANGE_HEADING *)packet.GetPacketData();

	res->wOpCode = GU_CHAR_CHANGE_HEADING;
	res->handle = this->GetavatarHandle();
	res->vNewHeading.x = req->vCurrentHeading.x;
	res->vNewHeading.y = req->vCurrentHeading.y;
	res->vNewHeading.z = req->vCurrentHeading.z;
	res->vNewLoc.x = req->vCurrentPosition.x;
	res->vNewLoc.y = req->vCurrentPosition.y;
	res->vNewLoc.z = req->vCurrentPosition.z;

	packet.SetPacketLen( sizeof(sGU_CHAR_CHANGE_HEADING) );
	app->UserBroadcastothers(&packet, this);
}
//--------------------------------------------------------------------------------------//
//		Char Jump
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharJump(CNtlPacket * pPacket, CGameServer * app)
{
	//printf("--- CHARACTER JUMP --- \n");
	sUG_CHAR_CHANGE_HEADING * req = (sUG_CHAR_CHANGE_HEADING*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_CHAR_JUMP));
	sGU_CHAR_JUMP * res = (sGU_CHAR_JUMP *)packet.GetPacketData();

	res->wOpCode = GU_CHAR_JUMP;
	res->handle = this->GetavatarHandle();
	res->vCurrentHeading.x = req->vCurrentHeading.x;
	res->vCurrentHeading.y = req->vCurrentHeading.y;
	res->vCurrentHeading.z = req->vCurrentHeading.z;

	res->vJumpDir.x = 0;
	res->vJumpDir.y = 0;
	res->vJumpDir.z = 0;

	res->byMoveDirection = 1;

	packet.SetPacketLen( sizeof(sGU_CHAR_JUMP) );
	app->UserBroadcastothers(&packet, this);

}
//--------------------------------------------------------------------------------------//
//		Change Char Direction on floating
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharChangeDirOnFloating(CNtlPacket * pPacket, CGameServer * app)
{
//	printf("--- Change Char Direction on floating --- \n");
	sUG_CHAR_CHANGE_DIRECTION_ON_FLOATING * req = (sUG_CHAR_CHANGE_DIRECTION_ON_FLOATING*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_CHAR_CHANGE_DIRECTION_ON_FLOATING));
	sGU_CHAR_CHANGE_DIRECTION_ON_FLOATING * res = (sGU_CHAR_CHANGE_DIRECTION_ON_FLOATING *)packet.GetPacketData();

	res->wOpCode = GU_CHAR_CHANGE_DIRECTION_ON_FLOATING;
	res->hSubject = this->GetavatarHandle();
	res->vCurDir.x = req->vCurDir.x;
	res->vCurDir.y = req->vCurDir.y;
	res->vCurDir.z = req->vCurDir.z;
	res->byMoveDirection = req->byMoveDirection;

	packet.SetPacketLen( sizeof(sGU_CHAR_CHANGE_DIRECTION_ON_FLOATING) );
	app->UserBroadcastothers(&packet, this);
}
//--------------------------------------------------------------------------------------//
//		Char falling
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharFalling(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- character falling --- \n");
	sUG_CHAR_FALLING * req = (sUG_CHAR_FALLING*)pPacket->GetPacketData();

	req->wOpCode = UG_CHAR_FALLING;
	req->bIsFalling = true;

	req->vCurLoc.x;
	req->vCurLoc.y;
	req->vCurLoc.z;
	req->vCurDir.x;
	req->vCurDir.z;
	req->byMoveDirection;

}

//--------------------------------------------------------------------------------------//
//		GM Command
//--------------------------------------------------------------------------------------//
void CClientSession::RecvServerCommand(CNtlPacket * pPacket, CGameServer * app)
{
	sUG_SERVER_COMMAND * pServerCmd = (sUG_SERVER_COMMAND*)pPacket;

	char chBuffer[1024];
	::WideCharToMultiByte(GetACP(), 0, pServerCmd->awchCommand, -1, chBuffer, 1024, NULL, NULL);

	CNtlTokenizer lexer(chBuffer);

	if(!lexer.IsSuccess())
		return;

	enum ECmdParseState
	{
		SERVER_CMD_NONE,
		SERVER_CMD_KEY,
		SERVER_CMD_END,
	};

	ECmdParseState eState = SERVER_CMD_KEY;
	int iOldLine = 0;
	int iLine;
	
	while(1)
	{
		std::string strToken = lexer.PeekNextToken(NULL, &iLine);

		if(strToken == "") 
			break;
	
		switch (eState)
		{
		case SERVER_CMD_KEY:
			if(strToken == "@setspeed")
			{
				printf("received char speed command");
				lexer.PopToPeek();
				strToken = lexer.PeekNextToken(NULL, &iLine);
				float fSpeed = (float)atof(strToken.c_str());
				CClientSession::SendUpdateCharSpeed(fSpeed, app);
				return;
			}
			else if(strToken == "@addmob")
			{
				lexer.PopToPeek();
				strToken = lexer.PeekNextToken(NULL, &iLine);
				unsigned int uiMobId = (unsigned int)atoi(strToken.c_str());
				lexer.PopToPeek();
				strToken = lexer.PeekNextToken(NULL, &iLine);
				float fDist = (float)atof(strToken.c_str());
				lexer.PopToPeek();

				//SendMonsterCreate(uiMobId, fDist);
				
				return;
			}
			else if(strToken == "@addmobg")
			{
				lexer.PopToPeek();
				strToken = lexer.PeekNextToken(NULL, &iLine);
				unsigned int iNum = (unsigned int)atoi(strToken.c_str());
				//SendMonsterGroupCreate(iNum);
				return;
			}
			else if(strToken == "@createitem")
			{
				lexer.PopToPeek();
				strToken = lexer.PeekNextToken(NULL, &iLine);
				unsigned int uiTblId = (unsigned int)atof(strToken.c_str());
			//	SendAddItem(uiTblId);
				return;
			}
			else if(strToken == "@learnskill")
			{
				lexer.PopToPeek();
				strToken = lexer.PeekNextToken(NULL, &iLine);
				unsigned int uiTblId = (unsigned int)atof(strToken.c_str());
			//	SendCharLearnSkillRes(uiTblId);
				return;
			}
			else if(strToken == "@learnhtb")
			{
				lexer.PopToPeek();
				strToken = lexer.PeekNextToken(NULL, &iLine);
				unsigned int uiTblId = (unsigned int)atof(strToken.c_str());
			//	SendCharLearnHTBRes(uiTblId);
				return;
			}
			else if(strToken == "@refreshlp")
			{
			//	app->db->prepare("SELECT LastMaxLp FROM characters WHERE CharID = ?");
			//	app->db->setInt(1, this->characterID);
			//	app->db->execute();
			//	app->db->fetch();
			//	int max_lp = app->db->getInt("LastMaxLp");

				return; 
			}
			else if(strToken == "@setscale")
			{
				lexer.PopToPeek();
				strToken = lexer.PeekNextToken(NULL, &iLine);
				float fScale = (float)atof(strToken.c_str());
			//	CNtlSob *pSobObj = GetNtlSobManager()->GetSobObject(m_uiTargetSerialId);
			//	if(pSobObj)
			//	{
			//		CNtlSobProxy *pSobProxy = pSobObj->GetSobProxy();
			//		pSobProxy->SetScale(fScale);
			//	}
				
				return;
			}
			else if(strToken == "@is")
			{
				lexer.PopToPeek();
				strToken = lexer.PeekNextToken(NULL, &iLine);
			//	CNtlBehaviorProjSteal::m_ffIncSpeed = (RwReal)atof(strToken.c_str());
			}
			else if(strToken == "@iw")
			{
				lexer.PopToPeek();
				strToken = lexer.PeekNextToken(NULL, &iLine);
			//	CNtlBehaviorProjSteal::m_fWaitCheckTime = (RwReal)atof(strToken.c_str());
			}
			else if(strToken == "@compilelua")
			{
		//		SLLua_Setup();
				return;
			}
			
			break;
		}

		lexer.PopToPeek();
	}
}
//--------------------------------------------------------------------------------------//
//		Update Char speed *dont work*
//--------------------------------------------------------------------------------------//
void CClientSession::SendUpdateCharSpeed(float fSpeed, CGameServer * app)
{
	printf("Update char speed \n");
	CNtlPacket packet(sizeof(sGU_UPDATE_CHAR_SPEED));
	sGU_UPDATE_CHAR_SPEED * res = (sGU_UPDATE_CHAR_SPEED *)packet.GetPacketData();

	res->wOpCode = GU_UPDATE_CHAR_SPEED;
	res->handle = this->GetavatarHandle();
	res->fLastWalkingSpeed = fSpeed;
	res->fLastRunningSpeed = fSpeed;

	packet.SetPacketLen( sizeof(sGU_UPDATE_CHAR_SPEED) );
	app->UserBroadcastothers(&packet, this);
}
//--------------------------------------------------------------------------------------//
//		Select target
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharTargetSelect(CNtlPacket * pPacket)
{
	sUG_CHAR_TARGET_SELECT * req = (sUG_CHAR_TARGET_SELECT*)pPacket->GetPacketData();
	m_uiTargetSerialId = req->hTarget;
	printf("UG_CHAR_TARGET_SELECT %i \n", m_uiTargetSerialId);
}
//--------------------------------------------------------------------------------------//
//		Select target
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharTargetFacing(CNtlPacket * pPacket)
{
	printf("UG_CHAR_TARGET_FACING \n");

	sUG_CHAR_TARGET_SELECT * req = (sUG_CHAR_TARGET_SELECT*)pPacket->GetPacketData();
	m_uiTargetSerialId = req->hTarget;
}
//--------------------------------------------------------------------------------------//
//		target info
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharTargetInfo(CNtlPacket * pPacket)
{
	printf("UG_CHAR_TARGET_INFO \n");
	sUG_CHAR_TARGET_SELECT * req = (sUG_CHAR_TARGET_SELECT*)pPacket->GetPacketData();

}
//--------------------------------------------------------------------------------------//
//		Send game leave request
//--------------------------------------------------------------------------------------//
void CClientSession::SendGameLeaveReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- CHARACTER REQUEST LEAVE GAME --- \n");

	app->RemoveUser( this->plr->GetName().c_str() );

	CNtlPacket packet(sizeof(sGU_OBJECT_DESTROY));
	sGU_OBJECT_DESTROY * sPacket = (sGU_OBJECT_DESTROY *)packet.GetPacketData();

	sPacket->wOpCode = GU_OBJECT_DESTROY;
	sPacket->handle = this->GetavatarHandle();
	packet.SetPacketLen( sizeof(sGU_OBJECT_DESTROY) );
	app->UserBroadcastothers(&packet, this);

}
//--------------------------------------------------------------------------------------//
//		Char exit request
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharExitReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- Char exit request --- \n");
	this->plr->SaveMe();
// log out of game
	CNtlPacket packet1(sizeof(sGU_OBJECT_DESTROY));
	sGU_OBJECT_DESTROY * sPacket = (sGU_OBJECT_DESTROY *)packet1.GetPacketData();

	sPacket->wOpCode = GU_OBJECT_DESTROY;
	sPacket->handle = this->GetavatarHandle();
	packet1.SetPacketLen( sizeof(sGU_OBJECT_DESTROY) );
	app->UserBroadcastothers(&packet1, this);

	app->RemoveUser( this->plr->GetName().c_str() );

// log in to char server
	CNtlPacket packet(sizeof(sGU_CHAR_EXIT_RES));
	sGU_CHAR_EXIT_RES * res = (sGU_CHAR_EXIT_RES *)packet.GetPacketData();

	res->wOpCode = GU_CHAR_EXIT_RES;
	res->wResultCode = GAME_SUCCESS;
	strcpy_s((char*)res->achAuthKey, NTL_MAX_SIZE_AUTH_KEY, "Dbo");
	res->byServerInfoCount = 1;
	strcpy_s(res->aServerInfo[0].szCharacterServerIP, NTL_MAX_LENGTH_OF_IP, "127.0.0.1");
	res->aServerInfo[0].wCharacterServerPortForClient = 20300;
	res->aServerInfo[0].dwLoad = 0;

	packet.SetPacketLen( sizeof(sGU_CHAR_EXIT_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );
}

//--------------------------------------------------------------------------------------//
//		Char sit down
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharSitDown(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- Char sit down request --- \n");

	CNtlPacket packet(sizeof(sGU_CHAR_SITDOWN));
	sGU_CHAR_SITDOWN * sPacket = (sGU_CHAR_SITDOWN *)packet.GetPacketData();

	sPacket->wOpCode = GU_CHAR_SITDOWN;
	sPacket->handle = this->GetavatarHandle();
	packet.SetPacketLen( sizeof(sGU_CHAR_SITDOWN) );
	app->UserBroadcastothers(&packet, this);
}
//--------------------------------------------------------------------------------------//
//		Char stand up
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharStandUp(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- Char stand up request --- \n");

	CNtlPacket packet(sizeof(sGU_CHAR_STANDUP));
	sGU_CHAR_STANDUP * sPacket = (sGU_CHAR_STANDUP *)packet.GetPacketData();

	sPacket->wOpCode = GU_CHAR_STANDUP;
	sPacket->handle = this->GetavatarHandle();
	packet.SetPacketLen( sizeof(sGU_CHAR_STANDUP) );
	app->UserBroadcastothers(&packet, this);
}
//--------------------------------------------------------------------------------------//
//		char start mail
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharMailStart(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- char start mail --- \n");

	sUG_MAIL_START_REQ * req = (sUG_MAIL_START_REQ*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_MAIL_START_RES));
	sGU_MAIL_START_RES * res = (sGU_MAIL_START_RES *)packet.GetPacketData();

	app->db->prepare("SELECT MailIsAway FROM characters WHERE CharID=?");
	app->db->setInt(1, this->plr->GetCharID());
	app->db->execute();
	app->db->fetch();

	//res->hObject = req->hObject;
	res->wOpCode = GU_MAIL_START_RES;
	res->wResultCode = GAME_SUCCESS;
	res->bIsAway = app->db->getBoolean("MailIsAway");
	
	app->db->prepare("SELECT * FROM mail WHERE CharID = ?");
	app->db->setInt(1, this->plr->GetCharID());
	app->db->execute();
	if (app->db->rowsCount() > 0)
	{
		while (app->db->fetch())
		{
			CNtlPacket packet2(sizeof(sGU_MAIL_LOAD_DATA));
			sGU_MAIL_LOAD_DATA * res2 = (sGU_MAIL_LOAD_DATA *)packet2.GetPacketData();
			res2->wOpCode = GU_MAIL_LOAD_DATA;
			res2->sData.bIsAccept = app->db->getBoolean("bIsAccept");
			res2->sData.bIsLock = app->db->getBoolean("bIsLock");
			res2->sData.bIsRead = app->db->getBoolean("bIsRead");
		//	res2->sData.bySenderType = app->db->getInt("SenderType");
			res2->sData.byMailType = app->db->getInt("byMailType");
			wcscpy_s(res2->wszText, NTL_MAX_LENGTH_OF_MAIL_MESSAGE_IN_UNICODE, s2ws(app->db->getString("wszText")).c_str() );
			wcscpy_s(res2->sData.wszFromName, NTL_MAX_SIZE_CHAR_NAME_UNICODE, s2ws(app->db->getString("wszFromName")).c_str() );
			res2->byTextSize = app->db->getInt("byTextSize");
			res2->sData.dwZenny = app->db->getInt("dwZenny");
			res2->byTextSize = app->db->getInt("byTextSize");
			res2->sData.endTime = app->db->getInt("byDay");
			res2->sData.mailID = app->db->getInt("id");
			packet2.SetPacketLen( sizeof(sGU_MAIL_LOAD_DATA) );
			g_pApp->Send( this->GetHandle(), &packet2 );
		}
	}
	
	packet.SetPacketLen( sizeof(sGU_MAIL_START_RES) );
	g_pApp->Send( this->GetHandle(), &packet );
}
//--------------------------------------------------------------------------------------//
//		load mails
//--------------------------------------------------------------------------------------//
void	CClientSession::SendCharMailLoadReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- load mails --- \n");
	sUG_MAIL_LOAD_REQ * req = (sUG_MAIL_LOAD_REQ*)pPacket->GetPacketData();
	
	CNtlPacket packet(sizeof(sGU_MAIL_LOAD_RES));
	sGU_MAIL_LOAD_RES * res = (sGU_MAIL_LOAD_RES *)packet.GetPacketData();

	res->wOpCode = GU_MAIL_LOAD_RES;
	res->hObject = req->hObject;
	res->wResultCode = GAME_SUCCESS;

	packet.SetPacketLen( sizeof(sGU_MAIL_LOAD_RES) );
	g_pApp->Send( this->GetHandle(), &packet );
}
//--------------------------------------------------------------------------------------//
//		reload mails
//--------------------------------------------------------------------------------------//
void	CClientSession::SendCharMailReloadReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- reload mails --- \n");
	sUG_MAIL_RELOAD_REQ * req = (sUG_MAIL_RELOAD_REQ*)pPacket->GetPacketData();
	
	CNtlPacket packet(sizeof(sGU_MAIL_RELOAD_RES));
	sGU_MAIL_RELOAD_RES * res = (sGU_MAIL_RELOAD_RES *)packet.GetPacketData();

// COUNT UNREAD MESSAGES START
	app->db->prepare("SELECT COUNT(*) AS countmsg FROM mail WHERE CharID = ? AND bIsRead=0");
	app->db->setInt(1, this->plr->GetCharID());
	app->db->execute();
	app->db->fetch();
	RwUInt32 count_unread_msg = app->db->getInt("countmsg");
// COUNT UNREAD MESSAGES END

	app->db->prepare("SELECT * FROM mail WHERE CharID = ?");
	app->db->setInt(1, this->plr->GetCharID());
	app->db->execute();
	RwUInt32 i = 0;
	while (app->db->fetch())
	{
		res->aMailID[i] = app->db->getInt("id");
		i++;
	}

		res->byMailCount = app->db->rowsCount(); //count all mails
		res->byManagerCount = count_unread_msg; //amount of unread messages
		res->byNormalCount = 0; 
		res->hObject = req->hObject;
		res->wOpCode = GU_MAIL_RELOAD_RES;
		res->wResultCode = GAME_SUCCESS;

		packet.SetPacketLen( sizeof(sGU_MAIL_RELOAD_RES) );
		g_pApp->Send( this->GetHandle(), &packet );

	this->SendCharMailStart(pPacket,app);
}
//--------------------------------------------------------------------------------------//
//		read mails
//--------------------------------------------------------------------------------------//
void	CClientSession::SendCharMailReadReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- UG_MAIL_READ_REQ --- \n");
	sUG_MAIL_READ_REQ * req = (sUG_MAIL_READ_REQ*)pPacket->GetPacketData();

	app->db->prepare("SELECT * FROM mail WHERE id = ?");
	app->db->setInt(1, req->mailID);
	app->db->execute();
	app->db->fetch();
	
	RwUInt32 itemid = app->db->getInt("item_id");

	CNtlPacket packet(sizeof(sGU_MAIL_READ_RES));
	sGU_MAIL_READ_RES * res = (sGU_MAIL_READ_RES *)packet.GetPacketData();

	CNtlPacket packet2(sizeof(sGU_MAIL_LOAD_INFO));
	sGU_MAIL_LOAD_INFO * res2 = (sGU_MAIL_LOAD_INFO *)packet2.GetPacketData();


	res->byRemainDay = app->db->getInt("byDay");
	res->endTime = 100;
	res->hObject = req->hObject;
	res->mailID = req->mailID;
	res->wOpCode = GU_MAIL_READ_RES;
	res->wResultCode = GAME_SUCCESS;

		res2->wOpCode = GU_MAIL_LOAD_INFO;
		res2->sData.bIsAccept = app->db->getBoolean("bIsAccept");
		res2->sData.bIsLock = app->db->getBoolean("bIsLock");
		res2->sData.bIsRead = app->db->getBoolean("bIsRead");
		res2->byTextSize = app->db->getInt("byTextSize");
		res2->sData.byExpired = 100;
		res2->sData.bySenderType = eMAIL_SENDER_TYPE_BASIC;
		res2->sData.byMailType = app->db->getInt("byMailType");
		res2->sData.dwZenny = app->db->getInt("dwZenny");
		res2->sData.endTime = app->db->getInt("byDay");
		res2->sData.mailID = app->db->getInt("id");
		wcscpy_s(res2->sData.wszFromName, NTL_MAX_SIZE_CHAR_NAME_UNICODE, s2ws(app->db->getString("wszFromName")).c_str() );
		wcscpy_s(res2->wszText, NTL_MAX_LENGTH_OF_MAIL_MESSAGE_IN_UNICODE, s2ws(app->db->getString("wszText")).c_str() );

	//	res2->sData.tCreateTime.second = app->db->getInt("byDay");
	//	res2->sData.tCreateTime.minute = app->db->getInt("byDay");
	//	res2->sData.tCreateTime.hour = app->db->getInt("byDay");
	//	res2->sData.tCreateTime.day = app->db->getInt("tCreateTime");
	//	res2->sData.tCreateTime.month = app->db->getInt("byDay");
	//	res2->sData.tCreateTime.year = app->db->getInt("byDay");

		if(app->db->getInt("byMailType") > 1){
			app->db->prepare("SELECT id,tblidx,count,rank,durability,grade FROM items WHERE id = ?");
			app->db->setInt(1, itemid);
			app->db->execute();
			app->db->fetch();
			res2->sData.sItemProfile.handle = app->db->getInt("id");
			res2->sData.sItemProfile.byCurDur = app->db->getInt("durability");
			res2->sData.sItemProfile.byStackcount = app->db->getInt("count");
			res2->sData.sItemProfile.byGrade = app->db->getInt("grade");
			res2->sData.sItemProfile.tblidx = app->db->getInt("tblidx");
			res2->sData.sItemProfile.byRank = app->db->getInt("rank");
		}

		packet2.SetPacketLen( sizeof(sGU_MAIL_LOAD_INFO) );
		g_pApp->Send( this->GetHandle(), &packet2 );

		//SET MAIL READ
		app->qry->SetMailRead(req->mailID);

	packet.SetPacketLen( sizeof(sGU_MAIL_READ_RES) );
	g_pApp->Send( this->GetHandle(), &packet );
}
//--------------------------------------------------------------------------------------//
//		send mails
//--------------------------------------------------------------------------------------//
void	CClientSession::SendCharMailSendReq(CNtlPacket * pPacket, CGameServer * app)
{
	sUG_MAIL_SEND_REQ * req = (sUG_MAIL_SEND_REQ*)pPacket->GetPacketData();
	
	CNtlPacket packet(sizeof(sGU_MAIL_SEND_RES));
	sGU_MAIL_SEND_RES * res = (sGU_MAIL_SEND_RES *)packet.GetPacketData();

	app->db->prepare("SELECT CharID,MailIsAway FROM characters WHERE CharName = ?");

	char targetname[NTL_MAX_SIZE_CHAR_NAME_UNICODE];
	wcstombs(targetname, req->wszTargetName, NTL_MAX_SIZE_CHAR_NAME_UNICODE);

	char *text = new char[req->byTextSize];
	wcstombs(text, req->wszText, req->byTextSize);
	text[req->byTextSize] = '\0';

	app->db->setString(1, targetname);
	app->db->execute();
	app->db->fetch();
	int id = app->db->getInt("CharID");

	wcscpy_s(res->wszTargetName, NTL_MAX_SIZE_CHAR_NAME_UNICODE, req->wszTargetName );
	res->wOpCode = GU_MAIL_SEND_RES;
	res->hObject = req->hObject;

	if(app->db->getBoolean("MailIsAway") == 1){
		res->wResultCode = GAME_MAIL_TARGET_AWAY_STATE;
	} else {
		res->wResultCode = GAME_SUCCESS;
		app->db->prepare("INSERT INTO mail (CharID, byDay, byMailType, byTextSize, dwZenny, wszText, item_id, item_place, item_pos, wszTargetName, wszFromName, bIsAccept, bIsLock, bIsRead) VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
		app->db->setInt(1, id);
		app->db->setInt(2, req->byDay);
		app->db->setInt(3, req->byMailType);
		app->db->setInt(4, req->byTextSize);
		app->db->setInt(5, req->dwZenny);
		app->db->setString(6, text);
		app->db->setInt(7, req->sItemData.hItem);
		app->db->setInt(8, req->sItemData.byPlace);
		app->db->setInt(9, req->sItemData.byPos);
		app->db->setString(10, targetname);
		app->db->setString(11, this->plr->GetName());
		app->db->setInt(12, app->db->getBoolean("MailIsAway"));
		app->db->setInt(13, false);
		app->db->setInt(14, false);
		app->db->execute();

		if(req->byMailType == 2 || req->byMailType == 5 ){
		  //SET OWNER ID TO 0
			app->qry->UpdateItemOwnerIdWithUniqueID(0, req->sItemData.hItem);
		  //DEL ITEM PACKET
			this->gsf->DeleteItemByUIdPlacePos(pPacket, this, req->sItemData.hItem, req->sItemData.byPlace, req->sItemData.byPos);
		}
		else if(req->byMailType == 3){
		  //UPDATE CHAR MONEY
			app->qry->SetMinusMoney(this->plr->GetCharID(), req->dwZenny);
			this->plr->SetMoney(this->plr->GetMoney() - req->dwZenny);
		  //UPDATE MONEY PACKET
			this->gsf->UpdateCharMoney(pPacket,this,16,this->plr->GetMoney(),this->GetavatarHandle());
		}
		else if(req->byMailType == 4){
		  //UPDATE MONEY
			app->qry->SetMinusMoney(this->plr->GetCharID(), req->dwZenny);
			this->plr->SetMoney(this->plr->GetMoney() - req->dwZenny);
		  //UPDATE MONEY PACKET
			this->gsf->UpdateCharMoney(pPacket,this,16,this->plr->GetMoney(),this->GetavatarHandle());
		  //SET OWNER ID TO 0
			app->qry->UpdateItemOwnerIdWithUniqueID(0, req->sItemData.hItem);
		  //DEL ITEM PACKET
			this->gsf->DeleteItemByUIdPlacePos(pPacket, this, req->sItemData.hItem, req->sItemData.byPlace, req->sItemData.byPos);
		}

	}

	packet.SetPacketLen( sizeof(sGU_MAIL_SEND_RES) );
	g_pApp->Send( this->GetHandle(), &packet );
}
//--------------------------------------------------------------------------------------//
//		delete mails
//--------------------------------------------------------------------------------------//
void	CClientSession::SendCharMailDelReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- UG_MAIL_DEL_REQ --- \n");

	sUG_MAIL_DEL_REQ * req = (sUG_MAIL_DEL_REQ*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_MAIL_DEL_RES));
	sGU_MAIL_DEL_RES * res = (sGU_MAIL_DEL_RES *)packet.GetPacketData();

	app->qry->DeleteFromMailByID(req->mailID);

	res->hObject = req->hObject;
	res->mailID = req->mailID;
	res->wOpCode = GU_MAIL_DEL_RES;
	res->wResultCode = GAME_SUCCESS;
	
	packet.SetPacketLen( sizeof(sGU_MAIL_DEL_RES) );
	g_pApp->Send( this->GetHandle(), &packet );
}
//--------------------------------------------------------------------------------------//
//		receive item with mail
//--------------------------------------------------------------------------------------//
void	CClientSession::SendCharMailItemReceiveReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- UG_MAIL_ITEM_RECEIVE_REQ --- \n");

	sUG_MAIL_ITEM_RECEIVE_REQ * req = (sUG_MAIL_ITEM_RECEIVE_REQ*)pPacket->GetPacketData();

	app->db->prepare("SELECT * FROM mail WHERE id = ?");
	app->db->setInt(1, req->mailID);
	app->db->execute();
	app->db->fetch();
	
	CNtlPacket packet(sizeof(sGU_MAIL_ITEM_RECEIVE_RES));
	sGU_MAIL_ITEM_RECEIVE_RES * res = (sGU_MAIL_ITEM_RECEIVE_RES *)packet.GetPacketData();

	res->hObject = req->hObject;
	res->mailID = req->mailID;
	res->wOpCode = GU_MAIL_ITEM_RECEIVE_RES;
	res->wResultCode = GAME_SUCCESS;


	if(app->db->getInt("byMailType") == 2 ){
	  //CHANGE ITEM OWNER
		app->qry->ChangeItemOwnerByUIdPlacePos(this->plr->GetCharID(), app->db->getInt("item_id"), 0, 0); // 0 = place and pos
	  //CREATE ITEM PACKET
		CNtlPacket packet1(sizeof(sGU_ITEM_CREATE));
		sGU_ITEM_CREATE * res1 = (sGU_ITEM_CREATE *)packet1.GetPacketData();

		res1->wOpCode = GU_ITEM_CREATE;
		packet1.SetPacketLen(sizeof(sGU_ITEM_CREATE));
		g_pApp->Send( this->GetHandle() , &packet1 );
	}
	else if(app->db->getInt("byMailType") == 3){
	  //UPDATE MONEY
		this->plr->SetMoney(this->plr->GetMoney() + app->db->getInt("dwZenny"));
		app->qry->SetPlusMoney(this->plr->GetCharID(), app->db->getInt("dwZenny"));
	  //UPDATE MONEY PACKET
		this->gsf->UpdateCharMoney(pPacket,this,17,this->plr->GetMoney(),this->GetavatarHandle());
	}
	else if(app->db->getInt("byMailType") == 4){
	  //UPDATE MONEY
		app->qry->SetPlusMoney(this->plr->GetCharID(), app->db->getInt("dwZenny"));
		this->plr->SetMoney(this->plr->GetMoney() + app->db->getInt("dwZenny"));
	  //UPDATE MONEY PACKET
		this->gsf->UpdateCharMoney(pPacket,this,17,this->plr->GetMoney(),this->GetavatarHandle());
	  //CHANGE ITEM OWNER
		app->qry->ChangeItemOwnerByUIdPlacePos(this->plr->GetCharID(), app->db->getInt("item_id"), 0, 0); // 0 = place and pos
	  //CREATE ITEM PACKET
		CNtlPacket packet3(sizeof(sGU_ITEM_CREATE));
		sGU_ITEM_CREATE * res3 = (sGU_ITEM_CREATE *)packet3.GetPacketData();

		res3->wOpCode = GU_ITEM_CREATE;
		packet3.SetPacketLen(sizeof(sGU_ITEM_CREATE));
		g_pApp->Send( this->GetHandle() , &packet3 );
	}
	
	app->qry->SetMailAccept(this->plr->GetCharID(), req->mailID);

	packet.SetPacketLen( sizeof(sGU_MAIL_ITEM_RECEIVE_RES) );
	g_pApp->Send( this->GetHandle(), &packet );
}
//--------------------------------------------------------------------------------------//
//		delete multiple mails
//--------------------------------------------------------------------------------------//
void	CClientSession::SendCharMailMultiDelReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- UG_MAIL_MULTI_DEL_REQ --- \n");

	sUG_MAIL_MULTI_DEL_REQ * req = (sUG_MAIL_MULTI_DEL_REQ*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_MAIL_MULTI_DEL_RES));
	sGU_MAIL_MULTI_DEL_RES * res = (sGU_MAIL_MULTI_DEL_RES *)packet.GetPacketData();

	for( RwInt32 j = 0 ; j < req->byCount ; ++j )
	{
		app->qry->DeleteFromMailByID(req->aMailID[j]);

		res->wOpCode = GU_MAIL_MULTI_DEL_RES;
		res->wResultCode = GAME_SUCCESS;
		res->hObject = req->hObject;
		res->byCount = req->byCount;
		res->aMailID[j] = req->aMailID[j];
	
		packet.SetPacketLen( sizeof(sGU_MAIL_MULTI_DEL_RES) );
		g_pApp->Send( this->GetHandle(), &packet );
	}

}
//--------------------------------------------------------------------------------------//
//		lock mail
//--------------------------------------------------------------------------------------//
void	CClientSession::SendCharMailLockReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- LOCK MAIL --- \n");
	sUG_MAIL_LOCK_REQ * req = (sUG_MAIL_LOCK_REQ*)pPacket->GetPacketData();

	app->db->prepare("SELECT * FROM mail WHERE id = ?");
	app->db->setInt(1, req->mailID);
	app->db->execute();
	app->db->fetch();
	
	CNtlPacket packet(sizeof(sGU_MAIL_LOCK_RES));
	sGU_MAIL_LOCK_RES * res = (sGU_MAIL_LOCK_RES *)packet.GetPacketData();

	res->wOpCode = GU_MAIL_LOCK_RES;
	res->wResultCode = GAME_SUCCESS;
	res->hObject = req->hObject;
	res->mailID = req->mailID;
	res->bIsLock = req->bIsLock;

	app->qry->UpdateMailLock(req->mailID, res->bIsLock);

	packet.SetPacketLen( sizeof(sGU_MAIL_LOCK_RES) );
	g_pApp->Send( this->GetHandle(), &packet );
}
//--------------------------------------------------------------------------------------//
//		RETURN MAIL
//--------------------------------------------------------------------------------------//
void	CClientSession::SendCharMailReturnReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- RETURN MAIL --- \n");

	sUG_MAIL_RETURN_REQ * req = (sUG_MAIL_RETURN_REQ*)pPacket->GetPacketData();

	app->db->prepare("SELECT item_id FROM mail WHERE id = ?");
	app->db->setInt(1, req->mailID);
	app->db->execute();
	app->db->fetch();
	
	CNtlPacket packet(sizeof(sGU_MAIL_RETURN_RES));
	sGU_MAIL_RETURN_RES * res = (sGU_MAIL_RETURN_RES *)packet.GetPacketData();

	res->wOpCode = GU_MAIL_RETURN_RES;
	res->wResultCode = GAME_SUCCESS;
	res->hObject = req->hObject;
	res->mailID = req->mailID;

	app->db->prepare("CALL ReturnMail (?,?)");
	app->db->setInt(1, req->mailID);
	app->db->setString(2, this->plr->GetName());
	app->db->execute();
	
	packet.SetPacketLen( sizeof(sGU_MAIL_RETURN_RES) );
	g_pApp->Send( this->GetHandle(), &packet );
}


//--------------------------------------------------------------------------------------//
//		char away req
//--------------------------------------------------------------------------------------//
void	CClientSession::SendCharAwayReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- char away req --- \n");
	sUG_CHAR_AWAY_REQ * req = (sUG_CHAR_AWAY_REQ*)pPacket->GetPacketData();
	
	CNtlPacket packet(sizeof(sGU_CHAR_AWAY_RES));
	sGU_CHAR_AWAY_RES * res = (sGU_CHAR_AWAY_RES *)packet.GetPacketData();

	res->wOpCode = GU_CHAR_AWAY_RES;
	res->wResultCode = GAME_SUCCESS;
	res->bIsAway = req->bIsAway;

	app->qry->UpdateCharAwayStatus(this->plr->GetCharID(), req->bIsAway);

	packet.SetPacketLen( sizeof(sGU_CHAR_AWAY_RES) );
	g_pApp->Send( this->GetHandle(), &packet );
}
//--------------------------------------------------------------------------------------//
//		char follow move
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharFollowMove(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- SEND CHAR FOLLOW MOVE --- \n");
	sUG_CHAR_FOLLOW_MOVE * req = (sUG_CHAR_FOLLOW_MOVE*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_CHAR_FOLLOW_MOVE));
	sGU_CHAR_FOLLOW_MOVE * res = (sGU_CHAR_FOLLOW_MOVE *)packet.GetPacketData();

	res->wOpCode = GU_CHAR_FOLLOW_MOVE;
	res->handle = this->GetavatarHandle();
	res->hTarget = this->GetTargetSerialId();
	res->fDistance = req->fDistance;
	res->byMovementReason = req->byMovementReason;
	res->byMoveFlag = NTL_MOVE_FLAG_RUN;

	packet.SetPacketLen( sizeof(sGU_CHAR_FOLLOW_MOVE) );
	app->UserBroadcastothers(&packet, this);
	int rc = g_pApp->Send( this->GetHandle(), &packet );
}



//--------------------------------------------------------------------------------------//
//		Create Guild
//--------------------------------------------------------------------------------------//
void CClientSession::SendGuildCreateReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- create guild request --- \n");

	sUG_GUILD_CREATE_REQ * req = (sUG_GUILD_CREATE_REQ*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_GUILD_CREATE_RES));
	sGU_GUILD_CREATE_RES * res = (sGU_GUILD_CREATE_RES *)packet.GetPacketData();

	res->wOpCode = GU_GUILD_CREATE_RES;
	printf("guild manager id: %i ", req->hGuildManagerNpc);

	app->db->prepare("CALL GuildCreate (?,?, @wResultCode, @cguildid, @charactername)");
	app->db->setString(1, Ntl_WC2MB(req->wszGuildName));
	app->db->setInt(2, this->plr->GetCharID());
	app->db->execute();
	app->db->execute("SELECT @wResultCode, @cguildid, @charactername");
	app->db->fetch(); 

	int result = app->db->getInt("@wResultCode");

	printf("create guild result %i \n ", result);
	res->wResultCode = result;

	packet.SetPacketLen( sizeof(sGU_GUILD_CREATE_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );

	if (result == 200) { 
		
// CREATE GUILD
		CNtlPacket packet2(sizeof(sTU_GUILD_CREATED_NFY));
		sTU_GUILD_CREATED_NFY * res2 = (sTU_GUILD_CREATED_NFY *)packet2.GetPacketData();
		res2->wOpCode = TU_GUILD_CREATED_NFY;
		memcpy(res2->wszGuildName, req->wszGuildName, sizeof(wchar_t)* NTL_MAX_SIZE_GUILD_NAME_IN_UNICODE);
		packet2.SetPacketLen( sizeof(sTU_GUILD_CREATED_NFY));
		rc = g_pApp->Send( this->GetHandle(), &packet2);

// GUILD INFORMATIONS
		CNtlPacket packet3(sizeof(sTU_GUILD_INFO));
		sTU_GUILD_INFO * res3 = (sTU_GUILD_INFO *)packet3.GetPacketData();

		res3->wOpCode = TU_GUILD_INFO;
		res3->guildInfo.dwGuildReputation = 0;
		res3->guildInfo.guildId = app->db->getInt("@cguildid");
		res3->guildInfo.guildMaster = this->plr->GetCharID();
		memcpy(res3->guildInfo.wszName, req->wszGuildName, sizeof(wchar_t)* NTL_MAX_SIZE_GUILD_NAME_IN_UNICODE);
		wcscpy_s(res3->guildInfo.awchName, NTL_MAX_SIZE_CHAR_NAME_UNICODE, s2ws(app->db->getString("@charactername")).c_str());
		packet3.SetPacketLen( sizeof(sTU_GUILD_INFO));
		rc = g_pApp->Send( this->GetHandle(), &packet3);

// GUILD MEMBER INFORMATIONS
		CNtlPacket packet4(sizeof(sTU_GUILD_MEMBER_INFO));
		sTU_GUILD_MEMBER_INFO * res4 = (sTU_GUILD_MEMBER_INFO *)packet4.GetPacketData();

		res4->wOpCode = TU_GUILD_MEMBER_INFO;
		res4->guildMemberInfo.bIsOnline = true;
		res4->guildMemberInfo.charId = this->plr->GetCharID();
		wcscpy_s(res4->guildMemberInfo.wszMemberName, NTL_MAX_SIZE_CHAR_NAME_UNICODE, s2ws(app->db->getString("@charactername")).c_str());
		packet4.SetPacketLen( sizeof(sTU_GUILD_MEMBER_INFO));
		rc = g_pApp->Send( this->GetHandle(), &packet4);
		app->UserBroadcastothers(&packet4, this);

		this->plr->SetGuildName(app->db->getString("@charactername"));
		
	}
	
}

//--------------------------------------------------------------------------------------//
//		Create Party
//--------------------------------------------------------------------------------------//
void CClientSession::SendCreatePartyReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- create party request --- \n");

	PlayerPartyClass *t = new PlayerPartyClass;

	t->m_partyList.begin();
	t->CreateParty(this->GetHandle());

	sUG_PARTY_CREATE_REQ * req = (sUG_PARTY_CREATE_REQ*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_PARTY_CREATE_RES));
	sGU_PARTY_CREATE_RES * res = (sGU_PARTY_CREATE_RES *)packet.GetPacketData();

	res->wOpCode = GU_PARTY_CREATE_RES;
	res->wResultCode = GAME_SUCCESS;
	memcpy(res->wszPartyName, req->wszPartyName, sizeof(wchar_t)* NTL_MAX_SIZE_PARTY_NAME_IN_UNICODE);

	packet.SetPacketLen( sizeof(sGU_PARTY_CREATE_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );

}
//--------------------------------------------------------------------------------------//
//		Disband Party
//--------------------------------------------------------------------------------------//
void CClientSession::SendDisbandPartyReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- disband party request --- \n");

	CNtlPacket packet(sizeof(sGU_PARTY_DISBAND_RES));
	sGU_PARTY_DISBAND_RES * res = (sGU_PARTY_DISBAND_RES *)packet.GetPacketData();

	res->wOpCode = GU_PARTY_DISBAND_RES;
	res->wResultCode = GAME_SUCCESS;

	packet.SetPacketLen( sizeof(sGU_PARTY_DISBAND_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );


	CNtlPacket packet2(sizeof(sGU_PARTY_DISBANDED_NFY));
	sGU_PARTY_DISBANDED_NFY * sPacket2 = (sGU_PARTY_DISBANDED_NFY *)packet2.GetPacketData();
	sPacket2->wOpCode = GU_PARTY_DISBANDED_NFY;

	packet2.SetPacketLen( sizeof(sGU_PARTY_DISBANDED_NFY));
	rc = g_pApp->Send( this->GetHandle(), &packet2);

}
//--------------------------------------------------------------------------------------//
//		Send party invite request
//--------------------------------------------------------------------------------------//
void CClientSession::SendPartyInviteReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- Send party invite request --- \n");
	sUG_PARTY_INVITE_REQ * req = (sUG_PARTY_INVITE_REQ*)pPacket->GetPacketData();

	app->db->prepare("SELECT * FROM characters WHERE OnlineID = ?");
	app->db->setInt(1, req->hTarget);
	app->db->execute(); 
	app->db->fetch(); 

	//Invite player
	CNtlPacket packet(sizeof(sGU_PARTY_INVITE_RES));
	sGU_PARTY_INVITE_RES * res = (sGU_PARTY_INVITE_RES *)packet.GetPacketData();

	res->wOpCode = GU_PARTY_INVITE_RES;
	res->wResultCode = GAME_SUCCESS;
	wcscpy_s(res->wszTargetName, NTL_MAX_SIZE_CHAR_NAME_UNICODE, s2ws(app->db->getString("CharName")).c_str());
	printf("target uniquee id %i \n", req->hTarget);

	packet.SetPacketLen( sizeof(sGU_PARTY_INVITE_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );

	//Send invitation request to player
	CNtlPacket packet2(sizeof(sGU_PARTY_INVITE_NFY));
	sGU_PARTY_INVITE_NFY * res2 = (sGU_PARTY_INVITE_NFY *)packet2.GetPacketData();

	res2->wOpCode = GU_PARTY_INVITE_NFY;
	res2->bFromPc = true;
	wcscpy_s(res2->wszInvitorPcName, NTL_MAX_SIZE_CHAR_NAME_UNICODE, s2ws(this->plr->GetName()).c_str());

	packet2.SetPacketLen( sizeof(sGU_PARTY_INVITE_NFY));
	app->UserBroadcastothers(&packet2, this);


	sUG_PARTY_RESPONSE_INVITATION * req2 = (sUG_PARTY_RESPONSE_INVITATION*)pPacket->GetPacketData();
	CNtlPacket packet3(sizeof(sGU_PARTY_RESPONSE_INVITATION_RES));
	sGU_PARTY_RESPONSE_INVITATION_RES * res3 = (sGU_PARTY_RESPONSE_INVITATION_RES *)packet3.GetPacketData();

	res3->wOpCode = GU_PARTY_RESPONSE_INVITATION_RES;
	res3->wResultCode = GAME_SUCCESS;

	packet.SetPacketLen( sizeof(sGU_PARTY_RESPONSE_INVITATION_RES) );
	rc = g_pApp->Send( this->GetHandle(), &packet3 );

	printf("response: %i ",req2->byResponse);
	if(req2->byResponse == 2) // User accepted party invite
	{
	CNtlPacket packet4(sizeof(sGU_PARTY_MEMBER_JOINED_NFY));
	sGU_PARTY_MEMBER_JOINED_NFY * res4 = (sGU_PARTY_MEMBER_JOINED_NFY *)packet4.GetPacketData();

	res2->wOpCode = GU_PARTY_MEMBER_JOINED_NFY;
	wcscpy_s(res4->memberInfo.awchMemberName, NTL_MAX_SIZE_CHAR_NAME_UNICODE, s2ws(app->db->getString("CharName")).c_str());
	
	res4->memberInfo.byClass = app->db->getInt("Class");
	res4->memberInfo.byLevel = app->db->getInt("Level");
	res4->memberInfo.byRace = app->db->getInt("Race");
	res4->memberInfo.hHandle = app->db->getInt("OnlineID");
	res4->memberInfo.vCurLoc.x = (float)app->db->getDouble("CurLocX");
	res4->memberInfo.vCurLoc.y = (float)app->db->getDouble("CurLocY");
	res4->memberInfo.vCurLoc.z = (float)app->db->getDouble("CurLocZ");
	res4->memberInfo.wCurEP = app->db->getInt("CurEP");
	res4->memberInfo.wCurLP = app->db->getInt("CurLP");
	res4->memberInfo.wMaxEP = app->db->getInt("BaseMaxEp");
	res4->memberInfo.wMaxLP = app->db->getInt("BaseMaxLp");
	res4->memberInfo.worldId = app->db->getInt("WorldID");
	res4->memberInfo.dwZenny = app->db->getInt("Money");
	res4->memberInfo.worldTblidx = app->db->getInt("WorldTable");

	packet4.SetPacketLen( sizeof(sGU_PARTY_MEMBER_JOINED_NFY));
	rc = g_pApp->Send( this->GetHandle(), &packet );
	app->UserBroadcastothers(&packet4, this);
	printf("user invited ");
	}
}
//--------------------------------------------------------------------------------------//
//		Party invitation response
//--------------------------------------------------------------------------------------//
void CClientSession::SendPartyResponse(CNtlPacket * pPacket, CGameServer * app)
{
/*
	printf("--- Party invitation response --- \n");

	sUG_PARTY_RESPONSE_INVITATION * req = (sUG_PARTY_RESPONSE_INVITATION*)pPacket->GetPacketData();

	printf("--- RESPONSE %i --- \n", req->byResponse);

	CNtlPacket packet(sizeof(sGU_PARTY_RESPONSE_INVITATION_RES));
	sGU_PARTY_RESPONSE_INVITATION_RES * res = (sGU_PARTY_RESPONSE_INVITATION_RES *)packet.GetPacketData();

	res->wOpCode = GU_PARTY_RESPONSE_INVITATION_RES;
	res->wResultCode = GAME_SUCCESS;
	
	packet.SetPacketLen( sizeof(sGU_PARTY_RESPONSE_INVITATION_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );

//Join notification
	CNtlPacket packet2(sizeof(sGU_PARTY_MEMBER_JOINED_NFY));
	sGU_PARTY_MEMBER_JOINED_NFY * res2 = (sGU_PARTY_MEMBER_JOINED_NFY *)packet2.GetPacketData();

	res2->wOpCode = GU_PARTY_MEMBER_JOINED_NFY;
	wcscpy_s(res2->memberInfo.awchMemberName, NTL_MAX_SIZE_CHAR_NAME_UNICODE, s2ws("fotzee").c_str());
	
	res2->memberInfo.byClass = 5;
	res2->memberInfo.byLevel = 1;
	res2->memberInfo.byRace = 2;
	res2->memberInfo.hHandle = this->GetTargetSerialId();
	res2->memberInfo.vCurLoc.x = 4605;
	res2->memberInfo.vCurLoc.y = -44;
	res2->memberInfo.vCurLoc.z = 4092;
	res2->memberInfo.wCurEP = 1000;
	res2->memberInfo.wCurLP = 1000;
	res2->memberInfo.wMaxEP = 1000;
	res2->memberInfo.wMaxLP = 1000;
	res2->memberInfo.worldId = 1;
	

	packet2.SetPacketLen( sizeof(sGU_PARTY_MEMBER_JOINED_NFY));
	//rc = g_pApp->Send( this->GetHandle(), &packet );
	app->UserBroadcastothers(&packet2, this);
*/

}
//--------------------------------------------------------------------------------------//
//		Leave Party
//--------------------------------------------------------------------------------------//
void CClientSession::SendPartyLeaveReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- leave party request --- \n");

	CNtlPacket packet(sizeof(sGU_PARTY_LEAVE_RES));
	sGU_PARTY_LEAVE_RES * res = (sGU_PARTY_LEAVE_RES *)packet.GetPacketData();

	res->wOpCode = GU_PARTY_LEAVE_RES;
	res->wResultCode = GAME_SUCCESS;

	packet.SetPacketLen( sizeof(sGU_PARTY_DISBAND_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );


	CNtlPacket packet2(sizeof(sGU_PARTY_MEMBER_LEFT_NFY));
	sGU_PARTY_MEMBER_LEFT_NFY * sPacket2 = (sGU_PARTY_MEMBER_LEFT_NFY *)packet2.GetPacketData();
	sPacket2->wOpCode = GU_PARTY_MEMBER_LEFT_NFY;
	//sPacket2->hMember = GET PARTY-MEMBER ID
	

	packet2.SetPacketLen( sizeof(sGU_PARTY_MEMBER_LEFT_NFY));
	rc = g_pApp->Send( this->GetHandle(), &packet2);

	app->UserBroadcastothers(&packet2, this);
}

//--------------------------------------------------------------------------------------//
//		Execute trigger object
//--------------------------------------------------------------------------------------//
void CClientSession::SendExcuteTriggerObject(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- SendExcuteTriggerObject --- \n");

	sUG_TS_EXCUTE_TRIGGER_OBJECT * req = (sUG_TS_EXCUTE_TRIGGER_OBJECT*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_TS_EXCUTE_TRIGGER_OBJECT_RES));
	sGU_TS_EXCUTE_TRIGGER_OBJECT_RES * res = (sGU_TS_EXCUTE_TRIGGER_OBJECT_RES *)packet.GetPacketData();

	res->wOpCode = GU_TS_EXCUTE_TRIGGER_OBJECT_RES;
	res->wResultCode = GAME_SUCCESS;
	res->hTriggerObject = req->hTarget;

	printf("SOURCE: %i TARGET: %i EVTGENTYPE: %i ", req->hSource, req->hTarget, req->byEvtGenType);

	packet.SetPacketLen( sizeof(sGU_TS_EXCUTE_TRIGGER_OBJECT_RES) );
	app->UserBroadcastothers(&packet, this);
	int rc = g_pApp->Send( this->GetHandle(), &packet );
}
//--------------------------------------------------------------------------------------//
//		Character bind to world
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharBindReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- UG_CHAR_BIND_REQ --- \n");

	sUG_CHAR_BIND_REQ * req = (sUG_CHAR_BIND_REQ*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_CHAR_BIND_RES));
	sGU_CHAR_BIND_RES * res = (sGU_CHAR_BIND_RES *)packet.GetPacketData();

	app->db->prepare("CALL CharBind (?,?, @currentWorldID)");
	app->db->setInt(1, this->plr->GetCharID());
	app->db->setInt(2, req->bindObjectTblidx);
	app->db->execute();
	app->db->execute("SELECT @currentWorldID");
	app->db->fetch(); 

	res->wOpCode = GU_CHAR_BIND_RES;
	res->wResultCode = GAME_SUCCESS;
	res->byBindType = DBO_BIND_TYPE_FIRST;
	res->bindObjectTblidx = req->bindObjectTblidx;

	res->bindWorldId = app->db->getInt("@currentWorldID");

	printf("bindWorldId: %i  bindObjectTblidx:%i", app->db->getInt("@currentWorldID"), req->bindObjectTblidx);

	packet.SetPacketLen( sizeof(sGU_CHAR_BIND_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );
}
//--------------------------------------------------------------------------------------//
//		PORTAL START REQUEST
//--------------------------------------------------------------------------------------//
void CClientSession::SendPortalStartReq(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- PORTAL START REQUEST --- \n");
	sUG_PORTAL_START_REQ * req = (sUG_PORTAL_START_REQ *)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_PORTAL_START_RES));
	sGU_PORTAL_START_RES * res = (sGU_PORTAL_START_RES *)packet.GetPacketData();

	res->wOpCode = GU_PORTAL_START_RES;
	res->wResultCode = GAME_SUCCESS;
	res->hNpcHandle = req->handle;

	CNtlPacket packet2(sizeof(sGU_PORTAL_INFO));
	sGU_PORTAL_INFO * res2 = (sGU_PORTAL_INFO *)packet2.GetPacketData();
	
	CPortalTable* pPortalTbl = app->g_pTableContainer->GetPortalTable();
	int i = 0;
	for ( CTable::TABLEIT itPortal = pPortalTbl->Begin(); itPortal != pPortalTbl->End(); ++itPortal )
	{
		sPORTAL_TBLDAT* pPortalTblData = (sPORTAL_TBLDAT*) itPortal->second;
		res2->aPortalID[i] = pPortalTblData->tblidx;
		i++;
	}
	res2->wOpCode = GU_PORTAL_INFO;
	res2->byCount = i;

	packet2.SetPacketLen( sizeof(sGU_PORTAL_INFO));
	int rc = g_pApp->Send( this->GetHandle(), &packet2);
	Sleep(1);
	packet.SetPacketLen( sizeof(sGU_PORTAL_START_RES) );
	rc = g_pApp->Send( this->GetHandle(), &packet );
}
//--------------------------------------------------------------------------------------//
//		PORTAL ADD REQUEST
//--------------------------------------------------------------------------------------//
void CClientSession::SendPortalAddReq(CNtlPacket * pPacket, CGameServer * app)
{
sUG_PORTAL_ADD_REQ* req = (sUG_PORTAL_ADD_REQ *)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_PORTAL_ADD_RES));
	sGU_PORTAL_ADD_RES * res = (sGU_PORTAL_ADD_RES *)packet.GetPacketData();

	res->wOpCode = GU_PORTAL_ADD_RES;
	res->wResultCode = GAME_SUCCESS;
	res->hNpcHandle = req->handle;
	res->PortalID = 1;

	packet.SetPacketLen( sizeof(sGU_PORTAL_ADD_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );
}
void CClientSession::SendPortalTelReq(CNtlPacket * pPacket, CGameServer * app)
{
	sUG_PORTAL_REQ* req = (sUG_PORTAL_REQ *)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_PORTAL_RES));
	sGU_PORTAL_RES * res = (sGU_PORTAL_RES *)packet.GetPacketData();

	CNtlPacket packet2(sizeof(sGU_CHAR_TELEPORT_RES));
	sGU_CHAR_TELEPORT_RES * res2 = (sGU_CHAR_TELEPORT_RES *)packet2.GetPacketData();

	int i = 0;
	
	CPortalTable* pPortalTbl = app->g_pTableContainer->GetPortalTable();
	for ( CTable::TABLEIT itPortal = pPortalTbl->Begin(); itPortal != pPortalTbl->End(); ++itPortal )
	{
		sPORTAL_TBLDAT* pPortalTblData = (sPORTAL_TBLDAT*) itPortal->second;
		if (req->byPoint == pPortalTblData->tblidx)
		{
			//pPortalTblData->adwPointZenny;
			//pPortalTblData->dwPointName;
			//pPortalTblData->szPointNameText;
			//pPortalTblData->vMap;

			res->vDir = pPortalTblData->vDir;
			res->vLoc = pPortalTblData->vLoc;
			res->byPoint = pPortalTblData->tblidx;
			res->worldID = pPortalTblData->worldId;
			res->wOpCode = GU_PORTAL_RES;
			res->wResultCode = GAME_SUCCESS;
			res->hNpcHandle = req->handle;

			res2->bIsToMoveAnotherServer = false;
			res2->sWorldInfo.sRuleInfo.byRuleType = GAMERULE_NORMAL;
			res2->sWorldInfo.hTriggerObjectOffset = 100000;
			res2->sWorldInfo.tblidx = 1;
			res2->sWorldInfo.worldID = res->worldID;
			res2->vNewDir.x = res->vDir.x;
			res2->vNewDir.y = res->vDir.y;
			res2->vNewDir.z = res->vDir.z;
			res2->vNewLoc.x = res->vLoc.x;
			res2->vNewLoc.y = res->vLoc.y;
			res2->vNewLoc.z = res->vLoc.z;
			res2->wOpCode = GU_CHAR_TELEPORT_RES;
			res2->wResultCode = GAME_SUCCESS;
			//res2->sWorldInfo.sRuleInfo.sTimeQuestRuleInfo;
			this->plr->SetPosition(res2->vNewLoc, res2->vNewDir);
			packet.SetPacketLen( sizeof(sGU_PORTAL_RES) );
			packet2.SetPacketLen( sizeof(sGU_CHAR_TELEPORT_RES) );
			app->db->prepare("UPDATE characters SET CurLocX=? , CurLocY=? , CurLocZ=? , CurDirX=? , CurDirZ=? WHERE CharID = ?");
			app->db->setInt(1, res->vLoc.x);
			app->db->setInt(2, res->vLoc.y);
			app->db->setInt(3, res->vLoc.z);
			app->db->setInt(4, res->vDir.x);
			app->db->setInt(5, res->vDir.z);
			app->db->setInt(6, this->plr->GetCharID());
			app->db->execute();
			g_pApp->Send( this->GetHandle(), &packet );
			g_pApp->Send( this->GetHandle(), &packet2 );
			break;
		}
		i++;
	}
}

//--------------------------------------------------------------------------------------//
//		ATTACK BEGIN
//--------------------------------------------------------------------------------------//
void CClientSession::SendAttackBegin(CNtlPacket * pPacket, CGameServer * app)
{
	
	sUG_CHAR_ATTACK_BEGIN* req = (sUG_CHAR_ATTACK_BEGIN *)pPacket->GetPacketData();

	printf("--- ATTACK BEGIN --- \n");

	if(req->byType == 0)
	{
		AddAttackBegin(this->GetavatarHandle(), this->GetTargetSerialId());
		SendCharActionAttack(this->GetavatarHandle(), this->GetTargetSerialId(), pPacket);
	}
	else if(req->byType == 1)
	{
		//CNtlSobAvatar *pSobAvatar = GetNtlSLGlobal()->GetSobAvatar();
		//CNtlPetBuffer *pPetBuffer = pSobAvatar->GetPetBuffer();
		//AddAttackBegin(pPetBuffer->GetSerialId(0));
		printf("ATTACK FOR TYPE 1 NOT EXIST \n");
	}


}
//--------------------------------------------------------------------------------------//
//		ATTACK END
//--------------------------------------------------------------------------------------//
void CClientSession::SendAttackEnd(CNtlPacket * pPacket, CGameServer * app)
{
	printf("--- ATTACK END --- \n");
	sUG_CHAR_ATTACK_END* req = (sUG_CHAR_ATTACK_END *)pPacket->GetPacketData();
	
	if(req->byType == 0)
	{
		RemoveAttackBegin(this->GetavatarHandle(), this->GetTargetSerialId());
	}
	else if(req->byType == 1)
	{
		//CNtlSobAvatar *pSobAvatar = GetNtlSLGlobal()->GetSobAvatar();
		//CNtlPetBuffer *pPetBuffer = pSobAvatar->GetPetBuffer();
		//RemoveAttackBegin(pPetBuffer->GetSerialId(0));
		printf("END ATTACK FOR TYPE 1 NOT EXIST \n");
	}


}

void CClientSession::AddAttackBegin(RwUInt32 uiSerialId, RwUInt32 m_uiTargetSerialId)
{
	SBattleData *pBattleData = new SBattleData;
	printf("AddAttackBegin SERIAL %i %i \n", uiSerialId,m_uiTargetSerialId);

	pBattleData->uiSerialId			= uiSerialId;
	pBattleData->m_uiTargetSerialId	= m_uiTargetSerialId;
	pBattleData->bAttackMode		= true;
	pBattleData->dwCurrTime			= timeGetTime();

	m_listAttackBegin.push_back(pBattleData);

}

void CClientSession::RemoveAttackBegin(RwUInt32 uiSerialId, RwUInt32 m_uiTargetSerialId)
{
	SBattleData *pBattleData;
	for(BATTLEIT it = m_listAttackBegin.begin(); it != m_listAttackBegin.end(); it++)
	{
		pBattleData = (*it);
		if(pBattleData->uiSerialId == uiSerialId)
		{
			printf("RemoveAttackBegin SERIAL %i %i \n", uiSerialId,m_uiTargetSerialId);
			RWS_DELETE(pBattleData);
			m_listAttackBegin.erase(it);
			return;
		}
	}
}

void CClientSession::SendCharActionAttack(RwUInt32 uiSerialId, RwUInt32 m_uiTargetSerialId, CNtlPacket * pPacket)
{
	CGameServer * app = (CGameServer*)NtlSfxGetApp();
	//static RwUInt8 byChainAttack = 0;
	RwBool bDamageApply = true;

	printf("SendCharActionAttack SERIAL %i %i \n", uiSerialId,m_uiTargetSerialId);

	//printf("AVATAR HANDLE TEST %i \n", this->GetavatarHandle());
	CNtlPacket packet(sizeof(sGU_CHAR_ACTION_ATTACK));
	sGU_CHAR_ACTION_ATTACK * res = (sGU_CHAR_ACTION_ATTACK *)packet.GetPacketData();

	res->wOpCode = GU_CHAR_ACTION_ATTACK;
	res->hSubject = uiSerialId;
	res->hTarget = m_uiTargetSerialId;
	res->bChainAttack = false;

	res->wAttackResultValue = m_iCurrentHp;
	
	res->vShift.x = this->plr->GetPosition().x;
	res->vShift.y = this->plr->GetPosition().y;
	res->vShift.z = this->plr->GetPosition().z;

	res->byAttackSequence = rand()%2;

	if(res->byAttackSequence == 6)
	{
		if(rand()%2)
			res->byAttackResult = BATTLE_ATTACK_RESULT_KNOCKDOWN;
		else
			res->byAttackResult = BATTLE_ATTACK_RESULT_SLIDING;
	}
	else
	{
		RwInt32 iRandValue = rand()%5;
		if(iRandValue <= 2)
			res->byAttackResult = BATTLE_ATTACK_RESULT_HIT;
		else if(iRandValue == 3)
		{
			bDamageApply = false;
			res->byAttackResult = BATTLE_ATTACK_RESULT_DODGE;
		}
		else
		{
			bDamageApply = false;
			res->byAttackResult = BATTLE_ATTACK_RESULT_BLOCK;
		}
	}

	packet.SetPacketLen( sizeof(sGU_CHAR_ACTION_ATTACK) );
	int rc = g_pApp->Send( this->GetHandle() , &packet );
	app->UserBroadcast(&packet);
	//byChainAttack++;
	// update LP
	if(bDamageApply)
	{
		m_iCurrentHp -= m_iCurrentHp;
		if(m_iCurrentHp <= 0)
			m_iCurrentHp = 0;

		SendCharUpdateLp(pPacket, app, m_iCurrentHp, m_uiTargetSerialId);
	}

	// fainting °Ë»ç.
	if(m_iCurrentHp <= 0)
	{
		SendCharUpdateFaintingState(pPacket, app, uiSerialId, m_uiTargetSerialId);
	}

}
void CClientSession::SendCharUpdateLp(CNtlPacket * pPacket, CGameServer * app, RwUInt16 wLp, RwUInt32 m_uiTargetSerialId)
{
	CNtlPacket packet(sizeof(sGU_UPDATE_CHAR_LP));
	sGU_UPDATE_CHAR_LP * res = (sGU_UPDATE_CHAR_LP *)packet.GetPacketData();

	res->wOpCode = GU_UPDATE_CHAR_LP;
	res->handle = m_uiTargetSerialId;
	res->wCurLP = wLp;
	res->wMaxLP = 1000;

	packet.SetPacketLen( sizeof(sGU_UPDATE_CHAR_LP) );
	app->UserBroadcastothers(&packet, this);
	g_pApp->Send( this->GetHandle() , &packet );
}

void CClientSession::SendCharUpdateFaintingState(CNtlPacket * pPacket, CGameServer * app, RwUInt32 uiSerialId, RwUInt32 m_uiTargetSerialId)
{
	printf("char die: %i \n", m_uiTargetSerialId);

	RemoveAttackBegin(uiSerialId, m_uiTargetSerialId);

	CNtlPacket packet(sizeof(sGU_UPDATE_CHAR_STATE));
	sGU_UPDATE_CHAR_STATE * res = (sGU_UPDATE_CHAR_STATE *)packet.GetPacketData();

	res->wOpCode = GU_UPDATE_CHAR_STATE;
	res->handle = m_uiTargetSerialId;
	res->sCharState.sCharStateBase.byStateID = CHARSTATE_FAINTING;
	res->sCharState.sCharStateBase.vCurLoc.x = this->plr->GetPosition().x;
	res->sCharState.sCharStateBase.vCurLoc.y = this->plr->GetPosition().y;
	res->sCharState.sCharStateBase.vCurLoc.z = this->plr->GetPosition().z;
	res->sCharState.sCharStateBase.vCurDir.x = this->plr->GetDirection().x;
	res->sCharState.sCharStateBase.vCurDir.y = this->plr->GetDirection().y;
	res->sCharState.sCharStateBase.vCurDir.z = this->plr->GetDirection().z;

	packet.SetPacketLen( sizeof(sGU_UPDATE_CHAR_STATE) );
	app->UserBroadcastothers(&packet, this);
	g_pApp->Send( this->GetHandle() , &packet );


	app->mob->UpdateDeathStatus(m_uiTargetSerialId, true);

}


void CGameServer::UpdateClient(CNtlPacket * pPacket, CClientSession * pSession)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

// BASIC ATTACK
	SBattleData *pBattleData;
	for(BATTLEIT it = m_listAttackBegin.begin(); it != m_listAttackBegin.end(); it++)
	{
		pBattleData = (*it);
		if(timeGetTime() - pBattleData->dwCurrTime >= MONSTER_ATTACK_UPDATE_TICK)
		{
			printf("ATTACK %i %i\n", pBattleData->uiSerialId, pBattleData->m_uiTargetSerialId);

			//app->pSession->SendCharActionAttack(pBattleData->uiSerialId, pBattleData->m_uiTargetSerialId, pPacket);
			pBattleData->dwCurrTime = timeGetTime();
		}
	}

// MAKE MOBS MOVE
	if(timeGetTime() - app->mob->last_mobMove >= MONSTER_MOVE_UPDATE_TICK)
	{
	//	app->mob->MonsterRandomWalk(pPacket);
		app->mob->last_mobMove = timeGetTime();
	}
}

//--------------------------------------------------------------------------------------//
//		Char toggle fight
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharToggleFighting(CNtlPacket * pPacket, CGameServer * app)
{
//	app->mob->AddToWorld(pPacket, this);
	
}

//--------------------------------------------------------------------------------------//
//		SKILL SHOP REQUEST
//--------------------------------------------------------------------------------------//
void CClientSession::SendShopSkillReq(CNtlPacket * pPacket, CGameServer * app)
{
	sUG_SHOP_SKILL_BUY_REQ * req = (sUG_SHOP_SKILL_BUY_REQ*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_SHOP_SKILL_BUY_RES));
	sGU_SHOP_SKILL_BUY_RES * res = (sGU_SHOP_SKILL_BUY_RES *)packet.GetPacketData();

	res->hNpchandle = req->hNpchandle;
	res->wOpCode = GU_SHOP_SKILL_BUY_RES;
	res->wResultCode  = GAME_SUCCESS;
	printf("pos %d \n", req->byPos);

	packet.SetPacketLen( sizeof(sGU_SHOP_SKILL_BUY_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );
}

//--------------------------------------------------------------------------------------//
//		Char learn skill
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharLearnSkillReq(CNtlPacket * pPacket, CGameServer * app)
{

	WORD		skill_learn_result;

// BUY SKILL FROM SHOP
	sUG_SHOP_SKILL_BUY_REQ * req0 = (sUG_SHOP_SKILL_BUY_REQ*)pPacket->GetPacketData();

	CNtlPacket packet0(sizeof(sGU_SHOP_SKILL_BUY_RES));
	sGU_SHOP_SKILL_BUY_RES * res0 = (sGU_SHOP_SKILL_BUY_RES *)packet0.GetPacketData();

	res0->wOpCode = GU_SHOP_SKILL_BUY_RES;
	res0->hNpchandle = req0->hNpchandle;
	res0->wResultCode  = GAME_SUCCESS;

	packet0.SetPacketLen( sizeof(sGU_SHOP_SKILL_BUY_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet0 );

// LEARN SKILL
	
	sUG_SKILL_LEARN_REQ * req = (sUG_SKILL_LEARN_REQ*)pPacket->GetPacketData();

	CSkillTable* pSkillTable = app->g_pTableContainer->GetSkillTable();
	CMerchantTable* pSkillMasterItemTable = app->g_pTableContainer->GetMerchantTable();
	CNPCTable* pNpcTable = app->g_pTableContainer->GetNpcTable();
	for ( CTable::TABLEIT itNPCSpawn = pNpcTable->Begin(); itNPCSpawn != pNpcTable->End(); ++itNPCSpawn )
	{
		sNPC_TBLDAT* pNPCtData = (sNPC_TBLDAT*) itNPCSpawn->second;
		if(pNPCtData->tblidx == req0->hNpchandle)
		{
			sMERCHANT_TBLDAT* pMerchantData = (sMERCHANT_TBLDAT*) pSkillMasterItemTable->FindData( pNPCtData->amerchant_Tblidx[req0->byMerchantTab] );
			if( pMerchantData->bySell_Type == MERCHANT_SELL_TYPE_SKILL )
			{
				for( RwInt32 j = 0 ; j < NTL_MAX_MERCHANT_COUNT ; ++j )
				{
					if( pMerchantData->aitem_Tblidx[j] == INVALID_TBLIDX )
					{
						skill_learn_result = 1004;
						break;
					}

					if(req0->byPos == j){
						sSKILL_TBLDAT* pSkillData = (sSKILL_TBLDAT*) pSkillTable->FindData( pMerchantData->aitem_Tblidx[j] );
					  if(app->qry->CheckIfSkillAlreadyLearned(pSkillData->tblidx, this->plr->GetCharID()) == false){
						if(this->plr->GetMoney() >= pSkillData->dwRequire_Zenny){
							if(this->plr->GetLevel() >= pSkillData->byRequire_Train_Level){
								if(this->plr->GetSpPoint() >= pSkillData->wRequireSP){
									skill_learn_result = 500;
									// Skill learned notification
									CNtlPacket packet2(sizeof(sGU_SKILL_LEARNED_NFY));
									sGU_SKILL_LEARNED_NFY * res2 = (sGU_SKILL_LEARNED_NFY *)packet2.GetPacketData();

									res2->wOpCode = GU_SKILL_LEARNED_NFY;
									res2->skillId = pSkillData->tblidx;
									res2->bySlot = pSkillData->bySlot_Index;

									app->qry->InsertNewSkill(pSkillData->tblidx, this->plr->GetCharID(), pSkillData->bySlot_Index, pSkillData->wKeep_Time, pSkillData->wNext_Skill_Train_Exp);
									this->plr->SetMoney(this->plr->GetMoney() - pSkillData->dwRequire_Zenny);
									this->plr->SetSpPoint(this->plr->GetSpPoint() - pSkillData->wRequireSP);

									packet2.SetPacketLen( sizeof(sGU_SKILL_LEARNED_NFY) );
									g_pApp->Send( this->GetHandle() , &packet2 );
									break;
								}else
								skill_learn_result = 645;
								break;

							}else
								skill_learn_result = 501;
								break;
						}else
							skill_learn_result = 617;
							break;
					  }else
						skill_learn_result = 620;
						break;
					}
				}
			}
		}
	}

//LEARN SKILL RESULT
	CNtlPacket packet(sizeof(sGU_SKILL_LEARN_RES));
	sGU_SKILL_LEARN_RES * res = (sGU_SKILL_LEARN_RES *)packet.GetPacketData();

	res->wOpCode = GU_SKILL_LEARN_RES;
	res->wResultCode = skill_learn_result;

	packet.SetPacketLen( sizeof(sGU_SKILL_LEARN_RES) );
	g_pApp->Send( this->GetHandle() , &packet );

}


//--------------------------------------------------------------------------------------//
//		MOVE ITEM
//--------------------------------------------------------------------------------------//
void CClientSession::SendItemMoveReq(CNtlPacket * pPacket, CGameServer * app)
{
    sUG_ITEM_MOVE_REQ * req = (sUG_ITEM_MOVE_REQ*)pPacket->GetPacketData();

    CNtlPacket packet(sizeof(sGU_ITEM_MOVE_RES));
    sGU_ITEM_MOVE_RES * res = (sGU_ITEM_MOVE_RES *)packet.GetPacketData();
	
	app->db->prepare("SELECT * FROM items WHERE owner_id=? AND place=? AND pos=?");
	app->db->setInt(1, this->plr->GetCharID());
	app->db->setInt(2, req->bySrcPlace);
	app->db->setInt(3, req->bySrcPos);
	app->db->execute();
	app->db->fetch();
	RwUInt32 uniqueID = app->db->getInt("id");

	if(app->qry->CheckIfCanMoveItemThere(this->plr->GetCharID(), req->byDestPlace, req->byDestPos) == false){
		res->wResultCode = GAME_MOVE_CANT_GO_THERE;
	} else {
		app->qry->UpdateItemPlaceAndPos(uniqueID, req->byDestPlace, req->byDestPos);
		res->wResultCode = GAME_SUCCESS;
	}

		res->wOpCode = GU_ITEM_MOVE_RES;
		res->hSrcItem = uniqueID;
		res->bySrcPlace = req->bySrcPlace;
		res->bySrcPos = req->bySrcPos;
		res->hDestItem = -1;
		res->byDestPlace = req->byDestPlace;
		res->byDestPos = req->byDestPos;

		packet.SetPacketLen(sizeof(sGU_ITEM_MOVE_RES));
		g_pApp->Send( this->GetHandle() , &packet );

}

//--------------------------------------------------------------------------------------//
//		DELETE ITEM
//--------------------------------------------------------------------------------------//
void CClientSession::SendItemDeleteReq(CNtlPacket * pPacket, CGameServer * app)
{
// GET DELETE ITEM
	sUG_ITEM_DELETE_REQ * req = (sUG_ITEM_DELETE_REQ*)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_ITEM_DELETE_RES));
	sGU_ITEM_DELETE_RES * res = (sGU_ITEM_DELETE_RES *)packet.GetPacketData();
	
	app->db->prepare("SELECT id,place,pos FROM items WHERE owner_id=? AND place=? AND pos=?");
	app->db->setInt(1, this->plr->GetCharID());
	app->db->setInt(2, req->bySrcPlace);
	app->db->setInt(3, req->bySrcPos);
	app->db->execute();
	app->db->fetch();

	RwUInt32 u_itemid = app->db->getInt("id");
	RwUInt32 item_place = app->db->getInt("place");
	RwUInt32 item_pos = app->db->getInt("pos");

	res->wOpCode = GU_ITEM_DELETE_RES;
	res->wResultCode = GAME_SUCCESS;
	res->byPlace = req->bySrcPlace;
	res->byPos = req->bySrcPos;

	packet.SetPacketLen( sizeof(sGU_ITEM_DELETE_RES) );
	g_pApp->Send( this->GetHandle() , &packet );

// DELETE ITEM
	app->qry->DeleteItemById(u_itemid);

	CNtlPacket packet2(sizeof(sGU_ITEM_DELETE));
	sGU_ITEM_DELETE * res2 = (sGU_ITEM_DELETE *)packet2.GetPacketData();

	res2->bySrcPlace = item_place;
	res2->bySrcPos = item_pos;
	res2->hSrcItem = u_itemid;
	res2->wOpCode = GU_ITEM_DELETE;

	packet2.SetPacketLen( sizeof(sGU_ITEM_DELETE) );
	g_pApp->Send( this->GetHandle() , &packet2 );
}

//--------------------------------------------------------------------------------------//
//		STACK ITEM
//--------------------------------------------------------------------------------------//
void CClientSession::SendItemStackReq(CNtlPacket * pPacket, CGameServer * app)
{
	sUG_ITEM_MOVE_STACK_REQ * req = (sUG_ITEM_MOVE_STACK_REQ*)pPacket->GetPacketData();

// GET DATA FROM MYSQL
	app->db->prepare("SELECT id,tblidx FROM items WHERE owner_id=? AND place=? AND pos=?");
	app->db->setInt(1, this->plr->GetCharID());
	app->db->setInt(2, req->bySrcPlace);
	app->db->setInt(3, req->bySrcPos);
	app->db->execute();
	app->db->fetch();
	unsigned int uniqueID = app->db->getInt("id");
	unsigned int item1ID = app->db->getInt("tblidx");

	app->db->prepare("SELECT id,count,tblidx FROM items WHERE owner_id=? AND place=? AND pos=?");
	app->db->setInt(1, this->plr->GetCharID());
	app->db->setInt(2, req->byDestPlace);
	app->db->setInt(3, req->byDestPos);
	app->db->execute();
	app->db->fetch();
	unsigned int uniqueID2 = app->db->getInt("id");
	unsigned int item2ID = app->db->getInt("tblidx");

	if (item1ID == item2ID)
	{
		// UPDATE ITEMS
		CNtlPacket packet(sizeof(sGU_ITEM_MOVE_STACK_RES));
		sGU_ITEM_MOVE_STACK_RES * res = (sGU_ITEM_MOVE_STACK_RES *)packet.GetPacketData();

		CNtlPacket packet1(sizeof(sGU_ITEM_DELETE));
		sGU_ITEM_DELETE * res1 = (sGU_ITEM_DELETE *)packet1.GetPacketData();

		res->wOpCode = GU_ITEM_MOVE_STACK_RES;
		res->bySrcPlace = req->bySrcPlace;
		res->bySrcPos = req->bySrcPos;
		res->byDestPlace = req->byDestPlace;
		res->byDestPos = req->byDestPos;
		res->hSrcItem = uniqueID;
		res->hDestItem = uniqueID2;
		res->byStackCount1 = req->byStackCount;
		res->byStackCount2 = req->byStackCount + app->db->getInt("count");
		res->wResultCode = GAME_SUCCESS;

		res1->bySrcPlace = req->bySrcPlace;
		res1->bySrcPos = req->bySrcPos;
		res1->hSrcItem = uniqueID;
		res1->wOpCode = GU_ITEM_DELETE;

	// UPDATE AND DELETE
		app->db->prepare("UPDATE items SET count=? WHERE id=?");
		app->db->setInt(1, res->byStackCount2);
		app->db->setInt(2, uniqueID2);
		app->db->execute();

		app->db->prepare("DELETE FROM items WHERE id=?");
		app->db->setInt(1, uniqueID);
		app->db->execute();


	// Send packet to client
		packet.SetPacketLen(sizeof(sGU_ITEM_MOVE_STACK_RES));
		g_pApp->Send( this->GetHandle() , &packet );
		packet1.SetPacketLen(sizeof(sGU_ITEM_DELETE));
		g_pApp->Send( this->GetHandle() , &packet1 );
	}
	else
	{
		CNtlPacket packet(sizeof(sGU_ITEM_MOVE_STACK_RES));
		sGU_ITEM_MOVE_STACK_RES * res = (sGU_ITEM_MOVE_STACK_RES *)packet.GetPacketData();
		res->wOpCode = GU_ITEM_MOVE_STACK_RES;
		res->wResultCode = GAME_FAIL;
		packet.SetPacketLen(sizeof(sGU_ITEM_MOVE_STACK_RES));
		g_pApp->Send( this->GetHandle() , &packet );
	}
}

void CClientSession::SendShopStartReq(CNtlPacket * pPacket, CGameServer * app)
{
	sUG_SHOP_START_REQ * req = (sUG_SHOP_START_REQ *)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sGU_SHOP_START_RES));
	sGU_SHOP_START_RES * res = (sGU_SHOP_START_RES *)packet.GetPacketData();

	res->wOpCode = GU_SHOP_START_RES;
	res->wResultCode = GAME_SUCCESS;
	res->handle = req->handle;
	res->byType = 1;

	packet.SetPacketLen( sizeof(sGU_SHOP_START_RES) );
	g_pApp->Send( this->GetHandle(), &packet );
}
void CClientSession::SendShopBuyReq(CNtlPacket * pPacket, CGameServer * app)
{
	WORD		buy_item_result;

	sUG_SHOP_BUY_REQ * req = (sUG_SHOP_BUY_REQ *)pPacket->GetPacketData();
	CMerchantTable* pMerchantItemTable = app->g_pTableContainer->GetMerchantTable();
	CItemTable *itemTbl = app->g_pTableContainer->GetItemTable();
	CNPCTable* pNpcTable = app->g_pTableContainer->GetNpcTable();
	for ( CTable::TABLEIT itNPCSpawn = pNpcTable->Begin(); itNPCSpawn != pNpcTable->End(); ++itNPCSpawn )
	{
		sNPC_TBLDAT* pNPCtData = (sNPC_TBLDAT*) itNPCSpawn->second;
		if(pNPCtData->tblidx == req->handle)
		{
			sMERCHANT_TBLDAT* pMerchantData = (sMERCHANT_TBLDAT*) pMerchantItemTable->FindData( pNPCtData->amerchant_Tblidx[req->sBuyData[0].byMerchantTab] );
			if( pMerchantData->bySell_Type == MERCHANT_SELL_TYPE_ITEM )
			{
				for( RwInt32 j = 0 ; j < NTL_MAX_MERCHANT_COUNT ; j++ )
				{
					if( pMerchantData->aitem_Tblidx[j] == INVALID_TBLIDX )
					{
						buy_item_result = 501;
						break;
					}
					if (j == 0)
						j = req->sBuyData[j].byItemPos;
					for(int l = 12; l >= 0; l--)
					{
						//sGU_TRADE_ZENNY_UPDATE_NFY;
						if(req->sBuyData[l].byItemPos == j)
						{
							sITEM_TBLDAT* pItemData = (sITEM_TBLDAT*) itemTbl->FindData( pMerchantData->aitem_Tblidx[j] );
							int ItemPos = 0;

							app->db->prepare("SELECT * FROM items WHERE owner_ID = ? AND place=1 ORDER BY pos ASC");
							app->db->setInt(1, this->plr->GetCharID());
							app->db->execute();
							int k = 0;
							while(app->db->fetch())
							{
								if(app->db->getInt("pos") < NTL_MAX_ITEM_SLOT)
								ItemPos = app->db->getInt("pos") + 1;
								else
								ItemPos = app->db->getInt("pos");
								k++;
							}
							app->db->prepare("CALL BuyItemFromShop (?,?,?,?,?, @unique_iID)");
							app->db->setInt(1, pMerchantData->aitem_Tblidx[j]);
							app->db->setInt(2, this->plr->GetCharID());
							app->db->setInt(3, ItemPos);
							app->db->setInt(4, pItemData->byRank);
							app->db->setInt(5, pItemData->byDurability);
							app->db->execute();
							app->db->execute("SELECT @unique_iID");
							app->db->fetch();

							CNtlPacket packet2(sizeof(sGU_ITEM_CREATE));
							sGU_ITEM_CREATE * res2 = (sGU_ITEM_CREATE *)packet2.GetPacketData();

							res2->bIsNew = true;
							res2->wOpCode = GU_ITEM_CREATE;
							res2->handle = app->db->getInt("@unique_iID");
							res2->sItemData.charId = this->GetavatarHandle();
							res2->sItemData.itemNo = pItemData->tblidx;
							res2->sItemData.byStackcount = req->sBuyData[0].byStack;
							res2->sItemData.itemId = app->db->getInt("@unique_iID");
							res2->sItemData.byPlace = 1;
							res2->sItemData.byPosition = ItemPos;
							res2->sItemData.byCurrentDurability = pItemData->byDurability;
							res2->sItemData.byRank = pItemData->byRank;

							packet2.SetPacketLen( sizeof(sGU_ITEM_CREATE) );
							g_pApp->Send( this->GetHandle(), &packet2 );

							break;
						}

					}
				}
			}
		}
	}

	CNtlPacket packet(sizeof(sGU_SHOP_BUY_RES));
	sGU_SHOP_BUY_RES * res = (sGU_SHOP_BUY_RES *)packet.GetPacketData();

	res->wOpCode = GU_SHOP_BUY_RES;
	res->wResultCode = GAME_SUCCESS;
	res->handle = req->handle;

	packet.SetPacketLen( sizeof(sGU_SHOP_BUY_RES) );
	g_pApp->Send( this->GetHandle(), &packet );
}
void CClientSession::SendShopEndReq(CNtlPacket * pPacket, CGameServer * app)
{
	CNtlPacket packet(sizeof(sGU_SHOP_END_RES));
	sGU_SHOP_END_RES * res = (sGU_SHOP_END_RES *)packet.GetPacketData();

	res->wOpCode = GU_SHOP_END_RES;
	res->wResultCode = GAME_SUCCESS;

	packet.SetPacketLen( sizeof(sGU_SHOP_END_RES) );
	g_pApp->Send( this->GetHandle(), &packet );
}
void	CClientSession::SendShopSellReq(CNtlPacket * pPacket, CGameServer * app)
{
	sUG_SHOP_SELL_REQ * req = (sUG_SHOP_SELL_REQ *)pPacket->GetPacketData();
	CNtlPacket packet(sizeof(sGU_SHOP_SELL_RES));
	sGU_SHOP_SELL_RES * res = (sGU_SHOP_SELL_RES *)packet.GetPacketData();
	CNtlPacket packet1(sizeof(sGU_ITEM_DELETE));
	sGU_ITEM_DELETE * res1 = (sGU_ITEM_DELETE *)packet1.GetPacketData();

	CItemTable *itemTbl = app->g_pTableContainer->GetItemTable();
	int zenit_amount = 0;
	for (int i = 0; (req->sSellData[i].byStack != 0 ); i++)
	{
		app->db->prepare("SELECT * FROM items WHERE owner_ID = ? AND place = ? AND pos = ?");
		app->db->setInt(1, this->plr->GetCharID());
		app->db->setInt(2, req->sSellData[i].byPlace);
		app->db->setInt(3, req->sSellData[i].byPos);
		app->db->execute();
		app->db->fetch();
		int item_id = app->db->getInt("tblidx");
		int id = app->db->getInt("id");

		res1->bySrcPlace = req->sSellData[i].byPlace;
		res1->bySrcPos = req->sSellData[i].byPos;
		res1->hSrcItem = id;
		res1->wOpCode = GU_ITEM_DELETE;
		packet1.SetPacketLen(sizeof(sGU_ITEM_DELETE));

		sITEM_TBLDAT* pItemData = (sITEM_TBLDAT*) itemTbl->FindData( item_id );
		zenit_amount += pItemData->bySell_Price * req->sSellData[i].byStack;
		int count_less = req->sSellData[i].byStack - app->db->getInt("count");
		if (count_less <= 0)
		{
			g_pApp->Send( this->GetHandle() , &packet1 );
			app->db->prepare("DELETE FROM items WHERE id = ?");
			app->db->setInt(1, id);
			app->db->execute();
		}
		else if (count_less >= 1)
		{
			app->db->prepare("UPDATE items SET count=? WHERE id=?");
			app->db->setInt(1, count_less);
			app->db->setInt(2, id);
			app->db->execute();
		}
	}
	app->db->prepare("select * from characters WHERE CharID=?");
	app->db->setInt(1, this->plr->GetCharID());
	app->db->execute();
	app->db->fetch();
	int zeni_plr = zeni_plr = app->db->getInt("money");

	app->db->prepare("UPDATE characters SET money=? WHERE CharID=?");
	app->db->setInt(1, zeni_plr + zenit_amount);
	app->db->setInt(2, this->plr->GetCharID());
	app->db->execute();

	res->handle = req->handle;
	res->wOpCode = GU_SHOP_SELL_RES;
	res->wResultCode = GAME_SUCCESS;
	packet.SetPacketLen(sizeof(sGU_SHOP_SELL_RES));
	g_pApp->Send( this->GetHandle() , &packet );
	g_pApp->Send( this->GetHandle() , &packet1 );
}
//ROLL DICE
void	CClientSession::SendRollDice(CNtlPacket * pPacket, CGameServer * app)
{
	CNtlPacket packet(sizeof(sGU_DICE_ROLL_RES));
	sGU_DICE_ROLL_RES * res = (sGU_DICE_ROLL_RES *)packet.GetPacketData();

	res->wOpCode = GU_DICE_ROLL_RES;
	res->wDiceResult = (WORD) rand() % 100;
	res->wResultCode = GAME_SUCCESS;

	packet.SetPacketLen( sizeof(sGU_DICE_ROLL_RES) );
	g_pApp->Send( this->GetHandle() , &packet );

	CNtlPacket packet2(sizeof(sGU_DICE_ROLLED_NFY));
	sGU_DICE_ROLLED_NFY * res2 = (sGU_DICE_ROLLED_NFY *)packet2.GetPacketData();

	res2->wDiceResult = res->wDiceResult;
	res2->wOpCode = GU_DICE_ROLLED_NFY;
	res2->hSubject = this->GetavatarHandle();

	packet2.SetPacketLen( sizeof(sGU_DICE_ROLLED_NFY) );
	g_pApp->Send( this->GetHandle() , &packet2 );
	app->UserBroadcastothers(&packet2, this);
}

void	CClientSession::SendScouterIndicatorReq(CNtlPacket * pPacket, CGameServer * app)
{
	sUG_SCOUTER_INDICATOR_REQ * req = (sUG_SCOUTER_INDICATOR_REQ *)pPacket->GetPacketData();
	CNtlPacket packet(sizeof(sGU_SCOUTER_INDICATOR_RES));
	sGU_SCOUTER_INDICATOR_RES * res = (sGU_SCOUTER_INDICATOR_RES *)packet.GetPacketData();

	int mobid = 0;

	if ((mobid = IsMonsterIDInsideList(req->hTarget)) != 0)
	{
		res->hTarget = req->hTarget;
		res->dwRetValue = 0;
		res->wOpCode = GU_SCOUTER_INDICATOR_RES;
		res->wResultCode = GAME_SUCCESS;
		
		CMobTable *Mob = app->g_pTableContainer->GetMobTable();
		for ( CTable::TABLEIT itmob = Mob->Begin(); itmob != Mob->End(); ++itmob )
		{
			sMOB_TBLDAT* pMOBtData = (sMOB_TBLDAT*) itmob->second;
			if (pMOBtData->tblidx == mobid)
			{
				CFormulaTable *form = app->g_pTableContainer->GetFormulaTable();
				for ( CTable::TABLEIT itfor = form->Begin(); itfor != form->End(); ++itfor )
				{
					sFORMULA_TBLDAT *formtbl = (sFORMULA_TBLDAT*) itmob->second;
					float lolilol = formtbl->afRate[0];
				}
			}
		}
	}
}