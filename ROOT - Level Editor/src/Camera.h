#pragma once
#include<iostream>
class Vector2D;
class Map;
class SpriteSet;
class Texture;

enum Indice
{
	CAMERA_X,
	CAMERA_Y
};

class Camera
{
private:
	SpriteSet* spriteSet;
	int limit = 0;
	Vector2D *m_position;
	int m_width;
	int m_height;
	Map* map;
public:
	//seta a posição, largura e altura
	Camera(Vector2D *, int, int, Map*, SpriteSet*);
	Camera();
	~Camera();

	int GetWidth() const;
	int GetHeight() const;
	Vector2D *GetPosition() const;
	int GetPosition(int);
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

	void setMap(Map* map) {
		this->map = map;
	}
	Camera * draw(Texture*);
	void UpDate(int, int);
	void End();
};

