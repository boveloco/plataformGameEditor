#pragma once
#include<SDL.h>
#include<SDL_image.h>

class Camera2;
class Texture;
class SpriteSet;
class Map;

class GamePlay
{
private:
	static SDL_Window *m_window;
	static SDL_Renderer *m_renderer;
	SDL_Event m_event;
	static bool m_quit;
	SpriteSet* ss;
	Texture *t;
	Map* map;
	Camera2 *m_camera;
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
	//Desenha apenas o que a camera
	//está vendo
	void DrawOnCamera();
	void End();

	void Run();
};

