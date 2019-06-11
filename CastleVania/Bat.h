#pragma once
#include "Enemy.h"
#include "DelayTime.h"

enum BAT_STATE
{
	BAT_STATE_INVISIBLE,
	BAT_STATE_WAIT,
	BAT_STATE_FLY
};

enum BIRD_ACTION
{
	BIRD_ACTION_RUN,
	BIRD_ACTION_COUNT
};

class Bat :
	public Enemy
{
	int playerContactDirection;
	int boxAreaActiveHeight, boxAreaActiveWidth, boxAreaActiveX, boxAreaActiveY;
	int alpha;
	BaseObject boxAreaActive;
	DelayTime invisibleDelay;
	BAT_STATE batState;
public:
	void onInitFromFile(ifstream& fs, int mapHeight) override;
	void setParam(const char* name, int value);
	void setAction(int action) override;
	BAT_STATE getBatState();
	void setBatState(BAT_STATE batState);
	void onUpdate(float dt) override;
	void onReborn() override;
	void onIntersection(BaseObject* other) override;
	Bat();
	~Bat();
};

