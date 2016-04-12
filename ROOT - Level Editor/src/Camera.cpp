#include "Camera.h"
#include"Vector2D.h"

Camera::Camera(Vector2D *p_position, int p_width, int p_height)
{
	m_position = p_position;
	m_width = p_width;
	m_height = p_height;
}

Camera::Camera()
{
	m_position = nullptr;
}

Camera::~Camera()
{
	End();
}

int Camera::GetWidth() const
{
	return m_width;
}

int Camera::GetHeight() const
{
	return m_height;
}

Vector2D *Camera::GetPosition() const
{
	return m_position;
}

int Camera::GetPosition(int indice)
{
	if (indice > 1)
		return EOF;
	if (indice == CAMERA_X) {
		int x = this->m_position->GetX();
		if (x > 0)
			return x;
		}
	if (indice == CAMERA_Y) {
		int y = this->m_position->GetY();
		if (y > 0)
			return y;
	}
}

int Camera::GetxPosition() const
{
	return m_position->GetX();
}

int Camera::GetyPosition() const
{
	return m_position->GetY();
}

void Camera::SetWidth(int p_width)
{
	m_width = p_width;
}

void Camera::SetHeight(int p_height)
{
	m_height = p_height;
}

void Camera::SetPosition(Vector2D *p_position)
{
	if (!m_position)
	{
		m_position = p_position;
		return;
	}

	delete m_position;
	m_position = p_position;
}

void Camera::SetPosition(int indice, int value)
{
	if (indice > 1)
		return;

	value = value < 0 ? 0 : value;

	if (indice == CAMERA_X) {
		this->m_position->SetX(value);
	}
	if (indice == CAMERA_Y) {
		this->m_position->SetY(value);
	}
}

void Camera::SetxPosition(int p_x)
{
	m_position->SetX(p_x);
}

void Camera::SetyPosition(int p_y)
{
	m_position->SetY(p_y);
}

void Camera::UpDate(int p_x, int p_y)
{
	this->SetPosition(CAMERA_X, this->GetPosition(CAMERA_X) + p_x);
	this->SetPosition(CAMERA_Y, this->GetPosition(CAMERA_Y) + p_y);
}

void Camera::End()
{
	if (m_position)
	{
		delete m_position;
		m_position = nullptr;
	}
}
