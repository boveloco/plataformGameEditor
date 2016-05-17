#include "GeometricShape.h"
#include"Vector2D.h"

GeometricShape::GeometricShape(Vector2D * p_position) : m_position(p_position)
{}

float GeometricShape::GetX() const
{
	return m_position->GetX();
}

float GeometricShape::GetY() const
{
	return m_position->GetY();
}
