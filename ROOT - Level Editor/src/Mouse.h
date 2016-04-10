#pragma once

class Vector2D;
class Texture;

class Mouse
{
private:
	static Vector2D *m_position;
	static Texture *m_image;

public:
	Mouse(Texture *, Vector2D *);
	Mouse();
	~Mouse();

	static Vector2D *GetPosition();
	static int GetX();
	static int GetY();
	static int GetWidth();
	static int GetHeight();
	static Texture *GetImage();

	static void SetPosition(int, int);
	static void SetX(int);
	static void SetY(int);
	static void SetImage(Texture *);

	static void Draw();
};