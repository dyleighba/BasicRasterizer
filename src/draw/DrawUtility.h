//
// Created by dylan on 5/04/2022.
//

#ifndef BASICRASTERIZER_DRAWUTILITY_H
#define BASICRASTERIZER_DRAWUTILITY_H

#include <linalg.h>
#include "frame/Frame.h"
#include "Triangle.h"

using linalg::aliases::float2;

class DrawUtility {
    DrawUtility();
    static bool pointInsideTriangle(Triangle triangle, float2 point);
public:
    static void drawTriangle(Frame &frame, Triangle triangle, Colour colour);
};


#endif //BASICRASTERIZER_DRAWUTILITY_H
