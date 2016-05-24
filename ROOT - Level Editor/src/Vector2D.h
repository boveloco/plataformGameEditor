#pragma once

class Vector2D
{
private:
	float m_x;
	float m_y;

public:

	Vector2D(float x, float y): m_x(x), m_y(y)
	{}

	Vector2D()
	{}

	~Vector2D()
	{}

	float GetX() const { return m_x; }
	float GetY() const { return m_y; }
	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }
	float operator [](int index);

	Vector2D &operator+=(Vector2D &);
	Vector2D &operator+=(float);
	Vector2D operator+(Vector2D &);
	Vector2D operator+(float);
	Vector2D &operator-=(Vector2D &);
	Vector2D &operator-=(float);
	Vector2D operator-(Vector2D &);
	Vector2D operator-(float);
	Vector2D &operator*=(Vector2D &);
	Vector2D &operator*=(float);
	Vector2D operator*(Vector2D &);
	Vector2D operator*(float);
	Vector2D &operator=(Vector2D &);
};

