#include "Texture.h"
#include"Vector2D.h"
#include"GamePlay.h"

Texture::Texture()
{}

Texture::Texture(std::string p_address, SDL_Renderer *p_renderer)
{
	UploadImage(p_address, p_renderer);
}


Texture::~Texture()
{
	Destroy();
}

int Texture::GetWidth() const
{
	return m_width;
}

int Texture::GetHeight() const
{
	return m_height;
}

void Texture::SetWidth(int p_width)
{
	m_width = p_width;
}

void Texture::SetHeight(int p_height)
{
	m_height = p_height;
}

bool Texture::UploadImage(std::string p_address, SDL_Renderer *p_renderer)
{
	SDL_Surface *newSurface = IMG_Load(p_address.c_str());

	if (!newSurface)
	{
		throw std::runtime_error(IMG_GetError());
		return false;
	}

	SDL_SetColorKey(newSurface, SDL_TRUE, SDL_MapRGB(newSurface->format, 0, 0, 0));

	SDL_Texture *newTexture = SDL_CreateTextureFromSurface(p_renderer, newSurface);

	if (!newSurface)
	{
		throw std::runtime_error(SDL_GetError());
		return false;
	}

	/*if (true)
	{
		m_height = newSurface->h;
		m_width = newSurface->w;
	}*/

	SDL_FreeSurface(newSurface);
	newSurface = nullptr;

	m_texture = newTexture;
	return m_texture != nullptr;
}

void Texture::Destroy()
{
	if (m_texture)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
		m_height = m_width = 0;
	}
}

void Texture::Draw(SDL_Renderer *p_renderer, Vector2D *p_position)
{
	m_rect.h = m_height;
	m_rect.w = m_width;
	m_rect.x = p_position->GetX();
	m_rect.y = p_position->GetY();

	SDL_RenderCopy(p_renderer, m_texture, NULL, &m_rect);
}

void Texture::Draw(SDL_Renderer *p_renderer, Vector2D *p_position,
	               int p_xIMG, int p_yIMG)
{
	SDL_Rect newRect = { p_xIMG, p_yIMG, m_width, m_height};

	m_rect.x = p_position->GetX();
	m_rect.y = p_position->GetY();
	m_rect.w = m_width;
	m_rect.h = m_height;

	SDL_RenderCopy(p_renderer, m_texture, &newRect, &m_rect);
}

void Texture::Draw(SDL_Renderer *p_renderer, int p_x, int p_y)
{
	m_rect.h = m_height;
	m_rect.w = m_width;
	m_rect.x = p_x;
	m_rect.y = p_y;

	SDL_RenderCopy(p_renderer, m_texture, NULL, &m_rect);
}

void Texture::DrawRotation(SDL_Renderer *p_renderer, Vector2D *p_position, 
	                       double p_angle, int p_xIMG, int p_yIMG)
{
	SDL_Rect newRect = { p_xIMG, p_yIMG, m_width, m_height };

	m_rect.x = p_position->GetX();
	m_rect.y = p_position->GetY();
	m_rect.w = m_width;
	m_rect.h = m_height;

	SDL_RenderCopyEx(p_renderer, m_texture, &newRect, 
		             &m_rect, p_angle, NULL, SDL_FLIP_NONE);
}

void Texture::DrawRotation(SDL_Renderer *p_renderer, 
	                       Vector2D *p_position, double p_angle)
{
	m_rect.x = p_position->GetX();
	m_rect.y = p_position->GetY();
	m_rect.w = m_width;
	m_rect.h = m_height;

	SDL_RenderCopyEx(p_renderer, m_texture, NULL, 
		             &m_rect, p_angle, NULL, SDL_FLIP_NONE);
}