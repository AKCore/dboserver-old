#ifndef _GAMEPROTOCOL_H
#define _GAMEPROTOCOL_H

#include "Protocol.h"

#pragma once

enum eOpcode
{
	// USER TO GAME
	UG_PING = 4000,
	UG_GAME_ENTER_REQ,
	UG_GAME_LEAVE_REQ,									// ���� ����
	UG_AUTH_KEY_FOR_COMMUNITY_SERVER_REQ,				// Ŀ�´�Ƽ ���� ����Ű ��û
	UG_ENTER_WORLD,										// ���� ����
	UG_SERVER_COMMAND,									// ���� ��ɾ�
	UG_CHAR_READY_FOR_COMMUNITY_SERVER_NFY,				// Ŀ�´�Ƽ �������� ����Ÿ ���� �غ� �Ǿ����� �˸�
	UG_CHAR_READY_TO_SPAWN,								// �ε� �Ϸ�(Spawning state���� ���� �غ� ����)
	UG_CHAR_READY,										// ĳ���� �غ�
	UG_CHAR_MOVE,										// ĳ���� �̵�
	UG_CHAR_DEST_MOVE,									// ĳ���� ������ �̵�
	UG_CHAR_CHANGE_HEADING,								// ĳ���� ȸ��
	UG_CHAR_MOVE_SYNC,									// ĳ���� ��ġ ����
	UG_CHAR_CHANGE_DIRECTION_ON_FLOATING,				// ĳ���� ����/falling ���� �ٶ󺸴� ����
	UG_CHAR_FOLLOW_MOVE,								// ĳ���� Ÿ�� ���󰡱�
	UG_CHAR_DASH_KEYBOARD,								// Keyboard dash ����
	UG_CHAR_DASH_MOUSE,									// Mouse dash ����
	UG_CHAR_JUMP,										// ���� ����
	UG_CHAR_JUMP_END,									// ���� ����
	UG_CHAR_FALLING,									// Falling ���� ����/����
	UG_CHAR_TOGG_SITDOWN,								// �ɱ��� ���
	UG_CHAR_TOGG_FIGHTING,								// ������� ���
	UG_CHAR_TOGG_RUNNING,								// �ٱ��� ��� ( ���� Ŭ���̾�Ʈ�� ������� ���� )
	UG_CHAR_TARGET_SELECT,								// Ÿ�� ����
	UG_CHAR_TARGET_INFO,								// Ÿ�� ���� ��û
	UG_CHAR_TARGET_FACING,								// Ÿ�� ���
	UG_CHAR_ATTACK_BEGIN,								// ���� ���� �˸�
	UG_CHAR_ATTACK_END,									// ���� ���� �˸�
	UG_CHAR_CHARGE,										// ĳ���� ������
	UG_CHAR_BLOCK_MODE,									// Block ��� ����/����
	UG_CHAR_TELEPORT_REQ,								// �ڷ���Ʈ ��û
	UG_CHAR_BIND_REQ,									// ���ε� ��û
	UG_CHAR_REVIVAL_REQ,								// ��Ȱ ��û
	UG_CHAR_SERVER_CHANGE_REQ,							// �ٸ� ���� �������� �̵� ��û
	UG_CHAR_CHANNEL_CHANGE_REQ,							// ĳ���� ���� -> �ٸ� ���� ä�η� �̵� ��û
	UG_CHAR_EXIT_REQ,									// ĳ���� ���� -> ĳ���� ������ �̵� ��û
	UG_GAME_EXIT_REQ,									// ������ ������
	UG_CHAR_AWAY_REQ,
	UG_CHAR_KEY_UPDATE_REQ,
	UG_CHAR_DIRECT_PLAY_ACK,							// ���� ������ �����ִ� ����
	UG_CHAR_KNOCKDOWN_RELEASE_NFY,						// �˴ٿ� Ǯ��
	UG_CHAR_SKILL_REQ,									// ��ų ��� ��û
	UG_SKILL_TARGET_LIST,								// ��ų Ÿ�� ��� �˸�
	UG_SKILL_LEARN_REQ,									// ��ų ���� ��û
	UG_SKILL_UPGRADE_REQ,								// ��ų ��� ��û
	UG_SKILL_RP_BONUS_SETTING_REQ,						// ��ų���� �ڵ����� ���� RP ���ʽ� Ÿ�� ����
	UG_HTB_START_REQ,								    // HTB ���� ��û
	UG_HTB_LEARN_REQ,									// HTB ���� ��û
	UG_HTB_FORWARD_REQ,									// HTB ����
	UG_HTB_RP_BALL_USE_REQ,
	UG_BUFF_DROP_REQ,									// Buff ���� ��û
	UG_ITEM_MOVE_REQ,									// ������ �̵� ��û
	UG_ITEM_MOVE_STACK_REQ,								// ������ ���� �̵� ��û
	UG_ITEM_DELETE_REQ,									// ������ ���� ��û
	UG_ITEM_EQUIP_REPAIR_REQ,							// ���� ���� ��û
	UG_ITEM_PICK_REQ,									// �������ݱ� ��û
	UG_ITEM_REPAIR_REQ,
	UG_ITEM_USE_REQ,									// ������ ��� ��û
	UG_ITEM_UPGRADE_REQ,								// ������ ���׷��̵�
	UG_ITEM_IDENTIFY_REQ,								// ��ī���������� ������ Ȯ��
	UG_ZENNY_PICK_REQ,									// ���ݱ� ��û
	UG_SHOP_START_REQ,									// ���� ����
	UG_SHOP_BUY_REQ,									// ���� ���� ���
	UG_SHOP_SELL_REQ,									// ���� ���� �ȱ�
	UG_SHOP_END_REQ,									// ���� �ݱ�
	UG_SHOP_SKILL_BUY_REQ,								// ��ų ���� ��û
	UG_PARTY_CREATE_REQ,								// ��Ƽ �����
	UG_PARTY_DISBAND_REQ,								// ��Ƽ �ػ��ϱ�
	UG_PARTY_INVITE_REQ,								// ��Ƽ�� �ʴ��ϱ�
	UG_PARTY_INVITE_CHARID_REQ,							// ��Ƽ�� �ʴ��ϱ�(������ CharID �̿�)
	UG_PARTY_INVITE_CHAR_NAME_REQ,						// ��Ƽ�� �ʴ��ϱ�(������ �̸� �̿�)
	UG_PARTY_RESPONSE_INVITATION,						// ��Ƽ �ʴ뿡 ���� ��� ������
	UG_PARTY_LEAVE_REQ,									// ��Ƽ Ż���ϱ�
	UG_PARTY_KICK_OUT_REQ,								// ��� ������ Ż���Ű��
	UG_PARTY_CHANGE_LEADER_REQ,							// ��Ƽ ���� �����ϱ�
	UG_PARTY_OPEN_CHARM_SLOT_REQ,						// ��Ƽ ���� ���â ����
	UG_PARTY_CLOSE_CHARM_SLOT_REQ,						// ��Ƽ ���� ���â �ݱ�
	UG_PARTY_REGISTER_VICTIM_ITEM_REQ,					// ���� ����(������) ����ϱ�
	UG_PARTY_UNREGISTER_VICTIM_ITEM_REQ,				// ��ϵ� ���� ����(������) �ٽ� ��������
	UG_PARTY_REGISTER_VICTIM_ZENNY_REQ,					// ���� ����(����) ����ϱ�
	UG_PARTY_UNREGISTER_VICTIM_ZENNY_REQ,				// ��ϵ� ���� ����(����) �ٽ� ��������
	UG_PARTY_DECLARE_ZENNY_REQ,							// ���� ����ϱ�
	UG_PARTY_ACTIVATE_CHARM_REQ,						// ���� Ȱ��ȭ�ϱ�
	UG_PARTY_DEACTIVATE_CHARM_REQ,						// Ȱ��ȭ�� ���� ȿ�� �����ϱ�
	UG_PARTY_CHANGE_ZENNY_LOOTING_METHOD_REQ,			// ���� �й� ��� �����ϱ�
	UG_PARTY_CHANGE_ITEM_LOOTING_METHOD_REQ,			// ������ �й� ��� �����ϱ�
	UG_PARTY_INVEST_ZENNY_REQ,							// ���ϸ� ��Ƽ �κ��丮�� �����ۿ� �����ϱ�
	UG_PARTY_INVEN_ITEM_RANK_SET_REQ,					// ��Ƽ�κ��� ���� �������� RANK�����ϱ�
	UG_BANK_START_REQ,									// Warehouse ������ �ε�
	UG_BANK_MOVE_REQ,									// Warehouse �� ������ �̵�
	UG_BANK_MOVE_STACK_REQ,								// Warehouse �� ���þ����� �̵�
	UG_BANK_END_REQ,									// Warehouse �� �ݴ´�.
	UG_BANK_ZENNY_REQ,									// Warehouse �� ���� Ȥ�� �����Ѵ�.
	UG_BANK_BUY_REQ,									// Warehouse �� â������ �ø���.
	UG_BANK_ITEM_DELETE_REQ,							// Warehouse �� �������� �����Ѵ�.
	UG_SCOUTER_INDICATOR_REQ,							// ��ī���� ����������	
	UG_SCOUTER_PREDICT_REQ,								// ��ī���� ���׷��̵� ����	
	UG_SCOUTER_EQUIP_CHECK_REQ,							// ��ī���� ��� ���������� Ȯ��
	UG_SCOUTER_CHIP_REMOVE_ALL_REQ,						// ��ī���� Ĩ�� ��� ����
	UG_SOCIAL_ACTION,									// Social Action ���
	UG_TS_CONFIRM_STEP_REQ,								// Ʈ���� ���� ��û
	UG_TS_UPDATE_STATE,									// Ʈ���� ���� ���� ������Ʈ
	UG_TS_EXCUTE_TRIGGER_OBJECT,						// Excute Trigger Object
	UG_QUEST_ITEM_MOVE_REQ,								// ����Ʈ ������ �̵� ��û
	UG_QUEST_ITEM_DELETE_REQ,							// ����Ʈ ������ ���� ��û
	UG_QUEST_GIVEUP_REQ,								// ����Ʈ ������ ���� ��û
	UG_QUEST_SHARE,										// ����Ʈ ���� ��û
	UG_QUEST_OBJECT_VISIT_REQ,							// npc, tobject �湮 �̺�Ʈ
	UG_FREEBATTLE_CHALLENGE_REQ,						// ������Ʋ ���� ��û
	UG_FREEBATTLE_ACCEPT_RES,							// ������Ʋ ���� ��������
	UG_QUICK_SLOT_UPDATE_REQ,							// �������� �߰� �ϰų� ����
	UG_QUICK_SLOT_DEL_REQ,								// �������� ����
	UG_PET_DISMISS_PET_REQ,								// ���� ��ȯ ��� ��û
	UG_TRADE_START_REQ,									// �ش� �������� ��ȯ ��û
	UG_TRADE_OK_RES,									// �ش� ������ ����
	UG_TRADE_ADD_REQ,                                   // ��ȯâ�� ������ ��� 
	UG_TRADE_DEL_REQ,									// ��ȯâ�� ������ ����
	UG_TRADE_MODIFY_REQ,                                   // ��ȯâ�� ��ϵ� ������ ���� ���� 
	UG_TRADE_ZENNY_UPDATE_REQ,							// ��ȯâ�� ���� ��� �� ����
	UG_TRADE_END_REQ,									// ��ȯ �Ϸ� ��ư Ŭ��
	UG_TRADE_CANCEL_REQ,								// ��ȯ ��� Ȥ�� ĳ������ �Ÿ� ��Ż�� ���
	UG_TRADE_DENY_REQ,									// ��ȯ�� �Ұ��� �ϰ� �ϰų� �����ϵ��� �Ѵ�.
	UG_GUILD_CREATE_REQ,								// ��� ����� ( Guild Creation/Disbanding )
	UG_GUILD_INVITE_REQ,								// ��忡 �ʴ��ϱ� ( Guild Member Invitation/Leaving/Kicking Out )
	UG_TUTORIAL_HINT_UPDATE_REQ,						// ��Ʈ ���� ��Ȳ�� ������Ʈ�Ѵ�.
	UG_TUTORIAL_WAIT_CANCEL_REQ,						// Ʃ�丮�� ��� ����ϱ�
	UG_TUTORIAL_PLAY_QUIT_REQ,							// Ʃ�丮�� �÷��� ����ϱ�
	UG_TIMEQUEST_ROOM_LIST_REQ,							// Ÿ�Ӹӽ� ����Ʈ �� ��� ��û
	UG_TIMEQUEST_ROOM_INFO_REQ,							// Ÿ�Ӹӽ� ����Ʈ �� ���� ��û
	UG_TIMEQUEST_ROOM_JOIN_REQ,							// Ÿ�Ӹӽ� ����Ʈ �� ���� ��û
	UG_TIMEQUEST_ROOM_LEAVE_REQ,						// Ÿ�Ӹӽ� ����Ʈ �� ���� ��û
	UG_TIMEQUEST_ROOM_TELEPORT_REQ,						// Ÿ�Ӹӽ� ����Ʈ ���� ��ġ�� �ڷ���Ʈ
	UG_RANKBATTLE_INFO_REQ,
	UG_RANKBATTLE_JOIN_REQ,
	UG_RANKBATTLE_LEAVE_REQ,
	UG_RANKBATTLE_ROOM_LIST_REQ,						// RankBattle �� ��� ��û
	UG_RANKBATTLE_ROOM_INFO_REQ,						// RankBattle �� ���� ��û
	UG_RANKBATTLE_ROOM_CREATE_REQ,						// RankBattle �� ���� ��û
	UG_RANKBATTLE_ROOM_LEAVE_REQ,						// RankBattle �� ���� ��û
	UG_RANKBATTLE_ROOM_CHALLENGE_REQ,					// RankBattle ��� ��û
	UG_RANKBATTLE_ROOM_MATCH_CANCEL_REQ,				// RankBattle ��� �غ� �Ϸ� �˸��� �� �� ����� �����(����)
	UG_DRAGONBALL_CHECK_REQ,							// �巡�ﺼ UI 7�� ��ġOK
	UG_DRAGONBALL_REWARD_REQ,							// �巡�ﺼ �� ������ ���� ���� ���� ��û
	UG_PRIVATESHOP_CREATE_REQ,							// ������ ������ ��û[6/28/2007 SGpro]
	UG_PRIVATESHOP_EXIT_REQ,							// ������ ������ �ݾƶ� ��û[6/28/2007 SGpro]
	UG_PRIVATESHOP_OPEN_REQ,							// ���� ���¸� Open���� �ض� ��û[6/28/2007 SGpro]
	UG_PRIVATESHOP_CLOSE_REQ,							// ���� ���¸� Close�� �ض� ��û[6/28/2007 SGpro]
	UG_PRIVATESHOP_ITEM_UPDATE_REQ,						// ���� �����ۿ� ������ ���� ��û[6/29/2007 SGpro]
	UG_PRIVATESHOP_ITEM_INSERT_REQ,						// ���� ������ �߰� ��û[6/29/2007 SGpro]
	UG_PRIVATESHOP_ITEM_GET_REQ,						// ���� ������ ���� ��û
	UG_PRIVATESHOP_ITEM_DELETE_REQ,						// ���� ������ ���� ��û[6/29/2007 SGpro]
	UG_PRIVATESHOP_ITEM_BUYING_REQ,						// ���� ������ ��� ��û[6/29/2007 SGpro]
	UG_PRIVATESHOP_ENTER_REQ,							// �մ� ����[6/29/2007 SGpro]
	UG_PRIVATESHOP_LEAVE_REQ,							// �մ� ����[6/29/2007 SGpro]
	UG_PRIVATESHOP_ITEM_SELECT_REQ,						// ������ ��[7/19/2007 SGpro]
	UG_MAIL_START_REQ,
	UG_MAIL_SEND_REQ,
	UG_MAIL_READ_REQ,
	UG_MAIL_DEL_REQ,
	UG_MAIL_RETURN_REQ,
	UG_MAIL_RELOAD_REQ,
	UG_MAIL_LOAD_REQ,
	UG_MAIL_ITEM_RECEIVE_REQ,
	UG_MAIL_LOCK_REQ,
	UG_MAIL_MULTI_DEL_REQ,
	UG_PRIVATESHOP_BUSINESS_REQUEST_REQ,				// [10/17/2007 SGpro]
	UG_PRIVATESHOP_BUSINESS_CONSENT_RES,				// [10/17/2007 SGpro]
	UG_PRIVATESHOP_BUSINESS_WAITTIMEOUT_NFY,			// [10/17/2007 SGpro]
	UG_PRIVATESHOP_BUSINESS_PRICEFLUCTUATIONS_REQ,		// [10/17/2007 SGpro]
	UG_PRIVATESHOP_BUSINESS_IMMEDIATE_ITEM_BUYING_REQ,	// [10/17/2007 SGpro]
	UG_PRIVATESHOP_BUSINESS_CANCEL_REQ,					// [10/17/2007 SGpro]
	UG_PORTAL_START_REQ,
	UG_PORTAL_ADD_REQ,
	UG_PORTAL_REQ,
	UG_WAR_FOG_UPDATE_REQ,
	UG_GUILD_FUNCTION_ADD_REQ,
	UG_GUILD_GIVE_ZENNY,
	UG_GUILD_BANK_START_REQ,							// GUILD Warehouse ������ �ε�
	UG_GUILD_BANK_MOVE_REQ,								// GUILD Warehouse �� ������ �̵�
	UG_GUILD_BANK_MOVE_STACK_REQ,						// GUILD Warehouse �� ���þ����� �̵�
	UG_GUILD_BANK_END_REQ,								// GUILD Warehouse �� �ݴ´�.
	UG_GUILD_BANK_ZENNY_REQ,							// GUILD Warehouse �� ���� Ȥ�� �����Ѵ�.
	UG_GUILD_CREATE_MARK_REQ,							// GuildMark Create
	UG_GUILD_CHANGE_MARK_REQ,							// GuildMark Change
	UG_CROSSFIRE_REQ,
	UG_BANK_LOAD_REQ,
	UG_GUILD_CHANGE_NAME_REQ,
	UG_PARTY_SHARETARGET_REQ,							// [3/28/2008 SGpro]
	UG_RIDE_ON_BUS_REQ,
	UG_RIDE_OFF_BUS_REQ,
	UG_TRANSFORM_CANCEL_REQ,							// ���� ��� ��û
	UG_SHOP_ITEM_IDENTIFY_REQ,
	UG_DICE_ROLL_REQ,									// Action Skill �ֻ��� ������
	UG_BUDOKAI_JOIN_INDIVIDUAL_REQ,						// ���� ���
	UG_BUDOKAI_LEAVE_INDIVIDUAL_REQ,					// ���� ���
	UG_BUDOKAI_JOIN_TEAM_INFO_REQ,						//
	UG_BUDOKAI_JOIN_TEAM_REQ,							// �� ���
	UG_BUDOKAI_LEAVE_TEAM_REQ,							// �� ���
	UG_BUDOKAI_LEAVE_TEAM_MEMBER_REQ,					// �� ��� ���
	UG_BUDOKAI_JOIN_INFO_REQ,							// ���� ���� ��û
	UG_BUDOKAI_JOIN_STATE_REQ,							// ���� ���� ��û
	UG_BUDOKAI_MUDOSA_INFO_REQ,							// ������ ���� ��û
	UG_BUDOKAI_MUDOSA_TELEPORT_REQ,						// ������� �ڷ���Ʈ ��û
	UG_BUDOKAI_PARTY_MAKER_REQ,							// ��Ƽ ���� ��û, õ�����Ϲ���ȸ �׽�Ʈ��
	UG_BUDOKAI_SOCIAL_ACTION,
	UG_BUDOKAI_PRIZEWINNER_NAME_REQ,					// ����� / �ؿ���� : ������
	//	UG_BUDOKAI_PRIZEWINNER_TEAM_NAME_REQ,				// ����� / �ؿ���� : ����
	UG_BUDOKAI_GM_BUDOKAI_SERVER_ENTER_REQ,				// õ�����Ϲ���ȸ ������ �ڷ���Ʈ ��û
	UG_BUDOKAI_GM_BUDOKAI_SERVER_LEAVE_REQ,				// õ�����Ϲ���ȸ �������� ���� ������ �̵�
	UG_BUDOKAI_GM_MATCH_PROGRESS_INFO_REQ,				// ��� ���� ���� ��û
	UG_BUDOKAI_GM_MATCH_ARENA_ENTER_REQ,				// ����� ����
	UG_BUDOKAI_GM_MATCH_ARENA_LEAVE_REQ,				// ����� ������
	UG_SCOUTER_TURN_ON,									// ��ī���� ���� ��
	UG_SCOUTER_TURN_OFF,								// ��ī���� ���� ����
	UG_SCOUTER_ITEM_SELL_REQ,							// ��ī���͸� ���� ������ �ȱ�
	UG_SHOP_EVENTITEM_START_REQ,						// [7/15/2008 SGpro]
	UG_SHOP_EVENTITEM_BUY_REQ,							// [7/11/2008 SGpro]
	UG_SHOP_EVENTITEM_END_REQ,							// [7/15/2008 SGpro]
	UG_SHOP_GAMBLE_BUY_REQ,							// [7/11/2008 SGpro]
	UG_PARTY_DIFF_CHANGE_REQ,							// party dungeon diff change
	UG_PARTY_DUNGEON_INIT_REQ,							// party dungeon Init
	UG_SKILL_INIT_REQ,
	UG_PARTY_CHARM_DICE_ROLL_REQ,							// ��Ƽ�� ��� �� �ֻ��� ������
	UG_PARTY_INVEN_LOCK_REQ,
	UG_PARTY_INVEN_RESET_REQ,
	UG_PARTY_INVEN_ACCEPTED_REQ,
	UG_PARTY_INVEN_GIVE_REQ,
	UG_PARTY_INVEN_DICE_START_REQ,
	UG_PARTY_INVEN_DICE_ROLL_REQ,					// ������ �й�� �ֻ��� ������
	UG_TELEPORT_CONFIRM_REQ,
	UG_HOIPOIMIX_ITEM_CHECK_REQ,					// ��������� ���� (�ʿ��� ������ ���� üũ)
	UG_HOIPOIMIX_ITEM_MAKE_REQ,						// ������ �����
	UG_HOIPOIMIX_ITEM_MAKE_EP_REQ,					// ������ ����� �� EP �ֱ�
	UG_HOIPOIMIX_ITEM_MACHINE_MAKE_REQ,				// �ӽ� �����
	UG_HOIPOIMIX_ITEM_MACHINE_DEL_REQ,				// �ӽ� ����
	UG_HOIPOIMIX_JOB_SET_REQ,						// �ͽ� �� ����
	UG_HOIPOIMIX_JOB_RESET_REQ,						// �ͽ� �� ����
	UG_VEHICLE_DIRECT_PLAY_CANCEL_NFY,
	UG_VEHICLE_ENGINE_START_REQ,					// Ż �� �õ� �Ҵ�.
	UG_VEHICLE_ENGINE_STOP_REQ,						// Ż �� �õ� ����.
	UG_VEHICLE_END_REQ,								// Ż �� ��� ����.
	UG_VEHICLE_STUNT_NFY,							// �����̽� �� ����(Ż��)
	UG_VEHICLE_FUEL_REMOVE_NFY,
	UG_VEHICLE_PASSENGER_GETON_REQ,
	UG_VEHICLE_ASK_RES,
	UG_VEHICLE_PASSENGER_GETOFF_REQ,
	UG_DOJO_CREATE_REQ,
	UG_DOJO_DELETE_REQ,
	UG_DOJO_FUNCTION_ADD_REQ,
	UG_DOJO_BANK_HISTORY_REQ,
	UG_DOGI_CREATE_REQ,								// ��������
	UG_DOGI_CHANGE_REQ,								// ��������
	UG_GUILD_DOGI_CREATE_REQ,						// ���ĵ�������
	UG_GUILD_DOGI_CHANGE_REQ,						// ���ĵ�������
	UG_DOJO_SCRAMBLE_REQ,							// ������Ż�� ��û
	UG_DOJO_SCRAMBLE_RESPONSE_REQ,					// ������Ż�� ��û�� ���� ����
	UG_SHOP_NETPYITEM_START_REQ,
	UG_SHOP_NETPYITEM_BUY_REQ,
	UG_SHOP_NETPYITEM_END_REQ,
	UG_WORLD_MAP_STATUS,
	UG_DOJO_NPC_INFO_REQ,							// ����NPC���� ������û
	UG_GAMEGUARD_AUTH_ANSWER_RES,
	UG_GAMEGUARD_HACK_INFO_NFY,
	UG_SKILL_CASTING_CANCELED_NFY,					// ��ų ĳ���� ��� �˸�
	UG_PET_ATTACK_TARGET_NFY,						// ���� ���� ����
	UG_DURATION_ITEM_BUY_REQ,						// �������� ���Ž�
	UG_DURATION_RENEW_REQ,							// �Ⱓ�� ������ �Ⱓ�� ���ſ�û��
	UG_CASHITEM_START_REQ,
	UG_CASHITEM_END_REQ,
	UG_CASHITEM_MOVE_REQ,
	UG_CASHITEM_USE_REQ,
	UG_CASHITEM_HLSHOP_START_REQ,					// ĳ�� ���� ����
	UG_CASHITEM_HLSHOP_END_REQ,
	UG_CASHITEM_BUY_REQ,							// ĳ�� ������ ���Ž�
	UG_BUDOKAI_PRIZEWINNER_TEAM_NAME_REQ,				// ����� / �ؿ���� : ����
	UG_GMT_UPDATE_REQ,
	UG_CHAR_LOC_AFTER_KNOCKDOWN_NFY,
	UG_CHAR_LOC_AFTER_SLIDING_NFY,
	UG_CHAR_LOC_AFTER_PUSH_NFY,

