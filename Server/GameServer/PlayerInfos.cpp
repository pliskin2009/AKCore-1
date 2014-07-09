#include "stdafx.h"
#include "GameServer.h"


sVECTOR3	PlayerInfos::GetPosition()
{
	return this->vCurLoc;
}
sVECTOR3	PlayerInfos::GetDirection()
{
	return this->vCurDir;
}
void		PlayerInfos::SetPosition(sVECTOR3 curPos, sVECTOR3 curDir)
{
	this->vCurLoc.x = curPos.x;
	this->vCurLoc.y = curPos.y;
	this->vCurLoc.z = curPos.z;

	this->vCurDir.x = curDir.x;
	this->vCurDir.y = curDir.y;
	this->vCurDir.z = curDir.z;
}

int			PlayerInfos::GetCharID()
{
	return this->charID;
}

int			PlayerInfos::GetAccountID()
{
	return this->AccountID;
}

void		PlayerInfos::SetcharID(int id)
{
	this->charID = id;
}

void		PlayerInfos::SetAccountID(int id)
{
	this->AccountID = id;
}

std::string		PlayerInfos::GetName()
{
	return this->Myname;
}

void		PlayerInfos::SetName(std::string name)
{
	this->Myname = name;
}

void		PlayerInfos::SetWorldID(int id)
{
	this->WorldID = id;
}
int			PlayerInfos::GetWorldID()
{
	return this->WorldID;
}

void		PlayerInfos::SetWorldTableID(int id)
{
	this->WorldTableID = id;
}
int			PlayerInfos::GetWorldTableID()
{
	return this->WorldTableID;
}

void		PlayerInfos::SetLevel(BYTE id)
{
	this->Level = id;
}
BYTE		PlayerInfos::GetLevel()
{
	return this->Level;
}

void		PlayerInfos::SetCurExp(int id)
{
	this->CurExp = id;
}
int		PlayerInfos::GetCurExp()
{
	return this->CurExp;
}

void		PlayerInfos::SetMoney(DWORD id)
{
	this->Money = id;
}
DWORD		PlayerInfos::GetMoney()
{
	return this->Money;
}

std::string		PlayerInfos::GetGuildName()
{
	return this->GuildName;
}

void		PlayerInfos::SetGuildName(std::string name)
{
	this->GuildName = name;
}

void		PlayerInfos::SetBaseMaxLp(int id)
{
	this->BaseMaxLp = id;
}
int		PlayerInfos::GetBaseMaxLp()
{
	return this->BaseMaxLp;
}

void		PlayerInfos::SetLastMaxLp(int id)
{
	this->LastMaxLp = id;
}
int		PlayerInfos::GetLastMaxLp()
{
	return this->LastMaxLp;
}

void		PlayerInfos::SetCurLp(int id)
{
	this->CurLp = id;
}
int		PlayerInfos::GetCurLp()
{
	return this->CurLp;
}

void		PlayerInfos::SetBaseMaxEp(int id)
{
	this->BaseMaxEp = id;
}
int		PlayerInfos::GetBaseMaxEp()
{
	return this->BaseMaxEp;
}

void		PlayerInfos::SetLastMaxEp(int id)
{
	this->LastMaxEp = id;
}
int		PlayerInfos::GetLastMaxEp()
{
	return this->LastMaxEp;
}

void		PlayerInfos::SetCurEp(int id)
{
	this->CurEp = id;
}
int		PlayerInfos::GetCurEp()
{
	return this->CurEp;
}

void		PlayerInfos::SetBaseMaxRp(int id)
{
	this->BaseMaxRp = id;
}
int		PlayerInfos::GetBaseMaxRp()
{
	return this->BaseMaxRp;
}

void		PlayerInfos::SetLastMaxRp(int id)
{
	this->LastMaxRp = id;
}
int		PlayerInfos::GetLastMaxRp()
{
	return this->LastMaxRp;
}

void		PlayerInfos::SetCurRp(int id)
{
	this->CurRp = id;
}
int		PlayerInfos::GetCurRp()
{
	return this->CurRp;
}

void		PlayerInfos::SetReputation(int id)
{
	this->Reputation = id;
}
int		PlayerInfos::GetReputation()
{
	return this->Reputation;
}

void		PlayerInfos::SetMudosaPoint(int id)
{
	this->MudosaPoint = id;
}
int		PlayerInfos::GetMudosaPoint()
{
	return this->MudosaPoint;
}

void		PlayerInfos::SetSpPoint(int id)
{
	this->SpPoint = id;
}
int		PlayerInfos::GetSpPoint()
{
	return this->SpPoint;
}

