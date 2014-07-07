#pragma once

#include "SharedType.h"

static RwUInt32 m_uiSerialId = 5;
static RwUInt32 m_uiTargetSerialId = 0;


typedef struct _SBattleData
{
	RwUInt32			uiSerialId;
	RwUInt32			m_uiTargetSerialId;
	RwBool				bAttackMode;
	DWORD				dwCurrTime;
}SBattleData;


#define MONSTER_ATTACK_UPDATE_TICK		2000


static RwUInt32 m_iCurrentHp		=		10000;

#ifndef GS_FUNCTIONS_CLASS_H
#define GS_FUNCTIONS_CLASS_H


class CGameServer;
class CClientSession;
class CNtlPacket;

class GsFunctionsClass
{
public:
	GsFunctionsClass(){};
	~GsFunctionsClass(){};

public:

	bool						DeleteItemByUIdPlacePos(CNtlPacket * pPacket, CClientSession * pSession, RwUInt32 UniqueID, RwUInt32 Place, RwUInt32 Pos);
	bool						UpdateCharMoney(CNtlPacket * pPacket, CClientSession * pSession, RwUInt32 ChangeType, RwUInt32 MoneyAmount, RwUInt32 AvatarHandle);
	

};

#endif