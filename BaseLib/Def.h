#ifndef _DEF_H
#define _DEF_H

#pragma once

#include "Base.h"
#include "Vector.h"

typedef char SBYTE;
typedef unsigned char BYTE;
typedef short SWORD;
typedef unsigned short WORD;
typedef long SDWORD;
typedef unsigned long DWORD;
typedef long long SQWORD;
typedef unsigned long long QWORD;
#define pi 3.1415926535897932384626433832795
#define r2d pi/180

#define SERVER_PORT 50200
#define MAX_BUFFER_SIZE 7048

#define MAX_USERNAME_SIZE (12)
#define MAX_PASSWORD_SIZE (12)
#define MAX_AUTHKEY_SIZE (16)
#define MAX_SRVADDR_SIZE (64)
#define MAX_CHARSRV_COUNT (10)
#define MAX_MAC_ADDR_SIZE (6)
#define INVALID_SERVERID (0xFF)
#define INVALID_SLOTID (0xFF)
#define MAX_SERVERNAME_SIZE (32)
#define MAX_CHANNEL_COUNT (10)
#define MAX_CHARNAME_SIZE (16)
#define MAX_PARTYNAME_SIZE (16)
#define MAX_ITEM_OPTION (2)
#define INVALID_MARKING_TYPE (0xffui8)
#define MAX_CHARSLOT_COUNT (8)
#define ALLRACES (0xFF)
#define MAX_CHATMESSAGE_USIZE (256)
#define MAX_CHATMESSAGE_SIZE (256)
#define MAX_CHATMESSAGE_SIZE_MBUFFER (1024)
#define SHORTCUT_MAX_COUNT (100)
#define MAX_SKILL_TARGET (8)
#define MAX_SHOPCART (12)
#define MAX_GUILDNAME_USIZE (32)
#define MAX_DRAGONBALLS (7)
#define MAX_PRIVATESHOPNAME_USIZE (32)
#define MAX_PRIVATESHOPNOTICE_USIZE (64)
#define MAX_MAILMESSAGE_SIZE (128)
#define MAX_MAILSLOT_COUNT (30)
#define MAX_MULTIDEL_COUNT (6)
#define MAX_BUDOKAITEAMNAME_USIZE (20)
#define MAX_HLSSHOP_CART (10)
#define GMT_MAX_EFFECT_LIST_SIZE (5)
#define GMT_MAX_TIME_SLOT_SIZE (3)
#define MAX_HTBSKILL_COUNT (10)
#define MAX_NEXTDESTLOC_COUNT (10)
#define MAX_EFFECTSKILL (2)
#define MAX_INVEN_ITEMCOUNT (128)
#define MAX_PCHARSKILLS_COUNT (120)
#define MAX_PCHARHTBSKILLS_COUNT (30)
#define MAX_PCHARBUFF_COUNT (8)
#define MAX_PCHARDEBUFF_COUNT (8)
#define MAX_WOLDDOJO_COUNT (7)
#define MAX_NEXT_DEST_LOC_COUNT (10)
#define MAX_SIZE_CP_COOKIE (1024 * 2)
#define MAX_SIZE_CJI_KOR_UNI_ID (12)
#define NEWBIE_ITEM_MAX (8)
#define NEWBIE_SKILL_MAX (3)
#define NEWBIE_MAX_QUICKSLOT_COUNT (5)
#define INVALID_OBJECT 0xFFFFFFFF
#define MAX_OBJECT 0x0FFFFFFF
#define MAX_COUNT_USER_HAVE_INVEN_ITEM (128)
#define MAX_COUNT_USER_HAVE_NORMAL_BANK_ITEM (52)
#define MAX_COUNT_USER_HAVE_PUBLIC_BANK_ITEM (16)
#define MAX_COUNT_USER_HAVE_BANK_ITEM (MAX_COUNT_USER_HAVE_NORMAL_BANK_ITEM + MAX_COUNT_USER_HAVE_PUBLIC_BANK_ITEM)
#define MAX_COUNT_USER_HAVE_TOTAL_ITEM (MAX_COUNT_USER_HAVE_INVEN_ITEM + MAX_COUNT_USER_HAVE_BANK_ITEM)
#define CHAR_QUICK_SLOT_MAX_COUNT 48
#define MAX_NPC_HAVE_SKILL 7
#define MAX_COUNT_WAR_FOG (80)
#define MAX_SIZE_WAR_FOG (int)(( MAX_COUNT_WAR_FOG - 1) / 8 + 1)
#define ITEM_UPGRADE_EQUIP_COUNT 5
#define MAX_BANK_ITEM_SLOT 16
#define	MAX_MINORMATCH_TEAM_COUNT 32
#define MAX_MATCH_EXTENDED_STAGE_COUNT 3
#define MAX_MATCH_STAGE_COUNT (5 + MAX_MATCH_EXTENDED_STAGE_COUNT)
#define MAX_MAJORMATCH_EXTENDED_STAGE_COUNT 1
#define	MAX_BUDOKAI_MATCH_REWARD_ITEM_COUNT 3
#define MAX_SIZE_QUESTION_CONTENT_UNICODE (256)
#define ITEM_RECIPE_MAX_COUNT 100
#define MAX_COUNT_DOJO_BANK_HISTORY 40
#define MAX_LENGTH_OF_DOJO_NOTICE_UNICODE (64)

// macro bit flag
#define BIT_FLAG_CLEAR(b)		( (b) = 0 )
#define BIT_FLAG_FLIP(b)		( (b) ^= (b) )
#define BIT_FLAG_SET(b, f)		( (b) |= (f) )
#define BIT_FLAG_UNSET(b, f)	( (b) &= ~(f) )
#define BIT_FLAG_TEST(b, f)		( (b) & (f) ? true : false ) 
#define BIT_FLAG_TOGGLE(b, f)	( (b) ^= (f) )
#define MAKE_BIT_FLAG(x)		( 0x01 << (x) )
#define MAKE_BIT_FLAG64(x)		( DWORD64(0x01) << (x) )

static wchar_t* charToWChar(const char* text)
{
	size_t conv, size = strlen(text) + 1;
	wchar_t* wa = new wchar_t[size];
	mbstowcs_s(&conv, wa, size, text, size);
	return wa;
}

enum ResultCodes
{
	// BASE
	RESULT_SUCCESS = 0,
	RESULT_FAIL,
	// AUTHSERVER
	AUTH_SUCCESS = 100,
	AUTH_FAIL,
	AUTH_VERSION_FAIL,
	AUTH_TOO_LONG_ACCOUNT,
	AUTH_TOO_LONG_PASSWORD,
	AUTH_AUTHKEY_FAIL,
	AUTH_USER_SAMENAME_EXIST,
	AUTH_WRONG_PASSWORD,
	AUTH_USER_NOT_FOUND,
	AUTH_USER_EXIST,
	AUTH_USER_EXIST_IN_CHARACTER_SERVER,
	AUTH_DB_FAIL,
	AUTH_NO_AVAILABLE_CHARACTER_SERVER,
	AUTH_USER_BLOCK,
	AUTH_USER_TEMPORARY_BLOCK,
	AUTH_SERVER_LOCKED,
	AUTH_COMMON_CANT_DO_THAT_FOR_SOME_REASON,
	AUTH_INVALID_CJI_KOR_COOKIE,
	AUTH_IP_BLOCK,
	AUTH_USER_KICKOUT_WAIT_PLZ,
	// CHARSERVER
	CHARACTER_SUCCESS = 200,
	CHARACTER_FAIL,
	CHARACTER_AUTHKEY_FAIL,
	CHARACTER_TOO_LONG_NAME,
	CHARACTER_TOO_SHORT_NAME,
	CHARACTER_SAMENAME_EXIST,
	CHARACTER_COUNT_OVER,
	CHARACTER_NAME_NOT_EXIST,
	CHARACTER_CREATE_VALUE_FAIL,
	CHARACTER_USER_EXIST,
	CHARACTER_USER_EXIST_IN_GAME_SERVER,
	CHARACTER_USER_ITEM_CREATE_FAIL,
	CHARACTER_USER_SKILL_CREATE_FAIL,
	CHARACTER_USER_QUICK_SLOT_CREATE_FAIL,
	CHARACTER_DB_QUERY_FAIL,
	CHARACTER_WRONG_SERVER_FARM_SELECTED,
	CHARACTER_USER_BLOCK,
	CHARACTER_BLOCK_STRING_INCLUDED,
	CHARACTER_TEMPORARY_BLOCK,
	CHARACTER_AUTHKEY_MISMATCH,
	CHARACTER_AUTHKEY_CREATE_FAIL,
	CHARACTER_AUTHKEY_NOT_FOUND,
	CHARACTER_DELETE_GUILD_LEADER_FAIL,
	CHARACTER_DELETE_BUDOKAI_REGISTER_FAIL,
	CHARACTER_SERVER_LOCKED,
	CHARACTER_DISCONNECTED_FORCEDLY,
	CHARACTER_DISCONNECTED_TEMPORARILY,
	CHARACTER_RACE_NOT_ALLOWED,
	CHARACTER_COMMON_CANT_DO_THAT_FOR_SOME_REASON,
	CHARACTER_USER_SHOULD_WAIT_FOR_CONNECT,
	CHARACTER_SERVER_IS_UNDER_CONSTRUCTION,
	CHARACTER_DELETE_CHAR_FAIL,
	// COMMUNITY SERVER
	CHAT_SUCCESS = 300,
	COMMUNITY_FAIL,
	COMMUNITY_INVALID_AUTH_KEY,
	COMMUNITY_ALREADY_IN_SERVER,
	COMMUNITY_DISCONNECTED_FORCEDLY,
	COMMUNITY_DISCONNECTED_TEMPORARILY,
	COMMUNITY_COMMON_SYSTEM_ERROR,
	COMMUNITY_COMMON_NO_SUCH_A_TARGET,
	COMMUNITY_COMMON_TARGET_IS_NOT_YOUR_GUILD_MEMBER,
	COMMUNITY_COMMON_NEED_MORE_TIME_TO_DO_IT,
	COMMUNITY_PARTY_LEADER_DOESNT_EXIST,
	COMMUNITY_PARTY_SAME_PARTYID_ALREADY_EXIST,
	COMMUNITY_PARTY_NO_SUCH_A_PARTY,
	COMMUNITY_PARTY_MEMBER_ALREADY_EXIST,
	COMMUNITY_PARTY_NO_SUCH_A_MEMBER,
	COMMUNITY_GUILD_CREATOR_NOT_FOUND,
	COMMUNITY_GUILD_GUILD_MEMBER_CANT_HAVE_MORE_GUILD,
	COMMUNITY_GUILD_NEED_MORE_PARTY_MEMBER_FOR_NEW_GUILD,
	COMMUNITY_GUILD_YOU_DONT_BELONG_TO_GUILD,
	COMMUNITY_GUILD_YOU_ARE_NOT_GUILD_MASTER,
	COMMUNITY_GUILD_GUILD_IS_BEING_DISBANDED,
	COMMUNITY_GUILD_GUILD_IS_NOT_BEING_DISBANDED,
	COMMUNITY_GUILD_YOU_DONT_HAVE_RIGHT_TO_INVITE,
	COMMUNITY_GUILD_TARGET_IS_ALREADY_IN_A_GUILD,
	COMMUNITY_GUILD_TARGET_ALREADY_HAS_INVITATION,
	COMMUNITY_GUILD_YOU_HAVE_NO_INVITATION,
	COMMUNITY_COMMON_NO_SUCH_A_GUILD,
	COMMUNITY_GUILD_YOU_ARE_ALREADY_IN_A_GUILD,
	COMMUNITY_GUILD_MAX_NUMBER_OF_MEMBERS,
	COMMUNITY_GUILD_LEADER_CANT_LEAVE,
	COMMUNITY_GUILD_YOU_DONT_HAVE_RIGHT_TO_KICK_OUT,
	COMMUNITY_GUILD_CANT_KICK_YOURSELF_OUT,
	COMMUNITY_GUILD_TRIED_TO_APPOINT_YOURSELF,
	COMMUNITY_GUILD_TARGET_IS_ALREADY_SECOND_MASTER,
	COMMUNITY_GUILD_MAX_NUMBER_OF_SECOND_MASTERS,
	COMMUNITY_GUILD_TARGET_IS_NOT_SECOND_MASTER,
	COMMUNITY_GUILD_FUNCTION_NOT_FOUND,
	COMMUNITY_GUILD_BANK_USING_NOW,
	COMMUNITY_FRIEND_CHAR_NOT_FOUND,
	COMMUNITY_FRIEND_CHAR_ARLEADY_ADDED,
	COMMUNITY_FRIEND_MAX_COUNT_OVER,
	COMMUNITY_FRIEND_CHAR_EXIST,
	COMMUNITY_FRIEND_BLACK_CHAR_EXIST,
	COMMUNITY_FRIEND_SELF_FAIL,
	COMMUNITY_RANK_BATTLE_LIST_NOT_FOUND,
	COMMUNITY_GUILD_BANK_QUERY,
	COMMUNITY_GUILD_BANK_CLOSED,
	COMMUNITY_GUILD_KICKOUT,
	COMMUNITY_GUILD_LEAVE,
	COMMUNITY_TMQ_CHAR_NOT_FOUND,
	COMMUNITY_TMQ_DATA_NOT_FOUND,
	COMMUNITY_DOJO_MAKE_FAIL,
	COMMUNITY_DOJO_DEL_FAIL,
	COMMUNITY_DOJO_FIND_FAIL,
	COMMUNITY_DOJO_SCRAMBLE_ARLEADY_HAVE,
	COMMUNITY_DOJO_SCRAMBLE_WAIT,
	COMMUNITY_DOJO_SCRAMBLE_REJECT_FAIL_FOR_BANK_USE,
	COMMUNITY_DOJO_SCRAMBLE_REJECT_FAIL_SECOND,
	COMMUNITY_DOJO_SEED_ALREADY_SETTING,
	COMMUNITY_DOJO_SEED_NAME_FAIL,
	COMMUNITY_DOJO_SEED_NOT_SET,
	COMMUNITY_DOJO_NON_EXISTING_FUNCTION,
	COMMUNITY_DOJO_YOU_ARE_NOT_OWNNER,
	COMMUNITY_GUILD_FIND_FAIL,
	COMMUNITY_DOJO_BANK_ZENNY_NOT_ENOUGH,
	COMMUNITY_GUILD_DISBANDE_FAIL_FOR_DOJO,
	COMMUNITY_DOJO_SCRAMBLE_FAIL_FOR_BEING_DISBANDED,
	// GAME SERVER
	GAME_SUCCESS = 500,				// ���Ӽ��� ���� ��� ����
	GAME_FAIL,						// ���Ӽ��� ���� �������� ����

	GAME_DB_CHAR_DATA_LOAD_FAIL,	// ĳ���� ����Ÿ �ε��� �����Ͽ����ϴ�.
	GAME_DB_CHAR_NOT_FOUND,			// �ش��ϴ� ĳ��Ÿ ����Ÿ�� �������� �ʽ��ϴ�.

	GAME_INVALID_AUTH_KEY,			// ����Ű ������ �����Ͽ����ϴ�.
	GAME_USER_EXIST,				// �̹� �������Դϴ�.
	GAME_SERVER_LOCKED,				// ���� ������ ��� ���¿��� ������ �� �����ϴ�.
	GAME_WRONG_SERVER_CHANNEL_HAS_BEEN_SPECIFIED,			// �߸��� ���� ä���� �����Ͽ����ϴ�.

	GAME_CHAR_IS_WRONG_STATE,		// ������ �� �� �����ϴ�
	GAME_INPUT_PARAMETER_WRONG,		// �ùٸ��� ���� �Է� �Դϴ�.

	GAME_TARGET_IS_WRONG_STATE,		// ����� ������ ���°� �ƴմϴ�.
	GAME_TARGET_NOT_FOUND,			// ����� ã�� �� �����ϴ�.
	GAME_TARGET_TOO_FAR,			// ������ �Ÿ��� �ʹ� �ٴϴ�.
	GAME_TARGET_TOO_CLOSE,			// ������ �Ÿ��� �ʹ� �������ϴ�.
	GAME_TARGET_HAS_NOT_FUNCTION,	// ����� �ش� ����� �������� �ʽ��ϴ�.

	GAME_DISCONNECTED_FORCEDLY,							// ����� ���� ������ ������ ����Ǿ����ϴ�.
	GAME_DISCONNECTED_TEMPORARILY,						// ��ڿ� ���Ͽ� �Ͻ������� �α׾ƿ� ó���� �Ǿ����ϴ�.

	GAME_COMMON_YOU_ARE_NOT_IN_A_PARTY,					// ��Ƽ�� ���� ���� �ʽ��ϴ�.
	GAME_COMMON_YOU_ARE_NOT_A_PARTY_LEADER,				// ��Ƽ ������ �ƴմϴ�.
	GAME_COMMON_ZENNY_CANT_BE_USED_RIGHT_NOW,			// �Ͻ������� ���ϸ� ����� �� ���� ��Ȳ�Դϴ�. ��� �� �ٽ� �õ��ϼ���.
	GAME_COMMON_CANT_DO_THAT_FOR_SOME_REASON,			// �ý��� ������ �۾��� ó���� �� �����ϴ�.
	GAME_COMMON_NON_EXISTING_PET_SPECIFIED,				// �������� �ʴ� ���� �����Ͽ����ϴ�.

	GAME_COMMON_CANT_DO_THAT_IN_SPAWNING_STATE,				// ���� ���� ���߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_STANDING_STATE,				// �� ���� ������ ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_STANDING_JUMPING_STATE,		// ���ڸ� ���� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_JUMPING_STATE,				// ���� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_NON_JUMPING_STATE,			// ���� ���� �ƴ� ������ ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_SITTING_STATE,				// �ɾ� ���� ������ ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_FAINTING_STATE,				// �ǽ��� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_CAMPING_STATE,				// ķ�� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_LEAVING_STATE,				// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_MOVING_STATE,				// �̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_MOVING_JUMPING_STATE,		// ���� �̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_DESTMOVING_STATE,			// �̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_FOLLOWING_STATE,			// �̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_FALLING_STATE,				// �������� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_DASH_STATE,					// �뽬 �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_TELEPORTING_STATE,			// �ڷ���Ʈ ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_SLIDING_STATE,				// �����̵� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_KNOCKDOWN_STATE,			// �˴ٿ� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_FOCUSING_STATE,				// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_CASTING_STATE,				// ��ų ���� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_AFFECTING_STATE,			// ��ų ���� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_KEEPING_EFFECT_STATE,		// ȿ�� ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_CASTING_ITEM_STATE,			// ������ ��� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_STUNNED_STATE,				// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_SLEEPING_STATE,				// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_PARALYZED_STATE,			// ���� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_HTB_STATE,					// HTB ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_SANDBAG_STATE,				// HTB ��ų�� �ɸ� ���¿����� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_CHARGING_STATE,				// �⸦ ������ �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_BLOCKING_STATE,				// Block ��忡���� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_DESPAWNING_STATE,			// ���忡�� ����� ���߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_PRIVATESHOP_STATE,			// ���� ������ ���� ���� ������ ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_DIRECT_PLAY_STATE,			// ���� �߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_OPERATING_STATE,			// ������Ʈ �����߿��� ����� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_RIDEON_STATE,				// Ż���� ź���¿����� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_TURNING_STATE,				// �ϻ��¿����� �� �� ���� ����Դϴ�.

	GAME_COMMON_CANT_DO_THAT_IN_INVISIBLE_CONDITION,		// ���� ���¿����� ��� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_HIDING_KI_CONDITION,		// �� ����� ���¿����� ��� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_TRANSPARENT_CONDITION,		// GM ���� ���¿����� ��� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_TERROR_CONDITION,			// ������ �ɸ� ���¿����� ��� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_AFTEREFFECT_CONDITION,		// ������ ���¿����� ��� �� �� ���� ����Դϴ�.
	GAME_COMMON_CANT_DO_THAT_IN_CHARGING_BLOCKED_CONDITION,		// �� �����Ⱑ �Ұ����� �����Դϴ�.

	GAME_GAMERULE_REG_CANT_PLAY_IN_FREEBATTLE,				// ������Ʋ �߿��� �� �� �����ϴ�.
	GAME_GAMERULE_REG_CANT_PLAY_IN_RANKBATTLE,				// ��ũ��Ʋ �߿��� �� �� �����ϴ�.
	GAME_GAMERULE_REG_CANT_PLAY_IN_TMQ,						// Ÿ�Ӹӽ� ����Ʈ �߿��� �� �� �����ϴ�.
	GAME_GAMERULE_REG_CANT_PLAY_IN_SUMMON_DRAGONBALL,		// �巡�ﺼ ��ȯ �߿��� �� �� �����ϴ�.
	GAME_GAMERULE_REG_CANT_PLAY_IN_PRIVATE_SHOP,			// ���λ��� �߿��� �� �� �����ϴ�.
	GAME_GAMERULE_REG_CANT_PLAY_IN_BUDOKAI,					// õ�����Ϲ���ȸ �߿��� �� �� �����ϴ�.

	GAME_GAMERULE_REG_ALREADY_JOINED_IN_FREEBATTLE,			// �̹� ������Ʋ ���� ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_JOINED_IN_RANKBATTLE,			// �̹� ��ũ��Ʋ ���� ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_JOINED_IN_TMQ,				// �̹� Ÿ�Ӹӽ� ����Ʈ ���� ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_SUMMON_DRAGONBALL,			// �̹� �巡�ﺼ ��ȯ ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_OPENED_PRIVATE_SHOP,			// �̹� ���λ��� ���� ���Դϴ�.
	GAME_GAMERULE_REG_ALREADY_JOINED_BUDOKAI,				// �̹� õ�����Ϲ���ȸ ���� ���Դϴ�.

	GAME_CONTENTS_LOCK,										// ���� ����ִ� �������Դϴ�.
	GAME_CONTENTS_CAN_NOT_PLAY_IN_BUDOKAI_REGISTER_STATE,	// õ�����Ϲ���ȸ ��ϱⰣ �߿��� �̿��� �� �����ϴ�.

	GAME_WORLD_CAN_NOT_CREATE_DYNAMIC_WORLD,			// ���带 ������ �� �����ϴ�.
	GAME_WORLD_NOW_CREATING,							// ��� �� �ٽ� �õ��Ͻʽÿ�.
	GAME_WORLD_ALREADY_WORLD_ENTERED,					// �̹� ���忡 ������ �ֽ��ϴ�.
	GAME_WORLD_CANT_ENTER_WORLD,						// ������ �� �ִ� ���尡 �����ϴ�.
	GAME_WORLD_ALREADY_WORLD_AREA_ENTERED,				// �̹� ���� ������ ������ �ֽ��ϴ�.
	GAME_WORLD_CANT_FIND_WORLD_AREA,					// ������ ���念���� ã�� �� �����ϴ�.
	GAME_WORLD_CANT_ENTER_WORLD_AREA,					// ������ �� �ִ¿��念���� �����ϴ�.

	GAME_SHORTCUT_KEY_ARLEADY_FOUND,					// ���� Ű�� �̹� �����Ǿ� �ֽ��ϴ�.
	GAME_SHORTCUT_KEY_DEL_NOT_FOUND,					// �����Ϸ��� Ű�� �����ϴ�.
	GAME_SHORTCUT_KEY_MODIFY_NOT_FOUND,					// �����Ϸ��� Ű�� �����ϴ�.

	GAME_COMMON_CANT_DO_THAT_NOT_ALLOWED_TARGET,		// ��� ������ �Ұ����� ���� �Դϴ�.

	GAME_COMMON_CANT_FIND_OBJECT,						// �ش� ������Ʈ�� ã�� �� �����ϴ�.

	GAME_CHAR_WRONG_REVIVAL_METHOD,						// �߸��� ��Ȱ ����Դϴ�.
	GAME_CANNOT_CONNECT_DUE_TO_TIMEOUT,					// Ÿ�Ӿƿ��Ǿ� ������ �� �����ϴ�.
	GAME_CANNOT_CONNECT_TARGET_CHANNEL_FULL,			// �̵��Ϸ��� ä�ο� ���� ������ �����ϴ�.
	GAME_CANNOT_CONNECT_DUE_TO_INVAlID_CHARACTER,		// �������� ĳ���Ͱ� �ƴմϴ�.
	GAME_TARGET_HAS_DIFFERENT_JOB,						// ����� ������ �ùٸ��� �ʽ��ϴ�.

	GAME_GMT_NOT_ENOUGH_RESET_POINT,					// GMT �缳�� ����Ʈ�� �����մϴ�.

	//-----------------------------------------------------------------
	GAME_SKILL_NOT_ACTIVE_TYPE = 600,		// Active Ÿ���� ��ų�� �ƴմϴ�.
	GAME_SKILL_YOU_DONT_HAVE_THE_SKILL,		// ������ ���� ���� ��ų�Դϴ�.
	GAME_SKILL_NOT_EXISTING_SKILL,			// �������� �ʴ� ��ų�Դϴ�.
	GAME_SKILL_CANT_CAST_NOW,				// ���� ��ų�� ������ �� �ִ� ���°� �ƴմϴ�.
	GAME_SKILL_NO_TARGET_APPOINTED,				// ����� �����ϼž� �մϴ�.
	GAME_SKILL_INVALID_TARGET_APPOINTED,		// ���� Ÿ�ٿ� ��ų�� ����� �� �����ϴ�.
	GAME_SKILL_NOT_READY_TO_BE_CAST,		// ��ų�� ��Ÿ���� ��ٷ��� �մϴ�.
	GAME_SKILL_NOT_ENOUGH_LP,				// LP�� ������� �ʽ��ϴ�.
	GAME_SKILL_NOT_ENOUGH_EP,				// EP�� ������� �ʽ��ϴ�.
	GAME_SKILL_NOT_ENOUGH_RP_BALL,						// RP ������ ������� �ʽ��ϴ�.

	GAME_SKILL_NO_REQUIRED_ITEM,			// ��ų�� ����ϱ� ���� �ʿ��� �������� ������ ���� �ʽ��ϴ�.
	GAME_SKILL_TOO_MANY_LP_TO_USE_SKILL,				// LP�� 50% ������ ������ �� ��ų�� ����� �� �ֽ��ϴ�.
	GAME_SKILL_TARGET_IS_NOT_KNOCKED_DOWN,				// Ÿ���� knock down ���°� �ƴմϴ�.
	GAME_SKILL_RESISTED,								// ��ų�� �����߽��ϴ�.
	GAME_SKILL_TRIED_TO_LEARN_AN_EXISTING_SKILL,		// �̹� ������ �ִ� ��ų�� ��� �� �����ϴ�.
	GAME_SKILL_TRIED_TO_LEARN_WRONG_CLASS_SKILL,		// ������ ���� �ʴ� ��ų�� ��� �� �����ϴ�.
	GAME_SKILL_TOO_HIGH_LEVEL_TO_TRAIN,					// ������ ���Ƽ� ���� ��ų�� ��� �� �����ϴ�.
	GAME_SKILL_NOT_ENOUGH_ZENNY,						// Zenny�� ���ڶ� ��ų�� ��� �� �����ϴ�.
	GAME_SKILL_NO_EMPTY_SKILL_SLOT,						// �� ��ų ������ �����ϴ�.
	GAME_SKILL_YOU_HAVE_NO_LOWER_LEVEL_SKILL,			// ���׷��̵带 ���ؼ��� ������ ��ų���� �� �ܰ� ���� ��ų�� ������ �־�� �մϴ�.

	GAME_SKILL_ALREADY_MASTERED_SKILL,					// �̹� �ñ��� ��ų�� ������ �����Դϴ�.
	GAME_SKILL_NO_PREREQUISITE_SKILLS_YOU_HAVE,			// ��ų ������ ���� �̹� ���� �־�� �� ��ų�� ������ ���� �ʽ��ϴ�.
	GAME_SKILL_UPGRADE_ONLY_SKILL,		// ���׷��̵�θ� ���� �� �ִ� ��ų�Դϴ�.
	GAME_SKILL_SHOULD_BE_GAINED_BY_YOURSELF,			// ������ ����� �ϴ� ��ų�Դϴ�.
	GAME_SKILL_CANT_BE_GAINED_BY_YOURSELF,				// ������ ��� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_FOR_SOME_REASON,		// �ý��� ������ ��ų�� ����� �� �����ϴ�.
	GAME_SKILL_TARGET_IS_NOT_IN_FRONT_SIDE,		// Ÿ���� ��� �տ� ��ġ�ؾ� �մϴ�.
	GAME_SKILL_YOU_ARE_NOT_IN_BACKSIDE_OF_TARGET,		// ����� �ڿ����� ��ų�� ����� �� �ֽ��ϴ�.
	GAME_SKILL_TARGET_IS_IN_FAINT,		// Ÿ���� �ǽ��� �����Դϴ�.
	GAME_SKILL_CAN_BE_CAST_ONLY_ON_PLAYER,		// �÷��̾�Ը� ����� �� �ִ� ��ų�Դϴ�.

	GAME_SKILL_TARGET_IS_NOT_FAINTING,					// Ÿ���� �ǽ��� ���°� �ƴմϴ�.
	GAME_SKILL_NOT_BATTLE_AVAILABLE_LOCATION,			// ��ų ����ڿ� ��� ��� ������ ������ ������ ��ġ�ؾ� �մϴ�.
	GAME_SKILL_CASTING_CANCELED_BY_DAMAGE,				// ������ �޾� ��ų ������ ��ҵǾ����ϴ�.
	GAME_SKILL_CANT_SET_THAT_RP_BONUS_IN_SKILL,			// ������ ��ų������ ������ �� ���� RP ���ʽ� Ÿ���Դϴ�.
	GAME_SKILL_CANT_USE_THAT_RP_BONUS_IN_SKILL,			// ������ ��ų������ ����� �� ���� RP ���ʽ� Ÿ���Դϴ�.
	GAME_SKILL_NO_BUFF_TO_DROP_FOUND,					// ������ �� �ִ� ������ �����Ͽ��� �մϴ�.
	GAME_SKILL_ALREADY_TRANSFORMED,						// ������ ���� ���°� �����Ǿ�� ���ο� ������ ����� �� �ֽ��ϴ�.
	GAME_SKILL_NOT_TRANSFORMED,							// ���� ���°� �ƴմϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_SUPER_SAIYAN,		// �ʻ��̾��� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_PURE_MAJIN,			// ���� ���� ���¿����� ����� �� ���� ��ų�Դϴ�.

