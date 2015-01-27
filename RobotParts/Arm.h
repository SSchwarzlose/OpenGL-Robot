#pragma once
#include "../Src/Primitives.hpp"

class Arm
{
public:
    Arm();
    ~Arm();

    Primitives* rects;

    void createArm(float width, float height);
};

