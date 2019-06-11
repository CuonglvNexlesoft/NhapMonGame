#include "Boss.h"
#include "GraphicsAssetsManager.h"
#include "Player.h"
#include "MermanBullet.h"
#include "Camera.h"
#include "Water.h"
#include "ScoreBar.h"
#include "ItemEndGame.h"

Boss::Boss()
{
	undyingDelayTime.init(1000);
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_BOSS));
	setPhysicsEnable(false);
	setIsAllowUpdateRender(true, false);
	setBOSSState(BOSS_STATE_JUMP);
	runDelay.init(1500);
	fireDelay.init(500);
	setHeight(32);
}

void Boss::setToInitLocation()
{
	BaseObject::setToInitLocation();
	setDirectionToPlayer();
	setAction(0);
}

void Boss::setAction(int action)
{
	BaseObject::setAction(getDir()*BOSS_ACTION_COUNT + action);
}

void Boss::onReborn()
{
	Enemy::onReborn();
	setPhysicsEnable(false);
	setDx(0);
	setDy(0);
	setVx(0);
	setVy(0);
	setIsAllowUpdateRender(true, false);
	setBOSSState(BOSS_STATE_JUMP);
	setIsGrounded(false);
	setHeight(32);
}

void Boss::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
	if (ny == 1)
	{
		if (other == PLAYER) return;
		BaseObject::onCollision(other, collisionTime, nx, ny);
	}
}

void Boss::setBOSSState(BOSS_STATE BOSSState)
{
	this->BOSSState = BOSSState;
}

BOSS_STATE Boss::getBOSSState()
{
	return this->BOSSState;
}

void Boss::onUpdate(float dt)
{
	undyingDelayTime.update();
	switch (BOSSState) {
	case BOSS_STATE_JUMP:
		setDirectionToPlayer();
		setAction(0);
		/*if (
		(PLAYER->getY() - this->getY() <= DISTANCE_Y_PLAYER_BOSS)
		&& (this->getY() <= BOSS_Y_IN_WATER)
		&& (abs(PLAYER->getMidX() - this->getMidX()) <= DISTANCE_X_PLAYER_BOSS)
		)
		{
		setIsAllowUpdateRender(true, true);
		setVy(BOSS_VY_JUMP);
		setPhysicsEnable(true);
		}*/
		setIsAllowUpdateRender(true, true);
		setPhysicsEnable(true);

		if (this->isGrounded()) {
			runDelay.start();
			setBOSSState(BOSS_STATE_RUN);
			setAction(0);
		}
		break;

	case BOSS_STATE_RUN:
		runDelay.update();
		if (getDir() == LEFT)
			setVx(-0.03);
		else
			setVx(0.03);

		if (runDelay.isTerminated()) {
			fireDelay.start();
			setBOSSState(BOSS_STATE_FIRE);
			//setHeight(32);
			//setY(getY() - 32 + 32);
			MermanBullet* BOSSBullet = new MermanBullet();
			BOSSBullet->setDir(getDir());
			if (BOSSBullet->getDir() == LEFT) {
				BOSSBullet->setX(this->getX());
				BOSSBullet->setY(this->getY() - 7);
			}
			else {
				BOSSBullet->setX(this->getX() + this->getWidth());
				BOSSBullet->setY(this->getY() - 7);
			}
		}
		break;

	case BOSS_STATE_FIRE:
		fireDelay.update();
		setVx(0);
		setVy(0);
		setDx(0);
		setAction(BOSS_ACTION_FIRE);

		if (fireDelay.isTerminated()) {
			runDelay.start();
			setBOSSState(BOSS_STATE_RUN);
			//setHeight(32);
			//setY(getY() + 32 - 32);
			setDirectionToPlayer();
			setAction(0);
		}

		break;
	}

	BaseObject::onUpdate(dt);
}

void Boss::onHitByWeapon()
{
	if (!undyingDelayTime.isOnTime())
	{
		undyingDelayTime.start();
		SCOREBAR->increaseBossHealth(-3);
		if (SCOREBAR->getBossHealth() <= 0)
		{
			Enemy::onHitByWeapon();
			ITEM_END_GAME->delayWaitTime.start();
		}
	}
}

Boss::~Boss()
{
}