	GAME_SKILL_CANT_USE_SKILL_WHEN_GREAT_NAMEK,			// �Ŵ� ����ũ ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_KAIOKEN,				// ��ձ� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_SPINNING_ATTACK,		// ȸ�� ���� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_VEHICLE,				// Ż �� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_CANT_USE_SKILL_WHEN_NOT_TRANSFORMED,		// �������� ���� ���¿����� ����� �� ���� ��ų�Դϴ�.
	GAME_SKILL_NOT_ENOUGH_SP_POINT,						// SP POINT �� �����մϴ�.
	GAME_SKILL_ERASE_FAIL,								// ��ų�� ����ٰ� �����߽��ϴ�.
	GAME_BLOCK_ATTACK_NOW,								// ����� ����Ǿ� ����� �� �����ϴ�. 
	GAME_SKILL_HAVE_UPGRADED_SKILL,						// ��ų�� ���׷��̵� �� ��ų�� ������ �����Դϴ�.
	GAME_SKILL_CANT_BE_CAST_ON_YOURSELF,				// �ڽ��� �����ϰ� ����� �� ���� ��ų�Դϴ�.

	GAME_SKILL_CANT_USE_HTB_WHEN_TRANSFORMED,			// ���� �߿��� HTB�� ����� �� �����ϴ�.
	GAME_SKILL_CASTING_CANCELED_BY_TARGET_NEW_STATE,	// 651 // ����� ���°� �ٲ�� ������ ��ҵǾ����ϴ�.
	GAME_SKILL_CASTING_CANCELED_OBJECT_OCCLUSION,       // ĳ�����߿� ������Ʈ�� ������ ��ҵǾ����ϴ�.
	GAME_SKILL_CANT_USE_VEHICLE_WHEN_TRANSFORMED,		// ���� �߿��� Ż ���� �̿��� �� �����ϴ�.
	GAME_SKILL_CANT_USE_WHEN_TRANSFORMED,				// ���� �߿��� �̿��� �� �����ϴ�.
	//-----------------------------------------------------------------
	GAME_CHAR_ONLY_ADULT_CAN_CHANGE_CLASS = 700,				// � ���¿����� ������ �� �� �ֽ��ϴ�.
	GAME_CHAR_NO_AUTHORITY_FOR_CHANGING_CLASS,					// ������ �� �ִ� �ڰ��� ���߰� ���� �ʽ��ϴ�.
	GAME_GM_CANT_DO_THAT_WHEN_YOU_ARE_HIDING,					// 702 // ���� ���¿����� �� �� ���� ����Դϴ�.
	//-----------------------------------------------------------------
	GAME_ITEM_NUM_NULL = 800,		// ������ ��ȣ�� �߸��Ǿ����ϴ�.
	GAME_ITEM_POSITION_FAIL,		// ������ ��ġ���� �߸��Ǿ����ϴ�.	
	GAME_ITEM_OWNER_NOT_SAME,		// ������ �����ְ� �߸��Ǿ����ϴ�.	
	GAME_ITEM_NOT_SAME,             // �������� �߸� �Ǿ����ϴ�.
	GAME_ITEM_OWNER_NULL,			// ������ �����ְ� �����ϴ�.
	GAME_ITEM_STACK_FAIL,           // ������ ������ �߸� �Ǿ����ϴ�.
	GAME_ITEM_NOT_FOUND,			// �������� ã�� �� �����ϴ�.
	GAME_NEEDITEM_NOT_FOUND,		// ������ ���Ž� �ʿ��� �������� Table���� ã�� �� �����ϴ�. [7/17/2008 SGpro]
	GAME_NEEDITEM_NOT_FOUND_INVANTORY,	// ������ ���Ž� �ʿ��� ��ȯ�������� �����ϴ�. [7/17/2008 SGpro]
	GAME_ITEM_BAG_IS_NOT_EMPTY,		// ������ ����� �̵��� �����մϴ�.

	GAME_ITEM_ALREADY_EXIST,        // �������� �����ϹǷ� �̵��� �Ұ� �մϴ�.
	GAME_ITEM_MAX_COUNT_OVER,       // ������ ������ �ʰ��Ͽ����ϴ�.
	GAME_ITEM_STACK_FULL,           // ������ ����á���ϴ�.
	GAME_EQUIP_SLOT_NOT_EMPTY,		// ��� ������ ������� �ʽ��ϴ�.
	GAME_ITEM_CLASS_FAIL,			// ������ ���� ���� Ŭ����Ÿ���� �ƴմϴ�.
	GAME_ITEM_NEED_MORE_LEVEL,		// ���� �������� �������� ������ �� �����ϴ�.
	GAME_ITEM_NEED_MORE_PARAMETER,  // ������ ���밡�� �ɷ�ġ�� �����մϴ�.
	GAME_ITEM_MAX_WATT_OVER,		// Scouter ���������� Max Watt���� �ʰ��Ͽ����ϴ�. 
	GAME_ITEM_INVEN_FULL,			// ������ ����á���ϴ�.
	GAME_ITEM_LOOTING,				// �������� �ݰ� �ֽ��ϴ�.

	GAME_ITEM_UNIDENTIFY,	        // ������ Ȯ���� �ȵǾ��ֽ��ϴ�.
	GAME_ITEM_UNIDENTIFY_FAIL,		// ������ Ȯ�� ����
	GAME_LOOTING_FAIL,			// ������ �������� �����ϴ�.
	GAME_ZENNY_NOT_ENOUGH,			// ���� �����մϴ�.	
	GAME_ITEM_IS_LOCK,				// �������� ��� �����Դϴ�.
	GAME_CHARM_POINT_IS_LOCKED,		// ������ ���� ����Ʈ�� ���� ó���� �Ϸ���� �ʾҽ��ϴ�. ��� �Ŀ� �ٽ� �õ��Ͽ� �ֽʽÿ�.
	GAME_ZENNY_IS_LOCK,				// ������ ��� �����Դϴ�.
	GAME_REPAIR_VALUE_FAIL,			// ���� ������ �������� �ƴմϴ�.
	GAME_REPAIR_NOT_FOUND,			// ���� ������ �������� �����ϴ�.
	GAME_ITEM_YOU_ARE_USING_AN_ITEM,				// �������� ����ϴ� ���Դϴ�.

	GAME_ITEM_NOT_FOR_USE,			// ����� �� �ִ� �������� �ƴմϴ�.
	GAME_ITEM_NOT_BATTLE_AVAILABLE_LOCATION,		// ������ ����ڿ� ��� ��� ������ ������ ������ ��ġ�ؾ� �մϴ�.
	GAME_ITEM_CANT_USE_FOR_SOME_REASON,		// �ý��� ������ �������� ����� �� �����ϴ�.
	GAME_ITEM_NOT_READY_TO_BE_USED,		// �������� ��Ÿ���� ��ٷ��� �մϴ�.
	GAME_ITEM_TOO_LOW_LEVEL_TO_USE_ITEM,		// ������ ���ڶ� �������� ����� �� �����ϴ�.
	GAME_ITEM_NOT_ENOUGH_LP,		// LP�� ������� �ʽ��ϴ�.
	GAME_ITEM_NOT_ENOUGH_EP,		// EP�� ������� �ʽ��ϴ�.
	GAME_ITEM_NOT_ENOUGH_RP_BALL,						// RP ������ ������� �ʽ��ϴ�.
	GAME_ITEM_CASTING_CANCELED,							// ������ ����� ��ҵǾ����ϴ�.
	GAME_ITEM_CANT_USE_NOW,		// ���� �������� ����� �� �ִ� ���°� �ƴմϴ�.

	GAME_ITEM_DUR_ZERO,			// �������� �����Դϴ�.
	GAME_SCOUTER_MAX_OVER,		// ����ġ�� ���� �Ǿ� ��ī���� ���������� ���峵���ϴ�.
	GAME_ITEM_NOT_ENOUGH,		// �������� �������� �ʽ��ϴ�.
	GAME_ITEM_UPGRADE_NO_SUBJECT_ITEM,			// ���׷��̵��� ��� �������� �־� �ֽʽÿ�.
	GAME_ITEM_UPGRADE_NO_HOIPOI_STONE,			// ������ �ϱ� ���ؼ��� ȣ�����̽����� �ʿ��մϴ�.
	GAME_ITEM_UPGRADE_WRONG_ITEM_TYPE,			// ���⳪ ���� ���׷��̵带 �� �� �ֽ��ϴ�.
	GAME_ITEM_UPGRADE_ALREADY_MAX_GRADE,		// �� �̻� ���׷��̵带 �� �� ���� �������Դϴ�.
	GAME_ITEM_UPGRADE_FAIL,     // ������ ���׷��̵� ����
	GAME_ITEM_UPGRADE_FAIL_AND_DEL,     // ���׷��̵� ���з� �������� �ı��Ǿ����ϴ�.
	GAME_BANK_NOT_READY,		// â�� ���� �������� �ʽ��ϴ�.

	GAME_BANK_ALREADY_EXIST,		// â�� �̹� �����մϴ�.
	GAME_SCOUTER_PARTS_NOT_FOUND,	// �ش� ��ī���� ������ ã�� ���߽��ϴ�.
	GAME_SCOUTER_JAMMING,			// ���Ĺ��ط� ���� ǥ���� �� �����ϴ�. 
	GAME_SCOUTER_TARGET_FAIL,	 // ǥ�� ����� �������մϴ�.
	GAME_CHAR_LEVEL_FAIL,		// ������ ���� �ʽ��ϴ�.
	GAME_CHAR_CLASS_FAIL,		// �ش�Ŭ������ ���� �ʽ��ϴ�.
	GAME_CHAR_RACE_FAIL,		// �ش� ������ ���� �ʽ��ϴ�.
	GAME_ZENNY_OVER,			// �ݾ��� �����Ǿ����ϴ�.
	GAME_QUEST_ALREADY_EXIST,	// �̹� �����ϴ� ����Ʈ�Դϴ�.
	GAME_QUEST_COUNT_OVER,		// ���డ���� ����Ʈ���� �ʰ��Ǿ����ϴ�.

	GAME_QUEST_NOT_EXIST,		// �������� �ʴ� ����Ʈ�Դϴ�.
	GAME_ITEM_CREATE_COUNT_OVER,// �ѹ��� ������ �� �ִ� ������ �Ѿ���.
	GAME_ITEM_DELETE_COUNT_OVER,// �ѹ��� ������ �� �ִ� ������ �Ѿ���.
	GAME_GM_LEVEL_NOT_FOUND,	// GM Level �� ����
	GAME_GM_PUNISH_NOT_FOUND,	// Punish type error
	GAME_SCOUTER_BODY_IS_NOT_EMPTY, // ��ī���� ������ ����� �̵������մϴ�.
	GAME_SCOUTER_PARTS_LEVEL_FAIL,	// ��ī���� ���� ������ ���� �ʽ��ϴ�.
	GAME_TRADE_TARGET_WRONG_STATE,		// ������ ���� Ʈ���̵带 �� �� ���� �����Դϴ�.
	GAME_TRADE_ALREADY_USE,		// Ʈ���̵� ���Դϴ�.
	GAME_TRADE_DENY_USE,		// Ʈ���̵� ���� ���Դϴ�.

	GAME_TRADE_DENY,			// Ʈ���̵带 �����Ͽ����ϴ�.
	GAME_TRADE_REPLY_WAIT_OVER,
	GAME_TRADE_WRONG_STATE,		// Ʈ���̵��ϱ⿡ ������ ���°� �ƴմϴ�.
	GAME_TRADE_ITEM_INVALID,	// Ʈ���̵� �Ұ����� ������ �Դϴ�.
	GAME_TRADE_ALREADY_CLOSE,	// Ʈ���̵尡 �̹� ������ �Դϴ�.
	GAME_TRADE_ALREADY_OPEN,	// Ʈ���̵尡 �̹� �������� �Դϴ�.
	GAME_TRADE_CHANGED_STATE,	// Ʈ���̵� ��ǰ ������ �ٲ�����ϴ�.
	GAME_ITEM_NOT_GO_THERE,		// �ű�� ���� ��ġ�Դϴ�.
	GAME_DRAGONBALL_OBJECT_ARLEADY_USED, // ������ ��� ���Դϴ�.
	GAME_DRAGONBALL_NOT_FOUND,	 // �巡�ﺼ�� ã���� �����ϴ�.

	GAME_DRAGONBALL_REWARD_NOT_FOUND,   // �巡�ﺼ ������ ã�� �� �����ϴ�.
	GAME_DRAGONBALL_TIME_OVER,	// ���ð��� ����Ǿ����ϴ�.
	GAME_DRAGONBALL_SAME_EXIST,		// ���� �� �巡�ﺼ�� �ֽ��ϴ�.
	GAME_QUSET_ITEM_CREATE_COUNT_OVER,// ����Ʈ �κ��丮���� ������ �������� ������ �� �����ϴ�.
	GAME_ITEM_CANT_BE_USED_ON_YOURSELF,					// �ڽ��� �����ϰ� ����� �� ���� �������Դϴ�.
	GAME_ITEM_TYPE_NOT_MISMATCHED,	// ������ Ÿ���� ���� �ʽ��ϴ�.
	GAME_ITEM_RECIPE_ALREADY_EXIST,	// ���� �����ǰ� �̹� ���� �մϴ�.	
	GAME_ITEM_RECIPE_NOT_FOUND,		// �ش� �����ǰ� ���� ���� �ʽ��ϴ� .	
	GAME_ITEM_RECIPE_REGISTER_PROFESSION,	// �ش� ������ �ͽ� ������ ���� �����Ͽ��� �մϴ�.
	GAME_ITEM_RECIPE_LEVEL_MISMATCHED,	// �ش� ������ �����Ƿ����� ���� �ʽ��ϴ�.
	GAME_ITEM_RECIPE_TYPE_MISMATCHED,	// �ش� ������ ������ Ÿ���� ���� �ʽ��ϴ�.
	GAME_ITEM_RECIPE_REGISTER_FAIL,		// ������ ������ ��Ͽ� �����߽��ϴ�.
	GAME_ZENNY_LOOTING,					// ���ϸ� �ݰ� �ֽ��ϴ�.
	GAME_ITEM_RECIPE_REGISTER_PROFESSION_FAIL,	// ������ �ͽ� ������ �߸��Ǿ����ϴ�.
	GAME_SCOUTER_MAIN_PARTS_NOT_FOUND,	// ��ī���� ���� ������ ã�� ���߽��ϴ�.
	GAME_ITEM_HOIPOIMIX_FARE_NOT_SET,	// ȣ�����̸ӽŻ��ᰡ ���õǾ����� �ʽ��ϴ�. 
	GAME_ITEM_HOIPOIMIX_FARE_CAN_NOT_SET,	// ȣ�����̸ӽŻ��� ������ ĳ���ӽŸ� �����մϴ�. 
	GAME_ITEM_HOIPOIMIX_FARE_RATE_FAIL,	// ȣ�����̸ӽŻ��ᰡ ������ �ʰ� �Ǿ����ϴ�.
	GAME_ITEM_CANNOT_BUY_NOW,			// ������ �� �ִ� �������� �ƴմϴ�.
	// GAME GM TOOL
	GAME_GM_TOOL_SUCCESS = 900,			// GM TOOL �۾��� �����߽��ϴ�.
	GAME_GM_TOOL_FAIL,					// GM TOOL FAIL
	GAME_GM_TOOL_LOGIN_PASS_FAIL,		// GM TOOL LOGIN PASSWORD MISMATCHED
	GAME_GM_TOOL_ACCOUNT_EXIST,			// �̹� �����ϴ� ���̵� �Դϴ�.
	GAME_GM_TOOL_PASS_NULL,				// �н����带 �������� �ʾҽ��ϴ�.
	GAME_GM_TOOL_GROUP_NOT_FOUND,		// �׷��� �����ϴ� �׷��� ���� ����ʽÿ�.
	GAME_GM_TOOL_GROUP_ALREADY_EXIST,	// 
	GAME_GM_TOOL_GROUP_NEED_ADMIN,
	GAME_GM_TOOL_USER_NOT_FOUND,		// �ش� ������ �������� �ʽ��ϴ�.
	GAME_GM_TOOL_LOGIN_DUPLICATE,		// �ߺ� �α���
	GAME_GM_TOOL_CHARACTER_IS_NOT_KICK,	// ű ���°� �ƴϴ�.
	GAME_GM_TOOL_CHARACTER_EXIST,		// ĳ���Ͱ� �����մϴ�.
	GAME_GM_TOOL_INVALID_TOOL_VERSION,	// �� ������ ���� �ʽ��ϴ�.
	GAME_GM_TOOL_INVALID_IP_ADDRESS,	// �ΰ����� ���� IP�Դϴ�.
	GAME_GM_TOOL_NOTICE_OVER,			// �������� �ִ밹���� �ʰ��߽��ϴ�.
	GAME_GM_TOOL_GUILD_NOT_FOUND,		// ��带 ã�� ���߽��ϴ�.
	GAME_GM_TOOL_CHARACTER_NOT_EXIST,	// ĳ���Ͱ� �������� �ʽ��ϴ�.
	GAME_GM_TOOL_SERVER_CANT_BE_TURNED_ON_BY_GM_TOOL,		// GM Tool�� ������ �� ���� �����Դϴ�.
	GAME_GM_TOOL_SERVER_CANT_BE_TURNED_OFF_BY_GM_TOOL,		// GM Tool�� ������ �� ���� �����Դϴ�.
	GAME_GM_TOOL_WRONG_SERVER_TO_TURN_ON,					// ������ ������ �߸� �����Ͽ����ϴ�.
	GAME_GM_TOOL_WRONG_SERVER_TO_TURN_OFF,					// ������ ������ �߸� �����Ͽ����ϴ�.
	GAME_GM_TOOL_SERVERFARMID_INVALID,						// ServerFarmID�� Invalid�Դϴ�.
	GAME_GM_TOOL_AGENTSERVER_NORUN,
	GAME_GM_TOOL_RANK_BATTLE_POINT_NOT_FOUND, // ��ũ ��Ʋ ������ ���� ĳ���� �Դϴ�.
	GAME_GM_TOOL_ACCOUNT_NOT_EXIST,							// �������� �ʴ� ���̵� �Դϴ�.

	//-----------------------------------------------------------------
	GAME_SKILL_SLOT_FAIL = 1000,
	GAME_SKILL_ID_NULL,
	GAME_SKILL_OWNER_NULL,
	GAME_SKILL_SAME_EXIST,
	GAME_SKILL_NOT_FOUND,
	GAME_ITEM_NOT_PROPER_PLACE_TO_USE,						// �������� ����ϱ⿡ ������ ��Ұ� �ƴմϴ�.
	GAME_ITEM_YOU_HAVE_NO_RELATED_QUEST_TO_USE,				// �����۰� ���õ� ����Ʈ�� ���� ���� �ʽ��ϴ�.
	//-----------------------------------------------------------------
	GAME_SHOP_NOT_FOUND = 1100,
	GAME_SHOP_SO_FAR,
	GAME_SHOP_NOT_CLOSED,					// ������ ���������Դϴ�.
	GAME_SHOP_ITEM_INVALID,					// �ȼ� ���� ������ �Դϴ�.
	//-----------------------------------------------------------------
	GAME_MOVE_CANT_GO_THERE = 1200,		// �� �� ���� ��ġ�Դϴ�
	GAME_WORLD_NOT_EXIST,				// �������� �ʴ� ���� �Դϴ�.
	GAME_MOVE_CANT_ALLOWED_ENTER,		// ������ ������ �ʽ��ϴ�.
	GAME_WORLD_CANT_MOVE_AGAIN,								// ���忡 ������ �� �� ���� �����Դϴ�.
	//-----------------------------------------------------------------
	GAME_PARTY_ALREADY_IN_PARTY = 1300,						// �̹� ��Ƽ�� ���� �ֽ��ϴ�.
	GAME_PARTY_ANOTHER_PLAYER_IS_INVITING_YOU,				// �ٸ� �÷��̾ �̹� ����� �ʴ��ϰ� �ֽ��ϴ�.
	GAME_PARTY_ANOTHER_PARTY_IS_INVITING_YOU,				// �ٸ� ��Ƽ�� �̹� ����� �ʴ��ϰ� �ֽ��ϴ�.
	GAME_PARTY_NOT_PROPER_PARTY_NAME_LENGTH,				// ��Ƽ �̸� ���̰� �������� �ʽ��ϴ�.
	GAME_PARTY_PARTY_NAME_HAS_INVALID_CHARACTER,			// ��Ƽ �̸��� ��� �Ұ����� ���ڰ� ���ԵǾ� �ֽ��ϴ�.
	GAME_PARTY_NOT_CREATED_FOR_SOME_REASON,					// �ý��� ������ ��Ƽ�� �������� �ʾҽ��ϴ�.
	GAME_PARTY_YOU_ARE_NOT_IN_PARTY,						// ��Ƽ�� ���� ���� �ʽ��ϴ�.
	GAME_PARTY_ONLY_ALLOWED_TO_PARTY_LEADER,				// ��Ƽ ������ ����� �� �ִ� ����Դϴ�.
	GAME_PARTY_NOT_AVAILABLE_OPERATION_RIGHT_NOW,			// ��Ƽ�� �����ϰ� �ִ� �۾��� ������ �����մϴ�.
	GAME_PARTY_NO_SUCH_A_PLAYER,							// �������� �ʴ� �÷��̾��Դϴ�.

	GAME_PARTY_TARGET_ALREADY_IN_PARTY,						// ������ �̹� ��Ƽ�� ���� �ֽ��ϴ�.
	GAME_PARTY_TARGET_ALREADY_HAS_INVITATION,				// ������ �̹� ��Ƽ �ʴ븦 ���� �����Դϴ�.
	GAME_PARTY_NO_ROOM_FOR_NEW_MEMBER,						// �� �̻� ����� ���� �� �����ϴ�.
	GAME_PARTY_MEMBER_IS_ALREADY_REGISTERED_TIMEQUEST,		// ������ Ÿ�Ӹӽ� ����Ʈ�� �̹� ��ϵǾ� �ֽ��ϴ�.
	GAME_PARTY_YOU_HAVE_NO_INVITATION,						// ����� ��Ƽ�κ��� �ʴ븦 ���� ���°� �ƴմϴ�.
	GAME_PARTY_INVITOR_PLAYER_IS_IN_A_PARTY,				// ����� �ʴ��ߴ� �÷��̾ ã�� �� �����ϴ�.
	GAME_PARTY_NO_SUCH_A_PARTY,								// ��Ƽ�� �����ϱ� �ʽ��ϴ�.
	GAME_PARTY_COULDNT_JOIN_FOR_SOME_REASON,				// �ý��� ������ ��Ƽ�� ������ �� �������ϴ�.
	GAME_PARTY_NO_SUCH_A_PLAYER_IN_THE_PARTY,				// ��Ƽ�� �������� �ʴ� �÷��̾��Դϴ�.
	GAME_PARTY_COULDNT_KICK_OUT_FOR_SOME_REASON,			// �ý��� ������ ����� ������ Ż���ų �� �������ϴ�.

	GAME_PARTY_CANT_KICK_OUT_HIMSELF,						// �ڱ� �ڽ��� ������ Ż���ų �� �����ϴ�.
	GAME_PARTY_YOU_ARE_ALREADY_A_LEADER,					// �̹� �ڽ��� ��Ƽ �����Դϴ�.
	GAME_PARTY_COULDNT_ASSIGN_A_LEADER_FOR_SOME_REASON,		// �ý��� ������ ����� ������ ������ �� �������ϴ�.
	GAME_PARTY_COULDNT_BE_DONE_FOR_SOME_REASON,				// �ý��� ������ ��û�� ó���� �� �������ϴ�.
	GAME_PARTY_WRONG_CHARM_INVENTORY_SPECIFIED,				// ���� �κ��丮�� �߸� �����Ǿ����ϴ�.
	GAME_PARTY_CHARM_INVENTORY_IS_OPEN,						// ���� �κ��丮�� ���� �ֽ��ϴ�.
	GAME_PARTY_CHARM_INVENTORY_IS_CLOSED,					// ���� �κ��丮�� ���� �ֽ��ϴ�.
	GAME_PARTY_CHARM_INVENTORY_SLOT_IS_NOT_EMPTY,			// ���� �κ��丮 ������ ��� ���� ���� �����Դϴ�.
	GAME_PARTY_CHARM_INVENTORY_SLOT_IS_EMPTY,				// ���� �κ��丮 ������ ��� �ִ� �����Դϴ�.
	GAME_PARTY_ZENNY_IS_LOCKED_RIGHT_NOW,					// ���� �κ��丮�� ���ϸ� ������ �� ���� �����Դϴ�.

	GAME_PARTY_NO_SUCH_A_VICTIM_ITEM,						// �������� �ʴ� ���� �������Դϴ�.
	GAME_PARTY_UNIDENTIFIED_VICTIM_ITEM,					// ���� �������� ������ ���� ���� �����Դϴ�.
	GAME_PARTY_THE_ITEM_IS_LOCKED,							// �������� ������ �� �����ϴ�.
	GAME_PARTY_VICTIM_ITEM_IS_NOT_YOURS,					// ����� ����� ���� �������� �ƴմϴ�.
	GAME_PARTY_CANT_UNREGISTER_CHARM_DUE_TO_VITIM,			// �̹� ����� ������ �־ ������ �ٽ� ������ �� �����ϴ�.
	GAME_PARTY_YOU_DONT_BELONG_TO_THE_PARTY,				// ����� ��Ƽ�� ���� ���� ���� �� �����ϴ�.
	GAME_PARTY_VICTIM_ZENNY_HASNT_CHANGED,					// ���� ������ ����� ������ ���� �ٲ��� �ʾҽ��ϴ�.
	GAME_PARTY_YOU_DONT_HAVE_THAT_MUCH_ZENNY,				// �׸�ŭ�� ���ϸ� ������ ���� �ʽ��ϴ�.
	GAME_PARTY_YOU_HAVENT_REGISTERED_VICTIM_ZENNY,			// ���ϸ� ���� ������ ����� ���� �����ϴ�.
	GAME_PARTY_TOO_MUCH_VICTIM_ZENNY_TO_UNREGISTER,			// ����� ������ �纸�� ���� ���� ���ϸ� ���������� �߽��ϴ�.

	GAME_PARTY_ONLY_LEADER_CAN_REGISTER_CHARM,				// ������ ��Ƽ ������ ����� �� �ֽ��ϴ�.
	GAME_PARTY_ONLY_CHARM_ITEM_AVAILABLE_IN_THAT_SLOT,		// ���� �����۸� ����� �� �ִ� �����Դϴ�.
	GAME_PARTY_SAME_CHARM_ALREADY_HAS_BEEN_REGISTERED,		// �̹� Ȱ��ȭ�Ǿ� �ִ� ���� �������Դϴ�.
	GAME_PARTY_ONLY_EQUIP_ITEM_AVAILABLE_IN_THAT_SLOT,		// ���� ������ �����۸� ����� �� �ִ� �����Դϴ�.
	GAME_PARTY_CHARM_ITEM_HASNT_BEEN_REGISTERED,			// ���� ������ ��ϵǾ� ���� �ʽ��ϴ�.
	GAME_PARTY_CHARM_SLOT_HAS_AN_ITEM_OF_IMPROPER_TYPE,		// ���� ���Կ� ������ �ƴ� �������� ��ϵǾ� �ֽ��ϴ�.
	GAME_PARTY_CHARM_SLOT_HAS_UNKNOWN_CHARM_ITEM,			// ���� ���Կ� �� �� ���� ������ ��ϵǾ� �ֽ��ϴ�.
	GAME_PARTY_ITEMS_DONT_SATISFY_THE_CONDITION,			// ���� �������� ������ ������ ������Ű�� �ʽ��ϴ�.
	GAME_PARTY_ZENNY_DOESNT_SATISFY_THE_CONDITION,			// ���ϰ� ������ ������ ������Ű�� �ʽ��ϴ�.
	GAME_PARTY_MEMBER_DOESNT_HAVE_ENOUGH_CHARM_POINT,		// ����� ���� ����Ʈ���� ���� ����Ʈ�� ���� ��Ƽ���� �ֽ��ϴ�.

	GAME_PARTY_MEMBER_DOESNT_HAVE_ENOUGH_ZENNY,				// ����� ���Ϻ��� ���� ���ϸ� ���� ��Ƽ���� �ֽ��ϴ�.
	GAME_PARTY_MEMBER_CHARM_POINT_IS_IN_TRANSACTION,		// ���� ����Ʈ�� ����� �� ���� ������ ��Ƽ���� �ֽ��ϴ�.
	GAME_PARTY_MEMBER_ZENNY_IS_IN_TRANSACTION,				// ���ϸ� ����� �� ���� ������ ��Ƽ���� �ֽ��ϴ�.
	GAME_PARTY_MEMBER_DOESNT_SATISFY_THE_CONDITION,			// ���� ��� ������ ������Ű�� ���� ��Ƽ���� �ֽ��ϴ�.
	GAME_PARTY_CHARM_BUFF_REGISTERED_ALREADY,				// �̹� ��ϵ� ���� ������ �ֽ��ϴ�.
	GAME_PARTY_NO_CHARM_BUFF_REGISTERED,					// ��ϵ� ���� ������ �����ϴ�.
	GAME_PARTY_UNKNOWN_ZENNY_LOOTING_METHOD,				// �߸��� ���� �й� ����Դϴ�.
	GAME_PARTY_UNKNOWN_ITEM_LOOTING_METHOD,					// �߸��� ������ �й� ����Դϴ�.
	GAME_PARTY_CANT_CHANGE_LOOTING_METHOD_YET,				// �ٽ� ����ǰ �й� ����� �ٲ� �� ���� ������ �ð��� �ʿ��մϴ�.
	GAME_PARTY_INVALID_INVENTORY_SLOT_INDEX,				// ��Ƽ �κ��丮�� ������ ��ġ�� �߸� �����Ǿ����ϴ�.

	GAME_PARTY_TOO_MANY_CONTRIBUTION_POINTS_TO_INVEST,		// ������ �� �ִ� �⿩���� ������ �Ѿ����ϴ�.
	GAME_PARTY_NOBODY_CANT_RECEIVE_ITEM_RIGHT_NOW,			// �������� ���� �� �ִ� ����� �ƹ��� �����ϴ�.
	GAME_PARTY_NO_EMPTY_SPACE_IN_INVENTORY,					// �κ��丮�� �� ������ �����ϴ�.
	GAME_PARTY_NO_EMPTY_SPACE_IN_PARTY_INVENTORY,			// ��Ƽ �κ��丮�� �� ������ �����ϴ�.
	GAME_PARTY_MEMBER_IS_TOO_FAR,							// ����� �ʹ� �ָ� ������ �ֽ��ϴ�. ����Ʈ ���� �Ҷ� ��� by niam
	GAME_PARTY_INVITING_IS_NOT_ALLOWED,						// �� ��Ƽ������ �ʴ밡 ������ �ʽ��ϴ�.
	GAME_PARTY_LEAVING_IS_NOT_ALLOWED,						// �� ��Ƽ������ Ż�� ������ �ʽ��ϴ�.
	GAME_PARTY_KICKING_OUT_IS_NOT_ALLOWED,					// �� ��Ƽ������ ���� Ż�� ������ �ʽ��ϴ�.
	GAME_PARTY_APPOINTING_A_LEADER_IS_NOT_ALLOWED,			// �� ��Ƽ������ ��Ƽ�� �Ӹ��� ������ �ʽ��ϴ�.
	GAME_PARTY_SHARETARGET_NOTFINDOBJECT,					// �ش� ������Ʈ�� �����ϴ� [3/28/2008 SGpro]

