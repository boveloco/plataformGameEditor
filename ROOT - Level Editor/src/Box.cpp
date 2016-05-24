#include "Box.h"

Box::Box(Vector2D *p_position, int p_width, int p_height) :
	GeometricShape(p_position, BOX), m_width(p_width), m_height(p_height)
{}

Box::~Box()
{
	if (m_position)
	{
		delete m_position;
		m_position = nullptr;
	}
}

int Box::GetHeight() const
{
	return m_height;
}

int Box::GetWidth() const
{
	return m_width;
}

Box *Box::SetHeight(int p_height)
{
	m_height = p_height;

	return this;
}

Box *Box::SetWidth(int p_width)
{
	m_width = p_width;

	return this;
}

Box *Box::SetPosition(Vector2D *p_posicao)
{
	if (!m_position)
		m_position = p_posicao;

	return nullptr;
}

Vector2D *Box::GetPosition() const
{
	return m_position;
}

