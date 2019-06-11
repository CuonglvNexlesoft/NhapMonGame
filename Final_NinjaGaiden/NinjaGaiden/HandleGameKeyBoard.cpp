#include "HandleGameKeyBoard.h"
#include "Game.h"
#include "WorldChildManager.h"


void HandleGameKeyBoard::OnKeyDown(int KeyCode)
{

	if (PLAYER->getPlayerState() == PLAYER_STATE_NORMAL) {
		//Ở dưới đất
		if (PLAYER->isGrounded()) {
			//Nhảy lên
			if (GAME->IsKeyDown(DIK_S)) {
				PLAYER->setVy(PLAYER_VY_JUMP);
				PLAYER->setAction(PLAYER_ACTION_JUMP);
			}
			//Đánh
			if (GAME->IsKeyDown(DIK_A)) {
				PLAYER->setPlayerState(PLAYER_STATE_ATTACK);
				//PLAYER->setAction(PLAYER_ACTION_STAND_ATTACK);
				PLAYER->setAction(PLAYER_ACTION_STAND_ATTACK);
			}

		}
		//Đang bay
		else {
			//Đánh được
			if (GAME->IsKeyDown(DIK_A)) {
				PLAYER->setAction(PLAYER_ACTION_JUMP_ATTACK);
				//PLAYER->setAction(PLAYER_ACTION_JUMP);

				PLAYER->setPlayerState(PLAYER_STATE_ATTACK);
			}
			
		
		}
	}
	else if (PLAYER->getPlayerState() == PLAYER_STATE_SEAT) {
		if (GAME->IsKeyDown(DIK_DOWN)) {
			PLAYER->setAction(PLAYER_ACTION_SEAT);
			if (GAME->IsKeyDown(DIK_A)) {
				PLAYER->setAction(PLAYER_ACTION_SIT_ATTACK);
				PLAYER->setPlayerState(PLAYER_STATE_ATTACK);
			}
		}
	}
}

void HandleGameKeyBoard::KeyState(BYTE * states)
{
	PLAYER->updatePlayerEvent();

	if (PLAYER->getPlayerState() == PLAYER_STATE_NORMAL) {
		//Ở dưới đất
		if (PLAYER->isGrounded()) {
			//Ngồi xuống
			if (GAME->IsKeyDown(DIK_DOWN))
			{
				PLAYER->setHeight(PLAYER_SEAT_HEIGHT); //theo trong luc rot xuong
				PLAYER->setPlayerState(PLAYER_STATE_SEAT);
				PLAYER->setAction(PLAYER_ACTION_SEAT);
				return;
			}
			//Qua phải
			if (GAME->IsKeyDown(DIK_RIGHT)) {
				PLAYER->setDir(RIGHT);
				PLAYER->setAction(PLAYER_ACTION_RUN);
				PLAYER->setVx(PLAYER_VX);
			}
			//Qua trái	
			else if (GAME->IsKeyDown(DIK_LEFT)) {
				//PLAYER->setDir(RIGHT);
				PLAYER->setDir(LEFT);
				PLAYER->setAction(PLAYER_ACTION_RUN);
				PLAYER->setVx(-PLAYER_VX);
			}
			//Dừng
			else {
				PLAYER->setAction(PLAYER_ACTION_STAND);
				PLAYER->setVx(0);
			}
		}
		//Đang bay
		else {
			PLAYER->setAction(PLAYER_ACTION_JUMP);
			//Qua phải
			if (GAME->IsKeyDown(DIK_RIGHT)) {
				PLAYER->setVx(PLAYER_VX);
			}
			//Qua trái	
			else if (GAME->IsKeyDown(DIK_LEFT)) {
				PLAYER->setVx(-PLAYER_VX);
			}
		}
	}
	else if (PLAYER->getPlayerState() == PLAYER_STATE_SEAT) {
		//Thả nút xuống ra thì đứng lên
		if (!GAME->IsKeyDown(DIK_DOWN))
		{
			PLAYER->setY(PLAYER->getY() + (PLAYER_NORMAL_HEIGHT - PLAYER_SEAT_HEIGHT));
			PLAYER->setHeight(PLAYER_NORMAL_HEIGHT);
			PLAYER->setPlayerState(PLAYER_STATE_NORMAL);
		}
	}
	
}


void HandleGameKeyBoard::OnKeyUp(int KeyCode)
{
}

HandleGameKeyBoard::HandleGameKeyBoard()
{
}