	GAME_PARTY_SHARETARGET_SLOTID_FAIL,						// ����Ÿ�� ����ID�� �߸��Ǿ����ϴ�[3/28/2008 SGpro]
	GAME_PARTY_ONLY_EQUIP_ITEM_ALLOWED_FOR_CHARM_POINT,		// ���� ���������θ� ���� ����Ʈ�� ���� �� �ֽ��ϴ�.
	GAME_PARTY_IDENTIFIED_ITEM_NEEDED_FOR_CHARM_POINT,		// ������ ���������θ� ���� ����Ʈ�� ���� �� �ֽ��ϴ�.
	GAME_PARTY_DUNGEON_IN_PLAYER_FOUND,						// 1372 // ������ ���� �����ִ� ĳ���Ͱ� �ֽ��ϴ�. 
	GAME_PARTY_DICE_FAIL,									// ��Ƽ �ֻ��� ��� ����
	GAME_PARTY_INVEN_ITEM_EXIST,							// ��Ƽ�κ��� �������� �����ֽ��ϴ�.
	GAME_PARTY_INVEN_INVEST_ZENNY_NOT_ENOUGH,				// ��Ƽ�κ��� ������ ���� �����մϴ�.
	GAME_PARTY_INVEN_LOCKED,								// ��Ƽ�κ��� �����ϴ�.
	GAME_PARTY_ITEM_DICE_USING_NOW,							// ��Ƽ ������ ���̽��� ������Դϴ�.
	GAME_PARTY_INVEN_ITEM_NON_EXIST,						// ��Ƽ�κ� �ش� ���Կ� ������ �����ϴ�.

	GAME_PARTY_ITEM_DICE_NOT_USING_NOW,						// ��Ƽ ������ ���̽��� �� ������Դϴ�.
	GAME_PARTY_DUNGEON_MIN_PLAYER_FAIL,						// ��Ƽ ������ �ּ��ο��� �����մϴ�.
	GAME_PARTY_DUNGEON_OUT_RESERVED,						// ��Ƽ ���� ������ ���� NTL_MIN_DUNGEON_PARTYOUT_TIME ���ҽ��ϴ�..(���ǵ� ���� �ٲ�� �ݵ�� ��ȹ�� GUI ����ڿ��� �˷� �ּ���)
	GAME_PARTY_INVEN_DISTRIBUTE_METHOD_NOT_MATCH,			// �й����� ���� �ʽ��ϴ�.
	GAME_PARTY_MEMBER_ZENNY_IS_LOCK,						// ��Ƽ ����� ���ϰ� ��� ���°� �ֽ��ϴ�.
	GAME_PARTY_MEMBER_NOT_SAME,								// ��Ƽ�κ��� ����� �ٸ��ϴ�.
	GAME_PARTY_INVEN_LOCK_FIRST,							// ��Ƽ�κ��� �����ֽ��ϴ�. ���� �ݾ��ֽʽÿ�.
	GAME_PARTY_INVEN_UNDER_INVEST,							// ��Ƽ�κ��� ���ڵ� �ִ�ݾ� ���� ���ƾ��մϴ�.
	GAME_PARTY_DUNGEON_ENTER_PARTY_FAIL,					// ��Ƽ������ ���÷��� ��Ƽ�� �����Ͻʽÿ�.
	GAME_PARTY_DUNGEON_IN_CHANGE_DIFF_NOW,					// ��Ƽ�����ȿ��� ���̵� ������ �Ұ����մϴ�.

	GAME_PARTY_CANT_INVITE_YOURSELF,						// �ڱ� �ڽ��� ��Ƽ�� �ʴ��� �� �����ϴ�.
	//-----------------------------------------------------------------
	GAME_HTB_NO_HTB_RESULT = 1400,							// ������ HTB�� �����ϴ�
	GAME_HTB_CANT_FORWARD_ANYMORE,							// ���̻� ������ HTB�ܰ谡 �����ϴ�.
	GAME_HTB_NOT_ENOUGH_RP_BALL,							// RP ������ ������� �ʽ��ϴ�.
	GAME_HTB_YOU_ALREADY_USED_RP_BALL,						// �̹� RP ������ ����� �����Դϴ�.
	GAME_HTB_YOU_HAVE_NO_RELATION_WITH_HTB,					// 1404 // HTB�� ���� ���� �����Դϴ�.

	GAME_WORLD_ENTER_NEED_LOW_LEVEL, // �ش� ������ �����ϱ⿡�� ���� �����Դϴ�.
	GAME_WORLD_ENTER_NEED_HIGH_LEVEL, // �ش� ������ �����ϱ⿡�� ���� �����Դϴ�.
	GAME_WORLD_ENTER_NEED_ITEM, // �ش� ������ �����ϱ����� �ʿ�  �������� �����ϴ�.

	GAME_FREEBATTLE_TARGET_HAS_NO_MATCH, // ����� ������ ������ �� �����ϴ�.
	GAME_FREEBATTLE_WRONG_PLACE, // ������ �� �� ���� �����Դϴ�.
	GAME_FREEBATTLE_ALREADY_HAS_MATCH, // �̹� �������Դϴ�.
	GAME_FREEBATTLE_TARGET_ALREADY_HAS_MATCH, // �̹� �������� ����Դϴ�.
	GAME_FREEBATTLE_CHALLENGE_TIME_REMAIN, // ���� ���� ��� �ð��Դϴ�.
	GAME_FREEBATTLE_CHALLENGE_ACCEPT_DENIED, // ���� ��û�� �������߽��ϴ�.
	GAME_FREEBATTLE_CHALLENGE_ACCEPT_TIME_DENIED, // ���� ��û�� ������ ���� �ʾ� �ڵ����� �����Ǿ����ϴ�.
	GAME_FREEBATTLE_CHALLENGE_WAIT_TIME_DENIED, // ���� ��û�� ���� ������ ���� �ڵ����� �����Ǿ����ϴ�.
	GAME_FREEBATTLE_ERROR_HAS_NO_MATCH, // ����(�����ڵ�) - ������ ������ �� �����ϴ�.
	GAME_FREEBATTLE_ERROR_TARGET_HAS_NO_MATCH, // ����(�����ڵ�)  - ����� ������ ������ �� �����ϴ�.
	GAME_FREEBATTLE_ERROR_WRONG_PEER, // ����(�����ڵ�) - �߸��� ���� ����� ������ �ֽ��ϴ�.
	GAME_FREEBATTLE_ERROR_TARGET_WRONG_PEER, // ����(�����ڵ�) - ����� �߸��� ���� ����� ������ �ֽ��ϴ�.
	//-----------------------------------------------------------------
	GAME_WORLD_ENTER_NEED_REPUTATION, // �ش� ������ �����ϱ����� �ʿ� ���� �����ϴ�.
	GAME_WORLD_NOT_FOUND,			  // �ش� ������ ã�� �� �����ϴ�.

	GAME_WORLD_ENTER_DISAPPROVAL,	 // �ش� ������ ������ �� �����ϴ�.

	GAME_SCOUTER_TARGET_SELF_FAIL,	 // �ڱ� �ڽ��� ������� �Ұ����մϴ�.

	//////////////////////////////////////////////////////////////////////////
	//
	// Trigger system ���� �޽�����
	//
	//////////////////////////////////////////////////////////////////////////

	GAME_TS_WARNING_BEGIN = 1500,						// Trigger warning message ����

	GAME_TS_WARNING_NOT_SATISFY_REWARD_CONDITIONS = 1500,	// ���� ���� �� �ִ� ������ �������� ���մϴ�.
	GAME_TS_WARNING_MUST_SELECT_ONE_SEL_REWARD,		// ���� ������ �����մϴ�. �ݵ�� �ϳ��� ���ú����� �����ؾ� �մϴ�.
	GAME_TS_WARNING_PROCESSING_PRE_CONFIRM_REQ,		// ���� ���� ��û�� ó�����Դϴ�. (����)
	GAME_TS_WARNING_NOW_TIME_WAIT,					// ���� ���� ��û�� ó�����Դϴ�. (�ð�)
	GAME_TS_WARNING_OVERFLOW_MAX_TS_NUM,			// ���డ���� �ִ� Ʈ���� ������ �Ѿ����ϴ�.

	GAME_TS_WARNING_SYSTEM_WAIT,					// �ٸ� �ý��۰� �浹�� �Ͼ ���. ��� ��ٷ� �ּ���.
	GAME_TS_WARNING_INVENTORY_IS_LOCK,				// ������ �κ��丮�� lock�� �ɷ� ����
	GAME_TS_WARNING_INVENTORY_IS_FULL,				// ������ �κ��丮�� ����á��
	GAME_TS_WARNING_QUEST_INVENTORY_IS_FULL,		// ����Ʈ �κ��丮�� ���� á��
	GAME_TS_WARNING_INVALID_QUEST_ITEM_DELETE_COUNT,// ����Ʈ �������� ���� ��û ������ Ʋ��
	GAME_TS_WARNING_REWARD_FAIL,					// ������ ���� ����(�Ƹ� �� �޽����� ������ ��������)
	GAME_TS_WARNING_EQUIP_SLOT_NOT_EMPTY,			// ��� ������ ������� �ʽ��ϴ�.
	GAME_TS_WARNING_EQUIP_SLOT_LOCK,				// ��� ������ ����ֽ��ϴ�.
	GAME_TS_WARNING_CLASS_CHANGE_CLASS_FAIL,		// ���� Ŭ������ �ٸ�
	GAME_TS_WARNING_CLASS_CHANGE_LEVEL_FAIL,		// ���� ������ �ȵ�
	GAME_TS_WARNING_NOT_YET_PROCESSED,				// ó������ �ʾ���
	GAME_TS_WARNING_ROLLBACK,						// ���� ó�� �Ͽ����� �ѹ��Ŵ
	GAME_TS_WARNING_ROLLBACK_FAIL,					// �ѹ��� ������
	GAME_TS_WARNING_ESCORT_EXCEED_MEMBER,			// ��� �ʰ�
	GAME_TS_WARNING_ESCORT_NOT_SHARED,				// ���� ��尡 �ƴ�
	GAME_TS_WARNING_ESCORT_TRIGGER_TYPE_WRONG,		// Ʈ���� Ÿ���� �ٸ�
	GAME_TS_WARNING_ESCORT_TRIGGER_ID_WRONG,		// Ʈ���� ���̵� �ٸ�
	GAME_TS_WARNING_ESCORT_PARTY_WRONG,				// ��Ƽ�� �ٸ�
	GAME_TS_WARNING_ESCORT_ALREADY_EXIST,			// �̹� ��ϵǾ� ����
	GAME_TS_WARNING_TMQ_COUPON_NOT_ENOUGH,			// TMQ���� ������ ������

	GAME_TS_WARNING_WPS_ALREDY_USED_BY_OTHER_PLAYER,// �̹� �ٸ� ������ �������Դϴ�.
	GAME_TS_WARNING_WPS_CAN_NOT_JOIN_NOW,			// ������ ���� �� �� �����ϴ�.

	GAME_TS_WARNING_CAN_NOT_FIND_VISIT_EVT,			// ���õ� �湮 �̺�Ʈ�� �����ϴ�. for visit event
	GAME_TS_WARNING_ALREADY_VISITED,				// �̹� �Ϸ��߽��ϴ�. for visit event
	GAME_TS_WARNING_WRONG_CONDITION,				// ���� ������ ���� �ʽ��ϴ�.
	GAME_TS_WARNING_CANNOT_FIND_QUEST_ITEM,			// ����Ʈ �������� ã�� �� �����ϴ�.
	GAME_TS_WARNING_DEL_FORBIDDENDEL_QUEST_ITEM,	// ����� ���� ����Ʈ �������Դϴ�.
	//-----------------------------------------------------------------
	GAME_TS_WARNING_END = 1700,							// Trigger warning message ����

	GAME_TS_ERROR_BEGIN = 1700,							// Trigger error message ����

	GAME_TS_ERROR_RUN_ERROR = 1700,	// Ʈ���� ���� ����
	GAME_TS_ERROR_CS_SCRIPT_MISSMATCH,				// ������ �����ؾ��� �����̳� Ÿ���� CS ���� ��ġ���� �ʽ��ϴ�.
	GAME_TS_ERROR_NO_IMP_CONT_TYPE,					// �������� ���� �����̳� Ÿ���� ���Ǿ����ϴ�.
	GAME_TS_ERROR_CANNOT_CREATE_TS_OBJECT,			// Ʈ���� ������Ʈ ���� ����.
	GAME_TS_ERROR_CANNOT_FIND_TID,					// Ʈ���Ÿ� ã�� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_FIND_TCID,					// �����̳ʸ� ã�� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_PROGRESS_REPEAT_QUEST,		// �ݺ� ����Ʈ�� ������ �ѹ��� ������ �� �ֽ��ϴ�


	GAME_TS_ERROR_SYSTEM,							// �Ϲ����� �ý��ۻ��� ����[����]
	GAME_TS_ERROR_TRIGGER_SYSTEM,					// Trigger System ���� ������ �� ���
	GAME_TS_ERROR_QUERY_SERVER,						// ���� ���� ����
	GAME_TS_ERROR_CANNOT_FIND_ITEM_HOBJECT,			// ���̺��� �������� ã���� ����
	GAME_TS_ERROR_CANNOT_FIND_SKILL_HOBJECT,			// ��ų�� ã�� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_LEARN_SKILL,				// ��ų�� ��� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_ADD_QUEST_EVENT_DATA,		// �̺�Ʈ �������� �̺�Ʈ�� ����� �� �����ϴ�.
	GAME_TS_ERROR_CANNOT_FIND_QUEST_ITEM,			// ����Ʈ �������� ã�� �� �����ϴ�.
	GAME_TS_ERROR_CREATE_ITEM_COUNT_OVER,			// �ѹ��� ������ �� �ִ� ���� ������ �Ѿ���.
	GAME_TS_ERROR_DELETE_ITEM_COUNT_OVER,			// �ѹ��� ������ �� �ִ� ���� ������ �Ѿ���
	GAME_TS_ERROR_CANNOT_FIND_PC,					// PC�� ã�� �� ����
	GAME_TS_ERROR_TRIGGER_OBJECT_NOT_EXIST,			// �������� �ʴ� Ʈ���� ������Ʈ �Դϴ�.
	GAME_TS_ERROR_TRIGGER_OBJECT_INVALID_FUNCFLAG,	// ����� �ùٸ��� ���� Ʈ���� ������Ʈ�Դϴ�.
	//-----------------------------------------------------------------
	GAME_TS_ERROR_END = 1900,							// Trigger error message ����
	//-----------------------------------------------------------------
	GAME_PET_CANT_MAKE_MORE_SUMMON_PET = 2000,			// �� �̻� ��ȯ���� �θ� �� �����ϴ�.
	GAME_PET_CANT_MAKE_MORE_ITEM_PET,					 // �� �̻� ������ ���� �θ� �� �����ϴ�.
	GAME_PET_COULDNT_BE_DONE_FOR_SOME_REASON,			// �ý��� ������ ��û�� ó���� �� �����ϴ�.
	GAME_PET_TARGET_IS_NOT_SPAWNED,						// ����� ��ȯ�Ǿ� ���� �ʽ��ϴ�.
	//-----------------------------------------------------------------
	GAME_GUILD_NO_GUILD_MANAGER_NPC_FOUND = 2100,			// ��� �Ŵ��� NPC�� ã�� �� �����ϴ�.
	GAME_GUILD_NOT_GUILD_MANAGER_NPC,						// ��� �Ŵ��� NPC�� �ƴմϴ�.
	GAME_GUILD_GUILD_MANAGER_IS_TOO_FAR,					// ������ ��� �Ŵ����� �ʹ� �־� ��ȭ�� �� �� �����ϴ�.
	GAME_GUILD_NEED_MORE_ZENNY_FOR_NEW_GUILD,				// ��� ������ ���ؼ��� ���ϰ� �� �ʿ��մϴ�.
	GAME_GUILD_NOT_PROPER_GUILD_NAME_LENGTH,				// ��� �̸� ���̰� �������� �ʽ��ϴ�.
	GAME_GUILD_GUILD_NAME_HAS_INVALID_CHARACTER,			// ��� �̸��� ��� �Ұ����� ���ڰ� ���ԵǾ� �ֽ��ϴ�.
	GAME_GUILD_NOT_PROPER_GUILD_NAME,						// ��� �̸��� �������� �ʽ��ϴ�.
	GAME_GUILD_SAME_GUILD_NAME_EXIST,						// ���� ��� �̸��� �����մϴ�.
	GAME_GUILD_NOT_EXIST,									// �ش� ��尡 �������� �ʽ��ϴ�.
	GAME_GUILD_NON_EXISTING_GUILD_FUNCTION,					// �� �� ���� ��� ����Դϴ�.

	GAME_GUILD_ALREADY_HAS_GUILD_FUNCTION,					// �̹� ������ �ִ� ��� ����Դϴ�.
	GAME_GUILD_NEED_PREREQUISITE_GUILD_FUNCTION,			// �� �ܰ� ���� ��� ����� ȹ���� ���¿��� �մϴ�.
	GAME_GUILD_NEED_MORE_GUILD_POINT,						// �� ���� ��� ����Ʈ�� �ʿ��մϴ�.
	GAME_GUILD_NEED_MORE_ZENNY,								// �� ���� ���ϰ� �ʿ��մϴ�.
	GAME_GUILD_NEED_LEVEL_MORE,								// ������ �����մϴ�.
	GAME_GUILD_GIVE_ZENNY_NOT_MATCHED,						// ��� ����Ʈ�� ������ؼ��� 1000���� ������ �������� 1000 �̻��̿��� �մϴ�.
	GAME_GUILD_NO_GUILD_FOUND,								// ��忡 ���ԵǾ� ���� �ʽ��ϴ�.
	GAME_GUILD_MARK_ARLEADY_CREATED,						// ��帶ũ�� �̹� ���� �Ǿ� �ֽ��ϴ�.
	GAME_GUILD_MARK_NOT_CREATED,							// ��帶ũ�� ���� �Ǿ� ���� �ʽ��ϴ�.
	GAME_GUILD_NEED_DOJO_NOT_FOUND,							// ������ ã�� �� �����ϴ�.

	GAME_GUILD_MAKE_DOJO_ALREADY_TAKEN,						// �̹� ���İ� ������ �����ϰ� �־� ������ ������ �� �����ϴ�.
	GAME_GUILD_NEED_GUILD_FUNCTION,							// ����� ����� �����ϴ�. ���ȹ���� �����Ͻʽÿ�.
	GAME_GUILD_NO_DOJO_MANAGER_NPC_FOUND,					// ���� �Ŵ��� NPC�� ã�� �� �����ϴ�.
	GAME_GUILD_NOT_DOJO_MANAGER_NPC,						// ���� �Ŵ��� NPC�� �ƴմϴ�.
	GAME_GUILD_DOJO_MANAGER_IS_TOO_FAR,						// ������ ���� �Ŵ����� �ʹ� �־� ��ȭ�� �� �� �����ϴ�.
	GAME_GUILD_NON_EXISTING_DOJO_FUNCTION,					// �� �� ���� ���� ����Դϴ�.
	GAME_GUILD_MAKE_DOJO_NOT_TAKEN,							// ������ ������ �����ϴ�.
	GAME_GUILD_DOGI_NOT_CREATED,							// ���� ���� �Ǿ� ���� �ʽ��ϴ�.
	GAME_GUILD_DOGI_ARLEADY_CREATED,						// ������ �̹� ���� �Ǿ� �ֽ��ϴ�.
	GAME_GUILD_ALREADY_HAS_DOJO_FUNCTION,					// �̹� ������ �ִ� ���� ����Դϴ�.

	GAME_GUILD_NEED_PREREQUISITE_DOJO_FUNCTION,				// �� �ܰ� ���� ���� ����� ȹ���� ���¿��� �մϴ�.
	GAME_GUILD_HOIPOIROCK_ITEM_NOT_FOUND,					// ȣ�����̶� �������� ã�� ���߽��ϴ�.
	GAME_GUILD_HOIPOIROCK_ITEM_NOT_MATCHED,					// ȣ�����̶� �������� �ƴմϴ�.
	GAME_GUILD_HOIPOIROCK_ITEM_COUNT_FAIL,					// ȣ�����̶� ������ ������ �����մϴ�.
	GAME_GUILD_DOJO_SCRAMBLE_CHALLENGE_HAVE,				// ���� ��Ż ��û��尡 �̹� �ֽ��ϴ�.
	GAME_GUILD_DOJO_YOU_ARE_NOT_A_PARTY_LEADER,				// ������ ������ ���� �ְ������� �����մϴ�.
	GAME_GUILD_DOJO_YOU_ARE_NOT_OWNNER,						// ������ ������ �ƴմϴ�.
	GAME_GUILD_DOJO_SCRAMBLE_CHALLENGE_STATUS_FAIL,			// ������Ż�� ��û���� ���°� �ƴմϴ�. 
	GAME_GUILD_DOJO_SCRAMBLE_CHALLENGE_HAVE_DOJO,			// ������ ������ ���Ĵ� ��Ż���� ��û�� �� �����ϴ�.
	GAME_GUILD_DOJO_SCRAMBLE_REJECT_STATUS_FAIL,			// ������Ż�� ��û�źΰ��� ���°� �ƴմϴ�. 

	GAME_GUILD_DOJO_NOT_FOUND_TABLE,						// �������̺��� ã���� �����ϴ�. 
	GAME_GUILD_DOJO_NEED_FUNCTION,							// ���弳�� ������ �����ϴ�. ����ȹ���� �����Ͻʽÿ�.
	GAME_GUILD_DOJO_SCRAMBLE_MAX_COUNT_OVER,				// ������Ż���� ���� �ִ� �ο� ���� �ʰ� �߽��ϴ�.	
	GAME_GUILD_DOJO_NOT_FOUND,								// �ش� ������ ã�� �� �����ϴ�.	
	GAME_GUILD_DOJO_SELF_SCRAMBLE_FAIL,						// �ڽ��� ���� ���忡 ��Ż���� ��û�Ҽ� �����ϴ�.	
	GAME_GUILD_DOJO_SCRAMBLE_NOT_A_PARTY_LEADER,			// ��Ż���� ��û�� �ְ����� �� �� �ֽ��ϴ�.
	GAME_GUILD_DOJO_YOU_ARE_NOT_ENOUGH_REPUTATION,			// ��Ż���� ��û�ϱ⿡�� ���� ����Ʈ�� ������� �ʽ��ϴ�. 
	GAME_GUILD_DOJO_YOU_ARE_NOT_ENOUGH_ZENNY,				// ��Ż���� ��û�ϱ⿡�� ������ ���ϰ� �����մϴ�. 
	GAME_GUILD_DOJO_YOU_ARE_ARLREADY_REJECT,				// ��Ż���� �źδ��� ��û�� �� ���� �����Դϴ�. ���� ��û�Ⱓ�� �����մϴ�. 
	GAME_GUILD_DOJO_YOU_DONT_BELONG_TO_ANY_DOJO,			// ���忡 ���� ���� �ʽ��ϴ�.

	GAME_GUILD_DOJO_YOU_DONT_BELONG_TO_THAT_DOJO,			// �ش� ���忡 ���� ���� �ʽ��ϴ�.
	GAME_GUILD_DOJO_YOU_ARE_ARLREADY_REJECT_ONE_TIME,		// ��Ż�� �źδ� �ѹ��� �����մϴ�.
	GAME_GUILD_DOJO_YOU_CANT_ATTACK_YOUR_TEAM_SEAL,			// �ڽ��� ���� ���� ������ ������ �� �����ϴ�.
	GAME_GUILD_DOJO_SEAL_CANT_BE_ATTACKED,					// ������ ������ ������ �� �����ϴ�.
	GAME_GUILD_DOJO_TOO_MANY_ATTACKER_ON_SEAL,				// �̹� ���� �÷��̾ ������ �����ϰ� �ֽ��ϴ�.
	GAME_GUILD_YOUR_GUILD_CANT_DO_DOJO_TELEPORT,			// 2155 // �ڷ����� ����� ����� �� ���� ���Ŀ� ���� �ֽ��ϴ�.
	GAME_GUILD_DOJO_FUNCTION_ADD_FIRST,						// ������ ����� ���� �����Ͻ� �� ����� �ּ���. 
	//-----------------------------------------------------------------
	GAME_ROOM_ENTER_EXCEED_MAX_MEMBER_COUNT = 2200,			// �濡 �ο��� ���� á���ϴ�.
	GAME_ROOM_ENTER_EXCEED_MAX_ROOM_COUNT,					// ���̻� ���� ���� �� �����ϴ�.
	GAME_ROOM_ENTER_NEED_MORE_MEMBER,						// �濡 �ο��� �� �ʿ� �մϴ�.
	GAME_ROOM_ENTER_TOO_LOW_LEVEL,							// �濡 �����ϱ⿡�� ������ �ʹ� �����ϴ�
	GAME_ROOM_ENTER_TOO_HIGHTLEVEL,							// �濡 �����ϱ⿡�� ������ �ʹ� �����ϴ�
	GAME_ROOM_ENTER_MUST_HAVE_NEED_ITEM,					// �濡 �����ϱ����� �ʿ� �������� �����ϴ�
	GAME_ROOM_ENTER_MUST_HAVE_NEED_ZENNY,					// �濡 �����ϱ����� ���ϰ� �����մϴ�.
	GAME_ROOM_ENTER_ROOM_NOT_EXIST,							// ���� �������� �ʽ��ϴ�.
	GAME_ROOM_ENTER_ROOMMANAGER_NOT_EXIST,					// �Խ����� �������� �ʽ��ϴ�.
	GAME_ROOM_ENTER_NEED_MORE_PARTY_MEMEBER,				// ��Ƽ����� �� �ʿ��մϴ�.
	GAME_ROOM_ENTER_NOT_MATCH_MEMBER,						// ���� ����� �ƴմϴ�.
	GAME_ROOM_ENTER_NOT_WAIT_STATE,							// ��� ���°� �ƴմϴ�.
	GAME_ROOM_ENTER_FAIL,									// ������ �õ��� �����Ͽ����ϴ�
	GAME_ROOM_LEAVE_LIMIT_TIME_ELAPSED,						// ���뿡�� ������ ���� �ð� �Դϴ�
	GAME_ROOM_LEAVE_FAIL,									// ���� ������ ����
	GAME_ROOM_NOT_OWNER,									// ���� �����ڰ� �ƴմϴ�.
	GAME_ROOM_CAN_NOT_FIND_PARTY_MEMBER,					// ��Ƽ����� ã�� �� �����ϴ�.

	GAME_RANKBATTLE_NOR_REGISTERED,							// ��ϵǾ� ���� �ʽ��ϴ�.
	GAME_RANKBATTLE_CANNOT_LEAVE_NOW,						// ��� �� �� �����ϴ�.
	GAME_RANKBATTLE_CANNOT_LEAVE_IN_MATCH,					// ����߿��� ����� �� �����ϴ�.
	GAME_RANKBATTLE_CANNOT_FIND_ARENA,						// ������� ã�� �� �����ϴ�.
	GAME_RANKBATTLE_CANNOT_FIND_OPPONENT,					// ��븦 ã�� �� �����ϴ�.
	GAME_RANKBATTLE_MEMBER_ALREADY_JOINED_RANKBATTLE,		// ��Ƽ���� �̹� ��ũ��Ʋ ���Դϴ�.
	GAME_RANKBATTLE_ARENA_IS_FULL,							// ����ִ� ������� �����ϴ�.
	GAME_RANKBATTLE_OBJECT_IS_TOO_FAR,						// �ʹ� �ָ� ������ �ֽ��ϴ�.

	GAME_MATCH_CAN_NOT_USE_SKILL_IN_THIS_WORLD,				// ���� ���忡���� ����� �� ���� ��ų�Դϴ�.
	GAME_MATCH_CAN_NOT_USE_SKILL_IN_OUTOFAREA,				// ����϶��� ��ų�� ����� �� �����ϴ�.
	GAME_TIMEQUEST_CANNOT_LEAVE_IN_PARTY_WHEN_PLAYING_RANKBATTLE,	// ��ũ��Ʋ ���϶����� ��Ƽ���� ���� �� �����ϴ�.