void		PlayerInfos::SetBaseStr(int id)
{
	this->BaseStr = id;
}
int		PlayerInfos::GetBaseStr()
{
	return this->BaseStr;
}

void		PlayerInfos::SetLastStr(int id)
{
	this->LastStr = id;
}
int		PlayerInfos::GetLastStr()
{
	return this->LastStr;
}

void		PlayerInfos::SetBaseCon(int id)
{
	this->BaseCon = id;
}
int		PlayerInfos::GetBaseCon()
{
	return this->BaseCon;
}

void		PlayerInfos::SetLastCon(int id)
{
	this->LastCon = id;
}
int		PlayerInfos::GetLastCon()
{
	return this->LastCon;
}

void		PlayerInfos::SetBaseFoc(int id)
{
	this->BaseFoc = id;
}
int		PlayerInfos::GetBaseFoc()
{
	return this->BaseFoc;
}

void		PlayerInfos::SetLastFoc(int id)
{
	this->LastFoc = id;
}
int		PlayerInfos::GetLastFoc()
{
	return this->LastFoc;
}

void		PlayerInfos::SetBaseDex(int id)
{
	this->BaseDex = id;
}
int		PlayerInfos::GetBaseDex()
{
	return this->BaseDex;
}

void		PlayerInfos::SetLastDex(int id)
{
	this->LastDex = id;
}
int		PlayerInfos::GetLastDex()
{
	return this->LastDex;
}

void		PlayerInfos::SetBaseSol(int id)
{
	this->BaseSol = id;
}
int		PlayerInfos::GetBaseSol()
{
	return this->BaseSol;
}

void		PlayerInfos::SetLastSol(int id)
{
	this->LastSol = id;
}
int		PlayerInfos::GetLastSol()
{
	return this->LastSol;
}

void		PlayerInfos::SetBaseEng(int id)
{
	this->BaseEng = id;
}
int		PlayerInfos::GetBaseEng()
{
	return this->BaseEng;
}

void		PlayerInfos::SetLastEng(int id)
{
	this->LastEng = id;
}
int		PlayerInfos::GetLastEng()
{
	return this->LastEng;
}

void		PlayerInfos::Setmob_SpawnTime(RwUInt32 id)
{
	this->mob_SpawnTime = id;
}
RwUInt32		PlayerInfos::Getmob_SpawnTime()
{
	return this->mob_SpawnTime;
}

void		PlayerInfos::Setlast_SpawnPos(sVECTOR3 id)
{
	this->last_SpawnPos = id;
}
sVECTOR3		PlayerInfos::Getlast_SpawnPos()
{
	return this->last_SpawnPos;
}

