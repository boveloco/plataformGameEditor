#include "Editor.h"
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

Editor::Editor(SpriteSet * spriteSet, Map* map, SDL_Window* p_window) :
	m_index(new int[2]), m_quit(false), img(0), m_camera_editor(nullptr), m_texture(nullptr),
	spriteSet(spriteSet), mapCameraEditor(map), m_window(p_window), hints(nullptr)
{}

Editor::~Editor()
{
	//this->End();
}

bool Editor::Quit()
{
	return m_quit;
}

void Editor::SetEvent(SDL_Event &p_event)
{
	if (p_event.type == SDL_KEYUP)
	{
		switch (p_event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			GamePlay::setLastIndex(1);
			GamePlay::SetIndex(0);
			break;
		case SDLK_LEFT:
			m_camera_editor->UpDate(-m_texture->GetWidth(), 0);
			break;
		case SDLK_RIGHT:
			m_camera_editor->UpDate(m_texture->GetWidth(), 0);
			break;
			////
		case SDLK_q:
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
			break;
		case SDLK_e:
			SDL_ShowCursor(SDL_ENABLE);
			m_index[0] = -spriteSet->getXSize();
			m_index[1] = -spriteSet->getYSize();
			img = 0;
			break;
		case SDLK_RETURN:
			std::cout << "Salvou Mapa" << std::endl;
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Mapa Salvo", "Mapa foi devidamente Salvo", m_window);
			this->mapCameraEditor->writeMap(mapa);
			break;
		case SDLK_BACKSPACE:
			std::cout << "Salvou Mapa" << std::endl;
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mapa novo criado", "Novo mapa foi criado. Dimensoes: 100x, 10y", m_window);
			this->mapCameraEditor = new Map(100, 10);
			m_camera_editor->SetPosition(0, 0);
			break;
		case SDLK_RSHIFT:
			std::cout << "Mapa Carregado" << std::endl;
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Mapa carregado!",  mapa  , m_window);
			this->mapCameraEditor = mapCameraEditor->readMap(mapa);
			m_camera_editor->SetPosition(0, 0);
			break;
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
	this->hints = new Texture("img/hints.png", GamePlay::GetRenderer(),100,300);
	this->m_camera_editor = new Camera(
								new Vector2D(SIZE_WINDOW_X - (spriteSet->getXSize() * 4), 0)
							  , SIZE_WINDOW_X - (spriteSet->getXSize() * 4)
							  , SIZE_WINDOW_Y
							  , mapCameraEditor
							  , spriteSet);

	Map* ma = new Map(4,spriteSet->getCount() / 4);
	std::cout << spriteSet->getCount() << std::endl;
	ma->setSpritePallete();
	this->m_camera_spriteSet = new Camera(new Vector2D(0, 0), spriteSet->getXSize() * 4, spriteSet->getCount() / 4 * spriteSet->getYSize(), ma->setSpritePallete(), spriteSet);
	this->m_texture = new Texture(spriteSet, GamePlay::GetRenderer());
}

void Editor::UpDate()
{

	if (Mouse::GetX() > SIZE_WINDOW_X - Mouse::GetWidth())
	{
		m_camera_editor->UpDate(5, 0);
	}
	else if ((Mouse::GetX() <= Mouse::GetWidth()))
	{
		m_camera_editor->UpDate(-5, 0);
	}

	if (Mouse::GetButtonLeft())
	{
		int* n = new int(2);
		n[CAMERA_X] = ((Mouse::GetX() - (spriteSet->getXSize() * 4)) + this->m_camera_editor->GetPosition(CAMERA_X)) / this->spriteSet->getXSize();
		if (n[CAMERA_X] < 0)
			n[CAMERA_X] = 0;
		n[CAMERA_Y] = (Mouse::GetY() + this->m_camera_editor->GetPosition(CAMERA_Y)) / this->spriteSet->getYSize();

		this->mapCameraEditor->setSprite(n, img);

	}
	else if (Mouse::GetButtonRight())
	{
		int* n = new int(2);
		n[CAMERA_X] = (Mouse::GetX() + this->m_camera_editor->GetPosition(CAMERA_X)) / this->spriteSet->getXSize();
		n[CAMERA_Y] = (Mouse::GetY() + this->m_camera_editor->GetPosition(CAMERA_Y)) / this->spriteSet->getYSize();
		this->mapCameraEditor->setSprite(n, img);

	}
}

void Editor::Draw()
{
	//CAMERAS
	m_camera_spriteSet->draw(m_texture);
	m_camera_editor->draw(m_texture);
	//DICAS
	this->hints->Draw(GamePlay::GetRenderer(), new Vector2D(0, 0));
	//MOUSE
	Mouse::Draw(m_index[CAMERA_X], m_index[CAMERA_Y]);
}

void Editor::DrawOnCamera() //DEPRECATED!
{
	for (size_t i = 0; i < mapCameraEditor->getYSize(); i++)
	{
		for (size_t j = 0; j < mapCameraEditor->getXSize(); j++)
		{
			//vector recebe a posicao menos o x e y da camera
			Vector2D* v = new Vector2D((j*spriteSet->getXSize()) - m_camera_editor->GetPosition(CAMERA_X) + (spriteSet->getXSize() * 4), (i*spriteSet->getYSize() - m_camera_editor->GetPosition(CAMERA_Y)));
			m_texture->Draw(GamePlay::GetRenderer(), v , spriteSet->getSprite(mapCameraEditor->getSprite(j, i))[0], spriteSet->getSprite(mapCameraEditor->getSprite(j, i))[1]);
			delete v;
		}
	}
}

void Editor::End()
{
	if (m_camera_editor)
	{
		delete m_camera_editor;
		m_camera_editor = nullptr;
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