	//-----------------------------------------------------------------
	GAME_TIMEQUEST_WORLD_NOT_FOUND = 2300,					// Ÿ�Ӹӽ� ����Ʈ�� �ش��ϴ� ���带 ã�� �� �����ϴ�
	GAME_TIMEQUEST_ROOM_NOT_FOUND,							// Ÿ�Ӹӽ� ����Ʈ ������ ã�� �� �����ϴ�
	GAME_TIMEQUEST_ALREADY_JOINED,							// Ÿ�Ӹӽ� ����Ʈ ���ǿ� �̹� �����ϰ� �ֽ��ϴ�
	GAME_TIMEQUEST_HAVE_NO_JOIN_ROOM,						// Ÿ�Ӹӽ� ����Ʈ ���ǿ� �����ϰ� ���� �ʽ��ϴ�
	GAME_TIMEQUEST_CANT_MAKE_PARTY,							// Ÿ�Ӹӽ� ����Ʈ�� �ڵ� ��Ƽ�� ������ �� �����ϴ�.
	GAME_TIMEQUEST_NEED_MORE_MEMBER,						// Ÿ�Ӹӽ� ����Ʈ�� �� �ο��� ������� �ʽ��ϴ�
	GAME_TIMEQUEST_NOT_ALLOWED_MEMBER,						// Ÿ�Ӹӽ� ����Ʈ�� ������ �㰡���� ���� ��� �Դϴ�.
	GAME_TIMEQUEST_EXCEED_MAX_MEMBER_COUNT,					// Ÿ�Ӹӽ� ����Ʈ �����ִ� �ο��� �ʰ��Ǿ����ϴ�.
	GAME_TIMEQUEST_TOO_LOW_LEVEL,							// Ÿ�Ӹӽ� ����Ʈ�� �ϱ����� ������ �ʹ� �����ϴ�.
	GAME_TIMEQUEST_TOO_HIGH_LEVEL,							// Ÿ�Ӹӽ� ����Ʈ�� �ϱ����� ������ �ʹ� �����ϴ�.
	GAME_TIMEQUEST_MUST_HAVE_NEED_ITEM,						// Ÿ�Ӹӽ� ����Ʈ�� �����ϱ����� �������� �����ϴ�
	GAME_TIMEQUEST_MUST_HAVE_NEED_ZENNY,					// Ÿ�Ӹӽ� ����Ʈ�� �����ϱ����� ���ϰ� �����մϴ�.
	GAME_TIMEQUEST_ROOM_NOT_WAIT_STATE,						// Ÿ�Ӹӽ� ����Ʈ ���ǿ� ������ �� �����ϴ�.
	GAME_TIMEQUEST_ROOM_PARTY_JOIN_FAIL,					// Ÿ�Ӹӽ� ����Ʈ ���ǿ� ��Ƽ����� �� �� �����ϴ�.
	GAME_TIMEQUEST_ROOM_PARTY_ALREADY_JOINED,				// Ÿ�Ӹӽ� ����Ʈ ���ǿ� �̹� ��Ƽ����� �Ǿ� �ֽ��ϴ�.
	GAME_TIMEQUEST_ROOM_OUT_OF_ENTER_RANGE,					// Ÿ�Ӹӽ� ����Ʈ�� ���� ������ ������ϴ�.
	GAME_TIMEQUEST_ROOM_CANNOT_TELEPORT_NOW,				// ������ Ÿ�Ӹӽ��� ��ġ�� �̵��� �� �����ϴ�.
	GAME_TIMEQUEST_DAYRECORD_IS_ALREADY_RESET,				// ���̷��ڵ� ������ �̹� ó���Ǿ����ϴ�.
	GAME_TIMEQUEST_WORLD_ENTER_FAIL,						// Ÿ�Ӹӽ� ����Ʈ ������ �����Ͽ����ϴ�.
	GAME_TIMEQUEST_CANNOT_LEAVE_IN_PARTY_WHEN_PLAYING_TMQ,	// Ÿ�Ӹӽ� ����Ʈ�� ���� �� ������ ��Ƽ���� ���� �� �����ϴ�.

	//-----------------------------------------------------------------
	GAME_TUTORIAL_CHAR_ALREADY_TUTORIAL_ACCOMPLISHED = 2350, // ĳ���Ͱ� �̹� Ʃ�丮���� �����߽��ϴ�
	GAME_TUTORIAL_CANT_FIND_TUTORIAL_WAIT_ROOM,				// Ʃ�丮�� ������ ���� ���� �ʽ��ϴ�
	GAME_TUTORIAL_CANT_ENTER_TUTORIAL_WAIT_ROOM,			// Ʃ�丮�� ���뿡 ������ �� �����ϴ�
	GAME_TUTORIAL_YOU_HAVE_NO_JOIN_ROOM,					// Ʃ�丮�� ��⸦ �ϰ� ���� �ʽ��ϴ�.


	//-----------------------------------------------------------------
	GAME_PRIVATESHOP = 2400,
	GAME_PRIVATESHOP_NOTAUTH,												// ������ �����ϴ�
	GAME_PRIVATESHOP_NOTRUNSTATE,											// ���� ���¿����� ���� �� �� �����ϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_NOT_CREATE_PLACE,							// ���� ������ ���� ���� ��� �Դϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_ANOTHER_PRIVATESHOP,						// ��ó�� �ٸ� ���λ����� �־ ���λ����� �� �� �����ϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_NULL,										// ������ �����ϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_INVENTORY_SAVEITEM_OVER,					// ���� �κ��丮�� �󽽷��� �����ϴ�
	GAME_PRIVATESHOP_PRIVATESHOP_INVENTORY_SLOT_ALREADY_ITEM,				// ���� �κ��丮 ���Կ� �̹� �������� �ֽ��ϴ�
	GAME_PRIVATESHOP_ITEM_NULL,												// �������� �����ϴ�
	GAME_PRIVATESHOP_ITEM_NOTVALID,											// �ȼ� ���� �������Դϴ�
	GAME_PRIVATESHOP_VISITOR_NULL,											// �մ��� �����ϴ�
	GAME_PRIVATESHOP_VISITOR_NOT_MONEY,										// �մԿ� ���� ���ڸ��ϴ�
	GAME_PRIVATESHOP_VISITOR_NOT_INVENTORY_EMPTY,							// �մԿ� �κ��丮 ���Կ� �����۵��� �� �� �ֽ��ϴ�
	GAME_PRIVATESHOP_VISITOR_ALREADYENTER,									// �մ��� �̹� ������ �����߽��ϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_NULL,								// �մ��� ���� �������� �����ϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_OVER,								// ���̻� �������� ���� �� �����ϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_ALREADY,							// �̹� ���� �������Դϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_ALLSELL,							// ������ �����۵��� ��� �����ϴ�
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_INVENSOLT_SHORTOF,					// �κ��丮�� �� ������ �����մϴ�
	GAME_PRIVATESHOP_VISITOR_FULL,											// ������ �մ��� �� �� �ִ� ���ڸ��� �����ϴ�
	GAME_PRIVATESHOP_OWNER_MONEY_FULL,										// ���� ���� ���� ���̻� �þ�� �����ϴ�
	GAME_PRIVATESHOP_OWNER_THEREISNO,										// ���� ������ �ڸ��� �����ϴ�
	GAME_PRIVATESHOP_OWNER_BUSINESS_REFUSED,								// ������ ������ �ź����̴�
	GAME_PRIVATESHOP_INVENTORY_NOTINVENTTORY,								// �߸��� �κ��丮 �Դϴ�
	GAME_PRIVATESHOP_INVENTORY_SAVEITEM_OVER,								// Inventory�� �� ������ �����ϴ�
	GAME_PRIVATESHOP_STOP_PROGRESS,											// �������Դϴ�
	GAME_PRIVATESHOP_OWNER_BARGAINS,										// ������ �ٸ������ �������Դϴ�
	GAME_PRIVATESHOP_ITEM_TABLE_ITEMID_DIFFERENT,							// �������� �������� �ʽ��ϴ�
	GAME_PRIVATESHOP_ITEM_SELECTITEM_NOTBUSINESS,							// �̹� ������ �������� ������ �� �����ϴ�
	GAME_PRIVATESHOP_OWNER_BUSINESS_NOT_CONSENT,							// ���� ������ ������ �ź��߽��ϴ�
	GAME_PRIVATESHOP_SAMENOT_PRICEFLUCTUATIONSCOUNTER,						// ������ ���� ������ Ƚ���� �մ��� ���� ���� ��Ŷ�� ���� ���� �ٸ��ϴ�.
	GAME_PRIVATESHOP_ZENNY_LOCK,											// �ٸ� ����� Item Buy���̿��� Zenny�� Lock�� �Ǿ����ϴ�. ó���� ���������� ��ٷ� �ּ���
	GAME_PRIVATESHOP_NOT_PROGRESS_COMPLETE,									// ���� ��û�� ó���ɶ����� ���������� ��ٷ� �ּ��� (��Ŷ�� Qry Srv�� �ӹ��� �ִ�)
	GAME_PRIVATESHOP_VISITOR_SELECTITEM_ALREADYBUYANDBUSINESSITEM,			// �̹� �ٸ� �մ��� ������ �������Դϴ�.
	GAME_PRIVATESHOP_PRIVATESHOP_ANOTHER_NPC,								// ��ó�� NPC�� �־ ���λ����� �� �� �����ϴ�

	//-----------------------------------------------------------------
	GAME_MAIL_TARGET_AWAY_STATE = 2500,						// ���� �޴� ����� �������̶� ���źҰ����մϴ�.
	GAME_MAIL_NOT_FOUND,									// ���� ã�� ���߽��ϴ�.
	GAME_MAIL_ALREADY_READ,									// ������ �̹� ���� �����Դϴ�.
	GAME_MAIL_INVALID_DEL,									// �ش������ ���� �� �����ϴ�.
	GAME_MAIL_INVALID_RETURN,								// �ش������ ������ �� �����ϴ�.
	GAME_MAIL_INVALID_ACCEPT,								// �ش������ ���� �� ���� �����Դϴ�.
	GAME_MAIL_INVALID_LOCK,									// �ش������ ��ݼ����� ���� �Ұ����մϴ�.
	GAME_MAIL_INVALID_ZENNY,								// ���� �� �ִ� ������ �ѵ��� �ʰ��߽��ϴ�.
	GAME_MAIL_NOT_EXISTING_PLAYER,							// �ش� ĳ���ʹ� �������� ���� ĳ�����Դϴ�.
	GAME_MAIL_CANT_SEND_MAIL_TO_YOURSELF,					// �ڱ� �ڽſ��Դ� ������ ���� �� �����ϴ�.
	GAME_MAIL_MAILING_PARTS_NOT_FOUND,						// ���� ����Ĩ�� �����ϴ�.
	GAME_MAIL_TRANSMIT_PARTS_NOT_FOUND,						// ���� ����Ĩ�� �����ϴ�.
	GAME_MAIL_SCOUTER_FAIL,									// ���������� ���� ��ī���͸� ����� �� ���� �����Դϴ�.
	//-----------------------------------------------------------------
	GAME_PORTAL_ARLEADY_ADDED = 2600,						// �̵̹�ϵ� ��Ż�Դϴ�.
	GAME_PORTAL_NOT_EXIST,									// �̵�� ��Ż�Դϴ�. 

	GAME_WARFOG_ARLEADY_ADDED = 2610,						// �̵̹�ϵ� �������Դϴ�.
	//-----------------------------------------------------------------
	GAME_PROCESSING_DB = 2620,						// ���ó�����Դϴ�.
	//-----------------------------------------------------------------
	GAME_RIDE_ON_STATE = 2630,						// ���� Ÿ �ִ� ���� �Դϴ�.
	GAME_VEHICLE_CANNOT_WHILE_DRIVING,						// ���� �߿� �� �� �����ϴ�.
	GAME_VEHICLE_ENGINE_ALREADY_STARTED,					// �̹� �õ��� ���� �ֽ��ϴ�.
	GAME_VEHICLE_ENGINE_ALREADY_STOPED,						// �̹� �õ��� ���� �ֽ��ϴ�.
	GAME_VEHICLE_INVALID_FUEL_ITEM,							// 
	GAME_VEHICLE_FAIL_TO_USE_FUEL_ITEM,						// ���� ������ ��뿡 �����߽��ϴ�.
	GAME_VEHICLE_NO_FUEL_ITEM_REMAINING,					// ���� ���� �������� �����ϴ�.
	GAME_VEHICLE_END_BY_USER,								// ������ Ż�Ϳ��� �����⸦ ��û�߽��ϴ�.
	GAME_VEHICLE_END_BY_HIT,								// �ǰ� ���߱� ������ Ż�Ϳ��� �����ϴ�.
	GAME_VEHICLE_END_BY_CONVERTCLASS,						// �������� ���� Ż �Ϳ��� �����ϴ�.
	GAME_VEHICLE_END_BY_TELEPORT,							// �ڷ���Ʈ�� ���� Ż �Ϳ��� �����ϴ�.
	GAME_VEHICLE_END_BY_FORCED,								// Ż �� ���°� ������ Ǯ�Ƚ��ϴ�.
	GAME_VEHICLE_END_BY_TMQ,								// TMQ ���¿� �����ϱ� ������ Ż�Ϳ��� �����ϴ�.
	GAME_VEHICLE_END_BY_FORBIDDEN_ZONE,						// Ż ���� ������ �ʴ� �����Դϴ�.
	//-----------------------------------------------------------------
	GAME_PETITION_NOTAUTH = 2700,							//������ �����ϴ�
	GAME_PETITION_TOO_LONG_NAME,							//ĳ���͸��� ���̰� �ʰ��Ǿ����ϴ�.
	GAME_PETITION_TOO_SHORT_NAME,							//ĳ���͸��� ���̰� �ʹ� ª���ϴ�.
	GAME_PETITION_TOO_LONG_QUESTION_CONTENT,				//���� ������ ���̰� �ʰ��Ǿ����ϴ�.
	GAME_PETITION_TOO_SHORT_QUESTION_CONTENT,				//���� ������ ���̰� �ʹ� ª���ϴ�.
	GAME_PETITION_CATEGORY_1_FAIL,							//ī�װ� 1�� ���� �̻��մϴ�.
	GAME_PETITION_CATEGORY_2_FAIL,							//ī�װ� 2�� ���� �̻��մϴ�.
	GAME_PETITION_CREATE_PETITION_FAILE,					//���� ������ �����߽��ϴ�
	GAME_PETITION_DELETE_FAILE_STARTED,					//�̹� ����߿� ������ �����̱⿡ ������ �� �����ϴ�
	GAME_PETITION_ISNOT_STARTED,							//���� ���°� ������ �ƴմϴ�
	GAME_PETITION_ALREADYSTARTED,							//�̹� �������Դϴ�
	GAME_PETITION_INSERT_ERROR_ZERO_ID,					//����Ÿ ���� ���� - ID�� 0�Դϴ�
	GAME_PETITION_INSERT_FAILE,							//����Ÿ ���� ���� (std::map���� ������ �뺸, �� �� ���� ����
	GAME_PETITION_INSERT_ALLREADY_ID,						//����Ÿ ���� ���� (�̹� ��ϵǾ� �ִ� ID �Դϴ�
	GAME_PETITION_CREATE_PETITION_ID_FAILE,				//Petition ID ���� ����
	GAME_PETITION_NOTRUNSTATE,								//���� ���¿����� ���� �� �� �����ϴ�
	GAME_PETITION_ACCOUNTNOTPETITION,						//�ش� ������ ������ �����ϴ�
	GAME_PETITION_ALREADY_INSERT,							//�̹� ������ ������ Account�Դϴ�.
	GAME_PETITION_LOCK,										// Petition�� Lock�Ǿ� �ֽ��ϴ�
	GAME_PETITION_PETITIONID_INVALID,						// Petition ID�� invalid �Դϴ�.
	GAME_PETITION_ALREADYFINISH,							//�̹� �Ϸ�� �����Դϴ�.

	//-----------------------------------------------------------------
	GAME_BUDOKAI_INVALID_TEAM_NAME = 2800,					// ���� �̸��� �ùٸ��� �ʽ��ϴ�.
	GAME_BUDOKAI_TOO_LONG_TEAM_NAME,						// ���� �̸��� �ʹ� ��ϴ�.
	GAME_BUDOKAI_TOO_SHORT_TEAM_NAME,						// ���� �̸��� �ʹ� ª���ϴ�.
	GAME_BUDOKAI_NEED_MORE_MEMBER,							// ������ �ʹ� �����ϴ�.
	GAME_BUDOKAI_NOT_REGISTER_PERIOD,						// ��� �Ⱓ�� �ƴմϴ�.
	GAME_BUDOKAI_OVER_COUNT,								// �����ο��� �ʰ��Ǿ����ϴ�.
	GAME_BUDOKAI_CHARACTER_ALREADY_JOIN,					// �̹� ��û�� �����Դϴ�.
	GAME_BUDOKAI_CHARACTER_NOT_JOINED,						// ��û���� ���� �����Դϴ�.
	GAME_BUDOKAI_MEMBER_ALREADY_JOINED,						// �̹� ��û�� ����� �ֽ��ϴ�.
	GAME_BUDOKAI_YOU_ARE_NOT_A_TEAM_LEADER,					// �� ������ �ƴմϴ�.
	GAME_BUDOKAI_NOT_MATCH_PLAYING,							// �������� ��Ⱑ �����ϴ�.
	GAME_BUDOKAI_NOT_OPENED,								// ���±Ⱓ�� �ƴմϴ�.
	GAME_BUDOKAI_NOT_MATCH_WORLD,							// õ�����Ϲ���ȸ ������� �ƴմϴ�.

	GAME_CAN_NOT_TELEPORT,									// �̵��� �� �����ϴ�.
	GAME_CAN_NOT_TELEPORT_THIS_STATE,						// �̵��� �� ���� �����Դϴ�. ��� �� �ٽ� �õ��ϼ���.

	GAME_MUDOSA_NOT_OPEND,									// ���� �Ⱓ�� �ƴմϴ�.
	GAME_MUDOSA_POINT_CANT_BE_USED_RIGHT_NOW,				// �Ͻ������� ������ ����Ʈ�� ����� �� ���� ��Ȳ�Դϴ�. ��� �� �ٽ� �õ��ϼ���.
	GAME_MUDOSA_POINT_NOT_ENOUGH,							// ������ ������ ������� �ʽ��ϴ�.
	GAME_MUDOSA_POINT_MAX_OVER,								// ������ ������ �ִ븦 �ʰ��Ͽ����ϴ�.

	GAME_MINORMATCH_CANNOT_TELEPORT_THIS_STATE,				// ������ ������ ���׿����� ������ �� �����ϴ�.

	GAME_NETP_POINT_CANT_BE_USED_RIGHT_NOW,					// �Ͻ������� NetPY ����Ʈ�� ����� �� ���� ��Ȳ�Դϴ�. ��� �� �ٽ� �õ��ϼ���.
	GAME_NETP_POINT_MAX_OVER,								// NetPY Point�� �ִ븦 �ʰ��Ͽ����ϴ�.
	GAME_NETP_POINT_NOT_ENOUGH,								// NetPY Point�� ������� �ʽ��ϴ�.
	GAME_NETPY_IS_LOCK,										// NetPY�� ��� �����Դϴ�.
	GAME_NETPY_NOT_ENOUGH,									// NetPY�� �����մϴ�.	

	GAME_BUILDING_VERSION_IS_NOT_CJI_KOR,					// The Building Version is not CJI Kor

	GAME_NETMARBLEMEMBER_IS_NOT,							// Netmarble Member�� �ƴմϴ�.

	GAME_CASHITEM_CANT_MOVE,								// �ش� ĳ���������� ������ �� �����ϴ�.
	GAME_CASHITEM_NOT_LOADED,								// ĳ�������� �ε��� �Ϸ���� �ʾҽ��ϴ�.
	GAME_CASHITEM_NOT_FOUND,								// �ش� ĳ���������� ã�� �� �����ϴ�.
	//-----------------------------------------------------------------
	// Game, Item ����. 800���뿡�� �̾���. ( 3000 ~ )
	//-----------------------------------------------------------------
	GAME_ITEM_UPGRADE_ITEM_IS_ZERO_GRADE = 3000,			// �� ȣ������ ������ ����� �� �����ϴ�.
	GAME_DRAGONBALL_NOT_SAME_EXIST,							// �ٸ� ������ �巡�ﺼ �Դϴ�.
	GAME_ITEM_DURATIONTIME_ZERO,							// ��� �Ⱓ�� �������ϴ�.
	GAME_ITEM_RECIPE_CANNOT_RESET_NORMAL_TYPE,				// �⺻ ���� ����� ������ �� �����ϴ�.
	GAME_ITEM_NOT_USE_THIS_PLACE,							// ���⼭ ����� �� ���� �������Դϴ�.
	GAME_ITEM_STACK_FAIL_ITEMTYPE_DURATION,					// ���Ⱓ�� �ִ� �������� Stack�� �� �����ϴ�.
	GAME_ITEM_RECIPE_NORMAL_RECIPE_ALREADY_STARTED,			// �⺻ ���� ����� �̹� ��� �����Դϴ�.
	GAME_ITEM_RECIPE_SPECIAL_RECIPE_ALREADY_STARTED,		// Ư�� ���� ����� �̹� ��� �����Դϴ�.
	GAME_ITEM_RECIPE_CANNOT_RESET_CAUSE_NOT_STARTED_YET,	// ���� ����� ���� ����� �ʱ�ȭ �� �� �����ϴ�.
	GAME_ITEM_RECIPE_CANNOT_SET_YOU_NEED_HIGHER_LEVEL,		// ������ �����ϱ� ������ ��������� ��� �� �����ϴ�.
	GAME_ITEM_RECIPE_CANNOT_SET_YOU_NEED_MORE_ZENNY,		// ���ϰ� �����ϱ� ������ ��������� ��� �� �����ϴ�.
	GAME_ITEM_CANT_USE_CAUSE_CAPSULE_ITEM_ALREADY_IN_USE,	// ĸ�� �������� �̹� ������Դϴ�.

	GAME_SCOUTER_CHIP_NOT_EXIST,							// ��ī���� Ĩ�� �������� �ʽ��ϴ�.

	//-----------------------------------------------------------------
	REPORT_SUCCESS = 6000,									// ������ ����
	REPORT_FAIL,											// ������ ����

	//-----------------------------------------------------------------
	// Petition System ( 10000 ~ )
	//-----------------------------------------------------------------
	PETITION_SUCCESS = 10000,								// Petition ����
	PETITION_FAIL,											// Petition ����

	PETITION_NOT_STARTED_CLEINT_GM_CHAT,					// Ŭ���̾�Ʈ�� GM ä���� ���۵��� �ʾҽ��ϴ�
	PETITION_DIFFERENT_CHAATING_GM_ID,						// Ŭ���̾�Ʈ�� ä������ GM�� ID�� �ٸ� GM ID�̴�.
	PETITION_NOT_YET_ENTER_WORLD,							// ������ ���忡 ���� �ʾҴ�
	PETITION_AREADY_GM_CHATTING,							// ������ �̹� GM ä�����̴�
};

enum SERVERSTATUS
{
	SERVERSTATUS_UP = 0,
	SERVERSTATUS_DOWN,
	SERVERSTATUS_LOCKED
};

enum RACE
{
	RACE_HUMAN,
	RACE_NAMEK,
	RACE_MAJIN,

	RACE_COUNT,
	RACE_UNKNOWN = 0xFF,

	RACE_FIRST = RACE_HUMAN,
	RACE_LAST = RACE_MAJIN
};

enum RACE_FLAG
{
	RACE_HUMAN_FLAG = MAKE_BIT_FLAG(RACE_HUMAN),
	RACE_NAMEK_FLAG = MAKE_BIT_FLAG(RACE_NAMEK),
	RACE_MAJIN_FLAG = MAKE_BIT_FLAG(RACE_MAJIN),
};

enum GENDER
{
	GENDER_MALE,
	GENDER_FEMALE,
	GENDER_ONE_SEX,

	GENDER_COUNT,
	GENDER_UNKNOWN = 0xFF,

	GENDER_FIRST = GENDER_MALE,
	GENDER_LAST = GENDER_ONE_SEX
};

enum PC_CLASS
{
	PC_CLASS_HUMAN_FIGHTER,
	PC_CLASS_HUMAN_MYSTIC,
	PC_CLASS_HUMAN_ENGINEER, 
	PC_CLASS_NAMEK_FIGHTER,
	PC_CLASS_NAMEK_MYSTIC,
	PC_CLASS_MIGHTY_MAJIN,
	PC_CLASS_WONDER_MAJIN,
	PC_CLASS_STREET_FIGHTER,
	PC_CLASS_SWORD_MASTER, 
	PC_CLASS_CRANE_ROSHI, 
	PC_CLASS_TURTLE_ROSHI,
	PC_CLASS_GUN_MANIA, 
	PC_CLASS_MECH_MANIA,
	PC_CLASS_DARK_WARRIOR, 
	PC_CLASS_SHADOW_KNIGHT, 
	PC_CLASS_DENDEN_HEALER,
	PC_CLASS_POCO_SUMMONER,
	PC_CLASS_ULTI_MA, 
	PC_CLASS_GRAND_MA,
	PC_CLASS_PLAS_MA,
	PC_CLASS_KAR_MA,

	PC_CLASS_COUNT,
	PC_CLASS_UNKNOWN = 0xFF,

	PC_CLASS_1_FIRST = PC_CLASS_HUMAN_FIGHTER,
	PC_CLASS_1_LAST = PC_CLASS_WONDER_MAJIN,
	PC_CLASS_2_FIRST = PC_CLASS_STREET_FIGHTER,
	PC_CLASS_2_LAST = PC_CLASS_KAR_MA,

	PC_CLASS_FIRST = PC_CLASS_HUMAN_FIGHTER,
	PC_CLASS_LAST = PC_CLASS_COUNT - 1
};

enum PC_CLASS_FLAG
{
	PC_CLASS_FLAG_HUMAN_FIGHTER = (0x01 << PC_CLASS_HUMAN_FIGHTER),
	PC_CLASS_FLAG_HUMAN_MYSTIC = (0x01 << PC_CLASS_HUMAN_MYSTIC),
	PC_CLASS_FLAG_HUMAN_ENGINEER = (0x01 << PC_CLASS_HUMAN_ENGINEER),
	PC_CLASS_FLAG_NAMEK_FIGHTER = (0x01 << PC_CLASS_NAMEK_FIGHTER),
	PC_CLASS_FLAG_NAMEK_MYSTIC = (0x01 << PC_CLASS_NAMEK_MYSTIC),
	PC_CLASS_FLAG_MIGHTY_MAJIN = (0x01 << PC_CLASS_MIGHTY_MAJIN),
	PC_CLASS_FLAG_WONDER_MAJIN = (0x01 << PC_CLASS_WONDER_MAJIN),
	PC_CLASS_FLAG_STREET_FIGHTER = (0x01 << PC_CLASS_STREET_FIGHTER) | PC_CLASS_FLAG_HUMAN_FIGHTER,
	PC_CLASS_FLAG_SWORD_MASTER = (0x01 << PC_CLASS_SWORD_MASTER) | PC_CLASS_FLAG_HUMAN_FIGHTER,
	PC_CLASS_FLAG_CRANE_ROSHI = (0x01 << PC_CLASS_CRANE_ROSHI) | PC_CLASS_FLAG_HUMAN_MYSTIC,
	PC_CLASS_FLAG_TURTLE_ROSHI = (0x01 << PC_CLASS_TURTLE_ROSHI) | PC_CLASS_FLAG_HUMAN_MYSTIC,
	PC_CLASS_FLAG_GUN_MANIA = (0x01 << PC_CLASS_GUN_MANIA) | PC_CLASS_FLAG_HUMAN_ENGINEER,
	PC_CLASS_FLAG_MECH_MANIA = (0x01 << PC_CLASS_MECH_MANIA) | PC_CLASS_FLAG_HUMAN_ENGINEER,
	PC_CLASS_FLAG_DARK_WARRIOR = (0x01 << PC_CLASS_DARK_WARRIOR) | PC_CLASS_FLAG_NAMEK_FIGHTER,	
	PC_CLASS_FLAG_SHADOW_KNIGHT = (0x01 << PC_CLASS_SHADOW_KNIGHT) | PC_CLASS_FLAG_NAMEK_FIGHTER,
	PC_CLASS_FLAG_DENDEN_HEALER = (0x01 << PC_CLASS_DENDEN_HEALER) | PC_CLASS_FLAG_NAMEK_MYSTIC,
	PC_CLASS_FLAG_POCO_SUMMONER = (0x01 << PC_CLASS_POCO_SUMMONER) | PC_CLASS_FLAG_NAMEK_MYSTIC,
	PC_CLASS_FLAG_GRAND_MA = (0x01 << PC_CLASS_GRAND_MA) | PC_CLASS_FLAG_MIGHTY_MAJIN,
	PC_CLASS_FLAG_ULTI_MA = (0x01 << PC_CLASS_ULTI_MA) | PC_CLASS_FLAG_MIGHTY_MAJIN,
	PC_CLASS_FLAG_PLAS_MA = (0x01 << PC_CLASS_PLAS_MA) | PC_CLASS_FLAG_WONDER_MAJIN,
	PC_CLASS_FLAG_KAR_MA = (0x01 << PC_CLASS_KAR_MA) | PC_CLASS_FLAG_WONDER_MAJIN,
};

enum ZENNY_CHANGE_TYPE
{
	ZENNY_CHANGE_TYPE_ITEM_BUY = 0,
	ZENNY_CHANGE_TYPE_ITEM_SELL,
	ZENNY_CHANGE_TYPE_PICK,
	ZENNY_CHANGE_TYPE_TRADE,
	ZENNY_CHANGE_TYPE_REPAIR,
	ZENNY_CHANGE_TYPE_REWARD,
	ZENNY_CHANGE_TYPE_SKILL,
	ZENNY_CHANGE_TYPE_PARTY_VICTIM_ADD,
	ZENNY_CHANGE_TYPE_PARTY_VICTIM_DEL,
	ZENNY_CHANGE_TYPE_PARTY_VICTIM_RETURN,
	ZENNY_CHANGE_TYPE_CHEAT,
	ZENNY_CHANGE_TYPE_BANK_BUY,
	ZENNY_CHANGE_TYPE_PARTY_PICK,
	ZENNY_CHANGE_TYPE_GUILD_CREATE,
	ZENNY_CHANGE_TYPE_DB_REWARD,
	ZENNY_CHANGE_TYPE_PRIVATESHOP_ITEM_BUY,
	ZENNY_CHANGE_TYPE_MAIL_SEND,
	ZENNY_CHANGE_TYPE_MAIL_RECV,
	ZENNY_CHANGE_TYPE_RANKBATTLE,
	ZENNY_CHANGE_TYPE_PORTAL_ADD,

	ZENNY_CHANGE_TYPE_GUILD_FUNCTION_ADD,
	ZENNY_CHANGE_TYPE_GUILD_GIVE_ZENNY,
	ZENNY_CHANGE_TYPE_GUILD_MARK_CHANGE,
	ZENNY_CHANGE_TYPE_GUILD_NAME_CHANGE,
	ZENNY_CHANGE_TYPE_RIDE_ON_BUS,
	ZENNY_CHANGE_TYPE_ITEM_IDENTIFY,
	ZENNY_CHANGE_TYPE_SCOUTER_ITEM_SELL,
	ZENNY_CHANGE_TYPE_PARTY_ITEM_INVEST,
	ZENNY_CHANGE_TYPE_ITEM_MIX_MAKE,
	ZENNY_CHANGE_TYPE_ITEM_MIX_FARE,
	ZENNY_CHANGE_TYPE_DOJO_CHANGE,
	ZENNY_CHANGE_TYPE_BANK,
	ZENNY_CHANGE_TYPE_GUILD_BANK,
	ZENNY_CHANGE_TYPE_DOJO_SCRAMBLE_REQ,
	ZENNY_CHANGE_TYPE_DOJO_ANTI_SCRAMBLE_ADD,
	ZENNY_CHANGE_TYPE_DOJO_ANTI_SCRAMBLE_DEL,
	ZENNY_CHANGE_TYPE_ITEM_RECIPE_JOB_SET, 

