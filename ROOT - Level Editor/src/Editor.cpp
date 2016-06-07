#include "Editor.h"
#include"Camera.h"
#include"Map.h"
#include"Texture.h"
#include"SpriteSet.h"
#include"Vector2D.h"
#include"GamePlay.h"
#include "Mouse.h"
#include "Defines.h"
#include"MiniTile.h"
#include"Box.h"
#include"Physic.h"
#include"Button.h"

//Scene::Scene(SpriteSet* spriteSet, Map* map) {
//	m_quit = false;
//
//	m_camera = nullptr;
//	m_texture = nullptr;
//	this->spriteSet = spriteSet;
//	this->map = map;
//}

Editor::Editor(SpriteSet * spriteSet, Map* map, SDL_Window* p_window) :
	m_index(new int[2]), m_quit(false), img(0), m_camera(nullptr), m_texture(nullptr),
	spriteSet(spriteSet), map(map), m_window(p_window), hints(nullptr)
{}

Editor::~Editor()
{
	//this->End();
}

bool Editor::Quit()
{
	return m_quit;
}

SpriteSet *Editor::GetSpriteSet() const
{
	return spriteSet;
}

void Editor::AddButtons()
{
	float sizeX = spriteSet->getXSize() / 2;
	float sizeY = spriteSet->getYSize() / 2;
	float x = 1, y = sizeY * 2;
	
	for (int i = 0; i < spriteSet->getSpriteset().size(); i++)
	{
		if (x > 8)
		{
			x = 1;
			y += sizeY + 10;
		}

		m_buttons.push_back(new Button(new Texture("img/tileset.png",
												   GamePlay::GetRenderer(),
												   spriteSet->getXSize(), 
												   spriteSet->getYSize()),
									   new Vector2D(x * sizeX - 20, y), B_TILE));
		x += 2;
	}

	float auxX = 10, auxY = 15;
	int sizeX1 = 64, sizeY1 = 30;

	m_buttons.push_back(new Button(new Texture("img/Botoes/NEW.png",
												GamePlay::GetRenderer(), sizeX1, sizeY1),
								  new Vector2D(auxX, auxY), B_NEW));

	m_buttons.push_back(new Button(new Texture("img/Botoes/SAVE.png",
												GamePlay::GetRenderer(), sizeX1, sizeY1),
								   new Vector2D(auxX + sizeX1 + 15, auxY), B_SAVE));

	m_buttons.push_back(new Button(new Texture("img/Botoes/LOAD.png",
												GamePlay::GetRenderer(), sizeX1, sizeY1),
								   new Vector2D(auxX + (sizeX1 * 2) + 30, auxY), B_LOAD));


	for (Button *button : m_buttons)
	{
		button->Initialize();

		if (button->GetType() == B_TILE)
		{
			if (Box *box = dynamic_cast<Box *>(button->GetGeometricShape()))
			{
				box->SetHeight(box->GetHeight() / 2);
				box->SetWidth(box->GetWidth() / 2);
			}
		}
	}
}

void Editor::AddTiles()
{
	float x = 1, y = spriteSet->getYSize() / 2;
	float sizeX = spriteSet->getXSize() / 2;
	y *= 2;
	for (int *i : spriteSet->getSpriteset())
	{
		if (x > 8)
		{
			x = 1;
			y += spriteSet->getYSize() / 2 + 10;
		}

		m_tiles.push_back(new MiniTile(m_texture, new Vector2D(x * sizeX - 20, y), i[0], i[1]));
		x += 2;
	}

	for (MiniTile *m : m_tiles)
	{
		m->Initialize();
	}
}

