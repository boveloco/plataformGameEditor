#pragma once
#include<SDL.h>
#include<SDL_ttf.h>
#include<string>

class Text
{
private:
	TTF_Font *m_font;
	SDL_Texture *m_texture;
	SDL_Color m_color;

public:
	Text();
	~Text();

	void LoadText(std::string, int);
	void DrawText(SDL_Renderer *, std::string, SDL_Color, int, int);
	void End();
};