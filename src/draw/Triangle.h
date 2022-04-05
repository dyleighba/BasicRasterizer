//
// Created by dylan on 5/04/2022.
//

#ifndef BASICRASTERIZER_TRIANGLE_H
#define BASICRASTERIZER_TRIANGLE_H

#include <draw/Colour.h>

#include <linalg.h>

using linalg::aliases::float2;

struct Triangle {
    float2 a;
    float2 b;
    float2 c;
    Colour aColour = red;
    Colour bColour = green;
    Colour cColour = blue;
};

#endif //BASICRASTERIZER_TRIANGLE_H
