#include "Player.h"
#include "debug.h"
#include "Game.h"
#include"Camera.h"
#include <string>


Player::Player()
{
	
	setWidth(PLAYER_WIDTH);
	setHeight(PLAYER_NORMAL_HEIGHT);
	setPhysicsEnable(true);
	setPlayerState(PLAYER_STATE_NORMAL);
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_SIMON));
	setSubWeapon(PLAYER_NO_SUBWEAPON);
	eatEffectDelay.init(1000);
	flashEffectDelay.init(600);
	flashEffectTime.init(20);
	deadActionTime.init(2000);
}

Player * Player::instance = 0;

Player * Player::getInstance()
{
	if (instance == 0) {
		instance = new Player();
	}
	return instance;
}

PLAYER_STATE Player::getPlayerState()
{
	return this->playerState;
}

void Player::setPlayerState(PLAYER_STATE playerState)
{
	this->playerState = playerState;
}

void Player::setAction(int action)
{
	BaseObject::setAction(getDir()*PLAYER_ACTION_COUNT + action);
	//BaseObject::setAction( action);
}

void Player::updatePlayerEvent()
{
	//DebugOut((wchar_t*)L"Update getAction %d \n", getAction());

	switch (PLAYER->getPlayerState())
	{
	case PLAYER_STATE_SEAT:
		PLAYER->setVx(0);
		break;
	case PLAYER_STATE_NORMAL:
		PLAYER->handleUndyingStatePlayer();
		break;
	case PLAYER_STATE_DIE:
		if (PLAYER->isGrounded()) {
			PLAYER->setVx(0);
			PLAYER->setVy(0);
			PLAYER->setDx(0);
			PLAYER->setDy(0);
			PLAYER->setIsUndying(true);
			PLAYER->flashEffectDelay.start(600);
			PLAYER->setPlayerState(PLAYER_STATE_NORMAL);
		}
		break;
	case PLAYER_STATE_ATTACK:
		if (PLAYER->getIsLastFrameAnimationDone())
		{
			PLAYER->setPlayerState(PLAYER_STATE_NORMAL);
			PLAYER->setY(PLAYER->getY() + (PLAYER_NORMAL_HEIGHT - PLAYER_SEAT_HEIGHT));
			PLAYER->setHeight(PLAYER_NORMAL_HEIGHT);
		}
		break;
	case PLAYER_STATE_ATTACK_SUBWEAPON:
		if (PLAYER->getIsLastFrameAnimationDone())
		{
			PLAYER->setPlayerState(PLAYER_STATE_NORMAL);
			PLAYER->setY(PLAYER->getY() + (PLAYER_NORMAL_HEIGHT - PLAYER_SEAT_HEIGHT));
			PLAYER->setHeight(PLAYER_NORMAL_HEIGHT);
		}
		break;
	case PLAYER_STATE_EAT_EFFECT:
		PLAYER->eatEffectDelay.update();
		if (PLAYER->eatEffectDelay.isTerminated())
		{
			PLAYER->setPlayerState(PLAYER_STATE_NORMAL);
			return;
		}
		//PLAYER->setAction(PLAYER_ACTION_EAT_EFFECT);
		PLAYER->setVx(0);
		PLAYER->setVy(0);
		break;
	case PLAYER_STATE_DEAD:
		PLAYER->setVx(0);
		PLAYER->setDx(0);
		PLAYER->deadActionTime.update();
		if (PLAYER->deadActionTime.isTerminated()) {
				PLAYER->setIsUndying(false);
				WORLD_CHILD_MANAGER->resetLocationInWorldChild();
				PLAYER->setAction(PLAYER_ACTION_STAND);
				PLAYER->setPlayerState(PLAYER_STATE_NORMAL);
				PLAYER->setHeight(PLAYER_NORMAL_HEIGHT);
				PLAYER->setIsAllowUpdateRender(true, true);
		}
		break;
	default:
		break;
	}
}

void Player::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
	if (playerState != PLAYER_STATE_ON_STAIR)
	{
		BaseObject::onCollision(other, collisionTime, nx, ny);
	}
}


void Player::setIsLastFrameAnimationDone(bool isLastFrameAnimationDone)
{
	BaseObject::setIsLastFrameAnimationDone(isLastFrameAnimationDone);
	if (isLastFrameAnimationDone)
		if (playerState == PLAYER_STATE_ATTACK)
			this->setFrame(this->getGraphicsAssets()->getAction(this->getAction())->getFrameCount() - 1);
}

bool Player::getIsUndying()
{
	return this->isUndying;
}

void Player::setIsUndying(bool isUndying)
{
	this->isUndying = isUndying;
}

void Player::handleUndyingStatePlayer()
{
	if (getIsUndying()) {
		flashEffectDelay.update();

		if (flashEffectTime.atTime()) {
			if (getIsAllowRender()) {
				setIsAllowUpdateRender(true, false);
				goto checkstop;
			}
			if (!getIsAllowRender()) {
				setIsAllowUpdateRender(true, true);
			}
		}

	checkstop:
		if (flashEffectDelay.isTerminated()) {
			setIsUndying(false);
			setIsAllowUpdateRender(true, true);
		}
	}
}

void Player::setSubWeapon(PLAYER_SUBWEAPON playerSubWeapon)
{
	this->playerSubWeapon = playerSubWeapon;
}

PLAYER_SUBWEAPON Player::getSubWeapon()
{
	return this->playerSubWeapon;
}

void Player::handleAttackSubWeapon()
{

}

bool Player::getIsHaveHolyCross()
{
	return this->isHaveHolyCross;
}

void Player::setIsHaveHolyCross(bool isHaveHolyCross)
{
	this->isHaveHolyCross = isHaveHolyCross;
}

Player::~Player()
{

}
