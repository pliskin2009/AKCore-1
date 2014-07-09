#pragma once

#include "NtlPacketCommon.h"

#include "Character.h"
#include "NtlWorld.h"
#include "Skill.h"
#include "NtlObject.h"
#include "Avatar.h"
#include "NtlParty.h"
#include "Quest.h"
#include "Guild.h"
#include "NtlChat.h"
#include "NtlTimeQuest.h"
#include "NtlRankBattle.h"
#include "NtlMail.h"
#include "CSArchitecture.h"
#include "NtlTeleport.h"
#include "NtlFriend.h"
#include "NtlBudokai.h"
#include "NtlMatch.h"
#include "NtlPartyDungeon.h"
#include "NtlPetition.h"
#include "NtlDojo.h"
#include "NtlHlsItem.h"
#include "NtlMovement.h"


enum eOPCODE_GU
{
	GU_OPCODE_BEGIN = 5000,

	GU_PONG = GU_OPCODE_BEGIN,
	GU_SESSION_STATE_WRONG, // ���� ���� ���¿� Ŭ���̾�Ʈ�� ��û�� ���� �ʴ�.
	GU_CHAR_STATE_WRONG, // ���� ĳ���� ���¿� Ŭ���̾�Ʈ�� ��û�� ���� �ʴ�.

	GU_GAME_ENTER_RES,
	GU_GAME_LEAVE_RES,
	GU_ENTER_WORLD_RES,
	GU_ENTER_WORLD_COMPLETE,
	GU_AUTH_KEY_FOR_COMMUNITY_SERVER_RES,

	GU_AVATAR_CHAR_INFO,
	GU_AVATAR_ITEM_INFO,
	GU_AVATAR_SKILL_INFO,
	GU_AVATAR_HTB_INFO,
	GU_AVATAR_BUFF_INFO,
	GU_AVATAR_WORLD_INFO,
	GU_AVATAR_ZONE_INFO,
	GU_AVATAR_QUEST_COMPLETE_INFO,	// ����Ʈ �Ϸ� ����
	GU_AVATAR_QUEST_PROGRESS_INFO,	// ����Ʈ ���� ����
	GU_AVATAR_QUEST_INVENTORY_INFO,	// ����Ʈ �κ� ����
	GU_AVATAR_INFO_END,
	GU_AVATAR_ATTRIBUTE_UPDATE,

	GU_OBJECT_CREATE,
	GU_OBJECT_DESTROY,

	GU_CHAR_MOVE, // �̵�
	GU_CHAR_DEST_MOVE, // �������̵�
	GU_CHAR_CHANGE_HEADING, // ���� ȸ��
	GU_CHAR_MOVE_SYNC, // ��ġ ����
	GU_CHAR_CHANGE_JUMP_DIRECTION, // ĳ���� ���� ����
	GU_CHAR_CHANGE_DIRECTION_ON_FLOATING,		// ĳ���� ����/falling ���� �ٶ󺸴� ����
	GU_CHAR_FOLLOW_MOVE, // ���󰡱�
	GU_CHAR_JUMP, // ����
	GU_CHAR_JUMP_END, // ���� ��
	GU_CHAR_PUSHED_NFY,							// Push �߻�
	GU_CHAR_FIGHTMODE, // ���ݸ��
	GU_CHAR_BLOCK_MODE_COOL_TIME_NFY, // Block ��� ��Ÿ�� count�� ���� �˸�
	//------------------------------------------------------------------
	//  [5/24/2006 zeroera] : �����ʿ� : ���� ȿ������ ������ ���� ���� ��� ������ �޽�����ε� ���� �����ϴ�
	// ����� ���� ������Ʈ �޽����� ó���ϹǷ� ��� ���� �ʴ´�.
	//------------------------------------------------------------------
	GU_CHAR_SITDOWN,
	GU_CHAR_STANDUP,
	GU_CHAR_CAMPING,
	GU_CHAR_FAINT,
	GU_CHAR_KNOCKDOWN,
	GU_CHAR_SLIDING,
	//------------------------------------------------------------------
	GU_CHAR_CONVERT_CLASS,
	GU_CHAR_DIALOG,									// ĳ���� ��ȭ ���
	GU_CHAR_DIRECT_PLAY,							// ĳ���� ����
	GU_CHAR_DIRECT_PLAY_END,					// ĳ���� ���� �� ( sync�� �����Ǿ� �ִ� ��쿡�� ���� )
	GU_CHAR_AWAY_RES,
	GU_CHAR_MAIL_INFO,	
	GU_CHAR_KEY_INFO,
	GU_CHAR_RANKBATTLE_SCORE,						// RankBattle Score
	GU_CHAR_KEY_UPDATE_RES,
	GU_CHAR_ACTION_ATTACK,
	GU_CHAR_ACTION_SKILL,
	GU_CHAR_ACTION_ITEM,
	GU_CHAR_REVIVAL_RES,
	GU_CHAR_TELEPORT_RES,
	GU_CHAR_BIND_RES,
	GU_CHAR_SERVER_CHANGE_RES,
	GU_CHAR_CHANNEL_CHANGE_RES,
	GU_CHAR_EXIT_RES,
	GU_CHAR_SKILL_RES,
	GU_GAME_EXIT_RES,
	GU_GAME_KICK_NFY,
	GU_EFFECT_AFFECTED,
	
	GU_SKILL_CASTING_CANCELED_NFY,
	GU_SKILL_CASTING_DELAYED_NFY,					// ��ų ĳ������ �����Ǿ����� �˸�
	GU_SKILL_AFFECTING_CANCELED_NFY,
	GU_SKILL_TARGET_LIST_REQ,
	GU_SKILL_LEARN_RES,
	GU_SKILL_LEARNED_NFY,
	GU_SKILL_UPGRADE_RES,
	GU_SKILL_RP_BONUS_SETTING_RES,
	GU_SKILL_NOTIFY_EXP,
	GU_SKILL_AFTEREFFECT_REMAINING_TIME_NFY,		// ���� ������ ��Ÿ�� count�� ���� �˸�
	GU_SKILL_COOL_TIME_STARTED_NFY,					// ��ų�� cool time�� ���۵Ǿ����� �˸�

	GU_HTB_START_RES, // HTB ���� ����
	GU_HTB_LEARN_RES, // HTB ���� ����
	GU_HTB_FORWARD_RES, // HTB ���� ����
	GU_HTB_RP_BALL_USE_RES,
	GU_HTB_RP_BALL_USED_NFY,
	GU_HTB_RP_BALL_RESULT_DECIDED_NFY,

	GU_BUFF_REGISTERED,
	GU_BUFF_DROPPED,
	GU_BUFF_REFRESH_ALL,
	GU_BUFF_DROP_RES,				// Buff ���� ��û�� ���� ���

	GU_ITEM_CREATE,
	GU_ITEM_UPDATE,
	GU_ITEM_MOVE_RES,
	GU_ITEM_MOVE_STACK_RES,
	GU_ITEM_DELETE,
	GU_ITEM_DELETE_RES,
	GU_ITEM_EQUIP_REPAIR_RES,			// ���� �Ϸ� ����
	GU_ITEM_REPAIR_RES,
	GU_ITEM_USE_RES, // ������ ��� ��û�� ���� ���
	GU_ITEM_CASTING_CANCELED,		// ������ ĳ������ ��ҵǾ����� �˸�
	GU_ITEM_CASTING_DELAYED_NFY,					// ������ ĳ������ �����Ǿ����� �˸�
	GU_ITEM_DUR_DOWN,
	GU_ITEM_DUR_UPDATE,
	GU_ITEM_STACK_UPDATE,
	GU_ITEM_UPGRADE_RES,
	GU_ITEM_IDENTIFY_RES,

	GU_ITEM_PICK_RES,
	GU_ZENNY_PICK_RES,

	GU_UPDATE_CHAR_STATE,
	GU_UPDATE_CHAR_ASPECT_STATE,
	GU_UPDATE_CHAR_CONDITION,
	GU_UPDATE_CHAR_EXP,
	GU_UPDATE_CHAR_LEVEL,
	GU_UPDATE_CHAR_SPEED,
	GU_UPDATE_CHAR_ATTACK_SPEEDRATE,
	GU_UPDATE_ITEM_EQUIP,	// neighbor pc���� �����Ѵ�.
	GU_UPDATE_ITEM_DELETED,	// 
	GU_UPDATE_TARGET_INFO,
	GU_UPDATE_CHAR_LP,
	GU_UPDATE_CHAR_EP,
	GU_UPDATE_CHAR_RP, 
	GU_UPDATE_CHAR_LP_EP,
	GU_UPDATE_CHAR_ZENNY,

	GU_UPDATE_CHAR_MUDOSA_POINT,

	GU_SYSTEM_DISPLAY_TEXT, // �ؽ�Ʈ ���÷���
	GU_SYSTEM_DISPLAY_RESULTCODE,	// ResultCode �ؽ�Ʈ�� Ŭ���̾�Ʈ�� ����Ѵ�.

	GU_SHOP_START_RES,
	GU_SHOP_BUY_RES,
	GU_SHOP_SELL_RES,
	GU_SHOP_END_RES,
	GU_SHOP_SKILL_BUY_RES,		// ��ų ���� ����

	GU_PARTY_CREATE_RES,
	GU_PARTY_DISBAND_RES,
	GU_PARTY_DISBANDED_NFY,
	GU_PARTY_INVITE_RES,
	GU_PARTY_INVITE_NFY,
	GU_PARTY_RESPONSE_INVITATION_RES,
	GU_PARTY_MEMBER_JOINED_NFY,
	GU_PARTY_INFO,
	GU_PARTY_INVENTORY_INFO,
	GU_PARTY_OPENED_CHARM_INVENTORY_INFO,
	GU_PARTY_INVITATION_DECLINED_NFY,
	GU_PARTY_INVITATION_EXPIRED_NFY,
	GU_PARTY_LEAVE_RES,
	GU_PARTY_MEMBER_LEFT_NFY,
	GU_PARTY_KICK_OUT_RES,
	GU_PARTY_MEMBER_KICKED_OUT_NFY,
	GU_PARTY_CHANGE_LEADER_RES,
	GU_PARTY_LEADER_CHANGED_NFY,

	GU_PARTY_MEMBER_LEVELED_UP_NFY,
	GU_PARTY_MEMBER_CLASS_CHANGED_NFY,
	GU_PARTY_OPEN_CHARM_SLOT_RES,
	GU_PARTY_CHARM_SLOT_OPENED_NFY,
	GU_PARTY_CLOSE_CHARM_SLOT_RES,
	GU_PARTY_CHARM_SLOT_CLOSED_NFY,
	GU_PARTY_REGISTER_VICTIM_ITEM_RES,
	GU_PARTY_VICTIM_ITEM_REGISTERED_NFY,
	
	GU_PARTY_UNREGISTER_VICTIM_ITEM_RES,
	GU_PARTY_VICTIM_ITEM_UNREGISTERED_NFY,
	GU_PARTY_REGISTER_VICTIM_ZENNY_RES,
	GU_PARTY_VICTIM_ZENNY_REGISTERED_NFY,
	GU_PARTY_UNREGISTER_VICTIM_ZENNY_RES,
	GU_PARTY_VICTIM_ZENNY_UNREGISTERED_NFY,
	GU_PARTY_DECLARE_ZENNY_RES,
	GU_PARTY_DECLARED_ZENNY_CHANGED_NFY,
	GU_PARTY_CHARM_ACTIVATION_FAILED_NFY,
	GU_PARTY_ACTIVATE_CHARM_RES,
	GU_PARTY_CHARM_ACTIVATED_NFY,
	GU_PARTY_DEACTIVATE_CHARM_RES,
	GU_PARTY_CHARM_DEACTIVATED_NFY,
	GU_PARTY_CHANGE_ZENNY_LOOTING_METHOD_RES,
	GU_PARTY_ZENNY_LOOTING_METHOD_CHANGED_NFY,
	GU_PARTY_CHANGE_ITEM_LOOTING_METHOD_RES,
	GU_PARTY_ITEM_LOOTING_METHOD_CHANGED_NFY,
	GU_PARTY_ZENNY_LOOTING_METHOD_UNLOCKED_NFY,
	GU_PARTY_ITEM_LOOTING_METHOD_UNLOCKED_NFY,
	GU_PARTY_ZENNY_UPDATED_NFY,
	GU_PARTY_INVENTORY_ITEM_ADDED_NFY,
	GU_PARTY_INVENTORY_ITEM_REMOVED_NFY,
	GU_PARTY_MEMBER_GAINED_ITEM_NFY,
	GU_PARTY_MEMBER_GAINED_ZENNY_NFY,
	GU_PARTY_INVEST_ZENNY_RES,
	GU_PARTY_INVEST_ZENNY_NFY,
	GU_PARTY_INVENTORY_ITEM_WINNER_CHANGED_NFY,
	GU_PARTY_MEMBER_LOCATION_NFY,
	GU_PARTY_INVEN_ITEM_RANK_SET_RES,
	GU_PARTY_INVEN_ITEM_RANK_SET_NFY,

	GU_BANK_START_RES,
	GU_BANK_MOVE_RES,
	GU_BANK_MOVE_STACK_RES,
	GU_BANK_END_RES,
	GU_BANK_ZENNY_INFO,
	GU_BANK_ITEM_INFO,
	GU_BANK_ZENNY_RES,
	GU_BANK_BUY_RES,
	GU_BANK_ITEM_DELETE_RES,

	GU_SOCIAL_ACTION, // Social Action ���

	GU_SCOUTER_INDICATOR_RES, // ��ī���� ���������� ���
	GU_SCOUTER_PREDICT_RES,
	GU_SCOUTER_EQUIP_CHECK_RES,
	GU_SCOUTER_CHIP_REMOVE_ALL_RES,

	GU_TS_CONFIRM_STEP_RES,							// Ʈ���� �ܰ� ���� ����
	GU_TS_UPDATE_SYNC_NFY,							// Ʈ���� ���� ���� �˸�
	GU_TS_UPDATE_STATE,								// Ʈ���� ���� ���� ������Ʈ
	GU_TS_UPDATE_EVENT_NFY,							// Ʈ���� �̺�Ʈ ������Ʈ
	GU_TS_EXCUTE_TRIGGER,							// Ŭ���̾�Ʈ Ʈ���� ���� ����
	GU_TS_EXCUTE_TRIGGER_OBJECT_RES,				//
	GU_TS_TRIGGER_OBJECT_DIALOG_NFY,				// TriggerObject Conversation
	GU_TS_PC_DIALOG_NFY,							// PC Conversation
	GU_TS_SKIP_CONTAINER,

	GU_QUEST_ITEM_CREATE_NFY,						// ����Ʈ ������ ���� �˸�
	GU_QUEST_ITEM_DELETE_NFY,						// ����Ʈ ������ ���� �˸�
	GU_QUEST_ITEM_UPDATE_NFY,						// ����Ʈ ������ ���� �˸�
	GU_QUEST_ITEM_MOVE_RES,							// ����Ʈ ������ �̵� ����
	GU_QUEST_ITEM_DELETE_RES,						// ����Ʈ ������ ���� ����
	GU_QUEST_SVREVT_START_NFY,						// ����Ʈ �̺�Ʈ ����
	GU_QUEST_SVREVT_END_NFY,						// ����Ʈ �̺�Ʈ ����
	GU_QUEST_SVREVT_UPDATE_NFY,						// ����Ʈ �̺�Ʈ ������Ʈ
	GU_QUEST_GIVEUP_RES,							// ����Ʈ ���� ����
	GU_QUEST_SHARE_NFY,								// ����Ʈ ����
	GU_QUEST_RESET_NFY,								// ����Ʈ�� ������ ������ŭ ���� ������ �Ϸ� ������ �����Ѵ�.
	GU_QUEST_OBJECT_VISIT_RES,						// npc, tobject �湮 �̺�Ʈ
	GU_QUEST_FORCED_COMPLETION_NFY,					// ����Ʈ ���� �Ϸ� ����(�׽�Ʈ��)

	GU_FREEBATTLE_CHALLENGE_RES,					// ������Ʋ ���� ��û ����
	GU_FREEBATTLE_ACCEPT_REQ,						// ������Ʋ �������� ��û
	GU_FREEBATTLE_CANCEL_NFY,						// ������Ʋ ���� ���
	GU_FREEBATTLE_START_NFY,						// ������Ʋ ���� ����
	GU_FREEBATTLE_OUTSIDE_NFY,						// ������Ʋ �������� ���
	GU_FREEBATTLE_INSIDE_NFY,						// ������Ʋ �������� ����
	GU_FREEBATTLE_END_NFY,							// ������Ʋ ���� ����

	GU_QUICK_SLOT_UPDATE_RES,						// �����Ծ�����Ʈ
	GU_QUICK_SLOT_DEL_NFY,							// ������ ����	
	GU_QUICK_SLOT_INFO,								// QuickSlot Load

	GU_PET_CHAR_INFO,
	GU_PET_SKILL_INFO,
	GU_PET_INFO_END,
	GU_PET_DESPAWNED_NFY,							// ���� �����
	GU_PET_DISMISS_PET_RES,							// ���� ��ȯ ��� ��û ���

	GU_ACTION_REPORT_MESSAGE,						// ǥ���ϰ� ���� �޼����� ����Ʈ �ڵ� �ε����� ÷���Ͽ� ������ Ŭ���̾�Ʈ�� ǥ���Ѵ�.

	GU_TRADE_START_NFY,
	GU_TRADE_START_RES,
	GU_TRADE_OK_REQ,
	GU_TRADE_ADD_NFY,
	GU_TRADE_ADD_RES,
	GU_TRADE_DEL_NFY,
	GU_TRADE_DEL_RES,
	GU_TRADE_MODIFY_NFY,
	GU_TRADE_MODIFY_RES,
	GU_TRADE_ZENNY_UPDATE_NFY,
	GU_TRADE_ZENNY_UPDATE_RES,
	GU_TRADE_END_NFY,
	GU_TRADE_END_RES,
	GU_TRADE_CANCEL_NFY,
	GU_TRADE_CANCEL_RES,
	GU_TRADE_DENY_RES,

