#pragma once
#include<SDL_image.h>
#include<SDL.h>
#include<string>

class Vector2D;

class Texture
{
private:
	SDL_Texture *m_texture;
	SDL_Rect m_rect;
	int m_width;
	int m_height;
	
public:
	Texture();
	Texture(std::string, SDL_Renderer *);
	~Texture();

	int GetWidth() const;
	int GetHeight() const;
	void SetWidth(int p_width);
	void SetHeight(int p_height);
	
	bool UploadImage(std::string, SDL_Renderer *);
	void Destroy();

	void Draw(SDL_Renderer *, Vector2D *);
	//         renderer, posi��o na tela, x matriz e y matriz
	void Draw(SDL_Renderer *, Vector2D *, int, int);
	void Draw(SDL_Renderer *, int, int);
	void DrawRotation(SDL_Renderer *, Vector2D *, double);
	void DrawRotation(SDL_Renderer *, Vector2D *, double, int, int);
};

