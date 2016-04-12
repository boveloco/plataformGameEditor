#pragma once
#include<iostream>
class Vector2D;


enum Indice
{
	CAMERA_X,
	CAMERA_Y
};

class Camera
{
private:
	Vector2D *m_position;
	int m_width;
	int m_height;

public:
	//seta a posição, largura e altura
	Camera(Vector2D *, int, int);
	Camera();
	~Camera();

	int GetWidth() const;
	int GetHeight() const;
	Vector2D *GetPosition() const;
	int getPosition(int) const;
	int GetxPosition() const;
	int GetyPosition() const;

	//seta o limete em que o personagem
	//pode se mover sem atualizar a 
	//camera
	int GetLimitLeft() const;
	int GetLimitRight() const;
	int GetUpperLimit() const;
	int GetInferiorLimit() const;

	void SetWidth(int);
	void SetHeight(int);
	void SetPosition(Vector2D *);
	void SetPosition(int, int);
	void SetxPosition(int);
	void SetyPosition(int);

	void UpDate(int, int);
	void End();
};

