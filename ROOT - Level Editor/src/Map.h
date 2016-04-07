#pragma once
#include<vector>

class Map
{
public:
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

private:
	int ** matriz;
	int xSize;
	int ySize;
	
};