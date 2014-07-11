#include "stdafx.h"
//#include <boost/thread.hpp>
//#include <boost/date_time.hpp>
#include "Vector.h"
#include <list>
#include "Avatar.h"
#include "Character.h"

class CClientSession;

class PlayerInfos
{
public:
	PlayerInfos()
	{
		this->pcProfile = new sPC_PROFILE;
		this->sCharState = new sCHARSTATE;
	};
	~PlayerInfos(){};
	sPC_PROFILE		*pcProfile;
	sCHARSTATE		*sCharState;
	HSESSION		MySession;
	void		setPlayerStat(sPC_PROFILE* pc, sCHARSTATE *sCharSt)
	{	
		memcpy(this->pcProfile, pc, sizeof(sPC_PROFILE));
		memcpy(this->sCharState, sCharSt, sizeof(sCHARSTATE));
	};
	void		StoreSession(HSESSION ss){this->MySession = ss;};
	void		ClearTheList();
	sVECTOR3	GetPosition();
	sVECTOR3	GetDirection();
	void		SetPosition(sVECTOR3 curPos, sVECTOR3 curDir);
	int			GetAccountID(){return this->AccountID;};
	void		SetAccountID(int id){this->AccountID = id;};
	void		SetGuildName(std::string name){this->guildname = name;};
	std::string		GetGuildName(){return this->guildname;};
	void		SetPlayerName(std::string name){this->username = name;};
	std::string		GetPlayerName(){return this->username;};
	void		SetWorldID(int id);
	int			GetWorldID();
	void		SetWorldTableID(int id);
	int			GetWorldTableID();
	void		Setmob_SpawnTime(RwUInt32 id);
	RwUInt32	Getmob_SpawnTime();

	void		Setlast_SpawnPos(sVECTOR3 id);
	sVECTOR3	Getlast_SpawnPos();
	// PLAYER STAT CALCULE
	void		calculeMyStat(CGameServer * app);
	void		setZero();
	void		StoreHandle(RwUInt32 _avatarHandle){this->avatarHandle = _avatarHandle;};
private:
	MySQLConnWrapper			*db;
public:

void		SaveMe();
void		SavePlayerData();
private:
	sVECTOR3			vCurLoc;
	sVECTOR3			vCurDir;
	int					AccountID;
	int					WorldID;
	int					WorldTableID;
	std::string			guildname;
	std::string			username;
	RwUInt32			mob_SpawnTime;
	sVECTOR3			last_SpawnPos;
	RwUInt32			avatarHandle;
};