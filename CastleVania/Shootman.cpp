#include "Shootman.h"
#include "GraphicsAssetsManager.h"
#include "Player.h"
#include "MermanBullet.h"
#include "Camera.h"
#include "Water.h"

Shootman::Shootman()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_SHOOTMAN));
	setPhysicsEnable(true);
	setIsAllowUpdateRender(true, true);
	setMermanState(SHOOTMAN_STATE_RUN);
	runDelay.init(1500);
	fireDelay.init(500);
	setAction(1);
	runDelay.start();
}

void Shootman::setToInitLocation()
{
	BaseObject::setToInitLocation();
	setDirectionToPlayer();
}

void Shootman::setAction(int action)
{
	BaseObject::setAction(getDir()*SHOOTMAN_ACTION_COUNT + action);
}

void Shootman::onReborn()
{
	/*Enemy::onReborn();
	setPhysicsEnable(false);
	setDx(0);
	setDy(0);
	setVx(0);
	setVy(0);
	setIsAllowUpdateRender(true, false);
	setMermanState(0);
	setIsGrounded(false);
	setHeight(MERMAN_RUN_HEIGHT);*/
}

void Shootman::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
	if (ny == 1)
	{
		if (other == PLAYER) return;
		BaseObject::onCollision(other, collisionTime, nx, ny);
	}
}

void Shootman::setMermanState(SHOOTMAN_STATE mermanState)
{
	this->mermanState = mermanState;
}

SHOOTMAN_STATE Shootman::getMermanState()
{
	return this->mermanState;
}

void Shootman::onUpdate(float dt)
{
	switch (mermanState) {

	case SHOOTMAN_STATE_RUN:
		runDelay.update();
		if (getDir() == LEFT)
			setVx(0);
		else
			setVx(0);

		if (runDelay.isTerminated()) {
			fireDelay.start();
			setMermanState(SHOOTMAN_STATE_FIRE);
			//setHeight(MERMAN_FIRE_HEIGHT);
			//setY(getY() - MERMAN_RUN_HEIGHT + MERMAN_FIRE_HEIGHT);
			MermanBullet* mermanBullet = new MermanBullet();
			mermanBullet->setDir(getDir());
			if (mermanBullet->getDir() == LEFT) {
				mermanBullet->setX(this->getX());
				mermanBullet->setY(this->getY() - 1);
			}
			else {
				mermanBullet->setX(this->getX() + this->getWidth());
				mermanBullet->setY(this->getY() - 7);
			}
		}
		break;

	case SHOOTMAN_STATE_FIRE:
		fireDelay.update();
		setVx(0);
		setDx(0);
		setAction(SHOOTMAN_ACTION_FIRE);

		if (fireDelay.isTerminated()) {
			runDelay.start();
			setMermanState(SHOOTMAN_STATE_RUN);
			//setHeight(MERMAN_RUN_HEIGHT);
			//setY(getY() + MERMAN_RUN_HEIGHT - MERMAN_FIRE_HEIGHT);
			setDirectionToPlayer();
			setAction(SHOOTMAN_ACTION_FIRE);
		}

		break;
	}

	BaseObject::onUpdate(dt);
}


Shootman::~Shootman()
{
}
