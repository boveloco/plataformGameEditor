#include <iostream>
#include "Camera.h"

Camera::Camera() {}

Camera::Camera(int * pos, int* size)
{
	this->pos = pos;
	this->size = size;
}

Camera::Camera(int x, int y, int sX, int sY)
{
	this->pos[0] = x;
	this->pos[1] = y;
	this->size[0] = sX;
	this->size[1] = sY;
}

Camera::~Camera()
{
	delete this->pos;
	delete this->ofset;
}

int * Camera::getOfset()
{
	return this->ofset;
}

int Camera::getOfset(int indice)
{
	if (indice > 1)
		return NULL;
	
	return this->pos[indice];
}

int * Camera::getPos()
{
	return this->pos;
}

int Camera::getPos(int indice)
{
	if (indice > 1)
		return NULL;
	return this->pos[indice];
}

int * Camera::getSize()
{
	return this->size;
}

int Camera::getSize(int indice)
{
	if (indice > 1)
		return NULL;
	return this->size[indice];
}

void Camera::setOfset(int * offset)
{
	if (offset == nullptr)
		return;
	this->ofset = offset;
}

void Camera::setOfset(int indice, int value)
{
	if (indice > 1)
		return;
	this->ofset[indice] = value;
}

void Camera::setPos(int * pos)
{
	if (pos == nullptr)
		return;
	this->pos = pos;
}

void Camera::setPos(int indice, int value)
{
	if (indice > 1)
		return;
	this->pos[indice] = value;
}

void Camera::setSize(int * size)
{
	if (size == nullptr)
		return;
	this->size = size;
}

void Camera::setSize(int indice, int value)
{
	if (indice > 1)
		return;
	this->size[indice] = value;
}