	// GAME TO USER
	GU_PONG = 5000,
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
	GU_CHAR_SITDOWN,
	GU_CHAR_STANDUP,
	GU_CHAR_CAMPING,
	GU_CHAR_FAINT,
	GU_CHAR_KNOCKDOWN,
	GU_CHAR_SLIDING,
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
};

#pragma pack(1)

// USER TO GAME
BEGIN_PACKET(UG_GAME_ENTER_REQ)
	unsigned int accountId;
	unsigned int charId;
	BYTE AuthKey[MAX_AUTHKEY_SIZE];
	bool TutorialMode;
END_PACKET()

BEGIN_PACKET(UG_GAME_LEAVE_REQ)
END_PACKET()

BEGIN_PACKET(UG_AUTH_KEY_FOR_COMMUNITY_SERVER_REQ)
END_PACKET()

BEGIN_PACKET(UG_ENTER_WORLD)
END_PACKET()

BEGIN_PACKET(UG_SERVER_COMMAND)
	WORD MessageLengthInUnicode;
	WCHAR Command[MAX_CHATMESSAGE_USIZE + 1];
END_PACKET()

BEGIN_PACKET(UG_CHAR_READY_FOR_COMMUNITY_SERVER_NFY)
END_PACKET()

BEGIN_PACKET(UG_CHAR_READY_TO_SPAWN)
END_PACKET()

BEGIN_PACKET(UG_CHAR_READY)
	BYTE AvatarType;
END_PACKET()

BEGIN_PACKET(UG_CHAR_MOVE)
	DWORD TimeStamp;
	BYTE AvatarType;
	VECTORXYZ CurLoc;
	VECTORXY CurDir;
	BYTE MoveDirection;
END_PACKET()

BEGIN_PACKET(UG_CHAR_DEST_MOVE)
	DWORD TimeStamp;
	BYTE AvatarType;
	VECTORXYZ CurLoc;
	VECTORXYZ DestLoc;
END_PACKET()

BEGIN_PACKET(UG_CHAR_CHANGE_HEADING)
	DWORD TimeStamp;
	VECTORXYZ CurrentPosition;
	VECTORXYZ CurrentHeading;
END_PACKET()

BEGIN_PACKET(UG_CHAR_MOVE_SYNC)
	DWORD TimeStamp;
	BYTE AvatarType;
	VECTORXYZ CurLoc;
	VECTORXYZ CurDir;
END_PACKET()

BEGIN_PACKET(UG_CHAR_CHANGE_DIRECTION_ON_FLOATING)
	DWORD TimeStamp;
	VECTORXYZ CurDir;
	BYTE MoveDirection;
END_PACKET()

BEGIN_PACKET(UG_CHAR_FOLLOW_MOVE)
	DWORD TimeStamp;
	BYTE AvatarType;
	unsigned int Target;
	float Distance;
	BYTE MovementReason;
END_PACKET()

BEGIN_PACKET(UG_CHAR_DASH_KEYBOARD)
	DWORD TimeStamp;
	VECTORXYZ CurLoc;
	VECTORXY CurDir;
	BYTE MoveDirection;
END_PACKET()

BEGIN_PACKET(UG_CHAR_DASH_MOUSE)
	DWORD TimeStamp;
	VECTORXYZ DestLoc;
END_PACKET()

BEGIN_PACKET(UG_CHAR_JUMP)
	VECTORXYZ CurrentHeading;
END_PACKET()

BEGIN_PACKET(UG_CHAR_JUMP_END)
END_PACKET()

BEGIN_PACKET(UG_CHAR_FALLING)
	bool IsFalling;
	VECTORXYZ CurLoc;
	VECTORXY CurDir;
	BYTE MoveDirection;
END_PACKET()

BEGIN_PACKET(UG_CHAR_TOGG_SITDOWN)
	bool SitDown;
END_PACKET()

BEGIN_PACKET(UG_CHAR_TOGG_FIGHTING)
	BYTE AvatarType;
	bool FightMode;
END_PACKET()

BEGIN_PACKET(UG_CHAR_TOGG_RUNNING)
	bool RunMode;
END_PACKET()

BEGIN_PACKET(UG_CHAR_TARGET_SELECT)
	BYTE AvatarType;
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(UG_CHAR_TARGET_INFO)
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(UG_CHAR_TARGET_FACING)
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(UG_CHAR_ATTACK_BEGIN)
	BYTE AvatarType;
	BYTE Type;
END_PACKET()

BEGIN_PACKET(UG_CHAR_ATTACK_END)
	BYTE AvatarType;
	BYTE Type;
END_PACKET()

BEGIN_PACKET(UG_CHAR_CHARGE)
	bool Charge;
END_PACKET()

BEGIN_PACKET(UG_CHAR_BLOCK_MODE)
	bool IsOn;
END_PACKET()

BEGIN_PACKET(UG_CHAR_TELEPORT_REQ)
END_PACKET()

BEGIN_PACKET(UG_CHAR_BIND_REQ)
	unsigned int bindObjectTblidx;
END_PACKET()

BEGIN_PACKET(UG_CHAR_REVIVAL_REQ)
	BYTE RevivalRequestType;
END_PACKET()

BEGIN_PACKET(UG_CHAR_SERVER_CHANGE_REQ)
END_PACKET()

BEGIN_PACKET(UG_CHAR_CHANNEL_CHANGE_REQ)
	BYTE destChannelId;
END_PACKET()

BEGIN_PACKET(UG_CHAR_EXIT_REQ)
END_PACKET()

BEGIN_PACKET(UG_GAME_EXIT_REQ)
END_PACKET()

BEGIN_PACKET(UG_CHAR_AWAY_REQ)
	bool IsAway;
END_PACKET()

BEGIN_PACKET(UG_CHAR_KEY_UPDATE_REQ)
	BYTE Count;
	SHORTCUT_UPDATE_DATA asData[SHORTCUT_MAX_COUNT];
END_PACKET()

BEGIN_PACKET(UG_CHAR_DIRECT_PLAY_ACK)
END_PACKET()

BEGIN_PACKET(UG_CHAR_KNOCKDOWN_RELEASE_NFY)
END_PACKET()

BEGIN_PACKET(UG_CHAR_SKILL_REQ)
	BYTE AvatarType;
	BYTE SlotIndex;
	BYTE RpBonusType;
	unsigned int Target;
	BYTE ApplyTargetCount;
	unsigned int ApplyTarget[MAX_SKILL_TARGET];
END_PACKET()

BEGIN_PACKET(UG_SKILL_TARGET_LIST)
	BYTE AvatarType;
	BYTE ApplyTargetCount;
	unsigned int ApplyTarget[MAX_SKILL_TARGET];
END_PACKET()

BEGIN_PACKET(UG_SKILL_LEARN_REQ)
	unsigned int skillTblidx;
END_PACKET()

BEGIN_PACKET(UG_SKILL_UPGRADE_REQ)
	BYTE SlotIndex;
END_PACKET()

BEGIN_PACKET(UG_SKILL_RP_BONUS_SETTING_REQ)
	BYTE SlotIndex;
	BYTE RpBonusType;
	bool IsRpBonusAuto;
END_PACKET()

BEGIN_PACKET(UG_HTB_START_REQ)
	unsigned int Target;
	BYTE SkillSlot;
END_PACKET()

BEGIN_PACKET(UG_HTB_LEARN_REQ)
	unsigned int Trainer;
	unsigned int skillId;
END_PACKET()

BEGIN_PACKET(UG_HTB_FORWARD_REQ)
	VECTORXYZ CurLoc;
	VECTORXY CurDir;
END_PACKET()

BEGIN_PACKET(UG_HTB_RP_BALL_USE_REQ)
	BYTE RpBallCount;
END_PACKET()

BEGIN_PACKET(UG_BUFF_DROP_REQ)
	BYTE SourceType;
	unsigned int tblidx;
END_PACKET()

BEGIN_PACKET(UG_ITEM_MOVE_REQ)
	BYTE SrcPlace;
	BYTE SrcPos;
	BYTE DestPlace;
	BYTE DestPos;
END_PACKET()

BEGIN_PACKET(UG_ITEM_MOVE_STACK_REQ)
	BYTE SrcPlace;
	BYTE SrcPos;
	BYTE DestPlace;
	BYTE DestPos;
	BYTE StackCount;
END_PACKET()

BEGIN_PACKET(UG_ITEM_DELETE_REQ)
	BYTE SrcPlace;
	BYTE SrcPos;
END_PACKET()

BEGIN_PACKET(UG_ITEM_EQUIP_REPAIR_REQ)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(UG_ITEM_PICK_REQ)
	BYTE AvatarType;
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(UG_ITEM_REPAIR_REQ)
	unsigned int handle;
	BYTE Place;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(UG_ITEM_USE_REQ)
	unsigned int Target;
	BYTE Place;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(UG_ITEM_UPGRADE_REQ)
	unsigned int handle;
	BYTE ItemPlace;
	BYTE ItemPos;
	BYTE StonPlace;
	BYTE StonPos;
	BYTE PosNum;
END_PACKET()

BEGIN_PACKET(UG_ITEM_IDENTIFY_REQ)
	BYTE Place;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(UG_ZENNY_PICK_REQ)
	BYTE AvatarType;
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(UG_SHOP_START_REQ)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(UG_SHOP_BUY_REQ)
	unsigned int handle;
	BYTE BuyCount;
	SHOP_BUYCART BuyData[MAX_SHOPCART];
END_PACKET()

BEGIN_PACKET(UG_SHOP_SELL_REQ)
	unsigned int handle;
	BYTE SellCount;
	SHOP_SELLCART SellData[MAX_SHOPCART];
END_PACKET()

BEGIN_PACKET(UG_SHOP_END_REQ)
END_PACKET()

BEGIN_PACKET(UG_SHOP_SKILL_BUY_REQ)
	unsigned int Npchandle;
	BYTE MerchantTab;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(UG_PARTY_CREATE_REQ)
	WCHAR PartyName[MAX_PARTYNAME_SIZE + 1];
END_PACKET()

BEGIN_PACKET(UG_PARTY_DISBAND_REQ)
END_PACKET()

BEGIN_PACKET(UG_PARTY_INVITE_REQ)
	unsigned int Target;
	WCHAR PartyName[MAX_PARTYNAME_SIZE + 1];
END_PACKET()

BEGIN_PACKET(UG_PARTY_INVITE_CHARID_REQ)
	unsigned int targetCharId;
	WCHAR PartyName[MAX_PARTYNAME_SIZE + 1];
END_PACKET()

BEGIN_PACKET(UG_PARTY_INVITE_CHAR_NAME_REQ)
	WCHAR TargetName[MAX_CHARNAME_SIZE + 1];
	WCHAR PartyName[MAX_PARTYNAME_SIZE + 1];
END_PACKET()

BEGIN_PACKET(UG_PARTY_RESPONSE_INVITATION)
	BYTE Response;
END_PACKET()

BEGIN_PACKET(UG_PARTY_LEAVE_REQ)
END_PACKET()

BEGIN_PACKET(UG_PARTY_KICK_OUT_REQ)
	unsigned int TargetMember;
END_PACKET()

BEGIN_PACKET(UG_PARTY_CHANGE_LEADER_REQ)
	unsigned int TargetMember;
END_PACKET()

BEGIN_PACKET(UG_PARTY_OPEN_CHARM_SLOT_REQ)
	BYTE CharmInventoryIndex;
END_PACKET()

BEGIN_PACKET(UG_PARTY_CLOSE_CHARM_SLOT_REQ)
END_PACKET()

BEGIN_PACKET(UG_PARTY_REGISTER_VICTIM_ITEM_REQ)
	BYTE SrcPlace;
	BYTE SrcPos;
	BYTE DestSlotIndex;
END_PACKET()

BEGIN_PACKET(UG_PARTY_UNREGISTER_VICTIM_ITEM_REQ)
	BYTE DestSlotIndex;
END_PACKET()

BEGIN_PACKET(UG_PARTY_REGISTER_VICTIM_ZENNY_REQ)
	DWORD Zenny;
