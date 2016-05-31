#include"Physic.h"
#include"Box.h"
#include"Circle.h"
#include"RigidBody2D.h"

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

bool Physic::Collision(RigidBody2D *p_r1, RigidBody2D *p_r2)
{
	return Collision(p_r1->GetCollider(), p_r2->GetCollider());
}

bool Physic::Collision(GeometricShape *p_geometricShape, GeometricShape *p_other)
{
	if (p_geometricShape->GetType() == BOX &&
		p_other->GetType() == BOX)
	{
		Box *box1 = dynamic_cast<Box *>(p_geometricShape);
		Box *box2 = dynamic_cast<Box *>(p_other);

		if (box1 && box2)
		{
			return BoxCollisionCheck(box1, box2);
		}
	}
	else if (p_geometricShape->GetType() == CIRCLE &&
			 p_other->GetType() == CIRCLE)
	{
		Circle *circle1 = dynamic_cast<Circle *>(p_geometricShape);
		Circle *circle2 = dynamic_cast<Circle *>(p_other);

		if (circle1 && circle2)
		{
			return CircleCollisionCheck(circle1, circle2);
		}
	}
	else if (p_geometricShape->GetType() == CIRCLE &&
			 p_other->GetType() == BOX)
	{
		Circle *circle = dynamic_cast<Circle *>(p_geometricShape);
		Box *box = dynamic_cast<Box *>(p_other);

		if (circle && box)
		{
			return CircleBoxCollisionCheck(circle, box);
		}
	}
	else if (p_geometricShape->GetType() == BOX &&
			 p_other->GetType() == CIRCLE)
	{
		Box *box = dynamic_cast<Box *>(p_geometricShape);
		Circle *circle = dynamic_cast<Circle *>(p_other);

		if (box && circle)
		{
			return CircleBoxCollisionCheck(circle, box);
		}
	}
	
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

bool Physic::CircleBoxCollisionCheck(Circle *p_circle, Box *p_other)
{
	float circleX, circleY;

	circleX = (p_circle->GetX() < p_other->GetX()) ?
			   p_other->GetX() :
			  (p_circle->GetX() > p_other->GetX() + p_other->GetWidth()) ?
			   p_other->GetX() + p_other->GetWidth() : p_circle->GetX();

	circleY = (p_circle->GetY() < p_other->GetY()) ?
			   p_other->GetY() :
			  (p_circle->GetY() > p_other->GetY() + p_other->GetHeight()) ?
			   p_other->GetY() + p_other->GetHeight() : p_circle->GetY();

	
	return (GetDistance(p_circle->GetX(), p_circle->GetY(), circleX, circleY) < 
			(p_circle->GetRadius() * p_circle->GetRadius()))? true : false;
}

bool Physic::RectCollisionCheck(SDL_Rect *p_rect, SDL_Rect *p_other)
{
	int offx, offy;

	offx = p_other->x - p_rect->x;
	offy = p_other->y - p_rect->y;

	return ((offx >= 0) && (offx > p_rect->w) ||
			(-offx > p_other->w) ||
			(offy >= 0) && (offy > p_rect->h) ||
			(-offy > p_other->h))? false : true;
}

float Physic::GetDistance(float p_x1, float p_y1, float p_x2, float p_y2)
{
	float deltax = p_x2 - p_x1;
	float deltay = p_y2 - p_y1;

	return (deltax * deltax) + (deltay * deltay);
}

