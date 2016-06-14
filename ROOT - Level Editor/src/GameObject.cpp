#include"GameObject.h"
#include"Texture.h"
#include"Vector2D.h"
#include"RigidBody2D.h"
#include"GeometricShape.h"

GameObject::GameObject()
{
}

GameObject::GameObject(Texture *p_image, Vector2D *p_position, GeometricShape *p_geometricShape) :
			m_image(p_image), m_transform(new RigidBody2D(p_position, p_geometricShape))

{}

GameObject::~GameObject()
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

RigidBody2D *GameObject::GetTransform() const
{
	return m_transform;
}

Vector2D *GameObject::GetPosition() const
{
	return m_transform->GetPosition();
}

int GameObject::GetXPosition() const
{
	return GetPosition()->GetX();
}

int GameObject::GetYPosition() const
{
	return GetPosition()->GetY();
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

GameObject *GameObject::SetTransform(RigidBody2D *p_transform)
{
	if (!m_transform)
	{
		m_transform = p_transform;
	}

	return this;
}

void GameObject::SetPosition(Vector2D *p_position)
{
	if (!GetPosition())
	{
		m_transform->SetPosition(p_position);
		return;
	}

	GetPosition()->SetX(p_position->GetX());
	GetPosition()->SetY(p_position->GetY());
}

void GameObject::SetPosition(int p_x, int p_y)
{
	GetPosition()->SetX(p_x);
	GetPosition()->SetY(p_y);
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