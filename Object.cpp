#include "Object.h"
#include "Game_Specs.h"


//Constructor της Object
Object::Object(float x, float y, float rad, float wid, float hei)
{
	//Αρχικοποίηση των δεδομένων της Object που θα χρησιμοποιηθούν σε οποιδήποτε αντικείμενο δημιουργήσω.
	this->x = x;
	this->y = y;
	radius = rad;
	width = wid;
	height = hei;
}

//Distructor
Object::~Object()
{

}

float Object::getX()
{
	return x;
}

float Object::getY()
{
	return y;
}

float Object::getHeight()
{
	return height;
}

float Object::getWidth()
{
	return width;

}




