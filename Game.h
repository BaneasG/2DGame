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




//Όλες οι ρυμθίσεις του game Και τα αντικείμενα που εισάγω.
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
	

	//Δήλωση ενός vector ενός vectοr όπου μπορώ να προσθαφαιρώ τα στοιχεία μου που ως template έχουν Pointer τύπου Object. 
	vector< Object* > objects;

	//Δηλώσεις pointers διαφόρων τύπου για να μπορώ να έχω προσβαση στις μεθόδους που έχω δημιουργήσει στην εκάστοτε κλάση.Πολυμορφισμός.
	Menu1* main_menu;
	Menu2* second_menu;
	Ball* ball;
	
	
	
	
	
	//Constructor της Game όπου θα εισάγω όλα τα αντικείμενα.
	Game()
	{
		//Εισάγω αντικείμενα μέσα στο vector μέσω της push_back.

		ball = new Ball(width_camva / 2, height_camva / 2, 18, 36, 36);
		
		

		objects.push_back(new BG());
		objects.push_back(ball);
		objects.push_back(new Score(435, 30, 30, *ball));
		objects.push_back(new PlayerObj(25,height_camva/2,15,90,90,1));
		objects.push_back(new PlayerObj(width_camva-25, height_camva / 2, 15, 90, 90,2));
		
		

		main_menu = new Menu1(435,200 ,530, 400,*ball);

		second_menu = new Menu2(435, 200, 530,400,*main_menu);

		

		main_menu->setVisible(true); //To κάνω true έτσι ώστε όταν ξεκινήσει το game να είναι το πρώτο που θα ζωγραφίσει.

		second_menu->setVisible2(false);

		
		
		
		
	}

	
	//Χρωματίζει όλα τα αντικείμενα του Game.
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
		else //εάν δεν είμαστε στις περιπτώσεις όπου χρειάζεται να εμφανίσουμε ενα menu
		{
			//Ζωγραφίζουμε ολα τα αντικείμενα του Game.
			for (int i = 0; i < objects.size(); i++)
			{


				objects[i]->draw();
			}

		}



	}
		
		
			
		
			
			
		

		
	


	//Κάνει Update όλα τα αντικείμενα του Game.
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
		else //Εάν δεν είμαστε στις περιπτώσεις οπού χρειάζεται να γίνει update στα menu Μας
		{

			//Για κάθε ένα αντικείμενο που εισάγω .
			for (int i = 0; i < objects.size(); i++)
			{
				for (int j = i + 1; j < objects.size(); j++)
				{
					// Με dynamic cast κάνω έλεγχο της ιεραρχίας.Εάν δεν είναι λαθος δλδ !=0.Επίσης διακόπτεται και ο πολυμορφισμός.
					Ball* b = dynamic_cast<Ball*>(objects[i]);
					PlayerObj* r = dynamic_cast<PlayerObj*>(objects[j]);

					if (b != nullptr && r != nullptr)
					{
						b->collision(*r); //Κάνει collision την μπάλα με τον παίκτη.
					}


				}
			}




			//Το auto αναγνωρίζει τον τύπο που έχει το vector και για κάθε obj του Objects,το Obj παίρνει τιμή σε κάθε επανάληψη απο το περιεχόμενο του πίνακα.
			for (auto obj : objects)
			{
				obj->update();
			}
		}

		//Ένα key statement έτσι ώστε άν πατήσεις το F10 το Game Να κάνει Pause Και να εμφανίζεται το Menu2. 
		if (graphics::getKeyState(graphics::SCANCODE_F10))
		{
			second_menu->setVisible2(true);
			
		}

			

	}
		
	

	//Καταστροφέας της Game.
	~Game()
	{
		for (int i = 0; i < objects.size(); i++)

			delete objects[i];


		delete main_menu;
		delete second_menu;
	}

	


	


};



