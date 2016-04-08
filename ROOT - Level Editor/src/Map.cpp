#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include "Map.h"

Map::Map(){}

Map::Map(char* path)
{
	this->readMap(path);
}

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

	//deleta arquivo mapa
	delete map;
}

int Map::getXSize()
{
	return this->xSize;
}

int Map::getYSize()
{
	return this->ySize;
}

int Map::writeMap(char *path)
{
	try
	{
		this->map = fopen( path ,"w");
		fwrite((Map*) this, sizeof(Map), sizeof(this), this->map);
		return fclose(this->map);
	}
	catch (const std::exception&)
	{
		return NULL;
	}
	return NULL;
}

Map * Map::readMap(char * path)
{
	if (!path)
		return nullptr;
	try
	{
		this->map = fopen(path, "r");
		if (this->map == nullptr)
			return nullptr;
		fread((Map*) this, sizeof(Map), sizeof(this), this->map);
		fclose(this->map);
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
	return this;
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