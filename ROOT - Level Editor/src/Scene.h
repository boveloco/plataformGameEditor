#pragma once
#include<SDL.h>

enum TypeScene
{
	S_MENU,
	S_EDITOR,
	S_GAME

};

class Scene
{
public:
	Scene() {}
	virtual ~Scene() {}
	virtual void Initialize() = 0;
	virtual void UpDate() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;
	virtual void SetEvent(SDL_Event &) = 0;
};
