#pragma once
#include "BaseObject.h"
#include "GraphicsAssetsManager.h"
#include "Define.h"
#include "DelayTime.h"
#include "Game.h"

enum PLAYER_ACTION {
	PLAYER_ACTION_STAND,
	PLAYER_ACTION_SEAT,
	PLAYER_ACTION_RUN, 
	PLAYER_ACTION_CLIMB,
	PLAYER_ACTION_JUMP,
	PLAYER_ACTION_JUMP_ATTACK,
	PLAYER_ACTION_STAND_ATTACK,
	PLAYER_ACTION_SIT_ATTACK,
	PLAYER_ACTION_SHOOT,
	PLAYER_ACTION_HURT,
	PLAYER_ACTION_COUNT
};

enum PLAYER_STATE
{
	PLAYER_STATE_NORMAL,
	PLAYER_STATE_ON_STAIR,
	PLAYER_STATE_DIE,
	PLAYER_STATE_ATTACK,
	PLAYER_STATE_ATTACK_SUBWEAPON,
	PLAYER_STATE_EAT_EFFECT,
	PLAYER_STATE_SEAT,
	PLAYER_STATE_DEAD
};

enum PLAYER_SUBWEAPON
{
	PLAYER_NO_SUBWEAPON,
	PLAYER_SUBWEAPON_KNIFE,
	PLAYER_SUBWEAPON_HOLYWATER,
	PLAYER_SUBWEAPON_THE_AX
};

enum PLAYER_STAIR_STATE
{
	PLAYER_STAIR_STATE_READY, PLAYER_STAIR_STATE_GO_UP, PLAYER_STAIR_STATE_GO_DOWN
};

class Player :
	public BaseObject
{
	static Player* instance;

	PLAYER_STATE playerState;

	//Subweapon
	PLAYER_SUBWEAPON playerSubWeapon;

	//bất tử
	bool isUndying; 

	//có thánh giá
	bool isHaveHolyCross;

	//handle on stair
	int stairDirection;
	int playerStairDestX, playerStairDestY;
	PLAYER_STAIR_STATE playerStairState;
public:
	static Player* getInstance();

	DelayTime eatEffectDelay, deadActionTime, flashEffectDelay;
	GameTime flashEffectTime;

	PLAYER_STATE getPlayerState();
	void setPlayerState(PLAYER_STATE playerState);
	void setAction(int action) override;
	void setIsLastFrameAnimationDone(bool isLastFrameAnimationDone) override;
	bool getIsUndying();
	void setIsUndying(bool isUndying);
	void handleUndyingStatePlayer();
	void setSubWeapon(PLAYER_SUBWEAPON playerSubWeapon);
	PLAYER_SUBWEAPON getSubWeapon();
	void handleAttackSubWeapon();
	bool getIsHaveHolyCross();
	void setIsHaveHolyCross(bool isHaveHolyCross);

	void updatePlayerEvent();

	void onCollision(BaseObject* other, float collisionTime, int nx, int ny) override;
	Player();
	~Player();
};
