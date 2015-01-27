#include "Hand.h"


Hand::Hand()
{
	doOpenHand = false;
}


Hand::~Hand()
{
}

void Hand::createHand(float radius, float heigth, float handAngle)
{
    hand->drawHand(radius, heigth, handAngle);
}