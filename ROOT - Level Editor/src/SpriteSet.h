#pragma once
#include <vector>

class SpriteSet
{
public:
	//isntancia um novo spriteset (x1[x imagem], y1[y imagem], x2[tamanho em x de cada sprite], y2[tamanho em y de cada sprite])
	//SEMPRE NESSA ORDEM
	SpriteSet(int, int, int, int);
	SpriteSet(std::string,int, int, int, int);

	~SpriteSet();
	//adiciona um sprite no vetor
	void addSprite(int*);
	//descobre a quantidade de sprites que haverá no spriteset
	bool loadSize(int, int, int, int);
	//adiciona os sprites nos vetores
	bool loadSprites(int, int, int, int);
	//retorna sprite no indicie n
	int* getSprite(int);
	//retorna o spriteset
	std::vector<int*> getSpriteset();
	//retorna quantos sprites total tem
	int getCount();

	//get && set do tamanho x e y de cada sprite [inherit no spriteset]
	int getYSize();
	int getXSize();
	//gss
	std::string getSrc();

private:
	std::string src;
	std::vector<int*> spriteSet;
	int countAllSprites;
	int xSize;
	int ySize;
		
};