	GU_GUILD_NAME_CHANGED_NFY,					// ��� �̸� ���� �˸�
	GU_GUILD_CREATE_RES,						// ��� ���� ��û ���
	GU_GUILD_INVITE_RES,						// ��� �ʴ� ���

	GU_TOBJECT_UPDATE_STATE,						// Ʈ���� ������Ʈ ���� ������Ʈ
	GU_TOBJECT_ACTION_ATTACK,						// Ʈ���� ������Ʈ ������
	
	GU_TUTORIAL_HINT_UPDATE_RES,					// ��Ʈ �÷��� ������Ʈ

	GU_TELECAST_MESSAGE_BEG_NFY,					// ��� �޽��� ���� ����
	GU_TELECAST_MESSAGE_END_NFY,					// ��� �޽��� ���� ����
	GU_BROAD_MESSAGE_BEG_NFY,						// ��� �޽��� ����
	GU_BROAD_MESSAGE_END_NFY,						// ��� �޽��� ��
	GU_MINI_NARRATION_NFY,							// �̴ϳ����̼�
	GU_PROGRESS_MESSAGE_NFY,						// Ÿ�Ӹӽ� ���� �޽��� ����
	GU_DIRECTION_INDICATE_NFY,						// �������� ����

	GU_TIMEQUEST_ROOM_LIST_RES,						// Ÿ�Ӹӽ� ����Ʈ �� ��� ��û ����
	GU_TIMEQUEST_ROOM_INFO_RES,						// Ÿ�Ӹӽ� ����Ʈ �� ���� ��û ����
	GU_TIMEQUEST_ROOM_JOIN_RES,						// Ÿ�Ӹӽ� ����Ʈ �� ���� ��û ����
	GU_TIMEQUEST_ROOM_JOIN_NFY,						// Ÿ�Ӹӽ� ����Ʈ �� ������ ��Ƽ������ �˸�(��Ƽ�� ����)
	GU_TIMEQUEST_ROOM_LEAVE_RES,					// Ÿ�Ӹӽ� ����Ʈ �� ���� ��û ����
	GU_TIMEQUEST_ROOM_LEAVE_NFY,					// Ÿ�Ӹӽ� ����Ʈ �� ������ ��Ƽ������ �˸�(��Ƽ�� ����)
	GU_TIMEQUEST_ROOM_SELECTION_NFY,				// Ÿ�Ӹӽ� ����Ʈ ��÷
	GU_TIMEQUEST_ROOM_TELEPORT_RES,					// Ÿ�Ӹӽ� ����Ʈ ���� ��ġ�� �̵� ����
	GU_TIMEQUEST_START_NFY,							// Ÿ�Ӹӽ� ����Ʈ ���� ����
	GU_TIMEQUEST_START_EXCEPTION_NFY,				// Ÿ�Ӹӽ� ����Ʈ ���忡 ���� ������(�����ÿ��� ���۵��� �ʴ´�.)
	GU_TIMEQUEST_LEAVE_NFY,							// Ÿ�Ӹӽ� ����Ʈ ���� ����
	GU_TIMEQUEST_COUNTDOWN_NFY,						// Ÿ�Ӹӽ� ����Ʈ ī��Ʈ�ٿ� ����
	GU_TIMEQUEST_REWARD_NFY,						// Ÿ�Ӹӽ� ����Ʈ ���� ����
	GU_TIMEQUEST_INFORMATION_NFY,				// Ÿ�Ӹӽ� ����Ʈ �������� ���� ����
	GU_TIMEQUEST_UPDATE_GAME_STATE,					// Ÿ�Ӹӽ� ����Ʈ ���� ���� ������Ʈ
	GU_TIMEQUEST_UPDATE_KILL_COUNT,					// Ÿ�Ӹӽ� ����Ʈ �÷��̾� ų ī��Ʈ ������Ʈ
	GU_TIMEQUEST_UPDATE_COUPON_COUNT,				// Ÿ�Ӹӽ� ����Ʈ �������� ������Ʈ
	GU_TIMEQUEST_UPDATE_TMQ_POINT,					// Ÿ�Ӹӽ� ����Ʈ TMQ ����Ʈ ������Ʈ
	GU_TIMEQUEST_UPDATE_GAME_TIME,					// Ÿ�Ӹӽ� ����Ʈ ���� �ð� ������Ʈ

	GU_RANKBATTLE_INFO_RES,							// �⺻ ����
	GU_RANKBATTLE_JOIN_RES,							// ��û
	GU_RANKBATTLE_JOIN_NFY,							// member ���� ��û �˸�
	GU_RANKBATTLE_LEAVE_RES,						// ���
	GU_RANKBATTLE_LEAVE_NFY,						// ��� ��Ƽ�� �˸�
	GU_RANKBATTLE_MATCH_START_NFY,					// ��� ����
	GU_RANKBATTLE_MATCH_CANCELED_NFY,				// ��Ⱑ ��ҵ�

	GU_RANKBATTLE_ROOM_LIST_RES,					// RankBattle �� ��� ��û
	GU_RANKBATTLE_ROOM_INFO_RES,					// RankBattle �� ���� ��û
	GU_RANKBATTLE_ROOM_CREATE_RES,					// RankBattle �� ���� ��û
	GU_RANKBATTLE_ROOM_CREATE_NFY,					// RankBattle ���� �����Ǿ����� ��Ƽ������ �˸�
	GU_RANKBATTLE_ROOM_LEAVE_RES,					// RankBattle �� ���� ��û
	GU_RANKBATTLE_ROOM_LEAVE_NFY,					// RankBattle ���� �����Ǿ����� ��Ƽ������ �˸�
	GU_RANKBATTLE_ROOM_JOIN_INFO_NFY,				// Party�� ���� ��� RankBattle�� ���� ���� ������ ����
	GU_RANKBATTLE_ROOM_CHALLENGE_RES,				// RankBattle ��� ��û
	GU_RANKBATTLE_ROOM_CHALLENGE_NFY,				// RankBattle ��� ��û ����� ��Ƽ������ �˸�
	GU_RANKBATTLE_ROOM_MATCH_READY_NFY,				// RankBattle�� �� ���۵��� �˸�
	GU_RANKBATTLE_ROOM_MATCH_START_NFY,				// RankBattle�� ���۵� - ��������� �̵�
	GU_RANKBATTLE_ROOM_MATCH_CANCEL_RES,			// RankBattle ������ �����(����)
	GU_RANKBATTLE_ROOM_MATCH_CANCELED_NFY,			// RankBattle ������ ��ҵ�(owner ���Ը� ����, �ٽ� �����·� ����)
	GU_RANKBATTLE_BATTLE_STATE_UPDATE_NFY,			// RankBattle Battle State�� ������Ʈ(������� ����)
	GU_RANKBATTLE_BATTLE_TEAM_INFO_NFY,				// RankBattle Team ������ �˸�
	GU_RANKBATTLE_BATTLE_PLAYER_STATE_NFY,			// RankBattle Player�� ���� �˸�(���, ������)
	GU_RANKBATTLE_BATTLE_KILLSCORE_UPDATE_NFY,		// RankBattle KillScore ������Ʈ
	GU_RANKBATTLE_BATTLE_STAGE_FINISH_NFY,			// RankBattle Stage Finish - Stage ��ħ
	GU_RANKBATTLE_BATTLE_MATCH_FINISH_NFY,			// RankBattle Battle Finish - ��� ��ħ
	GU_RANKBATTLE_BATTLE_END_NFY,					// RankBattle�� ������ pc���� �˸�(PC ���� Battle�� ������ ������ �ٸ��Ƿ�)
	GU_RANKBATTLE_BATTLE_FORCED_LEAVE_NFY,			// RankBattle ���� ���������� WorldLeave ��(�ʹ� ���� �ε� ���� ��)
	GU_RANKBATTLE_TOTAL_SCORE_UPDATE_NFY,			// ���� ���� ������Ʈ

	GU_DRAGONBALL_START_RES,						// ����Ŭ��
	GU_DRAGONBALL_CHECK_RES,						// �巡�ﺼ UI 7�� ��ġOK
	GU_DRAGONBALL_REWARD_RES,						// �巡�ﺼ �� ������ ���� ���� ���� ��û
	GU_DRAGONBALL_COLLECT_NFY,						// �巡�ﺼ ������ Ÿ�� �����뺸
	GU_DRAGONBALL_SCHEDULE_INFO,						// �巡�ﺼ �����Ⱓ ����

	GU_PRIVATESHOP_CREATE_RES,							// ���λ����� ���� [6/28/2007 SGpro]
	GU_PRIVATESHOP_CREATE_NFY,							// ���λ��� ���� [1/31/2008 SGpro]
	GU_PRIVATESHOP_EXIT_RES,							// ���λ����� �ݴ´�[6/28/2007 SGpro]
	GU_PRIVATESHOP_OPEN_RES,							// ���λ����� ���¸� Open���� ���ּ���[6/28/2007 SGpro]
	GU_PRIVATESHOP_OPEN_NFY,							// [7/31/2007 SGpro]
	GU_PRIVATESHOP_CLOSE_RES,							// ���λ����� ���¸� Close���� ���ּ���[6/28/2007 SGpro]
	GU_PRIVATESHOP_CLOSE_NFY,							// [7/31/2007 SGpro]
	GU_PRIVATESHOP_ITEM_INSERT_RES,						// ���λ����� ������ �߰� ����[6/29/2007 SGpro]
	GU_PRIVATESHOP_ITEM_UPDATE_RES,						// ���λ����� ������ ���� ����[6/29/2007 SGpro]
	GU_PRIVATESHOP_ITEM_DELETE_RES,						// ���λ����� ������ ���� ����[6/29/2007 SGpro]
	GU_PRIVATESHOP_ITEM_BUYING_RES,						// ������ ���� ����[6/29/2007 SGpro]
	GU_PRIVATESHOP_ITEM_BUYING_NFY,						// [7/31/2007 SGpro]
	GU_PRIVATESHOP_ENTER_RES,							// �մ� ���� ����[6/29/2007 SGpro]
	GU_PRIVATESHOP_LEAVE_RES,							// �մ� ���� ����[6/29/2007 SGpro]
	GU_PRIVATESHOP_ITEM_DATA_INFO,						// ������ ����Ÿ [7/2/2007 SGpro]
	GU_PRIVATESHOP_ITEM_SELECT_RES,						// [7/19/2007 SGpro]
	GU_PRIVATESHOP_ITEM_SELECT_NFY,						// [7/19/2007 SGpro]
	GU_PRIVATESHOP_ITEM_STATE_NFY,						// [7/31/2007 SGpro]
	GU_PRIVATESHOP_LEAVE_NFY,							// [8/3/2007 SGpro]
	GU_PRIVATESHOP_BUSINESS_REQUEST_RES,						// [10/17/2007 SGpro]
	GU_PRIVATESHOP_BUSINESS_REQUEST_NFY,						// [10/17/2007 SGpro]
	GU_PRIVATESHOP_BUSINESS_CONSENT_REQ,						// [10/17/2007 SGpro]
	GU_PRIVATESHOP_BUSINESS_CONSENT_NFY,						// [10/17/2007 SGpro]
	GU_PRIVATESHOP_BUSINESS_WAITTIMEOUT_NFY,					// [10/17/2007 SGpro]
	GU_PRIVATESHOP_BUSINESS_PRICEFLUCTUATIONS_RES,				// [10/17/2007 SGpro]
	GU_PRIVATESHOP_BUSINESS_PRICEFLUCTUATIONS_NFY,				// [10/17/2007 SGpro]
	GU_PRIVATESHOP_BUSINESS_IMMEDIATE_ITEM_BUYING_RES,			// [10/17/2007 SGpro]
	GU_PRIVATESHOP_BUSINESS_IMMEDIATE_ITEM_BUYING_NFY,			// [10/17/2007 SGpro]
	GU_PRIVATESHOP_BUSINESS_WINDOWCLOSE_NFY,					// [2/4/2008 SGpro]
	GU_PRIVATESHOP_BUSINESS_CANCEL_RES,							// [10/17/2007 SGpro]
	GU_PRIVATESHOP_BUSINESS_CANCEL_NFY,							// [10/17/2007 SGpro]

	GU_TUTORIAL_WAIT_NFY,								// Ʃ�丮�� ��� �˸� 
	GU_TUTORIAL_WAIT_CANCEL_RES,						// Ʃ�丮�� ��� ��� ��û ����
	GU_TUTORIAL_PLAY_QUIT_RES,							// Ʃ�丮�� �÷��� ��� ��û ����
	
	GU_MAIL_START_RES,
	GU_MAIL_SEND_RES,
	GU_MAIL_READ_RES,
	GU_MAIL_RELOAD_NFY,
	GU_MAIL_DEL_RES,
	GU_MAIL_RETURN_RES,
	GU_MAIL_RELOAD_RES,
	GU_MAIL_LOAD_RES,
	GU_MAIL_LOAD_DATA,
	GU_MAIL_LOAD_INFO,
	GU_MAIL_ITEM_RECEIVE_RES,
	GU_MAIL_LOCK_RES,
	GU_MAIL_CLOSE_NFY,
	GU_MAIL_MULTI_DEL_RES,

	GU_PORTAL_START_RES,
	GU_PORTAL_INFO,
	GU_PORTAL_ADD_RES,
	GU_PORTAL_RES,

	GU_WAR_FOG_INFO,
	GU_WAR_FOG_UPDATE_RES,

	GU_MOB_LUCKY_DROP_NFY,

	GU_ITEM_UPGRADE_ALL_NFY,
	GU_BOT_BOTCAUTION_NFY,// Bot ��� [2/20/2008 SGpro]
	GU_UPDATE_CHAR_REPUTATION,

	GU_GUILD_FUNCTION_ADD_RES,
	GU_GUILD_GIVE_ZENNY_RES,

	GU_GUILD_BANK_START_RES,
	GU_GUILD_BANK_MOVE_RES,
	GU_GUILD_BANK_MOVE_STACK_RES,
	GU_GUILD_BANK_END_RES,
	GU_GUILD_BANK_ZENNY_INFO,
	GU_GUILD_BANK_ITEM_INFO,
	GU_GUILD_BANK_ZENNY_RES,
	GU_GUILD_CREATE_MARK_RES,
	GU_GUILD_CHANGE_MARK_RES,
	GU_GUILD_MARK_CHANGED_NFY,

	GU_CROSSFIRE_RES,
	GU_BANK_LOAD_RES,
	
	GU_GUILD_CHANGE_NAME_RES,

	GU_PARTY_SHARETARGET_RES,						// [3/28/2008 SGpro]
	GU_PARTY_SHARETARGET_NFY,						// [3/28/2008 SGpro]

	GU_RIDE_ON_BUS_RES,
	GU_RIDE_OFF_BUS_RES,

	GU_TRANSFORM_CANCEL_RES,
	GU_SHOP_ITEM_IDENTIFY_RES,

	GU_MATCH_MINORMATCH_STATE_UPDATE_NFY,						// Match
	GU_MATCH_MINORMATCH_TEAM_INFO_NFY,				// ���� �� ����
	GU_MATCH_MINORMATCH_PLAYER_STATE_NFY,			//
	GU_MATCH_MINORMATCH_UPDATE_SCORE_NFY,			// ���� Score Update
	GU_MATCH_MINORMATCH_TEAM_SCORE_NFY,				// ���� �� ���ھ� ����, �����ڸ� ���� ����
	GU_MATCH_MINORMATCH_SELECTION_NFY,				// ���� ���� �߻��� �ֻ��� ����
	GU_MATCH_MINORMATCH_STAGE_FINISH_NFY,			// ���� stage finish �˸�
	GU_MATCH_MINORMATCH_MATCH_FINISH_NFY,

	GU_MATCH_MAJORMATCH_STATE_UPDATE_NFY,			//
	GU_MATCH_MAJORMATCH_TEAM_INFO_NFY,				// ���� �� ����
	GU_MATCH_MAJORMATCH_PLAYER_STATE_NFY,			//
	GU_MATCH_MAJORMATCH_UPDATE_SCORE_NFY,			// ���� Score Update
	GU_MATCH_MAJORMATCH_STAGE_FINISH_NFY,			// ���� stage finish �˸�
	GU_MATCH_MAJORMATCH_MATCH_FINISH_NFY,			// ���� match finish �˸�

	GU_MATCH_FINALMATCH_STATE_UPDATE_NFY,			//
	GU_MATCH_FINALMATCH_TEAM_INFO_NFY,				// �ἱ �� ����
	GU_MATCH_FINALMATCH_PLAYER_STATE_NFY,			//
	GU_MATCH_FINALMATCH_UPDATE_SCORE_NFY,			// �ἱ Score Update
	GU_MATCH_FINALMATCH_STAGE_FINISH_NFY,			// �ἱ stage finish �˸�
	GU_MATCH_FINALMATCH_MATCH_FINISH_NFY,			// �ἱ match finish �˸�

	GU_MATCH_AWARDING_NFY,							// �û�� ���

	GU_SKILL_CONFUSE_TARGET_NFY,					// Confuse ������ ���� ���� ��� �˸�
	GU_SKILL_TERROR_COURSE_CHANGE_NFY,				// Terror ������ �� ���� ��ȯ �˸�

	GU_DICE_ROLL_RES,								// Action Skill �ֻ��� ������
	GU_DICE_ROLLED_NFY,								// Action Skill �ֻ��� ������

	GU_BUDOKAI_STATE_INFO_NFY,						// õ�����Ϲ���ȸ�� ���� ���¸� ����
	GU_BUDOKAI_UPDATE_STATE_NFY,					// õ�����Ϲ���ȸ : main state update
	GU_BUDOKAI_UPDATE_MATCH_STATE_NFY,				// õ�����Ϲ���ȸ : match state update

	GU_BUDOKAI_JOIN_INDIVIDUAL_RES,					// ���� ���
	GU_BUDOKAI_LEAVE_INDIVIDUAL_RES,				// ���� ���

