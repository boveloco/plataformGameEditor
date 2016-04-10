#include <iostream>
#include "GamePlay.h"
#include "SpriteSet.h"
#include "Map.h"
#include "Camera.h"

int main(int argc, char** argv) 
{
	GamePlay game;
	game.Run();
	
	//Camera c(CAMERA_Y, 1, CAMERA_X, 1);
	system("PAUSE");
	return 0;
}