#include "Level.h"
#include "Player.h"
#include "Boss.h"
#include "Greenman.h"
#include "Ghost.h"
#include "Gate1.h"
#include "Gate2.h"
#include "Stair.h"
#include "Torch.h"
#include "MorningStar.h"
#include "ExplosionEffect.h"
#include "ItemMorningStar.h"
#include "ItemBigHeart.h"
#include "ItemSmallHeart.h"
#include "ItemKnife.h"
#include "Candle.h"
#include "BirdItem.h"
#include "Panther.h"
#include "Runman.h"
#include "Shootman.h"
#include "Item1000pts.h"
#include "Item700pts.h"
#include "Item400pts.h"
#include "ItemHolycross.h"
#include "ItemHolyWater.h"
#include "BreakWall1.h"
#include "BreakWall2.h"
#include "Brick.h"
#include "TeleportStair.h"
#include "Merman.h"
#include "MermanBulletListInstance.h"
#include "Bat.h"
#include "WaterListInstance.h"
#include "ListGateInstance.h"
#include "ListSubWeaponInstance.h"
#include "ActiveWater.h"
#include "VampireBat.h"
#include "ItemIncreaseHealth.h"
#include "ItemMagicLamp.h"
#include "ItemTheAx.h"
#include "ItemEndGame.h"

Level::Level()
{
	flatRenderTileMap = true;
	effectHollyCrossTime.init(30);
	effectHollyCrossDelay.init(1000);
	instance = this;
}

Level* Level::instance = NULL;
Level * Level::getInstance()
{
	if (instance == NULL) {
		instance = new Level();
	}
	return instance;
}

void Level::Init(const char * folderPath)
{
	objectTagGroupManager = OBJECT_TAG_GROUP_MANAGER;
	grid = GRID;

	string folderPathString = (string)folderPath;
	string tilesheetString = folderPathString;
	string matrixPathString = folderPathString;
	string objectPathString = folderPathString;
	string objectTagGroupPath = folderPathString;
	string worldChildsPath = folderPathString;

		/*tilesheetString.append("/map3.3/tilesheet.png");
		matrixPathString.append("/map3.3/matrix.dat");
		objectPathString.append("/map3.3/objects.dat");
		objectTagGroupPath.append("/map3.3/collision_type_collides.dat");
		worldChildsPath.append("/map3.3/worldChilds.dat");*/
		/*objectTagGroupManager->readInformationFromFile(objectTagGroupPath.c_str());
		worldChildManager = WORLD_CHILD_MANAGER;
		worldChildManager->readInformationWorldChild(worldChildsPath.c_str());
		worldChildManager->setCurrentWorldChild(0);
		worldChildManager->resetLocationInWorldChild();*/

		 
		/*tilesheetString.append("/map3.2/tilesheet.png");
		matrixPathString.append("/map3.2/matrix.dat");
		objectPathString.append("/map3.2/objects.dat");
		objectTagGroupPath.append("/map3.2/collision_type_collides.dat");
		worldChildsPath.append("/map3.2/worldChilds.dat");*/

		tilesheetString.append("/world/tilesheet.png");
		matrixPathString.append("/world/matrix.dat");
		objectPathString.append("/world/objects.dat");
		objectTagGroupPath.append("/world/collision_type_collides.dat");
		worldChildsPath.append("/world/worldChilds.dat");


		objectTagGroupManager->readInformationFromFile(objectTagGroupPath.c_str());
		worldChildManager = WORLD_CHILD_MANAGER;
		worldChildManager->readInformationWorldChild(worldChildsPath.c_str());
		worldChildManager->setCurrentWorldChild(0);
		worldChildManager->resetLocationInWorldChild();


	/*string tilesheetString = folderPathString; tilesheetString.append("/tilesheet.png");
	string matrixPathString = folderPathString; matrixPathString.append("/matrix.dat");
	string objectPathString = folderPathString; objectPathString.append("/objects.dat");
	string objectTagGroupPath = folderPathString; objectTagGroupPath.append("/collision_type_collides.dat");
	string worldChildsPath = folderPathString; worldChildsPath.append("/worldChilds.dat");*/
	/*string tilesheetString = folderPathString; tilesheetString.append("/map3.1/tilesheet.png");
	string matrixPathString = folderPathString; matrixPathString.append("/map3.1/matrix.dat");
	string objectPathString = folderPathString; objectPathString.append("/map3.1/1.dat");
	string objectTagGroupPath = folderPathString; objectTagGroupPath.append("/map3.1/collision_type_collides.dat");
	string worldChildsPath = folderPathString; worldChildsPath.append("/map3.1/worldChilds.dat");*/
	
	wstring ws = stringToWstring(tilesheetString);
	LPCWSTR tilesheetPath = ws.c_str();

	TextureManager::GetInstance()->Add(TEXTURE_TILESHEET, tilesheetPath, 0);
	tilemap.Init(tilesheetString.c_str(), matrixPathString.c_str());

	InitAllObjectsInLevel(objectPathString.c_str());

	//objectTagGroupManager->readInformationFromFile(objectTagGroupPath.c_str());
	//worldChildManager = WORLD_CHILD_MANAGER;
	//worldChildManager->readInformationWorldChild(worldChildsPath.c_str());
	//worldChildManager->setCurrentWorldChild(0);
	//worldChildManager->resetLocationInWorldChild();
}