	GU_BUDOKAI_JOIN_TEAM_INFO_RES,					// �� ����Ʈ
	GU_BUDOKAI_JOIN_TEAM_RES,						// �� ���
	GU_BUDOKAI_JOIN_TEAM_NFY,						// �� ��� �˸�
	GU_BUDOKAI_LEAVE_TEAM_RES,						// �� ��� ���
	GU_BUDOKAI_LEAVE_TEAM_NFY,						// �� ��� ��� �˸�
	GU_BUDOKAI_LEAVE_TEAM_MEMBER_RES,				// �� ��� ���
	GU_BUDOKAI_LEAVE_TEAM_MEMBER_NFY,				// �� ��� ��� �˸�

	GU_BUDOKAI_JOIN_INFO_RES,						// ���� ����
	GU_BUDOKAI_JOIN_STATE_RES,						// ���� ����
	GU_BUDOKAI_JOIN_STATE_NFY,						// ���� ���� �˸�
	GU_BUDOKAI_MUDOSA_INFO_RES,						// ������ ����
	GU_BUDOKAI_MUDOSA_TELEPORT_RES,					// ������ �ڷ���Ʈ
	GU_BUDOKAI_PROGRESS_MESSAGE_NFY,				// ��� ���� ���� �˸�(����)
	GU_BUDOKAI_SOCIAL_ACTION_NFY,
	GU_BUDOKAI_PRIZEWINNER_NAME_RES,				// ����� / �ؿ���� : ������
//	GU_BUDOKAI_PRIZEWINNER_TEAM_NAME_RES,			// ����� / �ؿ���� : ����

	GU_BUDOKAI_GM_BUDOKAI_SERVER_ENTER_RES,			// õ�����Ϲ���ȸ ������ �ڷ���Ʈ ��û
	GU_BUDOKAI_GM_BUDOKAI_SERVER_LEAVE_RES,			// õ�����Ϲ���ȸ �������� ���� ������ �̵�
	GU_BUDOKAI_GM_MATCH_PROGRESS_INFO_RES,			// ���� ��� ���� ��Ȳ ����Ʈ
	GU_BUDOKAI_GM_MATCH_ARENA_ENTER_RES,			// ����� ����
	GU_BUDOKAI_GM_MATCH_ARENA_LEAVE_RES,			// ����� ������

	GU_DISCONNECTED_NFY,

	GU_BOT_BOTCAUTION_HELPME_NFY,					// Help Me ��� [5/27/2008 SGpro]

	GU_SCOUTER_TURN_ON_NFY,	
	GU_SCOUTER_TURN_OFF_NFY,
	GU_SCOUTER_BROKEN_NFY,
	GU_SCOUTER_ITEM_SELL_RES,

	GU_SHOP_EVENTITEM_START_RES,					// [7/15/2008 SGpro]
	GU_SHOP_EVENTITEM_BUY_RES,						// EVENT ITEM ���� [7/11/2008 SGpro]
	GU_SHOP_EVENTITEM_END_RES,						// [7/15/2008 SGpro]

	GU_ITEM_REPLACE,								// ITEM ��ü [7/11/2008 SGpro]

	GU_SHOP_GAMBLE_BUY_RES,						// EVENT ITEM ���� [7/11/2008 SGpro]

	GU_PARTY_DUNGEON_DIFF_NFY,
	GU_PARTY_DUNGEON_DIFF_RES,
	GU_PARTY_DUNGEON_INIT_NFY,
	GU_PARTY_DUNGEON_INIT_RES,

	GU_UPDATE_CHAR_SP,
	GU_SKILL_INIT_RES,
	GU_SKILL_REMOVE_NFY,
	GU_HTB_REMOVE_NFY,

	GU_CHAR_MARKING_NFY, // Īȣ [9/10/2008 SGpro]

	GU_PARTY_CHARM_DICE_START_NFY,					// ��Ƽ ���̽� UI ���� �����϶�
	GU_PARTY_CHARM_DICE_ROLLED_NFY,					// ���õ� ���̽� ��� ���
	GU_PARTY_CHARM_DICE_ROLLED_RES,					// ���õ� ���̽� ���
	GU_PARTY_CHARM_DICE_END_NFY,					// ��Ƽ ���̽� ���ýð� �Ϸ� �� �Ѱ��

	GU_PARTY_INVEN_LOCK_NFY,
	GU_PARTY_INVEN_LOCK_RES,
	GU_PARTY_INVEN_RESET_RES,
	GU_PARTY_INVEN_RESET_NFY,
	GU_PARTY_INVEN_ACCEPTED_RES,
	GU_PARTY_INVEN_ACCEPTED_NFY,
	GU_PARTY_INVEN_GIVE_RES,
	GU_PARTY_INVEN_GIVE_NFY,
	GU_PARTY_INVEN_DICE_START_RES,
	GU_PARTY_INVEN_DICE_START_NFY,
	GU_PARTY_INVEN_DICE_ROLL_RES,
	GU_PARTY_INVEN_DICE_ROLL_NFY,
    GU_PARTY_INVEN_DICE_END_NFY,

	GU_TELEPORT_PROPOSAL_NFY,
	GU_TELEPORT_CONFIRM_RES,

	GU_AVATAR_PETITION_INFO,

	GU_GAME_COMMON_MSG_NFY,

	GU_CHAR_NICKNAME_CHANGED_NFY,

	GU_HOIPOIMIX_RECIPE_REG_NFY,					// �����ǵ��
	GU_HOIPOIMIX_ITEM_CHECK_RES,					// ��������� ���� (�ʿ��� ������ ���� üũ)
	GU_HOIPOIMIX_ITEM_MAKE_RES,						// ������ �����
	GU_HOIPOIMIX_ITEM_MAKE_EP_RES,					// ������ ����� �� EP �ֱ�
	GU_HOIPOIMIX_ITEM_RECIPE_INFO,
	GU_DYNAMIC_OBJECT_UPDATE_STATE,
	GU_HOIPOIMIX_ITEM_MACHINE_MAKE_RES,
	GU_HOIPOIMIX_ITEM_MACHINE_DEL_RES,
	GU_HOIPOIMIX_ITEM_MAKE_EXP_NFY,					// ȣ������ �ͽ� �������̳� ����ġ ������Ʈ

	GU_CHAR_TARGET_LOST_NFY,
	GU_CHAR_GUARD_CRASHED_NFY,		// Guard�� Skill ability�� ���� ������ ������

	GU_UPDATE_CHAR_RP_BALL,
	GU_UPDATE_CHAR_RP_BALL_MAX,

	GU_HOIPOIMIX_JOB_SET_RES,
	GU_HOIPOIMIX_JOB_RESET_RES,

	GU_AVATAR_RP_INCREASE_START_NFY,
	GU_AVATAR_RP_DECREASE_START_NFY,
	GU_AVATAR_RP_INCREASE_STOP_NFY,

	GU_HTB_LAST_STEP_CHANGED_NFY,

	GU_CHAR_CHARGE_CANCELED_NFY,
	GU_CHAR_REFRESH_LP_EP,

	GU_CHAR_NONBATTLEACTIONPATTERNSET_UNITIDX_NFY,

	GU_VEHICLE_START_NFY,			// Ż �� ���� ��ġ �˸�
	GU_VEHICLE_ENGINE_START_RES,			// Ż �� �õ� �� RES
	GU_VEHICLE_ENGINE_START_NFY,			// Ż �� �õ� �� ��ε� ĳ��Ʈ
	GU_VEHICLE_ENGINE_STOP_RES,
	GU_VEHICLE_ENGINE_STOP_NFY,
	GU_VEHICLE_FUEL_UPDATE_NFY,				// Ż �� ���� ��� ������Ʈ
	GU_VEHICLE_END_RES,						// Ż �� ��� ���� �˸�
	GU_VEHICLE_END_NFY,
	GU_VEHICLE_STUNT_NFY,					// �����̽��� ����(Ż��)

	/* �̹� ���Ͻ��濡�� 1�ν� �۾��� �ϱ� ������ �ϴ� �ּ�ó�� 2009.1.5 �¿�.
	GU_VEHICLE_PASSENGER_GETON_RES,			// Ż �� �°� ž�� RES
	GU_VEHICLE_PASSENGER_GETON_NFY,			// Ż �� �°� ž�� ��ε� ĳ��Ʈ
	GU_VEHICLE_ASK_REQ,						// Ż �� �����ڿ��� Ÿ�� �Ǵ��� ���´�
	GU_VEHICLE_PASSENGER_GETOFF_RES,		// Ż �� �°� ���� RES
	GU_VEHICLE_PASSENGER_GETOFF_NFY			// Ż �� �°� ���� ��ε� ĳ��Ʈ
	*/

	GU_SKILL_PASSIVE_EFFECT_APPLIED_NFY,
	GU_AVATAR_UPDATED_SKILL_DATA_INFO,

	GU_MONSTER_TRANSFORMED_NFY,

	GU_DOJO_CREATE_RES,
	GU_DOJO_DELETE_RES,
	GU_DOJO_FUNCTION_ADD_RES,
	GU_DOJO_BANK_HISTORY_RES,
	GU_DOGI_CREATE_RES,								// ��������
	GU_DOGI_CHANGE_RES,								// ��������
	GU_DOGI_UPDATE_NFY,								// ��������˸�
	GU_GUILD_DOGI_CREATE_RES,
	GU_GUILD_DOGI_CHANGE_RES,

	GU_CHILD_ADULT_SWITCHED_NFY,
	GU_CHANGE_CLASS_AUTHORITY_CHANGED_NFY,

	GU_PLAY_BGM,

	GU_DOJO_MARK_CHANGED_NFY,
	GU_DOJO_LEVEL_CHANGED_NFY,

	GU_UPDATE_CHAR_NETP,

	GU_DOJO_SCRAMBLE_RES,							// ������Ż�� ��û�� ���� ����
	GU_DOJO_SCRAMBLE_RESPONSE_RES,					// ������Ż�� ��û���� ó���� ���� ����

	GU_NETMARBLEMEMBERIP_NFY,

	GU_BUS_LOCATION_NFY,
	GU_BUS_LOCATION_ERASED_NFY,
	GU_BUS_LOCATION_RESET_ALL_NFY,

	GU_ITEM_EXPIRED_NFY,

	GU_SHOP_NETPYITEM_START_RES,
	GU_SHOP_NETPYITEM_BUY_RES,
	GU_SHOP_NETPYITEM_END_RES,

	GU_CHAR_REFRESH_BATTLE_ATTRIBUTE_MODIFIER,

	GU_CHAR_RANKBATTLE_ALLOW_NFY,
	GU_CHAR_RANKPOINT_RESET_NFY,

	GU_DOJO_NPC_INFO_RES,

	GU_GAMEGUARD_AUTH_ANSWER_REQ,

	GU_DOJO_SEAL_ATTACK_BEGIN_NFY,
	GU_DOJO_SEAL_ATTACK_END_NFY,
	GU_DOJO_SEAL_CURRENT_STATE_NFY,
	GU_INVENTORY_CAPSULE_UNLOCK_NFY,

	GU_DOJO_SCRAMBLE_SHIFT_SEAL_STATE_NFY,
	
	GU_UPDATE_CHAR_LP_STATUS_NFY,

	GU_DURATION_ITEM_BUY_RES,
	GU_DURATION_RENEW_RES,

	GU_CASHITEM_START_RES,
	GU_CASHITEM_INFO_NFY,
	GU_CASHITEM_END_RES,
	GU_CASHITEM_MOVE_RES,
	GU_CASHITEM_USE_RES,
	GU_CASHITEM_ADD_NFY,
	GU_CASHITEM_DEL_NFY,
	GU_CASHITEM_HLSHOP_START_RES,
	GU_CASHITEM_HLSHOP_END_RES,
	GU_CASHITEM_BUY_RES,

	GU_BUDOKAI_PRIZEWINNER_TEAM_NAME_RES,			// ����� / �ؿ���� : ����
	GU_GMT_INFO_NFY,								// GMT �ð��� �˸�
	GU_GMT_UPDATE_RES,							// GMT �缳�� ����
	GU_GMT_CHANGED_NFY,								// GMT �缳�� ���� ���� �˸�

	GU_UPDATE_CHAR_MAX_LP,
	GU_UPDATE_CHAR_MAX_EP,
	GU_UPDATE_CHAR_MAX_RP,

	GU_OPCODE_END_DUMMY,
	GU_OPCODE_END = GU_OPCODE_END_DUMMY - 1
};


//------------------------------------------------------------------
//
//------------------------------------------------------------------
const char * NtlGetPacketName_GU(WORD wOpCode);
//------------------------------------------------------------------


#pragma pack(push, 1)
//------------------------------------------------------------------

//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PONG)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SESSION_STATE_WRONG)
	WORD			wPrevOPCode;	// ������ ���´� �ڵ��ȣ
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_STATE_WRONG)
	WORD			wPrevOPCode; // ������ ���´� �ڵ��ȣ
	HOBJECT			handle; // ĳ���� �ڵ�
	BYTE			byStateID; // ���� ĳ���� ����
	//sCHARSTATE		sCharState; // ���� ĳ���� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GAME_ENTER_RES)
	WORD			wResultCode;
	char			achCommunityServerIP[NTL_MAX_LENGTH_OF_IP + 1];
	WORD			wCommunityServerPort;
	DBOTIME			timeDBOEnter;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GAME_LEAVE_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ENTER_WORLD_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ENTER_WORLD_COMPLETE)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AUTH_KEY_FOR_COMMUNITY_SERVER_RES)
	WORD			wResultCode;
	BYTE			abyAuthKey[NTL_MAX_SIZE_AUTH_KEY];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_CHAR_INFO)
	HOBJECT			handle;
	sPC_PROFILE		sPcProfile;
	WORD			wCharStateSize; //-[9/7/2006 zeroera] : ���� : Ŭ���̾�Ʈ�� ���� ĳ���ͻ��� ������ ���� 
	sCHARSTATE		sCharState;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_ITEM_INFO)
	BYTE			byBeginCount;
	BYTE			byItemCount;
	sITEM_PROFILE	aItemProfile[NTL_MAX_COUNT_USER_HAVE_INVEN_ITEM];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_SKILL_INFO)
	BYTE			bySkillCount;
	sSKILL_INFO		aSkillInfo[NTL_MAX_PC_HAVE_SKILL];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_HTB_INFO)
	BYTE			byHTBSkillCount; // HTB ��ų ����
	sHTB_SKILL_INFO	aHTBSkillnfo[NTL_HTB_MAX_PC_HAVE_HTB_SKILL]; // HTB ��ų ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_BUFF_INFO)
	BYTE			byBuffCount;
	sBUFF_INFO		aBuffInfo[NTL_MAX_BLESS_BUFF_CHARACTER_HAS + NTL_MAX_CURSE_BUFF_CHARACTER_HAS];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_WORLD_INFO)
	sVECTOR3		vCurLoc;
	sVECTOR3		vCurDir;
	sWORLD_INFO		worldInfo;
	BYTE			byDojoCount;
	sDBO_DOJO_BRIEF sDojoData[DBO_MAX_COUNT_DOJO_IN_WORLD];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_ZONE_INFO)
	sWORLD_ZONE_INFO		zoneInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_QUEST_COMPLETE_INFO)
	sQUEST_COMPLETE_INFO	completeInfo; // 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_QUEST_PROGRESS_INFO)
	BYTE					byProgressCount; // ���� �����ϰ� �ִ� ����Ʈ ����
	sQUEST_PROGRESS_INFO	progressInfo[1]; // ���� ����Ʈ ����Ÿ
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_QUEST_INVENTORY_INFO)
	BYTE					byItemCount;
	sQUEST_INVENTORY_INFO	aInventoryInfo[1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_INFO_END)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_ATTRIBUTE_UPDATE)
	HOBJECT			hHandle;
	BYTE			byAttributeTotalCount;
	BYTE			abyFlexibleField[((UCHAR_MAX - 1) / 8 + 1) + sizeof(sAVATAR_ATTRIBUTE)];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_OBJECT_CREATE)
	HOBJECT			handle;
	sOBJECT_INFO	sObjectInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_OBJECT_DESTROY)
	HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_MOVE)
	HOBJECT			handle;
	//- yoshiki : Do we use dwTimeStamp or not?
	DWORD			dwTimeStamp;
	sVECTOR3		vCurLoc;
	sVECTOR3		vCurDir;
	BYTE			byMoveDirection;
	BYTE			byMoveFlag;		// �ٱ� Ȥ�� �ȱ�(ENtlMovementFlag ����)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_DEST_MOVE)
	HOBJECT			handle;
	//- yoshiki : Do we use dwTimeStamp or not?
	DWORD			dwTimeStamp;
	sVECTOR3		vCurLoc;
	BYTE			byMoveFlag;		// �ٱ� Ȥ�� �ȱ�(ENtlMovementFlag ����)
	bool			bHaveSecondDestLoc;
	sVECTOR3		vSecondDestLoc;
	BYTE			byDestLocCount;
	sVECTOR3		avDestLoc[DBO_MAX_NEXT_DEST_LOC_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_CHANGE_HEADING)
	HOBJECT			handle;
	//- yoshiki : Do we use dwTimeStamp or not?
	DWORD			dwTimeStamp;
	sVECTOR3		vNewHeading;
	sVECTOR3		vNewLoc;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_MOVE_SYNC)
	HOBJECT			handle;
	DWORD			dwTimeStamp;
	sVECTOR3		vCurLoc;
	sVECTOR3		vCurDir;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_CHANGE_JUMP_DIRECTION)
	HOBJECT			handle;
	//- yoshiki : Do we use dwTimeStamp or not?
	DWORD			dwTimeStamp;
	sVECTOR3		vJumpDir;
	//	BYTE			byMoveFlag;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_CHANGE_DIRECTION_ON_FLOATING)
	HOBJECT				hSubject;
	//- yoshiki : Do we use dwTimeStamp or not?
	DWORD				dwTimeStamp;
	sVECTOR3			vCurDir;
	BYTE				byMoveDirection;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_FOLLOW_MOVE)
	HOBJECT			handle;
	//- yoshiki : Do we use dwTimeStamp or not?
	DWORD			dwTimeStamp;
	HOBJECT			hTarget;
	float			fDistance;
	BYTE			byMovementReason;
	BYTE			byMoveFlag;		// �ٱ� Ȥ�� �ȱ�(ENtlMovementFlag ����)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_JUMP)
	HOBJECT			handle;
	sVECTOR3		vCurrentHeading;
	sVECTOR3		vJumpDir;
	BYTE			byMoveDirection;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_JUMP_END)
	HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_PUSHED_NFY)
	HOBJECT			hSubject;
	BYTE			byAttackResult;		// eBATTLE_ATTACK_RESULT
	WORD			wAttackResultValue;
	sVECTOR3		vDestLoc;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_SITDOWN)
	HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_STANDUP)
	HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_FIGHTMODE)
	HOBJECT			handle;
	bool			bFightMode; // ���� �ڼ� On/Off
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_BLOCK_MODE_COOL_TIME_NFY)
	DWORD			dwCoolTimeRemaining;		// in Millisecs.
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_FAINT)
	HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_KNOCKDOWN)
	HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_SLIDING)
	HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_CAMPING)
	HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_CHAR_CONVERT_CLASS )
	HOBJECT			hTarget;
	BYTE			byClass;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_DIALOG)
	HOBJECT				hSubject;				// ��ȭ �ϴ� ĳ���� �ڵ�
	BYTE				byDialogType;			// ��ȭ ���� ( eCHAR_DIALOG_TYPE )
	TBLIDX				textTblidx;				// ��ȭ ���� ���̺� ��ȣ ( INVALID �� �ƴϸ� �ش� �ؽ�Ʈ�� ã�� ����ϰ�, INVALID�� �Ʒ��� �ؽ�Ʈ�� ����� �� ��)
	bool				bIsRefSpeechTable;		// speech table( NPCSpeechTable �� �����ϴ°�? )
	WORD				wTextLen;				// ��ȭ������ ����
	WCHAR				awchText[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1]; // ��ȭ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_CHAR_DIRECT_PLAY )
	HOBJECT				hSubject;				// ���� ĳ���� �ڵ�
	BYTE				byPlayMode;				// ���� ���
	TBLIDX				directTblidx;			// ���� ��ȣ
	bool				bSynchronize;			// ���� Ŭ���̾�Ʈ ����ȭ
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_CHAR_DIRECT_PLAY_END )

