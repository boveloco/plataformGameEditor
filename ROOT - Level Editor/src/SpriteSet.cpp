#include "SpriteSet.h"

SpriteSet::SpriteSet(std::string p_address, SDL_Renderer *p_renderer,int x1, int y1, int x2, int y2)
{
	this->xSize = x2;
	this->ySize = y2;
	this->countAllSprites = 0;
	this->loadSize(p_address, p_renderer, x1, y1, x2, y2);
//	this->
}

SpriteSet::~SpriteSet()
{
}

void SpriteSet::addSprite(SDL_Texture* t)
{
	this->spriteSet.push_back(t);
}

SDL_Texture* SpriteSet::getSprite(int x)
{
	if (this->spriteSet.size() < x)
		return false;

	return  this->spriteSet[x];
}

int SpriteSet::getCount()
{
	return this->countAllSprites;
}

int SpriteSet::getYSize()
{
	return this->ySize;
}

int SpriteSet::getXSize()
{
	return this->xSize;
}

bool SpriteSet::loadSize(std::string p_address, SDL_Renderer *p_renderer, int x1, int y1, int x2, int y2) {
	if (y1 > x1)
		return false;
	if (y2 > x2)
		return false;
	
	int n = 0;
	if (x1 / x2) {
		if (y1 / y2) {
			this->countAllSprites = (x1 / x2)*(y1 / y2);
		} else {
			n = (y1 % y2) * 100;
			this->countAllSprites = (x1 / x2) * n;
		}
	}
	else {
		if(y1 / y2) {
			this->countAllSprites = ((x1%x2)*100)*(y1 / y2);
		}
	else {
		 
		this->countAllSprites = ((x1%x2)*100) * ((y1 % y2) * 100);
	}
	}

	this->loadSprites(p_address, p_renderer, x1, y1, x2, y2);

	return true;

}

bool SpriteSet::loadSprites(std::string p_address, SDL_Renderer *p_renderer, int x1, int x2, int y1, int y2)
{
	for (size_t i = 0; i < x1; i + x2) {
		for (size_t j = 0; j < y1; j + y2)
		{
			
		}
	}
	return true;
}

SDL_Texture* SpriteSet::loadTexture(std::string p_address, SDL_Renderer *p_renderer)
	{
		SDL_Surface *newSurface = IMG_Load(p_address.c_str());

		if (!newSurface)
		{
			throw std::runtime_error(IMG_GetError());
			return false;
		}

		SDL_SetColorKey(newSurface, SDL_TRUE, SDL_MapRGB(newSurface->format, 0, 0, 0));

		SDL_Texture *newTexture = SDL_CreateTextureFromSurface(p_renderer, newSurface);

		if (!newSurface)
		{
			throw std::runtime_error(SDL_GetError());
			return false;
		}

		/*if (true)
		{
		m_height = newSurface->h;
		m_width = newSurface->w;
		}*/

		SDL_FreeSurface(newSurface);
		return newTexture;
	}
