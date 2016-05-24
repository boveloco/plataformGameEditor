#include"RigidBody2D.h"
#include"Vector2D.h"
#include"Box.h"
#include"Circle.h"

RigidBody2D::RigidBody2D(Vector2D *p_position, GeometricShape *p_collider) :
	         m_position(p_position), m_collider(p_collider), m_static(false),
			 m_velocity(new Vector2D(0, 0)), m_direction(new Vector2D(1, 0)), 
			 m_up(new Vector2D(0, 1))
{}

RigidBody2D::~RigidBody2D()
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
	if(m_velocity)
	{
		delete m_velocity;
		m_velocity = nullptr;
	}
	if (m_direction)
	{
		delete m_direction;
		m_direction = nullptr;
	}
	if (m_up)
	{
		delete m_up;
		m_up = nullptr;
	}
}

Vector2D *RigidBody2D::GetPosition() const
{
	return m_position;
}

Vector2D *RigidBody2D::GetDirection() const
{
	return m_direction;
}

Vector2D *RigidBody2D::GetVelocity() const
{
	return m_velocity;
}

float RigidBody2D::GetX() const
{
	return m_collider->GetX();
}

float RigidBody2D::GetY() const
{
	return m_position->GetY();
}

GeometricShape *RigidBody2D::GetCollider() const
{
	return m_collider;
}

bool RigidBody2D::GetStatic() const
{
	return m_static;
}

RigidBody2D *RigidBody2D::SetPosition(Vector2D *p_position)
{
	m_position = p_position;

	return this;
}

RigidBody2D *RigidBody2D::SetPosition(float p_x, float p_y)
{
	m_position->SetX(p_x);
	m_position->SetY(p_y);

	return this;
}

RigidBody2D *RigidBody2D::SetDirection(Vector2D *p_direction)
{
	m_direction = p_direction;

	return this;
}

RigidBody2D *RigidBody2D::SetVelocity(Vector2D *p_velocity)
{
	m_velocity = p_velocity;

	return this;
}

RigidBody2D *RigidBody2D::SetDirection(float p_x, float p_y)
{
	m_direction->SetX(p_x);
	m_direction->SetY(p_y);

	return this;
}

RigidBody2D *RigidBody2D::SetVelocity(float p_x, float p_y)
{
	m_velocity->SetX(p_x);
	m_velocity->SetY(p_y);

	return this;
}

RigidBody2D *RigidBody2D::SetCollider(GeometricShape *p_collider)
{
	if (!m_collider)
		m_collider = p_collider;

	return this;
}

RigidBody2D *RigidBody2D::SetStatic(bool p_static)
{
	m_static = p_static;

	return this;
}

RigidBody2D *RigidBody2D::AddForce(Vector2D *p_force)
{
	*m_velocity -= *p_force;

	return this;
}