END_PACKET()

BEGIN_PACKET(UG_PARTY_UNREGISTER_VICTIM_ZENNY_REQ)
	DWORD Zenny;
END_PACKET()

BEGIN_PACKET(UG_PARTY_DECLARE_ZENNY_REQ)
	DWORD ZennyToDeclare;
END_PACKET()

BEGIN_PACKET(UG_PARTY_ACTIVATE_CHARM_REQ)
END_PACKET()

BEGIN_PACKET(UG_PARTY_DEACTIVATE_CHARM_REQ)
	BYTE CharmInventoryIndex;
END_PACKET()

BEGIN_PACKET(UG_PARTY_CHANGE_ZENNY_LOOTING_METHOD_REQ)
	BYTE LootingMethod;
END_PACKET()

BEGIN_PACKET(UG_PARTY_CHANGE_ITEM_LOOTING_METHOD_REQ)
	BYTE LootingMethod;
END_PACKET()

BEGIN_PACKET(UG_PARTY_INVEST_ZENNY_REQ)
	BYTE Pos;
	DWORD ZennyToInvest;
END_PACKET()

BEGIN_PACKET(UG_PARTY_INVEN_ITEM_RANK_SET_REQ)
	BYTE ItemRank;
END_PACKET()

BEGIN_PACKET(UG_BANK_START_REQ)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(UG_BANK_MOVE_REQ)
	unsigned int handle;
	BYTE SrcPlace;
	BYTE SrcPos;
	BYTE DestPlace;
	BYTE DestPos;
END_PACKET()

BEGIN_PACKET(UG_BANK_MOVE_STACK_REQ)
	unsigned int handle;
	BYTE SrcPlace;
	BYTE SrcPos;
	BYTE DestPlace;
	BYTE DestPos;
	BYTE StackCount;
END_PACKET()

BEGIN_PACKET(UG_BANK_END_REQ)
END_PACKET()

BEGIN_PACKET(UG_BANK_ZENNY_REQ)
	unsigned int handle;
	DWORD Zenny;
	bool IsSave;
END_PACKET()

BEGIN_PACKET(UG_BANK_BUY_REQ)
	unsigned int Npchandle;
	BYTE MerchantTab;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(UG_BANK_ITEM_DELETE_REQ)
BYTE				byPlace;
BYTE				byPos;
END_PACKET()

BEGIN_PACKET(UG_SCOUTER_INDICATOR_REQ)
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(UG_SCOUTER_PREDICT_REQ)
	BYTE PusNum;
END_PACKET()

BEGIN_PACKET(UG_SCOUTER_EQUIP_CHECK_REQ)
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(UG_SCOUTER_CHIP_REMOVE_ALL_REQ)
END_PACKET()

BEGIN_PACKET(UG_SOCIAL_ACTION)
	unsigned int socialActionId;
END_PACKET()

BEGIN_PACKET(UG_TS_CONFIRM_STEP_REQ)
	BYTE TsType;
	WORD Id;
	BYTE CurId;
	BYTE NextId;
	DWORD Param;
	BYTE EventType;
	DWORD EventData;
END_PACKET()

BEGIN_PACKET(UG_TS_UPDATE_STATE)
	BYTE TsType;
	WORD Id;
	BYTE Type;
	WORD TSState;
	DWORD Param;
END_PACKET()

BEGIN_PACKET(UG_TS_EXCUTE_TRIGGER_OBJECT)
	unsigned int Source;
	unsigned int Target;
	BYTE EvtGenType;
	unsigned int uiParam;
END_PACKET()

BEGIN_PACKET(UG_QUEST_ITEM_MOVE_REQ)
	BYTE SrcPos;
	BYTE DestPos;
END_PACKET()

BEGIN_PACKET(UG_QUEST_ITEM_DELETE_REQ)
	BYTE DeletePos;
END_PACKET()

BEGIN_PACKET(UG_QUEST_GIVEUP_REQ)
	WORD Id;
END_PACKET()

BEGIN_PACKET(UG_QUEST_SHARE)
	WORD Id;
END_PACKET()

BEGIN_PACKET(UG_QUEST_OBJECT_VISIT_REQ)
	WORD Id;
	unsigned int worldId;
	BYTE ObjType;
	unsigned int objectTblidx;
END_PACKET()

BEGIN_PACKET(UG_FREEBATTLE_CHALLENGE_REQ)
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(UG_FREEBATTLE_ACCEPT_RES)
	BYTE Accept;
END_PACKET()

BEGIN_PACKET(UG_QUICK_SLOT_UPDATE_REQ)
	unsigned int tblidx;
	BYTE SlotID;
	BYTE Type;
	BYTE Place;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(UG_QUICK_SLOT_DEL_REQ)
	BYTE SlotID;
END_PACKET()

BEGIN_PACKET(UG_PET_DISMISS_PET_REQ)
	BYTE AvatarType; 
END_PACKET()

BEGIN_PACKET(UG_TRADE_START_REQ) 
	unsigned int Target; 
END_PACKET()

BEGIN_PACKET(UG_TRADE_OK_RES)
	unsigned int handle;
	BYTE OK;
END_PACKET()

BEGIN_PACKET(UG_TRADE_ADD_REQ)
	unsigned int Target;
	unsigned int Item;
	BYTE Count;
END_PACKET()

BEGIN_PACKET(UG_TRADE_DEL_REQ)
	unsigned int Target;
	unsigned int Item;
END_PACKET()

BEGIN_PACKET(UG_TRADE_MODIFY_REQ)
	unsigned int Target;
	unsigned int Item;
	BYTE Count;
END_PACKET()

BEGIN_PACKET(UG_TRADE_ZENNY_UPDATE_REQ)
	unsigned int Target;
	DWORD Zenny;
END_PACKET()

BEGIN_PACKET(UG_TRADE_END_REQ)
	unsigned int Target;
	DWORD PacketCount;
	bool IsSet;
END_PACKET()

BEGIN_PACKET(UG_TRADE_CANCEL_REQ)
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(UG_TRADE_DENY_REQ)
	bool IsDeny;
END_PACKET()
	
BEGIN_PACKET(UG_GUILD_CREATE_REQ)
	unsigned int GuildManagerNpc;
	WCHAR GuildName[MAX_GUILDNAME_USIZE + 1];
END_PACKET()

BEGIN_PACKET(UG_GUILD_INVITE_REQ)
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(UG_TUTORIAL_HINT_UPDATE_REQ)
	DWORD TutorialHint;
END_PACKET()

BEGIN_PACKET(UG_TUTORIAL_WAIT_CANCEL_REQ)
END_PACKET()

BEGIN_PACKET(UG_TUTORIAL_PLAY_QUIT_REQ)
END_PACKET()

BEGIN_PACKET(UG_TIMEQUEST_ROOM_LIST_REQ)
	unsigned int TimeQuestNpc;
END_PACKET()

BEGIN_PACKET(UG_TIMEQUEST_ROOM_INFO_REQ)
END_PACKET()

BEGIN_PACKET(UG_TIMEQUEST_ROOM_JOIN_REQ)
	unsigned int TimeQuestNpc;
	BYTE TimeQuestMode;
	bool IsRetry;
END_PACKET()

BEGIN_PACKET(UG_TIMEQUEST_ROOM_LEAVE_REQ)
END_PACKET()

BEGIN_PACKET(UG_TIMEQUEST_ROOM_TELEPORT_REQ)
END_PACKET()

BEGIN_PACKET(UG_RANKBATTLE_INFO_REQ)
	BYTE BattleMode;
END_PACKET()

BEGIN_PACKET(UG_RANKBATTLE_JOIN_REQ)
	unsigned int BoardObject;
	unsigned int rankBattleTblidx;
END_PACKET()

BEGIN_PACKET(UG_RANKBATTLE_LEAVE_REQ)
	unsigned int rankBattleTblidx;
END_PACKET()

BEGIN_PACKET(UG_RANKBATTLE_ROOM_LIST_REQ)
	unsigned int RankBattleObject;
	WORD Page;
END_PACKET()

BEGIN_PACKET(UG_RANKBATTLE_ROOM_INFO_REQ)
	unsigned int RankBattleObject;
	unsigned int roomId;
END_PACKET()

BEGIN_PACKET(UG_RANKBATTLE_ROOM_CREATE_REQ)
	unsigned int RankBattleObject;
END_PACKET()

BEGIN_PACKET(UG_RANKBATTLE_ROOM_LEAVE_REQ)
END_PACKET()

BEGIN_PACKET(UG_RANKBATTLE_ROOM_CHALLENGE_REQ)
	unsigned int RankBattleObject;
	unsigned int roomId;
END_PACKET()

BEGIN_PACKET(UG_RANKBATTLE_ROOM_MATCH_CANCEL_REQ)
END_PACKET()

BEGIN_PACKET(UG_DRAGONBALL_CHECK_REQ)
	unsigned int Object;
	ITEMPOS_DATA sData[MAX_DRAGONBALLS];
END_PACKET()

BEGIN_PACKET(UG_DRAGONBALL_REWARD_REQ)
	unsigned int Object;
	unsigned int rewardTblidx;
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_CREATE_REQ)
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_EXIT_REQ)
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_OPEN_REQ)
	WCHAR PrivateShopName[MAX_PRIVATESHOPNAME_USIZE + 1];
	bool IsOwnerEmpty;
	BYTE NoticeSize;
	WCHAR Notice[MAX_PRIVATESHOPNOTICE_USIZE + 1];
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_CLOSE_REQ)
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_ITEM_GET_REQ)
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_ITEM_INSERT_REQ)
	BYTE PrivateShopInventorySlotPos;
	BYTE InventoryPlace;
	BYTE InventoryPos;
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_ITEM_UPDATE_REQ)
	BYTE PrivateShopInventorySlotPos;
	DWORD Zenny;
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_ITEM_DELETE_REQ)
	BYTE PrivateShopInventorySlotPos;
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_ITEM_BUYING_REQ)
	unsigned int Owner;
	BYTE PrivateShopInventorySlotPos[MAX_SHOPCART];
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_ENTER_REQ)
	unsigned int Owner;
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_LEAVE_REQ)
	unsigned int Owner;
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_ITEM_SELECT_REQ)
	unsigned int Owner;
	BYTE PrivateShopInventorySlotPos;
	BYTE ItemState;
END_PACKET()

BEGIN_PACKET(UG_MAIL_START_REQ)
	unsigned int Object; 
END_PACKET()

BEGIN_PACKET(UG_MAIL_SEND_REQ)
	unsigned int Object;
	BYTE MailType;	
	ITEMPOS_DATA ItemData;
	DWORD Zenny;
	BYTE Day;
	WCHAR TargetName[MAX_CHARNAME_SIZE + 1];
	BYTE TextSize;
	WCHAR Text[MAX_MAILMESSAGE_SIZE + 1];
END_PACKET()

BEGIN_PACKET(UG_MAIL_READ_REQ)
	unsigned int Object;
	unsigned int mailID;
END_PACKET()

BEGIN_PACKET(UG_MAIL_DEL_REQ)
	unsigned int Object;
	unsigned int mailID;
END_PACKET()

BEGIN_PACKET(UG_MAIL_RETURN_REQ)
	unsigned int Object;
	unsigned int mailID;
END_PACKET()

BEGIN_PACKET(UG_MAIL_RELOAD_REQ)
	unsigned int Object;
END_PACKET()

BEGIN_PACKET(UG_MAIL_LOAD_REQ)
	unsigned int Object;
	BYTE Count;
	unsigned int MailID[MAX_MAILSLOT_COUNT];
END_PACKET()

BEGIN_PACKET(UG_MAIL_ITEM_RECEIVE_REQ)
	unsigned int Object;
	unsigned int mailID;
END_PACKET()

BEGIN_PACKET(UG_MAIL_LOCK_REQ)
	unsigned int Object;
	unsigned int mailID;
	bool IsLock;
END_PACKET()

BEGIN_PACKET(UG_MAIL_MULTI_DEL_REQ)
	unsigned int Object;
	BYTE Count;
	unsigned int MailID[MAX_MULTIDEL_COUNT];
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_BUSINESS_REQUEST_REQ)
	unsigned int Owner;
	BYTE PrivateShopInventorySlotPos;
	unsigned int itemNo;
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_BUSINESS_CONSENT_RES)
	bool Result;
	unsigned int itemNo;
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_BUSINESS_WAITTIMEOUT_NFY)
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_BUSINESS_PRICEFLUCTUATIONS_REQ)
	DWORD PriceFluctuationsZenny;
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_BUSINESS_IMMEDIATE_ITEM_BUYING_REQ)
	unsigned int Owner;
	unsigned __int16 PriceFluctuationsCounter;
END_PACKET()

BEGIN_PACKET(UG_PRIVATESHOP_BUSINESS_CANCEL_REQ)
	unsigned int Owner;
END_PACKET()

BEGIN_PACKET(UG_PORTAL_START_REQ)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(UG_PORTAL_ADD_REQ)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(UG_PORTAL_REQ)
	unsigned int handle;
	BYTE Point;
END_PACKET()

BEGIN_PACKET(UG_PING)
END_PACKET()

BEGIN_PACKET(UG_WAR_FOG_UPDATE_REQ)
	unsigned int Object;		
END_PACKET()

BEGIN_PACKET(UG_GUILD_FUNCTION_ADD_REQ)
	unsigned int GuildManagerNpc;
	BYTE Function;
END_PACKET()

BEGIN_PACKET(UG_GUILD_GIVE_ZENNY)
	unsigned int GuildManagerNpc;
	DWORD Zenny;
END_PACKET()

BEGIN_PACKET(UG_GUILD_BANK_START_REQ)
	unsigned int handle;			// â�� NpcHandle
END_PACKET()

BEGIN_PACKET(UG_GUILD_BANK_MOVE_REQ)
	unsigned int handle;			// â�� NpcHandle	
	BYTE SrcPlace;
	BYTE SrcPos;
	BYTE DestPlace;
	BYTE DestPos;
END_PACKET()

BEGIN_PACKET(UG_GUILD_BANK_MOVE_STACK_REQ)
	unsigned int handle;
	BYTE SrcPlace;
	BYTE SrcPos;
	BYTE DestPlace;
	BYTE DestPos;
	BYTE StackCount;
END_PACKET()

BEGIN_PACKET(UG_GUILD_BANK_END_REQ)
END_PACKET()

BEGIN_PACKET(UG_GUILD_BANK_ZENNY_REQ)
	unsigned int handle;
	DWORD Zenny;
	bool IsSave;
END_PACKET()

BEGIN_PACKET(UG_CROSSFIRE_REQ)
	unsigned int AnotherUser;
END_PACKET()

BEGIN_PACKET(UG_GUILD_CREATE_MARK_REQ)
	GUILD_MARK Mark;
END_PACKET()

BEGIN_PACKET(UG_GUILD_CHANGE_MARK_REQ)
	GUILD_MARK Mark;
END_PACKET()

BEGIN_PACKET(UG_BANK_LOAD_REQ)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(UG_GUILD_CHANGE_NAME_REQ)
	unsigned int GuildManagerNpc;
	WCHAR GuildName[MAX_GUILDNAME_USIZE + 1];
END_PACKET()

BEGIN_PACKET(UG_PARTY_SHARETARGET_REQ)
	BYTE Slot;
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(UG_RIDE_ON_BUS_REQ)
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(UG_RIDE_OFF_BUS_REQ)
END_PACKET()

BEGIN_PACKET(UG_TRANSFORM_CANCEL_REQ)
END_PACKET()

BEGIN_PACKET(UG_SHOP_ITEM_IDENTIFY_REQ)
	unsigned int Npchandle;
	BYTE Place;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(UG_DICE_ROLL_REQ)
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_JOIN_INDIVIDUAL_REQ)
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_LEAVE_INDIVIDUAL_REQ)
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_JOIN_TEAM_INFO_REQ)
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_JOIN_TEAM_REQ)
	WCHAR TeamName[MAX_BUDOKAITEAMNAME_USIZE + 1];
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_LEAVE_TEAM_REQ)
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_LEAVE_TEAM_MEMBER_REQ)
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_JOIN_INFO_REQ)
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_JOIN_STATE_REQ)
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_MUDOSA_INFO_REQ)
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_MUDOSA_TELEPORT_REQ)
	BYTE MudosaIndex;
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_PARTY_MAKER_REQ)
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_SOCIAL_ACTION)
	WORD socialAction;
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_PRIZEWINNER_NAME_REQ)
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_PRIZEWINNER_TEAM_NAME_REQ)
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_GM_BUDOKAI_SERVER_ENTER_REQ)
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_GM_BUDOKAI_SERVER_LEAVE_REQ)
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_GM_MATCH_PROGRESS_INFO_REQ)
	BYTE yMatchType;
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_GM_MATCH_ARENA_ENTER_REQ)
	BYTE MatchType;
	BYTE MatchWorldType;
	BYTE MatchDepth;
	BYTE MatchIndex;
END_PACKET()

BEGIN_PACKET(UG_BUDOKAI_GM_MATCH_ARENA_LEAVE_REQ)
END_PACKET()

BEGIN_PACKET(UG_SCOUTER_TURN_ON)
END_PACKET()

BEGIN_PACKET(UG_SCOUTER_TURN_OFF)
END_PACKET()

BEGIN_PACKET(UG_SCOUTER_ITEM_SELL_REQ)
	BYTE Place;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(UG_SHOP_EVENTITEM_START_REQ)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(UG_SHOP_EVENTITEM_BUY_REQ)
	unsigned int handle;
	BYTE BuyCount;
	SHOP_BUYCART BuyData[MAX_SHOPCART];
END_PACKET()

BEGIN_PACKET(UG_SHOP_EVENTITEM_END_REQ)
END_PACKET()

BEGIN_PACKET(UG_SHOP_GAMBLE_BUY_REQ)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(UG_PARTY_DIFF_CHANGE_REQ)
	PARTYDUNGEON_STATE Diff;
END_PACKET()

BEGIN_PACKET(UG_PARTY_DUNGEON_INIT_REQ)
END_PACKET()

BEGIN_PACKET(UG_SKILL_INIT_REQ)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(UG_PARTY_CHARM_DICE_ROLL_REQ)
END_PACKET()

BEGIN_PACKET(UG_PARTY_INVEN_LOCK_REQ)
	bool IsOpen;
END_PACKET()

BEGIN_PACKET(UG_PARTY_INVEN_RESET_REQ)
END_PACKET()

BEGIN_PACKET(UG_PARTY_INVEN_ACCEPTED_REQ)
	BYTE byItemSlot;
END_PACKET()

BEGIN_PACKET(UG_PARTY_INVEN_GIVE_REQ)
	BYTE ItemSlot;
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(UG_PARTY_INVEN_DICE_START_REQ)
	BYTE ItemSlot;	
END_PACKET()

BEGIN_PACKET(UG_PARTY_INVEN_DICE_ROLL_REQ)
END_PACKET()

