#include "Circle.h"

Circle::Circle(Vector2D *p_position, float p_radius) :
	GeometricShape(p_position, CIRCLE), m_radius(p_radius)
{}

Circle::~Circle()
{
	if (m_position)
	{
		delete m_position;
		m_position = nullptr;
	}
}

Circle *Circle::SetRadius(float p_radius)
{
	m_radius = p_radius;

	return this;
}

Circle *Circle::SetRadius(int p_width, int height)
{
	return this;
}

float Circle::GetRadius() const
{
	return m_radius;
}

Circle *Circle::SetPosition(Vector2D *p_position)
{
	if (!m_position)
		m_position = p_position;

	return this;
}

Vector2D *Circle::GetPosition() const
{
	return m_position;
}

