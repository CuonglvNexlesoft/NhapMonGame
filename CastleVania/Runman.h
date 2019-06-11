
#include "Enemy.h"


class Runman :
	public Enemy
{
	BaseObject* currentGroundCollision; //Ground dang va cham hien tai
public:
	void onUpdate(float dt) override;
	void setToInitLocation() override;
	void setAction(int action) override;
	Runman();
	~Runman();
};

