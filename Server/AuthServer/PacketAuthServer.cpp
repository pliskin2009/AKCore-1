#include "stdafx.h"
#include "NtlSfx.h"
#include "NtlPacketUA.h"
#include "NtlPacketAU.h"
#include "ResultCode.h"

#include "AuthServer.h"



//--------------------------------------------------------------------------------------//
//		Get the account ID and log in to Char Server									//
//--------------------------------------------------------------------------------------//
void CClientSession::SendCharLogInReq(CNtlPacket * pPacket, CAuthServer * app) 
{
	NTL_PRINT(PRINT_APP, "Client Received Login Request");

	sUA_LOGIN_REQ * req = (sUA_LOGIN_REQ *)pPacket->GetPacketData();

	CNtlPacket packet(sizeof(sAU_LOGIN_RES));
	sAU_LOGIN_RES * res = (sAU_LOGIN_RES *)packet.GetPacketData();


	res->wOpCode = AU_LOGIN_RES;
	memcpy(res->awchUserId, req->awchUserId, NTL_MAX_SIZE_USERID_UNICODE);
	strcpy_s((char*)res->abyAuthKey, NTL_MAX_SIZE_AUTH_KEY, "Dbo");


	app->db->prepare("CALL AuthLogin (? ,?, @acc_id, @result_code)");
	app->db->setString(1, Ntl_WC2MB(req->awchUserId));
	app->db->setString(2, Ntl_WC2MB(req->awchPasswd));
	app->db->execute();
	app->db->execute("SELECT @acc_id, @result_code");
	app->db->fetch(); 

	res->wResultCode = app->db->getInt("@result_code");
	res->accountId = app->db->getInt("@acc_id");

	res->byServerInfoCount = 1;
	strcpy_s(res->aServerInfo[0].szCharacterServerIP, NTL_MAX_LENGTH_OF_IP, IP_SERVER_ALL);
	res->aServerInfo[0].wCharacterServerPortForClient = 20300;
	res->aServerInfo[0].dwLoad = 0;
	res->lastServerFarmId = 0;

	packet.SetPacketLen(sizeof(sAU_LOGIN_RES));
	int rc = g_pApp->Send(this->GetHandle(), &packet);
		if (NTL_SUCCESS != rc)
		{
			NTL_PRINT(PRINT_APP, "Failed to send packet %d(%s)", rc, NtlGetErrorMessage(rc));
		}
		else{
			NTL_PRINT(PRINT_APP, "User %S send to charserver", req->awchUserId);
		 }
}

//--------------------------------------------------------------------------------------//
//		Disconnect from Auth Server
//--------------------------------------------------------------------------------------//
void CClientSession::SendLoginDcReq(CNtlPacket * pPacket) 
{
	CNtlPacket packet(sizeof(sAU_LOGIN_DISCONNECT_RES));
	sAU_LOGIN_DISCONNECT_RES * res = (sAU_LOGIN_DISCONNECT_RES *)packet.GetPacketData();
	res->wOpCode = AU_LOGIN_DISCONNECT_RES;

	packet.SetPacketLen(sizeof(sAU_LOGIN_DISCONNECT_RES));
	int rc = g_pApp->Send(this->GetHandle(), &packet);
	this->Disconnect(true);
}
