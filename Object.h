#pragma once

#include "graphics.h"



class Object
{
protected:

	float width, height; //������ ��� ���� ��� ���� �����������.
	
	float radius; //������ ���� ����������.
	
	float x,y; //������ x,y �� ���� ��� ����� ���.
	 
	

	

	graphics::Brush vourtsa; //H ������� ��� �� ���������� �� ���� ��� ���������� ���.

public:

	Object(const float x, const float y, const float rad, const float wid, const float hei); 

	//������� ��� ���������� �� ����� ��� draw ��� ��� update.����������� virtual(��������) ��� �� ����� ���� ���� ��� �������� ����������� ��� �� ������ ��� ������������ ���������.
	virtual void update() = 0;
	virtual void draw() = 0;
	
	//getters ��� �� ����� ���� ������ �� ������ �� x,y,width ��� height ��� ������������ ��� �� �� ������������.
	float getX();

	float getY();

	float getHeight();

	float getWidth();


	virtual ~Object(); //Distructor ��� ������ Object.
};





