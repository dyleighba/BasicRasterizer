//
// Created by dylan on 6/3/22.
//
#include <draw/DrawUtility.h>
#include <frame/Frame.h>
#include <output/OutputSFML.h>
#include <linalg.h>

using linalg::aliases::int2;
using linalg::aliases::float2;

int main() {
    OutputSFML output = OutputSFML("Test");
    Frame frame = Frame(output.resolution[0], output.resolution[1]);
    Triangle triangle {float2{500, 500},
                       float2{500, 600},
                       float2{600, 600}};
    DrawUtility::drawTriangle(frame, triangle);
    output.output(frame);
    output.poll();
}