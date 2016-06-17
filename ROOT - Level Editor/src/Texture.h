#pragma once
#include<SDL_image.h>
#include<SDL.h>
#include<string>
#include<vector>

class Vector2D;
class SpriteSet;

class Texture
{
private:
	SDL_Texture *m_texture;
	SDL_Rect m_rect;
	int m_width;
	int m_height;
	std::string m_src;

public:
	//sprites no spriteset carregado
	Texture();
	//da load em um spriteset definindo o tamanho do spriteset(x,y) e definindo o tamanho de cada sprite(x,y) respectivamente
	Texture(SpriteSet* , SDL_Renderer *);
	
	//da load com o x e y automaticamente e respectivamente
	Texture(std::string, SDL_Renderer *, int, int);
	Texture(std::string, SDL_Renderer *);
	~Texture();
	int GetWidth() const;
	int GetHeight() const;
	void SetWidth(int p_width);
	void SetHeight(int p_height);
	
	std::string getSrc();

	bool UploadImage(std::string, SDL_Renderer *, int, int);
	void Destroy();

	bool loadSpriteSet(std::string, int, int, int, int);

	void Draw(SDL_Renderer *, Vector2D *);
	//         renderer, posição na tela, x matriz e y matriz
	void Draw(SDL_Renderer *, Vector2D *, int, int);
	void Draw(SDL_Renderer *, Vector2D *, int, int, int, int);
	void Draw(SDL_Renderer *, int, int, int, int);
	void Draw(SDL_Renderer *, int, int);
	void DrawRotation(SDL_Renderer *, Vector2D *, double);
	void DrawRotation(SDL_Renderer *, Vector2D *, double, int, int);
};

