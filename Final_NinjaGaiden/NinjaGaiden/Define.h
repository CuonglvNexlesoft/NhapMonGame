#pragma once
#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"Ninja"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 0)
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define MAX_FRAME_RATE 120


#define PLAYER_VX 0.09
//#define PLAYER_VX 0.1

#define PLAYER_VY_JUMP 0.25
#define PLAYER_VX_DIE 0.06
#define PLAYER_VY_DIE 0.1

#define OBJECT_GRAVITY -0.00055
#define PLAYER_STAIR_DX 1
#define PLAYER_STAIR_DY 1

#define PLAYER_NORMAL_HEIGHT 30
#define PLAYER_SEAT_HEIGHT 26
#define PLAYER_DEAD_HEIGHT 15
#define PLAYER_WIDTH 16

#define VX_WATER 0.04
#define VY_WATER 0.15

#define VX_THE_AX 0.05
#define VY_THE_AX 0.25

#define GRAPHICS_ASSETS_MANAGER GraphicsAssetsManager::getInstance()
#define PLAYER Player::getInstance()
#define CAMERA Camera::getInstance()

#define TEXTURE_MANAGER TextureManager::GetInstance()
#define GAME CGame::GetInstance()
#define OBJECT_TAG_GROUP_MANAGER ObjectTagGroupManager::getInstance()
#define GRID Grid::getInstance()
#define WORLD_CHILD_MANAGER WorldChildManager::getInstance()

#define LEVEL Level::getInstance()

enum OBJECT_DIRECTION
{
	RIGHT = 0,
	LEFT = 1
};