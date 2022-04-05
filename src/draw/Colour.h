//
// Created by dylan on 5/04/2022.
//

#ifndef BASICRASTERIZER_COLOUR_H
#define BASICRASTERIZER_COLOUR_H

#include <cstdint>

struct Colour {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
};

const Colour black {0,0,0};
const Colour white {255,255,255};
const Colour red {255,0,0};
const Colour blue {0,255,0};
const Colour green {0,0,255};

#endif //BASICRASTERIZER_COLOUR_H
