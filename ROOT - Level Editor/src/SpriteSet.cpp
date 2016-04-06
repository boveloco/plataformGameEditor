#include "SpriteSet.h"

SpriteSet::SpriteSet(int x1, int y1, int x2, int y2)
{
	this->xSize = x2;
	this->ySize = y2;
	this->countAllSprites = 0;
	this->loadSize(x1, y1, x2, y2);
	//this->loadSprites(x1, y1, x2, y2);
}

SpriteSet::~SpriteSet()
{
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

bool SpriteSet::loadSize(int x1, int y1, int x2, int y2) {
	if (x2 > x1)
		return false;
	if (y2 > y1)
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
	
	return true;

}

bool SpriteSet::loadSprites(int x1, int x2, int y1, int y2)
{
	for (int i = 0; i < x1; (i + x2)) {
		for (int j = 0; j < y1; (j + y2)) {
			
			if (x2 + i > x1)
				continue;
			if (y2 + j > y1)
				continue;
			int x[2];
			x[0] = i;
			x[1] = j;
			this->addSprite(x);
		}
	}
	return true;
}

int * SpriteSet::getSprite(int n)
{
	return this->spriteSet[n];
}

std::vector<int*> SpriteSet::getSpriteset()
{
	return this->spriteSet;
}