void Level::InitAllObjectsInLevel(const char * objectPathString)
{
	int worldHeight = tilemap.getWorldHeight();
	int objectCount;
	ifstream fs(objectPathString);
	fs >> objectCount;
	for (size_t i = 0; i < objectCount; i++)
	{
		BaseObject* obj;
		int id;
		fs >> id;
		//DebugOut((wchar_t*) L"%d \n", id);

		switch (id)
		{
		case 1:
			obj = new Zoombie();
			break;
		case -2:
			obj = new Gate1();
			break;
	/*	case SPRITE_INFO_STAIR:
			obj = new Stair();
			break;*/
		/*case 3:
			obj = new Torch();
			break;*/
		/*case SPRITE_INFO_ITEM_MORNING_STAR:
			obj = new ItemMorningStar();
			break;*/
		case 22:
			obj = new ItemBigHeart();
			break;
		case 21:
			obj = new ItemKnife();
			break;
		case 2:
			obj = new Panther();
			break;
		case 3:
			obj = new Candle();
			break;
		case 8:
			obj = new BirdItem();
			break;
		case 23:
			obj = new ItemSmallHeart();
			break;
		/*case SPRITE_INFO_ITEM_1000PTS:
			obj = new Item1000pts();
			break;*/
		/*case SPRITE_INFO_ITEM_SMALL_HEART:
			obj = new ItemSmallHeart();
			break;*/
		/*case 22:
			obj = new Item700pts();
			break;*/
		/*case SPRITE_INFO_ITEM_400PTS:
			obj = new Item400pts();
			break;*/
		/*case 22:
			obj = new ItemHolycross();
			break;*/
		/*case SPRITE_INFO_ITEM_HOLYWATER:
			obj = new ItemHolyWater();
			break;*/
		/*case 22:
			obj = new ItemMagicLamp();
			break;*/
		/*case 22:
			obj = new ItemIncreaseHealth();
			break;*/
		/*case SPRITE_INFO_ITEM_THEAX:
			obj = new ItemTheAx();
			break;*/
		case -3:
			obj = new Gate1();
			break;
		/*case SPRITE_INFO_BRICK:a
			obj = new Brick();
			break;*/
		/*case SPRITE_INFO_BREAKWALL1:
			obj = new BreakWall1();
			break;*/
		/*case SPRITE_INFO_BREAKWALL2:
			obj = new BreakWall2();
			break;*/
		/*case SPRITE_INFO_TELEPORTSTAIR:
			obj = new TeleportStair();
			break;*/

		case 9:
			obj = new Shootman();
			break;

		case 10:
			obj = new Runman();
			break;

		case 6:
			obj = new Ghost();
			break;
		
		case 7:
			obj = new Greenman();
			break;
		case 4:
			obj = new Bat();
			break;
		case -5:
			obj = new ActiveWater();
			break;
		/*case 15:
			obj = new Boss();
			break;*/
		case 15:
			obj = new Boss();
			break;
		/*case SPRITE_INFO_ITEM_ENDGAME:
			obj = new ItemEndGame();
			break;*/
		default:
			obj = new BaseObject();
			break;
		}
		obj->onInitFromFile(fs, worldHeight);
		objectTagGroupManager->addObjectToEachCategories(obj);
		grid->addObjectToGrid(obj);
	}
}


