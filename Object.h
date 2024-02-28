#pragma once

#include "graphics.h"



class Object
{
protected:

	float width, height; //Πλάτος και ύψος για κάθε αντικείμενο.
	
	float radius; //Ακτίνα όπου χρειάζεται.
	
	float x,y; //Κέντρο x,y ως προς τον καμβά μου.
	 
	

	

	graphics::Brush vourtsa; //H βούρτσα που θα χρησιμποιώ σε όλες τις υποκλάσεις μου.

public:

	Object(const float x, const float y, const float rad, const float wid, const float hei); 

	//Ανγκάζω τις υποκλάσεις να έχουν την draw και την update.Χρησιμοποιώ virtual(εικονική) για να μπορώ κάθε φορά στα υπόλοιπα αντικείμενα μου να καλούν την υπερκαλυμένη συνάρτηση.
	virtual void update() = 0;
	virtual void draw() = 0;
	
	//getters για να μπορω κάθε στιγμή να παίρνω τα x,y,width και height των αντικειμένων και να τα επξεργάζομαι.
	float getX();

	float getY();

	float getHeight();

	float getWidth();


	virtual ~Object(); //Distructor της κλάσης Object.
};





