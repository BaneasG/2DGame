#pragma once

#include "Object.h"
#include "Ball.h"





class Score : public Object
{
	int k;
	int l;
	Ball& otherBall; //������ ���� ���������� otherball ��� ����� reference ���� ����� Ball.
	


public:

	
	
	
	Score(float x, float y, float hei,Ball &mp); 

	
	
	
	//Setter ��� getter ��� �� ������ ���� ������ �� score.
	int getK();
	int getL();

	void setK(int k);
	void setL(int l);

	void update();
	void draw();
	

};

