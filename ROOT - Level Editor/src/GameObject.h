#pragma once
#include<SDL.h>

class Vector2D;
class Texture;
class RigidBody2D;
class GeometricShape;

class GameObject
{
protected:
	Texture *m_image;
	RigidBody2D *m_transform;

public:
	GameObject();
	GameObject(Texture *, Vector2D *, GeometricShape *);
	~GameObject();

	//get
	RigidBody2D *GetTransform() const;
	Vector2D *GetPosition() const;
	int GetXPosition() const;
	int GetYPosition() const;
	Texture *GetImage() const;
	int GetWidth() const;
	int GetHeight() const;
	int GetXCenter() const;
	int GetYCenter() const;
	//set
	GameObject *SetTransform(RigidBody2D *);
	void SetPosition(Vector2D *);
	void SetPosition(int, int);
	
	void SetImage(Texture *);
	void SetWidth(int);
	void SetHeight(int);

	virtual void Initialize() = 0;
	virtual void UpDate() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;
};
