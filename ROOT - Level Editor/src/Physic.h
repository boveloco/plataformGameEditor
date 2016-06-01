#pragma once
#include<SDL.h>

class Vector2D;
class Circle;
class Box;
class RigidBody2D;
class GeometricShape;

class Physic
{
private:
	static Vector2D *m_gravity;

public:
	Physic(Vector2D *);
	~Physic();

	static void SetGravity(Vector2D *);
	static Vector2D *GetGravity();

	static bool Collision(RigidBody2D *, RigidBody2D *);
	static bool Collision(GeometricShape *, GeometricShape *);
	static bool BoxCollisionCheck(Box *, Box *);
	static bool CircleCollisionCheck(Circle *, Circle *);
	static bool CircleBoxCollisionCheck(Circle *, Box *);
	static bool RectCollisionCheck(SDL_Rect *, SDL_Rect *);
	static bool PointBoxColisionCheck(Vector2D *, GeometricShape *);
	static float GetDistance(float, float, float, float);
	//Vector2D *Overlap();
};
