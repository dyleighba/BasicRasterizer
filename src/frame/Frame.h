//
// Created by dylan on 5/04/2022.
//

#ifndef BASICRASTERIZER_FRAME_H
#define BASICRASTERIZER_FRAME_H

#include <linalg.h>
#include <draw/Colour.h>

class Frame {
    int width;
    int height;
    uint8_t *pixels;
    float *zBuffer;

    [[nodiscard]] int xyToIndex(int x, int y) const;
    [[nodiscard]] int xyToIndexZ(int x, int y) const;
public:
    explicit Frame(int width, int height);
    ~Frame();
    void setPixel(int x, int y, Colour colour);
    Colour getPixel(int x, int y);
    float getZValue(int x, int y);
    void setZValue(int x, int y, float zValue);
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
};


#endif //BASICRASTERIZER_FRAME_H
