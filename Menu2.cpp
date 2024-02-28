#include "Menu2.h"


Menu2::Menu2(int x, int y, int wid, int hei,Menu1 & m) : Object(x, y, 0, wid, hei),menu(m)
{

	pos = 1;

	vourtsa.fill_color[0] = 0.5;
	vourtsa.fill_color[1] = 0.5;
	vourtsa.fill_color[2] = 0.5;
	vourtsa.fill_opacity = 0.5;

	visible2 = false;
	
}




void Menu2::draw()
{
	graphics::drawText(730, 450, 20, "F1=RESUME", vourtsa);
	graphics::drawText(830, 450, 20, "F2=MAIN MENU", vourtsa);
	


	vourtsa.fill_color[0] = 1.0;
	vourtsa.fill_color[1] = 0.9;
	vourtsa.fill_color[2] = 0.7;
	
	graphics::drawRect(480, 250, width - 250, height - 150, vourtsa);

	
	vourtsa.fill_color[0] = 0.5;
	vourtsa.fill_color[1] = 0.5;
	vourtsa.fill_color[2] = 0.5;


	if (pos == 1)
	{
		vourtsa.fill_opacity = 1;

	}
	graphics::drawText(x, y, 30, "RESUME", vourtsa);
	vourtsa.fill_opacity = 0.5;



	if (pos == 2)
	{
		vourtsa.fill_opacity = 1;

	}
	graphics::drawText(x, y + 60, 30, "MAIN MENU", vourtsa);
	vourtsa.fill_opacity = 0.5;



	
	

}





void Menu2::update()
{

	 if (graphics::getKeyState(graphics::SCANCODE_UP))
		pos--;
	else if (graphics::getKeyState(graphics::SCANCODE_DOWN))
		pos++;

	if (pos < 1)
		pos = 1;
	else if (pos >= 3)
		pos = 2;
	
	
	if (pos==1)
		
	{
		if (graphics::getKeyState(graphics::SCANCODE_F1))  // ��� �������� �� F1 ���� �� menu ������� unvisible ��� ����������� �� ��������.
		
		visible2 = false;
	}
	else
	{
		if (graphics::getKeyState(graphics::SCANCODE_F2)) //��� �������� �� F2  
		{
			
			visible2 = false; //���� �� menu2 ������� Unvisible
			menu.setVisible(true);//��� �� menu ������� visible. ��� ��������� �� ������ ��� ���� ��� ���� ��� set ��� ����� ��� menu.h.

		}
			

	}

	
}

int Menu2::getPosition()
{
	return pos;
}

bool Menu2::getVisible2()
{
	return visible2;
}

void Menu2::setVisible2(bool v)
{
	visible2 = v;
}



