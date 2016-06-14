#include "Tile.h"
#include"Texture.h"
#include"Box.h"
#include"Vector2D.h"
#include"GamePlay.h"

Tile::Tile(Texture *p_image, Vector2D *p_position, int p_inX, int p_inY) :
		  m_image(p_image), m_position(p_position), m_indexX(p_inX), m_indexY(p_inY),
		  m_collider(nullptr)
{
}

Tile::~Tile()
{
	if (m_position)
	{
		delete m_position;
		m_position = nullptr;
	}
	if (m_collider)
	{
		delete m_collider;
		m_collider = nullptr;
	}
}

Vector2D *Tile::GetPosition() const
{
	return m_position;
}

float Tile::GetX() const
{
	return m_position->GetX();
}

float Tile::GetY() const
{
	return m_position->GetY();
}

Texture *Tile::GetImage() const
{
	return m_image;
}

GeometricShape *Tile::GetCollider() const
{
	return m_collider;
}

int Tile::GetIndexX() const
{
	return m_indexX;
}

int Tile::GetIndexY() const
{
	return m_indexY;
}

void Tile::Initialize()
{
	m_collider = new Box(m_position, m_image->GetWidth(), m_image->GetHeight());
}

void Tile::Draw()
{
	m_image->Draw(GamePlay::GetRenderer(), m_position, m_indexX, m_indexY);
}
