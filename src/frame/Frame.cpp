//
// Created by dylan on 5/04/2022.
//

#include "Frame.h"

int Frame::xyToIndex(int x, int y) const {
    return ((width * y) + x)*3;
}

int Frame::xyToIndexZ(int x, int y) const {
    return ((width * y) + x);
}

Frame::Frame(int width, int height) {
    this->width = width;
    this->height = height;
    pixels = new uint8_t[xyToIndex(width, height)];
    zBuffer = new float[xyToIndexZ(width, height)];
}

Frame::~Frame() {
    delete(pixels);
    delete(zBuffer);
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

void Frame::setZValue(int x, int y, int zValue) {
    int index = xyToIndexZ(x, y);
    zBuffer[index] = zValue;
}

int Frame::getZValue(int x, int y) {
    int index = xyToIndexZ(x, y);
    return zBuffer[index];
}

int Frame::getWidth() const {
    return width;
}

int Frame::getHeight() const {
    return height;
}




