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

void DrawUtility::drawTriangle(Frame &frame, Triangle triangle, Colour colour) {
    float2 minVec = linalg::max(
            linalg::min(linalg::min(triangle.a, triangle.b), triangle.c),
            float2{0,0});
    float2 maxVec = linalg::min(
            linalg::max(linalg::max(triangle.a, triangle.b), triangle.c),
            float2{static_cast<float>(frame.getWidth()),static_cast<float>(frame.getHeight())});

    for (int x = minVec.x; x < maxVec.x; ++x) {
        for (int y = minVec.y; y < maxVec.y; ++y) {
            if (pointInsideTriangle(triangle, float2{(float) x, (float) y})) {
                frame.setPixel(x, y, colour);
            }
        }
    }
}

DrawUtility::DrawUtility() {}
