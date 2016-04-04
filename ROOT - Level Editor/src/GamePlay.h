#pragma once
#include<SDL.h>
#include<SDL_image.h>

class Texture;

class GamePlay
{
private:
	static SDL_Window *m_window;
	static SDL_Renderer *m_renderer;
	SDL_Event m_event;
	static bool m_quit;

	Texture *t;
	Texture *t2;

public:
	GamePlay();
	~GamePlay();

	static SDL_Window *GetWindow();
	static SDL_Renderer *GetRenderer();
	static bool Quit();

	void SetEvent();

	void Initialize();
	void Update();
	void Draw();
	void End();

	void Run();
};

