#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<vector>

class Camera;
class Editor;
class Mouse;
class Scene;

class GamePlay
{
private:
	static SDL_Window *m_window;
	static SDL_Renderer *m_renderer;
	SDL_Event m_event;
	static bool m_quit;

	//Camera2 *m_camera;
	//Editor *m_scene;
	Mouse *m_mouse;

	std::vector<Scene *> m_scenes;
	int m_index;
public:
	GamePlay();
	~GamePlay();

	static SDL_Window *GetWindow();
	static SDL_Renderer *GetRenderer();
	static bool Quit();

	void AddScenes(Scene *);
	void SetEvent();

	void Initialize();
	void Update();
	void Draw();
	//Desenha apenas o que a camera
	//está vendo
	void End();

	void Run();
};

