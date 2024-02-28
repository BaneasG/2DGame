#pragma once


#include "Object.h"
#include "PlayerObj.h"
#include "Game_Specs.h"




using namespace std;


class PlayerObj;



//���������� ��� Object Ball.
class Ball : public Object  //� ����� ���������� ��� Object.
{
	
	

	float ball_speed;
	

public:
	
	float forceX;
	float forceY;
	
	
	//Constructor ��� Ball.
	Ball(float x, float y, float rad, float wid, float hei) 
		:Object(x, y, rad, wid, hei)
	{
		//���������� �� �������� ��� Ball.

		

		ball_speed = 1.5f;
		
		forceX = 1.5f;
		forceY = 1.5f;

		
		

		

		if (rand() % 2 == 0) //�� ��� ������ rand ���� ������� ����� ���� �������� ��� ������ ���.
			forceX = -1.0f;

		if (rand() % 2 == 0)
			forceY = -1.0f;
		

		vourtsa.texture = "assets\\ball.png"; //�������� ��� ���������� ��� ������.
		vourtsa.fill_opacity = 1; 
		vourtsa.outline_opacity = 0;
		

	}

	
	
	
	
	
	//����������� ����������� ��� update ��� draw ����� ����� Pure virtual ���� ����� Object.!
	
	
	
	void draw()
	{
		graphics::drawRect(x, y, width, height, vourtsa);

		
	}

	void update()
	{
		x = x + forceX; //������� ���� ���� ���� ����� ��� �� ������ x,y ��� ������ ���� ��� ������ ��� ��� ������ ����� ��� ���� �������� � �����.
		y = y + forceY;



		if (y + radius > 500 || y - radius < 0) // ��� � ����� ���� ���� ���� � ���� ���� ������ ��� �����.
		{
			graphics::playSound("assets\\ballsound.wav", 1.0f, false);
			forceY = -forceY;//������� ���������� ���� ����� �� ���� ��� ������� ���� ���.
		}

		if (x<0 || x > CAMVA_WIDTH ) //�� � ����� ���� ���� 2 ������� ������� ��� ����� ���,����� ����.

		{
			graphics::playSound("assets\\goal.wav", 0.2f, false);

			//��� ��������� ��� ������ ��� �����.
			x = forceX = 500; 
			y = forceY = 250;

			//��� ������ ��� ������ ������ �� �������� ��� ����� 0.��� ��� ��������.
			forceX = 0;
			forceY = 0;
			
			
			
        }
		
		
			
		

		
		

		
		//KEY ��� �� ��������� � ����� ���� ��� ����.
		if (graphics::getKeyState(graphics::SCANCODE_SPACE))
		{
			forceX = ball_speed;
			forceY = ball_speed;


			

			if (rand() % 2 == 0)
				forceX = -ball_speed;

			if (rand() % 2 == 0)
				forceY = -ball_speed;
		}

		


		
			
	}
	
	
	
	
	//������ ��� ������ collision ����� bool ��� ���� ��� ������ ��� ��������� obj � ����� ����� reference ���� PlayerObj.
	bool collision(class PlayerObj& obj)
	{
		//����� �� min max ��� ������� ��� PlayerObj ��� ������� �� ���� ������ ��� � ����� �� �������� ��� ������.

		float minX = obj.getX() - obj.getWidth() / 2;
		float minY = obj.getY() - obj.getHeight() / 2;

		float maxX = obj.getX() + obj.getWidth() / 2;
		float maxY = obj.getY() + obj.getHeight() / 2;

		bool coll = (x > minX && x < maxX && y > minY && y < maxY); //�� ������ x,y ��� ������ ��������� �� ���� ��� ��� ����� �������� ��� ��� ������� ��� ������ ���.


		if (coll == true) //��� ���������� ��� ������.
		{
			graphics::playSound("assets\\hit1.wav", 1.0f, false);
			forceX = -forceX;
		}
		
			
		
		

		return coll;
	}


	//������� setter ��� getter ��� �� ������� �� ���� ��� �������� ��� ������ ����������� ������ �� ���� �����.

	float getDunamiX()
	{
		return forceX;
	}

	float getDunamiY()
	{
		return forceY;
	}

	void setDunamiX(float forceX)
	{
		
		this->forceX = forceX;
		ball_speed = forceX;
	}

	void setDunamiY(float forceY)
	{
		this->forceY = forceY;
		
	}

};



