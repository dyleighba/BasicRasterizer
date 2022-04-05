//
// Created by dylan on 5/04/2022.
//

#ifndef BASICRASTERIZER_FRAME_H
#define BASICRASTERIZER_FRAME_H

#include <linalg.h>

class Frame {
    int width;
    int height;
    int *pixels;
    float *zBuffer;

    [[nodiscard]] int xyToIndex(int x, int y) const;
    [[nodiscard]] int xyToIndexZ(int x, int y) const;
public:
    Frame(int width, int height);
    ~Frame();
    void setPixel(int x, int y, linalg::vec<int,3> rgb);
    linalg::vec<int, 3> getPixel(int x, int y);
    int getZValue(int x, int y);
    void setZValue(int x, int y, int zValue);
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
};


#endif //BASICRASTERIZER_FRAME_H
