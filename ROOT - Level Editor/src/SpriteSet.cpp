#include <iostream>
#include "SpriteSet.h"

SpriteSet::SpriteSet(int x1, int y1, int x2, int y2) : xSize(x2), ySize(y2), countAllSprites(0)
{
	this->loadSize(x1, y1, x2, y2);
	this->loadSprites(x1, y1, x2, y2);
}

SpriteSet::SpriteSet(std::string address, int x1, int y1, int x2, int y2) 
		  : xSize(x2), ySize(y2), countAllSprites(0), src(address)
{
	this->loadSize(x1, y1, x2, y2);
	this->loadSprites(x1, y1, x2, y2);
}

SpriteSet::~SpriteSet()
{
	if (this->spriteSet.size() > 0)
	{
		for (int *s : spriteSet)
		{
			delete []s;
			s = nullptr;
		}

		spriteSet.clear();
	}
	/*for (size_t i = 0; i < this->spriteSet.size(); i++)
	{
		delete this->spriteSet[i];
		this->spriteSet.erase(spriteSet.begin());
	}*/
}

void SpriteSet::addSprite(int* x)
{
	this->spriteSet.push_back(x);
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

std::string SpriteSet::getSrc()
{
	return this->src;
}

bool SpriteSet::loadSize(int x1, int y1, int x2, int y2) {
	if (x2 > x1)
		return false;
	if (y2 > y1)
		return false;
	
	//TODO: refazer os carculo
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
	
	return true;

}

bool SpriteSet::loadSprites(int x1, int y1, int x2, int y2)
{
	for (int i = 0; i < x1;) {
		for (int j = 0; j < y1;) {
			
			if (x2 + i > x1)
				break;
			if (y2 + j > y1)
				break;
			int *x = new int(2);
			x[0] = j;
			x[1] = i;
			this->addSprite(x);
			j += y2;
		}
		i += x2;
	}
	return true;
}

int *SpriteSet::getSprite(int n)
{
	int m = -1;
	if (n > this->getCount())
		return nullptr;
	if (n == 0)
		return &m;
	return this->spriteSet[n - 1];
}

std::vector<int*> SpriteSet::getSpriteset()
{
	return this->spriteSet;
}
