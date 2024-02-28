#include "Score.h"
#include "PlayerObj.h"

#include <string>





using namespace std;






//Constructor ��� score.
Score::Score(float x, float y, float hei,Ball &m)
    :Object(x, y, 0, 0, hei),otherBall(m) //���������� ��� ��� Other ball ���� ��� ������ ��� ������ �������������.�������� ��� rad ��� ��� wid ����� ��� ��� ����������� ������ �� ������� ��� score ����������� ��� ���� ���� drawText.
{

    k = 0;//�������� �� score ��� ����.
    l = 0;

	
	vourtsa.fill_color[0] = 0.038;
	vourtsa.fill_color[1] = 0.95;
	vourtsa.fill_color[2] = 0.45;
	
	
	vourtsa.fill_opacity = 1;

}

void Score::update()
{
	//��� � ����� ���������� ��� 2 ������� ������� ��� �����.
	if (otherBall.getX() <= 1)
	{
		l++;//������ �� ���� ���� ���.(���� ��� ��� ����� ������).
		
	}
	else if (otherBall.getX() >= 999 )
	{
		k++; //������ �� ���� ���� ���.(���� ��� ��� �������� ������).
		
	}





}

void Score::draw()
{
	//��������� �� ���� ��� txt ��� ������ �� ���������.
	string txt = to_string(k)+": "+" " +"Score"+ " "+":" + to_string(l);
	graphics::drawText(x, y, height, txt, vourtsa);
	
	
}



//�� setter ��� getter ��� ���� ���� ��� ����� �� score.
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


















