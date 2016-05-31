#pragma once
#include<string>

class Vector2D;
class Texture;

class Mouse
{
private:
	static Vector2D *m_position;
	static Texture *m_image;

	//para verificar se o botão
	//esquerdo esta ativo
	static bool m_buttonLeft;
	//para verificar se o botão
	//direito esta ativo
	static bool m_buttonRight;
public:
	Mouse(Texture *, Vector2D *);
	Mouse();
	~Mouse();

	static Vector2D *GetPosition();
	static float GetX();
	static float GetY();
	static int GetWidth();
	static int GetHeight();
	static Texture *GetImage();

	static bool GetButtonLeft();
	static bool GetButtonRight();

	static void SetPosition(int, int);
	static void SetX(int);
	static void SetY(int);
	static void SetImage(Texture *);
	//caminho da imagem largura e altura do sprite
	static void SetImage(std::string, int, int);
	
	static void SetButtonLeft(bool);
	static void SetButtonRight(bool);

	static void Draw(int, int);
};