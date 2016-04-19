#pragma once
#include<SDL.h>
class SpriteSet;
class Texture;
class Map;
class Camera;
class Mouse;

class Scene
{
private:
	bool m_quit;
	char* mapa = "map1.dat";

	SpriteSet* spriteSet;
	Texture *m_texture;
	Texture* hints;
	Map* map;
	Camera *m_camera;
	Mouse* mouse;
	SDL_Window* m_window;

	//posição x e y da imagem
	//namatriz de sprite
	//para passar para o mause
	int *m_index;

	// id imagem que sera
	//gravada na matriz
	int img;

public:	
	Scene(SpriteSet*, Map*, SDL_Window*);
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
