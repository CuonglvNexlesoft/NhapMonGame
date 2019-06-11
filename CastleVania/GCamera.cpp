#include "GCamera.h"

GCamera::GCamera(float x, float y, int minSize, int maxSize)
{
	float vx;
	if (x - G_ScreenWidth / 2 <= minSize) vx = minSize;
	else
		if (x + G_ScreenWidth / 2 >= maxSize ) vx = maxSize - G_ScreenWidth;
		else
			vx = x - G_ScreenWidth / 2;

	_minSize = minSize;
	_maxSize = maxSize;

	switch (State)
	{
		case 0:
		{
			viewport.x = minSize;
			viewport.y = G_ScreenHeight;
			break;
		}
		case 1:
		{
			viewport.x = vx;
			viewport.y = G_ScreenHeight;
			break;
		}
		case 2:
		{
			viewport.x = vx;
			viewport.y = G_ScreenHeight + 384;
			break;
		}
		case 3:
		{
			viewport.x = vx;
			viewport.y = G_ScreenHeight;
			break;
		}
	}

	//Cài đặt để test game
	if (State == 3)
	{
		if (y < 384) return;
		if (y < 384 * 2)
		{
			viewport.y = G_ScreenHeight + 384;
			return;
		}
		if (y < 384 * 3)
		{
			viewport.y = G_ScreenHeight + 384 * 2;
			return;
		}
		if (y < 384 * 4)
		{
			viewport.y = G_ScreenHeight + 384*3;
			return;
		}
	}
	//viewport.y -= AutoFit*(State != 0);
}

void GCamera::SetSizeMap(int _min, int _max)
{
	_maxSize = _max;
	_minSize = _min;
}

int GCamera::GetMaxSize()
{
	return _maxSize;
}

int GCamera::GetMinSize()
{
	return _minSize;
}


D3DXVECTOR2 GCamera::Transform(int x, int y)
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	matrix._22 = -1;
	matrix._41 = -viewport.x;
	matrix._42 = viewport.y;

	D3DXVECTOR3 pos3(x, y, 1);
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform(&MatrixResult, &pos3, &matrix);

	D3DXVECTOR2 result = D3DXVECTOR2(MatrixResult.x, MatrixResult.y);
	return result;
}

D3DXVECTOR3 GCamera::CenterSprite(int x, int y)
{
	D3DXVECTOR3 pCenter = D3DXVECTOR3(x / 2, y / 2, 0);
	return pCenter;
}

void GCamera::UpdateCamera(int x)
{
	//Tự viết dự vào hướng dẫn của GV LT
}

void GCamera::UpdateCamera()
{
	/*if ((viewport.x + _VCameraX >= _minSize) && (viewport.x + _VCameraX + G_ScreenWidth <= _maxSize))
	{
		viewport.x += _VCameraX;
		return;
	}

	if (viewport.x + _VCameraX + G_ScreenWidth > _maxSize)
	{
		viewport.x += _maxSize - G_ScreenWidth - viewport.x;
		return;
	}

	if (viewport.x + _VCameraX < 0)
	{
		viewport.x = 0;
		return;
	}*/
	if ((_FolowPosX >= G_ScreenWidth / 2 + viewport.x && _VCameraX>0) || (_FolowPosX <= viewport.x + G_ScreenWidth / 2 && _VCameraX<0))
	{
		viewport.x += _VCameraX;
	}
	
	if (viewport.x + G_ScreenWidth > _maxSize) viewport.x = _maxSize - G_ScreenWidth;
	if (viewport.x < _minSize) viewport.x = _minSize;
}

void GCamera::SetVCam(float vcamX,float vcamY)
{
	/*if (vcamX > 0)
	{
		if ((_FolowPosX >= G_ScreenWidth / 2 + vcamX + _minSize) && (_FolowPosX <= _maxSize - G_ScreenWidth / 2))
		{
			_VCameraX = vcamX;
			return;
		}
		if ((_FolowPosX >= G_ScreenWidth / 2 + _minSize) && (_FolowPosX < G_ScreenWidth / 2 + vcamX + _minSize))
		{
			_VCameraX = _FolowPosX - G_ScreenWidth / 2 - _minSize;
			return;
		}
		if ((_FolowPosX > _maxSize - G_ScreenWidth / 2) && (_FolowPosX <= _maxSize - G_ScreenWidth / 2 + vcamX))
		{
			_VCameraX = _maxSize - G_ScreenWidth / 2 - (_FolowPosX - vcamX);
			return;
		}
	}
	if (vcamX < 0)
	{
		if ((_FolowPosX >= G_ScreenWidth / 2 + _minSize) && (_FolowPosX <= _maxSize - G_ScreenWidth / 2 + vcamX))
		{
			_VCameraX = vcamX;
			return;
		}
		if ((_FolowPosX >= G_ScreenWidth / 2 + vcamX + _minSize) && (_FolowPosX < G_ScreenWidth / 2))
		{
			_VCameraX = vcamX + (G_ScreenWidth / 2 - _FolowPosX + _minSize);
			return;
		}
		if ((_FolowPosX > _maxSize - G_ScreenWidth / 2 + vcamX) && (_FolowPosX <= _maxSize - G_ScreenWidth / 2))
		{
			_VCameraX = _FolowPosX - (_maxSize - G_ScreenWidth / 2);
			return;
		} 
	}
	_VCameraX = 0;*/

	_VCameraX = vcamX;
}

void GCamera::SetFolowPos(float x, float y)
{
	_FolowPosX = x;
	_FolowPosY = y;
}



