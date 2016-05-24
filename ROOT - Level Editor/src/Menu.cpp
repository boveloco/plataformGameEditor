#include "Menu.h"
#include"Button.h"
#include"Vector2D.h"
#include"Texture.h"
#include"GamePlay.h"
#include"Mouse.h"

Menu::Menu(Texture *p_image, Vector2D *p_position) :
	  m_image(p_image), m_position(p_position)
{}

Menu::Menu() :
	  m_image(nullptr), 
	  m_position(nullptr)
{}

Menu::~Menu()
{
	End();
}

Menu *Menu::AddButtons()
{
	m_buttons.push_back(new Button(nullptr, nullptr));
	m_buttons.push_back(new Button(nullptr, nullptr));
	m_buttons.push_back(new Button(nullptr, nullptr));
	m_buttons.push_back(new Button(nullptr, nullptr));

	for (Button *button : m_buttons)
	{
		
	}

	return this;
}

void Menu::Initialize()
{
	SDL_ShowCursor(SDL_ENABLE);
	AddButtons();
}

void Menu::UpDate()
{
}

void Menu::Draw()
{
	for (Button *button : m_buttons)
	{
		button->GetImage()->Draw(GamePlay::GetRenderer(), m_position);
	}
}

void Menu::End()
{
	if (m_buttons.size() > 0)
	{
		for (Button *button : m_buttons)
		{
			delete button;
			button = nullptr;
		}

		m_buttons.clear();
	}

	if (m_image)
	{
		delete m_image;
		m_image = nullptr;
	}
	if (m_position)
	{
		delete m_position;
		m_position = nullptr;
	}
}

void Menu::SetEvent(SDL_Event &p_event)
{
	if (p_event.type == SDL_MOUSEBUTTONDOWN) 
	{
		if (p_event.button.button == SDL_BUTTON_LEFT) 
		{
			Mouse::SetButtonLeft(true);
		}
		else if (p_event.button.button == SDL_BUTTON_RIGHT) 
		{
			Mouse::SetButtonRight(true);
		}
	}
	else if (p_event.type == SDL_MOUSEBUTTONUP)
	{
		if (p_event.button.button == SDL_BUTTON_LEFT) 
		{
			Mouse::SetButtonLeft(false);
		}
		else if (p_event.button.button == SDL_BUTTON_RIGHT) 
		{
			Mouse::SetButtonRight(false);
		}
	}
}
