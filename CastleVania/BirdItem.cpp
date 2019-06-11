#include "BirdItem.h"
#include "GraphicsAssetsManager.h"



BirdItem::BirdItem()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_BIRD_ITEM));
	setIsAllowUpdateRender(true, true);
	setPhysicsEnable(false);
}


BirdItem::~BirdItem()
{
}
