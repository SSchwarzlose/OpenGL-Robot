#include "Primitives.hpp"

const float DEG2RAD = 3.141592 / 180;

Primitives::Primitives()
{
}


Primitives::~Primitives()
{
}

void Primitives::drawCircle(float radius)
{
    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad)*radius, sin(degInRad)*radius);
    }

    glEnd();
}

void Primitives::drawRectangle(float width, float height)
{
    glBegin(GL_QUADS);

    glVertex2f(0, 0);
    glVertex2f(width, 0);
    glVertex2f(width, -height);
    glVertex2f(0, -height);

    glEnd();
}

void Primitives::drawHand(float radius, float height, float handAngle)
{
    float angleLeft = 90;
    float angleRight = 90;

    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad)*radius, sin(degInRad)*radius);
    }

    glEnd();

    glTranslatef(0.0, -radius, 0.0f);

    glRotatef(-90, 0, 0, 1);

    glRotatef(handAngle, 0, 0, 1);

    glBegin(GL_TRIANGLES);
    glVertex2f(0, 0);
    glVertex2f(height / 3, height / 3);
    glVertex2f(height, 0);
    glEnd();

    
	glRotatef(handAngle*(-2), 0, 0, 1);

    glBegin(GL_TRIANGLES);
    glVertex2f(height, 0);
    glVertex2f(height / 3, (height * -1) / 3);
    glVertex2f(0, 0);
    glEnd();
}