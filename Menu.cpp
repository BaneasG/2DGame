#include "Menu.h"







Menu1::Menu1(int x, int y, int wid, int hei,Ball&kep) : Object(x, y, 0, wid, hei),kappa(kep)

{
	position = 1; //������������ ���������� Position ��� �� ������� ��� ���� �� ������ ��� ������ ��� ����� ���.
	time = 0;

	vourtsa.fill_color[0] = 0.5;
	vourtsa.fill_color[1] = 0.5;
	vourtsa.fill_color[2] = 0.5;

	vourtsa.fill_opacity = 0.5;

	visible = false; //��� ���� false ��� ����.
	
}




void Menu1::draw()
{
	
	graphics::drawRect(470, 250, width - 300, height - 200, vourtsa);


	graphics::drawText(100, 100, 75, "WELCOME TO ALIEN BATTLE!", vourtsa);
	graphics::drawText(400, 370, 20, "PRESS ENTER TO START", vourtsa);

	graphics::drawText(330, 450, 50, "Enjoy the game.", vourtsa);

	vourtsa.fill_color[0] = 0.0;
	vourtsa.fill_color[1] = 0.0;
	vourtsa.fill_color[2] = 0.0;
	

	//������ ���� ���� �� ���� ���� ����� ��� �����.������� �� ��� ������� ������ ���� �������� ��� ������� ���� ����� ���������.
	if (position == 1)
	{
		vourtsa.fill_opacity = 1;

	}
	graphics::drawText(x, y, 30, "EASY", vourtsa);
	vourtsa.fill_opacity = 0.5;

	

	if (position == 2)
	{
		vourtsa.fill_opacity = 1;

	}
	graphics::drawText(x, y + 60, 30, "MEDIUM", vourtsa);
	vourtsa.fill_opacity = 0.5;

	

	if (position == 3)
	{
		vourtsa.fill_opacity = 1;

	}
	graphics::drawText(x, y + 120, 30, "HARD", vourtsa);
	vourtsa.fill_opacity = 0.5;

	

}





void Menu1::update()
{
	float nowtime = graphics::getGlobalTime();
	

	//����� key ��� �������������� ���� �������� ���.
	if ((nowtime - time > 100) && graphics::getKeyState(graphics::SCANCODE_UP))
	{
		position = position - 1;
		time = nowtime;
	}
	else if ((nowtime - time > 100) && graphics::getKeyState(graphics::SCANCODE_DOWN))
	{
		position = position + 1;
		time = nowtime;
	}
	
	
	
	//Statement ��� �� ��� ������ ����� �����.
	if (position < 1)
		position = 1;
	else if (position > 3)
		position = 3;
	
	//��� ������ enter ��� �������� �� Position ��� ��������� ��� �����,���� unvisible �� ����� ��� �� game ��������.
    if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		

		if (position == 1) //������� EASY.
		{
			
			visible = false;
			
			kappa.setDunamiX(1.5); //���� ��� setter ��� ���� ������ ���� Ball ����� �� ��� �������� ���� �������� ��� ������ ��� ������� ��� ������� �� ������� ��� �������� �����.
			kappa.setDunamiY(1.5);
			
		    
			
		}
		else if (position == 2) //������� MEDIUM.
		{ 
			
			visible = false;
			
			kappa.setDunamiX(3.0);
			kappa.setDunamiY(3.0);
			
		}
		else //������� HARD.
		{
			
			visible = false;
			
			kappa.setDunamiX(5.0);
			kappa.setDunamiY(5.0);
		}
	     
		
    }
}



int Menu1::getPos()
{
	return position;
}



bool Menu1::getVisible()
{
	return visible;
}


void Menu1::setVisible(bool vis)
{
	visible = vis;
}



