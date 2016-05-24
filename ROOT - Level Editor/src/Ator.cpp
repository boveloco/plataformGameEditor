#include"Ator.h"
#include"Texture.h"
#include"Vector2D.h"

Ator::Ator()
{
}

Ator::Ator(Texture *p_image, Vector2D *p_position) :
			m_image(p_image), m_position(p_position)

{}

Ator::~Ator()
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

Vector2D *GameObject::GetPosition() const
{
	return m_position;
}

int GameObject::GetXPosition() const
{
	return m_position->GetX();
}

int GameObject::GetYPosition() const
{
	return m_position->GetY();
}

Texture *GameObject::GetImage() const
{
	return m_image;
}

int GameObject::GetWidth() const
{
	return m_image->GetWidth();
}

int GameObject::GetHeight() const
{
	return m_image->GetHeight();
}

int GameObject::GetXCenter() const
{
	return GetXPosition() + (GetWidth() / 2);
}

int GameObject::GetYCenter() const
{
	return GetYPosition() + (GetHeight() / 2);
}

void GameObject::SetPosition(Vector2D *p_position)
{
	if (!m_position)
	{
		m_position = p_position;
		return;
	}

	m_position->SetX(p_position->GetX());
	m_position->SetY(p_position->GetY());
}

void GameObject::SetPosition(int p_x, int p_y)
{
	m_position->SetX(p_x);
	m_position->SetY(p_y);
}

void GameObject::SetXPosition(int p_x)
{
	m_position->SetX(p_x);
}

void GameObject::SetYPosition(int p_y)
{
	m_position->SetY(p_y);
}

void GameObject::SetImage(Texture *p_image)
{
	if (!m_image)
	{
		m_image = p_image;
	}
}

void GameObject::SetWidth(int p_width)
{
	m_image->SetWidth(p_width);
}

void GameObject::SetHeight(int p_height)
{
	m_image->SetHeight(p_height);
}