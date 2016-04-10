#include "Scene.h"
#include"Camera2.h"
#include"Map.h"
#include"Texture.h"
#include"SpriteSet.h"
#include"Vector2D.h"
#include"GamePlay.h"

Scene::Scene()
{
	m_quit = false;

	m_camera = nullptr;
	t = nullptr;
	map = nullptr;
	ss = nullptr;
}

Scene::~Scene()
{
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
			m_camera->UpDate(-t->GetWidth(), 0);
			break;
		case SDLK_RIGHT:
			m_camera->UpDate(t->GetWidth(), 0);
			break;
		default:
			break;
		}
	}

}

void Scene::Initialize()
{
	this->m_camera = new Camera2(new Vector2D(0, 0), 1024, 768);

	this->map = new Map(10, 10);
	int * c = new int(2);
	c[0] = 0;
	c[1] = 9;
	for (size_t i = 0; i < 10; i++)
	{
		c[0] = i;
		this->map->setSprite(c, 3);
	}

	this->ss = new SpriteSet("img/tileset.png", 512, 512, 64, 64);
	this->t = new Texture(ss, GamePlay::GetRenderer());
}

void Scene::Update()
{
}

void Scene::Draw()
{
	DrawOnCamera();
}

void Scene::DrawOnCamera()
{
	for (size_t i = 0; i < map->getYSize(); i++)
	{
		for (size_t j = 0; j < map->getXSize(); j++)
		{
			//vector recebe a posição menos o x e y da camera
			Vector2D* v = new Vector2D((j*ss->getXSize()) - m_camera->GetxPosition(), (i*ss->getYSize() - m_camera->GetyPosition()));
			t->Draw(GamePlay::GetRenderer(), v, ss->getSprite(map->getSprite(j, i))[0], ss->getSprite(map->getSprite(j, i))[1]);
			delete(v);

		}
	}
}

void Scene::End()
{
	delete m_camera;
	delete map;
	delete t;

	m_camera = nullptr;
	map = nullptr;
	t = nullptr;
}
