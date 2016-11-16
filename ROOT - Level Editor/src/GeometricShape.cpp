#include "GeometricShape.h"
#include"Vector2D.h"

GeometricShape::GeometricShape(Vector2D * p_position, Type p_type) : 
	            m_position(p_position), m_type(p_type)
{}

float GeometricShape::GetX() const
{
	return m_position->GetX();
}

float GeometricShape::GetY() const
{
	return m_position->GetY();
}

Type GeometricShape::GetType() const
{
	return m_type;
}
