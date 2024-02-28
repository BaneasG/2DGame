#pragma once
#include "Object.h"
#include "Ball.h"
#include "Score.h"





class Menu1:public Object
{

	
	Ball& kappa; //Δηλώνω μια μεταβλητή kappa τύπου Ball.
	
	
public:

	
	

	float time;

	bool visible;
	int position;

	Menu1(int x, int y,int wid,int hei,Ball&kapp);


	void setVisible(bool v); 
	bool getVisible();
	void draw();
	void update();
	int getPos();
	
};

