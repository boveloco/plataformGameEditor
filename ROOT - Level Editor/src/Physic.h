#pragma once
#include<SDL.h>

class Vector2D;
class Circle;
class Box;
class RigidBody;
class Forma;

class Physic
{
private:
	Vector2D *m_gravity;

public:
	Physic(Vector2D *);
	~Physic();

	Physic *SetGravity(Vector2D *);
	Vector2D *GetGravity() const;

	bool Collision(RigidBody *, RigidBody *);
	bool Collision(Forma *, Forma *);
	bool BoxCollisionCheck(Box *, Box *);
	bool CircleCollisionCheck(Circle *, Circle *);
	bool CircleBoxCollisionCheck(Circle *, Box *);
	bool RectCollisionCheck(SDL_Rect *, SDL_Rect *);
	float GetDistance(float, float, float, float);
};
