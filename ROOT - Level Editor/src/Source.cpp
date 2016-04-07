#include <iostream>
#include "GamePlay.h"
#include "SpriteSet.h"
int main(int argc, char** argv) 
{
	GamePlay game;
	game.Run();
	
	//testando spriteset
	//SpriteSet* spriteS = new SpriteSet(10, 10, 1, 5);
	//std::cout << spriteS->getCount() << std::endl;
	//std::cout << spriteS->getSprite(4)[0] << " && " << spriteS->getSprite(4)[1] << std::endl;
	return 0;
}