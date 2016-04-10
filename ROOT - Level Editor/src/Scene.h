#pragma once
#include<SDL.h>

class SpriteSet;
class Texture;
class Map;
class Camera2;

class Scene
{
private:
	bool m_quit;

	SpriteSet* ss;
	Texture *t;
	Map* map;
	Camera2 *m_camera;

public:
	Scene();
	~Scene();

	bool Quit();

	void SetEvent(SDL_Event &);

	void Initialize();
	void Update();
	void Draw();
	//Desenha apenas o que a camera
	//está vendo
	void DrawOnCamera();
	void End();
};
