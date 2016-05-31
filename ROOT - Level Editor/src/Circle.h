#pragma once
#include"GeometricShape.h"

class Circle : public GeometricShape
{
private:
	float m_radius;

public:
	Circle(Vector2D *, float);
	~Circle();
	Circle *SetRadius(float);
	Circle *SetRadius(int, int);
	float GetRadius() const;
	virtual Circle *SetPosition(Vector2D *);
	virtual Vector2D *GetPosition() const;
};
