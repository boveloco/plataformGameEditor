#include "Menu.h"
#include"Button.h"
#include"Vector2D.h"
#include"Texture.h"
#include"GamePlay.h"
#include"Mouse.h"
#include"Defines.h"
#include"Physic.h"
#include"Editor.h"

Menu::Menu(Texture *p_image, Vector2D *p_position) :
	  m_image(p_image), m_position(p_position), m_index(0)
{}

Menu::Menu() :
	  m_image(nullptr), 
	  m_position(nullptr)
{}

Menu::~Menu()
{
	//End();
}

Menu *Menu::AddButtons()
{
	m_buttons.push_back(new Button(new Texture("img/EDITOR1.png",  
												GamePlay::GetRenderer(), 
												202, 43), 
								   new Vector2D((SIZE_WINDOW_X / 2) - 71, 
												 SIZE_WINDOW_Y / 2 + 10),
								   _EDITOR));

	m_buttons.push_back(new Button(new Texture("img/GAME1.png",
												GamePlay::GetRenderer(),
												202, 43),
								   new Vector2D((SIZE_WINDOW_X / 2) - 71, 
											    m_buttons[0]->GetY() + 50),
								   _GAME));

	/*m_buttons.push_back(new Button(new Texture("img/CREDITS1.png",
												GamePlay::GetRenderer(),
												202, 43),
								  new Vector2D((SIZE_WINDOW_X / 2) - 71, 
											   m_buttons[1]->GetY() + 50)));*/

	m_buttons.push_back(new Button(new Texture("img/QUIT1.png",
												GamePlay::GetRenderer(),
												202, 43),
								   new Vector2D((SIZE_WINDOW_X / 2) - 71, 
									            m_buttons[1]->GetY() + 50),
								   _QUIT));

	for (Button *button : m_buttons)
	{
		button->Initialize();
	}

	return this;
}

Button *Menu::GetButton()
{
	return m_buttons[m_index];
}

void Menu::Initialize()
{
	SDL_ShowCursor(SDL_ENABLE);
	AddButtons();
}

void Menu::UpDate()
{
	if (Mouse::GetButtonLeft())
	{
		//m_index = 0;

		for (Button *button : m_buttons)
		{
			if (Physic::PointBoxColisionCheck(Mouse::GetPosition(), 
									   button->GetGeometricShape()))
			{
				button->SetPress(true);
				//m_index == button->GetType();
				break;
			}
			//m_index++;
		}

		Mouse::SetButtonLeft(false);
	}
	if (m_index == TypeButton::_MENU)
		SDL_ShowCursor(SDL_ENABLE);
}

void Menu::Draw()
{
	m_image->Draw(GamePlay::GetRenderer(), m_position);

	for (Button *button : m_buttons)
	{
		button->Draw();
	}

}

void Menu::End()
{
	if (m_buttons.size() > 0)
	{
		/*for (int i = 0; i < m_buttons.size(); i++)
		{
			delete m_buttons[i];
			m_buttons[i] = nullptr;
		}*/

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
	if (p_event.type == SDL_KEYUP && p_event.key.keysym.sym == SDLK_ESCAPE)
		if(GamePlay::getIndex() == 0)
			GamePlay::SetIndex(GamePlay::getLastIndex());
}
