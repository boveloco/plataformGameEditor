#pragma once
#include<SDL.h>
#include<SDL_image.h>

class Camera2;
class Scene;
class Mouse;

class GamePlay
{
private:
	static SDL_Window *m_window;
	static SDL_Renderer *m_renderer;
	SDL_Event m_event;
	static bool m_quit;

	//Camera2 *m_camera;
	Scene *m_scene;
	Mouse *m_mouse;

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
	void End();

	void Run();
};

