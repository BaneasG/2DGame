#include "Object.h"
#include "Game_Specs.h"


//Constructor ��� Object
Object::Object(float x, float y, float rad, float wid, float hei)
{
	//������������ ��� ��������� ��� Object ��� �� ��������������� �� ���������� ����������� �����������.
	this->x = x;
	this->y = y;
	radius = rad;
	width = wid;
	height = hei;
}

//Distructor
Object::~Object()
{

}

float Object::getX()
{
	return x;
}

float Object::getY()
{
	return y;
}

float Object::getHeight()
{
	return height;
}

float Object::getWidth()
{
	return width;

}