END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_CHAR_AWAY_RES )
	bool	bIsAway;		// AwayOn 1: Awayoff: 0
	WORD 	wResultCode;	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_CHAR_MAIL_INFO )
	BYTE	byMailCount;		// ���� ��ü���� ī��Ʈ 
	BYTE	byManagerCount;		// ���� ���� �Ŵ��� ���� ī��Ʈ
	BYTE	byNormalCount;		// ���� ���� ��� ���� ī��Ʈ
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_KEY_INFO)
	BYTE			byCount;
	sSHORTCUT_DATA  asData[NTL_SHORTCUT_MAX_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_RANKBATTLE_SCORE)
	sRANKBATTLE_SCORE_INFO	sScoreInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_KEY_UPDATE_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_ACTION_ATTACK)
	HOBJECT			hSubject; // �׼� ��ü ĳ���� �ڵ�
	HOBJECT			hTarget; // �׼� Ÿ�� ĳ���� �ڵ�
	DWORD			dwLpEpEventId;
	BYTE			bChainAttack:1; // ü�ξ��ÿ���
	BYTE			byAttackResult:7; // �׼� ��� ( eBATTLE_ATTACK_RESULT )
	WORD			wAttackResultValue; // �׼��� ��� �� ( ������ )
	BYTE			byAttackSequence; // ���� ������ ��ȣ (ü�ξ���)
	float			fReflectedDamage; // Ÿ�����κ��� �ݻ�Ǿ� ���� ����
	BYTE			byBlockedAction;		// eDBO_GUARD_TYPE
	sVECTOR3		vShift; // �������� ���� �̵� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_ACTION_SKILL)
	HOBJECT				handle;
	WORD				wResultCode;
	DWORD				dwLpEpEventId;
	TBLIDX				skillId;
	BYTE				byRpBonusType;		// eDBO_RP_BONUS_TYPE
	HOBJECT				hAppointedTarget;
	bool				bIsSkillHarmful;
	BYTE				bySkillResultCount;
	sSKILL_RESULT		aSkillResult[NTL_MAX_NUMBER_OF_SKILL_TARGET];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_ACTION_ITEM)
	HOBJECT				handle;
	WORD				wResultCode;
	DWORD				dwLpEpEventId;
	TBLIDX				itemTblidx;
	BYTE				bySkillResultCount;
	sSKILL_RESULT		aSkillResult[NTL_MAX_NUMBER_OF_SKILL_TARGET];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_REVIVAL_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_TELEPORT_RES)
	WORD			wResultCode;
	sVECTOR3		vNewLoc;
	sVECTOR3		vNewDir;
	bool			bIsToMoveAnotherServer;
	// Data in 'sWorldInfo' will not be sent if the character moves within the current world.
	// ���� ���� �ȿ����� �̵��� ��쿡�� sWorldInfo ����Ÿ�� ������ �ʴ´�.
	// by YOSHIKI(2007-10-25)
	sWORLD_INFO				sWorldInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_BIND_RES)
	WORD			wResultCode;
	BYTE			byBindType;		// eDBO_BIND_TYPE
	WORLDID			bindWorldId;
	TBLIDX			bindObjectTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_SERVER_CHANGE_RES)
	WORD					wResultCode;
	char					achAuthKey[NTL_MAX_SIZE_AUTH_KEY];
	sSERVER_INFO			serverInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_CHANNEL_CHANGE_RES)
	WORD					wResultCode;
	char					achAuthKey[NTL_MAX_SIZE_AUTH_KEY];
	sSERVER_INFO			serverInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_EXIT_RES)
	WORD					wResultCode;
	char					achAuthKey[NTL_MAX_SIZE_AUTH_KEY];
	BYTE					byServerInfoCount;
	sSERVER_INFO			aServerInfo[DBO_MAX_CHARACTER_SERVER_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_SKILL_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GAME_EXIT_RES)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GAME_KICK_NFY)
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_EFFECT_AFFECTED)
	HOBJECT			handle;
	HOBJECT			hCaster;
	TBLIDX			effectTblidx;
	WORD			wResultCode;
	float			fActualArgument1;
	float			fActualArgument2;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_CASTING_CANCELED_NFY)
	HOBJECT			handle;
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_CASTING_DELAYED_NFY)
	HOBJECT			handle;
	WORD			wResultCode;
	DWORD			dwCastingTime;
	DWORD			dwCastingTimeRemaining;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_AFFECTING_CANCELED_NFY)
	HOBJECT			hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_TARGET_LIST_REQ)
	BYTE			byAvatarType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_LEARN_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_LEARNED_NFY)
	TBLIDX			skillId;
	BYTE			bySlot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_UPGRADE_RES)
	WORD			wResultCode;
	TBLIDX			skillId;
	BYTE			bySlot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_RP_BONUS_SETTING_RES)
	WORD			wResultCode;
	TBLIDX			skillId;
	BYTE			bySlotIndex;
	BYTE			byRpBonusType;		// eDBO_RP_BONUS_TYPE
	bool			bIsRpBonusAuto;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_NOTIFY_EXP)
	BYTE			bySlotIndex;
	WORD			wSkillExp;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_AFTEREFFECT_REMAINING_TIME_NFY)
	DWORD			dwTimeRemaining;		// in Millisecs.
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_COOL_TIME_STARTED_NFY)
	HOBJECT			hSubject;
	TBLIDX			skillTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUFF_REGISTERED)
	HOBJECT			hHandle;
	BYTE			bySourceType;		// eDBO_OBJECT_SOURCE
	TBLIDX			tblidx;
	float			afEffectValue[NTL_MAX_EFFECT_IN_SKILL];
	DWORD			dwInitialDuration;		// In Millisecs.
	DWORD			dwTimeRemaining;		// in millisecs.
	bool			bNeedToDisplayMessage;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUFF_DROPPED)
	HOBJECT			hHandle;
	BYTE			bySourceType;		// eDBO_OBJECT_SOURCE
	TBLIDX			tblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUFF_REFRESH_ALL)
	HOBJECT			hHandle;
	BYTE			byCount;
	sBUFF_INFO		aBuffInfo[DBO_MAX_BUFF_CHARACTER_HAS];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUFF_DROP_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_START_RES)
	WORD			wResultCode;
	BYTE			bySkillSlot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_LEARN_RES)
	WORD			wResultCode;
	TBLIDX			skillId;
	BYTE			bySkillSlot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_FORWARD_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_RP_BALL_USE_RES)
	WORD			wResultCode;
	BYTE			byRpBallCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_RP_BALL_USED_NFY)
	HOBJECT			hSubject;
	BYTE			byRpBallCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_RP_BALL_RESULT_DECIDED_NFY)
	HOBJECT			hAttacker;
	HOBJECT			hWinner;
	bool			bHasSubjectRpBallUsed;
	bool			bHasTargetRpBallUsed;
	BYTE			bySubjectRpBallUsed;
	BYTE			byTargetRpBallUsed;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_CREATE)
	HOBJECT			handle;
	sITEM_DATA      sItemData;
	bool			bIsNew;		// Effect �߰� 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_UPDATE)
	HOBJECT			handle;
	sITEM_DATA      sItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_MOVE_RES)
	WORD			wResultCode;
	HOBJECT			hSrcItem;
	HOBJECT			hDestItem;
	BYTE			bySrcPlace;
	BYTE			bySrcPos;
	BYTE			byDestPlace;
	BYTE			byDestPos;	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_MOVE_STACK_RES)
	WORD			wResultCode;
	HOBJECT			hSrcItem;
	HOBJECT			hDestItem;
	BYTE			bySrcPlace;
	BYTE			bySrcPos;
	BYTE			byDestPlace;
	BYTE			byDestPos;	
	BYTE			byStackCount1;//��������� �������� SOURCE
	BYTE			byStackCount2;//��������� �������� DESTINATION
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_DELETE)
	HOBJECT			hSrcItem;
	BYTE			bySrcPlace;
	BYTE			bySrcPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_DELETE_RES)
	WORD			wResultCode;
	BYTE			byPlace;
	BYTE			byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_EQUIP_REPAIR_RES)
	HOBJECT			handle;			// hNpchandle
	WORD			wResultCode;	
	DWORD			dwSpendedZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_REPAIR_RES)
	HOBJECT				hNpchandle;
	WORD				wResultCode;
	HOBJECT				hItem;
	DWORD				dwSpendedZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_USE_RES)
	WORD			wResultCode;
	TBLIDX			tblidxItem;
	BYTE			byPlace;
	BYTE			byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_CASTING_CANCELED)
	HOBJECT			handle;
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_CASTING_DELAYED_NFY)
	HOBJECT			handle;
	WORD			wResultCode;
	DWORD			dwCastingTime;
	DWORD			dwCastingTimeRemaining;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_DUR_DOWN)
	BYTE			byDur[NTL_MAX_EQUIP_ITEM_SLOT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_DUR_UPDATE)
	HOBJECT			hItemHandle;
	BYTE			byDur;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_STACK_UPDATE)
	HOBJECT			hItemHandle;
	BYTE			byStack;
	bool			bIsNew;		// Effect �߰� 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_UPGRADE_RES)
	WORD			wResultCode;
	BYTE			byStack;			// ���� ����� ���ð���					-> ����� ����
	BYTE			byGrade;			// ����� �׷��̵�						-> ����� �׷��̵�
	BYTE			byItemPlace;		// ���׷��̵� �� �������� �����̳� ��ġ
	BYTE			byItemPos;			// ���׷��̵� �� �������� ��ġ
	BYTE			byStonPlace;		// ȣ�����̽��� �����̳� ��ġ
	BYTE			byStonPos;			// ȣ�����̽��� ��ġ
	BYTE			byBattleAttribute;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_IDENTIFY_RES)
	HOBJECT			hItemHandle;
	WORD			wResultCode;
	sITEM_DATA      sItemData;			// �����ÿ��� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_PICK_RES)
	TBLIDX			itemTblidx;
	WORD			wResultCode;
	// Any message doesn't need to be displayed if 'bByPartyHunting' is true.
	// (If a party member picks up an item, the message is displayed by another type of packet.)
	// bByPartyHunting�� true�̸� Ŭ���̾�Ʈ���� �޼����� ����� �ʿ䰡 ����.
	// (��Ƽ ���¿��� drop�� �������� ��� ��쿡�� �ٸ� packet�� ���� �޼����� ��µȴ�.)
	bool			bByPartyHunting;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ZENNY_PICK_RES)
	WORD			wResultCode;
	bool			bSharedInParty;
	DWORD			dwZenny;
	DWORD			dwAcquisitionZenny;
	DWORD			dwBonusZenny;
	// 'dwOriginalZenny' MUST NOT be referred if 'bSharedInParty' is false.
	// bSharedInParty�� false�̸� dwOriginalZenny���� �����ؼ��� �� �ȴ�.
	// by YOSHIKI(2007-10-02)
	DWORD			dwOriginalZenny; //Drop Zenny�̴�.
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_STATE)
	HOBJECT			handle;
	sCHARSTATE		sCharState;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_ASPECT_STATE)
	HOBJECT			handle;
	sASPECTSTATE	aspectState;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_CONDITION)
	HOBJECT			handle;
	DWORD			dwConditionFlag;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_EXP)
	HOBJECT			handle;
	DWORD			dwCurExp;
	DWORD			dwIncreasedExp;
	DWORD			dwAcquisitionExp;
	DWORD			dwBonusExp;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_LEVEL)
	HOBJECT			handle;
	BYTE			byPrevLevel;
	BYTE			byCurLevel;
	DWORD			dwMaxExpInThisLevel;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_SPEED)
	HOBJECT			handle;
	float			fLastWalkingSpeed;
	float			fLastRunningSpeed;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_ATTACK_SPEEDRATE)
	HOBJECT			handle;
	WORD			wAttackSpeedRate;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_ITEM_EQUIP)
	HOBJECT			handle;
	BYTE			byPos;
	sITEM_BRIEF		sItemBrief;		// ���� ���� �Ǿ��� ��� INVALID VALUE�� ��� �´�.
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_ITEM_DELETED)
	HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_TARGET_INFO)
	HOBJECT			handle;
	WORD			wCurLP;
	WORD			wMaxLP;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_LP)
	HOBJECT			handle;
	DWORD			dwLpEpEventId;
	WORD			wCurLP;
	WORD			wMaxLP;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_EP)
	HOBJECT			handle;
	DWORD			dwLpEpEventId;
	WORD			wCurEP;
	WORD			wMaxEP;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_RP)
	HOBJECT			handle;
	WORD			wCurRP;
	WORD			wMaxRP;
	bool			bHitDelay;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_LP_EP)
	HOBJECT			handle;
	DWORD			dwLpEpEventId;
	WORD			wCurLP;
	WORD			wMaxLP;
	WORD			wCurEP;
	WORD			wMaxEP;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_ZENNY)
	HOBJECT			handle;
	DWORD			dwZenny;
	bool			bIsNew;		// Effect �߰�
	BYTE			byChangeType; // eZENNY_CHANGE_TYPE - NtlCharacter.h
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_MUDOSA_POINT)
	DWORD			dwMudosaPoint;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SYSTEM_DISPLAY_TEXT)
	WCHAR			awGMChar[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	BYTE			byDisplayType;				// eSERVER_TEXT_TYPE
	WORD			wMessageLengthInUnicode;
	WCHAR			awchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1]; // ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SYSTEM_DISPLAY_RESULTCODE)
	BYTE			byDisplayType;				// eSERVER_TEXT_TYPE
	WORD			wResultCode;				// ����� ResultCode
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_START_RES)
	HOBJECT			handle;
	BYTE			byType; //	0: �⺻  1:�������� �Ǹ� �̺�Ʈ NPC 
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_BUY_RES)
	HOBJECT			handle;
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_SELL_RES)
	HOBJECT			handle;
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_END_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_SKILL_BUY_RES)
	HOBJECT				hNpchandle;
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CREATE_RES)
	WORD			wResultCode;
	WCHAR			wszPartyName[NTL_MAX_SIZE_PARTY_NAME_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DISBAND_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DISBANDED_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVITE_RES)
	WORD			wResultCode;
	WCHAR			wszTargetName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVITE_NFY)
	bool			bFromPc;
	union
	{
		WCHAR				wszInvitorPcName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
		WCHAR				wszInvitorPartyName[NTL_MAX_SIZE_PARTY_NAME_IN_UNICODE + 1];
	};
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_RESPONSE_INVITATION_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_JOINED_NFY)
	sPARTY_MEMBER_INFO		memberInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INFO)
	WCHAR					awchPartyName[NTL_MAX_SIZE_PARTY_NAME_IN_UNICODE + 1];
	HOBJECT					hLeader;
	BYTE					byItemLootingMethod;
	BYTE					byZennyLootingMethod;
	TBLIDX					registeredCharmTblidx[NTL_PARTY_CHARM_INVENTORY_COUNT];
	DWORD					adwRemainingTime[NTL_PARTY_CHARM_INVENTORY_COUNT];
	sSHARETARGET_INFO		sharetargetInfo[NTL_MAX_SHARETARGET_COUNT];// ����Ÿ�ٵ���Ÿ [3/28/2008 SGpro]
	ePARTY_DUNGEON_STATE	eDiff;
	BYTE					byItemRank;			// ��Ƽ�κ��� ���� �������� eITEM_RANK �߰�
	BYTE					byMemberInfoCount;
	sPARTY_MEMBER_INFO		memberInfo[NTL_MAX_MEMBER_IN_PARTY - 1];	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVENTORY_INFO)
	BYTE								bySlotInfoCount;
	sDBO_PARTY_INVENTORY_SLOT_INFO		inventorySlotInfo[NTL_PARTY_INVENTORY_SLOT_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_OPENED_CHARM_INVENTORY_INFO)
	BYTE							byCharmInventoryIndex;
	sDBO_PARTY_VICTIM_ITEM_INFO		victimItemInfo;
	DWORD							dwTotalVictimZenny;
	BYTE							byVictimInfoCount;
	sDBO_VICTIM_INFO				aVictimInfo[NTL_MAX_MEMBER_IN_PARTY - 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVITATION_DECLINED_NFY)
	WCHAR			wszPlayerName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVITATION_EXPIRED_NFY)
	WCHAR			wszPlayerName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_LEAVE_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_LEFT_NFY)
	HOBJECT			hMember;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_KICK_OUT_RES)
	WORD			wResultCode;
	HOBJECT			hTargetMember;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_KICKED_OUT_NFY)
	HOBJECT			hMember;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHANGE_LEADER_RES)
	WORD			wResultCode;
	HOBJECT			hNewLeader;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_LEADER_CHANGED_NFY)
	HOBJECT					hNewLeader;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_LEVELED_UP_NFY)
	HOBJECT			hMember;
	BYTE			byLevel;
	WORD			wMaxLP;
	WORD			wMaxEP;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_CLASS_CHANGED_NFY)
	HOBJECT			hMember;
	BYTE			byNewClass;		// ePC_CLASS
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_OPEN_CHARM_SLOT_RES)
	WORD			wResultCode;
	BYTE			byCharmInventoryIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_SLOT_OPENED_NFY)
	BYTE			byCharmInventoryIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CLOSE_CHARM_SLOT_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_SLOT_CLOSED_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_REGISTER_VICTIM_ITEM_RES)
	WORD			wResultCode;
	BYTE			bySrcPlace;
	BYTE			bySrcPos;
	BYTE			byDestSlotIndex;
	DWORD			dwTotalVictimItemScore;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_VICTIM_ITEM_REGISTERED_NFY)
	HOBJECT			hMember;
	sDBO_PARTY_VICTIM_ITEM_INFO		itemInfo;
	DWORD			dwTotalVictimItemScore;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_UNREGISTER_VICTIM_ITEM_RES)
	WORD			wResultCode;
	BYTE			byDestSlotIndex;
	DWORD			dwTotalVictimItemScore;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_VICTIM_ITEM_UNREGISTERED_NFY)
	HOBJECT			hMember;
	TBLIDX			itemTblidx;
	BYTE			byDestSlotIndex;
	DWORD			dwTotalVictimItemScore;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_REGISTER_VICTIM_ZENNY_RES)
	WORD			wResultCode;
	DWORD			dwRegisteredZenny;
	DWORD			dwReturningZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_VICTIM_ZENNY_REGISTERED_NFY)
	HOBJECT			hMember;
	DWORD			dwIncreasedZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_UNREGISTER_VICTIM_ZENNY_RES)
	WORD			wResultCode;
	DWORD			dwUnregisteredZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_VICTIM_ZENNY_UNREGISTERED_NFY)
	HOBJECT			hMember;
	DWORD			dwDecreasedZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DECLARE_ZENNY_RES)
	WORD							wResultCode;

	DWORD							dwInitialZenny;
	DWORD							dwFinalDeclaredZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DECLARED_ZENNY_CHANGED_NFY)
	HOBJECT							hMember;
	DWORD							dwDeclaredZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_ACTIVATION_FAILED_NFY)
	WORD							wResultCode;
	HOBJECT							hMember;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_ACTIVATE_CHARM_RES)
	WORD			wResultCode;
	BYTE							byCharmInventoryIndex;
	TBLIDX							registeredCharmTblidx;
	DWORD							dwRemainingTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_ACTIVATED_NFY)
	BYTE							byCharmInventoryIndex;
	TBLIDX							registeredCharmTblidx;
	DWORD							dwRemainingTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DEACTIVATE_CHARM_RES)
	WORD							wResultCode;
	BYTE							byCharmInventoryIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_DEACTIVATED_NFY)
	BYTE							byCharmInventoryIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHANGE_ZENNY_LOOTING_METHOD_RES)
	WORD							wResultCode;
	BYTE							byNewLootingMethod;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_ZENNY_LOOTING_METHOD_CHANGED_NFY)
	BYTE							byNewLootingMethod;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHANGE_ITEM_LOOTING_METHOD_RES)
	WORD							wResultCode;
	BYTE							byNewLootingMethod;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_ITEM_LOOTING_METHOD_CHANGED_NFY)
	BYTE							byNewLootingMethod;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_ZENNY_LOOTING_METHOD_UNLOCKED_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_ITEM_LOOTING_METHOD_UNLOCKED_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_ZENNY_UPDATED_NFY)
	BYTE byMemberCount;
	sINVEST_ZENNY_INFO aZennyInfo[NTL_MAX_MEMBER_IN_PARTY];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVENTORY_ITEM_ADDED_NFY)
	BYTE							bySlotIndex;
	sPARTY_INVENTORY_ITEM_INFO		newLoot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVENTORY_ITEM_REMOVED_NFY)
	BYTE					byPos;
	bool					bIsYourItem;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_GAINED_ITEM_NFY)
	HOBJECT					hMember;
	// If itemTblidx is INVALID_TBLIDX, this means an unidentified item.
	// itemTblidx�� INVALID_TBLIDX�� ���, ������ �ʿ��� ���������� ���Ѵ�.
	// by YOSHIKI(2006-11-02)
	TBLIDX					itemTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_GAINED_ZENNY_NFY)
	HOBJECT					hMember;
	bool					bIsShared;
	DWORD					dwZenny; //dwAcquisitionZenny + dwBonusZenny
	DWORD					dwAcquisitionZenny;
	DWORD					dwBonusZenny;

	// 'dwOriginalZenny' MUST NOT be referred if 'bSharedInParty' is false.
	// bSharedInParty�� false�̸� dwOriginalZenny���� �����ؼ��� �� �ȴ�.
	// by YOSHIKI(2007-10-02)
	DWORD					dwOriginalZenny; //Mob�� Drop�� Zenny
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEST_ZENNY_RES)
	WORD					wResultCode;
	BYTE					byPos;
	DWORD					dwInvestedZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEST_ZENNY_NFY)
	BYTE					byPos;
	DWORD					dwInvestedZenny;
	HOBJECT					hMember;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVENTORY_ITEM_WINNER_CHANGED_NFY)
	BYTE					byPos;
	HOBJECT					hWinner;
	DWORD					dwInvestedZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_LOCATION_NFY)
	HOBJECT					hMember;
	TBLIDX					worldTblidx;
	WORLDID					worldId;
	sVECTOR3				vCurLoc;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_START_RES)
	HOBJECT			handle;			// Npc handle
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_MOVE_RES)
	HOBJECT			handle;
	HOBJECT			hSrcItem;
	HOBJECT			hDstItem;
	BYTE			bySrcPlace;
	BYTE			bySrcPos;
	BYTE			byDestPlace;
	BYTE			byDestPos;
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_MOVE_STACK_RES)
	HOBJECT			handle;
	HOBJECT			hSrcItem;
	HOBJECT			hDestItem;
	BYTE			bySrcPlace;
	BYTE			bySrcPos;
	BYTE			byDestPlace;
	BYTE			byDestPos;
	BYTE			byStackCount1;
	BYTE			byStackCount2;
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_END_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_ZENNY_INFO)
	DWORD			dwZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_ITEM_INFO)
	BYTE			byBeginCount;
	BYTE			byItemCount;
	sITEM_PROFILE	aBankProfile[NTL_MAX_COUNT_USER_HAVE_BANK_ITEM];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_ZENNY_RES)
	HOBJECT				handle;
	WORD				wResultCode;
	DWORD				dwZenny;
	bool				bIsSave;		// 1: ���� 0: ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_BUY_RES)
	HOBJECT				hNpchandle;
	WORD				wResultCode;
	HOBJECT				hItemhandle;
	sITEM_DATA			sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_ITEM_DELETE_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SOCIAL_ACTION)
	HOBJECT			hSubject;
	TBLIDX			socialActionId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_INDICATOR_RES)
	HOBJECT			hTarget;
	WORD			wResultCode;
	DWORD			dwRetValue;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_PREDICT_RES)
	BYTE			byPusNum;
	WORD			wResultCode;
	BYTE			byRetRate;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_EQUIP_CHECK_RES)
	HOBJECT			hTarget;
	WORD			wResultCode;
	BYTE			byItemCount;
	sITEM_PROFILE	aItemProfile[NTL_MAX_EQUIP_ITEM_SLOT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_CHIP_REMOVE_ALL_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_CONFIRM_STEP_RES)
	BYTE				byTsType; // Ʈ���� Ÿ��
	WORD				wResultCode;
	NTL_TS_T_ID			tId;
	NTL_TS_TC_ID		tcCurId;
	NTL_TS_TC_ID		tcNextId;
	DWORD				dwParam;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_UPDATE_SYNC_NFY)
	BYTE				byTsType; // Ʈ���� Ÿ��
	NTL_TS_T_ID			tId;
	NTL_TS_TC_ID		tcId;
	NTL_TS_TA_ID		taId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_UPDATE_STATE)
	BYTE				byTsType; // Ʈ���� Ÿ��
	NTL_TS_T_ID			tId;
	BYTE				byType;
	WORD				wTSState;
	DWORD				dwParam;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_UPDATE_EVENT_NFY)
	BYTE				byTsType; // Ʈ���� Ÿ��
	NTL_TS_EVENT_ID		teid;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_EXCUTE_TRIGGER)
	BYTE				byTsType; // Ʈ���� Ÿ��
	NTL_TS_T_ID			tId; // Ʈ���� ���̵�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_EXCUTE_TRIGGER_OBJECT_RES)
	WORD				wResultCode;
	HOBJECT				hTriggerObject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_TRIGGER_OBJECT_DIALOG_NFY)
	HOBJECT				hTriggerObject;
	BYTE				byDialogType;		// eNPCCONV_TYPE
	TBLIDX				textTblidx;			// text
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_PC_DIALOG_NFY)
	TBLIDX				textTblidx;			// text
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_SKIP_CONTAINER)
	NTL_TS_T_ID			tId;
	NTL_TS_TC_ID		tcId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_ITEM_CREATE_NFY)
	BYTE				byPos;
	TBLIDX				qItemTblidx;
	BYTE				byCurCount;			// ���� ī��Ʈ
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_ITEM_DELETE_NFY)
	BYTE				byDeletePos;		// ������ �������� ��ġ
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_ITEM_UPDATE_NFY)
	BYTE				byPos;
	BYTE				byCurCount;			// ���� ī��Ʈ
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_ITEM_MOVE_RES)
	WORD				wResultCode;
	BYTE				bySrcPos;
	TBLIDX				dwSrcTblidx;
	BYTE				byDestPos;
	TBLIDX				dwDestTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_ITEM_DELETE_RES)
	WORD				wResultCode;
	BYTE				byDeletePos;		// ������ �������� ��ġ
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_SVREVT_START_NFY)
	NTL_TS_T_ID				tId;
	NTL_TS_TC_ID			tcId;
	NTL_TS_TA_ID			taId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_SVREVT_END_NFY)
	NTL_TS_T_ID				tId;
	NTL_TS_TC_ID			tcId;
	NTL_TS_TA_ID			taId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_SVREVT_UPDATE_NFY)
	NTL_TS_T_ID				tId;
	NTL_TS_TC_ID			tcId;
	NTL_TS_TA_ID			taId;
	BYTE					bySvrEvtType;		// eSTOC_EVT_DATA_TYPE
	BYTE					bySlot;
	uSTOC_EVT_UPDATE_DATA	uEvtData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_GIVEUP_RES)
	NTL_TS_T_ID			tId;
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_SHARE_NFY)				// ����Ʈ ����
	WORD				wResultCode;
	NTL_TS_T_ID			tId;
	HOBJECT				hActor;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_RESET_NFY)			// ����Ʈ�� ������ ������ŭ ���� ������ �Ϸ� ������ �����Ѵ�.
	QUESTID				startResetQID;		// ���� ����
	QUESTID				endResetQID;		// ���� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_OBJECT_VISIT_RES)
	WORD				wResultCode;

	QUESTID				qId;
	WORLDID				worldId;
	BYTE				byObjType;
	TBLIDX				objectTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_FORCED_COMPLETION_NFY)
	QUESTID				questId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_FREEBATTLE_CHALLENGE_RES)
	HOBJECT				hTarget; // ������ ��û�ߴ� Ÿ���� �ڵ�
	WORD				wResultCode; // ���� �ڵ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_FREEBATTLE_ACCEPT_REQ)
	HOBJECT				hChallenger; // ������ ��û�� ĳ������ �ڵ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_FREEBATTLE_CANCEL_NFY)
	WORD				wResultCode; // ������ҿ� ���� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_FREEBATTLE_START_NFY)
	HOBJECT				hTarget; // ������� �ڵ�
	sVECTOR3			vRefreeLoc;	// ���� ��ġ
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_FREEBATTLE_OUTSIDE_NFY)

