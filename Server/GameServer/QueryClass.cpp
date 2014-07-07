#include "stdafx.h"
#include "GameServer.h"


bool	QueryClass::InsertNewSkill(TBLIDX SkillID, int CharID, BYTE SlotID, WORD Time, WORD Exp)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("INSERT INTO skills (skill_id,owner_id,SlotID,TimeRemaining,Exp) VALUES (?,?,?,?,?) ");
	app->db->setInt(1, SkillID);
	app->db->setInt(2, CharID);
	app->db->setInt(3, SlotID);
	app->db->setInt(4, Time);
	app->db->setInt(5, Exp);
	app->db->execute();

	return true;
}
bool	QueryClass::CheckIfSkillAlreadyLearned(TBLIDX SkillID, int CharID)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("SELECT skill_id FROM skills WHERE skill_id=? AND owner_id=?");
	app->db->setInt(1, SkillID);
	app->db->setInt(2, CharID);
	app->db->execute();

	if(app->db->rowsCount() == 0)
		return false;
	else
		return true;
}
bool	QueryClass::DeleteItemById(TBLIDX ItemID)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("DELETE FROM items WHERE id=?");
	app->db->setInt(1, ItemID);
	app->db->execute();

	return true;
}
bool	QueryClass::CheckIfCanMoveItemThere(RwUInt32 CharID, BYTE Place, BYTE Pos)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("SELECT * FROM items WHERE owner_id=? AND place=? AND pos=?");
	app->db->setInt(1, CharID);
	app->db->setInt(2, Place);
	app->db->setInt(3, Pos);
	app->db->execute();

	if(app->db->rowsCount() == 0)
		return true;
	else
		return false;
}
bool	QueryClass::UpdateItemPlaceAndPos(RwUInt32 ItemID, BYTE Place, BYTE Pos)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("UPDATE items SET place=? , pos=? WHERE id=?");
	app->db->setInt(1, Place);
	app->db->setInt(2, Pos);
	app->db->setInt(3, ItemID);
	app->db->execute();

	return true;
}
bool	QueryClass::UpdateItemsCount(RwUInt32 ItemID, RwUInt32 Count)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("UPDATE items SET count=? WHERE id=?");
	app->db->setInt(1, Count);
	app->db->setInt(2, ItemID);
	app->db->execute();

	return true;
}
bool	QueryClass::UpdateItemOwnerIdWithUniqueID(RwUInt32 NewOwnerID, RwUInt32 UniqueID)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("UPDATE items SET owner_id=? WHERE id=?");
	app->db->setInt(1, NewOwnerID);
	app->db->setInt(2, UniqueID);
	app->db->execute();

	return true;
}
bool	QueryClass::SetMinusMoney(RwUInt32 CharID, int Money)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("UPDATE characters SET money=money-? WHERE CharID=?");
	app->db->setInt(1, Money);
	app->db->setInt(2, CharID);
	app->db->execute();

	return true;
}
bool	QueryClass::SetPlusMoney(RwUInt32 CharID, int Money)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("UPDATE characters SET money=money+? WHERE CharID=?");
	app->db->setInt(1, Money);
	app->db->setInt(2, CharID);
	app->db->execute();

	return true;
}
bool	QueryClass::SetMailRead(RwUInt32 MailID)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("UPDATE mail SET bIsRead=1 WHERE id=?");
	app->db->setInt(1, MailID);
	app->db->execute();

	return true;
}
bool	QueryClass::DeleteFromMailByID(RwUInt32 MailID)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("DELETE FROM mail WHERE id=?");
	app->db->setInt(1, MailID);
	app->db->execute();

	return true;
}
bool	QueryClass::ChangeItemOwnerByUIdPlacePos(RwUInt32 NewOwnerID, RwUInt32 UniqueID, RwUInt32 Place, RwUInt32 Pos)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("UPDATE items SET owner_id=? , place=? , pos=? WHERE id=?");
	app->db->setInt(1, NewOwnerID);
	app->db->setInt(2, Place);
	app->db->setInt(3, Pos);
	app->db->setInt(4, UniqueID);
	app->db->execute();

	return true;
}
bool	QueryClass::UpdateMailLock(RwUInt32 MailID, RwUInt32 LockStatus)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("UPDATE mail SET bIsLock=? WHERE id=?");
	app->db->setInt(1, LockStatus);
	app->db->setInt(2, MailID);
	app->db->execute();

	return true;
}
bool	QueryClass::UpdateCharAwayStatus(RwUInt32 CharID, RwUInt32 AwayStatus)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("UPDATE characters SET MailIsAway=? WHERE CharID=?");
	app->db->setInt(1, AwayStatus);
	app->db->setInt(2, CharID);
	app->db->execute();

	return true;
}
bool	QueryClass::SetMailAccept(RwUInt32 CharID, RwUInt32 MailID)
{
	CGameServer * app = (CGameServer*) NtlSfxGetApp();

	app->db->prepare("UPDATE mail SET bIsAccept=1 WHERE id=? AND CharID=?");
	app->db->setInt(1, MailID);
	app->db->setInt(2, CharID);
	app->db->execute();

	return true;
}