BEGIN_PACKET(UG_TELEPORT_CONFIRM_REQ)
	bool Teleport;
	BYTE TeleportIndex;
END_PACKET()

BEGIN_PACKET(UG_HOIPOIMIX_ITEM_CHECK_REQ)
	unsigned int objHandle;
	unsigned int recipeTblidx;
END_PACKET()

BEGIN_PACKET(UG_HOIPOIMIX_ITEM_MAKE_REQ)
	unsigned int objHandle;
	unsigned int recipeTblidx;
	bool IsEPUseSuccess;
END_PACKET()
			
BEGIN_PACKET(UG_HOIPOIMIX_ITEM_MAKE_EP_REQ)
	unsigned int recipeTblidx;
END_PACKET()
	
BEGIN_PACKET(UG_HOIPOIMIX_ITEM_MACHINE_DEL_REQ)
	unsigned int objHandle;
END_PACKET()

BEGIN_PACKET(UG_HOIPOIMIX_JOB_SET_REQ)
	unsigned int Npchandle;
	BYTE RecipeType;
END_PACKET()

BEGIN_PACKET(UG_HOIPOIMIX_JOB_RESET_REQ)
	unsigned int Npchandle;
	BYTE RecipeType;
END_PACKET()

BEGIN_PACKET(UG_VEHICLE_DIRECT_PLAY_CANCEL_NFY)
END_PACKET()

BEGIN_PACKET(UG_VEHICLE_ENGINE_START_REQ)
	unsigned int idFuelItemTblidx;
END_PACKET()

BEGIN_PACKET(UG_VEHICLE_ENGINE_STOP_REQ)
END_PACKET()

BEGIN_PACKET(UG_VEHICLE_END_REQ)
END_PACKET()

BEGIN_PACKET(UG_VEHICLE_STUNT_NFY)
END_PACKET()

BEGIN_PACKET(UG_VEHICLE_FUEL_REMOVE_NFY)
	unsigned int idFuelItemTblidx;
END_PACKET()

BEGIN_PACKET(UG_DOJO_CREATE_REQ)
	unsigned int Object;
END_PACKET()

BEGIN_PACKET(UG_DOJO_DELETE_REQ)
unsigned int Object;
unsigned int				dojoTblidx;
END_PACKET()

BEGIN_PACKET(UG_DOJO_FUNCTION_ADD_REQ)
	unsigned int GuildManagerNpc;
	BYTE Function;
	BYTE Place;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(UG_DOJO_BANK_HISTORY_REQ)
unsigned int Object;
END_PACKET()

BEGIN_PACKET(UG_DOGI_CREATE_REQ)
	unsigned int Object;
	DOGIDATA Data;
END_PACKET()

BEGIN_PACKET(UG_DOGI_CHANGE_REQ)
	unsigned int Object;
	DOGIDATA Data;
END_PACKET()

BEGIN_PACKET(UG_GUILD_DOGI_CREATE_REQ)
	unsigned int Object;
	DOGIDATA Data;
END_PACKET()

BEGIN_PACKET(UG_GUILD_DOGI_CHANGE_REQ)
	unsigned int Object;
	DOGIDATA Data;
END_PACKET()

BEGIN_PACKET(UG_DOJO_SCRAMBLE_REQ)
	unsigned int NpcHandle;
END_PACKET()

BEGIN_PACKET(UG_DOJO_SCRAMBLE_RESPONSE_REQ)
	bool IsAccept;
END_PACKET()
						
BEGIN_PACKET(UG_SHOP_NETPYITEM_START_REQ)
END_PACKET()

BEGIN_PACKET(UG_SHOP_NETPYITEM_BUY_REQ)
	BYTE BuyCount;
	SHOP_BUYCART BuyData[MAX_SHOPCART];
END_PACKET()

BEGIN_PACKET(UG_SHOP_NETPYITEM_END_REQ)
END_PACKET()

BEGIN_PACKET(UG_WORLD_MAP_STATUS)
	bool IsWorldMapOpen;
END_PACKET()

BEGIN_PACKET(UG_DOJO_NPC_INFO_REQ)
	unsigned int NpcHandle;
END_PACKET()

BEGIN_PACKET(UG_GAMEGUARD_AUTH_ANSWER_RES)
	BYTE DataSize;
	BYTE Data[UCHAR_MAX];
END_PACKET()

BEGIN_PACKET(UG_GAMEGUARD_HACK_INFO_NFY)
	WORD DataSize;
	BYTE Data[USHRT_MAX];
END_PACKET()

BEGIN_PACKET(UG_SKILL_CASTING_CANCELED_NFY)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(UG_PET_ATTACK_TARGET_NFY)
	BYTE AvatarType;
END_PACKET()

BEGIN_PACKET(UG_DURATION_ITEM_BUY_REQ)
	unsigned int merchantTblidx;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(UG_DURATION_RENEW_REQ)
	unsigned int ItemHandle;
END_PACKET()

BEGIN_PACKET(UG_CASHITEM_START_REQ)
END_PACKET()

BEGIN_PACKET(UG_CASHITEM_END_REQ)
END_PACKET()

BEGIN_PACKET(UG_CASHITEM_MOVE_REQ)
	DWORD ProductId;
END_PACKET()

BEGIN_PACKET(UG_CASHITEM_USE_REQ)
	DWORD ProductId;
END_PACKET()

BEGIN_PACKET(UG_CASHITEM_HLSHOP_START_REQ)
END_PACKET()

BEGIN_PACKET(UG_CASHITEM_HLSHOP_END_REQ)
END_PACKET()

BEGIN_PACKET(UG_CASHITEM_BUY_REQ)
BYTE				byBuyCount;
DWORD				adwIdxHlsTable[MAX_HLSSHOP_CART];
END_PACKET()

BEGIN_PACKET(UG_GMT_UPDATE_REQ)
	GAMEMANIA_TIME	Next;
END_PACKET()

BEGIN_PACKET(UG_CHAR_LOC_AFTER_KNOCKDOWN_NFY)
	VECTORXYZ CurLoc;
	VECTORXY CurDir;
END_PACKET()

BEGIN_PACKET(UG_CHAR_LOC_AFTER_SLIDING_NFY)
	VECTORXYZ CurLoc;
	VECTORXY CurDir;
END_PACKET()

BEGIN_PACKET(UG_CHAR_LOC_AFTER_PUSH_NFY)
	VECTORXYZ CurLoc;
	VECTORXY CurDir;
END_PACKET()

// GAME TO USER
BEGIN_PACKET(GU_PONG)
END_PACKET()

BEGIN_PACKET(GU_SESSION_STATE_WRONG)
	WORD PrevOPCode;
END_PACKET()

BEGIN_PACKET(GU_CHAR_STATE_WRONG)
	WORD PrevOPCode;
	unsigned int handle;
	BYTE StateID;
END_PACKET()

BEGIN_PACKET(GU_GAME_ENTER_RES)
	WORD ResultCode;
	char CommunityServerIP[MAX_SRVADDR_SIZE + 1];
	WORD CommunityServerPort;
	time_t EnterTime;
END_PACKET()

BEGIN_PACKET(GU_GAME_LEAVE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_ENTER_WORLD_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_ENTER_WORLD_COMPLETE)
END_PACKET()

BEGIN_PACKET(GU_AUTH_KEY_FOR_COMMUNITY_SERVER_RES)
	WORD ResultCode;
	BYTE AuthKey[MAX_AUTHKEY_SIZE];
END_PACKET()

BEGIN_PACKET(GU_AVATAR_CHAR_INFO)
	unsigned int handle;
	PCHAR_PROFILE PcProfile;
	WORD CharStateSize;
	CHARSTATE CharState;
END_PACKET()

BEGIN_PACKET(GU_AVATAR_ITEM_INFO)
	BYTE BeginCount;
	BYTE ItemCount;
	ITEM_PROFILE ItemProfile[MAX_INVEN_ITEMCOUNT];
END_PACKET()

BEGIN_PACKET(GU_AVATAR_SKILL_INFO)
	BYTE SkillCount;
	SKILL_INFO SkillInfo[MAX_PCHARSKILLS_COUNT];
END_PACKET()

BEGIN_PACKET(GU_AVATAR_HTB_INFO)
	BYTE HTBSkillCount;
	HTB_SKILL_INFO HTBSkillnfo[MAX_PCHARHTBSKILLS_COUNT];
END_PACKET()

BEGIN_PACKET(GU_AVATAR_BUFF_INFO)
	BYTE BuffCount;
	BUFF_INFO BuffInfo[MAX_PCHARBUFF_COUNT + MAX_PCHARDEBUFF_COUNT];
END_PACKET()

BEGIN_PACKET(GU_AVATAR_WORLD_INFO)
	VECTORXYZ CurLoc;
	VECTORXYZ CurDir;
	WORLD_INFO worldInfo;
	BYTE DojoCount;
	DOJO_BRIEF DojoData[MAX_WOLDDOJO_COUNT];
END_PACKET()

BEGIN_PACKET(GU_AVATAR_ZONE_INFO)
	WORLD_ZONE_INFO zoneInfo;
END_PACKET()

BEGIN_PACKET(GU_AVATAR_QUEST_COMPLETE_INFO)
	COMPLETE_QUEST_INFO	completeInfo;
END_PACKET()

BEGIN_PACKET(GU_AVATAR_QUEST_PROGRESS_INFO)
	BYTE ProgressCount;
	PROGRESS_QUEST_INFO	progressInfo[1];
END_PACKET()

BEGIN_PACKET(GU_AVATAR_QUEST_INVENTORY_INFO)
	BYTE ItemCount;
	QUESTITEM_DATA InventoryInfo[1];
END_PACKET()

BEGIN_PACKET(GU_AVATAR_INFO_END)
END_PACKET()

BEGIN_PACKET(GU_AVATAR_ATTRIBUTE_UPDATE)
	unsigned int Handle;
	BYTE AttributeTotalCount;
	BYTE FlexibleField[((UCHAR_MAX - 1) / 8 + 1) + sizeof(AVATAR_ATTRIBUTE)];
END_PACKET()

BEGIN_PACKET(GU_OBJECT_CREATE)
	unsigned int handle;
	OBJECT_INFO	ObjectInfo;
END_PACKET()

BEGIN_PACKET(GU_OBJECT_DESTROY)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(GU_CHAR_MOVE)
	unsigned int handle;
	DWORD TimeStamp;
	VECTORXYZ CurLoc;
	VECTORXYZ CurDir;
	BYTE MoveDirection;
	BYTE MoveFlag;
END_PACKET()

BEGIN_PACKET(GU_CHAR_DEST_MOVE)
	unsigned int handle;
	DWORD TimeStamp;
	VECTORXYZ CurLoc;
	BYTE yMoveFlag;
	bool HaveSecondDestLoc;
	VECTORXYZ SecondDestLoc;
	BYTE DestLocCount;
	VECTORXYZ DestLoc[MAX_NEXT_DEST_LOC_COUNT];
END_PACKET()

BEGIN_PACKET(GU_CHAR_CHANGE_HEADING)
	unsigned int handle;
	DWORD TimeStamp;
	VECTORXYZ NewHeading;
	VECTORXYZ NewLoc;
END_PACKET()

BEGIN_PACKET(GU_CHAR_MOVE_SYNC)
	unsigned int handle;
	DWORD TimeStamp;
	VECTORXYZ CurLoc;
	VECTORXYZ CurDir;
END_PACKET()

BEGIN_PACKET(GU_CHAR_CHANGE_JUMP_DIRECTION)
	unsigned int handle;
	DWORD TimeStamp;
	VECTORXYZ JumpDir;
END_PACKET()

BEGIN_PACKET(GU_CHAR_CHANGE_DIRECTION_ON_FLOATING)
	unsigned int Subject;
	DWORD TimeStamp;
	VECTORXYZ CurDir;
	BYTE MoveDirection;
END_PACKET()

BEGIN_PACKET(GU_CHAR_FOLLOW_MOVE)
	unsigned int handle;
	DWORD TimeStamp;
	unsigned int Target;
	float Distance;
	BYTE MovementReason;
	BYTE MoveFlag;
END_PACKET()

BEGIN_PACKET(GU_CHAR_JUMP)
	unsigned int handle;
	VECTORXYZ CurrentHeading;
	VECTORXYZ JumpDir;
	BYTE MoveDirection;
END_PACKET()

BEGIN_PACKET(GU_CHAR_JUMP_END)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(GU_CHAR_PUSHED_NFY)
	unsigned int Subject;
	BYTE AttackResult;
	WORD AttackResultValue;
	VECTORXYZ DestLoc;
END_PACKET()

BEGIN_PACKET(GU_CHAR_SITDOWN)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(GU_CHAR_STANDUP)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(GU_CHAR_FIGHTMODE)
	unsigned int handle;
	bool FightMode;
END_PACKET()

BEGIN_PACKET(GU_CHAR_BLOCK_MODE_COOL_TIME_NFY)
	DWORD CoolTimeRemaining;
END_PACKET()

BEGIN_PACKET(GU_CHAR_FAINT)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(GU_CHAR_KNOCKDOWN)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(GU_CHAR_SLIDING)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(GU_CHAR_CAMPING)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(GU_CHAR_CONVERT_CLASS)
	unsigned int Target;
	BYTE Class;
END_PACKET()

BEGIN_PACKET(GU_CHAR_DIALOG)
	unsigned int Subject;
	BYTE DialogType;
	unsigned int textTblidx;
	bool IsRefSpeechTable;
	WORD TextLen;
	WCHAR Text[MAX_CHATMESSAGE_USIZE + 1];
END_PACKET()

BEGIN_PACKET(GU_CHAR_DIRECT_PLAY)
	unsigned int Subject;
	BYTE PlayMode;
	unsigned int directTblidx;
	bool Synchronize;
END_PACKET()

BEGIN_PACKET(GU_CHAR_DIRECT_PLAY_END)
END_PACKET()

BEGIN_PACKET(GU_CHAR_AWAY_RES)
	bool IsAway;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_CHAR_MAIL_INFO)
	BYTE MailCount; 
	BYTE ManagerCount;
	BYTE NormalCount;
END_PACKET()

BEGIN_PACKET(GU_CHAR_KEY_INFO)
	BYTE Count;
	SHORTCUT_DATA Data[SHORTCUT_MAX_COUNT];
END_PACKET()

BEGIN_PACKET(GU_CHAR_RANKBATTLE_SCORE)
	RANKBATTLE_SCORE_INFO ScoreInfo;
END_PACKET()

BEGIN_PACKET(GU_CHAR_KEY_UPDATE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_CHAR_ACTION_ATTACK)
	unsigned int Subject;
	unsigned int Target;
	DWORD LpEpEventId;
	BYTE ChainAttack : 1;
	BYTE AttackResult : 7;
	WORD AttackResultValue;
	BYTE AttackSequence;
	float ReflectedDamage;
	BYTE BlockedAction;
	VECTORXYZ Shift;
END_PACKET()

BEGIN_PACKET(GU_CHAR_ACTION_SKILL)
	unsigned int handle;
	WORD ResultCode;
	DWORD LpEpEventId;
	unsigned int skillId;
	BYTE RpBonusType;
	unsigned int AppointedTarget;
	bool IsSkillHarmful;
	BYTE SkillResultCount;
	SKILL_RESULT SkillResult[MAX_SKILL_TARGET];
END_PACKET()

BEGIN_PACKET(GU_CHAR_ACTION_ITEM)
	unsigned int handle;
	WORD ResultCode;
	DWORD LpEpEventId;
	unsigned int itemTblidx;
	BYTE SkillResultCount;
	SKILL_RESULT SkillResult[MAX_SKILL_TARGET];
END_PACKET()

BEGIN_PACKET(GU_CHAR_REVIVAL_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_CHAR_TELEPORT_RES)
	WORD ResultCode;
	VECTORXYZ NewLoc;
	VECTORXYZ NewDir;
	bool IsToMoveAnotherServer;
	WORLD_INFO WorldInfo;
END_PACKET()

BEGIN_PACKET(GU_CHAR_BIND_RES)
	WORD ResultCode;
	BYTE BindType;
	unsigned int bindWorldId;
	unsigned int bindObjectTblidx;
END_PACKET()

BEGIN_PACKET(GU_CHAR_SERVER_CHANGE_RES)
	WORD ResultCode;
	char AuthKey[MAX_AUTHKEY_SIZE];
	SRVINFO serverInfo;
END_PACKET()

BEGIN_PACKET(GU_CHAR_CHANNEL_CHANGE_RES)
	WORD ResultCode;
	char AuthKey[MAX_AUTHKEY_SIZE];
	SRVINFO serverInfo;
END_PACKET()

BEGIN_PACKET(GU_CHAR_EXIT_RES)
	WORD ResultCode;
	char AuthKey[MAX_AUTHKEY_SIZE];
	BYTE ServerInfoCount;
	SRVINFO ServerInfo[MAX_CHARSRV_COUNT];
END_PACKET()

BEGIN_PACKET(GU_CHAR_SKILL_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_GAME_EXIT_RES)
END_PACKET()

BEGIN_PACKET(GU_GAME_KICK_NFY)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_EFFECT_AFFECTED)
	unsigned int handle;
	unsigned int Caster;
	unsigned int effectTblidx;
	WORD ResultCode;
	float ActualArgument1;
	float ActualArgument2;
END_PACKET()

BEGIN_PACKET(GU_SKILL_CASTING_CANCELED_NFY)
	unsigned int handle;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SKILL_CASTING_DELAYED_NFY)
	unsigned int handle;
	WORD ResultCode;
	DWORD CastingTime;
	DWORD CastingTimeRemaining;
END_PACKET()

BEGIN_PACKET(GU_SKILL_AFFECTING_CANCELED_NFY)
	unsigned int Subject;
END_PACKET()

BEGIN_PACKET(GU_SKILL_TARGET_LIST_REQ)
	BYTE AvatarType;
END_PACKET()

BEGIN_PACKET(GU_SKILL_LEARN_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SKILL_LEARNED_NFY)
	unsigned int skillId;
	BYTE Slot;
END_PACKET()

BEGIN_PACKET(GU_SKILL_UPGRADE_RES)
	WORD ResultCode;
	unsigned int skillId;
	BYTE Slot;
END_PACKET()

BEGIN_PACKET(GU_SKILL_RP_BONUS_SETTING_RES)
	WORD ResultCode;
	unsigned int skillId;
	BYTE SlotIndex;
	BYTE RpBonusType;
	bool IsRpBonusAuto;
END_PACKET()

BEGIN_PACKET(GU_SKILL_NOTIFY_EXP)
	BYTE SlotIndex;
	WORD SkillExp;
END_PACKET()

BEGIN_PACKET(GU_SKILL_AFTEREFFECT_REMAINING_TIME_NFY)
	DWORD TimeRemaining;
END_PACKET()

BEGIN_PACKET(GU_SKILL_COOL_TIME_STARTED_NFY)
	unsigned int Subject;
	unsigned int skillTblidx;
END_PACKET()

