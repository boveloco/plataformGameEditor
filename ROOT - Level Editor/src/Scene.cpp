#include "Scene.h"
#include"Camera.h"
#include"Map.h"
#include"Texture.h"
#include"SpriteSet.h"
#include"Vector2D.h"
#include"GamePlay.h"
#include "Mouse.h"
#include "Defines.h"


//Scene::Scene(SpriteSet* spriteSet, Map* map) {
//	m_quit = false;
//
//	m_camera = nullptr;
//	m_texture = nullptr;
//	this->spriteSet = spriteSet;
//	this->map = map;
//}

Scene::Scene(SpriteSet * spriteSet, Map* map, SDL_Window* p_window)
{
	m_index = new int[2];
	m_quit = false;
	img = 0;
	m_camera = nullptr;
	m_texture = nullptr;
	this->spriteSet = spriteSet;
	this->map = map;
	this->m_window = p_window;
}

Scene::~Scene()
{
	//this->End();
}

bool Scene::Quit()
{
	return m_quit;
}

void Scene::SetEvent(SDL_Event &p_event)
{
	if (p_event.type == SDL_KEYDOWN)
	{
		switch (p_event.key.keysym.sym)
		{
		case SDLK_LEFT:
			m_camera->UpDate(-m_texture->GetWidth(), 0);
			break;
		case SDLK_RIGHT:
			m_camera->UpDate(m_texture->GetWidth(), 0);
			break;
			////
		case SDLK_q:
			img--;
			if (img <= 0)
				img = 1;
			m_index = spriteSet->getSprite(img);
			SDL_ShowCursor(SDL_DISABLE);
			break;
			////
		case SDLK_w:
			img++;
			if (img > spriteSet->getCount())
				img = spriteSet->getCount();
			m_index = spriteSet->getSprite(img);
			SDL_ShowCursor(SDL_DISABLE);
			break;
		case SDLK_e:
			SDL_ShowCursor(SDL_ENABLE);
			m_index[0] = -100;
			m_index[1] = -100;
			img = 0;
			break;
		case SDLK_RETURN:
			std::cout << "Salvou Mapa" << std::endl;
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Mapa Salvo", "Mapa foi devidamente Salvo", m_window);
			this->map->writeMap("map.dat");
			break;
		case SDLK_BACKSPACE:
			std::cout << "Salvou Mapa" << std::endl;
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mapa novo criado", "Novo mapa foi criado. Dimensoes: 100x, 10y", m_window);
			this->map = new Map(100, 10);
			m_camera->SetPosition(0, 0);
			break;
		case SDLK_RSHIFT:
			std::cout << "Mapa Carregado" << std::endl;
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mapa carregado!", "map.dat deu load;", m_window);
			this->map = map->readMap("map.dat");
			m_camera->SetPosition(0, 0);
			break;
		default:
			break;
		}
	}
	if (p_event.type == SDL_MOUSEBUTTONDOWN) {
		if (p_event.button.button == SDL_BUTTON_LEFT) {
			Mouse::SetButtonLeft(true);
		}
		else if (p_event.button.button == SDL_BUTTON_RIGHT) {
			Mouse::SetButtonRight(true);
		}
	}
	else if (p_event.type == SDL_MOUSEBUTTONUP)
	{
		if (p_event.button.button == SDL_BUTTON_LEFT) {
			Mouse::SetButtonLeft(false);
		}
		else if (p_event.button.button == SDL_BUTTON_RIGHT) {
			Mouse::SetButtonRight(false);
		}
	}
}

void Scene::Initialize()
{
	this->m_camera = new Camera(new Vector2D(0, 0), 1024, 768, map, spriteSet);
	this->m_texture = new Texture(spriteSet, GamePlay::GetRenderer());
}

void Scene::Update()
{
	if (Mouse::GetButtonLeft())
	{
		int* n = new int(2);
		n[CAMERA_X] = (Mouse::GetX() + this->m_camera->GetPosition(CAMERA_X)) / this->spriteSet->getXSize();
		n[CAMERA_Y] = (Mouse::GetY() + this->m_camera->GetPosition(CAMERA_Y)) / this->spriteSet->getYSize();

		this->map->setSprite(n, img);

		if (Mouse::GetX() > SIZE_WINDOW_X - Mouse::GetWidth())
		{
			m_camera->UpDate(5, 0);
		}
		else if ((Mouse::GetX() <= Mouse::GetWidth()))
		{
			m_camera->UpDate(-5, 0);
		}
	}
	else if (Mouse::GetButtonRight())
	{
		int* n = new int(2);
		n[CAMERA_X] = (Mouse::GetX() + this->m_camera->GetPosition(CAMERA_X)) / this->spriteSet->getXSize();
		n[CAMERA_Y] = (Mouse::GetY() + this->m_camera->GetPosition(CAMERA_Y)) / this->spriteSet->getYSize();
		this->map->setSprite(n, img);

		if (Mouse::GetX() > SIZE_WINDOW_X - Mouse::GetWidth()*2)
		{
			m_camera->UpDate(5, 0);
		}
		else if ((Mouse::GetX() <= Mouse::GetWidth()*2))
		{
			m_camera->UpDate(-5, 0);
		}
	}
}

void Scene::Draw()
{
	DrawOnCamera();

	Mouse::Draw(m_index[CAMERA_X], m_index[CAMERA_Y]);
}

void Scene::DrawOnCamera()
{
	for (size_t i = 0; i < map->getYSize(); i++)
	{
		for (size_t j = 0; j < map->getXSize(); j++)
		{
			//vector recebe a posição menos o x e y da camera
			Vector2D* v = new Vector2D((j*spriteSet->getXSize()) - m_camera->GetPosition(CAMERA_X), (i*spriteSet->getYSize() - m_camera->GetPosition(CAMERA_Y)));
			m_texture->Draw(GamePlay::GetRenderer(), v, spriteSet->getSprite(map->getSprite(j, i))[0], spriteSet->getSprite(map->getSprite(j, i))[1]);
			delete v;
		}
	}
}

void Scene::End()
{
	if (m_camera)
	{
		delete m_camera;
		m_camera = nullptr;
	}
	if (m_texture)
	{
		delete m_texture;
		m_texture = nullptr;
	}
	/*if (m_index)
	{
		delete[] m_index;
		m_index = nullptr;
	}*/
}
