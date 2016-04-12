#pragma once

class Vector2D
{
private:
	int m_x;
	int m_y;

public:

	Vector2D(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	Vector2D()
	{}

	~Vector2D()
	{}

	int GetX() const { return m_x; }
	int GetY() const { return m_y; }
	void SetX(int x) { m_x = x; }
	void SetY(int y) { m_y = y; }
	int* operator [](int index);
};

