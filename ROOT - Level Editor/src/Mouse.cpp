#include "Mouse.h"
#include"Vector2D.h"
#include"Texture.h"
#include"GamePlay.h"

Texture *Mouse::m_image = nullptr;
Vector2D *Mouse::m_position = nullptr;
bool Mouse::m_buttonLeft = false;
bool Mouse::m_buttonRight = false;

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

bool Mouse::GetButtonLeft()
{
	return m_buttonLeft;
}

bool Mouse::GetButtonRight()
{
	return m_buttonRight;
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

void Mouse::SetImage(std::string p_address, int p_width, int p_height)
{
	m_image->UploadImage(p_address, GamePlay::GetRenderer(), p_width, p_height);
}

void Mouse::SetButtonLeft(bool p_left)
{
	m_buttonLeft = p_left;
}

void Mouse::SetButtonRight(bool p_right)
{
	m_buttonRight = p_right;
}

void Mouse::Draw(int p_indexX, int p_indexY)
{
	m_image->Draw(GamePlay::GetRenderer(), m_position, p_indexX, p_indexY,
		          m_image->GetWidth() / 2, m_image->GetHeight() / 2);
}
