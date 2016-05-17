#include"Physic.h"
#include"Box.h"
#include"Circle.h"

Physic::Physic(Vector2D *p_gravity) : m_gravity(p_gravity)
{}

Physic::~Physic()
{
	if (m_gravity)
	{
		delete m_gravity;
		m_gravity = nullptr;
	}
}

Physic *Physic::SetGravity(Vector2D *p_gravity)
{
	if (!m_gravity)
	{
		m_gravity = p_gravity;
	}

	return this;
}

Vector2D *Physic::GetGravity() const
{
	return m_gravity;
}

bool Physic::Collision(RigidBody *p_r1, RigidBody *p_r2)
{
	return false;
}

bool Physic::Collision(Forma *p_mold1, Forma *p_mold2)
{

	return false;
}

bool Physic::BoxCollisionCheck(Box *p_box, Box *p_other)
{
	float boxLeft = p_box->GetX();
	float boxRight = p_box->GetX() + p_box->GetWidth();
	float boxUp = p_box->GetY();
	float boxDown = p_box->GetY() + p_box->GetHeight();

	float otherLeft = p_other->GetX();
	float otherRight = p_other->GetX() + p_other->GetWidth();
	float otherUp = p_other->GetY();
	float otherDown = p_other->GetY() + p_other->GetHeight();

	return (boxDown <= otherUp || boxUp >= otherDown ||
		boxRight <= otherLeft || boxLeft >= otherRight) ? false : true;

	/*float offx, offy;

	offx = p_other->GetX() - p_box->GetX();
	offy = p_other->GetY() - p_box->GetY();

	return ((offx >= 0) && (offx > p_box->GetWidth()) ||
	(-offx > p_other->GetWidth()) ||
	(offy >= 0) && (offy > p_box->GetHeight()) ||
	(-offy > p_other->GetHeight()))? false : true;*/
}

bool Physic::CircleCollisionCheck(Circle *p_circle, Circle *p_other)
{
	float radius = p_circle->GetRadius() + p_other->GetRadius();
	radius *= radius;

	return (GetDistance(p_circle->GetX(), p_circle->GetY(),
		p_other->GetX(), p_other->GetY())
		< radius) ? true : false;
}

bool Physic::CircleBoxCollisionCheck(Circle *, Box *)
{
	return false;
}

bool Physic::RectCollisionCheck(SDL_Rect *p_rect1, SDL_Rect *p_rect2)
{
	return false;
}

float Physic::GetDistance(float p_x1, float p_y1, float p_x2, float p_y2)
{
	float deltax = p_x2 - p_x1;
	float deltay = p_y2 - p_y1;

	return (deltax * deltax) + (deltay * deltay);
}

