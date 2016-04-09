#include <iostream>
#include "GamePlay.h"
#include "SpriteSet.h"
#include "Map.h"
int main(int argc, char** argv) 
{
	//GamePlay game;
	//game.Run();
	
	//testando spriteset
	//SpriteSet* spriteS = new SpriteSet(10, 10, 1, 5);
	//std::cout << spriteS->getCount() << std::endl;
	//std::cout << spriteS->getSprite(4)[0] << " && " << spriteS->getSprite(4)[1] << std::endl;
	
	//testando mapa
	Map* m = new Map(10, 10);
	int * p = new int(2);
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			p[0] = i;
			p[1] = j;
			m->setSprite(p, i + j);
		}
	}

	m->print();
	m->writeMap("map.dat");

	Map* n = new Map();
	n = m->readMap("map.dat");
	n->print();
	system("PAUSE");
	return 0;
}