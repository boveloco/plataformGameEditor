#pragma once
#include"Scene.h"
#include<vector>

class Button;
class Texture;
class Vector2D;

class Menu : public Scene
{
private:
	std::vector<Button *> m_buttons;
	Texture *m_image;
	Vector2D *m_position;

public:
	Menu(Texture *, Vector2D *);
	Menu();
	~Menu();
	Menu *AddButtons();
	virtual void Initialize();
	virtual void UpDate();
	virtual void Draw();
	virtual void End();
	virtual void SetEvent(SDL_Event &);
};