END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_FREEBATTLE_INSIDE_NFY)

END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_FREEBATTLE_END_NFY)
	BYTE				byFreeBattleResult; // eFREEBATTLE_RESULT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUICK_SLOT_UPDATE_RES)  
	WORD				wResultCode;
	TBLIDX				tblidx;
	BYTE				bySlotID;
	BYTE				byType;
	BYTE				byPlace;
	BYTE				byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUICK_SLOT_DEL_NFY)  
	BYTE				bySlotID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUICK_SLOT_INFO)  
	BYTE				byQuickSlotCount;
	sQUICK_SLOT_PROFILE	asQuickSlotData[NTL_CHAR_QUICK_SLOT_MAX_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PET_CHAR_INFO)
	HOBJECT				handle;
	BYTE				byObjectType;		// eOBJTYPE
	union
	{
		sSUMMON_PET_PROFILE		sSummonPetProfile;
		sITEM_PET_PROFILE		sItemPetProfile;
	};
	WORD				wCharStateSize; //-[9/7/2006 zeroera] : ���� : Ŭ���̾�Ʈ�� ���� ĳ���ͻ��� ������ ����
	sCHARSTATE			sCharState;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PET_SKILL_INFO)
	BYTE				bySkillCount;
	sSKILL_INFO_PET		aSkillInfo[NTL_MAX_NPC_HAVE_SKILL];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PET_INFO_END)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PET_DESPAWNED_NFY)
	BYTE				byAvatarType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PET_DISMISS_PET_RES)
	WORD				wResultCode;
	BYTE				byAvatarType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ACTION_REPORT_MESSAGE)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_START_NFY)
	HOBJECT				handle;			// ��û�� �ڵ�
	HOBJECT				hTarget;		// Ÿ�� �ڵ�  (�ڱ� �ڽ�)
	WORD				wResultCode;	// Ÿ���� ����� ���� ���� �� ���� �������� �����
	BYTE				byEmptyInven;	// ����� �κ��� �����	(���� �ִ�ĭ���� ������ ��Ȱ��ĭ�� ǥ��)	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_START_RES)
	HOBJECT				handle;			// ��û�� �ڵ� (�ڱ� �ڽ�)
	HOBJECT				hTarget;		// Ÿ�� �ڵ�
	WORD				wResultCode;	// Ÿ���� ����� ���� ���� �� ���� �������� �����
	BYTE				byEmptyInven;	// ����� �κ��� �����	(���� �ִ�ĭ���� ������ ��Ȱ��ĭ�� ǥ��)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_OK_REQ)
	HOBJECT				handle;			// ��û���� �ڵ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_ADD_NFY)			// ������ ����
	//HOBJECT				hTarget;			// Ÿ�� �ڵ�
	HOBJECT				hItem;				// ��� ������ �ڵ�
	sITEM_DATA			sItem;				// ��밡 �÷� ���� �������� ����
	BYTE				byCount;			// �����ִ� �������� ��ΰ�? Default 1��
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_ADD_RES)
	//HOBJECT				hTarget;			// Ÿ�� �ڵ�
	HOBJECT				hItem;				// �� ������ �ڵ�
	BYTE				byCount;			// �����ִ� �������� ��ΰ�? Default 1��
	WORD				wResultCode;		// Ÿ���� ����� ���� ���� �� ���� �������� �����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_DEL_NFY)			// ������ ����
	//HOBJECT				hTarget;			// Ÿ�� �ڵ�
	HOBJECT				hItem;				// ��� ������ �ڵ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_DEL_RES)
	//HOBJECT				hTarget;			// Ÿ�� �ڵ�
	HOBJECT				hItem;				// �� ������ �ڵ�
	WORD				wResultCode;		// Ÿ���� ����� ���� ���� �� ���� �������� �����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_MODIFY_NFY)
	HOBJECT				hTarget;			// Ÿ�� �ڵ�
	HOBJECT				hItem;				// �� ������ �ڵ�
	BYTE				byCount;			// �����ִ� �������� ��ΰ�? Default 1��
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_MODIFY_RES)
	HOBJECT				hTarget;			// Ÿ�� �ڵ�
	HOBJECT				hItem;				// �� ������ �ڵ�
	BYTE				byCount;			// �����ִ� �������� ��ΰ�? Default 1��
	WORD				wResultCode;		// Ÿ���� ����� ���� ���� �� ���� �������� �����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_ZENNY_UPDATE_NFY)	// ������ ����
	HOBJECT				hTarget;			// Ÿ�� �ڵ�
	DWORD				dwZenny;			// �ű� ��ŭ�� ���� (�ڱⰡ ���� �ִ� ���� �ѵ� ��)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_ZENNY_UPDATE_RES)
	HOBJECT				hTarget;			// Ÿ�� �ڵ�
	DWORD				dwZenny;			// �ű� ��ŭ�� ���� (�ڱⰡ ���� �ִ� ���� �ѵ� �� ����� ���ϰ� ���� �Ǹ� �ڵ� ����)
	WORD				wResultCode;		// Ÿ���� ����� ���� ���� �� ���� �������� �����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_END_NFY)
	HOBJECT				hTarget;			// Ÿ�� �ڵ�
	WORD				wResultCode;		// Ÿ���� ����� ���� ���� �� ���� �������� �����
	bool				bIsSet;				// false: Ǯ�� true: ���
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_END_RES)
	HOBJECT				hTarget;			// Ÿ�� �ڵ�
	DWORD				dwPacketCount;		// ������ ���� ī��Ʈ ( ������ ������ �÷����ų� ���� Ȥ�� ���� �� ��Ŷ���� ���� )
	WORD				wResultCode;		// Ÿ���� ����� ���� ���� �� ���� �������� �����
	bool				bIsSet;				// false: Ǯ�� true: ���
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_CANCEL_NFY)
	HOBJECT				hTarget;			// Ÿ�� �ڵ�
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_CANCEL_RES)
	HOBJECT				hTarget;			// Ÿ�� �ڵ�
	WORD				wResultCode;		// Ÿ���� ����� ���� ���� �� ���� �������� �����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_DENY_RES)
	bool				bIsDeny;			// ���� ������ 
	WORD				wResultCode;		// ���� ��ȯ���̶�� �����Ѵ�. �׿� ���� �� ���
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_NAME_CHANGED_NFY)
	HOBJECT				hSubject;
	WCHAR				wszGuildName[NTL_MAX_SIZE_GUILD_NAME_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_CREATE_RES)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_INVITE_RES)
	WORD				wResultCode;
	WCHAR				wszTargetName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TOBJECT_UPDATE_STATE)
	HOBJECT				handle;
	sTOBJECT_BRIEF		tobjectBrief;
	sTOBJECT_STATE		tobjectState;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TOBJECT_ACTION_ATTACK)
	HOBJECT				hSubject;				// �׼� ��ü ĳ���� �ڵ�
	HOBJECT				hTarget;				// �׼� Ÿ�� ĳ���� �ڵ�
	BYTE				byAttackType;			// �׼� ��� ( eBATTLE_ATTACK_RESULT )
	BYTE				byAttackResult;			// �׼� ��� ( eBATTLE_ATTACK_RESULT )
	WORD				wAttackResultValue;		// �׼��� ��� �� ( ������ )
	sVECTOR3			vShift;					// �������� ���� �̵� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TUTORIAL_HINT_UPDATE_RES)
	WORD				wResultCode;
	DWORD				dwTutorialHint;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_ROOM_LIST_RES )
	WORD					wResultCode;			// �����ڵ�
	sTIMEQUEST_ROOM_TMQ_INFO	sTMQInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_ROOM_INFO_RES )
	WORD					wResultCode;			// �����ڵ�
	BYTE						byRoomState;			// eTIMEQUEST_ROOM_STATE
	uTIMEQUEST_ROOM_ICON_INFO	sIconInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_ROOM_JOIN_RES )
	WORD					wResultCode;			// �����ڵ�
	sTIMEQUEST_ROOM_JOIN_INFO	sJoinInfo;
	HOBJECT						hTroubleMember;			// join�� ������ pc�� �ڵ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_ROOM_JOIN_NFY )
	sTIMEQUEST_ROOM_JOIN_INFO	sJoinInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_ROOM_LEAVE_RES )
	WORD					wResultCode;			// �����ڵ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_ROOM_LEAVE_NFY )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_ROOM_SELECTION_NFY )
	bool							bIsSecondWinner;
	uTIMEQUEST_ROOM_SELECTION_INFO	uSelectionInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_ROOM_TELEPORT_RES )
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_START_NFY )			
	WORD					wResultCode;			// ��� �ڵ� ( ���� �� ���� ����, �ݵ�� Ȯ���� ��)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_START_EXCEPTION_NFY )			
	WORD					wResultCode;			// ��� �ڵ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_LEAVE_NFY )
	HOBJECT					handle;					// ������ ����� �ڵ�
	WORD					wResultCode;			// ������ ��Ÿ���� ���� �ڵ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_COUNTDOWN_NFY )
	bool					bCountDown;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_REWARD_NFY )
	BYTE					byTriggerType;			// ���� ���� tsŸ�� ����
	NTL_TS_EVENT_ID			teid;					// ���� ���� ts�̺�Ʈ ����
	DWORD					dwWaitTime;				// Reward Wait �ð�
	DWORD					dwClearTime;			// Ŭ���� �ð�
	DWORD					dwBonusTime;			// ���ʽ� �ð�
	bool					bIsDayRecord : 1;			// DayRecord�� ������ ��� true
	bool					bIsBestRecord : 1;			// ����Ʈ ���ڵ带 ������ ��쿡�� true
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_INFORMATION_NFY )
	BYTE					byInfoType;				// ���� Ÿ�� eTIMEQUEST_INFORMATION_TYPE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TELECAST_MESSAGE_BEG_NFY )
	TBLIDX					npcTblidx;				// ����� �ϴ� NPC ���̺� �ε���
	BYTE					byTelecastType;			// ��� Ÿ�� eTELECAST_MESSAGE_TYPE
	TBLIDX					speechTblidx;			// ��۳����� ���� Speech ���̺� �ε���
	DWORD					dwDisplayTime;			// ��۽ð��� ��Ÿ���� millisec ( INVALID_DWORD �̸� telecast�� ��� ����, �ƴϸ� �� �ð��� ������ ���� �� )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TELECAST_MESSAGE_END_NFY )

