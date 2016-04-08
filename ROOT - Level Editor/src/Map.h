#pragma once
#include<vector>
#include <string>
#include <iostream>
#include <fstream>

class Map
{
public:
	enum ERRORS
	{
		CANNOT_FIND_FILE,
		CANNOT_READ_FILE,
	};

	Map();
	Map(char*);
	//cria o mapa
	Map(int, int);
	//retorna sprite dado um indice x e y
	int getSprite(int, int);
	//seta na position [intx, inty] o sprite s
	void setSprite(int*, int);
	//destroi a porra toda
	~Map();
	//printa o mapa (teste)
	void print();

	//getters and setters
	int getXSize();
	int getYSize();

	//escreve e le os mapas em arquivos
	int writeMap(char*);
	Map* readMap(char*);

private:
	int ** matriz;
	int xSize;
	int ySize;
	FILE* map = nullptr;
	
};