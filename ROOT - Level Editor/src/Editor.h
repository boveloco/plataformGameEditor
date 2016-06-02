#pragma once
#include"Scene.h"

class SpriteSet;
class Texture;
class Map;
class Camera;
class Mouse;

class Editor : public Scene
{
private:
	bool m_quit;
	char* mapa = "map1.dat";

	SpriteSet* spriteSet;
	Texture *m_texture;
	Texture* hints;
	Map* mapCameraEditor;
	Map* mapCameraSpriteSet;
	Camera *m_camera_editor;
	Camera *m_camera_spriteSet;
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
	Editor(SpriteSet*, Map*, SDL_Window*);
	~Editor();

	bool Quit();

	virtual void SetEvent(SDL_Event &);

	virtual void Initialize();
	virtual void UpDate();
	virtual void Draw();
	//Desenha apenas o que a camera
	//está vendo
	void DrawOnCamera();
	virtual void End();
};
