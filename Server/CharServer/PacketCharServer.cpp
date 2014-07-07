#include "stdafx.h"
#include "NtlSfx.h"
#include "NtlPacketUC.h"
#include "NtlPacketCU.h"
#include "ResultCode.h"

#include "CharServer.h"

//--------------------------------------------------------------------------------------//
//		Log into Character Server
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharServerReq(CNtlPacket * pPacket)
{
	NTL_PRINT(PRINT_APP, "-- - LOGIN CHAR SERVER REQUEST-- - ");
	sUC_LOGIN_REQ * req = (sUC_LOGIN_REQ *)pPacket->GetPacketData();
			
	printf("--- LOGIN CHAR SERVER REQUEST --- \n");
	printf("ACC ID: %i Server: %i auth key: %s \n", req->accountId, req->serverID, req->abyAuthKey);

	this->accountID = req->accountId;

	CNtlPacket packet(sizeof(sCU_LOGIN_RES));
	sCU_LOGIN_RES * res = (sCU_LOGIN_RES *)packet.GetPacketData();

	res->wOpCode = CU_LOGIN_RES;
	res->wResultCode = CHARACTER_SUCCESS;
	//	res->lastServerFarmId = 0;
	//	res->RaceAllowedFlag = 1;

	packet.SetPacketLen(sizeof(sCU_LOGIN_RES));
	int rc = g_pApp->Send(this->GetHandle(), &packet);
		if (NTL_SUCCESS != rc)
		{
			NTL_PRINT(PRINT_APP, "Failed to send packet %d(%s)", rc, NtlGetErrorMessage(rc));
		}
		else{
			CNtlString ipadress;
			WORD pooort;
			this->GetAddressInfo(&ipadress, &pooort, true);
			NTL_PRINT(PRINT_APP, "User %s logedin", ipadress.c_str());
		}
}

//--------------------------------------------------------------------------------------//
//		Load Server Informations
//--------------------------------------------------------------------------------------//
void CClientSession::SendServerListOneReq(CNtlPacket * pPacket)
{
// Load farm info
	printf("--- LOAD SERVER FARM INFO --- \n");
	CNtlPacket packet(sizeof(sCU_SERVER_FARM_INFO));
	sCU_SERVER_FARM_INFO * res = (sCU_SERVER_FARM_INFO *)packet.GetPacketData();

	res->wOpCode = CU_SERVER_FARM_INFO;
	res->serverFarmInfo.serverFarmId = 0;
	wcscpy_s((wchar_t*)res->serverFarmInfo.wszGameServerFarmName, NTL_MAX_SIZE_SERVER_FARM_NAME_UNICODE, L"Test");
	res->serverFarmInfo.byServerStatus = DBO_SERVER_STATUS_UP;
	res->serverFarmInfo.dwLoad = 10;
	res->serverFarmInfo.dwMaxLoad = 100;


	packet.SetPacketLen(sizeof(sCU_SERVER_FARM_INFO));
	int rc = g_pApp->Send(this->GetHandle(), &packet);


// Load Server list
	printf("--- LOAD SERVER LIST ONE --- \n");
	CNtlPacket packet2(sizeof(sCU_CHARACTER_SERVERLIST_ONE_RES));
	sCU_CHARACTER_SERVERLIST_ONE_RES * res2 = (sCU_CHARACTER_SERVERLIST_ONE_RES *)packet2.GetPacketData();

	res2->wOpCode = CU_CHARACTER_SERVERLIST_ONE_RES;
	res2->wResultCode = CHARACTER_SUCCESS;

	packet2.SetPacketLen(sizeof(sCU_CHARACTER_SERVERLIST_ONE_RES));
	rc = g_pApp->Send(this->GetHandle(), &packet2);


// Load Channel
	printf("--- LOAD SERVER CHANNEL --- \n");
	CNtlPacket packet3(sizeof(sCU_SERVER_CHANNEL_INFO));
	sCU_SERVER_CHANNEL_INFO * res3 = (sCU_SERVER_CHANNEL_INFO *)packet3.GetPacketData();

	res3->wOpCode = CU_SERVER_CHANNEL_INFO;
	res3->byCount = 1;
	res3->serverChannelInfo[0].serverFarmId = 0;
	res3->serverChannelInfo[0].byServerChannelIndex = 0;
	res3->serverChannelInfo[0].dwLoad = 10;
	res3->serverChannelInfo[0].bIsVisible = true;
	res3->serverChannelInfo[0].dwMaxLoad = 100;
	res3->serverChannelInfo[0].byServerStatus = DBO_SERVER_STATUS_UP;

	packet3.SetPacketLen(sizeof(sCU_SERVER_CHANNEL_INFO));
	rc = g_pApp->Send(this->GetHandle(), &packet3);
}

