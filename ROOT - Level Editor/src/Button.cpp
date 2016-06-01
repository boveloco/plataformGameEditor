#include "Button.h"
#include"RigidBody2D.h"
#include"Texture.h"
#include"GamePlay.h"
#include"Vector2D.h"
#include"Box.h"

Button::Button(Texture *p_image, Vector2D *p_position, TypeButton p_type) :
		m_image(p_image), m_position(p_position), m_type(p_type), m_press(false)
{}

Button::~Button()
{
	End();
}

Texture *Button::GetImage() const
{
	return m_image;
}

Vector2D *Button::GetPosition() const
{
	return m_position;
}

float Button::GetX() const
{
	return m_position->GetX();
}

float Button::GetY() const
{
	return m_position->GetY();
}

bool Button::GetPress() const
{
	return m_press;
}

TypeButton Button::GetType() const
{
	return m_type;
}

Button *Button::SetTexture(Texture *p_image)
{
	if(!m_image)
		m_image = p_image;

	return this;
}

Button *Button::SetTexture(std::string p_address, int p_width, int p_height)
{
	if(m_image)
		m_image->UploadImage(p_address, GamePlay::GetRenderer(), 
											   p_width, p_height);

	return this;
}

Button *Button::SetPress(bool p_press)
{
	m_press = p_press;

	return this;
}

GeometricShape *Button::GetGeometricShape() const
{
	return m_collider;
}

void Button::Initialize()
{
	m_collider = new Box(new Vector2D(m_position->GetX(), m_position->GetY()), 
				 	                 m_image->GetWidth(), m_image->GetHeight());
}

void Button::Draw()
{
	m_image->Draw(GamePlay::GetRenderer(), m_position);
}

void Button::End()
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
	if (m_collider)
	{
		delete m_collider;
		m_collider = nullptr;
	}
}
