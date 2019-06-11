#include "Greenman.h"
#include "GraphicsAssetsManager.h"
#include "Player.h"

Greenman::Greenman()
{
	currentGroundCollision = 0;
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_GREENMAN));
	setPhysicsEnable(true);
	setIsAllowUpdateRender(true, true);
	setDir(LEFT);
	setAction(0);
}


void Greenman::onUpdate(float dt)
{
	//if (getIsAllowUpdate() && getIsAllowRender() && (this->getMidX() - PLAYER->getMidX() <= ZOOMBIE_DETECT_PLAYER_DISTANCE)) {
	//	if(getDir() == LEFT) 
	//		setVx(-ZOOMBIE_VX);
	//	else 
	//		setVx(ZOOMBIE_VX);
	//	if (currentGroundCollision != NULL && ((
	//		getLeft() < currentGroundCollision->getLeft()) && getDir() == LEFT ||
	//		(getRight() > currentGroundCollision->getRight() && getDir() == RIGHT)))
	//	{
	//		if (isGrounded())
	//		{
	//			setDirectionToPlayer();
	//		}
	//		//setVy(PANTHER_VY);
	//		/*setState(PANTHER_STATE_RUN);
	//		setDirectionToPlayer();*/
	//		//currentGroundCollision = NULL;
	//	}
	//}
	if (getDir() == LEFT)
		setVx(-ZOOMBIE_VX);
	else
		setVx(ZOOMBIE_VX);
	if (currentGroundCollision != NULL && ((
		getLeft() < currentGroundCollision->getLeft()) && getDir() == LEFT ||
		(getRight() > currentGroundCollision->getRight() && getDir() == RIGHT)))
	{
		if (isGrounded())
		{
			setDirectionToPlayer();
		}
		//setVy(PANTHER_VY);
		/*setState(PANTHER_STATE_RUN);
		setDirectionToPlayer();*/
		//currentGroundCollision = NULL;
	}
	BaseObject::onUpdate(dt);
}

void Greenman::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
	currentGroundCollision = other;
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Greenman::setToInitLocation()
{
	BaseObject::setToInitLocation();
	setDirectionToPlayer();
	setAction(0);
}

void Greenman::setAction(int action)
{
	BaseObject::setAction(getDir() + action);
}





Greenman::~Greenman()
{

}
