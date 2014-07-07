#include "stdafx.h"
//#include <boost/thread.hpp>
//#include <boost/date_time.hpp>
#include "Vector.h"
#include <list>

class CClientSession;

class PlayerInfos
{
public:
	PlayerInfos(){};
	~PlayerInfos(){};
	void		ClearTheList();
	sVECTOR3	GetPosition();
	sVECTOR3	GetDirection();
	void		SetPosition(sVECTOR3 curPos, sVECTOR3 curDir);
	int			GetCharID();
	int			GetAccountID();
	void		SetcharID(int id);
	void		SetAccountID(int id);
	std::string		GetName();
	void		SetName(std::string name);
	void		SetWorldID(int id);
	int			GetWorldID();
	void		SetWorldTableID(int id);
	int			GetWorldTableID();
	void			SetLevel(BYTE id);
	BYTE			GetLevel();
	void		SetCurExp(int id);
	int			GetCurExp();
	void			SetMoney(DWORD id);
	DWORD			GetMoney();
	std::string		GetGuildName();
	void		SetGuildName(std::string name);
	void		SetBaseMaxLp(int id);
	int			GetBaseMaxLp();
	void		SetLastMaxLp(int id);
	int			GetLastMaxLp();
	void		SetCurLp(int id);
	int			GetCurLp();
	void		SetBaseMaxEp(int id);
	int			GetBaseMaxEp();
	void		SetLastMaxEp(int id);
	int			GetLastMaxEp();
	void		SetCurEp(int id);
	int			GetCurEp();
	void		SetBaseMaxRp(int id);
	int			GetBaseMaxRp();
	void		SetLastMaxRp(int id);
	int			GetLastMaxRp();
	void		SetCurRp(int id);
	int			GetCurRp();
	void		SetReputation(int id);
	int			GetReputation();
	void		SetMudosaPoint(int id);
	int			GetMudosaPoint();
	void		SetSpPoint(int id);
	int			GetSpPoint();
	void		SetBaseStr(int id);
	int			GetBaseStr();
	void		SetLastStr(int id);
	int			GetLastStr();
	void		SetBaseCon(int id);
	int			GetBaseCon();
	void		SetLastCon(int id);
	int			GetLastCon();
	void		SetBaseFoc(int id);
	int			GetBaseFoc();
	void		SetLastFoc(int id);
	int			GetLastFoc();
	void		SetBaseDex(int id);
	int			GetBaseDex();
	void		SetLastDex(int id);
	int			GetLastDex();
	void		SetBaseSol(int id);
	int			GetBaseSol();
	void		SetLastSol(int id);
	int			GetLastSol();
	void		SetBaseEng(int id);
	int			GetBaseEng();
	void		SetLastEng(int id);
	int			GetLastEng();

	void		Setmob_SpawnTime(RwUInt32 id);
	RwUInt32	Getmob_SpawnTime();

	void		Setlast_SpawnPos(sVECTOR3 id);
	sVECTOR3	Getlast_SpawnPos();


public:

private:
	std::string			Myname;
	sVECTOR3			vCurLoc;
	sVECTOR3			vCurDir;
	int					charID;
	int					AccountID;
	int					WorldID;
	int					WorldTableID;
	BYTE				Level;
	int					CurExp;
	DWORD					Money;
	std::string			GuildName;
	int					BaseMaxLp;
	int					LastMaxLp;
	int					CurLp;
	int					BaseMaxEp;
	int					LastMaxEp;
	int					CurEp;
	int					BaseMaxRp;
	int					LastMaxRp;
	int					CurRp;
	int					Reputation;
	int					MudosaPoint;
	int					SpPoint;
	int					BaseStr;
	int					LastStr;
	int					BaseCon;
	int					LastCon;
	int					BaseFoc;
	int					LastFoc;
	int					BaseDex;
	int					LastDex;
	int					BaseSol;
	int					LastSol;
	int					BaseEng;
	int					LastEng;

