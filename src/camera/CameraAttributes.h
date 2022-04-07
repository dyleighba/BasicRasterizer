//
// Created by dylan on 7/04/2022.
//

#ifndef BASICRASTERIZER_CAMERAATTRIBUTES_H
#define BASICRASTERIZER_CAMERAATTRIBUTES_H

#include <linalg.h>

using linalg::aliases::float3;
using linalg::aliases::float4;
using linalg::aliases::float4x4;

struct CameraAttributes {
    float3 position; // Position in world coordinates
    float4 rotation; // Quaternion
    float fov;
    float nearCulling;
    float farCulling;
};
#endif //BASICRASTERIZER_CAMERAATTRIBUTES_H
