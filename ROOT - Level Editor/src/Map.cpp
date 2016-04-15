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
	this->createMatriz(x, y);
}

int** Map::createMatriz(int x, int y) {
	this->matriz = (int**)calloc(x, sizeof(int)*x);
	for (size_t i = 0; i < x; i++)
	{
		this->matriz[i] = (int*)calloc(y, sizeof(int)*y);
	}
	return this->matriz;
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

int Map::writeMap(char *path)
{
	std::ofstream map(path, std::ifstream::binary);
	try
	{
		//fwrite((Map*) this, sizeof(Map), sizeof(this), this->map);
		//fclose(this->map);
		map << this->getXSize();
		map << "\n";
		map << this->getYSize();
		map << "\n";
		for (size_t i = 0; i < this->xSize; i++)
		{
			for (size_t j = 0; j < this->ySize; j++)
			{
				map << this->matriz[i][j] << " ";
			}
			map << "\n";
		}

	}
	catch (const std::exception&)
	{
		return NULL;
	}
	map.close();
	return 1;
}

Map * Map::readMap(char * path)
{
	std::string line;
	int count = 0;
	std::ifstream map(path, std::ifstream::binary);
	std::string::size_type sz;
	//faz a leitura das primeiras duas linha (tamanho em x e em y respectivamente)
	while (std::getline(map, line))
	{
		std::cout << line << std::endl;
		if (count == 0)
			this->xSize = std::stoi(line, &sz);
		if (count == 1) {
			this->ySize = std::stoi(line, &sz);
			break;
		}
		count++;
	}
	
	//cria a matriz
	this->createMatriz(this->xSize, this->ySize);	

	//pega os valores da matriz
	int x, y;
	for (x = 0; x < this->xSize; x++) {
		for (y = 0; y < this->ySize; y++) {
			 map >> this->matriz[x][y];
		}
	}
	map.close();
	return this;
}

void Map::print() {
	for (size_t i = 0; i < this->ySize; i++)
	{
		for (size_t j = 0; j < this->xSize; j++)
		{
			std::cout << this->matriz[i][j] << " | ";
		}
		std::cout << std::endl;
	}
}