#include <iostream>

#include "GamePlay.h"
#include "Texture.h"
#include "Vector2D.h"
#include "SpriteSet.h"
#include "Map.h"
#include"Camera2.h"

SDL_Window *GamePlay::m_window = nullptr;
SDL_Renderer *GamePlay::m_renderer = nullptr;
bool GamePlay::m_quit = false;

GamePlay::GamePlay()
{}

GamePlay::~GamePlay()
{
	/*delete m_camera;
	delete ss;
	delete t;
	delete map;

	m_camera = nullptr;
	ss = nullptr;
	t = nullptr;
	map = nullptr*/;
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
			case SDLK_LEFT:
				m_camera->UpDate(t->GetWidth(), 0);
				break;
			case SDLK_RIGHT:
				m_camera->UpDate(-t->GetWidth(), 0);
				break;
			default:
				break;
			}
		}
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

	m_window = SDL_CreateWindow("...", SDL_WINDOWPOS_UNDEFINED,
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

	this->m_camera = new Camera2(new Vector2D(0, 0), 1024, 768);

	this->map = new Map(10, 10);
	int * c = new int(2);
	c[0] = 0;
	c[1] = 4;
	for (size_t i = 0; i < 10; i++)
	{
		c[0] = i;
		this->map->setSprite(c, 3);
	}

	this->ss = new SpriteSet("img/tileset.png", 512, 512, 64, 64);
	this->t = new Texture(ss, this->m_renderer);

}

void GamePlay::Update()
{
	SetEvent();
}

void GamePlay::Draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	SDL_RenderClear(m_renderer);

	DrawOnCamera();
	/*for (size_t i = 0; i < map->getYSize(); i++)
	{
	for (size_t j = 0; j < map->getXSize(); j++)
	{
	Vector2D* v = new Vector2D(j*ss->getXSize(), i*ss->getYSize());
	t->Draw(m_renderer, v, ss->getSprite(map->getSprite(j, i))[0], ss->getSprite(map->getSprite(j, i))[1]);
	delete(v);

	}
	}*/

	//t->Draw(m_renderer, new Vector2D(200, 200), ss->getSprite(3)[0], ss->getSprite(3)[1]);


}

void GamePlay::DrawOnCamera()
{
	for (size_t i = 0; i < map->getYSize(); i++)
	{
		for (size_t j = 0; j < map->getXSize(); j++)
		{
			//vector recebe a posi��o menos o x e y da camera
			Vector2D* v = new Vector2D(j*ss->getXSize() - m_camera->GetxPosition(), i*ss->getYSize() - m_camera->GetyPosition());
			t->Draw(m_renderer, v, ss->getSprite(map->getSprite(j, i))[0], ss->getSprite(map->getSprite(j, i))[1]);
			delete(v);

		}
	}
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

	delete t;
	t = nullptr;
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
