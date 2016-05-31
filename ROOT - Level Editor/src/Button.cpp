#include "Button.h"
#include"RigidBody2D.h"
#include"Texture.h"
#include"GamePlay.h"
#include"Vector2D.h"
#include"Box.h"

Button::Button(Texture *p_image, RigidBody2D *p_tranform) :
		m_image(p_image), m_transform(p_tranform), m_press(false)
{}

Button::~Button()
{
	End();
}

Texture *Button::GetImage() const
{
	return m_image;
}

RigidBody2D *Button::GetTransform() const
{
	return m_transform;
}

Vector2D *Button::GetPosition() const
{
	return m_transform->GetPosition();
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

Button *Button::SetTransform(RigidBody2D *p_transform)
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

void Button::Initialize()
{
	m_transform->SetStatic(true);
	m_transform->SetCollider(new Box(GetPosition(), 
									 m_image->GetWidth(), 
									 m_image->GetHeight()));
}

void Button::Draw()
{
	m_image->Draw(GamePlay::GetRenderer(), GetPosition());
}

void Button::End()
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