	ZENNY_CHANGE_TYPE_COUNT,
	ZENNY_CHANGE_TYPE_INVALID = 0xFF
};

enum CONTAINER_TYPE
{
	CONTAINER_TYPE_BAGSLOT,
	CONTAINER_TYPE_BAG1,
	CONTAINER_TYPE_BAG2,
	CONTAINER_TYPE_BAG3,
	CONTAINER_TYPE_BAG4,
	CONTAINER_TYPE_BAG5,

	CONTAINER_TYPE_NETPYSTORE,

	CONTAINER_TYPE_EQUIP,
	CONTAINER_TYPE_SCOUT,

	CONTAINER_TYPE_BANKSLOT,
	CONTAINER_TYPE_BANK1,
	CONTAINER_TYPE_BANK2,
	CONTAINER_TYPE_BANK3,
	CONTAINER_TYPE_BANK4,

	CONTAINER_TYPE_GUILD1,
	CONTAINER_TYPE_GUILD2,
	CONTAINER_TYPE_GUILD3,

	CONTAINER_TYPE_COUNT,
	CONTAINER_TYPE_NONE = 0xFF,

	CONTAINER_TYPE_BAG_FIRST = CONTAINER_TYPE_BAG1,
	CONTAINER_TYPE_BAG_LAST = CONTAINER_TYPE_NETPYSTORE,

	CONTAINER_TYPE_INVEN_FIRST = CONTAINER_TYPE_BAGSLOT,
	CONTAINER_TYPE_INVEN_LAST = CONTAINER_TYPE_SCOUT,

	CONTAINER_TYPE_BANK_FIRST = CONTAINER_TYPE_BANKSLOT,
	CONTAINER_TYPE_BANK_LAST = CONTAINER_TYPE_BANK4,

	CONTAINER_TYPE_GUILD_FIRST = CONTAINER_TYPE_GUILD1,
	CONTAINER_TYPE_GUILD_LAST = CONTAINER_TYPE_GUILD3,

	CONTAINER_TYPE_FIRST = CONTAINER_TYPE_BAGSLOT,
	CONTAINER_TYPE_LAST = CONTAINER_TYPE_BANK4,
};

enum EQUIP_SLOTTYPE
{
	EQUIP_SLOT_TYPE_HAND,
	EQUIP_SLOT_TYPE_SUB_WEAPON,
	EQUIP_SLOT_TYPE_JACKET,
	EQUIP_SLOT_TYPE_PANTS,
	EQUIP_SLOT_TYPE_BOOTS,
	EQUIP_SLOT_TYPE_SCOUTER,
	EQUIP_SLOT_TYPE_COSTUME,
	EQUIP_SLOT_TYPE_NECKLACE,
	EQUIP_SLOT_TYPE_EARRING_1,
	EQUIP_SLOT_TYPE_EARRING_2,
	EQUIP_SLOT_TYPE_RING_1,
	EQUIP_SLOT_TYPE_RING_2,

	EQUIP_SLOT_TYPE_COUNT,
	EQUIP_SLOT_TYPE_UNKNOWN = 0xFF,

	EQUIP_SLOT_TYPE_FIRST = EQUIP_SLOT_TYPE_HAND,
	EQUIP_SLOT_TYPE_LAST = EQUIP_SLOT_TYPE_RING_2,
};

enum AVATAR_TYPE
{
	AVATAR_TYPE_AVATAR = 0,
	AVATAR_TYPE_SUMMON_PET_1,
	AVATAR_TYPE_ITEM_PET_1,
	AVATAR_TYPE_COUNT,
	AVATAR_TYPE_INVALID = 0xFF,
	AVATAR_TYPE_PET_FIRST = AVATAR_TYPE_SUMMON_PET_1,
	AVATAR_TYPE_PET_LAST = AVATAR_TYPE_ITEM_PET_1,
	AVATAR_TYPE_SUMMON_PET_FIRST = AVATAR_TYPE_SUMMON_PET_1,
	AVATAR_TYPE_SUMMON_PET_LAST = AVATAR_TYPE_SUMMON_PET_1,
	AVATAR_TYPE_ITEM_PET_FIRST = AVATAR_TYPE_ITEM_PET_1,
	AVATAR_TYPE_ITEM_PET_LAST = AVATAR_TYPE_ITEM_PET_1,
	DAVATAR_TYPE_COUNT_SUMMON_PET = AVATAR_TYPE_SUMMON_PET_LAST - AVATAR_TYPE_SUMMON_PET_FIRST + 1,
	DAVATAR_TYPE_COUNT_ITEM_PET = AVATAR_TYPE_ITEM_PET_LAST - AVATAR_TYPE_ITEM_PET_FIRST + 1,
};

enum REVIVAL_REQUEST_TYPE
{
	REVIVAL_REQUEST_TYPE_TELEPORT_SOMEWHERE = 0,
	REVIVAL_REQUEST_TYPE_CURRENT_POSITION,
	REVIVAL_REQUEST_TYPE_COUNT,
	REVIVAL_REQUEST_TYPE_FIRST = REVIVAL_REQUEST_TYPE_TELEPORT_SOMEWHERE,
	REVIVAL_REQUEST_TYPE_LAST = REVIVAL_REQUEST_TYPE_COUNT - 1,
};

enum REVIVAL_TYPE
{
	REVIVAL_TYPE_CURRENT_POSITION = 0,
	REVIVAL_TYPE_BIND_POINT,
	REVIVAL_TYPE_RESCUED,
	REVIVAL_TYPE_SPECIFIED_POSITION,

	REVIVAL_TYPE_FIRST = REVIVAL_TYPE_CURRENT_POSITION,
	REVIVAL_TYPE_LAST = REVIVAL_TYPE_RESCUED,
	INVALID_REVIVAL_TYPE = 0xFF
};

enum SHORTCUT_CHANGE_TYPE
{
	SHORTCUT_CHANGE_TYPE_ADD = 0,
	SHORTCUT_CHANGE_TYPE_DEL,
	SHORTCUT_CHANGE_TYPE_UPDATE,
};

enum PARTYDUNGEON_STATE
{
	PARTY_DUNGEON_STATE_NORMAL,
	PARTY_DUNGEON_STATE_HARD,
	PARTY_DUNGEON_STATE_SUPER,
	PARTY_DUNGEON_STATE_HERO,
	PARTY_DUNGEON_STATE_FIRST = PARTY_DUNGEON_STATE_NORMAL,
	PARTY_DUNGEON_STATE_LAST = PARTY_DUNGEON_STATE_HERO,
};

enum SYSTEM_EFFECT_RESULT_TYPE
{
	SYSTEM_EFFECT_RESULT_TYPE_GENERAL = 0,
	SYSTEM_EFFECT_RESULT_TYPE_DH_HOT,
	SYSTEM_EFFECT_RESULT_TYPE_DD_DOT,
	DSYSTEM_EFFECT_RESULT_TYPE_LP_EP_STEAL,
	SYSTEM_EFFECT_RESULT_TYPE_COUNT,
	SYSTEM_EFFECT_RESULT_TYPE_UNKNOWN = 0xFFui8,
	SYSTEM_EFFECT_RESULT_TYPE_FIRST = SYSTEM_EFFECT_RESULT_TYPE_GENERAL,
	SYSTEM_EFFECT_RESULT_TYPE_LAST = SYSTEM_EFFECT_RESULT_TYPE_COUNT - 1
};

enum QUEST_ID_RANGE
{
	QUEST_ID_RANGE_GENERAL_QUEST_MIN = 0,
	QUEST_ID_RANGE_GENERAL_QUEST_MAX = 7000,
	QUEST_ID_RANGE_GENERAL_QUEST_COUNT = QUEST_ID_RANGE_GENERAL_QUEST_MAX - QUEST_ID_RANGE_GENERAL_QUEST_MIN,
	QUEST_ID_RANGE_RESERVE_QUEST_MIN = 7000,
	QUEST_ID_RANGE_RESERVE_QUEST_MAX = 11000,
	QUEST_ID_RANGE_RESERVE_QUEST_COUNT = QUEST_ID_RANGE_RESERVE_QUEST_MAX - QUEST_ID_RANGE_RESERVE_QUEST_MIN,
	QUEST_ID_RANGE_SPECIAL_QUEST_MIN = 11000,
	QUEST_ID_RANGE_SPECIAL_QUEST_MAX = 14000,
	QUEST_ID_RANGE_SPECIAL_QUEST_COUNT = QUEST_ID_RANGE_SPECIAL_QUEST_MAX - QUEST_ID_RANGE_SPECIAL_QUEST_MIN,
	QUEST_ID_RANGE_QUEST_MAX = 14000,
};

enum COMPLETE_QUEST_STATE
{
	COMPLETE_QUEST_STATE_CLEAR = 0x1,
	COMPLETE_QUEST_STATE_MAX = 1
};

enum
{
	COMPLETE_QUEST_QUEST_PER_BYTE = 8 / COMPLETE_QUEST_STATE_MAX
};

enum
{
	COMPLETE_QUEST_QUEST_PER_STRUCT = 1000
};

enum
{
	COMPLETE_QUEST_QUEST_STRUCT_COUNT = QUEST_ID_RANGE_QUEST_MAX / COMPLETE_QUEST_QUEST_PER_STRUCT
};

enum
{
	MAX_CAN_PROGRESS_QUEST_NUM = 20,
	MAX_CAN_PROGRESS_GENERAL_QUEST_NUM = 10,
	MAX_CAN_PROGRESS_SPECIAL_QUEST_NUM = 10,
};

enum
{
	MAX_CAN_PROGRESS_TRIGGER_NUM = 20
};

enum TS_SVR_STATE
{
	TS_SVR_STATE_ERROR = 0x0001,
	TS_SVR_STATE_FAILED = 0x0002,
	TS_SVR_STATE_ESCORT = 0x0004,
	TS_SVR_STATE_SVR_EVT_WORLD_RANGE = 0x0008,
	TS_SVR_STATE_WPS_MODE = 0x0010,
	TS_SVR_STATE_USER_OUT_FAILED_WPS = 0x0020,
};

enum GAMERULE_TYPE
{
	GAMERULE_NORMAL,		// �Ϲ� �ʵ�
	GAMERULE_RANKBATTLE,	// ��ŷ ��Ʋ
	GAMERULE_MUDOSA,		// õ�����Ϲ���ȸ��
	GAMERULE_DOJO,			// ����
	GAMERULE_RAID,			// ���̵�
	GAMERULE_HUNT,			// ��� (����/��Ƽ�� �ν��Ͻ�)
	GAMERULE_TIMEQUEST,		// Ÿ�Ӹӽ� ����Ʈ
	GAMERULE_TUTORIAL,		// Ʃ�丮��
	GAMERULE_MINORMATCH,	// õ�����Ϲ���ȸ ����
	GAMERULE_MAJORMATCH,	// õ�����Ϲ���ȸ ����
	GAMERULE_FINALMATCH,	// õ�����Ϲ���ȸ �ἱ
	GAMERULE_TEINKAICHIBUDOKAI,	// õ�����Ϲ���ȸ
	GAMERULE_TLQ,			// Ÿ�Ӹ��� ����Ʈ

	GAMERULE_TYPE_COUNT,
	INVALID_GAMERULE = 0xFFFFFFFF, // ����
};

enum ITEM_RANK
{
	ITEM_RANK_NOTHING,
	ITEM_RANK_NORMAL,
	ITEM_RANK_SUPERIOR,
	ITEM_RANK_EXCELLENT,
	ITEM_RANK_RARE,
	ITEM_RANK_LEGENDARY,

	ITEM_RANK_COUNT,
	ITEM_RANK_UNKNOWN = 0xFF,

	ITEM_RANK_FIRST = ITEM_RANK_NOTHING,
	ITEM_RANK_LAST = ITEM_RANK_LEGENDARY
};

enum INVITATION_RESPONSE
{
	INVITATION_RESPONSE_ACCEPT = 0,	
	INVITATION_RESPONSE_DECLINE,
	INVITATION_RESPONSE_EXPIRE,

	INVITATION_RESPONSE_COUNT,

	INVITATION_RESPONSE_FIRST = INVITATION_RESPONSE_ACCEPT,
	INVITATION_RESPONSE_LAST = INVITATION_RESPONSE_EXPIRE
};

enum PARTY_ZENNY_LOOTING
{
	PARTY_ZENNY_LOOTING_GREEDILY = 0,
	PARTY_ZENNY_LOOTING_SHARED,

	PARTY_ZENNY_LOOTING_COUNT,

	PARTY_ZENNY_LOOTING_UNKNOWN = 0xFF,

	PARTY_ZENNY_LOOTING_FIRST = PARTY_ZENNY_LOOTING_GREEDILY,
	PARTY_ZENNY_LOOTING_LAST = PARTY_ZENNY_LOOTING_SHARED
};

enum PARTY_ITEM_LOOTING
{
	PARTY_ITEM_LOOTING_GREEDILY = 0,
	PARTY_ITEM_LOOTING_IN_ORDER,
	PARTY_ITEM_LOOTING_IN_ORDER_SEPERATELY,

	PARTY_ITEM_LOOTING_IN_LEADER,	
	PARTY_ITEM_LOOTING_BY_ZENNY,
	PARTY_ITEM_LOOTING_DICE,

	PARTY_ITEM_LOOTING_COUNT,

	PARTY_ITEM_LOOTING_UNKNOWN = 0xFF,

	PARTY_ITEM_LOOTING_FIRST = PARTY_ITEM_LOOTING_GREEDILY,
	PARTY_ITEM_LOOTING_LAST = PARTY_ITEM_LOOTING_DICE
};

enum PARTY_OPTION
{
	PARTY_OPTION_CANT_INVITE = 0,
	PARTY_OPTION_CANT_LEAVE,
	PARTY_OPTION_CANT_KICK_OUT,
	PARTY_OPTION_CANT_APPOINT_LEADER
};

enum PARTY_OPTION_FLAG
{
	PARTY_OPTION_FLAG_CANT_INVITE = 1 << PARTY_OPTION_CANT_INVITE,
	PARTY_OPTION_FLAG_CANT_LEAVE = 1 << PARTY_OPTION_CANT_LEAVE,
	PARTY_OPTION_FLAG_CANT_KICK_OUT = 1 << PARTY_OPTION_CANT_KICK_OUT,
	PARTY_OPTION_FLAG_CANT_APPOINT_LEADER = 1 << PARTY_OPTION_CANT_APPOINT_LEADER
};
// Basic Values
const DWORD MAX_PARTY_COUNT = 2000;

const DWORD MAX_MEMBER_IN_PARTY = 5;
const float VALID_DISTANCE_FOR_EXP_FROM_VICTIM = 100.0f;
const float VALID_DISTANCE_TO_GET_ZENNY_IN_PARTY = 100.0f;
const float VALID_DISTANCE_TO_GET_ITEM_IN_PARTY = 100.0f;

// Charm
const DWORD PARTY_CHARM_INVENTORY_COUNT = 2;
const DWORD SLOT_COUNT_IN_PARTY_CHARM_INVENTORY = 11;
const DWORD MAX_PARTY_BUFF = 2;

const DWORD TIME_PARTY_CHARM_DICE = 30000;		//30sec 
const DWORD TIME_PARTY_DICE_ITEM = 30000;		//30sec 
const BYTE	PARTY_INVEN_DEFAULT_ITEM_RANK = ITEM_RANK_SUPERIOR;
// Party Inventory
const DWORD PARTY_INVENTORY_SLOT_COUNT = 16;
// Party Option
const DWORD PARTY_OPTION_FLAG_DEFAULT = 0;
const DWORD PARTY_OPTION_FLAG_TMQ =
					PARTY_OPTION_FLAG_CANT_INVITE |
					PARTY_OPTION_FLAG_CANT_LEAVE |
					PARTY_OPTION_FLAG_CANT_KICK_OUT |
					PARTY_OPTION_FLAG_CANT_APPOINT_LEADER;
const DWORD PARTY_OPTION_FLAG_RANK_BATTLE =
					PARTY_OPTION_FLAG_CANT_INVITE |
					PARTY_OPTION_FLAG_CANT_LEAVE |
					PARTY_OPTION_FLAG_CANT_KICK_OUT |
					PARTY_OPTION_FLAG_CANT_APPOINT_LEADER;
const DWORD PARTY_OPTION_FLAG_BUDOKAI =
					PARTY_OPTION_FLAG_CANT_INVITE |
					PARTY_OPTION_FLAG_CANT_LEAVE |
					PARTY_OPTION_FLAG_CANT_KICK_OUT |
					PARTY_OPTION_FLAG_CANT_APPOINT_LEADER;
const DWORD MAX_SHARETARGET_COUNT = 5;

enum NPCCONV_TYPE
{
	NPCCONV_TYPE_DIALOGBOX,
	NPCCONV_TYPE_TOOLTIP,

	NPCCONV_TYPE_INVALID = 0xffffffff
};

enum STOC_EVT_DATA_TYPE
{
	STOC_EVT_DATA_TYPE_MOB_KILL_CNT,
	STOC_EVT_DATA_TYPE_MOB_KILL_ITEM_CNT,
	STOC_EVT_DATA_TYPE_DELIVERY_ITEM,
	STOC_EVT_DATA_TYPE_OBJECT_ITEM,
	STOC_EVT_DATA_TYPE_PUBLIC_MOB_ITEM_CNT,
	STOC_EVT_DATA_TYPE_CUSTOM_EVT_CNT,
	STOC_EVT_DATA_TYPE_VISIT,

	STOC_EVT_DATA_TYPE_MAX,
	STOC_EVT_DATA_TYPE_INVALID = 0xffffffff
};

enum FREEBATTLE_RESULT
{
	FREEBATTLE_RESULT_WIN,
	FREEBATTLE_RESULT_LOSE,
	FREEBATTLE_RESULT_DRAW,

	FREEBATTLE_RESULT_COUNT
};

enum ACCEPT_RES_TYPE
{
	ACCEPT_RES_TYPE_DENY = 0,
	ACCEPT_RES_TYPE_OK,
	ACCEPT_RES_TYPE_CANCEL,
};

enum OBJTYPE
{
	OBJTYPE_PC,
	OBJTYPE_NPC,
	OBJTYPE_MOB,
	OBJTYPE_SUMMON_PET,
	OBJTYPE_ITEM_PET,
	OBJTYPE_DROPMONEY,
	OBJTYPE_DROPITEM,
	OBJTYPE_TOBJECT,
	OBJTYPE_DYNAMIC,
	OBJTYPE_ITEM,

	MAX_OBJTYPE,
	MAX_SPAWNOBJTYPE = OBJTYPE_DYNAMIC,
	INVALID_OBJTYPE = 0xFF,

	OBJTYPE_FIRST = OBJTYPE_PC,
	OBJTYPE_LAST = MAX_OBJTYPE - 1,
};

enum OBJECT_SOURCE
{
	OBJECT_SOURCE_SKILL = 0,	
	OBJECT_SOURCE_ITEM,

	OBJECT_SOURCE_UNKNOWN = 0xFF,

	OBJECT_SOURCE_FIRST = OBJECT_SOURCE_SKILL,
	OBJECT_SOURCE_LAST = OBJECT_SOURCE_ITEM
};

enum TRIGGER_OBJECT_FUNC
{
	TRIGGER_OBJECT_FUNC_SELECTION = 0x1,
	TRIGGER_OBJECT_FUNC_PORTAL = 0x2,
	TRIGGER_OBJECT_FUNC_BIND = 0x4,
	TRIGGER_OBJECT_FUNC_SCOUTER = 0x8,
	TRIGGER_OBJECT_FUNC_RANK_BATTLE = 0x10,
	TRIGGER_OBJECT_FUNC_NORMAL_DRAGONBALL = 0x20,
	TRIGGER_OBJECT_FUNC_RAID_DRAGONBALL = 0x40,
	TRIGGER_OBJECT_FUNC_MAIL_BOX = 0x80,
	TRIGGER_OBJECT_FUNC_TIME_MACHINE = 0x100,
	TRIGGER_OBJECT_FUNC_NAMEKAN_SIGN = 0x200,
	TRIGGER_OBJECT_FUNC_PARTY_INSTANCE_DUNGEON = 0x400,
	TRIGGER_OBJECT_FUNC_TIME_LEAP_QUEST = 0x800,
	TRIGGER_OBJECT_FUNC_HOIPOIMIX = 0x1000,
	TRIGGER_OBJECT_FUNC_DOJO_WAREHOUSE = 0x2000,
	TRIGGER_OBJECT_FUNC_DOJO_SEAL = 0x4000,
};

enum DYNAMIC_OBJECT_STATES
{
	DYNAMIC_OBJECT_STATE_SPAWN,
	DYNAMIC_OBJECT_STATE_IDLE,
	DYNAMIC_OBJECT_STATE_DESPAWN,

	DYNAMIC_OBJECT_STATE_NUMS,
	DYNAMIC_OBJECT_STATE_INVALID = 0xFF
};

enum DYNAMIC_OBJECT_FUNCTION
{
	DYNAMIC_OBJECT_FUNCTION_HOIPOIMIX = 0x1,

	DYNAMIC_OBJECT_FUNCTION_NUMS,
	DYNAMIC_OBJECT_FUNCTION_INVALID = 0xFF
};

enum DYNAMIC_OBJECT_TYPE
{
	DYNAMIC_OBJECT_TYPE_HOIPOI_MIX_MACHINE = 1,
	DYNAMIC_OBJECT_TYPE_CAPSULE_HOUSE,

	DYNAMIC_OBJECT_TYPE_NONE = 0xFF,
};

enum DYNAMIC_OBJECT_SUBSTATE
{
	DYNAMIC_OBJECT_SUBSTATE_ALL_SHOW,
	DYNAMIC_OBJECT_SUBSTATE_ONLY_SPAWN_AVATAR_SHOW,
	DYNAMIC_OBJECT_SUBSTATE_ENEMY_HIDE,

	DYNAMIC_OBJECT_SUBSTATE_NUMS,
	DYNAMIC_OBJECT_SUBSTATE_INVALID = 0xFF
};

enum DYNAMIC_OBJECT_HOIPOI_MACHINE_TYPE
{
	DYNAMIC_OBJECT_HOIPOI_MACHINE_TYPE_NORMAL = 1,
	DYNAMIC_OBJECT_HOIPOI_MACHINE_TYPE_RENTAL,
	DYNAMIC_OBJECT_HOIPOI_MACHINE_TYPE_NETP,
	DYNAMIC_OBJECT_HOIPOI_MACHINE_TYPE_CASH,

	DYNAMIC_OBJECT_HOIPOI_MACHINE_TYPE_NONE = 0xFF,
};

const unsigned int MAX_PC = 3000;
const unsigned int MAX_NPC = 3000;
const unsigned int MAX_MOB = 60000;
const unsigned int MAX_SUMMON_PET = MAX_PC;
const unsigned int MAX_ITEM_PET = MAX_PC;
const unsigned int MAX_DROP_ITEM = 3000;
const unsigned int MAX_DROP_MONEY = 3000;
const unsigned int MAX_PC_HAVE_ITEM = 200;
const unsigned int MAX_TRIGGER_OBJECT = 20000;
const unsigned int MAX_DYNAMIC_OBJECT = MAX_PC;
const unsigned int MAX_BOT = MAX_NPC + MAX_MOB + MAX_SUMMON_PET + MAX_ITEM_PET;
const unsigned int MAX_ITEM = MAX_PC * MAX_PC_HAVE_ITEM;
const unsigned int MAX_GAME_OBJECT = MAX_PC + MAX_BOT + MAX_ITEM + MAX_DROP_ITEM + MAX_DROP_MONEY + MAX_TRIGGER_OBJECT + MAX_DYNAMIC_OBJECT;
const float MAX_DISTANCE_OF_DYNAMIC_OBJECT = 20.0f;
const unsigned int DYNAMIC_OBJECT_CHECK_TERM = 1000;
const unsigned int DYNAMIC_OBJECT_DESPAWN_TERM = 1000;
const unsigned int DYNAMIC_OBJECT_SPAWN_TERM = 1000;

enum TIMEQUEST_TYPE
{
	TIMEQUEST_TYPE_TUTORIAL,
	TIMEQUEST_TYPE_PARTY,
	TIMEQUEST_TYPE_GROUP,

	MAX_TIMEQUEST_TYPE,
};

enum TIMEQUEST_MODE
{
	TIMEQUEST_MODE_INDIVIDUAL,
	TIMEQUEST_MODE_PARTY,

	MAX_TIMEQUEST_MODE,
	INVALID_TIMEQUEST_MODE = 0xFF,
};

enum TIMEQUEST_ROOM_STATE
{
	TIMEQUEST_ROOM_STATE_REGISTRAITION,
	TIMEQUEST_ROOM_STATE_WAITENTRY,	
	TIMEQUEST_ROOM_STATE_PC_DIRECTION,
	TIMEQUEST_ROOM_STATE_DAYRECORD_REQ,
	TIMEQUEST_ROOM_STATE_OBJECT_DIRECTION,
	TIMEQUEST_ROOM_STATE_PREPARE_WORLD,

	MAX_TIMEQUEST_ROOM_STATE,
	INVALID_TIMEQUEST_ROOM_STATE = 0xFF,
};

enum TIMEQUEST_GAME_STATE
{
	TIMEQUEST_GAME_STATE_WAIT,
	TIMEQUEST_GAME_STATE_PREPARE,
	TIMEQUEST_GAME_STATE_ARRIVE,
	TIMEQUEST_GAME_STATE_BEGIN,
	TIMEQUEST_GAME_STATE_STAGE_READY,
	TIMEQUEST_GAME_STATE_STAGE_START,
	TIMEQUEST_GAME_STATE_STAGE_FINISH,
	TIMEQUEST_GAME_STATE_END,
	TIMEQUEST_GAME_STATE_LEAVE,
	TIMEQUEST_GAME_STATE_FAIL,
	TIMEQUEST_GAME_STATE_CLOSE,

	MAX_TIMEQUEST_GAME_STATE
};

enum TIMEQUEST_STAGE_STATE
{
	MAX_TIMEQUEST_STAGE_STATE
};

enum TIMEQUEST_DIFFICULTY
{
	TIMEQUEST_DIFFICULTY_EASY,
	TIMEQUEST_DIFFICULTY_NORMAL,
	TIMEQUEST_DIFFICULTY_HARD,

	MAX_TIMEQUEST_DIFFICULTY,
	FIRST_TIMEQUEST_DIFFICULTY = TIMEQUEST_DIFFICULTY_EASY,
	INVALID_TIMEQUEST_DIFFICULTY = 0xFF,
};

enum TIMEQUEST_DIFFICULTY_FLAG
{
	TIMEQUEST_DIFFICULTY_FLAG_EASY = MAKE_BIT_FLAG(TIMEQUEST_DIFFICULTY_EASY),
	TIMEQUEST_DIFFICULTY_FLAG_NORMAL = MAKE_BIT_FLAG(TIMEQUEST_DIFFICULTY_NORMAL),
	TIMEQUEST_DIFFICULTY_FLAG_HARD = MAKE_BIT_FLAG(TIMEQUEST_DIFFICULTY_HARD),
};

enum TIMEQUEST_PROGRESS_MESSAGE_TYPE
{
	TIMEQUEST_PROGRESS_MESSAGE_TYPE_START,
	TIMEQUEST_PROGRESS_MESSAGE_TYPE_END,
	TIMEQUEST_PROGRESS_MESSAGE_TYPE_CLEAR,
	TIMEQUEST_PROGRESS_MESSAGE_TYPE_FAIL,

	MAX_TIMEQUEST_PROGRESS_MESSAGE_TYPE,
	INVALID_TIMEQUEST_PROGRESS_MESSAGE_TYPE = 0xFF,
};

enum TIMEQUEST_INFORMATION_TYPE
{
	TIMEQUEST_INFORMATION_TYPE_SCENARIO,
	TIMEQUEST_INFORMATION_TYPE_STAGE,

	MAX_TIMEQUEST_INFORMATION_TYPE,
	INVALID_TIMEQUEST_INFORMATION_TYPE = 0xFF,
};

const DWORD TIMEQUEST_MAX_ROOM_COUNT = 10; 
const DWORD TIMEQUEST_MAX_MEMBER_COUNT = MAX_MEMBER_IN_PARTY; 
const DWORD TIMEQUEST_ROOM_START_REPORT_TIME = 30000; 
const DWORD TIMEQUEST_ROOM_LEAVE_LIMIT_TIME = 60000;
const DWORD TIMEQUEST_MAX_STAGE_NUMBER = 64;
const DWORD TIMEQUEST_MAX_KILL_COUNT = 3;
const DWORD TIMEQUEST_ROOM_REFRESH_TIME = 10000;
const WORD TIMEQUEST_COUNPON_CHANGE_POINT = 1000;
const WORD TIMEQUEST_COUNPON_LIMIT_COUNT = 4;
const WORD TIMEQUEST_DEFAULT_DAYRECORD_RANK_COUNT = 5;
const WORD TIMEQUEST_DEFAULT_TOTAL_RANK_COUNT = TIMEQUEST_DEFAULT_DAYRECORD_RANK_COUNT + 1;

enum RANKBATTLE_ROOMSTATE
{
	RANKBATTLE_ROOMSTATE_NONE,
	RANKBATTLE_ROOMSTATE_WAIT,
	RANKBATTLE_ROOMSTATE_MATCH_READY,
	RANKBATTLE_ROOMSTATE_WAIT_MATCH_WORLD,
	RANKBATTLE_ROOMSTATE_MATCH_RUN,
	RANKBATTLE_ROOMSTATE_MATCH_END,

	RANKBATTLE_ROOMSTATE_COUNT,
	INVALID_RANKBATTLE_ROOMSTATE = INVALID_BYTE,
};

enum RANKBATTLE_MODE
{
	RANKBATTLE_MODE_INDIVIDUAL,
	RANKBATTLE_MODE_PARTY,

	MAX_RANKBATTLE_MODE,
	INVALID_RANKBATTLE_MODE = INVALID_BYTE
};

enum RANKBATTLE_TEAM_TYPE
{
	RANKBATTLE_TEAM_NONE = 0,
	RANKBATTLE_TEAM_OWNER = 0x01 << 0,
	RANKBATTLE_TEAM_CHALLENGER = 0x01 << 1,
	RANKBATTLE_TEAM_OTHER = 0x01 << 2,

	RANKBATTLE_TEAM_ALL = RANKBATTLE_TEAM_OWNER | RANKBATTLE_TEAM_CHALLENGER,
};

