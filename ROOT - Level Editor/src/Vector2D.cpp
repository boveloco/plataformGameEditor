#include "Vector2D.h"
#include "Camera.h"

float Vector2D::operator[](int index)
{
	if (index < 1)
		return EOF;
	if (index == CAMERA_X)
	{
		return m_x;
	}
	if (index == CAMERA_Y)
	{
		return m_y;
	}
}

Vector2D &Vector2D::operator+=(Vector2D &p_vector)
{
	this->m_x += p_vector.GetX();
	this->m_y += p_vector.GetY();

	return *this;
}

Vector2D &Vector2D::operator+=(float p_value)
{
	this->m_x += p_value;
	this->m_y += p_value;

	return *this;
}

Vector2D Vector2D::operator+(Vector2D &p_vector)
{
	return Vector2D(m_x + p_vector.GetX(),
		m_y + p_vector.GetY());
}

Vector2D Vector2D::operator+(float p_value)
{
	return Vector2D(m_x + p_value,
		m_y + p_value);
}

Vector2D &Vector2D::operator-=(Vector2D &p_vector)
{
	this->m_x -= p_vector.GetX();
	this->m_y -= p_vector.GetY();

	return *this;
}

Vector2D &Vector2D::operator-=(float p_value)
{
	this->m_x -= p_value;
	this->m_y -= p_value;

	return *this;
}

Vector2D Vector2D::operator-(Vector2D &p_vector)
{
	return Vector2D(m_x - p_vector.GetX(),
		m_y - p_vector.GetY());
}

Vector2D Vector2D::operator-(float p_value)
{
	return Vector2D(m_x + p_value,
		m_y + p_value);
}

Vector2D &Vector2D::operator*=(Vector2D &p_vector)
{
	this->m_x *= p_vector.GetX();
	this->m_y *= p_vector.GetY();

	return *this;
}

Vector2D &Vector2D::operator*=(float p_value)
{
	this->m_x *= p_value;
	this->m_y *= p_value;

	return *this;
}

Vector2D Vector2D::operator*(Vector2D &p_vector)
{
	return Vector2D(m_x * p_vector.GetX(),
		m_y * p_vector.GetY());
}

Vector2D Vector2D::operator*(float p_value)
{
	return Vector2D(m_x * p_value,
		m_y * p_value);
}