void Level::update(float dt)
{
	//Nếu đang chuyển cảnh
	for (size_t i = 0; i < ListGateInstance::getGateList()->size(); i++)
	{
		Gate2* obj = ListGateInstance::getGateList()->at(i);
		if (obj->getOnChangeWorldChildGate()) {
			obj->changeWorldChildInGate(dt, grid);
			return;
		}
	}
	
	//Nếu không đang ở giai đoạn chuyển cảnh
	vector<BaseObject*> allObjectsHaveToWork = grid->getAllObjectsHaveToWork();
	for (size_t i = 0; i < allObjectsHaveToWork.size(); i++)
	{
		allObjectsHaveToWork[i]->update(dt);
		Collision::CheckCollision(PLAYER, allObjectsHaveToWork[i]);
		Collision::CheckCollision(MORNING_STAR, allObjectsHaveToWork[i]);
		for (size_t j = 0; j < ListSubWeaponInstance::getListSupWeapon()->size(); j++)
		{
			auto obj = ListSubWeaponInstance::getListSupWeapon()->at(j);
			Collision::CheckCollision(obj, allObjectsHaveToWork[i]);
		}
	}

	for (size_t i = 0; i < MermanBulletListInstance::getBulletList()->size(); i++)
	{
		auto obj = MermanBulletListInstance::getBulletList()->at(i);
		obj->update(dt);
		Collision::CheckCollision(PLAYER, obj);
		Collision::CheckCollision(MORNING_STAR, obj);
	}
	MermanBulletListInstance::deleteObjectInList();

	for (size_t i = 0; i < WaterListInstance::getWaterList()->size(); i++)
	{
		auto obj = WaterListInstance::getWaterList()->at(i);
		obj->update(dt);
	}
	WaterListInstance::deleteObjectInList();

	for (size_t i = 0; i < ListSubWeaponInstance::getListSupWeapon()->size(); i++)
	{
		auto obj = ListSubWeaponInstance::getListSupWeapon()->at(i);
		obj->update(dt);
	}
	ListSubWeaponInstance::deleteObjectInList();

	objectTagGroupManager->onCollision();
	CAMERA->update();
	PLAYER->update(dt);
	MORNING_STAR->update(dt);
	EXPLOSION_EFFECT->update(dt);
	
}

void Level::render()
{
	handleRenderTileMap();
	
	vector<BaseObject*> allObjectsHaveToWork = grid->getAllObjectsHaveToWork();
	for (size_t i = 0; i < allObjectsHaveToWork.size(); i++)
	{
		allObjectsHaveToWork[i]->render(CAMERA);
	}
	
	PLAYER->render(CAMERA);
	MORNING_STAR->render(CAMERA);
	EXPLOSION_EFFECT->render(CAMERA);
	

	for (size_t i = 0; i < MermanBulletListInstance::getBulletList()->size(); i++)
	{
		auto obj = MermanBulletListInstance::getBulletList()->at(i);
		obj->render(CAMERA);
	}

	for (size_t i = 0; i < WaterListInstance::getWaterList()->size(); i++)
	{
		auto obj = WaterListInstance::getWaterList()->at(i);
		obj->render(CAMERA);
	}

	for (size_t i = 0; i < ListSubWeaponInstance::getListSupWeapon()->size(); i++)
	{
		auto obj = ListSubWeaponInstance::getListSupWeapon()->at(i);
		obj->render(CAMERA);
	}
	//VAMPIRE_BAT->render(CAMERA);
}

void Level::handleRenderTileMap()
{
	if (PLAYER->getIsHaveHolyCross()) {
		effectHollyCrossDelay.update();
		if (effectHollyCrossTime.atTime()) {
			if (flatRenderTileMap) {
				tilemap.Render(CAMERA);
				flatRenderTileMap = false;
				goto checkstop;
			}
			if (!flatRenderTileMap) {
				flatRenderTileMap = true;
			}
		}

	checkstop:
		if (effectHollyCrossDelay.isTerminated()) {
			PLAYER->setIsHaveHolyCross(false);
		}
	}
	else {
		tilemap.Render(CAMERA);
	}
}



Level::~Level()
{
}
