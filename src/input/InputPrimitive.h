//
// Created by dylan on 6/04/2022.
//

#ifndef BASICRASTERIZER_INPUTPRIMITIVE_H
#define BASICRASTERIZER_INPUTPRIMITIVE_H


#include <input/Input.h>
#include <geometry/Geometry.h>
#include <linalg.h>

class InputPrimitive: Input {
public:
    static Geometry generateCube();
};


#endif //BASICRASTERIZER_INPUTPRIMITIVE_H
