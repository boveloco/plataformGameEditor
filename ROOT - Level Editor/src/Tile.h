#pragma once

class Texture;
class Vector2D;
class GeometricShape;

class Tile
{
private:
	Texture *m_image;
	Vector2D *m_position;
	GeometricShape *m_collider;
	int m_indexX;
	int m_indexY;

public:
	Tile(Texture *, Vector2D *, int, int);
	~Tile();
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
