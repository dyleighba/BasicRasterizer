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

    // create image container for sfml
    int channelCount = 4;
    std::vector<sf::Uint8> pixels(frame.getWidth() * frame.getHeight() * channelCount);

    unsigned char fullOpacity = 255;

    // translate from frame to sfml
    for (int x = 0; x < frame.getWidth(); x++) {
        for (int y = 0; y < frame.getHeight(); y++) {
            Colour colour = frame.getPixel(x, y);
            int indexOffset = (x + y * frame.getWidth()) * channelCount;
            pixels[indexOffset + 0] = colour.r;
            pixels[indexOffset + 1] = colour.g;
            pixels[indexOffset + 2] = colour.b;
            pixels[indexOffset + 3] = fullOpacity;
        }
    }

    sf::Image image;
    image.create(frame.getWidth(), frame.getHeight(), pixels.data());
    sf::Texture tex;
    tex.loadFromImage(image);
    sf::Sprite sprite;
    sprite.setTexture(tex);
    window.draw(sprite);
    window.display();
}

void OutputSFML::poll() {
    // wait for window to close
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }
    }
}
