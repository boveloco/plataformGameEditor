#include "Scene.h"
#include"Camera.h"
#include"Map.h"
#include"Texture.h"
#include"SpriteSet.h"
#include"Vector2D.h"
#include"GamePlay.h"
#include "Mouse.h"


Scene::Scene(SpriteSet* spriteSet, Map* map, Mouse* mouse) {
	m_quit = false;

	m_camera = nullptr;
	t = nullptr;
	this->spriteSet = spriteSet;
	this->map = map;
	this->mouse = mouse;
}
Scene::Scene(SpriteSet * spriteSet, Map* map)
{
	m_quit = false;

	m_camera = nullptr;
	t = nullptr;
	this->spriteSet = spriteSet;
	this->map = map;
}

Scene::~Scene()
{
	this->End();
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
	if (p_event.type == SDL_MOUSEBUTTONDOWN) {
		if (p_event.button.button == SDL_BUTTON_LEFT) {
			int* n = new int(2);
			n[CAMERA_X] = (this->mouse->GetX() + this->m_camera->GetPosition(CAMERA_X)) / this->spriteSet->getXSize();
			n[CAMERA_Y] = (this->mouse->GetY() + this->m_camera->GetPosition(CAMERA_Y)) / this->spriteSet->getYSize();
			this->map->setSprite(n, 3);
		}
		if (p_event.button.button == SDL_BUTTON_RIGHT) {
			int* n = new int(2);
			n[CAMERA_X] = (this->mouse->GetX() + this->m_camera->GetPosition(CAMERA_X)) / this->spriteSet->getXSize();
			n[CAMERA_Y] = (this->mouse->GetY() + this->m_camera->GetPosition(CAMERA_Y)) / this->spriteSet->getYSize();
			this->map->setSprite(n, 0);

		}
	}

}

void Scene::Initialize()
{
	this->m_camera = new Camera(new Vector2D(0, 0), 1024, 768, map, spriteSet);
	this->t = new Texture(spriteSet, GamePlay::GetRenderer());
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
			Vector2D* v = new Vector2D((j*spriteSet->getXSize()) - m_camera->GetPosition(CAMERA_X), (i*spriteSet->getYSize() - m_camera->GetPosition(CAMERA_Y)));
			t->Draw(GamePlay::GetRenderer(), v, spriteSet->getSprite(map->getSprite(j, i))[0], spriteSet->getSprite(map->getSprite(j, i))[1]);
			delete v;
		}
	}
}

void Scene::End()
{
	delete m_camera;
	delete map;
	delete t;
	delete spriteSet;

	m_camera = nullptr;
	map = nullptr;
	t = nullptr;
}
