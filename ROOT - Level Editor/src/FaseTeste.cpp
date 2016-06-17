#define _CRT_SECURE_NO_WARNINGS

#include"Defines.h"
#include"FaseTeste.h"
#include"Box.h"
#include"Texture.h"
#include"SpriteSet.h"
#include"Map.h"
#include"Physic.h"
#include"GamePlay.h"
#include"Vector2D.h"
#include"Camera.h"
#include"Tile.h"
#include"Hero.h"
#include"RigidBody2D.h"



FaseTeste::FaseTeste(SpriteSet *p_spriteSet) : Scene(S_GAME),
		   m_spriteSet(p_spriteSet), m_map(new Map(100,12)), 
		   m_image(nullptr), m_mapa(nullptr), m_camera(nullptr)
{
	for (int i = 0; i < 5; i++)
	{
		fases[i] = new char[9];
		sprintf(fases[i], "map%d.dat", i+1);
	}

	m_mapa = fases[0];
}

FaseTeste::~FaseTeste()
{
	End();
}

void FaseTeste::AddTiles()
{
	for (size_t i = 0; i < m_map->getYSize(); i++)
	{
		for (size_t j = 0; j < m_map->getXSize(); j++)
		{
			if (m_spriteSet->getSprite(m_map->getSprite(j, i))[0] < 0 ||
				m_spriteSet->getSprite(m_map->getSprite(j, i))[1] < 0)
			{
				continue;
			}
			//vector recebe a posição menos o x e y da camera
			Vector2D* v = new Vector2D(j*m_spriteSet->getXSize(),
									   i*m_spriteSet->getYSize());

			Tile *tile = new Tile(m_image, v, m_spriteSet->getSprite(m_map->getSprite(j, i))[0],
									m_spriteSet->getSprite(m_map->getSprite(j, i))[1]);
			tile->Initialize();
			m_tiles.push_back(tile);
		}
	}
}

void FaseTeste::DestroyTile()
{
	for (Tile *t : m_tiles)
	{
		delete t;
	}

	m_tiles.clear();
}

void FaseTeste::Initialize()
{
	m_image = new Texture(m_spriteSet, GamePlay::GetRenderer());
	m_map = m_map->readMap(m_mapa);
	AddTiles();
	m_camera = new Camera(new Vector2D(0, 0), SIZE_WINDOW_X, SIZE_WINDOW_Y, m_map, m_spriteSet);
	m_hero = new Hero(new Texture(PLAYER_IMAGE, GamePlay::GetRenderer(), 41, 44),
								  new Vector2D(20, 20), nullptr, m_camera);
	m_hero->Initialize();
}

void FaseTeste::UpDate()
{
	m_hero->UpDate();

	for (Tile *t : m_tiles)
	{
		if (t->GetX() - m_camera->GetxPosition() >= 0 &&
			t->GetX() - m_camera->GetxPosition() <= SIZE_WINDOW_X)
		{
			if (Physic::Collision(m_hero->GetTransform()->GetCollider(), t->GetCollider()))
			{
				m_hero->CollideTile(t);
			}
		}
	}

	if (m_hero->GetXPosition() < GetLimitLeft())
	{
		m_camera->SetxPosition(m_hero->GetXPosition() - (SIZE_WINDOW_X * 0.40));
		if (m_camera->GetxPosition() <= 0)
		{
			m_camera->SetxPosition(0);
		}
	}
	else if (m_hero->GetXPosition() + m_hero->GetWidth() > GetLimitRight())
	{
		m_camera->SetxPosition(m_hero->GetXPosition() + m_hero->GetWidth() - (SIZE_WINDOW_X * 0.60));

		if (m_camera->GetxPosition() + SIZE_WINDOW_X >= (m_map->getXSize() * m_spriteSet->getXSize()))
		{
			m_camera->SetxPosition((m_map->getXSize() * m_spriteSet->getXSize()) - SIZE_WINDOW_X);
		}
	}
	if (m_hero->GetYPosition() > SIZE_WINDOW_Y)
		m_hero->SetPosition(0, 0);
	if (m_hero->GetXPosition() > m_map->getXSize()*m_spriteSet->getXSize() - m_spriteSet->getXSize())
	{
		contFase++;
		//delete m_map;
		//m_map = new Map(getFases(contFase));
		std::cout << m_mapa << std::endl;
		m_mapa = getFases(contFase);
		std::cout << m_mapa << std::endl;
		m_map = m_map->readMap(m_mapa);
		DestroyTile();
		AddTiles();
		m_hero->SetPosition(0, 0);
	}
}