	RwUInt32			mob_SpawnTime;
	sVECTOR3			last_SpawnPos;

private:
	MySQLConnWrapper			*db;
	/*std::string			Myname;
	sVECTOR3			vCurLoc;
	sVECTOR3			vCurDir;
	int					charID;
	int					WorldID;
	int					WorldTableID;
	int					CurExp;
	std::string			GuildName;
	int					BaseMaxLp;
	int					LastMaxLp;
	int					CurLp;
	int					BaseMaxEp;
	int					LastMaxEp;
	int					CurEp;
	int					BaseMaxRp;
	int					LastMaxRp;
	int					CurRp;
	int					Reputation;
	int					MudosaPoint;
	int					SpPoint;
	int					BaseStr;
	int					LastStr;
	int					BaseCon;
	int					LastCon;
	int					BaseFoc;
	int					LastFoc;
	int					BaseDex;
	int					LastDex;
	int					BaseSol;
	int					LastSol;
	int					BaseEng;
	int					LastEng;

	RwUInt32			mob_SpawnTime;
	sVECTOR3			last_SpawnPos;*/
public:

void		SaveMe();
void		SavePlayerData();

	int			GetBasePhysicalOffence(){return this->BasePhysicalOffence;};
	int			GetLastPhysicalOffence(){return this->LastPhysicalOffence;};
	int			GetBasePhysicalDefence(){return this->BasePhysicalDefence;};
	int			GetLastPhysicalDefence(){return this->LastPhysicalDefence;};
	int			GetBaseEnergyOffence(){return this->BaseEnergyOffence;};
	int			GetLastEnergyOffence(){return this->LastEnergyOffence;};
	int			GetBaseEnergyDefence(){return this->BaseEnergyDefence;};
	int			GetLastEnergyDefence(){return this->LastEnergyDefence;};
	int			GetBaseAttackRate(){return this->BaseAttackRate;};
	int			GetLastAttackRate(){return this->LastAttackRate;};
	int			GetBaseDodgeRate(){return this->BaseDodgeRate;};
	int			GetGetLastDodgeRate(){return this->LastDodgeRate;};
	int			GetBaseBlockRate(){return this->BaseBlockRate;};
	int			GetLastBlockRate(){return this->LastBlockRate;};
	int			GetLastPhysicalCriticalRate(){return this->LastPhysicalCriticalRate;};
	int			GetLastEnergyCriticalRate(){return this->LastEnergyCriticalRate;};
	int			GetLastRunSpeed(){return this->LastRunSpeed;};

	void		SetBasePhysicalOffence(int id){this->BasePhysicalOffence = id;};
	void		SetLastPhysicalOffence(int id){this->LastPhysicalOffence = id;};
	void		SetBasePhysicalDefence(int id){this->BasePhysicalDefence = id;};
	void		SetLastPhysicalDefence(int id){this->LastPhysicalDefence = id;};
	void		SetBaseEnergyOffence(int id){this->BaseEnergyOffence = id;};
	void		SetLastEnergyOffence(int id){this->LastEnergyOffence = id;};
	void		SetBaseEnergyDefence(int id){this->BaseEnergyDefence = id;};
	void		SetLastEnergyDefence(int id){this->LastEnergyDefence = id;};
	void		SetBaseAttackRate(int id){this->BaseAttackRate = id;};
	void		SetLastAttackRate(int id){this->LastAttackRate = id;};
	void		SetBaseDodgeRate(int id){this->BaseDodgeRate = id;};
	void		SetLastDodgeRate(int id){this->LastDodgeRate = id;};
	void		SetBaseBlockRate(int id){this->BaseBlockRate = id;};
	void		SetLastBlockRate(int id){this->LastBlockRate = id;};
	void		SetLastPhysicalCriticalRate(int id){this->LastPhysicalCriticalRate = id;};
	void		SetLastEnergyCriticalRate(int id){this->LastEnergyCriticalRate = id;};
	void		SetLastRunSpeed(int id){this->LastRunSpeed = id;};

private:	
	int					BasePhysicalOffence;
	int					LastPhysicalOffence;
	int					BasePhysicalDefence;
	int					LastPhysicalDefence;
	int					BaseEnergyOffence;
	int					LastEnergyOffence;
	int					BaseEnergyDefence;
	int					LastEnergyDefence;
	int					BaseAttackRate;
	int					LastAttackRate;
	int					BaseDodgeRate;
	int					LastDodgeRate;
	int					BaseBlockRate;
	int					LastBlockRate;
	int					LastPhysicalCriticalRate;
	int					LastEnergyCriticalRate;
	int					LastRunSpeed;
};
