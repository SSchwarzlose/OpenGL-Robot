#include "Body.hpp"


Body::Body()
{
}


Body::~Body()
{
}

void Body::createBody(float width)
{
    bodyQuad->drawRectangle(width, width);
}