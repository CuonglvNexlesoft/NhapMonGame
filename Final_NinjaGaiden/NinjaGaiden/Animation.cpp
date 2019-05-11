#include "Animation.h"



Animation::Animation()
{
}


void Animation::Add(FrameAnimation * r)
{
	animation.push_back(r);
}

FrameAnimation* Animation::Get(unsigned int i)
{
	return animation[i];
}

void Animation::Render(int x, int y, LPDIRECT3DTEXTURE9 texture, int frame)
{
	int currentIndex = frame;
	FrameAnimation* r = Get(currentIndex);

	int anchorX = r->getAnchorX();
	int anchorY = r->getAnchorY();

	CGame::GetInstance()->GetSprite()->Draw(texture,
		r,
		&D3DXVECTOR3(anchorX, anchorY, 0),
		&D3DXVECTOR3(x, y, 0),
		D3DCOLOR_XRGB(255, 255, 255));
}

//void Animation::DrawFlipX(int x, int y)
//{
//	D3DXMATRIX oldMt;
//	G_SpriteHandler->GetTransform(&oldMt);
//
//	D3DXMATRIX newMt;
//	D3DXVECTOR2 center = D3DXVECTOR3(x, y);
//	D3DXVECTOR2 rotate = D3DXVECTOR2(-1, 1);
//
//	D3DXMatrixTransformation2D(&newMt, &center, 0.0f, &rotate, NULL, 0.0f, NULL);
//	D3DXMATRIX finalMt = newMt * oldMt;
//	G_SpriteHandler->SetTransform(&finalMt);
//
//	x += _texture->FrameWidth;
//	this->Draw(x, y);
//
//	G_SpriteHandler->SetTransform(&oldMt);
//}

void Animation::Update(int& frame)
{
	frame++;
	if (frame >= animation.size()) {
		frame = 0;
	}
}

int Animation::getFrameCount()
{
	return animation.size();
}

Animation::~Animation()
{
}
