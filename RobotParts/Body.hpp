#pragma once
#include "../Src/Primitives.hpp"

class Body
{
public:
    Body();
    ~Body();


    Primitives* bodyQuad;
    void createBody(float);

};

