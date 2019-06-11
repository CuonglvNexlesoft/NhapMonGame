#pragma once
#include "BaseObject.h"

enum BULLET_ACTION
{
	BULLET_ACTION,
	BULLET_ACTION_COUNT
};
class MermanBullet :
	public BaseObject
{
public:
	bool isRemove;
	void setAction(int action) override;
	void onIntersection(BaseObject* other) override;
	void onUpdate(float dt) override;
	void onCollision(BaseObject* other, float collisionTime, int nx, int ny) override;
	MermanBullet();
	~MermanBullet();
};

