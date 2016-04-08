#include <iostream>
#include "GamePlay.h"
#include "SpriteSet.h"
#include "Map.h"
int main(int argc, char** argv) 
{
	GamePlay game;
	game.Run();
	
	//testando spriteset
	//SpriteSet* spriteS = new SpriteSet(10, 10, 1, 5);
	//std::cout << spriteS->getCount() << std::endl;
	//std::cout << spriteS->getSprite(4)[0] << " && " << spriteS->getSprite(4)[1] << std::endl;
	
	//testando mapa
	//Map* m = new Map(100, 10);
	//int * p = new int(2);
	//p[0] = 1;
	//p[1] = 3;
	//m->setSprite(p, 2);
	//std::cout << std::endl;
	//m->print();

	system("PAUSE");
	return 0;
}