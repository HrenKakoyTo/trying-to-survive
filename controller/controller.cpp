#include "../model/hero.cpp"
#include "../model/hero.h"

#include "controller.h"
Controller::Controller()
{
    window = new sf::RenderWindow (sf::VideoMode(800, 600), "game");
}

Controller::~Controller() {
    //
}

void Controller::play() {
    sf::Clock clock;
    window.setFramerateLimit(60);
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

       switch (VARIABLE){
           case 1:
           {
               menu_num
           }
           case 2:
           {

           }
           case 3:
           {

           }
       }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            hero::move("l");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){

        }

    }

};