//--------------------------------------------------------------------------------------//
//		Load Characters
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharLoadReq(CNtlPacket * pPacket, CCharServer * app)
{
	sUC_CHARACTER_LOAD_REQ * req = (sUC_CHARACTER_LOAD_REQ*)pPacket->GetPacketData();
	printf("--- LOAD CHARACTERS  ACC ID: %i Farm ID: %i --- \n", req->accountId, req->serverFarmId);

	app->db->prepare("SELECT * FROM characters WHERE AccountID = ?");
	app->db->setInt(1, req->accountId);
	app->db->execute();

	cout << " TOTAL CHARACTERS: " << app->db->rowsCount() << endl;

// character info
	CNtlPacket packet(sizeof(sCU_CHARACTER_INFO));
	sCU_CHARACTER_INFO * res = (sCU_CHARACTER_INFO *)packet.GetPacketData();

	res->wOpCode = CU_CHARACTER_INFO;
	res->byCount = (int)app->db->rowsCount();


	for ( int i = 0; i < (int)app->db->rowsCount(); i++ ) {
	app->db->fetch();

		memcpy(res->sPcData[i].awchName, s2ws(app->db->getString("CharName")).c_str(), sizeof(wchar_t)* NTL_MAX_SIZE_CHAR_NAME_UNICODE);
		res->sPcData[i].charId = app->db->getInt("CharID");
		res->sPcData[i].byRace = app->db->getInt("Race");
		res->sPcData[i].byClass = app->db->getInt("Class");
		res->sPcData[i].bIsAdult = app->db->getBoolean("Adult");
		res->sPcData[i].byGender = app->db->getInt("Gender");
		res->sPcData[i].byFace = app->db->getInt("Face");
		res->sPcData[i].byHair = app->db->getInt("Hair");
		res->sPcData[i].byHairColor = app->db->getInt("HairColor");
		res->sPcData[i].bySkinColor = app->db->getInt("SkinColor");
		res->sPcData[i].byLevel = app->db->getInt("Level");
		res->sPcData[i].bTutorialFlag = app->db->getBoolean("TutorialFlag");
		res->sPcData[i].bNeedNameChange = app->db->getBoolean("NameChange");
		for(int j = 0; j < NTL_MAX_EQUIP_ITEM_SLOT; j++)
		{
			//Get items which the characters is wearing
			app->db2->prepare("select * from items WHERE place=7 AND pos=? AND owner_id=?");
			app->db2->setInt(1, j);
			app->db2->setInt(2, app->db->getInt("CharID"));
			app->db2->execute();
			app->db2->fetch();
			if(app->db2->rowsCount() == 0)
			{
				res->sPcData[i].sItem[j].tblidx =  INVALID_TBLIDX;
			}
			else
			{
				res->sPcData[i].sItem[j].tblidx = app->db2->getInt("tblidx");
			}

		}
	}

	packet.SetPacketLen( sizeof(sCU_CHARACTER_INFO) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );


// load characters
	CNtlPacket packet2(sizeof(sCU_CHARACTER_LOAD_RES));
	sCU_CHARACTER_LOAD_RES * res2 = (sCU_CHARACTER_LOAD_RES *)packet2.GetPacketData();

	res2->wOpCode = CU_CHARACTER_LOAD_RES;
	res2->wResultCode = CHARACTER_SUCCESS;

	packet2.SetPacketLen( sizeof(sCU_CHARACTER_LOAD_RES) );
	rc = g_pApp->Send( this->GetHandle(), &packet2 );
}