END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_BROAD_MESSAGE_BEG_NFY )
	BYTE byUIDirType;			// eBROAD_MSG_UI_DIR_TYPE
	BYTE byUIShowHideTypel;		// eBROAD_MSG_UI_SHOWHIDE_DIR_TYPE
	BYTE byUIBalloonShapeType;	// eBROAD_MSG_UI_BALLOON_SHAPE_TYPE
	BYTE byUISpeechDirType;		// eBROAD_MSG_UI_SPEECH_DIR_TYPE
	BYTE byOwnerCondition;		// eBROAD_MSG_OWNER_CONDITION
	BYTE byOwnerType;			// eBROAD_MSG_OWNER_TYPE
	unsigned int uiOwnerTblIdx;
	unsigned int uiQuestTextTblidx;
	float fDisplayTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_BROAD_MESSAGE_END_NFY )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MINI_NARRATION_NFY )
	unsigned int uiNarrtionTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PROGRESS_MESSAGE_NFY )
	BYTE					byProgressType;			// ���� Ÿ�� ePROGRESS_MESSAGE_TYPE
	BYTE					byMessageType;			// �޽��� Ÿ�� eTIMEQUEST_MESSAGE_TYPE
	BYTE					byMessageValue;			// �޽����� �� 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_DIRECTION_INDICATE_NFY )
	bool					bIndicate;				// true : Arrow On, false : Arrow Off
	sVECTOR3				vLoc;					// ������ġ ( Off �ϰ�� Access���� ���� )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_UPDATE_GAME_STATE )
	sTIMEQUEST_STATE		sTimeQuestState;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_UPDATE_KILL_COUNT )
	HOBJECT					handle;					// Ÿ�� ����Ʈ �߿� ������ 
	BYTE					byKillCount;			// 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_UPDATE_COUPON_COUNT )
	BYTE					byCouponCount;			// Ÿ�� ����Ʈ ���� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_UPDATE_TMQ_POINT )
	WORD					wTmqPoint;				// Ÿ�� ����Ʈ TMQ ����Ʈ
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TIMEQUEST_UPDATE_GAME_TIME )
	DWORD					dwClearTime;			// Ÿ�� ����Ʈ Ŭ���� �ð� ( �����Ǵ� �ð� )
	DWORD					dwBonusTime;			// Ÿ�� ����Ʈ ���ʽ� �ð�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_INFO_RES )
	WORD					wResultCode;

	BYTE					byBattleMode;		// eRANKBATTLE_MODE
	DWORD					dwRemainTime;		// ���� �ð�
	BYTE					byArenaCount;
	sRANKBATTLE_ARENA_INFO	asArenaInfo[1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_JOIN_RES )
	WORD					wResultCode;

	HOBJECT					hBoardObject;
	TBLIDX					rankBattleTblidx;
	DWORD					dwRemainTime;		// ���� �ð�
	BYTE					byArenaCount;
	sRANKBATTLE_ARENA_INFO	asArenaInfo[1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_JOIN_NFY )
	TBLIDX					rankBattleTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_LEAVE_RES )
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_LEAVE_NFY )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_MATCH_START_NFY )
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_MATCH_CANCELED_NFY )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_ROOM_LIST_RES )
	WORD					wResultCode;

	TBLIDX					rankBattleTblidx;	// RankBattle Tblidx

	WORD					wTotalPage;			// �Խ��� �� ������
	WORD					wCurPage;			// �Խ��� ��� Page

	BYTE					byRoomMode;			// RankBattle ��� : eRANKBATTLE_MODE
	BYTE					byRoomCount;		// �����ϴ� Room�� ����

	uRANKBATTLE_ROOMINFO_LIST	uRoomList;		// Room List
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_ROOM_INFO_RES )
	WORD						wResultCode;

	// ��Ŷ ������ ��꿡 �����Ѵ�.
	// if( RANKBATTLE_MODE_INDIVIDUAL == byBattleMode )
	// {
	//		wMsgSize = sizeof(sGU_RANKBATTLE_ROOM_INFO_RES) - sizeof(uRANKBATTLE_ROOMINFO) + sizeof(sRANKBATTLE_ROOMINFO_INDIVIDUAL);
	// }
	// else if (RANKBATTLE_MODE_PARTY == byBattleMode )
	// {
	//		wMsgSize = sizeof(sGU_RANKBATTLE_ROOM_INFO_RES) - sizeof(uRANKBATTLE_ROOMINFO) + sizeof(sRANKBATTLE_ROOMINFO_PARTY) + sizeof(sRANKBATTLE_ROOMINFO_MEMBER) * (msg->uRoom.sParty.byMemberCount - 1);
	// }

	BYTE						byRoomMode;		// eRANKBATTLE_MODE
	uRANKBATTLE_ROOMINFO		uRoom;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_ROOM_CREATE_RES )
	WORD						wResultCode;
	TBLIDX						rankBattleTblidx;	// RankBattle Tblidx
	ROOMID						roomId;
	BYTE						byTroubleCount;		// ������ ������ ����� ��
	sRANKBATTLE_MEMBER_RESULT	asTroublePc[1];		// ������ ������ ��� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_ROOM_CREATE_NFY )
	WORD				wResultCode;
	TBLIDX				rankBattleTblidx;	// RankBattle Tblidx
	ROOMID				roomId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_ROOM_LEAVE_RES )
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_ROOM_LEAVE_NFY )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_ROOM_JOIN_INFO_NFY )
	TBLIDX				rankBattleTblidx;	// RankBattle Tblidx
	ROOMID				roomId;
	BYTE				byTeamType;			// eRANKBATTLE_TEAM_TYPE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_ROOM_CHALLENGE_RES )
	WORD						wResultCode;
	TBLIDX						rankBattleTblidx;	// RankBattle Tblidx
	ROOMID						roomId;				// �� ��ȣ
	BYTE						byTroubleCount;		// ������ ������ ����� ��
	sRANKBATTLE_MEMBER_RESULT	asTroublePc[1];		// ������ ������ ��� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_ROOM_CHALLENGE_NFY )
	WORD				wResultCode;
	TBLIDX				rankBattleTblidx;	// RankBattle Tblidx
	ROOMID				roomId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_ROOM_MATCH_READY_NFY )
	WORD						wResultCode;
	BYTE						byMemberCount;		// ��� ��
	sRANKBATTLE_MEMBER_RESULT	asMemberResult[1];	// ��� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_ROOM_MATCH_START_NFY )
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_ROOM_MATCH_CANCEL_RES )
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_ROOM_MATCH_CANCELED_NFY )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_BATTLE_STATE_UPDATE_NFY )
	BYTE				byBattleState;
	BYTE				byStage;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_BATTLE_TEAM_INFO_NFY )
	WORD				wStraightWinCount;		// ���� ī��Ʈ
	WORD				wStraightKOWinCount;	// KO ���� ī��Ʈ
	BYTE				byCount;				// �ο�
	WORD				wMemberInfo;			// sRANKBATTLE_MATCH_MEMBER_INFO [byCount]
	WORD				wOwnerPartyName;		// WCHAR [NTL_MAX_SIZE_PARTY_NAME_IN_UNICODE]
	WORD				wChallengerPartyName;	// WCHAR [NTL_MAX_SIZE_PARTY_NAME_IN_UNICODE]
	sVARIABLE_DATA		sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_BATTLE_PLAYER_STATE_NFY )
	HOBJECT				hPc;
	BYTE				byPCState;	// eRANKBATTLE_MEMBER_STATE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_BATTLE_KILLSCORE_UPDATE_NFY )
	BYTE				byOwnerKillScore;
	BYTE				byChallengerKillScore;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_BATTLE_STAGE_FINISH_NFY )
	BYTE				byBattleResult;			// eRANKBATTLE_MATCH_RESULT
	sRANKBATTLE_SCORE	sStageScore;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_BATTLE_MATCH_FINISH_NFY )
	sRANKBATTLE_MATCH_FINISH_INFO	sMatchResult;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_BATTLE_END_NFY )
	BYTE					byMatchWinner;		// eRANKBATTLE_MATCH_RESULT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_BATTLE_FORCED_LEAVE_NFY )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_RANKBATTLE_TOTAL_SCORE_UPDATE_NFY )
	BYTE					byBattlemode;
	sRANKBATTLE_SCORE_INFO	sTotalScore;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_DRAGONBALL_CHECK_RES )// �巡�ﺼ UI 7�� ��ġOK
	HOBJECT				hObject;			// TS Object ����	
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_DRAGONBALL_REWARD_RES )// �巡�ﺼ �� ������ ���� ���� ���� ��û
	HOBJECT				hObject;			// TS Object ����
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_DRAGONBALL_COLLECT_NFY ) // ������ �Ϲ����� �뺸
	HOBJECT				hObject;			// TS Object ����
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_DRAGONBALL_SCHEDULE_INFO )
	bool						bIsAlive;			// �Ⱓ ���� false: �Ⱓ�� �ƴϴ�
	BYTE						byEventType;		// eSCHEDULE_EVENT_TYPE
	__int64						nStartTime;			// ���ʱⰣ ����
	__int64						nEndTime;           // ������ �Ⱓ ������ �ð�
	DWORD						dwMainTerm;			// �Ⱓ ���� (���� ������ �������� ��) 
	DWORD						dwSubTerm;			// �Ⱓ ���� (���� ������ �������� ��) 
	BYTE						byTermType;			// 0: �� 1: �� 2: ��
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_CREATE_RES )
	WORD		 				wResultCode;
	sPACKET_PRIVATESHOP_SHOP_DATA		sPrivateShopData;
	//Private Shop Item���� GU_PRIVATESHOP_ITEM_DATA_INFO�� ������
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_CREATE_NFY )
	HOBJECT							hOwner;
	sSUMMARY_PRIVATESHOP_SHOP_DATA	sSummaryPrivateShopData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_EXIT_RES )
	WORD						wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_OPEN_RES )
	WORD						wResultCode;
	sSUMMARY_PRIVATESHOP_SHOP_DATA	sSummaryPrivateShopData;
	BYTE							byNoticeSize;
	WCHAR							wcNotice[NTL_MAX_PRIVATESHOP_NOTICE_IN_UNICODE + 1];
	//wcNotice�� �����̱� ������ wcNotice �ؿ��� ���ο� ������ �����ϸ� ����� �ȵȴ�.
	//�ݵ�� byNoticeSize���� ���� ������ �Ұ�.[10/2/2007 SGpro]
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_OPEN_NFY )
	HOBJECT							hOwner;//���� ���� CharacterID
	sSUMMARY_PRIVATESHOP_SHOP_DATA	sSummaryPrivateShopData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_CLOSE_RES )
	WORD						wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_CLOSE_NFY )
	HOBJECT						hOwner;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_ITEM_INSERT_RES )
	WORD						wResultCode;
	sPRIVATESHOP_ITEM_DATA		sPrivateShopItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_ITEM_UPDATE_RES )
	WORD						wResultCode;
	DWORD						dwZenny;
	BYTE						byPrivateShopInventorySlotPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_ITEM_DELETE_RES )
	WORD						wResultCode;
	sPRIVATESHOP_ITEM_DATA		sPrivateShopItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_ITEM_BUYING_RES )
	WORD						wResultCode;
	sPRIVATESHOP_ITEM_DATA		sPrivateShopItemData[NTL_MAX_BUY_SHOPPING_CART];
	BYTE						byBuyItemCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_ITEM_BUYING_NFY )
	HOBJECT						hPrivateShopOwner;
	sPRIVATESHOP_ITEM_DATA		sPrivateShopItemData[NTL_MAX_BUY_SHOPPING_CART];
	BYTE						byBuyItemCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_ENTER_RES )
	WORD						wResultCode;
	sPACKET_PRIVATESHOP_SHOP_DATA		sPrivateShopData;
