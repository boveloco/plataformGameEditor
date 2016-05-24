#pragma once
#include<SDL.h>

class Vector2D;
class Texture;

class GameObject
{
protected:
	Vector2D *m_position;
	Texture *m_image;

public:
	GameObject();
	GameObject(Texture *, Vector2D *);
	~GameObject();

	//get
	Vector2D *GetPosition() const;
	int GetXPosition() const;
	int GetYPosition() const;
	Texture *GetImage() const;
	int GetWidth() const;
	int GetHeight() const;
	int GetXCenter() const;
	int GetYCenter() const;
	//set
	void SetPosition(Vector2D *);
	void SetPosition(int, int);
	void SetXPosition(int);
	void SetYPosition(int);
	void SetImage(Texture *);
	void SetWidth(int);
	void SetHeight(int);
};