void		PlayerInfos::SavePlayerData()
{
	this->db = new MySQLConnWrapper;
	this->db->connect();
	this->db->switchDb("dbo");

	char* save_query = "UPDATE characters SET CurLocX=? , CurLocY=? , CurLocZ=? , CurDirX=? , CurDirZ=? , level=?, exp=?, WorldTable=?, WorldID=?, money=?, MoneyBank=?, reputation=?, MudosaPoint=?, SpPoint=?, BaseStr=?, LastStr=?, BaseCon=?, LastCon=?, BaseFoc=?, LastFoc=?, BaseDex=?, LastDex=?, BaseSol=?, LastSol=?, BaseEng=?, LastEng=?, BaseMaxLP=?, LastMaxLP=?, BaseMaxRp=?, LastMaxRP=? WHERE CharID = ?";
	char* save_query2 = "UPDATE characters SET BaseLpRegen=?, LastLpRegen=?, BaseLpSitdownRegen=?, LastLpSitdownRegen=?, BaseLpBattleRegen=?, LastLpBattleRegen=?, BaseEpRegen=?, LastEpRegen=?, BaseEpSitdownRegen=?, LastEpSitdownRegen=?, BaseEpBattleRegen=?, LastEpBattleRegen=?, BaseRpRegen=?, LastRpRegen=?, LastRpDimimutionRate=?, BasePhysicalOffence=?, LastPhysicalOffence=?, BasePhysicalDefence=? WHERE CharID = ?";
	char* save_query3 = "UPDATE characters SET LastPhysicalDefence=?, BaseEnergyOffence=?, LastEnergyOffence=?, BaseEnergyDefence=?, LastEnergyDefence=?, BaseAttackRate=?, LastAttackRate=?,  BaseDodgeRate=?, LastDodgeRate=?, BaseBlockRate=?, BaseBlockRate=?, LastBlockRate=?, BaseCurseSuccessRate=?, LastCurseSuccessRate=?, BaseCurseToleranceRate=?, LastCurseToleranceRate=?, BasePhysicalCriticalRate=?, LastPhysicalCriticalRate=? WHERE CharID = ?";
	char* save_query4 = "UPDATE characters SET BaseEnergyCriticalRate=?, LastEnergyCriticalRate=?, LastRunSpeed=?, BaseAttackSpeedRate=?, BaseAttackRange=?, LastAttackRange=?, CastingTimeChangePercent=?, CoolTimeChangePercent=?, KeepTimeChangePercent=?, DotValueChangePercent=?, DotTimeChangeAbsolute=?, RequiredEpChangePercent=?, HonestOffence=?, HonestDefence=?, StrangeOffence=?, StrangeDefence=?, WildOffence=?, WildDefence=? WHERE CharID = ?";
	char* save_query5 = "UPDATE characters SET EleganceOffence=?, EleganceDefence=?, FunnyDefence=?, FunnyOffence=?, FunnyDefence=?, ParalyzeToleranceRate=?, TerrorToleranceRate=?, ConfuseToleranceRate=?, StoneToleranceRate=?, CandyToleranceRate=?, ParalyzeKeepTimeDown=?, TerrorKeepTimeDown=?, ConfuseKeepTimeDown=?, StoneKeepTimeDown=?, CandyKeepTimeDown=?, BleedingKeepTimeDown=?, PoisonKeepTimeDown=?, StomachacheKeepTimeDown=?, CriticalBlockSuccessRate=?  WHERE CharID = ?";
	char* save_query6 = "UPDATE characters SET GuardRate=?, SkillDamageBlockModeSuccessRate=?, CurseBlockModeSuccessRate=?, KnockdownBlockModeSuccessRate=?, HtbBlockModeSuccessRate=?, SitDownLpRegenBonusRate=?, SitDownEpRegenBonusRate=?, PhysicalCriticalDamageBonusRate=?, EnergyCriticalDamageBonusRate=?, ItemUpgradeBonusRate=?, ItemUpgradeBreakBonusRate=?, CurLP=?, CurEP=?, CurRP=? WHERE CharID = ?";

	this->db->prepare(save_query);
	this->db->setInt(1, this->vCurLoc.x);
	this->db->setInt(2, this->vCurLoc.y);
	this->db->setInt(3, this->vCurLoc.z);
	this->db->setInt(4, this->vCurDir.x);
	this->db->setInt(5, this->vCurDir.z);
	this->db->setInt(6, this->Level);
	this->db->setInt(7, this->CurEp);
	this->db->setInt(8, this->WorldTableID);
	this->db->setInt(9, this->WorldID);
	this->db->setInt(10, this->Money);
	this->db->setInt(11, this->Money);//bank
	this->db->setInt(12, this->Reputation);
	this->db->setInt(13, this->MudosaPoint);
	this->db->setInt(14, this->SpPoint);
	this->db->setInt(15, this->BaseStr);
	this->db->setInt(16, this->LastStr);
	this->db->setInt(17, this->BaseCon);
	this->db->setInt(18, this->LastCon);
	this->db->setInt(19, this->BaseFoc);
	this->db->setInt(20, this->LastFoc);
	this->db->setInt(21, this->BaseDex);
	this->db->setInt(22, this->LastDex);
	this->db->setInt(23, this->BaseSol);
	this->db->setInt(24, this->LastSol);
	this->db->setInt(25, this->BaseEng);
	this->db->setInt(26, this->LastEng);
	this->db->setInt(27, this->BaseMaxLp);
	this->db->setInt(28, this->LastMaxLp);
	this->db->setInt(29, this->BaseMaxRp);
	this->db->setInt(30, this->LastMaxRp);
	this->db->setInt(31, this->charID);
	this->db->execute();

	// 1 DONE
	this->db->prepare(save_query2);
	this->db->setInt(1, this->BaseLpRegen);
	this->db->setInt(2, this->LastLpRegen);
	this->db->setInt(3, this->BaseLpSitdownRegen);
	this->db->setInt(4, this->LastLpSitdownRegen);
	this->db->setInt(5, this->BaseLpBattleRegen);
	this->db->setInt(6, this->LastLpBattleRegen);
	this->db->setInt(7, this->BaseEpRegen);
	this->db->setInt(8, this->LastEpRegen);
	this->db->setInt(9, this->BaseEpSitdownRegen);
	this->db->setInt(10, this->LastEpSitdownRegen);
	this->db->setInt(11, this->BaseEpBattleRegen);
	this->db->setInt(12, this->LastEpBattleRegen);
	this->db->setInt(13, this->BaseRpRegen);
	this->db->setInt(14, this->LastRpRegen);
	this->db->setInt(15, this->LastRpDimimutionRate);
	this->db->setInt(16, this->BasePhysicalOffence);
	this->db->setInt(17, this->LastPhysicalOffence);
	this->db->setInt(18, this->BasePhysicalDefence);
	this->db->setInt(19, this->charID);
	this->db->execute();

	// 2 DONE
	this->db->prepare(save_query3);
	this->db->setInt(1, this->LastPhysicalDefence);
	this->db->setInt(2, this->BaseEnergyOffence);
	this->db->setInt(3, this->LastEnergyOffence);
	this->db->setInt(4, this->BaseEnergyDefence);
	this->db->setInt(5, this->LastEnergyDefence);
	this->db->setInt(6, this->BaseAttackRate);
	this->db->setInt(7, this->LastAttackRate);
	this->db->setInt(8, this->BaseDodgeRate);
	this->db->setInt(9, this->LastDodgeRate);
	this->db->setInt(10, this->BaseBlockRate);
	this->db->setInt(11, this->BaseBlockRate);
	this->db->setInt(12, this->LastBlockRate);
	this->db->setInt(13, this->BaseCurseSuccessRate);
	this->db->setInt(14, this->LastCurseSuccessRate);
	this->db->setInt(15, this->BaseCurseToleranceRate);
	this->db->setInt(16, this->LastCurseToleranceRate);
	this->db->setInt(17, this->BasePhysicalCriticalRate);
	this->db->setInt(18, this->LastPhysicalCriticalRate);
	this->db->setInt(19, this->charID);
	this->db->execute();

	//3 DONE
	this->db->prepare(save_query4);
	this->db->setInt(1, this->BaseEnergyCriticalRate);
	this->db->setInt(2, this->LastEnergyCriticalRate);
	this->db->setInt(3, this->LastRunSpeed);
	this->db->setInt(4, this->BaseAttackSpeedRate);
	this->db->setInt(5, this->BaseAttackRange);
	this->db->setInt(6, this->LastAttackRange);
	this->db->setInt(7, this->CastingTimeChangePercent);
	this->db->setInt(8, this->CoolTimeChangePercent);
	this->db->setInt(9, this->KeepTimeChangePercent);
	this->db->setInt(10, this->DotValueChangePercent);
	this->db->setInt(11, this->DotTimeChangeAbsolute);
	this->db->setInt(12, this->RequiredEpChangePercent);
	this->db->setInt(13, this->HonestOffence);
	this->db->setInt(14, this->HonestDefence);
	this->db->setInt(15, this->StrangeOffence);
	this->db->setInt(16, this->StrangeDefence);
	this->db->setInt(17, this->WildOffence);
	this->db->setInt(18, this->WildDefence);
	this->db->setInt(19, this->charID);
	this->db->execute();

	//4 DONE
	this->db->prepare(save_query5);
	this->db->setInt(1, this->EleganceOffence);
	this->db->setInt(2, this->EleganceDefence);
	this->db->setInt(3, this->FunnyDefence);
	this->db->setInt(4, this->FunnyOffence);
	this->db->setInt(5, this->FunnyDefence);
	this->db->setInt(6, this->ParalyzeToleranceRate);
	this->db->setInt(7, this->TerrorToleranceRate);
	this->db->setInt(8, this->ConfuseToleranceRate);
	this->db->setInt(9, this->StoneToleranceRate);
	this->db->setInt(10, this->CandyToleranceRate);
	this->db->setInt(11, this->ParalyzeKeepTimeDown);
	this->db->setInt(12, this->TerrorKeepTimeDown);
	this->db->setInt(13, this->ConfuseKeepTimeDown);
	this->db->setInt(14, this->StoneKeepTimeDown);
	this->db->setInt(15, this->CandyKeepTimeDown);
	this->db->setInt(16, this->BleedingKeepTimeDown);
	this->db->setInt(17, this->PoisonKeepTimeDown);
	this->db->setInt(18, this->StomachacheKeepTimeDown);
	this->db->setInt(19, this->CriticalBlockSuccessRate);
	this->db->setInt(20, this->charID);
	this->db->execute();

	//5 DONE
	this->db->prepare(save_query6);
	this->db->setInt(1, this->GuardRate);
	this->db->setInt(2, this->SkillDamageBlockModeSuccessRate);
	this->db->setInt(3, this->CurseBlockModeSuccessRate);
	this->db->setInt(4, this->KnockdownBlockModeSuccessRate);
	this->db->setInt(5, this->HtbBlockModeSuccessRate);
	this->db->setInt(6, this->SitDownLpRegenBonusRate);
	this->db->setInt(7, this->SitDownEpRegenBonusRate);
	this->db->setInt(8, this->PhysicalCriticalDamageBonusRate);
	this->db->setInt(9, this->EnergyCriticalDamageBonusRate);
	this->db->setInt(10, this->ItemUpgradeBonusRate);
	this->db->setInt(11, this->ItemUpgradeBreakBonusRate);
	this->db->setInt(12, this->CurLp);
	this->db->setInt(13, this->CurEp);
	this->db->setInt(14, this->CurRp);
	this->db->setInt(15, this->charID);
	this->db->execute();

	delete db;
}

