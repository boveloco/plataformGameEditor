#pragma once
#include<SDL.h>

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
