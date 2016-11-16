#include "MiniTile.h"
#include"Texture.h"
#include"Box.h"
#include"Vector2D.h"
#include"GamePlay.h"

MiniTile::MiniTile(Texture *p_image, Vector2D *p_position, int p_inX, int p_inY) :
		  m_image(p_image), m_position(p_position), m_indexX(p_inX), m_indexY(p_inY),
		  m_collider(nullptr)
{
}

MiniTile::~MiniTile()
{
}

Vector2D *MiniTile::GetPosition() const
{
	return m_position;
}

float MiniTile::GetX() const
{
	return m_position->GetX();
}

float MiniTile::GetY() const
{
	return m_position->GetY();
}

Texture *MiniTile::GetImage() const
{
	return m_image;
}

GeometricShape *MiniTile::GetCollider() const
{
	return m_collider;
}

int MiniTile::GetIndexX() const
{
	return m_indexX;
}

int MiniTile::GetIndexY() const
{
	return m_indexY;
}

void MiniTile::Initialize()
{
	m_collider = new Box(m_position, m_image->GetWidth() / 2, m_image->GetHeight() / 2);
}

void MiniTile::Draw()
{
	m_image->Draw(GamePlay::GetRenderer(), m_position, m_indexX, m_indexY,
				  m_image->GetWidth() / 2, m_image->GetHeight() / 2);
}
