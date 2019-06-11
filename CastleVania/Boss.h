#pragma once
#include "Enemy.h"
#include "MermanBullet.h"
#include"DelayTime.h"

enum BOSS_STATE {
	BOSS_STATE_JUMP,
	BOSS_STATE_RUN,
	BOSS_STATE_FIRE
};

enum BOSS_ACTION {
	BOSS_ACTION_FIRE,
	BOSS_ACTION_COUNT
};

class Boss :
	public Enemy
{
	BOSS_STATE BOSSState;
	DelayTime runDelay;
	DelayTime fireDelay;
	DelayTime undyingDelayTime;
public:
	void setBOSSState(BOSS_STATE BOSSState);
	BOSS_STATE getBOSSState();
	void onUpdate(float dt) override;
	void setToInitLocation() override;
	void setAction(int action) override;
	void onReborn() override;
	void onCollision(BaseObject* other, float collisionTime, int nx, int ny);
	void onHitByWeapon() override;
	Boss();
	~Boss();
};