BEGIN_PACKET(GU_BUFF_REGISTERED)
	unsigned int Handle;
	BYTE SourceType;
	unsigned int tblidx;
	float EffectValue[MAX_EFFECTSKILL];
	DWORD InitialDuration;		// In Millisecs.
	DWORD TimeRemaining;		// in millisecs.
	bool NeedToDisplayMessage;
END_PACKET()

BEGIN_PACKET(GU_BUFF_DROPPED)
	unsigned int Handle;
	BYTE SourceType;
	unsigned int tblidx;
END_PACKET()

BEGIN_PACKET(GU_BUFF_REFRESH_ALL)
	unsigned int Handle;
	BYTE Count;
	BUFF_INFO BuffInfo[MAX_PCHARBUFF_COUNT + MAX_PCHARDEBUFF_COUNT];
END_PACKET()

BEGIN_PACKET(GU_BUFF_DROP_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_HTB_START_RES)
	WORD ResultCode;
	BYTE SkillSlot;
END_PACKET()

BEGIN_PACKET(GU_HTB_LEARN_RES)
	WORD ResultCode;
	unsigned int skillId;
	BYTE SkillSlot;
END_PACKET()

BEGIN_PACKET(GU_HTB_FORWARD_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_HTB_RP_BALL_USE_RES)
	WORD ResultCode;
	BYTE RpBallCount;
END_PACKET()

BEGIN_PACKET(GU_HTB_RP_BALL_USED_NFY)
	unsigned int Subject;
	BYTE RpBallCount;
END_PACKET()

BEGIN_PACKET(GU_HTB_RP_BALL_RESULT_DECIDED_NFY)
	unsigned int Attacker;
	unsigned int Winner;
	bool HasSubjectRpBallUsed;
	bool HasTargetRpBallUsed;
	BYTE SubjectRpBallUsed;
	BYTE TargetRpBallUsed;
END_PACKET()

BEGIN_PACKET(GU_ITEM_CREATE)
	unsigned int handle;
	ITEM_DATA ItemData;
	bool IsNew; 
END_PACKET()

BEGIN_PACKET(GU_ITEM_UPDATE)
	unsigned int handle;
	ITEM_DATA ItemData;
END_PACKET()

BEGIN_PACKET(GU_ITEM_MOVE_RES)
	WORD ResultCode;
	unsigned int SrcItem;
	unsigned int DestItem;
	BYTE SrcPlace;
	BYTE SrcPos;
	BYTE DestPlace;
	BYTE DestPos;
END_PACKET()

BEGIN_PACKET(GU_ITEM_MOVE_STACK_RES)
	WORD ResultCode;
	unsigned int SrcItem;
	unsigned int DestItem;
	BYTE SrcPlace;
	BYTE SrcPos;
	BYTE DestPlace;
	BYTE DestPos;
	BYTE StackCount1;
	BYTE StackCount2;
END_PACKET()

BEGIN_PACKET(GU_ITEM_DELETE)
	unsigned int SrcItem;
	BYTE SrcPlace;
	BYTE SrcPos;
END_PACKET()

BEGIN_PACKET(GU_ITEM_DELETE_RES)
	WORD ResultCode;
	BYTE Place;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(GU_ITEM_EQUIP_REPAIR_RES)
	unsigned int handle; // NPC ID
	WORD ResultCode;
	DWORD SpendedZenny;
END_PACKET()

BEGIN_PACKET(GU_ITEM_REPAIR_RES)
	unsigned int Npchandle;
	WORD ResultCode;
	unsigned int Item;
	DWORD SpendedZenny;
END_PACKET()

BEGIN_PACKET(GU_ITEM_USE_RES)
	WORD ResultCode;
	unsigned int tblidxItem;
	BYTE Place;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(GU_ITEM_CASTING_CANCELED)
	unsigned int handle;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_ITEM_CASTING_DELAYED_NFY)
unsigned int			handle;
WORD			wResultCode;
DWORD			dwCastingTime;
DWORD			dwCastingTimeRemaining;
END_PACKET()

BEGIN_PACKET(GU_ITEM_DUR_DOWN)
	BYTE Dur[EQUIP_SLOT_TYPE_COUNT];
END_PACKET()

BEGIN_PACKET(GU_ITEM_DUR_UPDATE)
	unsigned int ItemHandle;
	BYTE Dur;
END_PACKET()

BEGIN_PACKET(GU_ITEM_STACK_UPDATE)
	unsigned int ItemHandle;
	BYTE Stack;
	bool IsNew;		// Effect �߰� 
END_PACKET()

BEGIN_PACKET(GU_ITEM_UPGRADE_RES)
	WORD ResultCode;
	BYTE Stack;
	BYTE Grade;
	BYTE ItemPlace;
	BYTE ItemPos;
	BYTE StonPlace;
	BYTE StonPos;
	BYTE BattleAttribute;
END_PACKET()

BEGIN_PACKET(GU_ITEM_IDENTIFY_RES)
	unsigned int ItemHandle;
	WORD ResultCode;
	ITEM_DATA ItemData;
END_PACKET()

BEGIN_PACKET(GU_ITEM_PICK_RES)
	unsigned int itemTblidx;
	WORD ResultCode;
	// Any message doesn't need to be displayed if 'bByPartyHunting' is true.
	// (If a party member picks up an item, the message is displayed by another type of packet.)
	bool ByPartyHunting;
END_PACKET()

BEGIN_PACKET(GU_ZENNY_PICK_RES)
	WORD ResultCode;
	bool SharedInParty;
	DWORD Zenny;
	DWORD AcquisitionZenny;
	DWORD BonusZenny;
	// 'dwOriginalZenny' MUST NOT be referred if 'bSharedInParty' is false.
	DWORD OriginalZenny;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_STATE)
	unsigned int handle;
	CHARSTATE CharState;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_ASPECT_STATE)
	unsigned int handle;
	ASPECTSTATE	aspectState;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_CONDITION)
	unsigned int handle;
	DWORD ConditionFlag;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_EXP)
	unsigned int handle;
	DWORD CurExp;
	DWORD IncreasedExp;
	DWORD AcquisitionExp;
	DWORD BonusExp;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_LEVEL)
	unsigned int handle;
	BYTE PrevLevel;
	BYTE CurLevel;
	DWORD MaxExpInThisLevel;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_SPEED)
	unsigned int handle;
	float LastWalkingSpeed;
	float LastRunningSpeed;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_ATTACK_SPEEDRATE)
	unsigned int handle;
	WORD AttackSpeedRate;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_ITEM_EQUIP)
	unsigned int handle;
	BYTE Pos;
	ITEM_BRIEF ItemBrief;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_ITEM_DELETED)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_TARGET_INFO)
	unsigned int handle;
	WORD CurLP;
	WORD MaxLP;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_LP)
	unsigned int handle;
	DWORD LpEpEventId;
	WORD CurLP;
	WORD MaxLP;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_EP)
	unsigned int handle;
	DWORD LpEpEventId;
	WORD CurEP;
	WORD MaxEP;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_RP)
	unsigned int handle;
	WORD CurRP;
	WORD MaxRP;
	bool HitDelay;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_LP_EP)
	unsigned int handle;
	DWORD LpEpEventId;
	WORD CurLP;
	WORD MaxLP;
	WORD CurEP;
	WORD MaxEP;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_ZENNY)
	unsigned int handle;
	DWORD Zenny;
	bool IsNew;
	BYTE ChangeType; // eZENNY_CHANGE_TYPE - NtlCharacter.h
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_MUDOSA_POINT)
	DWORD MudosaPoint;
END_PACKET()

BEGIN_PACKET(GU_SYSTEM_DISPLAY_TEXT)
	WCHAR GMChar[MAX_CHARNAME_SIZE + 1];
	BYTE DisplayType; // eSERVER_TEXT_TYPE
	WORD MessageLengthInUnicode;
	WCHAR Message[MAX_CHATMESSAGE_USIZE + 1];
END_PACKET()

BEGIN_PACKET(GU_SYSTEM_DISPLAY_RESULTCODE)
	BYTE DisplayType; // eSERVER_TEXT_TYPE
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SHOP_START_RES)
	unsigned int handle;
	BYTE Type;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SHOP_BUY_RES)
	unsigned int handle;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SHOP_SELL_RES)
	unsigned int handle;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SHOP_END_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SHOP_SKILL_BUY_RES)
	unsigned int Npchandle;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_PARTY_CREATE_RES)
	WORD ResultCode;
	WCHAR PartyName[MAX_PARTYNAME_SIZE + 1];
END_PACKET()

BEGIN_PACKET(GU_PARTY_DISBAND_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_PARTY_DISBANDED_NFY)
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVITE_RES)
	WORD ResultCode;
	WCHAR TargetName[MAX_CHARNAME_SIZE + 1];
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVITE_NFY)
	bool FromPc;
	union
	{
		WCHAR InvitorPcName[MAX_CHARNAME_SIZE + 1];
		WCHAR InvitorPartyName[MAX_PARTYNAME_SIZE + 1];
	};
END_PACKET()

BEGIN_PACKET(GU_PARTY_RESPONSE_INVITATION_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_PARTY_MEMBER_JOINED_NFY)
	PARTY_MEMBER_INFO memberInfo;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INFO)
	WCHAR PartyName[MAX_PARTYNAME_SIZE + 1];
	unsigned int Leader;
	BYTE ItemLootingMethod;
	BYTE ZennyLootingMethod;
	unsigned int registeredCharmTblidx[PARTY_CHARM_INVENTORY_COUNT];
	DWORD RemainingTime[PARTY_CHARM_INVENTORY_COUNT];
	SHARETARGET_INFO sharetargetInfo[MAX_SHARETARGET_COUNT];
	PARTYDUNGEON_STATE Diff;
	BYTE ItemRank;
	BYTE MemberInfoCount;
	PARTY_MEMBER_INFO memberInfo[MAX_MEMBER_IN_PARTY - 1];
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVENTORY_INFO)
	BYTE SlotInfoCount;
	PARTY_INVENTORY_SLOT_INFO inventorySlotInfo[PARTY_INVENTORY_SLOT_COUNT];
END_PACKET()

BEGIN_PACKET(GU_PARTY_OPENED_CHARM_INVENTORY_INFO)
	BYTE CharmInventoryIndex;
	PARTY_VICTIM_ITEM_INFO victimItemInfo;
	DWORD TotalVictimZenny;
	BYTE VictimInfoCount;
	VICTIM_INFO VictimInfo[MAX_MEMBER_IN_PARTY - 1];
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVITATION_DECLINED_NFY)
	WCHAR PlayerName[MAX_CHARNAME_SIZE + 1];
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVITATION_EXPIRED_NFY)
	WCHAR PlayerName[MAX_CHARNAME_SIZE + 1];
END_PACKET()

BEGIN_PACKET(GU_PARTY_LEAVE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_PARTY_MEMBER_LEFT_NFY)
	unsigned int Member;
END_PACKET()

BEGIN_PACKET(GU_PARTY_KICK_OUT_RES)
	WORD ResultCode;
	unsigned int TargetMember;
END_PACKET()

BEGIN_PACKET(GU_PARTY_MEMBER_KICKED_OUT_NFY)
	unsigned int Member;
END_PACKET()

BEGIN_PACKET(GU_PARTY_CHANGE_LEADER_RES)
	WORD ResultCode;
	unsigned int NewLeader;
END_PACKET()

BEGIN_PACKET(GU_PARTY_LEADER_CHANGED_NFY)
	unsigned int NewLeader;
END_PACKET()

BEGIN_PACKET(GU_PARTY_MEMBER_LEVELED_UP_NFY)
	unsigned int Member;
	BYTE Level;
	WORD MaxLP;
	WORD MaxEP;
END_PACKET()

BEGIN_PACKET(GU_PARTY_MEMBER_CLASS_CHANGED_NFY)
	unsigned int Member;
	BYTE NewClass;
END_PACKET()

BEGIN_PACKET(GU_PARTY_OPEN_CHARM_SLOT_RES)
	WORD ResultCode;
	BYTE CharmInventoryIndex;
END_PACKET()

BEGIN_PACKET(GU_PARTY_CHARM_SLOT_OPENED_NFY)
	BYTE CharmInventoryIndex;
END_PACKET()

BEGIN_PACKET(GU_PARTY_CLOSE_CHARM_SLOT_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_PARTY_CHARM_SLOT_CLOSED_NFY)
END_PACKET()

BEGIN_PACKET(GU_PARTY_REGISTER_VICTIM_ITEM_RES)
	WORD ResultCode;
	BYTE SrcPlace;
	BYTE SrcPos;
	BYTE DestSlotIndex;
	DWORD TotalVictimItemScore;
END_PACKET()

BEGIN_PACKET(GU_PARTY_VICTIM_ITEM_REGISTERED_NFY)
	unsigned int Member;
	PARTY_VICTIM_ITEM_INFO itemInfo;
	DWORD TotalVictimItemScore;
END_PACKET()

BEGIN_PACKET(GU_PARTY_UNREGISTER_VICTIM_ITEM_RES)
	WORD ResultCode;
	BYTE DestSlotIndex;
	DWORD TotalVictimItemScore;
END_PACKET()

BEGIN_PACKET(GU_PARTY_VICTIM_ITEM_UNREGISTERED_NFY)
	unsigned int Member;
	unsigned int itemTblidx;
	BYTE DestSlotIndex;
	DWORD TotalVictimItemScore;
END_PACKET()

BEGIN_PACKET(GU_PARTY_REGISTER_VICTIM_ZENNY_RES)
	WORD ResultCode;
	DWORD RegisteredZenny;
	DWORD ReturningZenny;
END_PACKET()

BEGIN_PACKET(GU_PARTY_VICTIM_ZENNY_REGISTERED_NFY)
	unsigned int Member;
	DWORD IncreasedZenny;
END_PACKET()

BEGIN_PACKET(GU_PARTY_UNREGISTER_VICTIM_ZENNY_RES)
	WORD ResultCode;
	DWORD UnregisteredZenny;
END_PACKET()

BEGIN_PACKET(GU_PARTY_VICTIM_ZENNY_UNREGISTERED_NFY)
	unsigned int Member;
	DWORD DecreasedZenny;
END_PACKET()

BEGIN_PACKET(GU_PARTY_DECLARE_ZENNY_RES)
	WORD ResultCode;
	DWORD InitialZenny;
	DWORD FinalDeclaredZenny;
END_PACKET()

BEGIN_PACKET(GU_PARTY_DECLARED_ZENNY_CHANGED_NFY)
	unsigned int Member;
	DWORD DeclaredZenny;
END_PACKET()

BEGIN_PACKET(GU_PARTY_CHARM_ACTIVATION_FAILED_NFY)
	WORD ResultCode;
	unsigned int Member;
END_PACKET()

BEGIN_PACKET(GU_PARTY_ACTIVATE_CHARM_RES)
	WORD ResultCode;
	BYTE CharmInventoryIndex;
	unsigned int registeredCharmTblidx;
	DWORD RemainingTime;
END_PACKET()

BEGIN_PACKET(GU_PARTY_CHARM_ACTIVATED_NFY)
	BYTE CharmInventoryIndex;
	unsigned int registeredCharmTblidx;
	DWORD RemainingTime;
END_PACKET()

BEGIN_PACKET(GU_PARTY_DEACTIVATE_CHARM_RES)
	WORD ResultCode;
	BYTE CharmInventoryIndex;
END_PACKET()

BEGIN_PACKET(GU_PARTY_CHARM_DEACTIVATED_NFY)
	BYTE CharmInventoryIndex;
END_PACKET()

BEGIN_PACKET(GU_PARTY_CHANGE_ZENNY_LOOTING_METHOD_RES)
	WORD ResultCode;
	BYTE NewLootingMethod;
END_PACKET()

BEGIN_PACKET(GU_PARTY_ZENNY_LOOTING_METHOD_CHANGED_NFY)
	BYTE NewLootingMethod;
END_PACKET()

BEGIN_PACKET(GU_PARTY_CHANGE_ITEM_LOOTING_METHOD_RES)
	WORD ResultCode;
	BYTE NewLootingMethod;
END_PACKET()

BEGIN_PACKET(GU_PARTY_ITEM_LOOTING_METHOD_CHANGED_NFY)
	BYTE NewLootingMethod;
END_PACKET()

BEGIN_PACKET(GU_PARTY_ZENNY_LOOTING_METHOD_UNLOCKED_NFY)
END_PACKET()

BEGIN_PACKET(GU_PARTY_ITEM_LOOTING_METHOD_UNLOCKED_NFY)
END_PACKET()

BEGIN_PACKET(GU_PARTY_ZENNY_UPDATED_NFY)
	BYTE MemberCount;
	INVEST_ZENNY_INFO ZennyInfo[MAX_MEMBER_IN_PARTY];
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVENTORY_ITEM_ADDED_NFY)
	BYTE SlotIndex;
	PARTY_INVENTORY_ITEM_INFO newLoot;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVENTORY_ITEM_REMOVED_NFY)
	BYTE Pos;
	bool IsYourItem;
END_PACKET()

BEGIN_PACKET(GU_PARTY_MEMBER_GAINED_ITEM_NFY)
	unsigned int Member;
	// If itemTblidx is INVALID_DWORD, this means an unidentified item.
	unsigned int itemTblidx;
END_PACKET()

BEGIN_PACKET(GU_PARTY_MEMBER_GAINED_ZENNY_NFY)
	unsigned int Member;
	bool IsShared;
	DWORD Zenny; //dwAcquisitionZenny + dwBonusZenny
	DWORD AcquisitionZenny;
	DWORD BonusZenny;
	// 'dwOriginalZenny' MUST NOT be referred if 'bSharedInParty' is false.
	DWORD OriginalZenny;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEST_ZENNY_RES)
	WORD ResultCode;
	BYTE Pos;
	DWORD InvestedZenny;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEST_ZENNY_NFY)
	BYTE Pos;
	DWORD InvestedZenny;
	unsigned int Member;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVENTORY_ITEM_WINNER_CHANGED_NFY)
	BYTE Pos;
	unsigned int Winner;
	DWORD InvestedZenny;
END_PACKET()

BEGIN_PACKET(GU_PARTY_MEMBER_LOCATION_NFY)
	unsigned int Member;
	unsigned int worldTblidx;
	unsigned int worldId;
	VECTORXYZ CurLoc;
END_PACKET()

BEGIN_PACKET(GU_BANK_START_RES)
	unsigned int handle; // Npc id
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_BANK_MOVE_RES)
	unsigned int handle;
	unsigned int SrcItem;
	unsigned int DstItem;
	BYTE SrcPlace;
	BYTE SrcPos;
	BYTE DestPlace;
	BYTE DestPos;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_BANK_MOVE_STACK_RES)
	unsigned int handle;
	unsigned int SrcItem;
	unsigned int DestItem;
	BYTE SrcPlace;
	BYTE SrcPos;
	BYTE DestPlace;
	BYTE DestPos;
	BYTE StackCount1;
	BYTE StackCount2;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_BANK_END_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_BANK_ZENNY_INFO)
	DWORD Zenny;
