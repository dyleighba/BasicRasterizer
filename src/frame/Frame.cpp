//
// Created by dylan on 5/04/2022.
//

#include "Frame.h"

int Frame::xyToIndex(int x, int y) {
    return ((width * y) + x)*3;
}

Frame::Frame(int width, int height) {
    this->width = width;
    this->height = height;
    pixels = new int[xyToIndex(width, height)];
}

Frame::~Frame() {
    delete(pixels);
}

void Frame::setPixel(int x, int y, linalg::vec<int, 3> rgb) {
    int index = xyToIndex(x, y);
    pixels[index] = rgb[0];
    pixels[index+1] = rgb[1];
    pixels[index+2] = rgb[2];
}

linalg::vec<int, 3> Frame::getPixel(int x, int y) {
    int index = xyToIndex(x, y);
    return linalg::vec<int, 3>{
        pixels[index],
        pixels[index+1],
        pixels[index+2]
    };
}

int Frame::getWidth() const {
    return width;
}

int Frame::getHeight() const {
    return height;
}




