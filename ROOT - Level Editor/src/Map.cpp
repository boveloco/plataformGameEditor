#include<iostream>
#include "Map.h"

Map::Map(int x, int y)
{
	this->xSize = x;
	this->ySize = y;
	this->matriz = (int**) calloc(y, sizeof(int)*y);
	for (size_t i = 0; i < x; i++)
	{
		this->matriz[i] = (int*) calloc(x, sizeof(int)*x);
	}

}

int Map::getSprite(int x, int y)
{
	return this->matriz[x][y];
}

void Map::setSprite(int * pos, int sprite)
{
	this->matriz[pos[0]][pos[1]] = sprite;
}

Map::~Map()
{
	for (size_t i = 0; i < this->xSize; i++)
	{
			delete this->matriz[i];
	}
	delete matriz;
}

int Map::getXSize()
{
	return this->xSize;
}

int Map::getYSize()
{
	return this->ySize;
}

void Map::print() {
	for (size_t i = 0; i < this->ySize; i++)
	{
		for (size_t j = 0; j < this->xSize; j++)
		{
			std::cout << this->matriz[j][i] << " | ";
		}
		std::cout << std::endl;
	}
}