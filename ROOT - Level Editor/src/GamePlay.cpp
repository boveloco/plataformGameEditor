#include <iostream>

#include"GamePlay.h"
#include"Texture.h"
#include"Vector2D.h"
#include"SpriteSet.h"
#include"Map.h"
#include"Camera2.h"
#include"Scene.h"
#include"Mouse.h"

SDL_Window *GamePlay::m_window = nullptr;
SDL_Renderer *GamePlay::m_renderer = nullptr;
bool GamePlay::m_quit = false;

GamePlay::GamePlay()
{
	m_scene = nullptr;
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

		m_scene->SetEvent(m_event);
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
			   SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN);

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

	/*this->m_camera = new Camera2(new Vector2D(0, 0), 1024, 768);*/
	SDL_ShowCursor(SDL_DISABLE);

	m_mouse = new Mouse(new Texture("img/cursores.png", m_renderer, 26, 26), new Vector2D(0, 0));
	m_scene = new Scene();
	m_scene->Initialize();
}

void GamePlay::Update()
{
	SetEvent();

	m_scene->Update();
}

void GamePlay::Draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	SDL_RenderClear(m_renderer);

	m_scene->DrawOnCamera();
	m_mouse->Draw();
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

	m_scene->End();

	delete m_scene;
	m_scene = nullptr;

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
		}

		End();

	}
	catch (std::exception &e)
	{
		std::cout << "ERRO INESPERADO. CODIGO: " << e.what() << std::endl;
	}
}
