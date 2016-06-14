#pragma once
#include"GameObject.h"

class Tile;
class Camera;

class Hero : public GameObject
{
private:
	bool m_moveLeft;
	bool m_moveRight;
	bool m_jump;
	int m_count;
	Camera *m_camera;
	float m_xSpeed;
	float m_ySpeed;
public:
	Hero(Texture *, Vector2D *, GeometricShape *, Camera *);
	~Hero();

	void SetLeft(bool);
	void SetRight(bool);
	void SetJump(bool);

	void CollideTile(Tile *);

	virtual void Initialize();
	virtual void UpDate();
	virtual void Draw();
	virtual void End();
};
