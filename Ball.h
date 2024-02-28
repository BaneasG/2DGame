#pragma once


#include "Object.h"
#include "PlayerObj.h"
#include "Game_Specs.h"




using namespace std;


class PlayerObj;



//Δημιουργία του Object Ball.
class Ball : public Object  //Η κλάση κληρονομεί την Object.
{
	
	

	float ball_speed;
	

public:
	
	float forceX;
	float forceY;
	
	
	//Constructor της Ball.
	Ball(float x, float y, float rad, float wid, float hei) 
		:Object(x, y, rad, wid, hei)
	{
		//Αρχικοποιώ τα δεδομένα της Ball.

		

		ball_speed = 1.5f;
		
		forceX = 1.5f;
		forceY = 1.5f;

		
		

		

		if (rand() % 2 == 0) //Με την μέθοδο rand δίνω τυχαίες τιμές στις δυνάμεις της μπάλας μου.
			forceX = -1.0f;

		if (rand() % 2 == 0)
			forceY = -1.0f;
		

		vourtsa.texture = "assets\\ball.png"; //Μονοπάτι του εικονιδίου της μπάλας.
		vourtsa.fill_opacity = 1; 
		vourtsa.outline_opacity = 0;
		

	}

	
	
	
	
	
	//Υποχρεωτικά υπερκαλύπτω τις update και draw διότι είναι Pure virtual στην κλάση Object.!
	
	
	
	void draw()
	{
		graphics::drawRect(x, y, width, height, vourtsa);

		
	}

	void update()
	{
		x = x + forceX; //Αυξάνει κάθε φορά στην οθόνη μας το κέντρο x,y της μπάλας κατά την δύναμη που του έχουμε δώσει και έτσι κινείται η μπάλα.
		y = y + forceY;



		if (y + radius > 500 || y - radius < 0) // Εάν η μπάλα βρεί στην πάνω ή στην κάτω πλευρά του καμβά.
		{
			graphics::playSound("assets\\ballsound.wav", 1.0f, false);
			forceY = -forceY;//Αλλάζει κατεύθυνση στην μπαλα ως προς την ανάποδη φορά της.
		}

		if (x<0 || x > CAMVA_WIDTH ) //Αν η μπάλα βρεί στις 2 κάθετες πλευρές του καμβά μας,είναι γκολ.

		{
			graphics::playSound("assets\\goal.wav", 0.2f, false);

			//Την επαναφέρω στο κέντρο του καμβά.
			x = forceX = 500; 
			y = forceY = 250;

			//Την κρατάω στο κέντρο εφόσον οι δυνάμεις της είναι 0.Δλδ δεν κινείται.
			forceX = 0;
			forceY = 0;
			
			
			
        }
		
		
			
		

		
		

		
		//KEY για να ξεκινήσει η μπάλα μετά από γκόλ.
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
	
	
	
	
	//Δηλώνω μια μέθοδο collision τύπου bool που έχει σαν όρισμα μια μεταβλητή obj η οποία είναι reference στον PlayerObj.
	bool collision(class PlayerObj& obj)
	{
		//Ορίζω τα min max των πλευρών του PlayerObj και σύμφωνα με αυτά κοιτάω εάν η μπάλα θα χτυπήσει τον παίκτη.

		float minX = obj.getX() - obj.getWidth() / 2;
		float minY = obj.getY() - obj.getHeight() / 2;

		float maxX = obj.getX() + obj.getWidth() / 2;
		float maxY = obj.getY() + obj.getHeight() / 2;

		bool coll = (x > minX && x < maxX && y > minY && y < maxY); //Το κέντρο x,y της μπάλας ακουμπάει τα όρια που έχω θέσει παραπάνω για τις πλευρές του παίκτη μου.


		if (coll == true) //Εάν ακουμπήσει τον παίκτη.
		{
			graphics::playSound("assets\\hit1.wav", 1.0f, false);
			forceX = -forceX;
		}
		
			
		
		

		return coll;
	}


	//Δήλωσει setter και getter για να μπορέσω να πάρω τις δυνάμεις της μπάλας οποιαδήποτε στιγμή σε άλλη κλάση.

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



