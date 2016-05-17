#pragma once
#include"GeometricShape.h"

class Box : public GeometricShape
{
private:
	int m_height;
	int m_width;

public:
	Box(Vector2D *, int, int);
	~Box();
	int GetHeight() const;
	int GetWidth() const;
	Box *SetHeight(int);
	Box *SetWidth(int);
	virtual Box *SetPosition(Vector2D *);
	virtual Vector2D *GetPosition() const;
};
