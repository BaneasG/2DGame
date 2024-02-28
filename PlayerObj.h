#pragma once

#include "Object.h"
#include "Ball.h"
#include "Game_Specs.h"


class Ball;

//Constructor παίκτη.
class PlayerObj : public Object //Κληρονομεί την Object.
{

	int player; //Δήλωση του παίκτη για να τους ξεχωρίζω.(1 ή 2).

	float min_x, min_y, max_x, max_y;
	

	

public:

	PlayerObj(float x, float y, float rad, float wid, float hei, int player)
		: Object(x, y, rad, wid, hei)
	{
		this->player = player; //Δείκτης που δείχνει στην ίδια την μεταβλητή για αποφυγή σύγκρουσης.

		

		vourtsa.texture = "assets\\player.png"; //Δίνω εικόνα στην μπάλα.
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


			//Ορισμός keys για να ανεβοκατεβάζω τον παίκτη στο Game.

			if (graphics::getKeyState(graphics::SCANCODE_E))
			{
				y--;
			}
			else if (graphics::getKeyState(graphics::SCANCODE_D))
			{
				y++;
			}
			
			// Statement για να μην φύγει ο παίκτης πάνω ή κάτω απο την οθόνη.(εκτός ορίων δλδ)
			if (y + height / 2 >= 500) 
				y = 500 - height / 2;
			else if (y - height / 2 <= 0)
				y = height / 2;
		}
		else //τα κουμπιά του 2ου παίκτη.
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