#pragma once

enum Indice
{
	CAMERA_X,
	CAMERA_Y
};

class Camera
{
public:
	//
	Camera();
	//set initial position with an array
	Camera(int*, int*);
	//set initial postion with 2 ints x,y
	Camera(int, int, int, int);
	//deleta os 2 ponteiros
	~Camera();
	
	//get and setters
	//os com (int) retorna um valor especifico, x ou y
	//os sem retornam o ponteiro

	int* getOfset();
	int getOfset(int);
	int* getPos();
	int getPos(int);
	int* getSize();
	int getSize(int);

	//os com (int,int) tem um int indice e um int value
	//dai com o indice voce acessa obj[indice] = value
	void setOfset(int*);
	void setOfset(int, int);
	void setPos(int*);
	void setPos(int, int);
	void setSize(int*);
	void setSize(int, int);

private:
	int* ofset = new int(2);
	int* pos = new int(2);
	int* size = new int(2);
};