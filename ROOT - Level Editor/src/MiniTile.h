#pragma once

class Texture;
class Vector2D;
class GeometricShape;

class MiniTile
{
private:
	Texture *m_image;
	Vector2D *m_position;
	GeometricShape *m_collider;
	int m_indexX;
	int m_indexY;

public:
	MiniTile(Texture *, Vector2D *, int, int);
	~MiniTile();
	Vector2D *GetPosition() const;
	float GetX() const;
	float GetY() const;
	Texture *GetImage() const;
	GeometricShape *GetCollider() const;
	int GetIndexX() const;
	int GetIndexY() const;

	void Initialize();
	void Draw();
};
