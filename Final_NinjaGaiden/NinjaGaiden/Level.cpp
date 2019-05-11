#include "Level.h"
#include "Player.h"
Level::Level()
{
	flatRenderTileMap = true;
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
	/*string tilesheetString = folderPathString; tilesheetString.append("/tilesheet.png");
	string matrixPathString = folderPathString; matrixPathString.append("/matrix.dat");*/
	string objectPathString = folderPathString; objectPathString.append("/map3.1/objects.dat");
	string objectTagGroupPath = folderPathString; objectTagGroupPath.append("/map3.1/collision_type_collides.dat");
	string worldChildsPath = folderPathString; worldChildsPath.append("/map3.1/worldChilds.dat");

	tilemap.Init(folderPath);

	InitAllObjectsInLevel(objectPathString.c_str());

	//objectTagGroupManager->readInformationFromFile(objectTagGroupPath.c_str());
	worldChildManager = WORLD_CHILD_MANAGER;
	worldChildManager->readInformationWorldChild(worldChildsPath.c_str());
	worldChildManager->setCurrentWorldChild(0);
	worldChildManager->resetLocationInWorldChild();
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
		

		switch (id)
		{
		
		default:
			obj = new BaseObject();
			break;
		}
		obj->onInitFromFile(fs, worldHeight);
		grid->addObjectToGrid(obj);
	}
}


void Level::update(float dt)
{
	vector<BaseObject*> allObjectsHaveToWork = grid->getAllObjectsHaveToWork();
	for (size_t i = 0; i < allObjectsHaveToWork.size(); i++)
	{
		Collision::CheckCollision(PLAYER, allObjectsHaveToWork[i]);
	}

	CAMERA->update();
	PLAYER->update(dt);
	
}

void Level::render()
{
	handleRenderTileMap();
	PLAYER->render(CAMERA);
}

void Level::handleRenderTileMap()
{
	tilemap.Render(CAMERA);
}



Level::~Level()
{
}
