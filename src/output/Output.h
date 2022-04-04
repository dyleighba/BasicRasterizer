//
// Created by dylan on 5/04/2022.
//

#ifndef BASICRASTERIZER_OUTPUT_H
#define BASICRASTERIZER_OUTPUT_H

#include <frame/Frame.h>

class Output {
public:
    const int resolution[2] {1024,1024};
    virtual void output(Frame frame) = 0;
};


#endif //BASICRASTERIZER_OUTPUT_H
