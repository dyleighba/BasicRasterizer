//
// Created by dylan on 6/04/2022.
//

#ifndef BASICRASTERIZER_TRIANGLE3D_H
#define BASICRASTERIZER_TRIANGLE3D_H

#include <linalg.h>

using linalg::aliases::float3;

struct Triangle3D {
    float3 a;
    float3 b;
    float3 c;
};

#endif //BASICRASTERIZER_TRIANGLE3D_H
