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
	this->db->setInt(6, this->pcProfile->byLevel);
	this->db->setInt(7, this->pcProfile->dwCurExp);
	this->db->setInt(8, this->WorldTableID);
	this->db->setInt(9, this->WorldID);
	this->db->setInt(10, this->pcProfile->dwZenny);
	this->db->setInt(11, this->pcProfile->dwZenny);//bank
	this->db->setInt(12, this->pcProfile->dwReputation);
	this->db->setInt(13, this->pcProfile->dwMudosaPoint);
	this->db->setInt(14, this->pcProfile->dwSpPoint);
	this->db->setInt(15, this->pcProfile->avatarAttribute.byBaseStr);
	this->db->setInt(16, this->pcProfile->avatarAttribute.byLastStr);
	this->db->setInt(17, this->pcProfile->avatarAttribute.byBaseCon);
	this->db->setInt(18, this->pcProfile->avatarAttribute.byLastCon);
	this->db->setInt(19, this->pcProfile->avatarAttribute.byBaseFoc);
	this->db->setInt(20, this->pcProfile->avatarAttribute.byLastFoc);
	this->db->setInt(21, this->pcProfile->avatarAttribute.byBaseDex);
	this->db->setInt(22, this->pcProfile->avatarAttribute.byLastDex);
	this->db->setInt(23, this->pcProfile->avatarAttribute.byBaseSol);
	this->db->setInt(24, this->pcProfile->avatarAttribute.byLastSol);
	this->db->setInt(25, this->pcProfile->avatarAttribute.byBaseEng);
	this->db->setInt(26, this->pcProfile->avatarAttribute.byLastEng);
	this->db->setInt(27, this->pcProfile->avatarAttribute.wBaseMaxLP);
	this->db->setInt(28, this->pcProfile->avatarAttribute.wLastMaxLP);
	this->db->setInt(29, this->pcProfile->avatarAttribute.wBaseMaxRP);
	this->db->setInt(30, this->pcProfile->avatarAttribute.wLastMaxRP);
	this->db->setInt(31, this->pcProfile->charId);
	this->db->execute();

	// 1 DONE
	this->db->prepare(save_query2);
	this->db->setInt(1, this->pcProfile->avatarAttribute.wBaseLpRegen);
	this->db->setInt(2, this->pcProfile->avatarAttribute.wLastLpRegen);
	this->db->setInt(3, this->pcProfile->avatarAttribute.wBaseLpSitdownRegen);
	this->db->setInt(4, this->pcProfile->avatarAttribute.wLastLpSitdownRegen);
	this->db->setInt(5, this->pcProfile->avatarAttribute.wBaseLpBattleRegen);
	this->db->setInt(6, this->pcProfile->avatarAttribute.wLastLpBattleRegen);
	this->db->setInt(7, this->pcProfile->avatarAttribute.wBaseEpRegen);
	this->db->setInt(8, this->pcProfile->avatarAttribute.wLastEpRegen);
	this->db->setInt(9, this->pcProfile->avatarAttribute.wBaseEpSitdownRegen);
	this->db->setInt(10, this->pcProfile->avatarAttribute.wLastEpSitdownRegen);
	this->db->setInt(11, this->pcProfile->avatarAttribute.wBaseEpBattleRegen);
	this->db->setInt(12, this->pcProfile->avatarAttribute.wLastEpBattleRegen);
	this->db->setInt(13, this->pcProfile->avatarAttribute.wBaseRpRegen);
	this->db->setInt(14, this->pcProfile->avatarAttribute.wLastRpRegen);
	this->db->setInt(15, this->pcProfile->avatarAttribute.wLastRpDimimutionRate);
	this->db->setInt(16, this->pcProfile->avatarAttribute.wBasePhysicalOffence);
	this->db->setInt(17, this->pcProfile->avatarAttribute.wLastPhysicalOffence);
	this->db->setInt(18, this->pcProfile->avatarAttribute.wBasePhysicalDefence);
	this->db->setInt(19, this->pcProfile->charId);
	this->db->execute();

	// 2 DONE
	this->db->prepare(save_query3);
	this->db->setInt(1, this->pcProfile->avatarAttribute.wLastPhysicalDefence);
	this->db->setInt(2, this->pcProfile->avatarAttribute.wBaseEnergyOffence);
	this->db->setInt(3, this->pcProfile->avatarAttribute.wLastEnergyOffence);
	this->db->setInt(4, this->pcProfile->avatarAttribute.wBaseEnergyDefence);
	this->db->setInt(5, this->pcProfile->avatarAttribute.wLastEnergyDefence);
	this->db->setInt(6, this->pcProfile->avatarAttribute.wBaseAttackRate);
	this->db->setInt(7, this->pcProfile->avatarAttribute.wLastAttackRate);
	this->db->setInt(8, this->pcProfile->avatarAttribute.wBaseDodgeRate);
	this->db->setInt(9, this->pcProfile->avatarAttribute.wLastDodgeRate);
	this->db->setInt(10, this->pcProfile->avatarAttribute.wBaseBlockRate);
	this->db->setInt(11, this->pcProfile->avatarAttribute.wBaseBlockRate);
	this->db->setInt(12, this->pcProfile->avatarAttribute.wLastBlockRate);
	this->db->setInt(13, this->pcProfile->avatarAttribute.wBaseCurseSuccessRate);
	this->db->setInt(14, this->pcProfile->avatarAttribute.wLastCurseSuccessRate);
	this->db->setInt(15, this->pcProfile->avatarAttribute.wBaseCurseToleranceRate);
	this->db->setInt(16, this->pcProfile->avatarAttribute.wLastCurseToleranceRate);
	this->db->setInt(17, this->pcProfile->avatarAttribute.wBasePhysicalCriticalRate);
	this->db->setInt(18, this->pcProfile->avatarAttribute.wLastPhysicalCriticalRate);
	this->db->setInt(19, this->pcProfile->charId);
	this->db->execute();

	//3 DONE
	this->db->prepare(save_query4);
	this->db->setInt(1, this->pcProfile->avatarAttribute.wBaseEnergyCriticalRate);
	this->db->setInt(2, this->pcProfile->avatarAttribute.wLastEnergyCriticalRate);
	this->db->setInt(3, this->pcProfile->avatarAttribute.fLastRunSpeed);
	this->db->setInt(4, this->pcProfile->avatarAttribute.wBaseAttackSpeedRate);
	this->db->setInt(5, this->pcProfile->avatarAttribute.fBaseAttackRange);
	this->db->setInt(6, this->pcProfile->avatarAttribute.fLastAttackRange);
	this->db->setInt(7, this->pcProfile->avatarAttribute.fCastingTimeChangePercent);
	this->db->setInt(8, this->pcProfile->avatarAttribute.fCoolTimeChangePercent);
	this->db->setInt(9, this->pcProfile->avatarAttribute.fKeepTimeChangePercent);
	this->db->setInt(10, this->pcProfile->avatarAttribute.fDotValueChangePercent);
	this->db->setInt(11, this->pcProfile->avatarAttribute.fDotTimeChangeAbsolute);
	this->db->setInt(12, this->pcProfile->avatarAttribute.fRequiredEpChangePercent);
	this->db->setInt(13, this->pcProfile->avatarAttribute.fHonestOffence);
	this->db->setInt(14, this->pcProfile->avatarAttribute.fHonestDefence);
	this->db->setInt(15, this->pcProfile->avatarAttribute.fStrangeOffence);
	this->db->setInt(16, this->pcProfile->avatarAttribute.fStrangeDefence);
	this->db->setInt(17, this->pcProfile->avatarAttribute.fWildOffence);
	this->db->setInt(18, this->pcProfile->avatarAttribute.fWildDefence);
	this->db->setInt(19, this->pcProfile->charId);
	this->db->execute();

	//4 DONE
	this->db->prepare(save_query5);
	this->db->setInt(1, this->pcProfile->avatarAttribute.fEleganceOffence);
	this->db->setInt(2, this->pcProfile->avatarAttribute.fEleganceDefence);
	this->db->setInt(3, this->pcProfile->avatarAttribute.fFunnyDefence);
	this->db->setInt(4, this->pcProfile->avatarAttribute.fFunnyOffence);
	this->db->setInt(5, this->pcProfile->avatarAttribute.fFunnyDefence);
	this->db->setInt(6, this->pcProfile->avatarAttribute.wParalyzeToleranceRate);
	this->db->setInt(7, this->pcProfile->avatarAttribute.wTerrorToleranceRate);
	this->db->setInt(8, this->pcProfile->avatarAttribute.wConfuseToleranceRate);
	this->db->setInt(9, this->pcProfile->avatarAttribute.wStoneToleranceRate);
	this->db->setInt(10, this->pcProfile->avatarAttribute.wCandyToleranceRate);
	this->db->setInt(11, this->pcProfile->avatarAttribute.fParalyzeKeepTimeDown);
	this->db->setInt(12, this->pcProfile->avatarAttribute.fTerrorKeepTimeDown);
	this->db->setInt(13, this->pcProfile->avatarAttribute.fConfuseKeepTimeDown);
	this->db->setInt(14, this->pcProfile->avatarAttribute.fStoneKeepTimeDown);
	this->db->setInt(15, this->pcProfile->avatarAttribute.fCandyKeepTimeDown);
	this->db->setInt(16, this->pcProfile->avatarAttribute.fBleedingKeepTimeDown);
	this->db->setInt(17, this->pcProfile->avatarAttribute.fPoisonKeepTimeDown);
	this->db->setInt(18, this->pcProfile->avatarAttribute.fStomachacheKeepTimeDown);
	this->db->setInt(19, this->pcProfile->avatarAttribute.fCriticalBlockSuccessRate);
	this->db->setInt(20, this->pcProfile->charId);
	this->db->execute();

	//5 DONE
	this->db->prepare(save_query6);
	this->db->setInt(1, this->pcProfile->avatarAttribute.wGuardRate);
	this->db->setInt(2, this->pcProfile->avatarAttribute.fSkillDamageBlockModeSuccessRate);
	this->db->setInt(3, this->pcProfile->avatarAttribute.fCurseBlockModeSuccessRate);
	this->db->setInt(4, this->pcProfile->avatarAttribute.fKnockdownBlockModeSuccessRate);
	this->db->setInt(5, this->pcProfile->avatarAttribute.fHtbBlockModeSuccessRate);
	this->db->setInt(6, this->pcProfile->avatarAttribute.fSitDownLpRegenBonusRate);
	this->db->setInt(7, this->pcProfile->avatarAttribute.fSitDownEpRegenBonusRate);
	this->db->setInt(8, this->pcProfile->avatarAttribute.fPhysicalCriticalDamageBonusRate);
	this->db->setInt(9, this->pcProfile->avatarAttribute.fEnergyCriticalDamageBonusRate);
	this->db->setInt(10, this->pcProfile->avatarAttribute.fItemUpgradeBonusRate);
	this->db->setInt(11, this->pcProfile->avatarAttribute.fItemUpgradeBreakBonusRate);
	this->db->setInt(12, this->pcProfile->wCurLP);
	this->db->setInt(13, this->pcProfile->wCurEP);
	this->db->setInt(14, this->pcProfile->wCurRP);
	this->db->setInt(15, this->pcProfile->charId);
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
	app->db->setInt(1, this->pcProfile->charId);
	app->db->execute();

	CItemTable *itemTbl = app->g_pTableContainer->GetItemTable();

	while (app->db->fetch())
	{
		sITEM_TBLDAT* pItemData = (sITEM_TBLDAT*) itemTbl->FindData(app->db->getInt("tblidx"));
		/*if (pItemData->wPhysical_Offence < 65535 && pItemData->wPhysical_Offence > 0)
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
			this->LastAttackRange += pItemData->fAttack_Range_Bonus;*/
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
		//printf("%d, %d, %d, %d, %d, %d\n",this->LastPhysicalOffence ,this->LastPhysicalDefence ,this->LastEnergyOffence ,this->LastEnergyDefence ,this->LastAttackSpeedRate ,this->LastAttackRange );
	}
}