#include "Runman.h"
#include "GraphicsAssetsManager.h"
#include "Player.h"

Runman::Runman()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_RUNMAN));
	setPhysicsEnable(true);
	setIsAllowUpdateRender(true, true);
	setDir(LEFT);
	setAction(0);
}


void Runman::onUpdate(float dt)
{
	if (getIsAllowUpdate() && getIsAllowRender() && (this->getMidX() - PLAYER->getMidX() <= ZOOMBIE_DETECT_PLAYER_DISTANCE)) {
		if (getDir() == LEFT)
			setVx(-ZOOMBIE_VX);
		else
			setVx(ZOOMBIE_VX);
	}
	BaseObject::onUpdate(dt);
}

void Runman::setToInitLocation()
{
	BaseObject::setToInitLocation();
	setDirectionToPlayer();
	setAction(0);
}

void Runman::setAction(int action)
{
	BaseObject::setAction(getDir() + action);
}





Runman::~Runman()
{

}
