//
// Created by dylan on 5/04/2022.
//

#include "Geometry.h"

Geometry::Geometry(int triangleAmount) {
    this->triangleAmount = triangleAmount;
    triangles = new float3[triangleAmount*3];
    colours = new Colour[triangleAmount];
}

Geometry::~Geometry() {
    delete(triangles);
    delete(colours);
}

void Geometry::setTriangle(int index, Triangle3D triangle) {
    int realIndex = index * 3;
    triangles[realIndex] = triangle.a;
    triangles[realIndex+1] = triangle.b;
    triangles[realIndex+2] = triangle.c;
}

Triangle3D Geometry::getTriangle(int index) {
    int realIndex = index * 3;
    return Triangle3D{
        triangles[realIndex],
        triangles[realIndex+1],
        triangles[realIndex+2]
    };
}

void Geometry::setTriangleColour(int index, Colour colour) {
    colours[index] = colour;
}

Colour Geometry::getTriangleColour(int index) {
    return colours[index];
}
