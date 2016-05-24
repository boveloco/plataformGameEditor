#pragma once

class Vector2D;
class GeometricShape;

class RigidBody2D
{
private:
	Vector2D *m_position;
	Vector2D *m_direction;
	Vector2D *m_velocity;
	Vector2D *m_up;
	GeometricShape *m_collider;
	bool m_static;

public:
	RigidBody2D(Vector2D *p_position = nullptr, GeometricShape *p_collider = nullptr);
	~RigidBody2D();
	Vector2D *GetPosition() const;
	Vector2D *GetDirection() const;
	Vector2D *GetVelocity() const;
	float GetX() const;
	float GetY() const;
	GeometricShape *GetCollider() const;
	bool GetStatic() const;
	RigidBody2D *SetPosition(Vector2D *);
	RigidBody2D *SetPosition(float, float);
	RigidBody2D *SetDirection(Vector2D *);
	RigidBody2D *SetVelocity(Vector2D *);
	RigidBody2D *SetDirection(float, float);
	RigidBody2D *SetVelocity(float, float);
	RigidBody2D *SetCollider(GeometricShape *);
	RigidBody2D *SetStatic(bool);

	RigidBody2D *AddForce(Vector2D *);
};