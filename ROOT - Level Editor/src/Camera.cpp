#include "Camera.h"
#include "Map.h"
#include "Vector2D.h"
#include "SpriteSet.h"
#include "Defines.h"
#include"GamePlay.h"
#include"Scene.h"

Camera::Camera(Vector2D *p_position, int p_width, int p_height, Map* map, SpriteSet* spriteSet) :
	spriteSet(spriteSet), map(map), m_position(p_position), m_width(p_width), m_height(p_height)
{}

Camera::Camera()
{
	m_position = nullptr;
}

Camera::~Camera()
{
	End();
}

int Camera::GetWidth() const
{
	return m_width;
}

int Camera::GetHeight() const
{
	return m_height;
}

Vector2D *Camera::GetPosition() const
{
	return m_position;
}

int Camera::GetPosition(int indice)
{
	if (indice > 1)
		return EOF;
	if (indice == CAMERA_X) {
		int x = this->m_position->GetX();
		int xMapSize = map->getXSize();
		int xSpriteSize = spriteSet->getXSize();
		if (x < 0)
			return 0;
		if (x  > xMapSize*xSpriteSize+(xSpriteSize*4)-SIZE_WINDOW_X)
			return x = xMapSize*xSpriteSize + (xSpriteSize * 4) -SIZE_WINDOW_X;
		return x;
	}
	if (indice == CAMERA_Y) {
		int y = this->m_position->GetY();
		int yMapSize = map->getYSize();
		int ySpriteSize = spriteSet->getYSize();
		if (y < 0)
			return 0;
		if (y > yMapSize*ySpriteSize - SIZE_WINDOW_Y)
			return yMapSize*ySpriteSize - SIZE_WINDOW_Y;
		return y;
	}
}

int Camera::GetxPosition() const
{
	return m_position->GetX();
}

int Camera::GetyPosition() const
{
	return m_position->GetY();
}

void Camera::SetWidth(int p_width)
{
	m_width = p_width;
}

void Camera::SetHeight(int p_height)
{
	m_height = p_height;
}

void Camera::SetPosition(Vector2D *p_position)
{
	if (!m_position)
	{
		m_position = p_position;
		return;
	}

	delete m_position;
	m_position = p_position;
}

void Camera::SetPosition(int indice, int value)
{
	if (indice > 1 || indice < 0)
		return;

	value = value < 0 ? 0 : value;
	/*int ssSizeX = this->spriteSet->getXSize();
	int ssSizeY = this->spriteSet->getYSize();
	int mapSizeX = this->map->getXSize();
	int mapSizeY = this->map->getYSize();*/

	if (indice == CAMERA_X) {
		this->m_position->SetX(value);
	}
	if (indice == CAMERA_Y) {
		this->m_position->SetY(value);
	}

}

void Camera::SetxPosition(int p_x)
{
	m_position->SetX(p_x);
}

void Camera::SetyPosition(int p_y)
{
	m_position->SetY(p_y);
}

void Camera::UpDate(int p_x, int p_y)
{
	this->SetPosition(CAMERA_X, this->GetPosition(CAMERA_X) + p_x);
	this->SetPosition(CAMERA_Y, this->GetPosition(CAMERA_Y) + p_y);
}

void Camera::End()
{
	if (m_position)
	{
		delete m_position;
		m_position = nullptr;
	}
}

void Camera::SetPositionEditor(int p_index, int p_value)
{
	if (p_index > 1)
		return;

	p_value = p_value < 0 ? 0 : p_value;
	/*int ssSizeX = this->spriteSet->getXSize();
	int ssSizeY = this->spriteSet->getYSize();
	int mapSizeX = this->map->getXSize();
	int mapSizeY = this->map->getYSize();*/

	if (p_index == CAMERA_X) 
	{
		this->m_position->SetX(p_value);
	}
	if (p_index == CAMERA_Y) 
	{
		this->m_position->SetY(p_value);
	}
}

int Camera::GetPositionEditor(int p_index) const
{
	if (p_index > 1)
		return EOF;
	if (p_index == CAMERA_X) {
		int x = this->m_position->GetX();
		int xMapSize = map->getXSize();
		int xSpriteSize = spriteSet->getXSize();
		if (x < 0)
			return 0;
		if (x  > xMapSize*xSpriteSize + (xSpriteSize * 4) - SIZE_WINDOW_X)
			return x = xMapSize*xSpriteSize + (xSpriteSize * 4) - SIZE_WINDOW_X;
		return x;
	}
	if (p_index == CAMERA_Y) {
		int y = this->m_position->GetY();
		int yMapSize = map->getYSize();
		int ySpriteSize = spriteSet->getYSize();
		if (y < 0)
			return 0;
		if (y > yMapSize*ySpriteSize - SIZE_WINDOW_Y)
			return yMapSize*ySpriteSize - SIZE_WINDOW_Y;
		return y;
	}
}
