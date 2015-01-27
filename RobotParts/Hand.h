#pragma once
#include "../Src/Primitives.hpp"
class Hand
{
public:
    Hand();
    ~Hand();

    Primitives* hand;
    bool doOpenHand;

    
    void createHand(float radius, float height, float angle);
};

