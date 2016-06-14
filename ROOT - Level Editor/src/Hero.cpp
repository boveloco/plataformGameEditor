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

Hero::Hero(Texture *p_image, Vector2D *p_position, GeometricShape *p_geometricShape, Camera *p_camera) :
	  GameObject(p_image, p_position, p_geometricShape), m_camera(p_camera),
	  m_moveLeft(false), m_moveRight(false), m_jump(false), m_count(0), m_xSpeed(5), m_ySpeed(0)
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
	//*m_transform->GetPosition() -= *m_transform->GetVelocity();

	//float catX = GetXCenter() - (p_tile->GetX() + p_tile->GetImage()->GetWidth() / 2);
	//float catY = GetYCenter() - (p_tile->GetY() + p_tile->GetImage()->GetHeight() / 2);

	//float sumHalfWidth = GetWidth()/2 + p_tile->GetImage()->GetWidth()/2;
	//float sumHalfHeight = GetHeight()/2 + p_tile->GetImage()->GetHeight()/2;

	//catX *= (catX < 0) ? -1 : 1;
	//catY *= (catY < 0) ? -1 : 1;

	//float overlapx = sumHalfWidth - catX;
	//float overlapy = sumHalfHeight - catY;

	//if (overlapx >= overlapy)
	//{
	//	//if (catY > 0)//por cima do objeto controlado
	//	//{
	//	//	GetPosition()->SetY(GetYPosition() + overlapy);
	//	//}
	//	//else // por baixo
	//	//{
	//	//	GetPosition()->SetY(GetYPosition() - overlapy);
	//	//}

	//}
	//else//colisão por esquerda ou direita
	//{
	//	if (catX > 0)//esquerda do objeto controlado
	//	{
	//		GetPosition()->SetX(GetXPosition() + overlapx);
	//	}
	//	else//direita
	//	{
	//		GetPosition()->SetX(GetXPosition() - overlapx);
	//	}
	//}

	/*if (GetYPosition() + GetImage()->GetHeight() >= p_tile->GetY())
	{
		GetPosition()->SetY(p_tile->GetY() - GetImage()->GetHeight());
	}


	if (GetXPosition() <= p_tile->GetX() + p_tile->GetImage()->GetWidth())
	{
		GetPosition()->SetX(p_tile->GetX() + p_tile->GetImage()->GetWidth());
	}
	else if (GetXPosition() + GetImage()->GetWidth() >= p_tile->GetX())
	{
		GetPosition()->SetX(p_tile->GetX() - GetImage()->GetWidth());
	}*/
	
	*m_transform->GetPosition() -= *m_transform->GetVelocity();
	m_transform->GetVelocity()->SetY(0);
	m_transform->GetVelocity()->SetX(0);
	m_count = 0;
}

void Hero::Initialize()
{
	m_transform->SetStatic(false);
	m_transform->SetCollider(new Box(GetPosition(), 41, 44));
	m_transform->GetVelocity()->SetX(0);
}

void Hero::UpDate()
{
	*m_transform->GetVelocity() += *Physic::GetGravity();

	if (m_moveLeft)
	{
		m_transform->GetVelocity()->SetX(-5);
	}
	if (m_moveRight)
	{
		m_transform->GetVelocity()->SetX(5);
	}
	if (m_jump)
	{
		if (m_count < 2)
		{
			m_count++;
			*m_transform->GetVelocity() -= *m_transform->GetUp() * 15;
		}
		m_jump = false;
	}
	
	*GetPosition() += *m_transform->GetVelocity();

	if (GetPosition()->GetX() <= 0)
		GetPosition()->SetX(0);
	else if (GetPosition()->GetX() + GetWidth() >= m_camera->GetxPosition() + m_camera->GetWidth())
	{
		GetPosition()->SetX((m_camera->GetxPosition() + m_camera->GetWidth()) - GetWidth());
	}

	m_transform->GetVelocity()->SetX(0);
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
