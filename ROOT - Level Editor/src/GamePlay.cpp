#include <iostream>

#include"GamePlay.h"
#include"Texture.h"
#include"Vector2D.h"
#include"SpriteSet.h"
#include"Map.h"
#include"Camera.h"
#include"Scene.h"
#include"Mouse.h"
#include "Defines.h"

SDL_Window *GamePlay::m_window = nullptr;
SDL_Renderer *GamePlay::m_renderer = nullptr;
bool GamePlay::m_quit = false;

GamePlay::GamePlay()
{
	this->m_scene = nullptr;
}

GamePlay::~GamePlay()
{
}

SDL_Window *GamePlay::GetWindow()
{
	return m_window;
}

SDL_Renderer *GamePlay::GetRenderer()
{
	return m_renderer;
}

bool GamePlay::Quit()
{
	return m_quit;
}

void GamePlay::SetEvent()
{
	while (SDL_PollEvent(&m_event))
	{
		if (m_event.type == SDL_QUIT)
		{
			m_quit = true;
		}
		if (m_event.type == SDL_KEYDOWN)
		{
			switch (m_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_quit = true;
				break;
			default:
				break;
			}
		}
		if (m_event.type == SDL_MOUSEMOTION)
		{
			m_mouse->SetPosition(m_event.motion.x, m_event.motion.y);
			SDL_MouseIsHaptic();
		}

		this->m_scene->SetEvent(m_event);
	}
}

void GamePlay::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < NULL)
	{
		throw std::runtime_error(SDL_GetError());
		m_quit = true;
		return;
	}

	m_window = SDL_CreateWindow("ROOT", SDL_WINDOWPOS_UNDEFINED,
			   SDL_WINDOWPOS_UNDEFINED, SIZE_WINDOW_X, SIZE_WINDOW_Y, SDL_WINDOW_SHOWN);

	if (!m_window)
	{
		throw std::runtime_error(SDL_GetError());
		m_quit = true;
		return;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC);

	if (!m_renderer)
	{
		throw std::runtime_error(SDL_GetError());
		m_quit = true;
		return;
	}

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);

	int imgP = IMG_INIT_PNG;
	int imgJ = IMG_INIT_JPG;

	if (!(IMG_Init(imgP) &imgP) ||
		!(IMG_Init(imgJ) & imgJ))

	{
		throw std::runtime_error(IMG_GetError());
		m_quit = true;
		return;
	}

	////////////////////
	////////////////////
	Map* map = new Map("map.dat");
	m_mouse = new Mouse(new Texture("img/tileset.png", m_renderer, 64, 64), new Vector2D(0, 0));
	this->m_scene = new Scene(new SpriteSet("img/tileset.png",512,512,64,64), map, m_window);
	this->m_scene->Initialize();
}

void GamePlay::Update()
{
	SetEvent();

	this->m_scene->Update();
}

void GamePlay::Draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	SDL_RenderClear(m_renderer);

	this->m_scene->Draw();
	//m_mouse->Draw(0, 0);
}

void GamePlay::End()
{
	if (m_window)
	{
		SDL_DestroyWindow(m_window);
		m_window = nullptr;
	}
	if (m_renderer)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}

	IMG_Quit();
	SDL_Quit();

	this->m_scene->End();

	delete this->m_scene;
	this->m_scene = nullptr;

	delete m_mouse;
	m_mouse = nullptr;
}

void GamePlay::Run()
{
	try
	{
		Initialize();

		while (!m_quit)
		{
			Update();
			Draw();

			SDL_RenderPresent(m_renderer);

			SDL_Delay(10);
		}

		End();

	}
	catch (std::exception &e)
	{
		std::cout << "ERRO INESPERADO. CODIGO: " << e.what() << std::endl;
	}
}
