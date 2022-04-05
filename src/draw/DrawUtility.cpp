//
// Created by dylan on 5/04/2022.
//

#include "DrawUtility.h"

bool DrawUtility::pointInsideTriangle(Triangle triangle, float2 point)
{
    float2 vecAB = triangle.b - triangle.a;
    float2 vecBC = triangle.c - triangle.b;
    float2 vecCA = triangle.a - triangle.c;

    float2 vecAP = point - triangle.a;
    float2 vecBP = point - triangle.b;
    float2 vecCP = point - triangle.c;

    bool dot1 = linalg::cross(vecAB, vecAP) > 0;
    bool dot2 = linalg::cross(vecBC, vecBP) > 0;
    bool dot3 = linalg::cross(vecCA, vecCP) > 0;

    return !(dot1 | dot2 | dot3);
}

void DrawUtility::drawTriangle(Frame &frame, Triangle triangle) {
    for (int x = 0; x < frame.getWidth(); ++x) {
        for (int y = 0; y < frame.getHeight(); ++y) {
            if (pointInsideTriangle(triangle, float2{(float)x, (float)y})) {
                frame.setPixel(x, y, linalg::vec<int,3>{0,0,255});
            }
        }
    }
}

DrawUtility::DrawUtility() {}
