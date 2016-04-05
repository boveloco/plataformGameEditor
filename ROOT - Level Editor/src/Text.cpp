#include "Text.h"

Text::Text()
{
	m_texture = nullptr;
	m_font = nullptr;
}

Text::~Text()
{
}

void Text::LoadText(std::string p_address, int p_size)
{
	if (TTF_Init() < NULL)
	{
		throw std::runtime_error(TTF_GetError());
		return;
	}

	m_font = TTF_OpenFont(p_address.c_str(), p_size);
}

void Text::DrawText(SDL_Renderer *p_renderer, std::string p_address,
	SDL_Color p_color, int p_x, int p_y)
{
	m_color = p_color;

	SDL_Surface *newSurface = TTF_RenderText_Solid(m_font, p_address.c_str(), m_color);

	if (!newSurface)
	{
		throw std::runtime_error(SDL_GetError());
		return;
	}

	m_texture = SDL_CreateTextureFromSurface(p_renderer, newSurface);

	if (!m_texture)
	{
		throw std::runtime_error(SDL_GetError());
		return;
	}

	SDL_Rect rect;
	rect.h = newSurface->h;
	rect.w = newSurface->w;
	rect.x = p_x;
	rect.y = p_y;

	SDL_RenderCopy(p_renderer, m_texture, nullptr, &rect);
}

void Text::End()
{
	if (m_texture)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
	}

	TTF_Quit();
}