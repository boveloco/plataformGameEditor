#pragma once
#include"Scene.h"
#include<vector>

class SpriteSet;
class Texture;
class Map;
class Camera;
class Mouse;
class Button;
class Tile;
class Box;

class Editor : public Scene
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

	std::vector<Tile *> m_tiles;
	std::vector<Button *> m_buttons;

public:	
	Editor(SpriteSet*, Map*, SDL_Window*);
	~Editor();

	bool Quit();
	SpriteSet *GetSpriteSet() const;
	void AddButtons();
	void AddTiles();
	virtual void SetEvent(SDL_Event &);

	virtual void Initialize();
	virtual void UpDate();
	virtual void Draw();
	//Desenha apenas o que a camera
	//está vendo
	void DrawOnCamera();
	virtual void End();
};