void		PlayerInfos::SaveMe()
{
	this->SavePlayerData();
	//this->SaveItems();
	//this->SaveSkills();
}

void		PlayerInfos::setZero()
{
}

void		PlayerInfos::calculeMyStat(CGameServer * app)
{
	app->db->prepare("SELECT * FROM items WHERE owner_ID = ? AND place=7 ORDER BY pos ASC");
	app->db->setInt(1, this->GetCharID());
	app->db->execute();

	CItemTable *itemTbl = app->g_pTableContainer->GetItemTable();

	this->LastPhysicalOffence = this->BasePhysicalOffence;
	this->LastPhysicalDefence = this->BasePhysicalDefence;
	this->LastEnergyOffence = this->BaseEnergyOffence;
	this->LastEnergyDefence = this->BaseEnergyDefence;
	this->LastAttackSpeedRate = this->BaseAttackSpeedRate;
	this->LastAttackRange = 0;//this->BaseAttackRange;

	while (app->db->fetch())
	{
		sITEM_TBLDAT* pItemData = (sITEM_TBLDAT*) itemTbl->FindData(app->db->getInt("tblidx"));
		if (pItemData->wPhysical_Offence < 65535 && pItemData->wPhysical_Offence > 0)
			this->LastPhysicalOffence += pItemData->wPhysical_Offence;
		if (pItemData->wPhysical_Defence < 65535 && pItemData->wPhysical_Defence > 0)
			this->LastPhysicalDefence += pItemData->wPhysical_Defence;
		if (pItemData->wEnergy_Offence < 65535 && pItemData->wEnergy_Offence > 0)
			this->LastEnergyOffence += pItemData->wEnergy_Offence;
		if (pItemData->wEnergy_Defence < 65535 && pItemData->wEnergy_Defence > 0)
			this->LastEnergyDefence += pItemData->wEnergy_Defence;
		if (pItemData->wAttack_Speed_Rate < 65535 && pItemData->wAttack_Speed_Rate > 0)
			this->LastAttackSpeedRate += pItemData->wAttack_Speed_Rate;
		if (pItemData->fAttack_Range_Bonus < 65535 && pItemData->fAttack_Range_Bonus > 0)
			this->LastAttackRange += pItemData->fAttack_Range_Bonus;
		pItemData->dwPhysical_OffenceUpgrade;
		pItemData->dwPhysical_DefenceUpgrade;
		pItemData->dwEnergy_OffenceUpgrade;
		pItemData->dwEnergy_DefenceUpgrade;
		pItemData->byNeed_Str;
		pItemData->byNeed_Sol;
		pItemData->byNeed_Foc;
		pItemData->byNeed_Eng;
		pItemData->byNeed_Con;
		pItemData->byNeed_Dex;
		pItemData->byBattle_Attribute;
		/*printf("Item: %d have attribute:\n", app->db->getInt("tblidx"));
		printf("%d, %d, %d, %d, %d, %d %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n",pItemData->wPhysical_Offence ,pItemData->wPhysical_Defence ,pItemData->wEnergy_Offence ,pItemData->wEnergy_Defence ,pItemData->wAttack_Speed_Rate,
			pItemData->fAttack_Range_Bonus,pItemData->dwPhysical_OffenceUpgrade ,pItemData->dwPhysical_DefenceUpgrade ,pItemData->dwEnergy_OffenceUpgrade ,pItemData->dwEnergy_DefenceUpgrade ,pItemData->byNeed_Str,
			pItemData->byNeed_Sol,pItemData->byNeed_Foc ,pItemData->byNeed_Eng ,pItemData->byNeed_Con ,pItemData->byNeed_Dex,pItemData->byBattle_Attribute );*/
		printf("%d, %d, %d, %d, %d, %d\n",this->LastPhysicalOffence ,this->LastPhysicalDefence ,this->LastEnergyOffence ,this->LastEnergyDefence ,this->LastAttackSpeedRate ,this->LastAttackRange );
	}
}