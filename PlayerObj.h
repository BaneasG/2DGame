#pragma once

#include "Object.h"
#include "Ball.h"
#include "Game_Specs.h"


class Ball;

//Constructor ������.
class PlayerObj : public Object //���������� ��� Object.
{

	int player; //������ ��� ������ ��� �� ���� ��������.(1 � 2).

	float min_x, min_y, max_x, max_y;
	

	

public:

	PlayerObj(float x, float y, float rad, float wid, float hei, int player)
		: Object(x, y, rad, wid, hei)
	{
		this->player = player; //������� ��� ������� ���� ���� ��� ��������� ��� ������� ����������.

		

		vourtsa.texture = "assets\\player.png"; //���� ������ ���� �����.
		vourtsa.outline_opacity = 0;
	}

	void draw()
	{
		graphics::drawRect(x, y, width, height, vourtsa);
	}


	void update()
	{
		if (player == 1)
		{


			//������� keys ��� �� ������������� ��� ������ ��� Game.

			if (graphics::getKeyState(graphics::SCANCODE_E))
			{
				y--;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_D))
			{
				y++;
			}
			
			// Statement ��� �� ��� ����� � ������� ���� � ���� ��� ��� �����.(����� ����� ���)
			if (y + height / 2 >= 500) 
				y = 500 - height / 2;
			else if (y - height / 2 <= 0)
				y = height / 2;
		}
		else //�� ������� ��� 2�� ������.
		{
			if (graphics::getKeyState(graphics::SCANCODE_UP))
			{
				y--;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_DOWN))
			{
				y++;
			}

			
			if (y + height / 2 >= 500)
				y = 500 - height / 2;
			else if (y - height / 2 <= 0)
				y = height / 2;
		}
	}



};