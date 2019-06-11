#pragma once
#include "Enemy.h"
#include "MermanBullet.h"
#include"DelayTime.h"

enum SHOOTMAN_STATE {
	//MERMAN_STATE_JUMP,
	SHOOTMAN_STATE_RUN,
	SHOOTMAN_STATE_FIRE
};

enum _ACTION {
	SHOOTMAN_ACTION_FIRE,
	SHOOTMAN_ACTION_COUNT
};

class Shootman :
	public Enemy
{
	SHOOTMAN_STATE mermanState;
	DelayTime runDelay;
	DelayTime fireDelay;
public:
	void setMermanState(SHOOTMAN_STATE mermanState);
	SHOOTMAN_STATE getMermanState();
	void onUpdate(float dt) override;
	void setToInitLocation() override;
	void setAction(int action) override;
	void onReborn() override;
	void onCollision(BaseObject* other, float collisionTime, int nx, int ny);
	Shootman();
	~Shootman();
};