//Private Shop Item���� GU_PRIVATESHOP_ITEM_DATA_INFO�� ������
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_LEAVE_RES )
	WORD						wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_ITEM_DATA_INFO)
	WORD						wResultCode;
	HOBJECT						hOwnerID;
	sPRIVATESHOP_ITEM_DATA		sPrivateShopItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_ITEM_SELECT_RES )
	WORD				wResultCode;
	//HOBJECT				hOwner;
	BYTE				byPrivateShopInventorySlotPos;
	BYTE				byItemState;//eITEMSTATE ���� ���´�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_ITEM_SELECT_NFY )
	//HOBJECT				hOwner;
	BYTE				byPrivateShopInventorySlotPos;
	BYTE				byItemState;//eITEMSTATE ���� ���´�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_ITEM_STATE_NFY )
	//HOBJECT				hOwner;
	BYTE				abyPrivateShopItemState[NTL_MAX_PRIVATESHOP_INVENTORY];
	int					nPrivateShopItemStateCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_LEAVE_NFY )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_BUSINESS_REQUEST_RES )
	WORD						wResultCode;
	BYTE						byPrivateShopInventorySlotPos;
	BYTE						byItemState;//eITEMSTATE ���� ���´�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_BUSINESS_REQUEST_NFY )
	HOBJECT						hOwner;
	BYTE						byPrivateShopInventorySlotPos;
	BYTE						byItemState;//eITEMSTATE ���� ���´�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_BUSINESS_CONSENT_REQ )
	HOBJECT						hVisitorID;
	BYTE						byPrivateShopInventorySlotPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_BUSINESS_CONSENT_NFY )
	HOBJECT						hOwner;
	BYTE						byPrivateShopInventorySlotPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_BUSINESS_WAITTIMEOUT_NFY )
	HOBJECT						hOwner;
	BYTE						byPrivateShopInventorySlotPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_BUSINESS_PRICEFLUCTUATIONS_RES )
	WORD						wResultCode;
	BYTE						byPrivateShopInventorySlotPos;
	DWORD						dwBeforeZenny;
	DWORD						dwAfterZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_BUSINESS_PRICEFLUCTUATIONS_NFY )
	HOBJECT						hOwner;
	BYTE						byPrivateShopInventorySlotPos;
	DWORD						dwBeforeZenny;
	DWORD						dwAfterZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_BUSINESS_IMMEDIATE_ITEM_BUYING_RES )
	WORD						wResultCode;
	sPRIVATESHOP_ITEM_DATA		sPrivateShopItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_BUSINESS_IMMEDIATE_ITEM_BUYING_NFY )
	HOBJECT						hPrivateShopOwner;
	sPRIVATESHOP_ITEM_DATA		sPrivateShopItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_BUSINESS_WINDOWCLOSE_NFY )
	HOBJECT						hPrivateShopOwner;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_BUSINESS_CANCEL_RES )
	WORD				wResultCode;
	BYTE				byCancelType;
	BYTE				byPrivateShopInventorySlotPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PRIVATESHOP_BUSINESS_CANCEL_NFY )
	HOBJECT						hOwner;
	BYTE						byCancelType;//1: ������⶧ ���, 2: ������ ���
	BYTE						byPrivateShopInventorySlotPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TUTORIAL_WAIT_NFY )
	WORD						wWaitingCount; // ���� �ڽž��� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TUTORIAL_WAIT_CANCEL_RES )
	WORD						wResultCode; 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_TUTORIAL_PLAY_QUIT_RES )
	WORD						wResultCode; 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MAIL_START_RES )
	HOBJECT	hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	WORD 	wResultCode;	// ���
	bool	bIsAway;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MAIL_SEND_RES )
	HOBJECT	hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	WCHAR wszTargetName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];	// ���� ĳ�� �̸�
	WORD wResultCode;	// ��������
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MAIL_READ_RES )
	HOBJECT	hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	MAILID	mailID;	// ���� ���̵�
	WORD	wResultCode;	// ������ �̹� ���� �Ǿ��� ���� ���� 
	BYTE	byRemainDay;
	DBOTIME endTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MAIL_DEL_RES )
	HOBJECT	hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	MAILID	mailID;	// ���� ���̵�
	WORD	wResultCode;	// ������ �̹� ���� �Ǿ��� ���� ���� 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MAIL_RETURN_RES )
	HOBJECT	hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	MAILID	mailID;	// ���� ���̵�
	WORD	wResultCode;	// ������ �̹� ���� �Ǿ��� ���� ���� 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MAIL_RELOAD_RES )
	HOBJECT	hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	WORD wResultCode;	// ��������
	BYTE	byMailCount;		// ���� ��ü���� ī��Ʈ 
	BYTE	byManagerCount;		// ���� ���� �Ŵ��� ���� ī��Ʈ
	BYTE	byNormalCount;		// ���� ���� ��� ���� ī��Ʈ
	MAILID   aMailID[NTL_MAX_MAIL_SLOT_COUNT];	// ī��Ʈ�� �ش��ϴ� ����� ���� ���̵� 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MAIL_RELOAD_NFY )		// �����ٿ� ���� �����ð��� ���� �ڵ� �۽�
	BYTE	byMailCount;		// ���� ��ü���� ī��Ʈ 
	BYTE	byManagerCount;		// ���� ���� �Ŵ��� ���� ī��Ʈ
	BYTE	byNormalCount;		// ���� ���� ��� ���� ī��Ʈ
	MAILID  aMailID[NTL_MAX_MAIL_SLOT_COUNT];	// ī��Ʈ�� �ش��ϴ� ����� ���� ���̵� 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MAIL_LOAD_RES )
	HOBJECT	hObject;		// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	WORD	wResultCode;	// ��������
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MAIL_LOAD_DATA )
	sMAIL_NEW_PROFILE sData;		
	BYTE	byTextSize;
	WCHAR	wszText[NTL_MAX_LENGTH_OF_MAIL_MESSAGE_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MAIL_LOAD_INFO )
	sMAIL_NEW_PROFILE sData;	
	BYTE	byTextSize;
	WCHAR	wszText[NTL_MAX_LENGTH_OF_MAIL_MESSAGE_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MAIL_ITEM_RECEIVE_RES )
	HOBJECT	hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	WORD wResultCode;	// ��������
	MAILID	mailID;	// ���� ���̵�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MAIL_LOCK_RES )
	HOBJECT	hObject;	// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	MAILID	mailID;	// ���� ���̵�
	bool	bIsLock;		// Lock 1: Unlock: 0
	WORD 	wResultCode;	// ������ �̹� ���� �Ǿ��� ���� ����
	BYTE	byExpiredDay;	// ������¥
	DBOTIME	endTime;		
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MAIL_CLOSE_NFY )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MAIL_MULTI_DEL_RES )
	HOBJECT	hObject;		// ���ϼۼ���ž ������Ʈ (��ī��Ʈ���� ����� INVALID_OBJECT )
	WORD	wResultCode;	// ������ �̹� ���� �Ǿ��� ���� ����
	BYTE	byCount;
	MAILID	aMailID[NTL_MAX_COUNT_OF_MULTI_DEL];	// ���� ���̵�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PORTAL_START_RES)
	WORD						wResultCode;
	HOBJECT			hNpcHandle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PORTAL_INFO)
	BYTE			byCount;
	PORTALID		aPortalID[NTL_PORTAL_MAX_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PORTAL_ADD_RES)
	WORD						wResultCode;
	HOBJECT			hNpcHandle;
	PORTALID		PortalID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PORTAL_RES)
	WORD				wResultCode;
	HOBJECT			hNpcHandle;
	BYTE			byPoint;		// 0~7���� ���õ� �ε���
	CNtlVector		vLoc;
	CNtlVector		vDir;
	WORLDID			worldID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_WAR_FOG_INFO)
	BYTE			abyWarFogInfo[NTL_MAX_SIZE_WAR_FOG];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_WAR_FOG_UPDATE_RES)
	WORD			wResultCode;
	HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MOB_LUCKY_DROP_NFY)
	HOBJECT			hMobhandle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_UPGRADE_ALL_NFY)
	BYTE			abyGrade[NTL_ITEM_UPGRADE_EQUIP_COUNT];  // �迭 �ε����� �ش� Pos, Value�� �ش� ��� �׷��̵�( 255 INVALID�� �������� ���� ���)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_BOT_BOTCAUTION_NFY )		//  [2/20/2008 SGpro]
	HOBJECT			hBot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_REPUTATION)
	HOBJECT			handle;
	DWORD			dwReputation;
END_PROTOCOL()
//-----------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_FUNCTION_ADD_RES)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_GIVE_ZENNY_RES)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_BANK_START_RES)
	HOBJECT			handle;			// Npc handle
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_BANK_MOVE_RES)
	HOBJECT			handle;
	HOBJECT			hSrcItem;
	HOBJECT			hDstItem;
	BYTE			bySrcPlace;
	BYTE			bySrcPos;
	BYTE			byDestPlace;
	BYTE			byDestPos;
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_BANK_MOVE_STACK_RES)
	HOBJECT			handle;
	HOBJECT			hSrcItem;
	HOBJECT			hDestItem;
	BYTE			bySrcPlace;
	BYTE			bySrcPos;
	BYTE			byDestPlace;
	BYTE			byDestPos;
	BYTE			byStackCount1;
	BYTE			byStackCount2;
	ITEMID			splitItemId;
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_BANK_END_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_BANK_ZENNY_INFO)
	DWORD			dwZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_BANK_ITEM_INFO)
	BYTE            byPlace;
	BYTE			byItemCount;
	sITEM_PROFILE	aItemProfile[NTL_MAX_BANK_ITEM_SLOT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_BANK_ZENNY_RES)
	HOBJECT			handle;
	WORD			wResultCode;
	DWORD			dwZenny;
	bool			bIsSave;		// 1: ���� 0: ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_CROSSFIRE_RES )
	HOBJECT			hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_GUILD_CREATE_MARK_RES )
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_GUILD_CHANGE_MARK_RES )
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_MARK_CHANGED_NFY)
	HOBJECT				hSubject;
	sDBO_GUILD_MARK		sMark;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_LOAD_RES)
	HOBJECT				handle;			// Npc handle
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_CHANGE_NAME_RES)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PARTY_SHARETARGET_RES )
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_PARTY_SHARETARGET_NFY )
	sSHARETARGET_INFO		sharetargetInfo[NTL_MAX_SHARETARGET_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RIDE_ON_BUS_RES)
	HOBJECT				hTarget;			// Npc handle
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RIDE_OFF_BUS_RES)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRANSFORM_CANCEL_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_ITEM_IDENTIFY_RES)
	WORD			wResultCode;
	HOBJECT			hNpchandle;		// NpcHandle
	BYTE			byPlace;
	BYTE			byPos;
	sITEM_DATA      sItemData;			// �����ÿ��� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_STATE_UPDATE_NFY)
	BYTE			byMatchState;		// eBUDOKAI_MAJORMATCH_STATE
	bool			bIsEnter;			// true : Enter, false : exit
	BYTE			byStage;
	DWORD			dwRemainTime;		// �и������� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_TEAM_INFO_NFY)
	BYTE			byMatchIndex;		// ���° �������?[����:0~31, ��:0~15]
	BYTE			byTeamCount;
	WORD			wTeamInfo_var;		// sMATCH_MINORMATCH_TEAM_INFO_VAR [NTL_MAX_MINORMATCH_TEAM_COUNT];
	sVARIABLE_DATA	sData;			
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_PLAYER_STATE_NFY)
	HOBJECT			hPc;
	BYTE			byPcState;			// eMATCH_MEMBER_STATE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_UPDATE_SCORE_NFY)
	TEAMTYPE		wTeamType;
	BYTE			byScore;
	HOBJECT			hSlayer;			// ������Ų character
	HOBJECT			hFainter;			// ������ character
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_TEAM_SCORE_NFY)
	BYTE							byCount;
	sMATCH_MINORMATCH_TEAM_SCORE	aTeamScore[BUDOKAI_MAX_MINORMATCH_TEAM_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_SELECTION_NFY)
	TEAMTYPE		teamWinner;
	BYTE			byTeamCount;
	sMINORMATCH_SELECTION_DATA	aSelection[BUDOKAI_MAX_MINORMATCH_TEAM_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_STAGE_FINISH_NFY)
	BYTE			byStageResult;		// eMATCH_RESULT
	WORD			wStageWinner;		// Stage Winner TeamType
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_MATCH_FINISH_NFY)
	BYTE			byMatchResult;
	WORD			wMatchWinner;
	BYTE			byKillCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MAJORMATCH_STATE_UPDATE_NFY)
	BYTE			byMatchState;		// eBUDOKAI_MAJORMATCH_STATE
	bool			bIsEnter;			// true : Enter, false : exit
	BYTE			byStage;
	DWORD			dwRemainTime;		// �и������� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MAJORMATCH_TEAM_INFO_NFY)
	BYTE			byMatchDepth;	// ����[8��~32��] ��[8��~16��]
	BYTE			byMatchIndex;	// depth�� ���� ��� ��ġ

	BYTE			byTeamCount;
	WORD			wTeamInfo_var;		// sMATCH_MINORMATCH_TEAM_INFO_VAR [2];
	sVARIABLE_DATA	sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MAJORMATCH_PLAYER_STATE_NFY)
	HOBJECT			hPc;
	BYTE			byPcState;			// eMATCH_MEMBER_STATE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MAJORMATCH_UPDATE_SCORE_NFY)
	sMATCH_SCORE	sStageScore;		// �������� ���ھ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MAJORMATCH_STAGE_FINISH_NFY)
	BYTE			byStageResult;		// eMATCH_RESULT
	WORD			wStageWinner;		// Stage Winner TeamType
	sMATCH_SCORE	sMatchScore;		// ��� ���ھ�
	bool			bIsObserver;		// ������ ��忡�� ���
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MAJORMATCH_MATCH_FINISH_NFY)
	BYTE			byMatchResult;		// eMATCH_RESULT
	WORD			wMatchWinner;		// Match Winner TeamType
	sMATCH_SCORE	sMatchScore;		// ��� ���ھ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_FINALMATCH_STATE_UPDATE_NFY)
	BYTE			byMatchState;		// eBUDOKAI_MAJORMATCH_STATE
	bool			bIsEnter;			// true : Enter, false : exit
	BYTE			byStage;
	DWORD			dwRemainTime;		// �и������� ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_FINALMATCH_TEAM_INFO_NFY)
	BYTE			byMatchDepth;
	BYTE			byMatchIndex;

	BYTE			byTeamCount;
	WORD			wTeamInfo_var;		// sMATCH_FINALMATCH_TEAM_INFO_VAR [4];
	sVARIABLE_DATA	sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_FINALMATCH_PLAYER_STATE_NFY)
	HOBJECT			hPc;
	BYTE			byPcState;			// eMATCH_MEMBER_STATE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_FINALMATCH_UPDATE_SCORE_NFY)
	sMATCH_SCORE	sStageScore;		// �������� ���ھ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_FINALMATCH_STAGE_FINISH_NFY)
	BYTE			byStageResult;		// eMATCH_RESULT
	WORD			wStageWinner;		// Stage Winner TeamType
	sMATCH_SCORE	sMatchScore;		// ��� ���ھ�
	bool			bIsObserver;		// ������ ��忡�� ���
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_FINALMATCH_MATCH_FINISH_NFY)
	BYTE			byMatchResult;		// eMATCH_RESULT
	WORD			wMatchWinner;		// Match Winner TeamType
	sMATCH_SCORE	sMatchScore;		// ��� ���ھ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_AWARDING_NFY)
	WORD			awTeamName[MAX_FINALMATCH_RESULT];
	sVARIABLE_DATA	sData;	// WCHAR wszTeamName[NTL_MAX_LENGTH_BUDOKAI_TEAM_NAME_IN_UNICODE + 1]; : ����� ���� NULL�� �������� �ʴ´�.
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_CONFUSE_TARGET_NFY)
	HOBJECT			hSubject;
	HOBJECT			hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_TERROR_COURSE_CHANGE_NFY)
	HOBJECT			hSubject;
	HOBJECT			hAttacker;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DICE_ROLL_RES)
	WORD			wResultCode;
	WORD			wDiceResult;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DICE_ROLLED_NFY)
	HOBJECT			hSubject;
	WORD			wDiceResult;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_STATE_INFO_NFY)
	BUDOKAITIME							tmDefaultOpenTime;
	bool								bRankbattleAllow;

	sBUDOKAI_UPDATE_STATE_INFO			sStateInfo;
	sBUDOKAI_UPDATE_MATCH_STATE_INFO	aMatchStateInfo[MAX_BUDOKAI_MATCH_TYPE];

	sBUDOKAI_JOIN_INFO					sJoinInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_UPDATE_STATE_NFY)
	sBUDOKAI_UPDATE_STATE_INFO			sStateInfo;
	bool								bRankbattleAllow;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_UPDATE_MATCH_STATE_NFY)
	BYTE								byMatchType;	// eBUDOKAI_MATCH_TYPE
	sBUDOKAI_UPDATE_MATCH_STATE_INFO	sStateInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_JOIN_INDIVIDUAL_RES)
	WORD			wResultCode;
	WORD			wJoinId;			// ���� ��ȣ
	bool			bDojoRecommender;	// ������õ������?
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_LEAVE_INDIVIDUAL_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_JOIN_TEAM_INFO_RES)
	WORD						wResultCode;

	BYTE						byMemberCount;
	sBUDOKAI_TEAM_POINT_INFO	asPointInfo[1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_JOIN_TEAM_RES)
	WORD			wResultCode;
	HOBJECT			hTroublePc;
	float			fTotalRankPoint;
	WORD			wJoinId;
	WCHAR			wszTeamName[NTL_MAX_LENGTH_BUDOKAI_TEAM_NAME_IN_UNICODE + 1];

	// 
	BYTE						byMemberCount;
	sBUDOKAI_TEAM_POINT_INFO	aTeamInfo[NTL_MAX_MEMBER_IN_PARTY];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_JOIN_TEAM_NFY)
	float			fTotalRankPoint;
	WORD			wJoinId;
	WCHAR			wszTeamName[NTL_MAX_LENGTH_BUDOKAI_TEAM_NAME_IN_UNICODE + 1];

	// 
	BYTE						byMemberCount;
	sBUDOKAI_TEAM_POINT_INFO	aTeamInfo[NTL_MAX_MEMBER_IN_PARTY];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_LEAVE_TEAM_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_LEAVE_TEAM_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_LEAVE_TEAM_MEMBER_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_LEAVE_TEAM_MEMBER_NFY)
	WCHAR			wszMemberName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_JOIN_INFO_RES)
	WORD					wResultCode;

	BYTE					byMatchType;		// eBUDOKAI_MATCH_TYPE

	// ���� ���� ������ ���� �ʿ�
	union
	{
		sBUDOKAI_REGISTER_INDIVIDUAL_INFO	sIndividualInfo;
		sBUDOKAI_REGISTER_TEAM_INFO			sTeamInfo;
	};
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_JOIN_STATE_RES)
	WORD			wResultCode;
	BYTE			byMatchType;		// eBUDOKAI_MATCH_TYPE
	BYTE			byJoinState;		// eBUDOKAI_JOIN_STATE
	BYTE			byJoinResult;		// ���� ���

	// ������ ���� ���
	// byMatchType = INVALID_BUDOKAI_MATCH_TYPE
	// byJoinState = INVALID_BUDOKAI_JOIN_STATE
	// byJoinResult = INVALID_BUDOKAI_JOIN_RESULT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_JOIN_STATE_NFY)
	BYTE			byMatchType;		// eBUDOKAI_MATCH_TYPE
	BYTE			byJoinState;		// eBUDOKAI_JOIN_STATE
	BYTE			byJoinResult;		// eBUDOKAI_JOIN_RESULT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DISCONNECTED_NFY)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BOT_BOTCAUTION_HELPME_NFY)
	HOBJECT			hBot;
	bool			bIsRequester; // true : SOS�� ��û�� ��
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_MUDOSA_INFO_RES)
	WORD					wResultCode;
	BYTE					byMudosaCount;
	sBUDOKAI_MUDOSA_INFO	aMudosaInfo[BUDOKAI_MAX_MUDOSA_INFO_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_MUDOSA_TELEPORT_RES)
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_PROGRESS_MESSAGE_NFY)
	BYTE					byMsgId;			// eBUDOKAI_PROGRESS_MESSAGE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_SOCIAL_ACTION_NFY)
	HOBJECT				hSubject;
	ANIMATIONID			socialAction;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_PRIZEWINNER_NAME_RES)
	WORD				wResultCode;

	// BUDOKAI_MATCH_TYPE_INDIVIDUAL
	//- WCHAR		wszName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	WORD				wWinner;			
	WORD				wSecondWinner;

	sVARIABLE_DATA		sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_PRIZEWINNER_TEAM_NAME_RES)
	WORD				wResultCode;

	// BUDOKAI_MATCH_TYPE_TEAM
	//- WCHAR		wszTeamName[NTL_MAX_LENGTH_BUDOKAI_TEAM_NAME_IN_UNICODE + 1];
	WORD				wWinner;			
	WORD				wSecondWinner;

	sVARIABLE_DATA		sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_GM_BUDOKAI_SERVER_ENTER_RES)
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_GM_BUDOKAI_SERVER_LEAVE_RES)
	WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_GM_MATCH_PROGRESS_INFO_RES)
	WORD								wResultCode;

	BYTE								byMatchType;		// eBUDOKAI_MATCH_TYPE
	BYTE								byMatchWorldType;	// eMATCHWORLD_TYPE;
	BYTE								byMatchDepth;		// eBUDOKAI_MATCH_DEPTH

	BYTE								byStateCount;
	sBUDOKAI_GM_MATCH_PROGRESS_STATE	aStateList[BUDOKAI_MAX_MATCH_COUNT];	// ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_GM_MATCH_ARENA_ENTER_RES)
	WORD								wResultCode;

	BYTE								byMatchType;		// eBUDOKAI_MATCH_TYPE
	BYTE								byMatchWorldType;	// eMATCHWORLD_TYPE
	BYTE								byMatchDepth;		// eBUDOKAI_MATCH_DEPTH
	BYTE								byMatchIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_GM_MATCH_ARENA_LEAVE_RES)
	WORD								wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_TURN_ON_NFY)
	HOBJECT			hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_TURN_OFF_NFY)
	HOBJECT			hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_BROKEN_NFY)
	HOBJECT			hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_ITEM_SELL_RES)
	TBLIDX				itemTblidx;
	BYTE				byPlace;
	BYTE				byPos;
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_EVENTITEM_START_RES)
	HOBJECT			handle;
	BYTE			byType; //	0: �⺻  1:�������� �Ǹ� �̺�Ʈ NPC 
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_EVENTITEM_BUY_RES)
	HOBJECT			handle;
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_EVENTITEM_END_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_REPLACE)
	HOBJECT			hDeleteItem;
	HOBJECT			hCreateItem;
	BYTE			byDeleteItemPlace;
	BYTE			byDeleteItemPos;
	sITEM_DATA      sCreateItemData;
	bool			bIsNew;		// Effect �߰� 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_GAMBLE_BUY_RES)
	WORD			wResultCode;
	HOBJECT			handle;
	HOBJECT			hItem;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DUNGEON_DIFF_NFY)
	ePARTY_DUNGEON_STATE eDiff;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DUNGEON_DIFF_RES)
	WORD			wResultCode;
	ePARTY_DUNGEON_STATE		eDiff;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DUNGEON_INIT_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DUNGEON_INIT_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_SP)
	DWORD			dwSpPoint;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_INIT_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_REMOVE_NFY)
	TBLIDX			skillId;
	BYTE			bySlot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_REMOVE_NFY)
	TBLIDX			skillId;
	BYTE			bySlot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_MARKING_NFY)
	HOBJECT			handle;
	sMARKING		sMarking;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_DICE_START_NFY)
	DWORD			dwWaitTick;		//ms
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_DICE_ROLLED_NFY)
	HOBJECT			handle;	// �ش� ĳ���� �ڵ�
	DWORD			dwRet;	// �����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_DICE_ROLLED_RES)
	DWORD			dwRet;	// �����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_DICE_END_NFY)
	bool			bIsSuccess;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_ITEM_RANK_SET_RES)
	WORD			wResultCode;
	BYTE			byItemRank; // eITEM_RANK 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_ITEM_RANK_SET_NFY)
	BYTE			byItemRank; // eITEM_RANK 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_LOCK_NFY)
	bool				bIsOpen;	// 1: Open 0:Close
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_LOCK_RES)
	WORD				wResultCode;    
	bool				bIsOpen;	// 1: Open 0:Close
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_RESET_RES)
	WORD				wResultCode;      
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_RESET_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_ACCEPTED_RES)
	BYTE				byItemSlot;	// ��Ƽ�κ� �ش� ���� ������ ����
	WORD				wResultCode;          
	HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_ACCEPTED_NFY)
	BYTE				byItemSlot;	// ��Ƽ�κ� �ش� ���� ������ ����
	HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_GIVE_RES)
	WORD				wResultCode;         
	BYTE				byItemSlot;		// ��Ƽ�κ� �ش� ���� ������ 
	HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_GIVE_NFY)
	BYTE				byItemSlot;		// ��Ƽ�κ� �ش� ���� ������ 
	HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_DICE_START_RES)
	WORD				wResultCode;         
	BYTE				byItemSlot;		// ��Ƽ�κ� �ش� ���� ������	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_DICE_START_NFY)
   	BYTE				byItemSlot;		// ��Ƽ�κ� �ش� ���� ������	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_DICE_ROLL_RES)
	WORD				wResultCode;         
	BYTE				byRet;		// �ֻ����������	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_DICE_ROLL_NFY)
	HOBJECT				handle;			// �ֻ�����ü
   	BYTE				byRet;			// �ֻ����������	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_DICE_END_NFY)
   	HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TELEPORT_PROPOSAL_NFY)
	BYTE				byTeleportType;
	BYTE				byInfoIndex;		// �������� �ڷ���Ʈ ������ �����ϱ����� �ε���
	WORD				wWaitTime;
	TBLIDX				worldTblidx;		// ���� ���̺� �ε��� : ������ ���� ���ϰ� ����ϱ� ���� �뵵.

	union
	{
		DWORD			dwReserve;
		BYTE			byBudokaiMatchDepth;	// õ�����Ϲ���ȸ XX��
	};

	BYTE				bySummonerNameLength;
	WCHAR				wszSummonnerName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];	// ����
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TELEPORT_CONFIRM_RES)
	WORD				wResultCode;

	BYTE				byTeleportIndex;
	bool				bTeleport;			// Ŭ���̾�Ʈ���� ���� ��
	bool				bClearInterface;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_PETITION_INFO)
	PETITIONID			petitionID;
	WCHAR				awchQuestionContent[NTL_MAX_SIZE_QUESTION_CONTENT_UNICODE + 1];
	PETITIONCATEGORY	nCategory1;//ePETITIONSYSTEM_CATEGORY_1
	PETITIONCATEGORY	nCategory2;//ePETITIONSYSTEM_CATEGORY_2
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GAME_COMMON_MSG_NFY)
	WORD				wResultCode;         
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_NICKNAME_CHANGED_NFY)
	HOBJECT				hSubject;
	TBLIDX				nicknameTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_RECIPE_REG_NFY)			// �����ǵ��
 	TBLIDX				recipeTblidx;	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_ITEM_CHECK_RES)			// ��������� ���� (�ʿ��� ������ ���� üũ)
	WORD				wResultCode;    
	HOBJECT				objHandle;			
	TBLIDX				recipeTblidx;	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_ITEM_MAKE_RES)			// ������ �����
	WORD				wResultCode;    
	BYTE				bySuccessResult;			// eITEM_MIX_RESULT_TYPE
	HOBJECT				objHandle;			
	TBLIDX				recipeTblidx;	
	HOBJECT				itemHandle;