//--------------------------------------------------------------------------------------//
//		Create Character
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharCreateReq(CNtlPacket * pPacket, CCharServer * app)
{
	sUC_CHARACTER_ADD_REQ * req = (sUC_CHARACTER_ADD_REQ*)pPacket->GetPacketData();
	printf("--- CHARACTER ADD REQUEST --- \n");

	app->db->prepare("CALL CharCreate (?,?,?,?,?,?,?,?,?, @charId, @wResultCode)");

	app->db->setString(1, Ntl_WC2MB(req->awchCharName));
	app->db->setInt(2, req->byRace);
	app->db->setInt(3, req->byClass);
	app->db->setInt(4, req->byGender);
	app->db->setInt(5, req->byFace);
	app->db->setInt(6, req->byHair);
	app->db->setInt(7, req->byHairColor);
	app->db->setInt(8, req->bySkinColor);
	app->db->setInt(9, this->accountID);

	app->db->execute();
	app->db->execute("SELECT @charId, @wResultCode");
	app->db->fetch(); 

	cout << "CHAR ID: " << app->db->print("@charId")
	<< " RESULT CODE: " << app->db->print("@wResultCode")
	<< endl;

	CNtlPacket packet(sizeof(sCU_CHARACTER_ADD_RES));
	sCU_CHARACTER_ADD_RES * res = (sCU_CHARACTER_ADD_RES *)packet.GetPacketData();

	res->wOpCode = CU_CHARACTER_ADD_RES;
	res->wResultCode = app->db->getInt("@wResultCode");

	if (res->wResultCode != 200) {

		packet.SetPacketLen( sizeof(sCU_CHARACTER_ADD_RES) );
		int rc = g_pApp->Send( this->GetHandle(), &packet );
		cout << " RESULT CODE: " << res->wResultCode << endl;

	}else{

	res->sPcDataSummary.charId = app->db->getInt("@charId");
	memcpy(res->sPcDataSummary.awchName, req->awchCharName, sizeof(wchar_t)* NTL_MAX_SIZE_CHAR_NAME_UNICODE);
	res->sPcDataSummary.byRace = req->byRace;
	res->sPcDataSummary.byClass = req->byClass;
	res->sPcDataSummary.bIsAdult = false;
	res->sPcDataSummary.byGender = req->byGender;
	res->sPcDataSummary.byFace = req->byFace;
	res->sPcDataSummary.byHair = req->byHair;
	res->sPcDataSummary.byHairColor = req->byHairColor;
	res->sPcDataSummary.bySkinColor = req->bySkinColor;
	res->sPcDataSummary.byLevel = 1;
	res->sPcDataSummary.worldId = 1;

	packet.SetPacketLen( sizeof(sCU_CHARACTER_ADD_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );

	}
}

//--------------------------------------------------------------------------------------//
//		Exit Character selection
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharExitReq(CNtlPacket * pPacket)
{
	CNtlPacket packet(sizeof(sCU_CHARACTER_EXIT_RES));
	sCU_CHARACTER_EXIT_RES * sPacket= (sCU_CHARACTER_EXIT_RES *)packet.GetPacketData();
	sPacket->wOpCode = CU_CHARACTER_EXIT_RES;
	sPacket->wResultCode = GAME_SUCCESS;
	packet.SetPacketLen( sizeof(sCU_CHARACTER_EXIT_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );
	this->Disconnect(true);
}

//--------------------------------------------------------------------------------------//
//		Delete Character
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharDeleteReq(CNtlPacket * pPacket, CCharServer * app)
{
	sUC_CHARACTER_DEL_REQ * req = (sUC_CHARACTER_DEL_REQ*)pPacket->GetPacketData();

	printf("--- CHARACTER DEL REQUEST --- \n");
	CNtlPacket packet(sizeof(sCU_CHARACTER_DEL_RES));
	sCU_CHARACTER_DEL_RES * res = (sCU_CHARACTER_DEL_RES *)packet.GetPacketData();

	res->wOpCode = CU_CHARACTER_DEL_RES;
	res->charId = req->charId;
	res->wResultCode = CHARACTER_SUCCESS;

	app->db->prepare("DELETE FROM account WHERE CharID = ?");
	app->db->setInt(1, req->charId);
	app->db->execute();

	packet.SetPacketLen( sizeof(sCU_CHARACTER_DEL_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );
}

//--------------------------------------------------------------------------------------//
//		Character Rename
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharRenameReq(CNtlPacket * pPacket, CCharServer * app)
{
	sUC_CHARACTER_RENAME_REQ * req = (sUC_CHARACTER_RENAME_REQ*)pPacket->GetPacketData();
	printf("--- CHARACTER RENAME REQUEST --- \n");

	CNtlPacket packet(sizeof(sCU_CHARACTER_RENAME_RES));
	sCU_CHARACTER_RENAME_RES * res = (sCU_CHARACTER_RENAME_RES *)packet.GetPacketData();

	app->db->prepare("CALL ChangeCharname (?,?, @wResultCode)");
	app->db->setString(1, Ntl_WC2MB(req->awchCharName));
	app->db->setInt(2, req->charId);
	app->db->execute();
	app->db->execute("SELECT @wResultCode");
	app->db->fetch(); 

	res->wOpCode = CU_CHARACTER_RENAME_RES;
	res->charId = req->charId;
	res->wResultCode = app->db->getInt("@wResultCode");

	packet.SetPacketLen( sizeof(sCU_CHARACTER_RENAME_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );
}

//--------------------------------------------------------------------------------------//
//		Connection check and login queue function
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharWaitCheckReq(CNtlPacket * pPacket)
{
	CNtlPacket packet(sizeof(sCU_CONNECT_WAIT_CHECK_RES));
	sCU_CONNECT_WAIT_CHECK_RES * sPacket = (sCU_CONNECT_WAIT_CHECK_RES *)packet.GetPacketData();
	sPacket->wOpCode = CU_CONNECT_WAIT_CHECK_RES;
	sPacket->wResultCode = GAME_SUCCESS;
	packet.SetPacketLen( sizeof(sCU_CONNECT_WAIT_CHECK_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet);


	CNtlPacket packet2(sizeof(sCU_CONNECT_WAIT_COUNT_NFY));
	sCU_CONNECT_WAIT_COUNT_NFY * sPacket2 = (sCU_CONNECT_WAIT_COUNT_NFY *)packet2.GetPacketData();
	sPacket2->wOpCode = CU_CONNECT_WAIT_COUNT_NFY;
	sPacket2->dwCountWaiting = 0; /// How many players are in queue?

	packet2.SetPacketLen( sizeof(sCU_CONNECT_WAIT_COUNT_NFY));
	rc = g_pApp->Send( this->GetHandle(), &packet2);
}

//--------------------------------------------------------------------------------------//
//		Select character and login to game-server
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharSelectReq(CNtlPacket * pPacket)
{
	sUC_CHARACTER_SELECT_REQ * req = (sUC_CHARACTER_SELECT_REQ*)pPacket->GetPacketData();
	CNtlPacket packet(sizeof(sCU_CHARACTER_SELECT_RES));
	sCU_CHARACTER_SELECT_RES * res = (sCU_CHARACTER_SELECT_RES *)packet.GetPacketData();
	res->wOpCode = CU_CHARACTER_SELECT_RES;
	res->wResultCode = CHARACTER_SUCCESS;
	res->charId = req->charId; 
	strcpy_s((char*)res->abyAuthKey, NTL_MAX_SIZE_AUTH_KEY, "Dbo");
	strcpy_s(res->szGameServerIP, sizeof(res->szGameServerIP), "127.0.0.1");
	res->wGameServerPortForClient = 30001;

	packet.SetPacketLen( sizeof(sCU_CHARACTER_SELECT_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet );
}

//--------------------------------------------------------------------------------------//
//		Cancel log in request
//--------------------------------------------------------------------------------------//
void CClientSession::SendCancelWaitReq(CNtlPacket * pPacket)
{
	sUC_CONNECT_WAIT_CANCEL_REQ * req = (sUC_CONNECT_WAIT_CANCEL_REQ*)pPacket->GetPacketData();
	printf("--- CANCEL LOGIN REQUEST SERVER CHANNEL INDEX %i --- \n", req->byServerChannelIndex);

	CNtlPacket packet(sizeof(sCU_CONNECT_WAIT_CANCEL_RES));
	sCU_CONNECT_WAIT_CANCEL_RES * res = (sCU_CONNECT_WAIT_CANCEL_RES *)packet.GetPacketData();


	res->wOpCode = CU_CONNECT_WAIT_CANCEL_RES;
	res->wResultCode = CHARACTER_SUCCESS;


	packet.SetPacketLen( sizeof(sCU_CONNECT_WAIT_CANCEL_RES) );
	int rc = g_pApp->Send( this->GetHandle(), &packet);

}