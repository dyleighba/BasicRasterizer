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
                float2 point = {static_cast<float>(x), static_cast<float>(y)};
                float distanceA = linalg::distance(triangle.a, point);
                float distanceB = linalg::distance(triangle.b, point);
                float distanceC = linalg::distance(triangle.c, point);
                float total = distanceA + distanceB + distanceC;
                distanceA = distanceA / total;
                distanceB = distanceB / total;
                distanceC = distanceC / total;
                Colour colour = {
                        static_cast<uint8_t>((triangle.aColour.r * distanceA) + (triangle.bColour.r * distanceB) + (triangle.cColour.r * distanceC)),
                        static_cast<uint8_t>((triangle.aColour.g * distanceA) + (triangle.bColour.g * distanceB) + (triangle.cColour.g * distanceC)),
                        static_cast<uint8_t>((triangle.aColour.b * distanceA) + (triangle.bColour.b * distanceB) + (triangle.cColour.b * distanceC))};
                frame.setPixel(x, y, colour);
            }
        }
    }
}

DrawUtility::DrawUtility() {}
