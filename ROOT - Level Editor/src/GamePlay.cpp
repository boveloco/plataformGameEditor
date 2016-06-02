#include <iostream>

#include"GamePlay.h"
#include"Texture.h"
#include"Vector2D.h"
#include"SpriteSet.h"
#include"Map.h"
#include"Camera.h"
#include"Editor.h"
#include"Mouse.h"
#include "Defines.h"
#include"Menu.h"
#include"Button.h"

SDL_Window *GamePlay::m_window = nullptr;
SDL_Renderer *GamePlay::m_renderer = nullptr;
bool GamePlay::m_quit = false;
int GamePlay::m_index = 0;
std::vector<Scene *> GamePlay::m_scenes;
int GamePlay::lastIndex = 0;

GamePlay::GamePlay()
{}

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

void GamePlay::AddScenes(Scene *p_scene)
{
	p_scene->Initialize();
	m_scenes.push_back(p_scene);
}

void GamePlay::SetEvent()
{
	while (SDL_PollEvent(&m_event))
	{
		if (m_event.type == SDL_QUIT)
		{
			m_quit = true;
		}
		/*if (m_event.type == SDL_KEYDOWN)
		{
			switch (m_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_quit = true;
				break;
			default:
				break;
			}
		}*/
		if (m_event.type == SDL_MOUSEMOTION)
		{
			m_mouse->SetPosition(m_event.motion.x, m_event.motion.y);
			SDL_MouseIsHaptic();
		}

		m_scenes[m_index]->SetEvent(m_event);
		//this->m_scene->SetEvent(m_event);
	}
}

void GamePlay::SetQuit(bool p_quit)
{
	m_quit = p_quit;
}

void GamePlay::SetIndex(int p_index)
{
	m_index = p_index;
}

void GamePlay::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < NULL)
	{
		throw std::runtime_error(SDL_GetError());
		m_quit = true;
		return;
	}

	m_window = SDL_CreateWindow("ROOT -- Map Editor", SDL_WINDOWPOS_UNDEFINED,
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
	Map* map = new Map(100,10);
	m_mouse = new Mouse(new Texture("img/tileset.png", m_renderer, 64, 64), new Vector2D(0, 0));
	AddScenes(new Menu(new Texture("img/Menu.png", m_renderer, 1024, 768), new Vector2D(0, 0)));
	AddScenes(new Editor(new SpriteSet("img/tileset.png", 512, 512, 64, 64), map, m_window));
	//this->m_scene = new Editor(new SpriteSet("img/tileset.png",512,512,64,64), map, m_window);
	//this->m_scene->Initialize();
}

void GamePlay::Update()
{
	SetEvent();

	//this->m_scene->UpDate();
	m_scenes[m_index]->UpDate();

	//if(Menu *menu = dynamic_cast<Menu *>(m_scenes[m_index]))
	//{
	//	Menu *menu = dynamic_cast<Menu *>(m_scenes[0]);
	//
	//	/*if (m_scenes.size() > 1)
	//	{
	//		for (int i = 1; i < m_scenes.size(); i++)
	//		{
	//			delete m_scenes[i];
	//			m_scenes[i] = nullptr;
	//			m_scenes.erase(m_scenes.begin() + i);
	//		}
	//		SDL_ShowCursor(SDL_ENABLE);
	//	}*/
	//	if (menu->GetButton()->GetPress())
	//	{
	//		if (menu->GetButton()->GetType() == _EDITOR)
	//		{
	//			
	//			GamePlay::SetIndex(TypeButton::_EDITOR);
	//		}
	//		else if (menu->GetButton()->GetType() == _QUIT)
	//		{
	//			m_quit = true;
	//		}
	//		menu->GetButton()->SetPress(false);
	//	}
	//}
}

void GamePlay::Draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	SDL_RenderClear(m_renderer);

	m_scenes[m_index]->Draw();
	//this->m_scene->Draw();
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

	m_scenes[m_index]->End();

	//limpa a lista de cenas
	//se for usa-la
	if (m_scenes.size() > 0)
	{
		for (Scene *scene : m_scenes)
		{
			delete scene;
			scene = nullptr;
		}

		m_scenes.clear();
	}

	IMG_Quit();
	SDL_Quit();

	//this->m_scene->End();

	//delete this->m_scene;
	//this->m_scene = nullptr;

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
