//
// Created by dylan on 6/3/22.
//
#include <output/OutputSFML.h>

int main() {
    sf::Clock clock;
    OutputSFML output = OutputSFML("Test");
    while (clock.getElapsedTime().asSeconds() < 10);
}