enum RANKBATTLE_BATTLESTATE
{
	RANKBATTLE_BATTLESTATE_NONE,
	RANKBATTLE_BATTLESTATE_WAIT,
	RANKBATTLE_BATTLESTATE_DIRECTION,
	RANKBATTLE_BATTLESTATE_STAGE_READY,
	RANKBATTLE_BATTLESTATE_STAGE_RUN,
	RANKBATTLE_BATTLESTATE_STAGE_FINISH,
	RANKBATTLE_BATTLESTATE_MATCH_FINISH,
	RANKBATTLE_BATTLESTATE_BOSS_DIRECTION,
	RANKBATTLE_BATTLESTATE_BOSS_READY,
	RANKBATTLE_BATTLESTATE_BOSS_RUN,
	RANKBATTLE_BATTLESTATE_BOSS_FINISH,	
	RANKBATTLE_BATTLESTATE_END,

	MAX_RANKBATTLE_BATTLESTATE,
	INVALID_RANKBATTLE_BATTLESTATE = INVALID_BYTE
};

enum RANKBATTLE_MEMBER_STATE
{
	RANKBATTLE_MEMBER_STATE_NONE,
	RANKBATTLE_MEMBER_STATE_NORMAL,	
	RANKBATTLE_MEMBER_STATE_FAINT,
	RANKBATTLE_MEMBER_STATE_OUTOFAREA,
	RANKBATTLE_MEMBER_STATE_GIVEUP,
	RANKBATTLE_MEMBER_STATE_NOAPPLY,
};

enum RANKBATTLE_MATCH_RESULT
{
	RANKBATTLE_MATCH_NONE,
	RANKBATTLE_MATCH_WIN_OWNER,
	RANKBATTLE_MATCH_WIN_CHALLENGER,
	RANKBATTLE_MATCH_DRAW,

	INVALID_RANKBATTLE_MATCH = INVALID_BYTE,
};

enum RANKBATTLE_QUERY_UPDATE_TYPE
{
	RANKBATTLE_QUERY_UPDATE_NONE,
	RANKBATTLE_QUERY_UPDATE_ADD,
	RANKBATTLE_QUERY_UPDATE_INIT,
};

const DWORD RANKBATTLE_MAX_ROOM_COUNT = 100;
const DWORD RANKBATTLE_MAX_ROOM_COUNT_PER_PAGE = 10;
const DWORD RANKBATTLE_USER_WAIT_TIME = 60000;
const DWORD RANKBATTLE_NAME_LENGTH = 128;
const BYTE RANKBATTLE_PARTY_MEMBER_RESTRICTION = 1;
const DWORD RANKBATTLE_ROOM_READY_TIME = 10000;
const DWORD RANKBATTLE_ENDSTAGE_WAIT_TIME = 5000;
const BYTE RANKBATTLE_MAX_RANK_BOARD_RECORD_COUNT = 10;
const BYTE RANKBATTLE_MAX_COMPARE_DAY = 7;
const DWORD RANKBATTLE_RANK_REQUEST_TERM = 500;
const BYTE _RANKBATTLE_RANK_BACKUP_TIME = 6;
const WORD RANKBATTLE_MAX_ARENA_TYPE = 10;
const DWORD	 RANKBATTLE_MATCH_START_TERM = 60;
const BYTE RANKBATTLE_MAX_MATCHING_LEVEL = 1;

enum PRIVATESHOP_STATE
{
	PRIVATESHOP_STATE_CLOSE = 0,
	PRIVATESHOP_STATE_OPEN,
	PRIVATESHOP_STATE_BUSINESS_WAIT,
	PRIVATESHOP_STATE_BUSINESS,
	PRIVATESHOP_STATE_NONE,
	PRIVATESHOP_STATE_NULL,
	PRIVATESHOP_STATE_DATALOADING
};

const BYTE MAX_PRIVATESHOP_INVENTORY = 36;
const int MAX_PRIVATESHOP_BUY_SHOPPING_CART = 12;
const BYTE PRIVATESHOP_ITEMPOS_INVALID = 0xFF;
const DWORD PRIVATESHOP_ITEM_BUY_ZENNY_DEFAULT = 1;

const DWORD MAX_BASIC_MAIL_SEND_ZENNY = 10;
const DWORD MAX_ATTACH_MAIL_SEND_ZENNY = 10;
const DWORD MAX_MAIL_SEND_ZENNY_AMOUNTS = 100000;
const DWORD MAX_MAIL_SLOT_COUNT = 30;
const DWORD MAIL_RELOAD_TIME = 1 * 60 * 1000;
const DWORD MAIL_DISTANCE_CHECK_TIME = 3 * 1000;
const BYTE DEFAULT_MAIL_KEEPING_PERIOD = 10;
const DWORD MAX_COUNT_OF_MULTI_DEL = 6;
const BYTE MAX_COUNT_MULTI_MAIL = 50;

enum MAIL_TYPE
{
	MAIL_TYPE_NONE,
	MAIL_TYPE_BASIC,
	MAIL_TYPE_ITEM,
	MAIL_TYPE_ZENNY,
	MAIL_TYPE_ITEM_ZENNY,
	MAIL_TYPE_ITEM_ZENNY_REQ, 
	MAIL_TYPE_ZENNY_REQ,
	MAIL_COUNT,
};

enum MAIL_SENDER_TYPE
{
	MAIL_SENDER_TYPE_BASIC,
	MAIL_SENDER_TYPE_REPLY,
	MAIL_SENDER_TYPE_RETURN,
	MAIL_SENDER_TYPE_SYSTEM,
	MAIL_SENDER_TYPE_GM,

};

enum TELEPORT_TYPE
{
	TELEPORT_TYPE_DEFAULT,
	TELEPORT_TYPE_GAME_IN,
	TELEPORT_TYPE_GAME_OUT,
	TELEPORT_TYPE_TELEPOPO,
	TELEPORT_TYPE_SKILL,
	TELEPORT_TYPE_NPC_PORTAL,
	TELEPORT_TYPE_POPOSTONE,
	TELEPORT_TYPE_WORLD_MOVE,
	TELEPORT_TYPE_TMQ_WORLD_MOVE,
	TELEPORT_TYPE_TMQ_PORTAL,

	TELEPORT_TYPE_RANKBATTLE,
	TELEPORT_TYPE_TIMEQUEST,
	TELEPORT_TYPE_TUTORIAL,
	TELEPORT_TYPE_BUDOKAI,
	TELEPORT_TYPE_MATCH,
	TELEPORT_TYPE_MINORMATCH,
	TELEPORT_TYPE_MAJORMATCH,
	TELEPORT_TYPE_FINALMATCH,

	TELEPORT_TYPE_COMMAND,
	TELEPORT_TYPE_GM,
	TELEPORT_TYPE_DUNGEON,
	TELEPORT_TYPE_DOJO,

	TELEPORT_TYPE_COUNT,

	TELEPORT_TYPE_INVALID = 0xFFui8,

	TELEPORT_TYPE_FIRST = TELEPORT_TYPE_GAME_IN,
	TELEPORT_TYPE_LAST = TELEPORT_TYPE_DUNGEON,
};

enum BIND_TYPE
{
	BIND_TYPE_INITIAL_LOCATION = 0,
	BIND_TYPE_POPO_STONE,
	BIND_TYPE_GM_TOOL,
	BIND_TYPE_SKILL,

	BIND_TYPE_FIRST = BIND_TYPE_INITIAL_LOCATION,
	BIND_TYPE_LAST = BIND_TYPE_SKILL,
	BIND_TYPE_INVALID = 0xFF
};

const int PORTAL_MAX_COUNT = 100;
const DWORD TELEPORT_PROPOSAL_WAIT_TIME = 120;

enum MATCHWORLD_TYPE
{
	MATCHWORLD_TYPE_MINOR_MATCH,
	MATCHWORLD_TYPE_MAJOR_MATCH,
	MATCHWORLD_TYPE_FINAL_MATCH,

	MAX_MATCHWORLD_TYPE,
	INVALID_MATCHWORLD_TYPE = 0xff
};

enum eMATCH_MEMBER_STATE
{
	MATCH_MEMBER_STATE_NONE,
	MATCH_MEMBER_STATE_NORMAL,	
	MATCH_MEMBER_STATE_FAINT,
	MATCH_MEMBER_STATE_OUTOFAREA,
	MATCH_MEMBER_STATE_GIVEUP,
	MATCH_MEMBER_STATE_NOAPPLY,
	MATCH_MEMBER_STATE_TELEPORTING,
	MATCH_MEMBER_STATE_BE_LATE,	
	MATCH_MEMBER_STATE_RESCUE,
};


enum MATCH_TEAM_TYPE
{
	MATCH_TEAM_TYPE_TEAM1,
	MATCH_TEAM_TYPE_TEAM2,

	MAX_MATCH_TEAM_TYPE_COUNT,
	INVALID_MATCH_TEAM_TYPE = 0xffff
};

enum MATCH_RESULT
{
	MATCH_RESULT_SUCCESS,
	MATCH_RESULT_DRAW,
	MATCH_RESULT_WIN,
	MATCH_RESULT_TIMEOVER,
	MATCH_RESULT_DOJO_RECOMMENDER,
	MATCH_RESULT_UNEARNED_WIN,

	INVALID_MATCH_RESULT = 0xff,
};

enum BUDOKAI_MINORMATCH_STATE
{
	BUDOKAI_MINORMATCH_STATE_NONE,
	BUDOKAI_MINORMATCH_STATE_WAIT_MINORMATCH,
	BUDOKAI_MINORMATCH_STATE_WAIT,
	BUDOKAI_MINORMATCH_STATE_DIRECTION,
	BUDOKAI_MINORMATCH_STATE_MATCH_READY,
	BUDOKAI_MINORMATCH_STATE_STAGE_READY,
	BUDOKAI_MINORMATCH_STATE_STAGE_RUN,
	BUDOKAI_MINORMATCH_STATE_STAGE_SELECTION,
	BUDOKAI_MINORMATCH_STATE_STAGE_FINISH,
	BUDOKAI_MINORMATCH_STATE_MATCH_FINISH,
	BUDOKAI_MINORMATCH_STATE_END,

	MAX_BUDOKAI_MINORMATCH_STATE,
	INVALID_BUDOKAI_MINORMATCH_STATE = INVALID_BYTE
};

enum BUDOKAI_MAJORMATCH_STATE
{
	BUDOKAI_MAJORMATCH_STATE_NONE,
	BUDOKAI_MAJORMATCH_STATE_WAIT,
	BUDOKAI_MAJORMATCH_STATE_DIRECTION,
	BUDOKAI_MAJORMATCH_STATE_MATCH_READY,
	BUDOKAI_MAJORMATCH_STATE_STAGE_READY,
	BUDOKAI_MAJORMATCH_STATE_STAGE_RUN,
	BUDOKAI_MAJORMATCH_STATE_STAGE_FINISH,
	BUDOKAI_MAJORMATCH_STATE_MATCH_FINISH,
	BUDOKAI_MAJORMATCH_STATE_END,

	MAX_BUDOKAI_MAJORMATCH_STATE,
	INVALID_BUDOKAI_MAJORMATCH_STATE = INVALID_BYTE
};

enum BUDOKAI_FINALMATCH_STATE
{
	BUDOKAI_FINALMATCH_STATE_NONE,
	BUDOKAI_FINALMATCH_STATE_WAIT,
	BUDOKAI_FINALMATCH_STATE_DIRECTION,
	BUDOKAI_FINALMATCH_STATE_MATCH_READY,
	BUDOKAI_FINALMATCH_STATE_STAGE_READY,
	BUDOKAI_FINALMATCH_STATE_STAGE_RUN,
	BUDOKAI_FINALMATCH_STATE_STAGE_FINISH,
	BUDOKAI_FINALMATCH_STATE_MATCH_FINISH,
	BUDOKAI_FINALMATCH_STATE_FINALDIRECTION,
	BUDOKAI_FINALMATCH_STATE_AWARDING,
	BUDOKAI_FINALMATCH_STATE_END,

	MAX_BUDOKAI_FINALMATCH_STATE,
	INVALID_BUDOKAI_FINALMATCH_STATE = INVALID_BYTE
};

enum FINALMATCH_TYPE
{
	FINALMATCH_TYPE_SEMIFINAL_1 = 0,
	FINALMATCH_TYPE_SEMIFINAL_2,
	FINALMATCH_TYPE_FINAL,

	FINALMATCH_TYPE_COUNT,
	INVALID_FINALMATCH_TYPE = 0xFF,
};

enum FINALMATCH_RESULT
{
	FINALMATCH_RESULT_WINNER,
	FINALMATCH_RESULT_SEMIWINNER,
	FINALMATCH_RESULT_MATCH1_LOSER,
	FINALMATCH_RESULT_MATCH2_LOSER,

	MAX_FINALMATCH_RESULT,
};

enum BUDOKAI_TYPE
{
	BUDOKAI_TYPE_JUNIOR,
	BUDOKAI_TYPE_ADULT,

	INVALID_BUDOKAI_TYPE = 0xff
};


enum BUDOKAI_MATCH_TYPE
{
	BUDOKAI_MATCH_TYPE_INDIVIDIAUL,
	BUDOKAI_MATCH_TYPE_TEAM,

	MAX_BUDOKAI_MATCH_TYPE,
	INVALID_BUDOKAI_MATCH_TYPE = 0xff,
};

enum BUDOKAI_NOTICE_TYPE
{
	BUDOKAI_NOTICE_SYSTEM,
	BUDOKAI_NOTICE_GM,
	BUDOKAI_NOTICE_ONLY_CLIENT,

	INVALID_BUDOKAI_NOTICE_TYPE = 0xff,
};

enum BUDOKAI_STATE
{
	BUDOKAI_STATE_JUNIOR_CLOSE,
	BUDOKAI_STATE_JUNIOR_OPEN_NOTICE,
	BUDOKAI_STATE_JUNIOR_DOJO_RECOMMEND,
	BUDOKAI_STATE_JUNIOR_OPEN,
	BUDOKAI_STATE_JUNIOR_CLEAR,

	BUDOKAI_STATE_CLOSE,
	BUDOKAI_STATE_OPEN_NOTICE,
	BUDOKAI_STATE_DOJO_RECOMMEND,
	BUDOKAI_STATE_OPEN,
	BUDOKAI_STATE_CLEAR,

	MAX_BUDOKAI_STATE,
	BUDOKAI_STATE_JUNIOR_FIRST = BUDOKAI_STATE_JUNIOR_CLOSE,
	BUDOKAI_STATE_JUNIOR_LAST = BUDOKAI_STATE_JUNIOR_CLEAR,
	BUDOKAI_STATE_ADULT_FIRST = BUDOKAI_STATE_CLOSE,
	BUDOKAI_STATE_ADULT_LAST = BUDOKAI_STATE_CLEAR,
	BUDOKAI_STATE_FIRST = BUDOKAI_STATE_JUNIOR_CLOSE,
	BUDOKAI_STATE_LAST = BUDOKAI_STATE_CLEAR,
	INVALID_BUDOKAI_STATE = 0xff,
};

enum BUDOKAI_MATCHSTATE
{
	BUDOKAI_MATCHSTATE_REGISTER,
	BUDOKAI_MATCHSTATE_WAIT_MINOR_MATCH,
	BUDOKAI_MATCHSTATE_MINOR_MATCH,
	BUDOKAI_MATCHSTATE_WAIT_MAJORMATCH_32,
	BUDOKAI_MATCHSTATE_MAJORMATCH_32,
	BUDOKAI_MATCHSTATE_WAIT_MAJORMATCH_16,
	BUDOKAI_MATCHSTATE_MAJORMATCH_16,
	BUDOKAI_MATCHSTATE_WAIT_MAJORMATCH_08,
	BUDOKAI_MATCHSTATE_MAJORMATCH_08,
	BUDOKAI_MATCHSTATE_WAIT_SEMIFINAL_MATCH,
	BUDOKAI_MATCHSTATE_SEMIFINAL_MATCH,
	BUDOKAI_MATCHSTATE_WAIT_FINAL_MATCH,
	BUDOKAI_MATCHSTATE_FINAL_MATCH,
	BUDOKAI_MATCHSTATE_MATCH_END,

	MAX_BUDOKAI_MATCHSTATE,
	INVALID_BUDOKAI_MATCHSTATE = 0xff,
};

enum BUDOKAI_JOIN_STATE
{
	BUDOKAI_JOIN_STATE_PLAY = 0,
	BUDOKAI_JOIN_STATE_DROPOUT,	

	INVALID_BUDOKAI_JOIN_STATE = 0xff,
};

enum BUDOKAI_JOIN_RESULT
{
	BUDOKAI_JOIN_RESULT_REGISTER = 0,
	BUDOKAI_JOIN_RESULT_MINORMATCH,
	BUDOKAI_JOIN_RESULT_ENTER_32,
	BUDOKAI_JOIN_RESULT_ENTER_16,
	BUDOKAI_JOIN_RESULT_ENTER_8,
	BUDOKAI_JOIN_RESULT_ENTER_4,
	BUDOKAI_JOIN_RESULT_ENTER_2,
	BUDOKAI_JOIN_RESULT_WINNER,

	INVALID_BUDOKAI_JOIN_RESULT = 0xff
};


enum BUDOKAI_MATCH_DEPTH
{
	BUDOKAI_MATCH_DEPTH_2 = 0,	// 1	2^0
	BUDOKAI_MATCH_DEPTH_4,		// 2	2^1
	BUDOKAI_MATCH_DEPTH_8,		// 4	2^2
	BUDOKAI_MATCH_DEPTH_16,		// 8	2^3
	BUDOKAI_MATCH_DEPTH_32,		// 16	2^4

	BUDOKAI_MATCH_DEPTH_COUNT,
	MAX_BUDOKAI_MATCH_DEPTH_INDIVIDUAL = BUDOKAI_MATCH_DEPTH_32,
	MAX_BUDOKAI_MATCH_DEPTH_TEAM = BUDOKAI_MATCH_DEPTH_16,
	INVALID_BUDOKAI_MATCH_DEPTH = 0xff,
};

enum BUDOKAI_PROGRESS_MESSAGE
{
	BUDOKAI_PROGRESS_MESSAGE_START = 0,

	BUDOKAI_PROGRESS_MESSAGE_MINORMATCH_ENTERING,
	BUDOKAI_PROGRESS_MESSAGE_MINORMATCH_BEFORE_1MIN,
	BUDOKAI_PROGRESS_MESSAGE_MINORMATCH_WINNER,
	BUDOKAI_PROGRESS_MESSAGE_MINORMATCH_LOSER,
	BUDOKAI_PROGRESS_MESSAGE_MINORMATCH_ALL_FINISHED,

	BUDOKAI_PROGRESS_MESSAGE_DEPTH_32_BEFORE_10SEC,
	BUDOKAI_PROGRESS_MESSAGE_DEPTH_32_WINNER,
	BUDOKAI_PROGRESS_MESSAGE_DEPTH_32_LOSER,
	BUDOKAI_PROGRESS_MESSAGE_DEPTH_32_ALL_FINISHED,

	BUDOKAI_PROGRESS_MESSAGE_DEPTH_16_BEFORE_10SEC,
	BUDOKAI_PROGRESS_MESSAGE_DEPTH_16_WINNER,
	BUDOKAI_PROGRESS_MESSAGE_DEPTH_16_LOSER,
	BUDOKAI_PROGRESS_MESSAGE_DEPTH_16_ALL_FINISHED,

	BUDOKAI_PROGRESS_MESSAGE_DEPTH_08_BEFORE_10SEC,
	BUDOKAI_PROGRESS_MESSAGE_DEPTH_08_WINNER,
	BUDOKAI_PROGRESS_MESSAGE_DEPTH_08_LOSER,
	BUDOKAI_PROGRESS_MESSAGE_DEPTH_08_ALL_FINISHED,

	BUDOKAI_PROGRESS_MESSAGE_SEMI_FINAL_BEFORE_10SEC,
	BUDOkAI_PROGRESS_MESSAGE_SEMI_FINAL_RUNNING,
	BUDOkAI_PROGRESS_MESSAGE_FINAL_WAIT_LOSER,

	BUDOkAI_PROGRESS_MESSAGE_END,

	INVALID_BUDOKAI_PROGRESS_MESSAGE = 0xff,
};

#define INVALID_MUDOSAPOINT INVALID_DWORD
#define MAX_MUDOSA_POINT (500000)
#define BUDOKAI_SERVER_INDEX 0
#define BUDOKAI_MAX_NOTICE_LENGTH 255
#define BUDOKAI_MAX_INDIVIDUAL_DB_DATA_PACKET_COUNT	20
#define BUDOKAI_MAX_TEAM_DB_DATA_PACKET_COUNT (int)(BUDOKAI_MAX_INDIVIDUAL_DB_DATA_PACKET_COUNT / MAX_MEMBER_IN_PARTY)
#define	BUDOKAI_MAX_TOURNAMENT_INDIVIDUAL_ENTRY_PACKET_COUNT (MAX_MEMBER_IN_PARTY * 4)
#define	BUDOKAI_MAX_TOURNAMENT_TEAM_ENTRY_PACKET_COUNT 4
#define BUDOKAI_MAX_INDIVIDUAL_REGISTER_COUNT 10000
#define BUDOKAI_MAX_TEAM_REGISTER_COUNT 2000
#define BUDOKAI_MIN_TEAM_MEMBER_COUNT 1
#define BUDOKAI_MAX_TEAM_MEMBER_COUNT MAX_MEMBER_IN_PARTY;
#define	BUDOKAI_MAX_INDIVIDUAL_MATCH_COUNT 32
#define	BUDOKAI_MAX_TEAM_MATCH_COUNT 16
#if BUDOKAI_MAX_INDIVIDUAL_MATCH_COUNT > BUDOKAI_MAX_TEAM_MATCH_COUNT
#define BUDOKAI_MAX_MATCH_COUNT BUDOKAI_MAX_INDIVIDUAL_MATCH_COUNT
#else
#define BUDOKAI_MAX_MATCH_COUNT BUDOKAI_MAX_TEAM_MATCH_COUNT
#endif
#define BUDOKAI_MINOR_MATCH_INDIVIDUAL_COUNT 15
#define BUDOKAI_MINOR_MATCH_TEAM_COUNT 5
#if BUDOKAI_MINOR_MATCH_INDIVIDUAL_COUNT > BUDOKAI_MINOR_MATCH_TEAM_COUNT
#define BUDOKAI_MAX_MINORMATCH_TEAM_COUNT BUDOKAI_MINOR_MATCH_INDIVIDUAL_COUNT
#else
#define BUDOKAI_MAX_MINORMATCH_TEAM_COUNT BUDOKAI_MINOR_MATCH_TEAM_COUNT
#endif
#define BUDOKAI_MINOR_MATCH_MAX_INDIVIDUAL_COUNT (BUDOKAI_MINOR_MATCH_INDIVIDUAL_COUNT * BUDOKAI_MAX_INDIVIDUAL_MATCH_COUNT)
#define BUDOKAI_MINOR_MATCH_MAX_TEAM_COUNT (BUDOKAI_MINOR_MATCH_TEAM_COUNT * BUDOKAI_MAX_TEAM_MATCH_COUNT)
#define BUDOKAI_MINOR_MATCH_MAX_TEAM_MEMBER_COUNT (BUDOKAI_MINOR_MATCH_MAX_TEAM_COUNT * MAX_MEMBER_IN_PARTY)
#define BUDOKAI_MAJOR_MATCH_PLAYER_NUMBER (BUDOKAI_MAX_INDIVIDUAL_MATCH_COUNT)
#define BUDOKAI_MAJOR_MATCH_TEAM_NUMBER (BUDOKAI_MAX_TEAM_MATCH_COUNT)
#define BUDOKAI_MINORMATCH_RESCUE_TIME 10
#define BUDOKAI_MINORMATCH_SELECTION_STATE_TIME 20
#define BUDOKAI_MINORMATCH_SELECTION_NUMBER 100
#define BUDOKAI_MAX_MUDOSA_INFO_COUNT 5
#define BUDOKAI_MAX_MUDOSA_PLAYER_COUNT 200
#define BUDOKAI_MAX_MUDOSA_NAME_IN_UNICODE 32
#define BUDOKAI_MAX_TOURNAMENT_INDIVIDUAL_MATCH_COUNT (BUDOKAI_MAJOR_MATCH_PLAYER_NUMBER - 1)
#define BUDOKAI_MAX_TOURNAMENT_TEAM_MATCH_COUNT (BUDOKAI_MAJOR_MATCH_TEAM_NUMBER - 1)
#define BUDOKAI_MAX_FINALMATCH_TEAM_COUNT 4
#define BUDOKAI_MAX_TOURNAMENT_INDIVIDUAL_MATCH_RECORD_COUNT (BUDOKAI_MAJOR_MATCH_PLAYER_NUMBER * 2)
#define BUDOKAI_MAX_TOURNAMENT_TEAM_MATCH_RECORD_COUNT (BUDOKAI_MAJOR_MATCH_TEAM_NUMBER * 2)
#define	BUDOKAI_MAX_SEASON_HISTORY_INDIVIAUL_WINNER_COUNT (4)
#define	BUDOKAI_MAX_SEASON_HISTORY_TEAM_WINNER_COUNT (MAX_MEMBER_IN_PARTY * 4)
#define	BUDOKAI_MAX_SEASON_HISTORY_WINNER_PLAYER_COUNT (BUDOKAI_MAX_SEASON_HISTORY_INDIVIAUL_WINNER_COUNT + BUDOKAI_MAX_SEASON_HISTORY_TEAM_WINNER_COUNT)
const BYTE BUDOkAI_MAX_PLAYER_JOIN_STATE_DATA_COUNT = 100;

enum ITEM_MIX_RESULT_TYPE
{
	ITEM_MIX_RESULT_TYPE_FAIL,
	ITEM_MIX_RESULT_TYPE_SUCCESS,
	ITEM_MIX_RESULT_TYPE_GREAT_SUCCESS,

	ITEM_MIX_RESULT_TYPE_NUMS
};

enum RECIPE_TYPE
{
	RECIPE_NORMAL,
	RECIPE_MAINWEAPON,
	RECIPE_ARMOR,
	RECIPE_ACCESSORY,
	RECIPE_SCOUTER,
	RECIPE_SUBWEAPON,

	RECIPE_INVALID = 0xFF,
};

#pragma pack(1)

struct TIME
{
	TIME()
	{
		minute = 0;
		second = 0;
	};
	WORD year;
	BYTE month;
	BYTE day;
	BYTE hour;
	BYTE minute;
	BYTE second;
};

struct SRVINFO
{
	BYTE CharServerIP[MAX_SRVADDR_SIZE + 1];
	WORD CharServerPort;
	DWORD Load;
};

struct GAMESERVER_INFO
{
	GAMESERVER_INFO() :
		serverId(INVALID_SERVERID),
		ServerStatus(SERVERSTATUS_DOWN),
		MaxLoad(0),
		Load(0)
	{
		::ZeroMemory(ServerName, sizeof(ServerName));
	};

	BYTE serverId;
	WCHAR ServerName[MAX_SERVERNAME_SIZE + 1];
	BYTE ServerStatus;
	DWORD MaxLoad;
	DWORD Load;
};

struct GAMECHANNEL_INFO
{
	GAMECHANNEL_INFO() :
		serverId(INVALID_SERVERID),
		ChannelId(INVALID_SLOTID),
		IsVisible(true),
		ServerStatus(SERVERSTATUS_DOWN),
		MaxLoad(0),
		Load(0)
	{
	};

	BYTE serverId;
	BYTE ChannelId;
	bool IsVisible;
	BYTE ServerStatus;
	DWORD MaxLoad;
	DWORD Load;
};

struct ITEMDATA
{
	unsigned int tblidx;
	BYTE Rank;
	BYTE Grade;
	BYTE BattleAttribute;
	unsigned int OptionTblidx[MAX_ITEM_OPTION];
};

struct MARKING
{
	BYTE Code;
public:
	MARKING()
		: Code(INVALID_MARKING_TYPE)
	{
	}
};

struct DOGIDATA
{
	bool IsIntialized;
	int guildId;
	BYTE Type;
	BYTE GuildColor;
	BYTE DojoColor;
};

struct CHARDATA
{
	unsigned int charId;
	WCHAR Name[MAX_CHARNAME_SIZE + 1];
	BYTE Race;
	BYTE Class;
	bool IsAdult;
	BYTE Gender;
	BYTE Face;
	BYTE Hair;
	BYTE HairColor;
	BYTE SkinColor;
	BYTE Level;
	unsigned int worldTblidx;
	unsigned int worldId;
	float PositionX;
	float PositionY;
	float PositionZ;
	DWORD Money;
	DWORD MoneyBank;
	ITEMDATA Item[EQUIP_SLOT_TYPE_COUNT];
	DWORD MapInfoId;
	bool TutorialFlag;
	MARKING Marking;
	bool NeedNameChange;
	DOGIDATA Dogi;
};

struct TODEL_CHARINFO
{
	int charId;
	DWORD PastTick;
};

struct SHORTCUT_UPDATE_DATA
{
	BYTE Type;
	WORD ActionID;
	WORD Key;
};

struct SHORTCUT_DATA
{
	WORD ActionID;
	WORD Key;
};

struct SHOP_BUYCART
{
	BYTE MerchantTab;
	BYTE ItemPos;
	BYTE Stack;
};

struct SHOP_SELLCART
{
	BYTE Place;
	BYTE Pos;
	BYTE Stack;
};

struct EMPTY_INVEN
{
	BYTE Place;
	BYTE Pos;
};

struct ITEMPOS_DATA
{
	unsigned int Item;
	BYTE Place;
	BYTE Pos;
};

struct GUILD_MARK
{
	bool IsIntialized;
	BYTE MarkMain;
	BYTE MarkMainColor;
	BYTE MarkInLine;
	BYTE MarkInColor;
	BYTE MarkOutLine;
	BYTE MarkOutColor;
};

struct GAMEMANIA_TIME_DATA
{
	DWORD SetTime;
	BYTE TimeSlot[GMT_MAX_EFFECT_LIST_SIZE][GMT_MAX_TIME_SLOT_SIZE];
};

struct GAMEMANIA_TIME
{
	BYTE TimeSlot[GMT_MAX_EFFECT_LIST_SIZE][GMT_MAX_TIME_SLOT_SIZE];
};

struct PCHAR_SHAPE
{
	BYTE Face;
	BYTE Hair;
	BYTE HairColor;
	BYTE SkinColor;
};

