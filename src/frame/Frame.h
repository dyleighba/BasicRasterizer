//
// Created by dylan on 5/04/2022.
//

#ifndef BASICRASTERIZER_FRAME_H
#define BASICRASTERIZER_FRAME_H

#include <linalg.h>

class Frame {
    int width;
    int height;
    int* pixels;

    int xyToIndex(int x, int y);
public:
    Frame(int width, int height);
    ~Frame();
    void setPixel(int x, int y, linalg::vec<int,3> rgb);
    linalg::vec<int, 3> getPixel(int x, int y);
    int getWidth() const;
    int getHeight() const;
};


#endif //BASICRASTERIZER_FRAME_H
