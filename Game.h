#pragma once
#include <string>
#include <vector>
#include "Object.h"
#include "graphics.h"
#include "Score.h"
#include "Ball.h"
#include "PlayerObj.h"
#include "Game_Specs.h"
#include "BG.h"
#include "Menu.h"
#include "Menu2.h"


using namespace std;




//���� �� ��������� ��� game ��� �� ����������� ��� ������.
class Game
{
public:
	
	//Window Settings
	int width_window = WIDTH_WINDOW;
	int	height_window = HEIGHT_WINSOW;
	
	string NameofGame = NAMEOFGAME;

	
	//Camva Settings
	float width_camva = CAMVA_WIDTH;
	int height_camva = CAMVA_HEIGHT;

	graphics::Brush br;

	string font_window = "assets\\alien.ttf";
	

	//������ ���� vector ���� vect�r ���� ����� �� ����������� �� �������� ��� ��� �� template ����� Pointer ����� Object. 
	vector< Object* > objects;

	//�������� pointers �������� ����� ��� �� ����� �� ��� �������� ���� �������� ��� ��� ������������ ���� �������� �����.�������������.
	Menu1* main_menu;
	Menu2* second_menu;
	Ball* ball;
	
	
	
	
	
	//Constructor ��� Game ���� �� ������ ��� �� �����������.
	Game()
	{
		//������ ����������� ���� ��� vector ���� ��� push_back.

		ball = new Ball(width_camva / 2, height_camva / 2, 18, 36, 36);
		
		

		objects.push_back(new BG());
		objects.push_back(ball);
		objects.push_back(new Score(435, 30, 30, *ball));
		objects.push_back(new PlayerObj(25,height_camva/2,15,90,90,1));
		objects.push_back(new PlayerObj(width_camva-25, height_camva / 2, 15, 90, 90,2));
		
		

		main_menu = new Menu1(435,200 ,530, 400,*ball);

		second_menu = new Menu2(435, 200, 530,400,*main_menu);

		

		main_menu->setVisible(true); //To ���� true ���� ���� ���� ��������� �� game �� ����� �� ����� ��� �� ����������.

		second_menu->setVisible2(false);

		
		
		
		
	}

	
	//���������� ��� �� ����������� ��� Game.
	void draw()
	{

		if (main_menu->getVisible() == true)
		{
			main_menu->draw();
		}

		else if (second_menu->getVisible2() == true)
		{
			second_menu->draw();
		}
		else //��� ��� ������� ���� ����������� ���� ���������� �� ����������� ��� menu
		{
			//������������ ��� �� ����������� ��� Game.
			for (int i = 0; i < objects.size(); i++)
			{


				objects[i]->draw();
			}

		}



	}
		
		
			
		
			
			
		

		
	


	//����� Update ��� �� ����������� ��� Game.
	void update()
	{


		if (main_menu->getVisible() == true)
		{
			main_menu->update();
		}
		else if (second_menu->getVisible2() == true)
		{
			
			second_menu->update();

		}
		else //��� ��� ������� ���� ����������� ���� ���������� �� ����� update ��� menu ���
		{

			//��� ���� ��� ����������� ��� ������ .
			for (int i = 0; i < objects.size(); i++)
			{
				for (int j = i + 1; j < objects.size(); j++)
				{
					// �� dynamic cast ���� ������ ��� ���������.��� ��� ����� ����� ��� !=0.������ ����������� ��� � �������������.
					Ball* b = dynamic_cast<Ball*>(objects[i]);
					PlayerObj* r = dynamic_cast<PlayerObj*>(objects[j]);

					if (b != nullptr && r != nullptr)
					{
						b->collision(*r); //����� collision ��� ����� �� ��� ������.
					}


				}
			}




			//�� auto ����������� ��� ���� ��� ���� �� vector ��� ��� ���� obj ��� Objects,�� Obj ������� ���� �� ���� ��������� ��� �� ����������� ��� ������.
			for (auto obj : objects)
			{
				obj->update();
			}
		}

		//��� key statement ���� ���� �� �������� �� F10 �� Game �� ����� Pause ��� �� ����������� �� Menu2. 
		if (graphics::getKeyState(graphics::SCANCODE_F10))
		{
			second_menu->setVisible2(true);
			
		}

			

	}
		
	

	//������������ ��� Game.
	~Game()
	{
		for (int i = 0; i < objects.size(); i++)

			delete objects[i];


		delete main_menu;
		delete second_menu;
	}

	


	


};



