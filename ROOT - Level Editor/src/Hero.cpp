#include "Hero.h"
#include"Texture.h"
#include"Vector2D.h"
#include"GeometricShape.h"
#include"RigidBody2D.h"
#include"GamePlay.h"
#include"Box.h"
#include"Physic.h"
#include"Camera.h"
#include"Tile.h"
#include<math.h>

Hero::Hero(Texture *p_image, Vector2D *p_position, GeometricShape *p_geometricShape, Camera *p_camera) :
	  GameObject(p_image, p_position, p_geometricShape), m_camera(p_camera),
	  m_moveLeft(false), m_moveRight(false), m_jump(false), m_count(0)
{}

Hero::~Hero()
{
	End();
}

void Hero::SetLeft(bool p_left)
{
	m_moveLeft = p_left;
}

void Hero::SetRight(bool p_right)
{
	m_moveRight = p_right;
}

void Hero::SetJump(bool p_jump)
{
	m_jump = p_jump;
}

void Hero::CollideTile(Tile *p_tile)
{
	float catX = GetXCenter() - (p_tile->GetX() + (p_tile->GetImage()->GetWidth() / 2));
	float catY = GetYCenter() - (p_tile->GetY() + (p_tile->GetImage()->GetHeight() / 2));

	float sumHalfWidth = (GetWidth()/2) + (p_tile->GetImage()->GetWidth()/2);
	float sumHalfHeight = (GetHeight()/2) + (p_tile->GetImage()->GetHeight()/2);

	float overlapx = sumHalfWidth - abs(catX);
	float overlapy = sumHalfHeight - abs(catY);

	if (overlapx >= overlapy)
	{
		if (catY > 0)//por cima do objeto controlado
		{
			m_transform->GetVelocity()->SetY(0);
			GetPosition()->SetY(GetYPosition() + overlapy);
		}
		else // por baixo
		{
			m_transform->GetVelocity()->SetY(0);
			GetPosition()->SetY(GetYPosition() - overlapy);
		}

	}
	else//colisão por esquerda ou direita
	{
		if (catX > 0)//esquerda do objeto controlado
		{
			GetPosition()->SetX(GetXPosition() + overlapx);
		}
		else//direita
		{
			GetPosition()->SetX(GetXPosition() - overlapx);
		}
	}

	m_count = 0;
}

void Hero::Initialize()
{
	m_transform->SetStatic(false);
	m_transform->SetCollider(new Box(GetPosition(), 41, 44));
	m_transform->GetVelocity()->SetX(5);
}

void Hero::UpDate()
{
	*m_transform->GetVelocity() += *Physic::GetGravity();

	if (m_moveLeft)
	{
		GetPosition()->SetX(GetXPosition() - m_transform->GetVelocity()->GetX());
		//m_transform->GetVelocity()->SetX(-5);
	}
	if (m_moveRight)
	{
		//m_transform->GetVelocity()->SetX(5);
		GetPosition()->SetX(GetXPosition() + m_transform->GetVelocity()->GetX());
	}
	if (m_jump)
	{
		if (m_count == 0)
		{
			m_count++;
			*m_transform->GetVelocity() -= *m_transform->GetUp() * 20;
		}
		else if (m_count == 1)
		{
			m_count++;
			*m_transform->GetVelocity() -= *m_transform->GetUp() * 8;
		}

		m_jump = false;
	}

	GetPosition()->SetY(GetYPosition() + m_transform->GetVelocity()->GetY());
	//*GetPosition() += *m_transform->GetVelocity();

	if (GetPosition()->GetX() <= 0)
		GetPosition()->SetX(0);
	else if (GetPosition()->GetX() + GetWidth() >= m_camera->GetxPosition() + m_camera->GetWidth())
	{
		GetPosition()->SetX((m_camera->GetxPosition() + m_camera->GetWidth()) - GetWidth());
	}

	//m_transform->GetVelocity()->SetX(0);
}

void Hero::Draw()
{
	m_image->Draw(GamePlay::GetRenderer(), 
				  GetXPosition() - m_camera->GetxPosition(), 
				  GetYPosition() - m_camera->GetyPosition());
}

void Hero::End()
{
	if (m_image)
	{
		delete m_image;
		m_image = nullptr;
	}
	if (m_transform)
	{
		delete m_transform;
		m_transform = nullptr;
	}
}
