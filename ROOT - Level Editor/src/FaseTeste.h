#pragma once
#include"Scene.h"
#include<vector>

class Map;
class SpriteSet;
class Texture;
class Box;
class Camera;
class Tile;
class Hero;

class FaseTeste : public Scene
{
private:
	Texture *m_image;
	SpriteSet *m_spriteSet;
	Map *m_map;
	Camera *m_camera;
	Hero *m_hero;
	//std::vector<Box *> m_tiles;
	std::vector<Tile *> m_tiles;
	char *m_mapa;
	char** fases = new char*[5];
public:
	int contFase = 0;
	char* getFases(int &n) {
		if (n > 5)
			n = 0;
		if (n < 0)
			n = 0;

		return fases[n];
	}

	FaseTeste(SpriteSet *);
	~FaseTeste();
	void AddTiles();
	void DestroyTile();
	virtual void Initialize();
	virtual void UpDate();
	virtual void Draw();
	virtual void End();
	virtual void SetEvent(SDL_Event &);
	void DrawOnCamera();

	int GetLimitLeft() const;
	int GetLimitRight() const;
	int GetUpperLimit() const;
	int GetInferiorLimit() const;
};
