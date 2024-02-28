#include "BG.h"
#include "Object.h"
#include "Game_Specs.h"

//Constructor ��� background ��� ��� ������� �� ���������� ����,������ ��� ��� ������� ��������,�������� ���������� ��� Object.
BG::BG() : Object(500, 250, 0, CAMVA_WIDTH, CAMVA_HEIGHT) //��� ��� ����� ������� �� background ��� Game ���� ���������� ��� ����� ���.
{
	vourtsa.texture = "assets\\background2.png";

}


void BG::update()
{

}


void BG :: draw()
{
	graphics::drawText(460,50, 20, "F10=PAUSE", vourtsa);
	graphics::drawRect(x, y, width, height, vourtsa);
}

