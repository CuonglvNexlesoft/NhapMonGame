#pragma once
#pragma once
#include "Enemy.h"

enum GHOST_ACTION
{
	GHOST_ACTION_STAND,
	GHOST_ACTION_RUN,
	GHOST_ACTION_COUNT
};

class Ghost :
	public Enemy
{
	BaseObject* currentGroundCollision; //Ground dang va cham hien tai

public:
	void onUpdate(float dt) override;
	void setToInitLocation() override;
	void setAction(int action) override;
	void onCollision(BaseObject* other, float collisionTime, int nx, int ny) override;
	Ghost();
	~Ghost();
};