END_PACKET()

BEGIN_PACKET(GU_BANK_ITEM_INFO)
	BYTE BeginCount;
	BYTE ItemCount;
	ITEM_PROFILE BankProfile[MAX_COUNT_USER_HAVE_BANK_ITEM];
END_PACKET()

BEGIN_PACKET(GU_BANK_ZENNY_RES)
	unsigned int handle;
	WORD ResultCode;
	DWORD Zenny;
	bool IsSave;
END_PACKET()

BEGIN_PACKET(GU_BANK_BUY_RES)
	unsigned int Npchandle;
	WORD ResultCode;
	unsigned int Itemhandle;
	ITEM_DATA Data;
END_PACKET()

BEGIN_PACKET(GU_BANK_ITEM_DELETE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SOCIAL_ACTION)
	unsigned int Subject;
	unsigned int socialActionId;
END_PACKET()

BEGIN_PACKET(GU_SCOUTER_INDICATOR_RES)
	unsigned int Target;
	WORD ResultCode;
	DWORD RetValue;
END_PACKET()

BEGIN_PACKET(GU_SCOUTER_PREDICT_RES)
	BYTE PusNum;
	WORD ResultCode;
	BYTE RetRate;
END_PACKET()

BEGIN_PACKET(GU_SCOUTER_EQUIP_CHECK_RES)
	unsigned int Target;
	WORD			wResultCode;
	BYTE			byItemCount;
	ITEM_PROFILE	aItemProfile[EQUIP_SLOT_TYPE_COUNT];
END_PACKET()

BEGIN_PACKET(GU_SCOUTER_CHIP_REMOVE_ALL_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TS_CONFIRM_STEP_RES)
	BYTE TsType;
	WORD ResultCode;
	WORD tId;
	BYTE tcCurId;
	BYTE tcNextId;
	DWORD Param;
END_PACKET()

BEGIN_PACKET(GU_TS_UPDATE_SYNC_NFY)
	BYTE TsType;
	WORD tId;
	BYTE tcId;
	unsigned char taId;
END_PACKET()

BEGIN_PACKET(GU_TS_UPDATE_STATE)
	BYTE TsType;
	WORD tId;
	BYTE Type;
	WORD TSState;
	DWORD Param;
END_PACKET()

BEGIN_PACKET(GU_TS_UPDATE_EVENT_NFY)
	BYTE TsType;
	unsigned int teid;
END_PACKET()

BEGIN_PACKET(GU_TS_EXCUTE_TRIGGER)
	BYTE TsType;
	WORD tId;
END_PACKET()

BEGIN_PACKET(GU_TS_EXCUTE_TRIGGER_OBJECT_RES)
	WORD ResultCode;
	unsigned int TriggerObject;
END_PACKET()

BEGIN_PACKET(GU_TS_TRIGGER_OBJECT_DIALOG_NFY)
	unsigned int TriggerObject;
	BYTE DialogType;
	unsigned int textTblidx;
END_PACKET()

BEGIN_PACKET(GU_TS_PC_DIALOG_NFY)
	unsigned int textTblidx;
END_PACKET()

BEGIN_PACKET(GU_TS_SKIP_CONTAINER)
	WORD tId;
	BYTE tcId;
END_PACKET()

BEGIN_PACKET(GU_QUEST_ITEM_CREATE_NFY)
	BYTE Pos;
	unsigned int qItemTblidx;
	BYTE CurCount;
END_PACKET()

BEGIN_PACKET(GU_QUEST_ITEM_DELETE_NFY)
	BYTE DeletePos;
END_PACKET()

BEGIN_PACKET(GU_QUEST_ITEM_UPDATE_NFY)
	BYTE Pos;
	BYTE CurCount;
END_PACKET()

BEGIN_PACKET(GU_QUEST_ITEM_MOVE_RES)
	WORD ResultCode;
	BYTE SrcPos;
	unsigned int SrcTblidx;
	BYTE DestPos;
	unsigned int DestTblidx;
END_PACKET()

BEGIN_PACKET(GU_QUEST_ITEM_DELETE_RES)
	WORD ResultCode;
	BYTE DeletePos;
END_PACKET()

BEGIN_PACKET(GU_QUEST_SVREVT_START_NFY)
	WORD tId;
	BYTE tcId;
	unsigned char taId;
END_PACKET()

BEGIN_PACKET(GU_QUEST_SVREVT_END_NFY)
	WORD tId;
	BYTE tcId;
	unsigned char taId;
END_PACKET()

BEGIN_PACKET(GU_QUEST_SVREVT_UPDATE_NFY)
	WORD tId;
	BYTE tcId;
	unsigned char taId;
	BYTE bySvrEvtType;
	BYTE bySlot;
	STOC_EVT_UPDATE_DATA EvtData;
END_PACKET()

BEGIN_PACKET(GU_QUEST_GIVEUP_RES)
	WORD tId;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_QUEST_SHARE_NFY)
	WORD ResultCode;
	WORD tId;
	unsigned int Actor;
END_PACKET()

BEGIN_PACKET(GU_QUEST_RESET_NFY)
	WORD startResetQID;
	WORD endResetQID;
END_PACKET()

BEGIN_PACKET(GU_QUEST_OBJECT_VISIT_RES)
	WORD ResultCode;
	WORD qId;
	unsigned int worldId;
	BYTE ObjType;
	unsigned int objectTblidx;
END_PACKET()

BEGIN_PACKET(GU_QUEST_FORCED_COMPLETION_NFY)
	WORD questId;
END_PACKET()

BEGIN_PACKET(GU_FREEBATTLE_CHALLENGE_RES)
	unsigned int Target;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_FREEBATTLE_ACCEPT_REQ)
	unsigned int Challenger;
END_PACKET()

BEGIN_PACKET(GU_FREEBATTLE_CANCEL_NFY)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_FREEBATTLE_START_NFY)
	unsigned int Target;
	VECTORXYZ RefreeLoc;
END_PACKET()

BEGIN_PACKET(GU_FREEBATTLE_OUTSIDE_NFY)
END_PACKET()

BEGIN_PACKET(GU_FREEBATTLE_INSIDE_NFY)
END_PACKET()

BEGIN_PACKET(GU_FREEBATTLE_END_NFY)
	BYTE FreeBattleResult;
END_PACKET()

BEGIN_PACKET(GU_QUICK_SLOT_UPDATE_RES)
	WORD ResultCode;
	unsigned int tblidx;
	BYTE SlotID;
	BYTE Type;
	BYTE Place;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(GU_QUICK_SLOT_DEL_NFY)
	BYTE SlotID;
END_PACKET()

BEGIN_PACKET(GU_QUICK_SLOT_INFO)
	BYTE QuickSlotCount;
	QUICK_SLOT_PROFILE QuickSlotData[CHAR_QUICK_SLOT_MAX_COUNT];
END_PACKET()

BEGIN_PACKET(GU_PET_CHAR_INFO)
	unsigned int handle;
	BYTE ObjectType;
	union
	{
		SUMMON_PET_PROFILE SummonPetProfile;
		ITEM_PET_PROFILE ItemPetProfile;
	};
	WORD CharStateSize;
	CHARSTATE CharState;
END_PACKET()

BEGIN_PACKET(GU_PET_SKILL_INFO)
	BYTE SkillCount;
	SKILL_INFO_PET SkillInfo[MAX_NPC_HAVE_SKILL];
END_PACKET()

BEGIN_PACKET(GU_PET_INFO_END)
END_PACKET()

BEGIN_PACKET(GU_PET_DESPAWNED_NFY)
	BYTE AvatarType;
END_PACKET()

BEGIN_PACKET(GU_PET_DISMISS_PET_RES)
	WORD ResultCode;
	BYTE AvatarType;
END_PACKET()

BEGIN_PACKET(GU_ACTION_REPORT_MESSAGE)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TRADE_START_NFY)
	unsigned int handle;
	unsigned int Target;
	WORD ResultCode;
	BYTE EmptyInven;	
END_PACKET()

BEGIN_PACKET(GU_TRADE_START_RES)
	unsigned int handle;
	unsigned int Target;
	WORD ResultCode;
	BYTE EmptyInven;
END_PACKET()

BEGIN_PACKET(GU_TRADE_OK_REQ)
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(GU_TRADE_ADD_NFY)
	unsigned int ItemObj;
	ITEM_DATA Item;
	BYTE Count;
END_PACKET()

BEGIN_PACKET(GU_TRADE_ADD_RES)
	unsigned int Item;
	BYTE Count;	
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TRADE_DEL_NFY)
	unsigned int Item;
END_PACKET()

BEGIN_PACKET(GU_TRADE_DEL_RES)
	unsigned int Item;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TRADE_MODIFY_NFY)
	unsigned int Target;
	unsigned int Item;
	BYTE Count;
END_PACKET()

BEGIN_PACKET(GU_TRADE_MODIFY_RES)
	unsigned int Target;
	unsigned int Item;
	BYTE Count;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TRADE_ZENNY_UPDATE_NFY)	// ������ ����
	unsigned int Target;
	DWORD Zenny;
END_PACKET()

BEGIN_PACKET(GU_TRADE_ZENNY_UPDATE_RES)
	unsigned int Target;
	DWORD Zenny;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TRADE_END_NFY)
	unsigned int Target;
	WORD ResultCode;	
	bool IsSet;
END_PACKET()

BEGIN_PACKET(GU_TRADE_END_RES)
	unsigned int Target;
	DWORD PacketCount;
	WORD ResultCode;
	bool IsSet;
END_PACKET()

BEGIN_PACKET(GU_TRADE_CANCEL_NFY)
	unsigned int Target;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TRADE_CANCEL_RES)
	unsigned int Target; 
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TRADE_DENY_RES)
	bool IsDeny;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_GUILD_NAME_CHANGED_NFY)
	unsigned int Subject;
	WCHAR GuildName[MAX_GUILDNAME_USIZE + 1];
END_PACKET()

BEGIN_PACKET(GU_GUILD_CREATE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_GUILD_INVITE_RES)
	WORD ResultCode;
	WCHAR TargetName[MAX_CHARNAME_SIZE + 1];
END_PACKET()

BEGIN_PACKET(GU_TOBJECT_UPDATE_STATE)
	unsigned int handle;
	TOBJECT_BRIEF tobjectBrief;
	TOBJECT_STATE tobjectState;
END_PACKET()

BEGIN_PACKET(GU_TOBJECT_ACTION_ATTACK)
	unsigned int Subject;
	unsigned int Target;
	BYTE AttackType;
	BYTE AttackResult;
	WORD AttackResultValue;
	VECTORXYZ Shift;
END_PACKET()

BEGIN_PACKET(GU_TUTORIAL_HINT_UPDATE_RES)
	WORD ResultCode;
	DWORD TutorialHint;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_ROOM_LIST_RES)
	WORD ResultCode;
	TIMEQUEST_ROOM_TMQ_INFO	TMQInfo;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_ROOM_INFO_RES)
	WORD ResultCode;
	BYTE RoomState;
	TIMEQUEST_ROOM_ICON_INFO IconInfo;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_ROOM_JOIN_RES)
	WORD ResultCode;
	TIMEQUEST_ROOM_JOIN_INFO JoinInfo;
	unsigned int TroubleMember;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_ROOM_JOIN_NFY)
	TIMEQUEST_ROOM_JOIN_INFO JoinInfo;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_ROOM_LEAVE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_ROOM_LEAVE_NFY)
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_ROOM_SELECTION_NFY)
	bool IsSecondWinner;
	TIMEQUEST_ROOM_SELECTION_INFO SelectionInfo;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_ROOM_TELEPORT_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_START_NFY)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_START_EXCEPTION_NFY)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_LEAVE_NFY)
	unsigned int handle;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_COUNTDOWN_NFY)
	bool CountDown;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_REWARD_NFY)
	BYTE TriggerType;
	unsigned int teid;	
	DWORD WaitTime;
	DWORD ClearTime;
	DWORD BonusTime;
	bool IsDayRecord : 1;
	bool IsBestRecord : 1;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_INFORMATION_NFY)
	BYTE InfoType;
END_PACKET()

BEGIN_PACKET(GU_TELECAST_MESSAGE_BEG_NFY)
	unsigned int npcTblidx;
	BYTE TelecastType;
	unsigned int speechTblidx;	
	DWORD DisplayTime;
END_PACKET()

BEGIN_PACKET(GU_TELECAST_MESSAGE_END_NFY)
END_PACKET()

BEGIN_PACKET(GU_BROAD_MESSAGE_BEG_NFY)
	BYTE byUIDirType;			// eBROAD_MSG_UI_DIR_TYPE
	BYTE byUIShowHideTypel;		// eBROAD_MSG_UI_SHOWHIDE_DIR_TYPE
	BYTE byUIBalloonShapeType;	// eBROAD_MSG_UI_BALLOON_SHAPE_TYPE
	BYTE byUISpeechDirType;		// eBROAD_MSG_UI_SPEECH_DIR_TYPE
	BYTE byOwnerCondition;		// eBROAD_MSG_OWNER_CONDITION
	BYTE byOwnerType;			// eBROAD_MSG_OWNER_TYPE
	unsigned int uiOwnerTblIdx;
	unsigned int uiQuestTextTblidx;
	float fDisplayTime;
END_PACKET()

BEGIN_PACKET(GU_BROAD_MESSAGE_END_NFY)
END_PACKET()

BEGIN_PACKET(GU_MINI_NARRATION_NFY)
	unsigned int uiNarrtionTblidx;
END_PACKET()

BEGIN_PACKET(GU_PROGRESS_MESSAGE_NFY)
	BYTE ProgressType;
	BYTE MessageType;
	BYTE MessageValue;
END_PACKET()

BEGIN_PACKET(GU_DIRECTION_INDICATE_NFY)
	bool Indicate;
	VECTORXYZ Loc;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_UPDATE_GAME_STATE)
	TIMEQUEST_STATE TimeQuestState;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_UPDATE_KILL_COUNT)
	unsigned int handle; 
	BYTE KillCount;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_UPDATE_COUPON_COUNT)
	BYTE CouponCount;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_UPDATE_TMQ_POINT)
	WORD TmqPoint;
END_PACKET()

BEGIN_PACKET(GU_TIMEQUEST_UPDATE_GAME_TIME)
	DWORD ClearTime;
	DWORD BonusTime;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_INFO_RES)
	WORD ResultCode;
	BYTE BattleMode;
	DWORD RemainTime;
	BYTE ArenaCount;
	RANKBATTLE_ARENA_INFO	ArenaInfo[1];
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_JOIN_RES)
	WORD ResultCode;
	unsigned int BoardObject;
	unsigned int rankBattleTblidx;
	DWORD RemainTime;		// ���� �ð�
	BYTE ArenaCount;
	RANKBATTLE_ARENA_INFO ArenaInfo[1];
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_JOIN_NFY)
	unsigned int rankBattleTblidx;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_LEAVE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_LEAVE_NFY)
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_MATCH_START_NFY)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_MATCH_CANCELED_NFY)
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_ROOM_LIST_RES)
	WORD ResultCode;
	unsigned int rankBattleTblidx;
	WORD TotalPage;
	WORD CurPage;
	BYTE RoomMode;
	BYTE RoomCount;
	RANKBATTLE_ROOMINFO_LIST RoomList;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_ROOM_INFO_RES)
	WORD ResultCode;
	BYTE RoomMode;
	RANKBATTLE_ROOMINFO Room;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_ROOM_CREATE_RES)
	WORD ResultCode;
	unsigned int rankBattleTblidx;
	unsigned int roomId;
	BYTE TroubleCount;
	RANKBATTLE_MEMBER_RESULT TroublePc[1];
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_ROOM_CREATE_NFY)
	WORD ResultCode;
	unsigned int rankBattleTblidx;
	unsigned int roomId;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_ROOM_LEAVE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_ROOM_LEAVE_NFY)
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_ROOM_JOIN_INFO_NFY)
	unsigned int rankBattleTblidx;
	unsigned int roomId;
	BYTE TeamType;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_ROOM_CHALLENGE_RES)
	WORD ResultCode;
	unsigned int rankBattleTblidx;
	unsigned int roomId;
	BYTE TroubleCount;
	RANKBATTLE_MEMBER_RESULT TroublePc[1];
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_ROOM_CHALLENGE_NFY)
	WORD ResultCode;
	unsigned int rankBattleTblidx;
	unsigned int roomId;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_ROOM_MATCH_READY_NFY)
	WORD ResultCode;
	BYTE MemberCount;
	RANKBATTLE_MEMBER_RESULT MemberResult[1];
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_ROOM_MATCH_START_NFY)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_ROOM_MATCH_CANCEL_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_ROOM_MATCH_CANCELED_NFY)
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_BATTLE_STATE_UPDATE_NFY)
	BYTE BattleState;
	BYTE Stage;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_BATTLE_TEAM_INFO_NFY)
	WORD StraightWinCount;
	WORD StraightKOWinCount;
	BYTE Count;
	WORD MemberInfo;
	WORD OwnerPartyName;
	WORD ChallengerPartyName;
	sVARIABLE_DATA sData;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_BATTLE_PLAYER_STATE_NFY)
	unsigned int Pc;
	BYTE PCState;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_BATTLE_KILLSCORE_UPDATE_NFY)
BYTE				byOwnerKillScore;
BYTE				byChallengerKillScore;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_BATTLE_STAGE_FINISH_NFY)
	BYTE BattleResult;
	RANKBATTLE_SCORE StageScore;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_BATTLE_MATCH_FINISH_NFY)
	RANKBATTLE_MATCH_FINISH_INFO MatchResult;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_BATTLE_END_NFY)
	BYTE MatchWinner;
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_BATTLE_FORCED_LEAVE_NFY)
END_PACKET()

BEGIN_PACKET(GU_RANKBATTLE_TOTAL_SCORE_UPDATE_NFY)
	BYTE Battlemode;
	RANKBATTLE_SCORE_INFO TotalScore;
END_PACKET()

