#pragma once
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <math.h>

class Primitives
{
public:
    Primitives();
    ~Primitives();

    static const int circleSegments = 360;

    static void drawCircle(float radius);
    static void drawRectangle(float width, float height);
    static void drawHand(float radius, float height, float angle);
};