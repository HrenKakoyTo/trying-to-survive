#include "model/game.h"
#include "controller/controller.h"
#include "visual/draw_game_elements.h"
#include <SFML/Window.hpp>

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "My window");

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    return 0;
}
