//
// Created by dylan on 5/04/2022.
//

#ifndef BASICRASTERIZER_FRAME_H
#define BASICRASTERIZER_FRAME_H

#include <linalg.h>

class Frame {
    int width;
    int height;
    linalg::vec<float,3> pixels[];

    int xyToIndex(int x, int y);
public:
    Frame(int width, int height);
    void setPixel(int x, int y, linalg::vec<float,3> rgb);
    linalg::vec<float,3> getPixel(int x, int y);
};


#endif //BASICRASTERIZER_FRAME_H