struct AVATAR_ATTRIBUTE
{
	BYTE BaseStr;
	BYTE LastStr;
	BYTE BaseCon;
	BYTE LastCon;
	BYTE BaseFoc;
	BYTE LastFoc;
	BYTE BaseDex;
	BYTE LastDex;
	BYTE BaseSol;
	BYTE LastSol;
	BYTE BaseEng;
	BYTE LastEng;
	WORD BaseMaxLP;
	WORD LastMaxLP;
	WORD BaseMaxEP;
	WORD LastMaxEP;
	WORD BaseMaxRP;
	WORD LastMaxRP;
	WORD BaseLpRegen;
	WORD LastLpRegen;
	WORD BaseLpSitdownRegen;
	WORD LastLpSitdownRegen;
	WORD BaseLpBattleRegen;
	WORD LastLpBattleRegen;
	WORD BaseEpRegen;
	WORD LastEpRegen;
	WORD BaseEpSitdownRegen;
	WORD LastEpSitdownRegen;
	WORD BaseEpBattleRegen;
	WORD LastEpBattleRegen;
	WORD BaseRpRegen;
	WORD LastRpRegen;
	WORD LastRpDimimutionRate;
	WORD BasePhysicalOffence;
	WORD LastPhysicalOffence;
	WORD BasePhysicalDefence;
	WORD LastPhysicalDefence;
	WORD BaseEnergyOffence;
	WORD LastEnergyOffence;
	WORD BaseEnergyDefence;
	WORD LastEnergyDefence;
	WORD BaseAttackRate;
	WORD LastAttackRate;
	WORD BaseDodgeRate;
	WORD LastDodgeRate;
	WORD BaseBlockRate;
	WORD LastBlockRate;
	WORD BaseCurseSuccessRate;
	WORD LastCurseSuccessRate;
	WORD BaseCurseToleranceRate;
	WORD LastCurseToleranceRate;
	WORD BasePhysicalCriticalRate;
	WORD LastPhysicalCriticalRate;
	WORD BaseEnergyCriticalRate;
	WORD LastEnergyCriticalRate;
	float LastRunSpeed;
	WORD BaseAttackSpeedRate;
	WORD LastAttackSpeedRate;
	float BaseAttackRange;
	float LastAttackRange;
	float CastingTimeChangePercent;
	float CoolTimeChangePercent;
	float KeepTimeChangePercent;
	float DotValueChangePercent;
	float DotTimeChangeAbsolute;
	float RequiredEpChangePercent;
	float HonestOffence;
	float HonestDefence;
	float StrangeOffence;
	float StrangeDefence;
	float WildOffence;
	float WildDefence;
	float EleganceOffence;
	float EleganceDefence;
	float FunnyOffence;
	float FunnyDefence;
	WORD ParalyzeToleranceRate;
	WORD TerrorToleranceRate;
	WORD ConfuseToleranceRate;
	WORD StoneToleranceRate;
	WORD CandyToleranceRate;
	float ParalyzeKeepTimeDown;
	float TerrorKeepTimeDown;
	float ConfuseKeepTimeDown;
	float StoneKeepTimeDown;
	float CandyKeepTimeDown;
	float BleedingKeepTimeDown;
	float PoisonKeepTimeDown;
	float StomachacheKeepTimeDown;
	float CriticalBlockSuccessRate;
	WORD GuardRate;
	float SkillDamageBlockModeSuccessRate;
	float CurseBlockModeSuccessRate;
	float KnockdownBlockModeSuccessRate;
	float HtbBlockModeSuccessRate;
	float SitDownLpRegenBonusRate;
	float SitDownEpRegenBonusRate;
	float PhysicalCriticalDamageBonusRate;
	float EnergyCriticalDamageBonusRate;
	float ItemUpgradeBonusRate;
	float ItemUpgradeBreakBonusRate;
};

struct HOIPOIMIX_DATA
{
	bool NormalStart;
	bool SpecialStart;
	BYTE SpecialType;
	BYTE MixLevel;
	DWORD MixExp;
};

struct PC_PROFILE_LOCALIZE_DEV
{
};

struct PC_PROFILE_LOCALIZE_CJIKOR
{
	DWORD netP;
};

struct PC_PROFILE_LOCALIZE
{
	BYTE type;
	union
	{
		PC_PROFILE_LOCALIZE_DEV pcProfileDev;
		PC_PROFILE_LOCALIZE_CJIKOR pcProfileCJKor;
	};
};

struct PCHAR_PROFILE
{
	unsigned int tblidx;
	bool IsAdult;
	bool ChangeClass;
	unsigned int charId;
	WCHAR Name[MAX_CHARNAME_SIZE + 1];
	PCHAR_SHAPE CharShape;
	AVATAR_ATTRIBUTE avatarAttribute;
	WORD CurLP;
	WORD CurEP;
	WORD CurRP;
	BYTE Level;
	DWORD CurExp;
	DWORD MaxExpInThisLevel;
	DWORD Zenny;
	DWORD TutorialHint;
	BYTE BindType;
	unsigned int bindWorldId;
	unsigned int bindObjectTblidx;
	DWORD Reputation;
	DWORD MudosaPoint;
	DWORD SpPoint;
	MARKING	Marking;
	HOIPOIMIX_DATA MixData;
	bool IsGameMaster;
	unsigned int guildId;
	PC_PROFILE_LOCALIZE Localize;
};

struct CHARSTATE_SPAWNING
{
	BYTE TeleportType;
};

struct CHARSTATE_DESPAWNING
{
	BYTE TeleportType;
};

struct CHARSTATE_STANDING
{
};

struct CHARSTATE_SITTING
{
};

struct CHARSTATE_FAINTING
{
	BYTE Reason;
};

struct CHARSTATE_CAMPING
{
};

struct CHARSTATE_LEAVING
{
	BYTE LeavingType;
};

struct CHARSTATE_MOVING
{
	DWORD TimeStamp;
	BYTE MoveFlag;
	BYTE MoveDirection;
};

struct CHARSTATE_DESTMOVE
{
	DWORD TimeStamp;
	BYTE MoveFlag;
	bool HaveSecondDestLoc;
	VECTORXYZ SecondDestLoc;
	BYTE DestLocCount;
	VECTORXYZ DestLoc[MAX_NEXTDESTLOC_COUNT];
};

struct CHARSTATE_FOLLOWING
{
	DWORD TimeStamp;
	BYTE MoveFlag;
	unsigned int Target;
	float Distance;
	BYTE MovementReason;
};

struct CHARSTATE_FALLING
{
	BYTE MoveDirection;
};

struct CHARSTATE_DASH_PASSIVE
{
	DWORD TimeStamp;
	BYTE MoveDirection;
	VECTORXYZ DestLoc;
};

struct CHARSTATE_TELEPORTING
{
	BYTE TeleportType;
};

struct CHARSTATE_SLIDING
{
	VECTORXYZ Shift;
};

struct CHARSTATE_KNOCKDOWN
{
	VECTORXYZ Shift;
};

struct CHARSTATE_FOCUSING
{
};

struct CHARSTATE_CASTING
{
	unsigned int skillId;
	unsigned int Target;
	DWORD CastingTime;
	DWORD CastingTimeRemaining;
};

struct CHARSTATE_SKILL_AFFECTING
{
	unsigned int skillId;
	unsigned int Target;
};

struct CHARSTATE_KEEPING_EFFECT
{
};

struct CHARSTATE_CASTING_ITEM
{
	unsigned int itemTblidx;
	unsigned int Target;
	DWORD CastingTime;
	DWORD CastingTimeRemaining;
};

struct CHARSTATE_STUNNED
{
	BYTE StunType;
};

struct CHARSTATE_SLEEPING
{
};

struct CHARSTATE_PARALYZED
{
};

struct SKILL_DATA
{
	BYTE Slot;
	unsigned int skillId;
	int RemainSec;
	int Exp;
	BYTE yRpBonusType;
	bool IsRpBonusAuto;
};

struct BUFF_DATA
{
	unsigned int sourceTblidx;
	BYTE SourceType;
	DWORD InitialDuration;
	DWORD TimeRemaining;
	int Argument1;
	int Argument2;
	float EffectValue1;
	float EffectValue2;
	BYTE BuffGroup;
};


struct PET_BUFF_DATA
{
	BYTE AvatarType;
	BYTE SourceType;
	unsigned int sourceTblidx;
	DWORD InitialDuration;
	DWORD TimeRemaining;
	int Argument1;
	int Argument2;
	float EffectValue1;
	float EffectValue2;
};

struct HTB_SKILL_DATA
{
	unsigned int skillId;
	int SkillTime;
};

struct SKILL_INFO
{
	unsigned int tblidx;
	DWORD TimeRemaining;
	int Exp;
	BYTE SlotId;
	BYTE RpBonusType;
	bool IsRpBonusAuto;
};

struct SKILL_INFO_PET
{
	unsigned int tblidx;
	BYTE SlotIndex;
};


struct BUFF_INFO
{
	unsigned int sourceTblidx;
	BYTE SourceType;
	DWORD InitialDuration;
	DWORD TimeRemaining;
	float EffectValue[MAX_EFFECTSKILL];
};

struct HTB_SKILL_INFO
{
	unsigned int skillId;
	BYTE SlotId;
	DWORD TimeRemaining;
};

struct SYSTEM_EFFECT_RESULT
{
	SYSTEM_EFFECT_RESULT_TYPE ResultType;
	union
	{
		float ResultValue;

		// DH/HOT
		struct
		{
			float DH_HOT_fHealAmount;
		};

		// DD/DOT
		struct
		{
			float DD_DOT_fDamage;
			float DD_DOT_fAbsorbedDamage;
			float DD_DOT_fReflectedDamage;
		};

		// ACTIVE_LP_STEAL, ACTIVE_EP_STEAL, ACTIVE_LP_STEAL_OVER_TIME, ACTIVE_EP_STEAL_OVER_TIME
		struct
		{
			float LP_EP_STEAL_fLpDamage;
			float LP_EP_STEAL_fEpDamage;
			float LP_EP_STEAL_fAbsorbedDamage;
			float LP_EP_STEAL_fReflectedDamage;
			float LP_EP_STEAL_fLpGained;
			float LP_EP_STEAL_fEpGained;
		};
	};
};

struct SKILL_RESULT
{
	unsigned int Target;
	BYTE AttackResult;
	SYSTEM_EFFECT_RESULT effectResult1;
	SYSTEM_EFFECT_RESULT effectResult2;
	BYTE BlockedAction;
	VECTORXYZ Shift;
};

struct HTBSKILL_RESULT
{
	BYTE Step;
	SKILL_RESULT SkillResult;
};

struct CHARSTATE_HTB
{
	unsigned int HTBId;
	unsigned int Target;
	BYTE StepCount;
	BYTE CurStep;
	BYTE ResultCount;
	HTBSKILL_RESULT	HTBSkillResult[MAX_HTBSKILL_COUNT];
};

struct CHARSTATE_SANDBAG
{
};

struct CHARSTATE_CHARGING
{
};

struct CHARSTATE_BLOCKING
{
};

struct SUMMARY_PRIVATESHOP_DATA
{
	bool IsOwnerEmpty;
	BYTE  ShopState;
	WCHAR PrivateShopName[MAX_PRIVATESHOPNAME_USIZE + 1];
};

struct CHARSTATE_PRIVATESHOP
{
	SUMMARY_PRIVATESHOP_DATA SummaryPrivateShopData;
};

struct CHARSTATE_DIRECT_PLAY
{
	BYTE DirectPlayType;
	unsigned int directTblidx;
};

struct CHARSTATE_OPERATING
{
	unsigned int TargetObject;
	DWORD OperateTime;
	unsigned int directTblidx;
};

struct CHARSTATE_RIDEON
{
	unsigned int Target;
};

struct CHARSTATE_TURNING
{
	unsigned int directTblidx;
	VECTORXYZ DestDir;
};

struct ASPECTSTATE_SUPER_SAIYAN
{
	BYTE SourceGrade;
};

struct ASPECTSTATE_PURE_MAJIN
{
	BYTE SourceGrade;
};

struct ASPECTSTATE_GREAT_NAMEK
{
	BYTE SourceGrade;
};

struct ASPECTSTATE_KAIOKEN
{
	BYTE SourceGrade;
	BYTE RepeatingCount;
};

struct ASPECTSTATE_SPINNING_ATTACK
{
};

struct ASPECTSTATE_VEHICLE
{
	unsigned int idVehicleTblidx;
	bool IsEngineOn;
};

struct ASPECTSTATE_BASE
{
	BYTE AspectStateId;
};

union ASPECTSTATE_DETAIL
{
	ASPECTSTATE_SUPER_SAIYAN SuperSaiyan;
	ASPECTSTATE_PURE_MAJIN PureMajin;
	ASPECTSTATE_GREAT_NAMEK GreatNamek;
	ASPECTSTATE_KAIOKEN Kaioken;
	ASPECTSTATE_SPINNING_ATTACK SpinningAttack;
	ASPECTSTATE_VEHICLE Vehicle;
};

struct ASPECTSTATE
{
	ASPECTSTATE_BASE AspectStateBase;
	ASPECTSTATE_DETAIL AspectStateDetail;
};

struct CHARSTATE_BASE
{
	BYTE StateID;
	DWORD StateTime;
	DWORD ConditionFlag;
	ASPECTSTATE	aspectState;
	bool FightMode : 1;
	VECTORXYZ CurLoc;
	VECTORXYZ CurDir;
};

union CHARSTATE_DETAIL
{
	CHARSTATE_SPAWNING CharStateSpawning;
	CHARSTATE_DESPAWNING CharStateDespawning;
	CHARSTATE_STANDING CharStateStanding;
	CHARSTATE_SITTING CharStateSitting;
	CHARSTATE_FAINTING CharStateFainting;
	CHARSTATE_CAMPING CharStateCamping;
	CHARSTATE_LEAVING CharStateLeaving;
	CHARSTATE_MOVING CharStateMoving;
	CHARSTATE_DESTMOVE CharStateDestMove;
	CHARSTATE_FOLLOWING	CharStateFollwing;
	CHARSTATE_FALLING CharStateFalling;
	CHARSTATE_DASH_PASSIVE CharStateDashPassive;
	CHARSTATE_TELEPORTING CharStateTeleporting;
	CHARSTATE_SLIDING CharStateSliding;
	CHARSTATE_KNOCKDOWN CharStateKnockdown;
	CHARSTATE_FOCUSING CharStateFocusing;
	CHARSTATE_CASTING CharStateCasting;
	CHARSTATE_SKILL_AFFECTING CharStateSkillAffecting;
	CHARSTATE_KEEPING_EFFECT CharStateKeepingEffect;
	CHARSTATE_CASTING_ITEM CharStateCastingItem;
	CHARSTATE_STUNNED CharStateStunned;
	CHARSTATE_SLEEPING CharStateSleeping;
	CHARSTATE_PARALYZED CharStateParalyzed;
	CHARSTATE_HTB CharStateHTB;
	CHARSTATE_SANDBAG CharStateSandBag;
	CHARSTATE_CHARGING CharStateCharging;
	CHARSTATE_PRIVATESHOP CharStatePrivateShop;
	CHARSTATE_DIRECT_PLAY CharStateDirectPlay;
	CHARSTATE_OPERATING CharStateOperating;
	CHARSTATE_RIDEON CharStateRideOn;
	CHARSTATE_TURNING CharStateTurning;
};

struct CHARSTATE
{
	CHARSTATE_BASE CharStateBase;
	CHARSTATE_DETAIL CharStateDetail;
};

struct ITEM_PROFILE
{
	unsigned int handle;
	unsigned int tblidx;
	BYTE Place;
	BYTE Pos;
	BYTE Stackcount;
	BYTE Rank;
	BYTE CurDur;
	bool NeedToIdentify;
	BYTE Grade;
	BYTE BattleAttribute;
	BYTE RestrictType;
	WCHAR Maker[MAX_CHARNAME_SIZE + 1];
	unsigned int OptionTblidx[MAX_ITEM_OPTION];
	BYTE DurationType;
	time_t UseStartTime;
	time_t UseEndTime;
};

struct TIMEQUEST_STAGE
{
	BYTE StageNumber;
};

struct TIMEQUEST_STATE
{
	BYTE GameState;
	TIMEQUEST_STAGE TimeQuestStage;
};

struct TIMEQUEST_RULE_INFO
{
	unsigned int timeQuestTblidx;
	BYTE StartHour;
	BYTE StartMin;
	BYTE TimeQuestMode;
	BYTE Difficulty;
	bool CountDown;
	DWORD LimitTime;
	DWORD BonusTime;
	DWORD DayRecord; 
	TIMEQUEST_STATE TimeQuestState;
};

struct GAME_RULE_INFO
{
	BYTE RuleType;
	union
	{
		TIMEQUEST_RULE_INFO	TimeQuestRuleInfo;
	};
};


struct WORLD_INFO
{
	unsigned int worldID;
	unsigned int tblidx;
	unsigned int TriggerObjectOffset;
	GAME_RULE_INFO RuleInfo;
};

struct WORLD_ZONE_INFO
{
	unsigned int zoneId;
	bool IsDark;
};

struct DOJO_BRIEF
{
	unsigned int guildId;
	unsigned int dojoTblidx;
	BYTE Level;
	GUILD_MARK Mark;
};

struct COMPLETE_QUEST_INFO
{
	BYTE QCInfo[QUEST_ID_RANGE_QUEST_MAX / COMPLETE_QUEST_QUEST_PER_BYTE];
};

struct COMPLETE_QUEST_BIT_INFO
{
	BYTE QCBitInfo[COMPLETE_QUEST_QUEST_PER_STRUCT / COMPLETE_QUEST_QUEST_PER_BYTE];
};

struct COMPLETE_QUEST_TOTAL_BIT_INFO
{
	COMPLETE_QUEST_BIT_INFO QCBitInfo[COMPLETE_QUEST_QUEST_STRUCT_COUNT]; 
};

struct MAIN_TSP
{
	BYTE CurId;
	BYTE PreId;
};

struct EXCEPT_TIMER
{
	BYTE tcId;
	BYTE taId;
	unsigned int uiRemainTime;
};

struct EXCEPT_TIMER_SLOT
{
	EXCEPT_TIMER ExceptTimer[4];
};

struct STORAGE_SLOT_MEMORY
{
	unsigned int uiSSM[8];
};

struct STOC_EVT_DB_DATA
{
	BYTE tcId;
	BYTE taId;
	unsigned int m_aUserData[4];
	void Init(void)
	{
		tcId = taId = 0xFF;
		memset(m_aUserData, 0, sizeof(m_aUserData));
	}
};

struct PROGRESS_QUEST_INFO
{
	PROGRESS_QUEST_INFO(void)
	{
		Ver = 0;
		Id = 0xFF;
		memset(&Data.QInfoV0, 0xff, sizeof(Data.QInfoV0));
		Data.QInfoV0.QState = 0;
		Data.QInfoV0.tcQuestInfo = 0xFF;
		Data.QInfoV0.taQuestInfo = 0xFF;
	}
	BYTE Ver;
	BYTE Id;
	union DATA
	{
		struct EXTENDED_POSSIBLE_V0
		{
			WORD QState;
			MAIN_TSP MainTSP;
			EXCEPT_TIMER_SLOT ETSlot;
			STORAGE_SLOT_MEMORY SSM;
			STOC_EVT_DB_DATA SToCEvtData;
			BYTE tgExcCGroup;
			BYTE tcQuestInfo;
			BYTE taQuestInfo;
		};
		EXTENDED_POSSIBLE_V0 QInfoV0;
	};
	DATA Data;
};

struct QUESTITEM_DATA
{
	unsigned int tblidx;
	BYTE CurStackCount;
	BYTE Pos;
};

struct PCHAR_BRIEF
{
	unsigned int charId;
	unsigned int tblidx;
	bool IsAdult;
	WCHAR Name[MAX_CHARNAME_SIZE + 1];
	WCHAR GuildName[MAX_GUILDNAME_USIZE + 1];
	PCHAR_SHAPE PcShape;
	WORD CurLP;
	WORD MaxLP;
	WORD CurEP;
	WORD MaxEP;
	BYTE Level;
	float Speed;
	ITEMDATA ItemBrief[EQUIP_SLOT_TYPE_COUNT];
	WORD AttackSpeedRate;
	GUILD_MARK Mark;
	MARKING Marking;
	DOGIDATA Dogi;
};

struct BOT_DATA
{
	unsigned int tblidx;
	unsigned int worldID;
	VECTORXYZ CurLoc;
	VECTORXYZ CurDir;
	VECTORXYZ SpawnLoc;
	VECTORXYZ SpawnDir;
	BYTE SpawnRange;
	WORD SpawnTime;
	BYTE SpawnFuncFlag;
	BYTE MoveType; 
	BYTE WanderRange;
	BYTE MoveRange;
	BYTE MoveDelayTime;
	unsigned int actionpatternTblIdx;
	unsigned int pathTblidx;
	unsigned int playScript;
	unsigned int playScriptScene;
	unsigned int tblidxAiScript;
	unsigned int tblidxAiScriptScene;
	unsigned int partyID;
	bool PartyLeader;
	VECTORXYZ PartyLeaderDistance;
	DWORD CharConditionFlag;
};

struct BOT_BRIEF
{
	unsigned int tblidx;
	WORD CurLP;
	WORD CurEP;
	WORD MaxLP;
	WORD MaxEP;
	float LastWalkingSpeed;
	float LastRunningSpeed;
	WORD AttackSpeedRate;
	unsigned int actionpatternTblIdx;
};

struct BOT_PROFILE
{
	unsigned int tblidx;
	unsigned int worldID;
	VECTORXYZ SpawnLoc;
	VECTORXYZ SpawnDir;
	BYTE SpawnRange;
	WORD SpawnTime;
	BYTE SpawnFuncFlag;
	BYTE MoveType;
	BYTE WanderRange;
	BYTE MoveRange;
	BYTE MoveDelayTime;
	unsigned int actionpatternTblIdx;
	unsigned int pathTblidx;
	unsigned int playScript;
	unsigned int playScriptScene;
	unsigned int tblidxAiScript;
	unsigned int tblidxAiScriptScene;
	unsigned int partyID;
	bool PartyLeader;
	VECTORXYZ PartyLeaderDistance;
	WORD CurLP;
	WORD MaxLP;
	float LastWalkingSpeed;
	float LastRunningSpeed;
};

struct NPC_DATA : public BOT_DATA
{
};

struct NPC_BRIEF : public BOT_BRIEF
{
	unsigned int nicknameTblidx;
};

struct NPC_PROFILE : public BOT_PROFILE
{
};

struct MOB_DATA : public BOT_DATA
{
	unsigned int spawnGroupId;
};

struct MOB_BRIEF : public BOT_BRIEF
{
	BYTE BallType;
};

struct MOB_PROFILE : public BOT_PROFILE
{
	unsigned int spawnGroupId;
};

struct PET_DATA
{
	BYTE PetIndex;
	BYTE SourceType;
	unsigned int sourceTblidx;
};

struct PET_BRIEF
{
	BYTE SourceType;
	unsigned int sourceTblidx;
	unsigned int npcTblidx;
	unsigned int Owner;
	float LastRunningSpeed;
};

struct PET_PROFILE
{
	BYTE SourceType;
	unsigned int sourceTblidx;
	unsigned int npcTblidx;
	unsigned int Owner;
	BYTE AvatarType;
	AVATAR_ATTRIBUTE attribute;
};

struct SUMMON_PET_DATA : public PET_DATA
{
	WORD CurLP;
	WORD CurEP;
};

struct SUMMON_PET_BRIEF : public PET_BRIEF
{
	WORD CurLP;
	WORD CurEP;
	WORD MaxLP;
	WORD MaxEP;
	WORD AttackSpeedRate;
};

struct SUMMON_PET_PROFILE : public PET_PROFILE
{
	WORD CurLP;
	WORD CurEP;
};

struct ITEM_PET_DATA : public PET_DATA
{
	unsigned int itemId;
};

struct ITEM_PET_BRIEF : public PET_BRIEF
{
};

struct ITEM_PET_PROFILE : public PET_PROFILE
{
};

struct ITEM_DATA
{
	unsigned int itemId;
	unsigned int itemNo;
	unsigned int charId;
	BYTE Place;
	BYTE Position;
	BYTE Stackcount;
	BYTE Rank;
	BYTE CurrentDurability;
	bool NeedToIdentify;
	BYTE Grade;
	BYTE BattleAttribute;
	BYTE RestrictType;
	WCHAR Maker[MAX_CHARNAME_SIZE + 1];
	unsigned int aOptionTblidx[MAX_ITEM_OPTION];
	BYTE DurationType;
	time_t UseStartTime;
	time_t UseEndTime;

};

struct ITEM_DURATION
{
	unsigned int itemID;
	BYTE Place;
	BYTE Position;
	time_t UseEndTime;
};

struct ITEM_BRIEF
{
	unsigned int tblidx;
	BYTE Rank;
	BYTE Grade;
	BYTE BattleAttribute;
	unsigned int aOptionTblidx[MAX_ITEM_OPTION];
};

struct ITEM_SUMMARY
{
	unsigned int tblidx;
	BYTE Rank;
	BYTE Grade;
	BYTE BattleAttribute;
	unsigned int aOptionTblidx[MAX_ITEM_OPTION];
};

struct ITEM_STATE
{
	VECTORXYZ CurLoc;
	bool NeedToIdentify;
	bool IsNew;
};

struct MONEY_BRIEF
{
	DWORD Zenny;
};

struct MONEY_STATE
{
	VECTORXYZ CurLoc;
	bool IsNew;
};

struct ITEM_DELETE_DATA
{
	BYTE Place;
	BYTE Pos;
	unsigned int Item;
	unsigned int itemId;
	unsigned int tblidx;	
};

struct TOBJECT_BRIEF
{
	unsigned int objectID;
};

struct TOBJECT_STATE
{
	BYTE State;
	BYTE SubStateFlag;
	DWORD StateTime;	
};

struct DYNAMIC_OBJECT_BRIEF
{
	BYTE ObjectType;
	unsigned int idObjectTblidx;
	unsigned int Owner;
};


struct DYNAMIC_OBJECT_STATE
{
	BYTE State;
	VECTORXYZ CurLoc;
};

struct OBJECT_INFO
{
	BYTE objType;
	union
	{
		struct // pc
		{
			PCHAR_BRIEF pcBrief;
			CHARSTATE pcState;
		};
		struct // npc
		{
			NPC_BRIEF npcBrief;
			CHARSTATE npcState;
		};
		struct // mob
		{
			MOB_BRIEF mobBrief;
			CHARSTATE mobState;
		};
		struct // summon pet
		{
			SUMMON_PET_BRIEF summonPetBrief;
			CHARSTATE summonPetState;
		};
		struct // item pet
		{
			ITEM_PET_BRIEF itemPetBrief;
			CHARSTATE itemPetState;
		};
		struct // item
		{
			ITEMDATA itemBrief;
			ITEM_STATE itemState;
		};
		struct // money
		{
			MONEY_BRIEF	moneyBrief;
			MONEY_STATE	moneyState;
		};
		struct // trigger object
		{
			TOBJECT_BRIEF tobjectBrief;
			TOBJECT_STATE tobjectState;
		};
		struct // dynamic object
		{
			DYNAMIC_OBJECT_BRIEF dynamicObjBrief;
			DYNAMIC_OBJECT_STATE dynamicObjState;
		};
	};
};

struct NEWBIE_QUICKSLOT_DATA
{
	unsigned int tblidx;
	BYTE Type;
	BYTE QuickSlot;
};

struct RANKBATTLE_SCORE_INFO
{
	WORD MaxStraightWin;
	WORD StraightWin;
	WORD MaxStraightKOWin;
	WORD StraightKOWin;
	DWORD Win;
	DWORD Draw;	
	DWORD Lose;
	float Point;
};

struct PARTY_MEMBER_INFO
{
	unsigned int Handle;
	WCHAR MemberName[MAX_CHARNAME_SIZE + 1];
	BYTE Race;
	BYTE Class;
	BYTE Level;
	WORD CurLP;
	WORD MaxLP;
	WORD CurEP;
	WORD MaxEP;
	DWORD Zenny;
	unsigned int worldTblidx;
	unsigned int worldId;
	VECTORXYZ CurLoc;
};

struct VICTIM_ITEM_DATA
{
	unsigned int charId;
	BYTE Place;
	BYTE Pos;
	unsigned int Item;
	unsigned int itemId;
};

struct PARTY_VICTIM_ITEM_INFO
{
	BYTE SlotIndex;
	unsigned int itemTblidx;
};

struct ZENNY_DATA
{
	unsigned int memberCharId;
	DWORD Zenny;
};

struct INVEST_ZENNY_INFO
{
	unsigned int Member;
	DWORD Zenny;
};

struct PARTY_INVENTORY_ITEM_INFO
{
	unsigned int tblidx;
	// byStackCount, byRank, byGrade and option's values are meaningless if bNeedToIdentify is true.
	BYTE StackCount;
	BYTE Rank;
	BYTE Grade;
	bool NeedToIdentify;
	BYTE BattleAttribute;
	unsigned int OptionTblidx[MAX_ITEM_OPTION];
};

struct PARTY_INVENTORY_SLOT_INFO
{
	BYTE SlotIndex;
	PARTY_INVENTORY_ITEM_INFO itemInfo;
};

struct VICTIM_INFO
{
	unsigned int Member;
	DWORD Zenny;
};

struct sDBO_VICTIM_DATA
{
	unsigned int charId;
	DWORD Zenny;
};

struct ZENNY_INFO
{
	unsigned int charId;
	DWORD Zenny; // dwOrgZenny + dwBonusZenny
	DWORD OrgZenny;
	DWORD BonusZenny;
};

struct SHARETARGET_INFO
{
	unsigned int Target;
	public:
	SHARETARGET_INFO() : Target(INVALID_OBJECT){}
};

union STOC_EVT_UPDATE_DATA
{
	struct MOB_KILL_CNT
	{
		int CurMobCnt;
	};

	struct MOB_KILL_ITEM_CNT
	{
		int CurMobLICnt;
	};

	struct DELIVERY_ITEM
	{
		int CurItemCnt;
	};

	struct OBJECT_ITEM
	{
		int CurItemCnt;
	};

	struct PUBLIC_MOB_ITEM_CNT
	{
		int CurItemCnt;
	};

	struct CUSTOM_EVT_CNT
	{
		int CurCnt;
	};

	struct VISIT_EVT
	{
		bool Completed;
	};


	MOB_KILL_CNT MobKillCnt;
	MOB_KILL_ITEM_CNT MobKillItemCnt;
	DELIVERY_ITEM DeliveryItemCnt;
	OBJECT_ITEM	ObjectItemCnt;
	PUBLIC_MOB_ITEM_CNT PublicMobItemCnt;
	CUSTOM_EVT_CNT CustomEvtCnt;
	VISIT_EVT VisitEvt;
};

