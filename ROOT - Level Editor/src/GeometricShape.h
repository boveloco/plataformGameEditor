#pragma once

class Vector2D;

class GeometricShape
{
protected:
	Vector2D *m_position;

public:
	GeometricShape(Vector2D *p_position = nullptr);
	virtual ~GeometricShape() {};
	virtual GeometricShape *SetPosition(Vector2D *) = 0;
	virtual Vector2D *GetPosition() const = 0;
	float GetX() const;
	float GetY() const;
};
