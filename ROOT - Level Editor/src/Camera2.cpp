#include "Camera2.h"
#include"Vector2D.h"

Camera2::Camera2(Vector2D *p_position, int p_width, int p_height)
{
	m_position = p_position;
	m_width = p_width;
	m_height = p_height;
}

Camera2::Camera2()
{
	m_position = nullptr;
}

Camera2::~Camera2()
{
	End();
}

int Camera2::GetWidth() const
{
	return m_width;
}

int Camera2::GetHeight() const
{
	return m_height;
}

Vector2D *Camera2::GetPosition() const
{
	return m_position;
}

int Camera2::GetxPosition() const
{
	return m_position->GetX();
}

int Camera2::GetyPosition() const
{
	return m_position->GetY();
}

void Camera2::SetWidth(int p_width)
{
	m_width = p_width;
}

void Camera2::SetHeight(int p_height)
{
	m_height = p_height;
}

void Camera2::SetPosition(Vector2D *p_position)
{
	if (!m_position)
	{
		m_position = p_position;
		return;
	}

	delete m_position;
	m_position = p_position;
}

void Camera2::SetPosition(int p_x, int p_y)
{
	m_position->SetX(p_x);
	m_position->SetY(p_y);
}

void Camera2::SetxPosition(int p_x)
{
	m_position->SetX(p_x);
}

void Camera2::SetyPosition(int p_y)
{
	m_position->SetY(p_y);
}

void Camera2::UpDate(int p_x, int p_y)
{
	SetPosition(GetxPosition() + p_x, GetyPosition() + p_y);
}

void Camera2::End()
{
	if (m_position)
	{
		delete m_position;
		m_position = nullptr;
	}
}