END_PROTOCOL()
//------------------------------------------------------------------			
BEGIN_PROTOCOL(GU_HOIPOIMIX_ITEM_MAKE_EP_RES)		// ������ ����� �� EP �ֱ�
	WORD				wResultCode;    
END_PROTOCOL()
//------------------------------------------------------------------	
BEGIN_PROTOCOL(GU_HOIPOIMIX_ITEM_RECIPE_INFO)  
	BYTE				byCount;
	sRECIPE_DATA		asRecipeData[NTL_ITEM_RECIPE_MAX_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DYNAMIC_OBJECT_UPDATE_STATE)
	HOBJECT				handle;
	sDYNAMIC_OBJECT_BRIEF		dynamicObjBrief;
	sDYNAMIC_OBJECT_STATE		dynamicObjState;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_ITEM_MACHINE_MAKE_RES)			// �ӽ� �ʵ� ���
	WORD				wResultCode;    
	BYTE				byPlace;
	BYTE				byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_ITEM_MACHINE_DEL_RES)			// �ӽ� �ʵ� ����
	WORD				wResultCode;    
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_ITEM_MAKE_EXP_NFY)			
	DWORD				dwCurExp;
	BYTE				byCurLevel;
	bool				bIsNormal; // recipe type�� eRECIPE_NORMAL �ΰ� �ƴѰ�.
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_TARGET_LOST_NFY)
	HOBJECT						hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_GUARD_CRASHED_NFY)
	HOBJECT						hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_RP_BALL)
	HOBJECT			handle;
	BYTE			byCurRPBall;
	bool			bDropByTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_RP_BALL_MAX)
	HOBJECT			handle;
	BYTE			byMaxRPBall;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_JOB_SET_RES)
	WORD				wResultCode;  
	HOBJECT				hNpchandle;
	BYTE				byRecipeType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_JOB_RESET_RES)
	WORD				wResultCode;  
	HOBJECT				hNpchandle;
	BYTE				byRecipeType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_RP_INCREASE_START_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_RP_DECREASE_START_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_RP_INCREASE_STOP_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_LAST_STEP_CHANGED_NFY)
	HOBJECT			hSubject;
	BYTE			byLastStep;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_CHARGE_CANCELED_NFY)
	HOBJECT			hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_REFRESH_LP_EP)
	HOBJECT			hSubject;
	WORD			wCurLp;
	WORD			wMaxLp;
	WORD			wCurEp;
	WORD			wMaxEp;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_CHAR_NONBATTLEACTIONPATTERNSET_UNITIDX_NFY )
	HOBJECT				hBotHandle;
	ACTIONPATTERN_FIELD unitIdx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_VEHICLE_START_NFY )
	HOBJECT				hDriverHandle;	
	sVECTOR3			vStartPosition;
	TBLIDX				idFuelItemTblidx;
	HOBJECT				hVehicleItem; 
	TBLIDX				idVehicleItemTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_VEHICLE_ENGINE_START_RES )
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_VEHICLE_ENGINE_START_NFY )
	HOBJECT				hDriverHandle;	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_VEHICLE_ENGINE_STOP_RES )
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_VEHICLE_ENGINE_STOP_NFY )
	HOBJECT				hDriverHandle;	
	DWORD				dwFuelRemain;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_VEHICLE_FUEL_UPDATE_NFY )
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_VEHICLE_END_NFY )
	HOBJECT				hDriverHandle;
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_VEHICLE_END_RES )
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_VEHICLE_STUNT_NFY )
	HOBJECT			hDriverHandle;	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_SKILL_PASSIVE_EFFECT_APPLIED_NFY )
	TBLIDX			skillTblidx;
	BYTE			bySlotIndex;
	sDBO_UPDATED_SKILL_DATA		sUpdatedSkillData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_AVATAR_UPDATED_SKILL_DATA_INFO )
	TBLIDX			skillTblidx;
	BYTE			bySlotIndex;
	sDBO_UPDATED_SKILL_DATA		sUpdatedSkillData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_MONSTER_TRANSFORMED_NFY )
	HOBJECT			hSubject;
	TBLIDX			newTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_DOJO_CREATE_RES )
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_DOJO_DELETE_RES )
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_FUNCTION_ADD_RES)
	WORD				wResultCode;
	BYTE				byFunction;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_BANK_HISTORY_RES)
	WORD				wResultCode;
	DWORD				dwBalance;
	BYTE				byCount;
    sDBO_DOJO_BANK_HISTORY_INFO asData[DBO_MAX_COUNT_DOJO_BANK_HISTORY];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOGI_CREATE_RES)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOGI_CHANGE_RES)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOGI_UPDATE_NFY)
	HOBJECT				handle;
	sDBO_DOGI_DATA		sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_DOGI_CREATE_RES)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_DOGI_CHANGE_RES)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHILD_ADULT_SWITCHED_NFY)
	HOBJECT				hSubject;
	bool				bIsAdult;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHANGE_CLASS_AUTHORITY_CHANGED_NFY)
	bool				bCanChangeClass;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PLAY_BGM)
	bool				bPlay;
	bool				bLoop;
	DWORD				dwDelay;
	BYTE				byLength;
	char				szName[1];		// null �� �����ؼ� ������.
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_MARK_CHANGED_NFY)
	TBLIDX				dojoTblidx;
	GUILDID				guildId;
	sDBO_GUILD_MARK		sMark;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_LEVEL_CHANGED_NFY)
	TBLIDX				dojoTblidx;
	BYTE				byLevel;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_NETP)
	WORD				wResultCode;
	NETP				netP;
	NETP				dwBonusNetP;
	NETP				dwAccumulationNetP;
	DWORD				timeNextGainTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_DOJO_SCRAMBLE_RES )			// ������Ż�� ��û�� ���� ���� (������)
	WORD				wResultCode;			
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_SCRAMBLE_RESPONSE_RES )
	WORD				wResultCode;
	WCHAR				wszGuildName[NTL_MAX_SIZE_GUILD_NAME_IN_UNICODE + 1];
	bool				bIsRetry; // true�� �ٽ� Ȯ���ؾ��Ѵ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_NETMARBLEMEMBERIP_NFY )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUS_LOCATION_NFY)
	HOBJECT				hSubject;
	TBLIDX				busTblidx;
	sVECTOR2			vCurLoc;
	sVECTOR2			vCurDir;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUS_LOCATION_ERASED_NFY)
	HOBJECT				hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUS_LOCATION_RESET_ALL_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL( GU_ITEM_EXPIRED_NFY )
	HOBJECT				hItem;
	BYTE				byPlace;
	BYTE				byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_NETPYITEM_START_RES)
	BYTE			byType; //	0: �⺻  1:�������� �Ǹ� �̺�Ʈ NPC 
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_NETPYITEM_BUY_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_NETPYITEM_END_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_REFRESH_BATTLE_ATTRIBUTE_MODIFIER)
	HOBJECT				hSubject;
	float				fHonestOffenceModifier;
	float				fHonestDefenceModifier;
	float				fStrangeOffenceModifier;
	float				fStrangeDefenceModifier;
	float				fWildOffenceModifier;
	float				fWildDefenceModifier;
	float				fEleganceOffenceModifier;
	float				fEleganceDefenceModifier;
	float				fFunnyOffenceModifier;
	float				fFunnyDefenceModifier;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_RANKBATTLE_ALLOW_NFY)
	bool				bAllow;
	WORD				wReasonCode;
END_PROTOCOL()
//------------------------------------------------------------------

BEGIN_PROTOCOL(GU_CHAR_RANKPOINT_RESET_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_NPC_INFO_RES)
	WORD					wResultCode;
	sDBO_DOJO_NPC_INFO		sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GAMEGUARD_AUTH_ANSWER_REQ)
	BYTE				byDataSize;
	BYTE				abyData[UCHAR_MAX];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_SEAL_ATTACK_BEGIN_NFY)
	TBLIDX				sealObjectTblidx;
	bool				bIsBeingStolen;
	sVECTOR2			vLoc;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_SEAL_ATTACK_END_NFY)
	TBLIDX				sealObjectTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_SEAL_CURRENT_STATE_NFY)
	TBLIDX				sealObjectTblidx;
	BYTE				byState;		// eTOBJECT_STATE_TYPE_C
	sVECTOR2			vLoc;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_INVENTORY_CAPSULE_UNLOCK_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_SCRAMBLE_SHIFT_SEAL_STATE_NFY)
	TBLIDX						dojoTblidx;
	TBLIDX						objectTblidx;
	GUILDID						guildId;
	WCHAR						wszName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_LP_STATUS_NFY)
	HOBJECT			handle;
	bool			bEmergency;	// true: Emergency false: General
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DURATION_ITEM_BUY_RES)
	TBLIDX				merchantTblidx;
	BYTE				byPos;
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DURATION_RENEW_RES)
	HOBJECT				hItemHandle;
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_START_RES)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_INFO_NFY)
	BYTE				byCount;
	sCASHITEM_BRIEF		aInfo[1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_END_RES)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_MOVE_RES)
	WORD				wResultCode;
	DWORD				dwProductId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_USE_RES)
	WORD				wResultCode;
	DWORD				dwProductId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_HLSHOP_START_RES)
	WORD				wResultCode;
	DWORD				dwRemainAmount;							// �����ܾ�
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_HLSHOP_END_RES)
	WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_BUY_RES)
	WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GMT_INFO_NFY)
	BYTE					byGMTResetCount;
	sGAME_MANIA_TIME_DATA	sCurrent;
	sGAME_MANIA_TIME_DATA	sNext;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GMT_UPDATE_RES)
	WORD				wResultCode;
	sGAME_MANIA_TIME	sNext;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GMT_CHANGED_NFY)
	sGAME_MANIA_TIME	sCurrent;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_ADD_NFY)
	sCASHITEM_BRIEF		sInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_DEL_NFY)
	DWORD				dwProductId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_MAX_LP)
	HOBJECT			hSubject;
	WORD			wMaxLp;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_MAX_EP)
	HOBJECT			hSubject;
	WORD			wMaxEp;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_MAX_RP)
	HOBJECT			hSubject;
	WORD			wMaxRp;
END_PROTOCOL()

//------------------------------------------------------------------
#pragma pack(pop)