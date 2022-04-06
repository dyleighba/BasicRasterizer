//
// Created by dylan on 5/04/2022.
//

#ifndef BASICRASTERIZER_TRIANGLE_H
#define BASICRASTERIZER_TRIANGLE_H

#include <linalg.h>

using linalg::aliases::float2;

struct Triangle {
    float2 a;
    float2 b;
    float2 c;
};

#endif //BASICRASTERIZER_TRIANGLE_H
