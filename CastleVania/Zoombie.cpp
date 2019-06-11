#include "Zoombie.h"
#include "GraphicsAssetsManager.h"
#include "Player.h"

Zoombie::Zoombie()
{
	currentGroundCollision = 0;
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ZOOMBIE));
	setPhysicsEnable(true);
	setIsAllowUpdateRender(true, true);
	setDir(LEFT);
	setAction(0);
}


void Zoombie::onUpdate(float dt)
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
		currentGroundCollision = NULL;
	}
	BaseObject::onUpdate(dt);
}

void Zoombie::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
	currentGroundCollision = other;
	Enemy::onCollision(other, collisionTime, nx, ny);
}

void Zoombie::setToInitLocation()
{
	BaseObject::setToInitLocation();
	setDirectionToPlayer();
	setAction(0);
}

void Zoombie::setAction(int action)
{
	BaseObject::setAction(getDir() + action);
}





Zoombie::~Zoombie()
{
	
}
