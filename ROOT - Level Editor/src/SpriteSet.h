#pragma once
#include "Texture.h"
#include"Vector2D.h"
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

class SpriteSet
{
public:
	SpriteSet(std::string p_address, SDL_Renderer *p_renderer, int, int, int, int);

	~SpriteSet();
	SDL_Texture* loadTexture(std::string p_address, SDL_Renderer *p_renderer);
	void addSprite(SDL_Texture*);
	bool loadSize(std::string p_address, SDL_Renderer *p_renderer, int,int,int,int);
	bool loadSprites(std::string p_address, SDL_Renderer *p_renderer, int, int, int, int);
	SDL_Texture* getSprite(int);
	int getCount();

	int getYSize();
	int getXSize();

private:
	std::vector<SDL_Texture *> spriteSet;
	int countAllSprites;
	int xSize;
	int ySize;
		
};
