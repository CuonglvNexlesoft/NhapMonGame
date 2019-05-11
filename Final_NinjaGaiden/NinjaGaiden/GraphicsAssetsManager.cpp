#include "GraphicsAssetsManager.h"
#include "Define.h"
#include "TextureManager.h"

GraphicsAssetsManager * GraphicsAssetsManager::instance = 0;

GraphicsAssetsManager * GraphicsAssetsManager::getInstance()
{
	if (instance == 0) {
		instance = new GraphicsAssetsManager();
	}

	return instance;
}

GraphicsAssets * GraphicsAssetsManager::getGraphicsAssets(int spriteInfo)
{
	return getInstance()->allGraphicsAssets[spriteInfo];
}

GraphicsAssetsManager::GraphicsAssetsManager()
{
	for (size_t i = 0; i < SPRITE_COUNT; i++)
	{
		allGraphicsAssets.push_back(new GraphicsAssets());
	}

	allGraphicsAssets[SPRITE_INFO_SIMON]->getGraphicsAssetsInfomation(TEXTURE_SIMON, L"Assets/GraphicsAssets/ryu.png", L"Assets/GraphicsAssets/ryu.info.dat");
	//allGraphicsAssets[SPRITE_INFO_SIMON]->getGraphicsAssetsInfomation(TEXTURE_SIMON, L"Assets/GraphicsAssets/Simon/image.png", L"Assets/GraphicsAssets/Simon/simon_animation.info.dat");
}


GraphicsAssetsManager::~GraphicsAssetsManager()
{
}
