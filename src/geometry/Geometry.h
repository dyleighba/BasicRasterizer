//
// Created by dylan on 5/04/2022.
//

#ifndef BASICRASTERIZER_GEOMETRY_H
#define BASICRASTERIZER_GEOMETRY_H

#include <geometry/Triangle3D.h>
#include <draw/Colour.h>
#include <linalg.h>



using linalg::aliases::float3;

class Geometry {
    int triangleAmount;
    float3 *triangles;
    Colour *colours;
public:
    explicit Geometry(int triangleAmount);
    ~Geometry();
    void setTriangle(int index, Triangle3D triangle);
    Triangle3D getTriangle(int index);
    void setTriangleColour(int index, Colour colour);
    Colour getTriangleColour(int index);
};


#endif //BASICRASTERIZER_GEOMETRY_H