struct QUICK_SLOT_DATA
{
	unsigned int tblidx;
	BYTE Slot;
	BYTE Type;
	unsigned int itemID;
	unsigned int Item;
};

struct QUICK_SLOT_PROFILE
{
	unsigned int tblidx;
	BYTE Slot;
	BYTE Type;
	unsigned int Item;
};

struct TIMEQUEST_ROOM_MEMBER
{
	unsigned int handle;
	WCHAR Name[MAX_CHARNAME_SIZE + 1];
	BYTE Class;
};

struct TIMEQUEST_ROOM_MEMBER_INFO
{
	BYTE MemberCount;
	TIMEQUEST_ROOM_MEMBER RoomMember[TIMEQUEST_MAX_MEMBER_COUNT];
};

struct TIMEQUEST_ROOM_PARTY_INFO
{
	WCHAR Name[MAX_PARTYNAME_SIZE + 1];
};

struct TIMEQUEST_ROOM
{
	unsigned int roomID;
	unsigned int timeQuestTblidx;
	DWORD RemainSec;
	BYTE StartHour;
	BYTE StartMin;
	BYTE RoomMode;
	BYTE Difficulty; 
	BYTE RoomState; 	
};

struct TIMEQUEST_TIME
{
	void NextTime(BYTE TermMinute)
	{
		Hour = Hour + (BYTE)(TermMinute / 60);
		Minute += TermMinute % 60;

		if (60 <= Minute)
		{
			Minute -= 60;
			Hour++;
		}

		if (24 < Hour)
		{
			Hour -= 24;
		}
	}

	void NextBySec(DWORD TermSec)
	{
		NextTime((BYTE)(TermSec / 60));
	}

	BYTE Hour;
	BYTE Minute;
};

struct TIMEQUEST_ROOM_TMQ_INFO
{
	unsigned int tmqTblidx;
	BYTE Difficult;	
	TIMEQUEST_TIME CurTime;
	TIMEQUEST_TIME NextEnterTime;
	WORD WaitPartyCount;
	WORD WaitIndividualCount;
};

struct TIMEQUEST_ROOM_JOIN_INFO
{
	unsigned int tmqTblidx;
	unsigned int roomId;
	BYTE RoomState;
	BYTE TimeQuestMode;	
	DWORD RemainTime;
	BYTE Difficult;	
	WORD WaitPartyCount;
	WORD WaitIndividualCount;
};

struct TIMEQUEST_ROOM_REGISTRATION_ICON_INFO
{
	WORD WaitPartyCount;
	WORD WaitIndividualCount;
};

struct TIMEQUEST_ROOM_WAITENTRY_ICON_INFO
{
	BYTE HaveItem;
};

union TIMEQUEST_ROOM_ICON_INFO
{
	TIMEQUEST_ROOM_REGISTRATION_ICON_INFO RegistrationInfo;	// eTIMEQUEST_ROOM_STATE == TIMEQUEST_ROOM_STATE_REGISTRAITION
	TIMEQUEST_ROOM_WAITENTRY_ICON_INFO WaitEntryInfo;		// eTIMEQUEST_ROOM_STATE == TIMEQUEST_ROOM_STATE_WAITENTRY
};

struct TIMEQUEST_ROOM_ENTRY_INFO
{
	DWORD ReaminEntryTime;
	bool HaveItem;
};

struct TIMEQUEST_ROOM_NEXT_TMQ_INFO
{
	unsigned int tmqTblidx;
	TIMEQUEST_TIME NextTMQTime;
};

union TIMEQUEST_ROOM_SELECTION_INFO
{
	TIMEQUEST_ROOM_ENTRY_INFO EntryInfo;
	TIMEQUEST_ROOM_NEXT_TMQ_INFO NextTmqInfo;
};

struct TIMEQUEST_DAYRECORD_DATA
{
	BYTE Difficult;
	DWORD ClearTime;
	BYTE MemberCount;
	unsigned int MemberCharId[MAX_MEMBER_IN_PARTY];
};

struct RANKBATTLE_ARENA_INFO
{
	unsigned int rankBattleTblidx;
	WORD RegisterCount;
};

struct RANKBATTLE_ROOMLIST_INDIVIDUAL
{
	unsigned int roomId;
	WCHAR OwnerPc[MAX_CHARNAME_SIZE + 1];
	WORD WinCounter;
};

struct RANKBATTLE_ROOMLIST_PARTY
{
	unsigned int roomId;
	WCHAR OwnerParty[MAX_PARTYNAME_SIZE + 1];
	WORD WinCounter;
};

struct RANKBATTLE_ROOMINFO_MEMBER
{
	WCHAR Name[MAX_CHARNAME_SIZE + 1];
	BYTE Class;
	BYTE Level;
};

struct RANKBATTLE_ROOMINFO_INDIVIDUAL
{
	unsigned int rankBattleTblidx;
	unsigned int roomId;
	WORD WinCount;
	RANKBATTLE_ROOMINFO_MEMBER Member;
};

struct RANKBATTLE_ROOMINFO_PARTY
{
	unsigned int rankBattleTblidx;
	unsigned int roomId;
	WORD WinCount;
	WCHAR PartyName[MAX_PARTYNAME_SIZE + 1];
	BYTE MemberCount;
	RANKBATTLE_ROOMINFO_MEMBER	Member[MAX_MEMBER_IN_PARTY];
};

union RANKBATTLE_ROOMINFO
{
	RANKBATTLE_ROOMINFO_INDIVIDUAL Individual;
	RANKBATTLE_ROOMINFO_PARTY Party;
};

union RANKBATTLE_ROOMINFO_LIST
{
	RANKBATTLE_ROOMLIST_INDIVIDUAL IndividualRoom[RANKBATTLE_MAX_ROOM_COUNT_PER_PAGE];
	RANKBATTLE_ROOMLIST_PARTY PartyRoom[RANKBATTLE_MAX_ROOM_COUNT_PER_PAGE];
};

struct RANKBATTLE_MEMBER_RESULT
{
	unsigned int Pc;
	WORD ResultCode;
};

struct RANKBATTLE_MATCH_MEMBER_INFO
{
	unsigned int Pc;
	BYTE Team;
	BYTE State;
};

struct RANKBATTLE_SCORE
{
	BYTE Owner;
	BYTE Challenger;
};

struct RANKBATTLE_POINT
{
	float Owner;
	float Challenger;
};

struct RANKBATTLE_MATCH_FINISH_INFO
{
	struct WINER_RECORD
	{
		WORD StraightKOWinCount;
		WORD StraightWinCount;
	};

	struct TEAM_MATCH_FINISH_INFO
	{
		BYTE Score;
		float Point;
		float BonusPoint;
		WORD WinCount;
		WORD DrawCount;
		WORD LoseCount;
	};
	BYTE MatchWinner;
	WINER_RECORD WinerRecord;
	TEAM_MATCH_FINISH_INFO OwnerInfo;
	TEAM_MATCH_FINISH_INFO ChallengerInfo;
};

struct RANKBATTLE_RANK_DATA
{
	WCHAR CharName[MAX_CHARNAME_SIZE];
	BYTE Level;
	BYTE Class;
	WCHAR GuildName[MAX_GUILDNAME_USIZE];
	int Point;
	WORD StraightWinCount;
	DWORD CompareRank[RANKBATTLE_MAX_COMPARE_DAY];
};

struct RANKBATTLE_RANK_INFO
{
	WORD CharName; 
	BYTE yLevel;
	BYTE Class;
	WORD GuildName;
	int Point;
	WORD StraightWinCount;
	DWORD CompareRank;
};

struct sVARIABLE_DATA
{
protected:
	WORD	wReserveSize;
	WORD	wOffset;
	BYTE	abyData[1];
public:
	sVARIABLE_DATA() : wOffset(0), wReserveSize(1){}
	sVARIABLE_DATA(WORD wReserve) : wOffset(0)
	{
		Init(wReserve);
	}
	void Init(WORD wReserve)
	{
		wOffset = 0;
		if (wReserve >= 4096/*PACKET_MAX_SIZE*/)
		{
			_ASSERT(0);

			wReserveSize = 0;
			return;
		}
		wReserveSize = wReserve;
		::memset(abyData, 0xff, sizeof(BYTE) * wReserve);
	}
	void InitPacketSize(WORD wDefaultPacketSize)
	{
		wOffset = 0;
		wReserveSize = 4096 - wDefaultPacketSize + sizeof(BYTE);
		if (wReserveSize >= 4096)
		{
			_ASSERT(0);

			wReserveSize = 0;
			return;
		}
		::memset(abyData, 0xff, sizeof(BYTE) * wReserveSize);
	}
	WORD GetPacketSize(WORD wDefaultPacketSize) { return wDefaultPacketSize - sizeof(BYTE) + GetDataSize(); }
	WORD GetTotalSize() { return wOffset + sizeof(sVARIABLE_DATA) - sizeof(BYTE); }
	WORD GetDataSize() { return wOffset; }
	void WriteLock() { wReserveSize = GetDataSize(); }
	void __SetData(WORD wOff, BYTE * pData)
	{
		wOffset = wOff;
		::memcpy(abyData, pData, wOff);
	}
	bool CopyTo(sVARIABLE_DATA * pData, WORD wReserve)
	{
		if (NULL == pData)
		{
			return false;
		}
		if (wReserve < GetDataSize())
		{
			return false;
		}
		pData->__SetData(wOffset, abyData);
		pData->WriteLock();
		return true;
	}
	WORD Write(WORD wSize, void * pData)
	{
		WORD wTemp = wOffset;

		if (127 >= wSize)
		{
			if (wOffset + wSize + 1 > wReserveSize)
			{
				return INVALID_WORD;
			}
			abyData[wOffset] = (BYTE)wSize;
			::memcpy(&(abyData[wOffset + 1]), pData, wSize);
			wOffset += wSize + 1;
		}
		else
		{
			if (wOffset + wSize + 2 > wReserveSize)
			{
				return INVALID_WORD;
			}
			abyData[wOffset] = (BYTE)((wSize % 0x80) | 0x80);
			abyData[wOffset + 1] = (BYTE)(wSize >> 7);	
			::memcpy(&(abyData[wOffset + 2]), pData, wSize);
			wOffset += wSize + 2;
		}

		return wTemp;
	}
	WORD Malloc(WORD wSize)
	{
		WORD wTemp = wOffset;
		if (127 >= wSize)
		{
			if (wOffset + wSize + 1 > wReserveSize)
			{
				return INVALID_WORD;
			}
			abyData[wOffset] = (BYTE)wSize;
			wOffset += wSize + 1;
		}
		else	
		{
			if (wOffset + wSize + 2 > wReserveSize)
			{
				return INVALID_WORD;
			}
			abyData[wOffset] = (BYTE)((wSize % 0x80) | 0x80);
			abyData[wOffset + 1] = (BYTE)(wSize >> 7);
			wOffset += wSize + 2;
		}
		return wTemp;
	}
	WORD GetSize(WORD wReadLoc)
	{
		if (wReadLoc >= wOffset)
		{
			return 0;
		}
		if (0x80 & abyData[wReadLoc])
		{
			if (wReadLoc + 1 >= wOffset)
			{
				return 0;
			}
			WORD wSize = (abyData[wReadLoc] & 0x7f) + (abyData[wReadLoc + 1] << 7);
			if (wReadLoc + wSize + 2 > wOffset)
			{
				return 0;
			}

			return wSize;
		}
		else
		{
			if (wReadLoc + abyData[wReadLoc] + 1 > wOffset)
			{
				return 0;
			}

			return abyData[wReadLoc];
		}
	}
	bool Read(WORD wReadLoc, void * pData)
	{
		if (wReadLoc >= wOffset)
		{
			return false;
		}
		if (0x80 & abyData[wReadLoc])
		{
			if (wReadLoc + 1 >= wOffset)
			{
				return false;
			}
			WORD wSize = (abyData[wReadLoc] & 0x7f) + (abyData[wReadLoc + 1] << 7);
			if (wReadLoc + wSize + 2 > wOffset)
			{
				return false;
			}
			::memcpy(pData, &(abyData[wReadLoc + 2]), wSize);
		}
		else
		{
			if (wReadLoc + abyData[wReadLoc] + 1 > wOffset)
			{
				return false;
			}
			::memcpy(pData, &(abyData[wReadLoc + 1]), abyData[wReadLoc]);
		}

		return true;
	}
	void * Read(WORD wReadLoc)
	{
		if (wReadLoc >= wOffset)
		{
			return NULL;
		}
		if (0x80 & abyData[wReadLoc])
		{
			if (wReadLoc + 1 >= wOffset)
			{
				return NULL;
			}
			WORD wSize = (abyData[wReadLoc] & 0x7f) + (abyData[wReadLoc + 1] << 7);
			if (wReadLoc + wSize + 2 > wOffset)
			{
				return NULL;
			}
			return &(abyData[wReadLoc + 2]);
		}
		else
		{
			if (wReadLoc + abyData[wReadLoc] + 1 > wOffset)
			{
				return NULL;
			}
			return &(abyData[wReadLoc + 1]);
		} 
	}
};

struct SUMMARY_PRIVATESHOP_SHOP_DATA
{
	bool IsOwnerEmpty;
	BYTE ShopState; 
	WCHAR PrivateShopName[MAX_PRIVATESHOPNAME_USIZE + 1];
};

struct PRIVATESHOP_SHOP_DATA
{
	unsigned int Owner;	
	long long waittimeCashShopStart;
	long long waittimeCashShopEnd;
	SUMMARY_PRIVATESHOP_SHOP_DATA SummaryPrivateShopData;
	WCHAR Notice[MAX_PRIVATESHOPNOTICE_USIZE + 1];

public:
	PRIVATESHOP_SHOP_DATA()
		: Owner(INVALID_OBJECT)
		, waittimeCashShopStart(0)
		, waittimeCashShopEnd(0)
	{
		SummaryPrivateShopData.IsOwnerEmpty = false;
		SummaryPrivateShopData.ShopState = PRIVATESHOP_STATE_NULL;
		ZeroMemory(SummaryPrivateShopData.PrivateShopName, sizeof(WCHAR) * (MAX_PRIVATESHOPNAME_USIZE + 1));
		ZeroMemory(Notice, sizeof(WCHAR) * (MAX_PRIVATESHOPNOTICE_USIZE + 1));
	}
};

struct PACKET_PRIVATESHOP_SHOP_DATA
{
	unsigned int Owner;
	long long waittimeCashShopStart;
	long long waittimeCashShopEnd;
	SUMMARY_PRIVATESHOP_SHOP_DATA SummaryPrivateShopData;
	BYTE NoticeSize;
	WCHAR Notice[MAX_PRIVATESHOPNOTICE_USIZE + 1];

public:
	PACKET_PRIVATESHOP_SHOP_DATA()
		: Owner(INVALID_OBJECT)
		, waittimeCashShopStart(0)
		, waittimeCashShopEnd(0)
		, NoticeSize(0)
	{
		SummaryPrivateShopData.IsOwnerEmpty = false;
		SummaryPrivateShopData.ShopState = PRIVATESHOP_STATE_NONE;
		ZeroMemory(SummaryPrivateShopData.PrivateShopName, sizeof(WCHAR) * (MAX_PRIVATESHOPNAME_USIZE + 1));
		ZeroMemory(Notice, sizeof(WCHAR) * (MAX_PRIVATESHOPNOTICE_USIZE + 1));
	}
};

struct PRIVATESHOP_ITEM_DATA
{
	enum ITEMSTATE
	{
		PRIVATESHOP_GENERAL = 0,
		PRIVATESHOP_BUSINESS_ITEM = 1,
		PRIVATESHOP_VISITOR_SELECT_ITEM = 2,
		PRIVATESHOP_VISITOR_UNSELECT_ITEM = 3,
		PRIVATESHOP_INVALID = 0xFF,
	};

	unsigned int ItemObj;
	BYTE PrivateShopInventorySlotPos;
	bool IsSaveItem;
	ITEM_DATA Item;
	DWORD Zenny;
	BYTE ItemState;

	PRIVATESHOP_ITEM_DATA()
		: ItemObj(INVALID_OBJECT)
		, PrivateShopInventorySlotPos(PRIVATESHOP_ITEMPOS_INVALID)
		, Zenny(PRIVATESHOP_ITEM_BUY_ZENNY_DEFAULT)
		, ItemState(PRIVATESHOP_INVALID)
		, IsSaveItem(false)
	{
		ZeroMemory(&Item, sizeof(Item));
	}
};

struct MAIL_SLOT
{
	unsigned int MailID[MAX_MAIL_SLOT_COUNT];
};

struct MAIL_BRIEF
{
	BYTE MailType;
	DWORD Zenny;
	bool IsRead;
	bool IsAccept;
	bool IsLock;
	BYTE SenderType;
	time_t endTime;
};

struct MAIL_DATA
{
	unsigned int mailID;
	bool IsRead;
	bool IsAccept;
	bool IsLock;
	BYTE MailType;
	BYTE SenderType;
	DWORD Zenny;
	BYTE Expired;
	ITEM_DATA ItemData;
	TIME CreateTime;
	WCHAR FromName[MAX_CHARNAME_SIZE + 1];
	BYTE TextSize;
	WCHAR Text[MAX_MAILMESSAGE_SIZE + 1];
	time_t endTime;
};

struct MAIL_GM_DATA
{
	unsigned int mailID;
	bool IsRead;
	bool IsAccept;
	bool IsLock;
	BYTE MailType;
	BYTE SenderType;
	DWORD Zenny;
	BYTE Expired;
	ITEM_DATA ItemData;	
	TIME CreateTime;
	unsigned int FromCharID;
	WCHAR FromName[MAX_CHARNAME_SIZE + 1];
	BYTE TextSize;
	WCHAR Text[MAX_MAILMESSAGE_SIZE + 1];
	bool IsTemp;
};

struct MAIL_PROFILE
{
	unsigned int mailID;
	bool IsRead;
	bool IsAccept;
	bool IsLock;
	BYTE MailType;
	BYTE SenderType;
	DWORD Zenny;
	BYTE Expired;
	ITEM_PROFILE ItemProfile;	
	TIME CreateTime;
	WCHAR FromName[MAX_CHARNAME_SIZE + 1];
	WCHAR Text[MAX_MAILMESSAGE_SIZE + 1];
	time_t endTime;
};

struct MAIL_NEW_PROFILE
{
	unsigned int mailID;
	bool IsRead;
	bool IsAccept;
	bool IsLock;
	BYTE MailType;
	BYTE SenderType;
	DWORD Zenny;
	BYTE Expired;
	ITEM_PROFILE ItemProfile;
	TIME CreateTime;
	WCHAR FromName[MAX_CHARNAME_SIZE + 1];
	time_t endTime;
};

struct MAIL_NEW_GM_PROFILE
{
	unsigned int mailID;
	bool IsRead;
	bool IsAccept;
	bool IsLock;
	BYTE MailType;
	BYTE SenderType;
	DWORD Zenny;
	BYTE Expired;
	ITEM_PROFILE ItemProfile;	
	TIME CreateTime;
	unsigned int FromCharID;
	WCHAR FromName[MAX_CHARNAME_SIZE + 1];
	bool IsTemp;
};

struct MAIL_NEW_BREIF
{
	BYTE MailCount;
	BYTE UnReadManager;
	BYTE UnReadNormal;
};

struct MATCH_SCORE
{
	BYTE Team1;
	BYTE Team2;
};

struct MATCH_MEMBER_STATE_INFO
{
	unsigned int handle;
	BYTE State;
	BYTE Level;
	BYTE Class;
	WORD GuildName;
	WORD WinCount;
	WORD DrawCount;
	WORD LoseCount;
	WORD CharName;
};

struct MATCH_MINORMATCH_TEAM_INFO
{
	WORD TeamType;
	WCHAR TeamName[MAX_BUDOKAITEAMNAME_USIZE + 1];
	bool DojoRecommender;
	BYTE MemberCount;
	MATCH_MEMBER_STATE_INFO	Members[MAX_MEMBER_IN_PARTY];
};

struct MATCH_MINORMATCH_TEAM_INFO_VAR
{
	WORD TeamType;
	WORD TeamName_var;
	bool DojoRecommender;
	BYTE MemberCount;
	WORD Members_var;
};

typedef	MATCH_MINORMATCH_TEAM_INFO MATCH_MAJORMATCH_TEAM_INFO;
typedef MATCH_MINORMATCH_TEAM_INFO_VAR MATCH_MAJORMATCH_TEAM_INFO_VAR;

typedef	MATCH_MINORMATCH_TEAM_INFO MATCH_FINALMATCH_TEAM_INFO;
typedef MATCH_MINORMATCH_TEAM_INFO_VAR MATCH_FINALMATCH_TEAM_INFO_VAR;

struct MATCH_MINORMATCH_TEAM_SCORE
{
	WORD teamType;
	BYTE Score;
};

struct BUDOKAI_STATE_DATA
{
	BYTE State;
	DWORD NextStepTime;
};

#define BUDOKAI_MATCHSTATE_DATA BUDOKAI_STATE_DATA	

struct BUDOKAI_UPDATEDB_INITIALIZE
{
	WORD SeasonCount;
	DWORD DefaultOpenTime;
	bool RankPointInitialized;
	BUDOKAI_STATE_DATA StateData;
	BUDOKAI_MATCHSTATE_DATA	IndividualStateData;
	BUDOKAI_MATCHSTATE_DATA	TeamStateData;
};

struct BUDOKAI_STATE_INFO
{
	BUDOKAI_STATE State;
	DWORD NextStepTime;
};

struct BUDOKAI_MATCHSTATE_INFO
{
	BUDOKAI_MATCHSTATE State;
	DWORD NextStepTime;
};

struct BUDOKAI_PLAYER_DATA
{
	unsigned int charId;
	BYTE Class;
	BYTE Level;
	float Point;
	WCHAR Name[MAX_CHARNAME_SIZE + 1];
};

struct BUDOKAI_REGISTER_DATA
{
	WORD JoinId;
	WORD Ranking;
	BYTE MinorMatch_MatchIndex;
	float Point;
};

struct BUDOKAI_REGISTER_INDIVIDUAL_DATA : public BUDOKAI_REGISTER_DATA
{
	unsigned int charId;
	bool DojoRecommender;
};

struct BUDOKAI_REGISTER_TEAM_DATA : public BUDOKAI_REGISTER_DATA
{
	WCHAR TeamName[MAX_BUDOKAITEAMNAME_USIZE + 1];
	unsigned int Members[MAX_MEMBER_IN_PARTY];
};

struct BUDOKAI_TOURNAMENT_ENTRY_DATA
{
	WORD JoinId;
	BYTE MinorMatch_MatchIndex;
};

struct BUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_DATA : public BUDOKAI_TOURNAMENT_ENTRY_DATA
{
	unsigned int charId;
	WCHAR CharName[MAX_CHARNAME_SIZE + 1];
	BYTE Class;
	BYTE Level;
	float RankPoint;
	bool DojoRecommender;
	WORD RankBattleWinCount;
	WORD RankBattleDrawCount;
	WORD RankBattleLoseCount;
	WCHAR GuildName[MAX_GUILDNAME_USIZE + 1];
};


struct BUDOKAI_TOURNAMENT_TEAM_ENTRY_MEMBER_DATA
{
	unsigned int charId;
	WCHAR CharName[MAX_CHARNAME_SIZE + 1];
	BYTE Class;
	BYTE Level;
	float RankPoint;
};

struct BUDOKAI_TOURNAMENT_TEAM_ENTRY_DATA : public BUDOKAI_TOURNAMENT_ENTRY_DATA
{
	WCHAR TeamName[MAX_BUDOKAITEAMNAME_USIZE + 1];
	BYTE MemberCount;
	BUDOKAI_TOURNAMENT_TEAM_ENTRY_MEMBER_DATA Members[MAX_MEMBER_IN_PARTY];
};

struct BUDOKAI_TOURNAMENT_INDIVIDUAL_ENTRY_DATA_VAR : BUDOKAI_TOURNAMENT_ENTRY_DATA
{
	unsigned int charId;
	WORD CharName;
	BYTE Class;
	BYTE Level;
	float RankPoint;
	bool DojoRecommender;
	WORD RankBattleWinCount;
	WORD RankBattleDrawCount;
	WORD RankBattleLoseCount;
	WORD GuildName;
};


struct BUDOKAI_TOURNAMENT_TEAM_ENTRY_MEMBER_DATA_VAR
{
	unsigned int charId;
	WORD CharName;
	BYTE Class;
	BYTE Level;
	float RankPoint;
};

struct BUDOKAI_TOURNAMENT_TEAM_ENTRY_DATA_VAR : public BUDOKAI_TOURNAMENT_ENTRY_DATA
{
	WORD TeamName;
	BYTE MemberCount;
	WORD Members;
};

struct BUDOKAI_TEAM_POINT_INFO
{
	BYTE Class;
	WCHAR Name[MAX_CHARNAME_SIZE + 1];
	BYTE Level;
	float Point;
};

struct BUDOKAI_REGISTER_INDIVIDUAL_INFO
{
	bool DojoRecommender;
	WORD JoinId;
	WCHAR CharName[MAX_CHARNAME_SIZE + 1];
};

struct BUDOKAI_REGISTER_TEAM_INFO
{
	WORD JoinId;
	WCHAR TeamName[MAX_BUDOKAITEAMNAME_USIZE + 1];
	BUDOKAI_TEAM_POINT_INFO MemberInfo[MAX_MEMBER_IN_PARTY];
};

struct BUDOKAI_JOIN_INFO
{
	BYTE MatchType;
	BYTE JoinState;	
	BYTE JoinResult;
	union
	{
		BUDOKAI_REGISTER_INDIVIDUAL_INFO IndividualInfo;
		BUDOKAI_REGISTER_TEAM_INFO TeamInfo;
	};
};

struct BUDOKAI_TOURNAMENT_ENTRY_TEAM_INFO
{
	WORD JoinId;
	bool DojoRecommender;
	WCHAR TeamName[MAX_BUDOKAITEAMNAME_USIZE + 1];
};

struct BUDOKAI_TOURNAMENT_ENTRY_TEAM_INFO_VAR
{
	WORD JoinId;
	bool DojoRecommender;
	WORD TeamName;
};

struct BUDOKAI_TOURNAMENT_MATCH_DATA
{
	BYTE Depth;
	BYTE MatchNumber;
	BYTE MatchResult;
	WORD WinnerTeam;
	WORD JoinId1;
	WORD JoinId2;
	BYTE Score1;
	BYTE Score2;
};

struct BUDOKAI_UPDATE_STATE_INFO
{
	BYTE State;
	DWORD NextStepTime;
	DWORD RemainTime;
	WORD SeasonCount;
};

struct BUDOKAI_UPDATE_MATCH_STATE_INFO
{
	BYTE State;
	DWORD NextStepTime;
	DWORD RemainTime;
};

struct BUDOKAI_MUDOSA_INFO
{
	WCHAR MudosaName[BUDOKAI_MAX_MUDOSA_NAME_IN_UNICODE + 1];
	WORD CurrentUserCount;
};

struct BUDOKAI_PREV_SEASON_PLAYER_INFO
{
	BYTE MatchType;
	unsigned int charId;
	WCHAR Name[MAX_CHARNAME_SIZE + 1];
	BYTE Class;
	BYTE Level;
	BYTE JoinResult;
};

struct MINORMATCH_TELEPORT_INDIVIDUAL_DATA
{
	unsigned int worldId;
	unsigned int worldTblidx;
	BYTE PlayerCount;
	unsigned int Players[BUDOKAI_MINOR_MATCH_INDIVIDUAL_COUNT];
};

struct MINORMATCH_TELEPORT_TEAM_MEMBER_LIST
{
	BYTE Count;
	unsigned int charId[MAX_MEMBER_IN_PARTY];
};

struct MINORMATCH_TELEPORT_TEAM_DATA
{
	unsigned int worldId;
	unsigned int worldTblidx;
	BYTE TeamCount;
	MINORMATCH_TELEPORT_TEAM_MEMBER_LIST TeamList[BUDOKAI_MINOR_MATCH_TEAM_COUNT];
};

enum BUDOKAI_GM_MATCH_PROGRESS_STATES
{
	BUDOKAI_GM_MATCH_PROGRESS_STATE_READY,
	BUDOKAI_GM_MATCH_PROGRESS_STATE_RUN,
	BUDOKAI_GM_MATCH_PROGRESS_STATE_FINISHED,
};

struct BUDOKAI_GM_MATCH_PROGRESS_STATE
{
	BYTE MatchIndex;
	BYTE ProgressState;
	BYTE MatchResult;
	WORD winnerTeamType;
	WCHAR TeamName1[MAX_BUDOKAITEAMNAME_USIZE + 1];
	BYTE Score1;
	WCHAR TeamName2[MAX_BUDOKAITEAMNAME_USIZE + 1];
	BYTE Score2;
};

struct MINORMATCH_SELECTION_DATA
{
	WORD teamType;
	BYTE Number;
};


struct BUDOKAI_JOIN_STATE_DATA
{
	unsigned int charId;
	WORD joinId;
	BYTE JoinState;
	BYTE JoinResult;
};

struct RECIPE_DATA
{
	unsigned int recipeTblidx;
	BYTE RecipeType;
};

struct UPDATED_SKILL_DATA
{
	BYTE SkillPassiveEffect;
	union
	{
		float Casting_Time;
		WORD Cool_Time;
		float Skill_Effect_Value[MAX_EFFECTSKILL];
		WORD Keep_Time;
		WORD Require_EP;
		BYTE Apply_Range;
		struct
		{
			BYTE Apply_Area_Size_1;
			BYTE Apply_Area_Size_2;
		};
		BYTE Use_Range_Max;
	};
};

struct DOJO_BANK_HISTORY_INFO
{
	TIME Time;
	BYTE Type;
	DWORD Amount;
	bool IsSave;
};

struct DOJO_NPC_INFO
{
	unsigned int dojoTblidx;
	WCHAR Name[MAX_GUILDNAME_USIZE + 1];
	BYTE Level;
	DWORD GuildReputation;
	DWORD MaxGuildPointEver;
	BYTE PeaceStatus;
	WCHAR SeedCharName[MAX_CHARNAME_SIZE + 1];
	WCHAR LeaderName[MAX_CHARNAME_SIZE + 1];
	WCHAR Notice[MAX_LENGTH_OF_DOJO_NOTICE_UNICODE + 1];
	WCHAR ChallengeName[MAX_GUILDNAME_USIZE + 1];
	WCHAR ChallengeLeaderName[MAX_CHARNAME_SIZE + 1];
};

struct CASHITEM_BRIEF
{
	DWORD ProductId;
	unsigned int HLSitemTblidx;
	BYTE StackCount;
};

#pragma pack()
#endif