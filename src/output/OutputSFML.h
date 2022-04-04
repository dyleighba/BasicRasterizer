//
// Created by dylan on 5/04/2022.
//

#ifndef BASICRASTERIZER_OUTPUTSFML_H
#define BASICRASTERIZER_OUTPUTSFML_H

#include <output/Output.h>
#include <SFML/Graphics.hpp>

class OutputSFML: public Output {
    sf::RenderWindow window;
public:
    OutputSFML(std::string windowName);
    ~OutputSFML();
    void output(Frame frame);
};


#endif //BASICRASTERIZER_OUTPUTSFML_H
