#pragma once
#include<string>

class Texture;
class Vector2D;
class GeometricShape;
class RigidBody2D;

class Button
{
private:
	Texture *m_image;
	//Vector2D *m_position;
	//GeometricShape *m_collider;
	RigidBody2D *m_transform;
	bool m_press;

public:
	Button(Texture *, RigidBody2D *);
	~Button();
	Texture *GetImage() const;
	RigidBody2D *GetTransform() const;
	Vector2D *GetPosition() const;
	bool GetPress() const;
	Button *SetTexture(Texture *);
	Button *SetTexture(std::string, int, int);
	Button *SetTransform(RigidBody2D *);
	Button *SetPress(bool);

	virtual void Initialize();
	virtual void Draw();
	virtual void End();
};