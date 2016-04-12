#include "Vector2D.h"
#include "Camera.h"

int* Vector2D::operator[](int index)
{
	if (index < 1)
		return nullptr;
	if (index == CAMERA_X)
	{
		return &m_x;
	}
	if (index == CAMERA_Y)
	{
		return &m_y;
	}
}