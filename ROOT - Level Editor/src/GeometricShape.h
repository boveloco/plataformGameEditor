#pragma once

enum Type
{
	BOX,
	CIRCLE
};

class Vector2D;

class GeometricShape
{
protected:
	Vector2D *m_position;
	Type m_type;
public:
	GeometricShape(Vector2D *, Type);
	virtual ~GeometricShape() {};
	virtual GeometricShape *SetPosition(Vector2D *) = 0;
	virtual Vector2D *GetPosition() const = 0;
	float GetX() const;
	float GetY() const;
	Type GetType() const;
};
