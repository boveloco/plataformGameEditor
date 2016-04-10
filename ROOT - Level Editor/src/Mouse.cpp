#include "Mouse.h"
#include"Vector2D.h"
#include"Texture.h"
#include"GamePlay.h"

Texture *Mouse::m_image = nullptr;
Vector2D *Mouse::m_position = nullptr;

Mouse::Mouse(Texture *p_image, Vector2D *p_position)
{
	m_image = p_image;
	m_position = p_position;
}

Mouse::Mouse()
{}

Mouse::~Mouse()
{
	if (m_image)
	{
		delete m_image;
		m_image = nullptr;
	}
	if (m_position)
	{
		delete m_position;
		m_position = nullptr;
	}
}

Vector2D *Mouse::GetPosition()
{
	return m_position;
}

int Mouse::GetX()
{
	return m_position->GetX();
}

int Mouse::GetY()
{
	return m_position->GetY();
}

int Mouse::GetWidth()
{
	return m_image->GetWidth();
}

int Mouse::GetHeight()
{
	return m_image->GetHeight();
}

Texture *Mouse::GetImage()
{
	return m_image;
}

void Mouse::SetPosition(int p_x, int p_y)
{
	m_position->SetX(p_x);
	m_position->SetY(p_y);
}

void Mouse::SetX(int p_x)
{
	m_position->SetX(p_x);
}

void Mouse::SetY(int p_y)
{
	m_position->SetY(p_y);
}

void Mouse::SetImage(Texture *p_image)
{
	if (!m_image)
	{
		m_image = p_image;
		return;
	}

	delete m_image;
	m_image = p_image;
}

void Mouse::Draw()
{
	m_image->Draw(GamePlay::GetRenderer(), m_position, 0, 0);
}
