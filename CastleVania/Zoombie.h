#pragma once
#include "Enemy.h"


class Zoombie :
	public Enemy
{
	BaseObject* currentGroundCollision; //Ground dang va cham hien tai
public:
	void onUpdate(float dt) override;
	void setToInitLocation() override;
	void setAction(int action) override;
	void onCollision(BaseObject* other, float collisionTime, int nx, int ny) override;
	Zoombie();
	~Zoombie();
};

