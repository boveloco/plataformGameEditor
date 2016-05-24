#include "Button.h"
#include"RigidBody2D.h"
#include"Texture.h"
#include"GamePlay.h"

Button::Button(Texture *p_image, RidigBody2D *p_tranform) : 
		m_image(p_image), m_transform(p_tranform), m_press(false)
{}

Button::~Button()
{
	if (m_image)
	{
		delete m_image;
		m_image = nullptr;
	}
	if (m_transform)
	{
		delete m_transform;
		m_transform = nullptr;
	}
}

Texture *Button::GetImage() const
{
	return m_image;
}

RidigBody2D *Button::GetTransform() const
{
	return m_transform;
}

bool Button::GetPress() const
{
	return m_press;
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

Button *Button::SetTransform(RidigBody2D *p_transform)
{
	if(!m_transform)
		m_transform = p_transform;

	return this;
}

Button *Button::SetPress(bool p_press)
{
	m_press = p_press;

	return this;
}
