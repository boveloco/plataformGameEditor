#pragma once

class Vector2D;

class Camera2
{
private:
	Vector2D *m_position;
	int m_width;
	int m_height;

public:
	//seta a posição, largura e altura
	Camera2(Vector2D *, int, int);
	Camera2();
	~Camera2();

	int GetWidth() const;
	int GetHeight() const;
	Vector2D *GetPosition() const;
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