BEGIN_PACKET(GU_DRAGONBALL_CHECK_RES)
	unsigned int Object;	
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_DRAGONBALL_REWARD_RES)
	unsigned int Object;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_DRAGONBALL_COLLECT_NFY)
	unsigned int Object;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_DRAGONBALL_SCHEDULE_INFO)
	bool IsAlive;
	BYTE EventType;	
	__int64 StartTime;
	__int64	 EndTime;
	DWORD MainTerm;	
	DWORD SubTerm;	
	BYTE TermType;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_CREATE_RES)
	WORD ResultCode;
	PACKET_PRIVATESHOP_SHOP_DATA PrivateShopData;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_CREATE_NFY)
	unsigned int Owner;
	SUMMARY_PRIVATESHOP_SHOP_DATA SummaryPrivateShopData;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_EXIT_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_OPEN_RES)
	WORD ResultCode;
	SUMMARY_PRIVATESHOP_SHOP_DATA SummaryPrivateShopData;
	BYTE NoticeSize;
	WCHAR Notice[MAX_PRIVATESHOPNOTICE_USIZE + 1];
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_OPEN_NFY)
	unsigned int Owner;
	SUMMARY_PRIVATESHOP_SHOP_DATA SummaryPrivateShopData;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_CLOSE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_CLOSE_NFY)
	unsigned int Owner;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_ITEM_INSERT_RES)
	WORD ResultCode;
	PRIVATESHOP_ITEM_DATA PrivateShopItemData;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_ITEM_UPDATE_RES)
	WORD ResultCode;
	DWORD Zenny;
	BYTE PrivateShopInventorySlotPos;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_ITEM_DELETE_RES)
	WORD ResultCode;
	PRIVATESHOP_ITEM_DATA PrivateShopItemData;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_ITEM_BUYING_RES)
	WORD ResultCode;
	PRIVATESHOP_ITEM_DATA PrivateShopItemData[MAX_SHOPCART];
	BYTE BuyItemCount;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_ITEM_BUYING_NFY)
	unsigned int PrivateShopOwner;
	PRIVATESHOP_ITEM_DATA PrivateShopItemData[MAX_SHOPCART];
	BYTE BuyItemCount;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_ENTER_RES)
	WORD ResultCode;
	PACKET_PRIVATESHOP_SHOP_DATA PrivateShopData;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_LEAVE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_ITEM_DATA_INFO)
	WORD ResultCode;
	unsigned int OwnerID;
	PRIVATESHOP_ITEM_DATA PrivateShopItemData;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_ITEM_SELECT_RES)
	WORD ResultCode;
	BYTE PrivateShopInventorySlotPos;
	BYTE ItemState;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_ITEM_SELECT_NFY)
	BYTE				byPrivateShopInventorySlotPos;
	BYTE				byItemState;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_ITEM_STATE_NFY)
	BYTE PrivateShopItemState[MAX_PRIVATESHOP_INVENTORY];
	int PrivateShopItemStateCount;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_LEAVE_NFY)
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_BUSINESS_REQUEST_RES)
	WORD ResultCode;
	BYTE PrivateShopInventorySlotPos;
	BYTE ItemState;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_BUSINESS_REQUEST_NFY)
	unsigned int Owner;
	BYTE PrivateShopInventorySlotPos;
	BYTE ItemState;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_BUSINESS_CONSENT_REQ)
	unsigned int VisitorID;
	BYTE PrivateShopInventorySlotPos;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_BUSINESS_CONSENT_NFY)
	unsigned int Owner;
	BYTE PrivateShopInventorySlotPos;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_BUSINESS_WAITTIMEOUT_NFY)
	unsigned int Owner;
	BYTE PrivateShopInventorySlotPos;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_BUSINESS_PRICEFLUCTUATIONS_RES)
	WORD ResultCode;
	BYTE PrivateShopInventorySlotPos;
	DWORD BeforeZenny;
	DWORD AfterZenny;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_BUSINESS_PRICEFLUCTUATIONS_NFY)
	unsigned int Owner;
	BYTE PrivateShopInventorySlotPos;
	DWORD BeforeZenny;
	DWORD AfterZenny;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_BUSINESS_IMMEDIATE_ITEM_BUYING_RES)
	WORD ResultCode;
	PRIVATESHOP_ITEM_DATA PrivateShopItemData;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_BUSINESS_IMMEDIATE_ITEM_BUYING_NFY)
	unsigned int PrivateShopOwner;
	PRIVATESHOP_ITEM_DATA PrivateShopItemData;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_BUSINESS_WINDOWCLOSE_NFY)
	unsigned int PrivateShopOwner;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_BUSINESS_CANCEL_RES)
	WORD ResultCode;
	BYTE CancelType;
	BYTE PrivateShopInventorySlotPos;
END_PACKET()

BEGIN_PACKET(GU_PRIVATESHOP_BUSINESS_CANCEL_NFY)
	unsigned int Owner;
	BYTE CancelType;
	BYTE PrivateShopInventorySlotPos;
END_PACKET()

BEGIN_PACKET(GU_TUTORIAL_WAIT_NFY)
	WORD WaitingCount;
END_PACKET()

BEGIN_PACKET(GU_TUTORIAL_WAIT_CANCEL_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TUTORIAL_PLAY_QUIT_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_MAIL_START_RES)
	unsigned int Object;
	WORD ResultCode;
	bool IsAway;
END_PACKET()

BEGIN_PACKET(GU_MAIL_SEND_RES)
	unsigned int Object;
	WCHAR TargetName[MAX_CHARNAME_SIZE + 1];
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_MAIL_READ_RES)
	unsigned int Object;
	unsigned int mailID;
	WORD ResultCode;
	BYTE RemainDay;
	time_t endTime;
END_PACKET()

BEGIN_PACKET(GU_MAIL_DEL_RES)
	unsigned int Object;
	unsigned int mailID;
	WORD	wResultCode;
END_PACKET()

BEGIN_PACKET(GU_MAIL_RETURN_RES)
	unsigned int Object;
	unsigned int mailID;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_MAIL_RELOAD_RES)
	unsigned int Object;
	WORD ResultCode;
	BYTE MailCount;
	BYTE ManagerCount;
	BYTE NormalCount;
	unsigned int aMailID[MAX_MAILSLOT_COUNT]; 
END_PACKET()

BEGIN_PACKET(GU_MAIL_RELOAD_NFY)
	BYTE MailCount;
	BYTE ManagerCount;
	BYTE NormalCount;
	unsigned int MailID[MAX_MAILSLOT_COUNT];
END_PACKET()

BEGIN_PACKET(GU_MAIL_LOAD_RES)
	unsigned int Object;
	WORD	wResultCode;
END_PACKET()

BEGIN_PACKET(GU_MAIL_LOAD_DATA)
	MAIL_NEW_PROFILE Data;
	BYTE TextSize;
	WCHAR Text[MAX_MAILMESSAGE_SIZE + 1];
END_PACKET()

BEGIN_PACKET(GU_MAIL_LOAD_INFO)
	MAIL_NEW_PROFILE Data;
	BYTE TextSize;
	WCHAR Text[MAX_MAILMESSAGE_SIZE + 1];
END_PACKET()

BEGIN_PACKET(GU_MAIL_ITEM_RECEIVE_RES)
	unsigned int Object;
	WORD ResultCode;
	unsigned int mailID;
END_PACKET()

BEGIN_PACKET(GU_MAIL_LOCK_RES)
	unsigned int Object;
	unsigned int mailID;
	bool IsLock;
	WORD ResultCode;
	BYTE ExpiredDay;
	time_t endTime;
END_PACKET()

BEGIN_PACKET(GU_MAIL_CLOSE_NFY)
END_PACKET()

BEGIN_PACKET(GU_MAIL_MULTI_DEL_RES)
	unsigned int Object;
	WORD ResultCode;
	BYTE Count;
	unsigned int MailID[MAX_MULTIDEL_COUNT];
END_PACKET()

BEGIN_PACKET(GU_PORTAL_START_RES)
	WORD ResultCode;
	unsigned int NpcHandle;
END_PACKET()

BEGIN_PACKET(GU_PORTAL_INFO)
	BYTE Count;
	BYTE PortalID[PORTAL_MAX_COUNT];
END_PACKET()

BEGIN_PACKET(GU_PORTAL_ADD_RES)
	WORD ResultCode;
	unsigned int NpcHandle;
	BYTE PortalID;
END_PACKET()

BEGIN_PACKET(GU_PORTAL_RES)
	WORD ResultCode;
	unsigned int NpcHandle;
	BYTE Point;
	CVector Loc;
	CVector Dir;
	unsigned int worldID;
END_PACKET()

BEGIN_PACKET(GU_WAR_FOG_INFO)
	BYTE WarFogInfo[MAX_SIZE_WAR_FOG];
END_PACKET()

BEGIN_PACKET(GU_WAR_FOG_UPDATE_RES)
	WORD ResultCode;
	unsigned int handle;
END_PACKET()

BEGIN_PACKET(GU_MOB_LUCKY_DROP_NFY)
	unsigned int Mobhandle;
END_PACKET()

BEGIN_PACKET(GU_ITEM_UPGRADE_ALL_NFY)
	BYTE Grade[ITEM_UPGRADE_EQUIP_COUNT];
END_PACKET()

BEGIN_PACKET(GU_BOT_BOTCAUTION_NFY)
	unsigned int Bot;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_REPUTATION)
	unsigned int handle;
	DWORD Reputation;
END_PACKET()

BEGIN_PACKET(GU_GUILD_FUNCTION_ADD_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_GUILD_GIVE_ZENNY_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_GUILD_BANK_START_RES)
	unsigned int handle;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_GUILD_BANK_MOVE_RES)
	unsigned int handle;
	unsigned int SrcItem;
	unsigned int DstItem;
	BYTE SrcPlace;
	BYTE SrcPos;
	BYTE DestPlace;
	BYTE DestPos;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_GUILD_BANK_MOVE_STACK_RES)
	unsigned int handle;
	unsigned int SrcItem;
	unsigned int DestItem;
	BYTE SrcPlace;
	BYTE SrcPos;
	BYTE DestPlace;
	BYTE DestPos;
	BYTE StackCount1;
	BYTE StackCount2;
	unsigned int splitItemId;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_GUILD_BANK_END_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_GUILD_BANK_ZENNY_INFO)
	DWORD Zenny;
END_PACKET()

BEGIN_PACKET(GU_GUILD_BANK_ITEM_INFO)
	BYTE Place;
	BYTE ItemCount;
	ITEM_PROFILE ItemProfile[MAX_BANK_ITEM_SLOT];
END_PACKET()

BEGIN_PACKET(GU_GUILD_BANK_ZENNY_RES)
	unsigned int handle;
	WORD ResultCode;
	DWORD Zenny;
	bool IsSave;
END_PACKET()

BEGIN_PACKET(GU_CROSSFIRE_RES)
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(GU_GUILD_CREATE_MARK_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_GUILD_CHANGE_MARK_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_GUILD_MARK_CHANGED_NFY)
	unsigned int Subject;
	GUILD_MARK Mark;
END_PACKET()

BEGIN_PACKET(GU_BANK_LOAD_RES)
	unsigned int handle;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_GUILD_CHANGE_NAME_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_PARTY_SHARETARGET_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_PARTY_SHARETARGET_NFY)
	SHARETARGET_INFO sharetargetInfo[MAX_SHARETARGET_COUNT];
END_PACKET()

BEGIN_PACKET(GU_RIDE_ON_BUS_RES)
	unsigned int Target;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_RIDE_OFF_BUS_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_TRANSFORM_CANCEL_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SHOP_ITEM_IDENTIFY_RES)
	WORD ResultCode;
	unsigned int Npchandle;
	BYTE Place;
	BYTE Pos;
	ITEM_DATA ItemData;
END_PACKET()

BEGIN_PACKET(GU_MATCH_MINORMATCH_STATE_UPDATE_NFY)
	BYTE MatchState;
	bool IsEnter;
	BYTE Stage;
	DWORD RemainTime;
END_PACKET()

BEGIN_PACKET(GU_MATCH_MINORMATCH_TEAM_INFO_NFY)
	BYTE MatchIndex;
	BYTE TeamCount;
	WORD TeamInfo_var;
	sVARIABLE_DATA sData;
END_PACKET()

BEGIN_PACKET(GU_MATCH_MINORMATCH_PLAYER_STATE_NFY)
	unsigned int Pc;
	BYTE PcState;
END_PACKET()

BEGIN_PACKET(GU_MATCH_MINORMATCH_UPDATE_SCORE_NFY)
	WORD TeamType;
	BYTE Score;
	unsigned int Slayer;
	unsigned int Fainter;
END_PACKET()

BEGIN_PACKET(GU_MATCH_MINORMATCH_TEAM_SCORE_NFY)
	BYTE Count;
	MATCH_MINORMATCH_TEAM_SCORE	TeamScore[BUDOKAI_MAX_MINORMATCH_TEAM_COUNT];
END_PACKET()

BEGIN_PACKET(GU_MATCH_MINORMATCH_SELECTION_NFY)
	WORD teamWinner;
	BYTE TeamCount;
	MINORMATCH_SELECTION_DATA	aSelection[BUDOKAI_MAX_MINORMATCH_TEAM_COUNT];
END_PACKET()

BEGIN_PACKET(GU_MATCH_MINORMATCH_STAGE_FINISH_NFY)
	BYTE StageResult;
	WORD StageWinner;
END_PACKET()

BEGIN_PACKET(GU_MATCH_MINORMATCH_MATCH_FINISH_NFY)
	BYTE MatchResult;
	WORD MatchWinner;
	BYTE KillCount;
END_PACKET()

BEGIN_PACKET(GU_MATCH_MAJORMATCH_STATE_UPDATE_NFY)
	BYTE MatchState;
	bool IsEnter;
	BYTE Stage;
	DWORD RemainTime;
END_PACKET()

BEGIN_PACKET(GU_MATCH_MAJORMATCH_TEAM_INFO_NFY)
	BYTE MatchDepth;
	BYTE MatchIndex;
	BYTE TeamCount;
	WORD TeamInfo_var;
	sVARIABLE_DATA sData;
END_PACKET()

BEGIN_PACKET(GU_MATCH_MAJORMATCH_PLAYER_STATE_NFY)
	unsigned int Pc;
	BYTE PcState;
END_PACKET()

BEGIN_PACKET(GU_MATCH_MAJORMATCH_UPDATE_SCORE_NFY)
	MATCH_SCORE	StageScore;
END_PACKET()

BEGIN_PACKET(GU_MATCH_MAJORMATCH_STAGE_FINISH_NFY)
	BYTE StageResult;
	WORD StageWinner;
	MATCH_SCORE	MatchScore;
	bool IsObserver;
END_PACKET()

BEGIN_PACKET(GU_MATCH_MAJORMATCH_MATCH_FINISH_NFY)
	BYTE MatchResult;
	WORD MatchWinner;
	MATCH_SCORE MatchScore;
END_PACKET()

BEGIN_PACKET(GU_MATCH_FINALMATCH_STATE_UPDATE_NFY)
	BYTE MatchState;
	bool IsEnter;
	BYTE Stage;
	DWORD	 RemainTime;
END_PACKET()

BEGIN_PACKET(GU_MATCH_FINALMATCH_TEAM_INFO_NFY)
	BYTE MatchDepth;
	BYTE MatchIndex;
	BYTE TeamCount;
	WORD TeamInfo_var;
	sVARIABLE_DATA sData;
END_PACKET()

BEGIN_PACKET(GU_MATCH_FINALMATCH_PLAYER_STATE_NFY)
	unsigned int Pc;
	BYTE PcState;
END_PACKET()

BEGIN_PACKET(GU_MATCH_FINALMATCH_UPDATE_SCORE_NFY)
	MATCH_SCORE StageScore;
END_PACKET()

BEGIN_PACKET(GU_MATCH_FINALMATCH_STAGE_FINISH_NFY)
	BYTE StageResult;
	WORD StageWinner;
	MATCH_SCORE MatchScore;
	bool IsObserver;
END_PACKET()

BEGIN_PACKET(GU_MATCH_FINALMATCH_MATCH_FINISH_NFY)
	BYTE MatchResult;
	WORD MatchWinner;
	MATCH_SCORE MatchScore;
END_PACKET()

BEGIN_PACKET(GU_MATCH_AWARDING_NFY)
	WORD TeamName[MAX_FINALMATCH_RESULT];
	sVARIABLE_DATA sData;
END_PACKET()

BEGIN_PACKET(GU_SKILL_CONFUSE_TARGET_NFY)
	unsigned int Subject;
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(GU_SKILL_TERROR_COURSE_CHANGE_NFY)
	unsigned int Subject;
	unsigned int Attacker;
END_PACKET()

BEGIN_PACKET(GU_DICE_ROLL_RES)
	WORD ResultCode;
	WORD DiceResult;
END_PACKET()

BEGIN_PACKET(GU_DICE_ROLLED_NFY)
	unsigned int Subject;
	WORD DiceResult;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_STATE_INFO_NFY)
	DWORD DefaultOpenTime;
	bool RankbattleAllow;
	BUDOKAI_UPDATE_STATE_INFO StateInfo;
	BUDOKAI_UPDATE_MATCH_STATE_INFO MatchStateInfo[MAX_BUDOKAI_MATCH_TYPE];
	BUDOKAI_JOIN_INFO JoinInfo;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_UPDATE_STATE_NFY)
	BUDOKAI_UPDATE_STATE_INFO StateInfo;
	bool RankbattleAllow;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_UPDATE_MATCH_STATE_NFY)
	BYTE MatchType;
	BUDOKAI_UPDATE_MATCH_STATE_INFO StateInfo;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_JOIN_INDIVIDUAL_RES)
	WORD ResultCode;
	WORD JoinId;
	bool DojoRecommender;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_LEAVE_INDIVIDUAL_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_JOIN_TEAM_INFO_RES)
	WORD ResultCode;
	BYTE MemberCount;
	BUDOKAI_TEAM_POINT_INFO PointInfo[1];
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_JOIN_TEAM_RES)
	WORD ResultCode;
	unsigned int TroublePc;
	float TotalRankPoint;
	WORD JoinId;
	WCHAR TeamName[MAX_BUDOKAITEAMNAME_USIZE + 1];
	BYTE MemberCount;
	BUDOKAI_TEAM_POINT_INFO TeamInfo[MAX_MEMBER_IN_PARTY];
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_JOIN_TEAM_NFY)
	float TotalRankPoint;
	WORD JoinId;
	WCHAR TeamName[MAX_BUDOKAITEAMNAME_USIZE + 1];
	BYTE MemberCount;
	BUDOKAI_TEAM_POINT_INFO TeamInfo[MAX_MEMBER_IN_PARTY];
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_LEAVE_TEAM_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_LEAVE_TEAM_NFY)
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_LEAVE_TEAM_MEMBER_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_LEAVE_TEAM_MEMBER_NFY)
	WCHAR MemberName[MAX_CHARNAME_SIZE + 1];
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_JOIN_INFO_RES)
	WORD ResultCode;
	BYTE MatchType;
	union
	{
		BUDOKAI_REGISTER_INDIVIDUAL_INFO IndividualInfo;
		BUDOKAI_REGISTER_TEAM_INFO TeamInfo;
	};
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_JOIN_STATE_RES)
	WORD ResultCode;
	BYTE MatchType;
	BYTE JoinState;
	BYTE JoinResult;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_JOIN_STATE_NFY)
	BYTE MatchType;
	BYTE JoinState;
	BYTE JoinResult;
END_PACKET()

