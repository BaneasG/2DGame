#pragma once
#include "Object.h"
#include "Menu.h"
#include "Score.h"





class Menu2 :public Object
{

	Menu1& menu;
	

public:


	bool visible2;
	int pos;

	Menu2(int x, int y, int wid, int hei,Menu1 &m);

	void draw();
	void update();
	
	void setVisible2(bool v);
	bool getVisible2();
	
	
	int getPosition();
	
};



