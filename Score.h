#pragma once

#include "Object.h"
#include "Ball.h"





class Score : public Object
{
	int k;
	int l;
	Ball& otherBall; //Δήλωση μιας μεταβλητής otherball που είναι reference στην κλάση Ball.
	


public:

	
	
	
	Score(float x, float y, float hei,Ball &mp); 

	
	
	
	//Setter και getter για να παίρων κάθε στιγμή το score.
	int getK();
	int getL();

	void setK(int k);
	void setL(int l);

	void update();
	void draw();
	

};