void FaseTeste::Draw()
{
	/*for (Box *t : m_tiles)
	{
		m_image->Draw(GamePlay::GetRenderer(), t->GetPosition(), 0, 0);
	}*/
	for (Tile *t : m_tiles)
	{
		m_image->Draw(GamePlay::GetRenderer(), t->GetX() - m_camera->GetxPosition(), 
					  t->GetY() - m_camera->GetyPosition(), t->GetIndexX(), t->GetIndexY());
	}

	m_hero->Draw();
}

void FaseTeste::DrawOnCamera()
{
	for (size_t i = 0; i < m_map->getYSize(); i++)
	{
		for (size_t j = 0; j < m_map->getXSize(); j++)
		{
			//vector recebe a posição menos o x e y da camera
			//Vector2D* v = new Vector2D((j*spriteSet->getXSize()) - m_camera->GetPosition(CAMERA_X) + (spriteSet->getXSize() * 4),
				//(i*spriteSet->getYSize() - m_camera->GetPosition(CAMERA_Y)));
			//if (v->GetX() >= (spriteSet->getXSize() * 4) && v->GetX() <= m_camera->GetWidth())
			//{
				//m_texture->Draw(GamePlay::GetRenderer(), v, spriteSet->getSprite(map->getSprite(j, i))[0],
					//spriteSet->getSprite(map->getSprite(j, i))[1]);
			//}

			//delete v;
		}
	}
}

int FaseTeste::GetLimitLeft() const
{
	return m_camera->GetxPosition() + (SIZE_WINDOW_X * 0.40);
}

int FaseTeste::GetLimitRight() const
{
	return m_camera->GetxPosition() + (SIZE_WINDOW_X * 0.60);
}
	
void FaseTeste::End()
{
	/*if (m_spriteSet)
	{
		delete m_spriteSet;
		m_spriteSet = nullptr;
	}*/
	if (m_map)
	{
		delete m_map;
		m_map = nullptr;
	}
	if (m_image)
	{
		delete m_image;
		m_image = nullptr;
	}
	/*if (m_tiles.size() > 0)
	{
		for (Box *b : m_tiles)
		{
			delete b;
			b = nullptr;
		}

		m_tiles.clear();
	}*/
	if (m_tiles.size() > 0)
	{
		for (Tile *t : m_tiles)
		{
			delete t;
			t = nullptr;
		}

		m_tiles.clear();
	}
	if (m_hero)
	{
		delete m_hero;
		m_hero = nullptr;
	}
}

void FaseTeste::SetEvent(SDL_Event &p_event)
{
	if (p_event.type == SDL_KEYUP)
	{
		if (p_event.key.keysym.sym == SDLK_ESCAPE)
		{
			GamePlay::SetIndex(0);
		}
		if (p_event.key.keysym.sym == SDLK_RIGHT)
		{
			m_hero->SetRight(false);
		}
		if (p_event.key.keysym.sym == SDLK_LEFT)
		{
			m_hero->SetLeft(false);
		}
		if (p_event.key.keysym.sym == SDLK_SPACE)
		{
			m_hero->SetJump(true);
		}
	}
	if (p_event.type == SDL_KEYDOWN)
	{
		if (p_event.key.keysym.sym == SDLK_RIGHT)
		{
			m_hero->SetRight(true);
		}
		if (p_event.key.keysym.sym == SDLK_LEFT)
		{
			m_hero->SetLeft(true);
		}
		
	}
}
