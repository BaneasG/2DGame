#include "Score.h"
#include "PlayerObj.h"

#include <string>





using namespace std;






//Constructor του score.
Score::Score(float x, float y, float hei,Ball &m)
    :Object(x, y, 0, 0, hei),otherBall(m) //Αρχικοποιώ και την Other ball βάση του κανόνα της λίστας αρχικοποίησης.Μηδένισα την rad Και την wid γιατί δεν μου χρειάζονται εφόσον το μέγεθος του score κανονίζεται πιο κάτω στην drawText.
{

    k = 0;//Μηδενίζω το score για αρχή.
    l = 0;

	
	vourtsa.fill_color[0] = 0.038;
	vourtsa.fill_color[1] = 0.95;
	vourtsa.fill_color[2] = 0.45;
	
	
	vourtsa.fill_opacity = 1;

}

void Score::update()
{
	//Εάν η μπάλα ακουμπήσει τις 2 κάθετες γραμμές του καμβά.
	if (otherBall.getX() <= 1)
	{
		l++;//Αυξησε το σκορ κατα ένα.(γκόλ για τον δεξιά παίκτη).
		
	}
	else if (otherBall.getX() >= 999 )
	{
		k++; //Αυξησε το σκορ κατα ένα.(γκόλ για τον αριστερά παίκτη).
		
	}





}

void Score::draw()
{
	//Δημιουργώ το σκορ σαν txt και ύστερα το ζωγραφίζω.
	string txt = to_string(k)+": "+" " +"Score"+ " "+":" + to_string(l);
	graphics::drawText(x, y, height, txt, vourtsa);
	
	
}



//Οι setter και getter που κάθε φορά μου δίνου το score.
int Score::getK()
{
	return k;
}

void Score::setK(int k)
{
	this->k = k;
}

int Score::getL()
{
	return l;
}


void Score::setL(int l)
{
	this->l = l;
}


















