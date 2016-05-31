#pragma once
#include<string>

class Texture;
class Vector2D;
class GeometricShape;
class RidigBody2D;

class Button
{
private:
	Texture *m_image;
	//Vector2D *m_position;
	//GeometricShape *m_collider;
	RidigBody2D *m_transform;
	bool m_press;

public:
	Button(Texture *, RidigBody2D *);
	~Button();
	Texture *GetImage() const;
	RidigBody2D *GetTransform() const;
	bool GetPress() const;
	Button *SetTexture(Texture *);
	Button *SetTexture(std::string, int, int);
	Button *SetTransform(RidigBody2D *);
	Button *SetPress(bool);
};