#pragma once
#include "../Src/Primitives.hpp"

class Joint
{
public:
    Joint();
    ~Joint();

    void createJoint(float);

private:
    Primitives* circle;

};

