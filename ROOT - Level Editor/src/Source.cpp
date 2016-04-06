#include <iostream>
#include "GamePlay.h"
#include "SpriteSet.h"
int main(int argc, char** argv) 
{
	//GamePlay game;
	//game.Run();
	
	//testando spriteset
	SpriteSet* spriteS = new SpriteSet(323, 747, 77, 33);
	std::cout << spriteS->getCount() << std::endl;

	return 0;
}