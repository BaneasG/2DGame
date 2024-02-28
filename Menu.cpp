#include "Menu.h"







Menu1::Menu1(int x, int y, int wid, int hei,Ball&kep) : Object(x, y, 0, wid, hei),kappa(kep)

{
	position = 1; //Αρχικοποίηση μεταβλητής Position για να μπορέσω πιο μετά να ελέγχω τις θέσεις στο μενού μου.
	time = 0;

	vourtsa.fill_color[0] = 0.5;
	vourtsa.fill_color[1] = 0.5;
	vourtsa.fill_color[2] = 0.5;

	vourtsa.fill_opacity = 0.5;

	visible = false; //την θέτω false για αρχή.
	
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
	

	//Ελέγχω κάθε φορά σε ποιά θέση είμαι στο μενού.Ανάλογα με την επιλογή σκιάζω λίγο παραπάνω την επιλογή στην οποία βρίσκομαι.
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
	

	//Ορίζω key για ανεβωκατεβαίνω στις επιλογές μου.
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
	
	
	
	//Statement για να μην ξεφύγω εκτός ορίων.
	if (position < 1)
		position = 1;
	else if (position > 3)
		position = 3;
	
	//Εάν πατήσω enter και αναλόγως το Position Που βρίσκομαι στο μενου,κάνω unvisible το μενού και το game Ξεκινάει.
    if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		

		if (position == 1) //Επιλογή EASY.
		{
			
			visible = false;
			
			kappa.setDunamiX(1.5); //Μέσω των setter Που είχα ορίσει στην Ball μπορώ να έχω πρόσβαση στις δυνάμεις της μπάλας και ανάλογα την επιλογή να ρυθμίζω την ταχύτητα αυτης.
			kappa.setDunamiY(1.5);
			
		    
			
		}
		else if (position == 2) //Επιλογή MEDIUM.
		{ 
			
			visible = false;
			
			kappa.setDunamiX(3.0);
			kappa.setDunamiY(3.0);
			
		}
		else //Επιλογή HARD.
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