void Editor::SetEvent(SDL_Event &p_event)
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
		}
	}
	if (p_event.type == SDL_KEYUP)
	{
		switch (p_event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			GamePlay::setLastIndex(1);
			GamePlay::SetIndex(0);
			break;
			////
		/*case SDLK_q:
			img--;
			if (img <= 0)
				img = 1;
			memcpy(m_index, spriteSet->getSprite(img), sizeof(spriteSet->getSprite(img)));
			SDL_ShowCursor(SDL_DISABLE);
			break;
		case SDLK_w:
			img++;
			if (img > spriteSet->getCount())
				img = spriteSet->getCount();
			memcpy(m_index, spriteSet->getSprite(img), sizeof(spriteSet->getSprite(img)));
			SDL_ShowCursor(SDL_DISABLE);
			break;*/
		case SDLK_e:
			//SDL_ShowCursor(SDL_ENABLE);
			m_index[0] = -spriteSet->getXSize();
			m_index[1] = -spriteSet->getYSize();
			img = 0;
			break;
		/*case SDLK_RETURN:
			std::cout << "Salvou Mapa" << std::endl;
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Mapa Salvo", "Mapa foi devidamente Salvo", m_window);
			this->map->writeMap(mapa);
			break;
		case SDLK_BACKSPACE:
			std::cout << "Salvou Mapa" << std::endl;
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mapa novo criado", "Novo mapa foi criado. Dimensoes: 100x, 10y", m_window);
			this->map = new Map(100, 10);
			m_camera->SetPosition(0, 0);
			break;
		case SDLK_RSHIFT:
			std::cout << "Mapa Carregado" << std::endl;
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mapa carregado!",  mapa  , m_window);
			this->map = map->readMap(mapa);
			m_camera->SetPosition(0, 0);
			break;*/
		case SDLK_1:
			this->mapa = "map1.dat";
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mapa selecionado!", "Mapa 1 selecionado!" , m_window);
			break;
		case SDLK_2:
			this->mapa = "map2.dat";
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mapa selecionado!", "Mapa 2 selecionado!", m_window);
			break;
		case SDLK_3:
			this->mapa = "map3.dat";
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mapa selecionado!", "Mapa 3 selecionado!", m_window);
			break;
		case SDLK_4:
			this->mapa = "map4.dat";
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mapa selecionado!", "Mapa 4 selecionado!", m_window);
			break;
		case SDLK_5:
			this->mapa = "map5.dat";
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mapa selecionado!", "Mapa 5 selecionado!", m_window);
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

void Editor::Initialize()
{
	this->hints = new Texture("img/MenuBotoes.png", GamePlay::GetRenderer(),256,768);
	this->m_camera = new Camera(new Vector2D(0, 0), SIZE_WINDOW_X, SIZE_WINDOW_Y, map, spriteSet);
	this->m_texture = new Texture(spriteSet, GamePlay::GetRenderer());

	//AddTiles();
	AddButtons();
}

void Editor::UpDate()
{
	if (Mouse::GetX() >= spriteSet->getXSize() * 4)
	{
		if (Mouse::GetX() > SIZE_WINDOW_X - Mouse::GetWidth())
		{
			m_camera->UpDate(5, 0);
		}
		else if ((Mouse::GetX() <= spriteSet->getXSize() * 4 + Mouse::GetWidth()))
		{
			m_camera->UpDate(-5, 0);
		}

		if (Mouse::GetButtonLeft())
		{
			int* n = new int(2);
			n[CAMERA_X] = ((Mouse::GetX() - (spriteSet->getXSize() * 4)) + this->m_camera->GetPosition(CAMERA_X)) / this->spriteSet->getXSize();
			if (n[CAMERA_X] < 0)
				n[CAMERA_X] = 0;
			n[CAMERA_Y] = (Mouse::GetY() + this->m_camera->GetPosition(CAMERA_Y)) / this->spriteSet->getYSize();

			this->map->setSprite(n, img);

		}
		else if (Mouse::GetButtonRight())
		{
			int* n = new int(2);
			n[CAMERA_X] = (Mouse::GetX() + this->m_camera->GetPosition(CAMERA_X)) / this->spriteSet->getXSize();
			n[CAMERA_Y] = (Mouse::GetY() + this->m_camera->GetPosition(CAMERA_Y)) / this->spriteSet->getYSize();
			this->map->setSprite(n, img);

		}

		if (img > 0)
		{
			SDL_ShowCursor(SDL_DISABLE);
		}
		else
		{
			SDL_ShowCursor(SDL_ENABLE);
		}
	}
	else
	{
		SDL_ShowCursor(SDL_ENABLE);

		if (Mouse::GetButtonLeft())
		{
			int i = 1;
			/*for (MiniTile *tile : m_tiles)
			{
				if (Physic::PointBoxColisionCheck(Mouse::GetPosition(), tile->GetCollider()))
				{
					m_index[0] = tile->GetIndexX();
					m_index[1] = tile->GetIndexY();
					img = i;
					break;
				}
				i++;
			}*/

			for (Button *button : m_buttons)
			{
				if (Physic::PointBoxColisionCheck(Mouse::GetPosition(), button->GetGeometricShape()))
				{
					if (button->GetType() == B_TILE)
					{
						img = i;
						m_index[0] = spriteSet->getSprite(img)[0];
						m_index[1] = spriteSet->getSprite(img)[1];
						break;
					}
					else if (button->GetType() == B_NEW)
					{
						delete map;
						SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mapa novo criado", "Novo mapa foi criado. Dimensoes: 100x, 10y", m_window);
						this->map = new Map(100, 10);
						m_camera->SetPosition(0, 0);
						break;
					}
					else if (button->GetType() == B_SAVE)
					{
						SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mapa Salvo", "Mapa foi devidamente Salvo", m_window);
						this->map->writeMap(mapa);
						break;
					}
					else if (button->GetType() == B_LOAD)
					{
						SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mapa carregado!", mapa, m_window);
						this->map = map->readMap(mapa);
						m_camera->SetPosition(0, 0);
						break;
					}
					break;
				}
				i++;
			}
		}
	}
}

void Editor::Draw()
{
	this->hints->Draw(GamePlay::GetRenderer(), new Vector2D(0, 0));

	DrawOnCamera();

	/*for (MiniTile *tile : m_tiles)
	{
		tile->Draw();
	}*/

	int count = 0;
	float sizeX = spriteSet->getXSize() / 2;
	float sizeY = spriteSet->getYSize() / 2;

	for (int *i : spriteSet->getSpriteset())
	{
		m_buttons[count]->GetImage()->Draw(GamePlay::GetRenderer(), 
										   m_buttons[count]->GetPosition(), 
										   i[0], i[1], sizeX, sizeY);
		count++;
	}

	for (int i = m_buttons.size() - 3; i < m_buttons.size(); i++)
	{
		m_buttons[i]->Draw();
	}

	if (Mouse::GetX() >= spriteSet->getXSize() * 4)
		Mouse::Draw(m_index[CAMERA_X], m_index[CAMERA_Y]);
}

void Editor::DrawOnCamera()
{
	for (size_t i = 0; i < map->getYSize(); i++)
	{
		for (size_t j = 0; j < map->getXSize(); j++)
		{
			//vector recebe a posi��o menos o x e y da camera
			Vector2D* v = new Vector2D((j*spriteSet->getXSize()) - m_camera->GetPosition(CAMERA_X) + (spriteSet->getXSize() * 4), 
										(i*spriteSet->getYSize() - m_camera->GetPosition(CAMERA_Y)));
			if (v->GetX() >= (spriteSet->getXSize() * 4) && v->GetX() <= m_camera->GetWidth())
			{
				m_texture->Draw(GamePlay::GetRenderer(), v, spriteSet->getSprite(map->getSprite(j, i))[0],
								spriteSet->getSprite(map->getSprite(j, i))[1]);
			}

			delete v;
		}
	}
}

void Editor::End()
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
	if (m_tiles.size() > 0)
	{
		for (MiniTile *tile : m_tiles)
		{
			delete tile;
			tile = nullptr;
		}

		m_tiles.clear();
	}
	if (m_buttons.size() > 0)
	{
		for (Button *button : m_buttons)
		{
			delete button;
			button = nullptr;
		}

		m_buttons.clear();
	}
	if (m_index)
	{
		delete[] m_index;
		m_index = nullptr;
	}
}
