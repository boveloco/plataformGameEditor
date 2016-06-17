#pragma once
#include<string>

enum TypeButton
{
	B_MENU,
	B_EDITOR,
	B_GAME,
	B_QUIT,
	B_CREDITS,
	B_TILE,
	B_NEW,
	B_LOAD,
	B_SAVE
};

class Texture;
class Vector2D;
class GeometricShape;
class RigidBody2D;

class Button
{
private:
	Texture *m_image;
	Vector2D *m_position;
	GeometricShape *m_collider;
	bool m_press;
	TypeButton m_type;
public:
	Button(Texture *, Vector2D *, TypeButton);
	~Button();
	Texture *GetImage() const;
	Vector2D *GetPosition() const;
	float GetX() const;
	float GetY() const;
	bool GetPress() const;
	TypeButton GetType() const;
	Button *SetTexture(Texture *);
	Button *SetTexture(std::string, int, int);
	Button *SetPress(bool);
	GeometricShape *GetGeometricShape() const;

	virtual void Initialize();
	virtual void Draw();
	virtual void End();
};