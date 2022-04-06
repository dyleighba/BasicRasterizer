//
// Created by dylan on 6/04/2022.
//

#include "InputPrimitive.h"

Geometry InputPrimitive::generateCube() {
    float3 v[]{
        float3{-0.5,  0.5, -0.5},
        float3{ 0.5,  0.5, -0.5},
        float3{-0.5, -0.5, -0.5},
        float3{ 0.5, -0.5, -0.5},
        float3{-0.5,  0.5,  0.5},
        float3{ 0.5,  0.5,  0.5},
        float3{-0.5, -0.5,  0.5},
        float3{ 0.5, -0.5,  0.5},
    };
    Geometry cube = Geometry(12);
    // Back
    cube.setTriangle(0, Triangle3D{v[0], v[1], v[2]});
    cube.setTriangle(1, Triangle3D{v[1], v[3], v[2]});
    // Front
    cube.setTriangle(2, Triangle3D{v[5], v[6], v[7]});
    cube.setTriangle(3, Triangle3D{v[5], v[4], v[6]});
    // Left
    cube.setTriangle(4, Triangle3D{v[4], v[0], v[6]});
    cube.setTriangle(5, Triangle3D{v[0], v[2], v[6]});
    // Right
    cube.setTriangle(6, Triangle3D{v[1], v[5], v[3]});
    cube.setTriangle(7, Triangle3D{v[5], v[7], v[3]});
    // Up
    cube.setTriangle(8, Triangle3D{v[4], v[5], v[0]});
    cube.setTriangle(9, Triangle3D{v[5], v[1], v[0]});
    // Down
    cube.setTriangle(10, Triangle3D{v[6], v[3], v[7]});
    cube.setTriangle(11, Triangle3D{v[6], v[2], v[3]});

    for (int i = 0; i < 6; ++i) {
        int index = 6*2;
        auto intensity = static_cast<uint8_t>(std::floor((255.f/6.f)*static_cast<float>(i)));
        cube.setTriangleColour(index, Colour{intensity,intensity,intensity});
        cube.setTriangleColour(index+1, Colour{intensity,intensity,intensity});
    }
    return cube;
}



