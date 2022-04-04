//
// Created by dylan on 5/04/2022.
//

#include "OutputSFML.h"

OutputSFML::OutputSFML(std::string windowName) {
    window.create(sf::VideoMode(resolution[0], resolution[1]), "Render");
}

OutputSFML::~OutputSFML() {
    window.close();
}

void OutputSFML::output(Frame frame) {

}