BEGIN_PACKET(GU_DISCONNECTED_NFY)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_BOT_BOTCAUTION_HELPME_NFY)
	unsigned int Bot;
	bool IsRequester;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_MUDOSA_INFO_RES)
	WORD ResultCode;
	BYTE MudosaCount;
	BUDOKAI_MUDOSA_INFO	aMudosaInfo[BUDOKAI_MAX_MUDOSA_INFO_COUNT];
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_MUDOSA_TELEPORT_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_PROGRESS_MESSAGE_NFY)
	BYTE MsgId;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_SOCIAL_ACTION_NFY)
	unsigned int Subject;
	WORD socialAction;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_PRIZEWINNER_NAME_RES)
	WORD ResultCode;
	WORD Winner;
	WORD SecondWinner;
	sVARIABLE_DATA sData;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_PRIZEWINNER_TEAM_NAME_RES)
WORD ResultCode;
WORD Winner;
WORD SecondWinner;
sVARIABLE_DATA sData;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_GM_BUDOKAI_SERVER_ENTER_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_GM_BUDOKAI_SERVER_LEAVE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_GM_MATCH_PROGRESS_INFO_RES)
	WORD ResultCode;
	BYTE MatchType;
	BYTE MatchWorldType;
	BYTE MatchDepth;
	BYTE StateCount;
	BUDOKAI_GM_MATCH_PROGRESS_STATE StateList[BUDOKAI_MAX_MATCH_COUNT];
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_GM_MATCH_ARENA_ENTER_RES)
	WORD ResultCode;
	BYTE MatchType;
	BYTE MatchWorldType;	
	BYTE MatchDepth;
	BYTE MatchIndex;
END_PACKET()

BEGIN_PACKET(GU_BUDOKAI_GM_MATCH_ARENA_LEAVE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SCOUTER_TURN_ON_NFY)
	unsigned int Subject;
END_PACKET()

BEGIN_PACKET(GU_SCOUTER_TURN_OFF_NFY)
	unsigned int Subject;
END_PACKET()

BEGIN_PACKET(GU_SCOUTER_BROKEN_NFY)
	unsigned int Subject;
END_PACKET()

BEGIN_PACKET(GU_SCOUTER_ITEM_SELL_RES)
	unsigned int itemTblidx;
	BYTE Place;
	BYTE Pos;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SHOP_EVENTITEM_START_RES)
	unsigned int handle;
	BYTE Type; 
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SHOP_EVENTITEM_BUY_RES)
	unsigned int handle;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SHOP_EVENTITEM_END_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_ITEM_REPLACE)
	unsigned int DeleteItem;
	unsigned int CreateItem;
	BYTE DeleteItemPlace;
	BYTE DeleteItemPos;
	ITEM_DATA CreateItemData;
	bool IsNew;
END_PACKET()

BEGIN_PACKET(GU_SHOP_GAMBLE_BUY_RES)
	WORD ResultCode;
	unsigned int handle;
	unsigned int Item;
END_PACKET()

BEGIN_PACKET(GU_PARTY_DUNGEON_DIFF_NFY)
	PARTYDUNGEON_STATE Diff;
END_PACKET()

BEGIN_PACKET(GU_PARTY_DUNGEON_DIFF_RES)
	WORD ResultCode;
	PARTYDUNGEON_STATE Diff;
END_PACKET()

BEGIN_PACKET(GU_PARTY_DUNGEON_INIT_NFY)
END_PACKET()

BEGIN_PACKET(GU_PARTY_DUNGEON_INIT_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_SP)
	DWORD SpPoint;
END_PACKET()

BEGIN_PACKET(GU_SKILL_INIT_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SKILL_REMOVE_NFY)
	unsigned int skillId;
	BYTE Slot;
END_PACKET()

BEGIN_PACKET(GU_HTB_REMOVE_NFY)
	unsigned int skillId;
	BYTE Slot;
END_PACKET()

BEGIN_PACKET(GU_CHAR_MARKING_NFY)
	unsigned int handle;
	MARKING Marking;
END_PACKET()

BEGIN_PACKET(GU_PARTY_CHARM_DICE_START_NFY)
	DWORD WaitTick;
END_PACKET()

BEGIN_PACKET(GU_PARTY_CHARM_DICE_ROLLED_NFY)
	unsigned int handle;
	DWORD Ret;
END_PACKET()

BEGIN_PACKET(GU_PARTY_CHARM_DICE_ROLLED_RES)
	DWORD Ret;
END_PACKET()

BEGIN_PACKET(GU_PARTY_CHARM_DICE_END_NFY)
	bool IsSuccess;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_ITEM_RANK_SET_RES)
	WORD ResultCode;
	BYTE ItemRank;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_ITEM_RANK_SET_NFY)
	BYTE ItemRank;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_LOCK_NFY)
	bool IsOpen;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_LOCK_RES)
	WORD ResultCode;
	bool IsOpen;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_RESET_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_RESET_NFY)
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_ACCEPTED_RES)
	BYTE ItemSlot;
	WORD ResultCode;
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_ACCEPTED_NFY)
	BYTE ItemSlot;
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_GIVE_RES)
	WORD ResultCode;
	BYTE ItemSlot; 
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_GIVE_NFY)
	BYTE ItemSlot;
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_DICE_START_RES)
	WORD ResultCode;
	BYTE ItemSlot;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_DICE_START_NFY)
	BYTE ItemSlot;	
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_DICE_ROLL_RES)
	WORD ResultCode;
	BYTE Ret;
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_DICE_ROLL_NFY)
	unsigned int handle;
	BYTE Ret;	
END_PACKET()

BEGIN_PACKET(GU_PARTY_INVEN_DICE_END_NFY)
	unsigned int Target;
END_PACKET()

BEGIN_PACKET(GU_TELEPORT_PROPOSAL_NFY)
	BYTE TeleportType;
	BYTE InfoIndex;
	WORD WaitTime;
	unsigned int worldTblidx;
	union
	{
		DWORD Reserve;
		BYTE BudokaiMatchDepth;	
	};
	BYTE SummonerNameLength;
	WCHAR SummonnerName[MAX_CHARNAME_SIZE + 1];
END_PACKET()

BEGIN_PACKET(GU_TELEPORT_CONFIRM_RES)
	WORD ResultCode;
	BYTE TeleportIndex;
	bool Teleport;
	bool ClearInterface;
END_PACKET()

BEGIN_PACKET(GU_AVATAR_PETITION_INFO)
	unsigned int petitionID;
	WCHAR QuestionContent[MAX_SIZE_QUESTION_CONTENT_UNICODE + 1];
	int	Category1;
	int Category2;
END_PACKET()

BEGIN_PACKET(GU_GAME_COMMON_MSG_NFY)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_CHAR_NICKNAME_CHANGED_NFY)
	unsigned int Subject;
	unsigned int nicknameTblidx;
END_PACKET()

BEGIN_PACKET(GU_HOIPOIMIX_RECIPE_REG_NFY)
	unsigned int recipeTblidx;
END_PACKET()

BEGIN_PACKET(GU_HOIPOIMIX_ITEM_CHECK_RES)
	WORD ResultCode;
	unsigned int objHandle;
	unsigned int recipeTblidx;
END_PACKET()

BEGIN_PACKET(GU_HOIPOIMIX_ITEM_MAKE_RES)
	WORD ResultCode;
	BYTE SuccessResult;
	unsigned int objHandle;
	unsigned int recipeTblidx;
	unsigned int itemHandle;
END_PACKET()
			
BEGIN_PACKET(GU_HOIPOIMIX_ITEM_MAKE_EP_RES)
	WORD ResultCode;
END_PACKET()
	
BEGIN_PACKET(GU_HOIPOIMIX_ITEM_RECIPE_INFO)
	BYTE Count;
	RECIPE_DATA RecipeData[ITEM_RECIPE_MAX_COUNT];
END_PACKET()

BEGIN_PACKET(GU_DYNAMIC_OBJECT_UPDATE_STATE)
	unsigned int handle;
	DYNAMIC_OBJECT_BRIEF dynamicObjBrief;
	DYNAMIC_OBJECT_STATE dynamicObjState;
END_PACKET()

BEGIN_PACKET(GU_HOIPOIMIX_ITEM_MACHINE_MAKE_RES)
	WORD ResultCode;
	BYTE Place;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(GU_HOIPOIMIX_ITEM_MACHINE_DEL_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_HOIPOIMIX_ITEM_MAKE_EXP_NFY)
	DWORD CurExp;
	BYTE CurLevel;
	bool IsNormal;
END_PACKET()

BEGIN_PACKET(GU_CHAR_TARGET_LOST_NFY)
	unsigned int Subject;
END_PACKET()

BEGIN_PACKET(GU_CHAR_GUARD_CRASHED_NFY)
	unsigned int Subject;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_RP_BALL)
	unsigned int handle;
	BYTE CurRPBall;
	bool DropByTime;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_RP_BALL_MAX)
	unsigned int handle;
	BYTE MaxRPBall;
END_PACKET()

BEGIN_PACKET(GU_HOIPOIMIX_JOB_SET_RES)
	WORD ResultCode;
	unsigned int Npchandle;
	BYTE RecipeType;
END_PACKET()

BEGIN_PACKET(GU_HOIPOIMIX_JOB_RESET_RES)
	WORD ResultCode;
	unsigned int Npchandle;
	BYTE RecipeType;
END_PACKET()

BEGIN_PACKET(GU_AVATAR_RP_INCREASE_START_NFY)
END_PACKET()

BEGIN_PACKET(GU_AVATAR_RP_DECREASE_START_NFY)
END_PACKET()

BEGIN_PACKET(GU_AVATAR_RP_INCREASE_STOP_NFY)
END_PACKET()

BEGIN_PACKET(GU_HTB_LAST_STEP_CHANGED_NFY)
	unsigned int Subject;
	BYTE LastStep;
END_PACKET()

BEGIN_PACKET(GU_CHAR_CHARGE_CANCELED_NFY)
	unsigned int Subject;
END_PACKET()

BEGIN_PACKET(GU_CHAR_REFRESH_LP_EP)
	unsigned int Subject;
	WORD CurLp;
	WORD MaxLp;
	WORD CurEp;
	WORD MaxEp;
END_PACKET()

BEGIN_PACKET(GU_CHAR_NONBATTLEACTIONPATTERNSET_UNITIDX_NFY)
	unsigned int BotHandle;
	BYTE unitIdx;
END_PACKET()

BEGIN_PACKET(GU_VEHICLE_START_NFY)
	unsigned int DriverHandle;
	VECTORXYZ StartPosition;
	unsigned int idFuelItemTblidx;
	unsigned int VehicleItem;
	unsigned int idVehicleItemTblidx;
END_PACKET()

BEGIN_PACKET(GU_VEHICLE_ENGINE_START_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_VEHICLE_ENGINE_START_NFY)
	unsigned int DriverHandle;
END_PACKET()

BEGIN_PACKET(GU_VEHICLE_ENGINE_STOP_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_VEHICLE_ENGINE_STOP_NFY)
	unsigned int hDriverHandle;
	DWORD FuelRemain;
END_PACKET()

BEGIN_PACKET(GU_VEHICLE_FUEL_UPDATE_NFY)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_VEHICLE_END_NFY)
	unsigned int DriverHandle;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_VEHICLE_END_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_VEHICLE_STUNT_NFY)
	unsigned int DriverHandle;
END_PACKET()

BEGIN_PACKET(GU_SKILL_PASSIVE_EFFECT_APPLIED_NFY)
	unsigned int skillTblidx;
	BYTE SlotIndex;
	UPDATED_SKILL_DATA UpdatedSkillData;
END_PACKET()

BEGIN_PACKET(GU_AVATAR_UPDATED_SKILL_DATA_INFO)
	unsigned int skillTblidx;
	BYTE SlotIndex;
	UPDATED_SKILL_DATA UpdatedSkillData;
END_PACKET()

BEGIN_PACKET(GU_MONSTER_TRANSFORMED_NFY)
	unsigned int Subject;
	unsigned int newTblidx;
END_PACKET()

BEGIN_PACKET(GU_DOJO_CREATE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_DOJO_DELETE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_DOJO_FUNCTION_ADD_RES)
	WORD ResultCode;
	BYTE Function;
END_PACKET()

BEGIN_PACKET(GU_DOJO_BANK_HISTORY_RES)
	WORD ResultCode;
	DWORD Balance;
	BYTE Count;
	DOJO_BANK_HISTORY_INFO asData[MAX_COUNT_DOJO_BANK_HISTORY];
END_PACKET()

BEGIN_PACKET(GU_DOGI_CREATE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_DOGI_CHANGE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_DOGI_UPDATE_NFY)
	unsigned int handle;
	DOGIDATA Data;
END_PACKET()

BEGIN_PACKET(GU_GUILD_DOGI_CREATE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_GUILD_DOGI_CHANGE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_CHILD_ADULT_SWITCHED_NFY)
	unsigned int Subject;
	bool IsAdult;
END_PACKET()

BEGIN_PACKET(GU_CHANGE_CLASS_AUTHORITY_CHANGED_NFY)
	bool CanChangeClass;
END_PACKET()

BEGIN_PACKET(GU_PLAY_BGM)
	bool Play;
	bool Loop;
	DWORD Delay;
	BYTE Length;
	char Name[1];
END_PACKET()

BEGIN_PACKET(GU_DOJO_MARK_CHANGED_NFY)
	unsigned int dojoTblidx;
	unsigned int guildId;
	GUILD_MARK Mark;
END_PACKET()

BEGIN_PACKET(GU_DOJO_LEVEL_CHANGED_NFY)
	unsigned int dojoTblidx;
	BYTE byLevel;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_NETP)
	WORD ResultCode;
	DWORD netP;
	DWORD BonusNetP;
	DWORD AccumulationNetP;
	DWORD timeNextGainTime;
END_PACKET()

BEGIN_PACKET(GU_DOJO_SCRAMBLE_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_DOJO_SCRAMBLE_RESPONSE_RES)
	WORD ResultCode;
	WCHAR GuildName[MAX_GUILDNAME_USIZE + 1];
	bool IsRetry;
END_PACKET()

BEGIN_PACKET(GU_NETMARBLEMEMBERIP_NFY)
END_PACKET()

BEGIN_PACKET(GU_BUS_LOCATION_NFY)
	unsigned int Subject;
	unsigned int busTblidx;
	VECTORXY CurLoc;
	VECTORXY CurDir;
END_PACKET()

BEGIN_PACKET(GU_BUS_LOCATION_ERASED_NFY)
	unsigned int Subject;
END_PACKET()

BEGIN_PACKET(GU_BUS_LOCATION_RESET_ALL_NFY)
END_PACKET()

BEGIN_PACKET(GU_ITEM_EXPIRED_NFY)
	unsigned int Item;
	BYTE Place;
	BYTE Pos;
END_PACKET()

BEGIN_PACKET(GU_SHOP_NETPYITEM_START_RES)
	BYTE Type;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SHOP_NETPYITEM_BUY_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_SHOP_NETPYITEM_END_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_CHAR_REFRESH_BATTLE_ATTRIBUTE_MODIFIER)
	unsigned int Subject;
	float HonestOffenceModifier;
	float HonestDefenceModifier;
	float StrangeOffenceModifier;
	float StrangeDefenceModifier;
	float WildOffenceModifier;
	float WildDefenceModifier;
	float EleganceOffenceModifier;
	float EleganceDefenceModifier;
	float FunnyOffenceModifier;
	float FunnyDefenceModifier;
END_PACKET()

BEGIN_PACKET(GU_CHAR_RANKBATTLE_ALLOW_NFY)
	bool Allow;
	WORD ReasonCode;
END_PACKET()


BEGIN_PACKET(GU_CHAR_RANKPOINT_RESET_NFY)
END_PACKET()

BEGIN_PACKET(GU_DOJO_NPC_INFO_RES)
	WORD ResultCode;
	DOJO_NPC_INFO Data;
END_PACKET()

BEGIN_PACKET(GU_GAMEGUARD_AUTH_ANSWER_REQ)
	BYTE DataSize;
	BYTE Data[UCHAR_MAX];
END_PACKET()

BEGIN_PACKET(GU_DOJO_SEAL_ATTACK_BEGIN_NFY)
	unsigned int sealObjectTblidx;
	bool IsBeingStolen;
	VECTORXY Loc;
END_PACKET()

BEGIN_PACKET(GU_DOJO_SEAL_ATTACK_END_NFY)
	unsigned int sealObjectTblidx;
END_PACKET()

BEGIN_PACKET(GU_DOJO_SEAL_CURRENT_STATE_NFY)
	unsigned int sealObjectTblidx;
	BYTE State;
	VECTORXY Loc;
END_PACKET()

BEGIN_PACKET(GU_INVENTORY_CAPSULE_UNLOCK_NFY)
END_PACKET()

BEGIN_PACKET(GU_DOJO_SCRAMBLE_SHIFT_SEAL_STATE_NFY)
	unsigned int dojoTblidx;
	unsigned int objectTblidx;
	unsigned int guildId;
	WCHAR Name[MAX_CHARNAME_SIZE + 1];
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_LP_STATUS_NFY)
	unsigned int handle;
	bool Emergency;
END_PACKET()

BEGIN_PACKET(GU_DURATION_ITEM_BUY_RES)
	unsigned int merchantTblidx;
	BYTE Pos;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_DURATION_RENEW_RES)
	unsigned int ItemHandle;
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_CASHITEM_START_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_CASHITEM_INFO_NFY)
	BYTE Count;
	CASHITEM_BRIEF Info[1];
END_PACKET()

BEGIN_PACKET(GU_CASHITEM_END_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_CASHITEM_MOVE_RES)
	WORD ResultCode;
	DWORD ProductId;
END_PACKET()

BEGIN_PACKET(GU_CASHITEM_USE_RES)
	WORD ResultCode;
	DWORD ProductId;
END_PACKET()

BEGIN_PACKET(GU_CASHITEM_HLSHOP_START_RES)
	WORD ResultCode;
	DWORD RemainAmount;
END_PACKET()

BEGIN_PACKET(GU_CASHITEM_HLSHOP_END_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_CASHITEM_BUY_RES)
	WORD ResultCode;
END_PACKET()

BEGIN_PACKET(GU_GMT_INFO_NFY)
	BYTE GMTResetCount;
	GAMEMANIA_TIME_DATA	Current;
	GAMEMANIA_TIME_DATA	Next;
END_PACKET()

BEGIN_PACKET(GU_GMT_UPDATE_RES)
	WORD ResultCode;
	GAMEMANIA_TIME Next;
END_PACKET()

BEGIN_PACKET(GU_GMT_CHANGED_NFY)
GAMEMANIA_TIME	sCurrent;
END_PACKET()

BEGIN_PACKET(GU_CASHITEM_ADD_NFY)
	CASHITEM_BRIEF Info;
END_PACKET()

BEGIN_PACKET(GU_CASHITEM_DEL_NFY)
	DWORD ProductId;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_MAX_LP)
	unsigned int Subject;
	WORD MaxLp;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_MAX_EP)
	unsigned int Subject;
	WORD MaxEp;
END_PACKET()

BEGIN_PACKET(GU_UPDATE_CHAR_MAX_RP)
	unsigned int Subject;
	WORD MaxRp;
END_PACKET()

#pragma pack()

#endif