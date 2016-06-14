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
public:
	FaseTeste(SpriteSet *);
	~FaseTeste();
	void AddTiles();
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
