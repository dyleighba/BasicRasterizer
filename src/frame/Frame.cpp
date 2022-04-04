//
// Created by dylan on 5/04/2022.
//

#include "Frame.h"

int Frame::xyToIndex(int x, int y) {
    return (width * y) + x;
}

Frame::Frame(int width, int height) {
    this->width = width;
    this->height = height;
    pixels[xyToIndex(width, height)];
}

void Frame::setPixel(int x, int y, linalg::vec<float, 3> rgb) {
    int index = xyToIndex(x, y);
    pixels[index] = rgb;
}

linalg::vec<float, 3> Frame::getPixel(int x, int y) {
    int index = xyToIndex(x, y);
    return pixels[index];
}

int Frame::getWidth() const {
    return width;
}

int Frame::getHeight() const {
    return height;
}




