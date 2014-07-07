#ifndef QUERY_CLASS_H
#define QUERY_CLASS_H

#include "NtlSfx.h"
#include "SharedType.h"
#include "mysqlconn_wrapper.h"
#include <list>


class CGameServer;

class QueryClass
{
public:
	QueryClass(){};
	~QueryClass(){};

public:

	bool						InsertNewSkill(TBLIDX SkillID, int CharID, BYTE SlotID, WORD Time, WORD Exp);
	bool						CheckIfSkillAlreadyLearned(TBLIDX SkillID, int CharID);
	bool						DeleteItemById(TBLIDX ItemID);
	bool						CheckIfCanMoveItemThere(RwUInt32 CharID, BYTE Place, BYTE Pos);
	bool						UpdateItemPlaceAndPos(RwUInt32 ItemID, BYTE Place, BYTE Pos);
	bool						UpdateItemsCount(RwUInt32 ItemID, RwUInt32 Count);
	bool						UpdateItemOwnerIdWithUniqueID(RwUInt32 NewOwnerID, RwUInt32 UniqueID);
	bool						SetMinusMoney(RwUInt32 CharID, int Money);
	bool						SetPlusMoney(RwUInt32 CharID, int Money);
	bool						SetMailRead(RwUInt32 MailID);
	bool						DeleteFromMailByID(RwUInt32 MailID);
	bool						ChangeItemOwnerByUIdPlacePos(RwUInt32 NewOwnerID, RwUInt32 UniqueID, RwUInt32 Place, RwUInt32 Pos);
	bool						UpdateMailLock(RwUInt32 MailID, RwUInt32 LockStatus);
	bool						UpdateCharAwayStatus(RwUInt32 CharID, RwUInt32 AwayStatus);
	bool						SetMailAccept(RwUInt32 CharID, RwUInt32 MailID);

};

#endif