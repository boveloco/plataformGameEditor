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
	Texture(std::string);
	~Texture();

	int GetWidth() const;
	int GetHeight() const;
	void SetWidth(int p_width);
	void SetHeight(int p_height);
	
	bool UploadImage(std::string);
	void Destroy();

	void Draw(Vector2D *);
	void Draw(Vector2D *, int, int);
	void Draw( int, int);
	void DrawRotation(Vector2D *, double);
	void DrawRotation(Vector2D *, double, int, int);
};

