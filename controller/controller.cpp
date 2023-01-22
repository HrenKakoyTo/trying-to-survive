#include "../model/game.h"
#include "controller.h"

void controller::play() {
    controller();
    sf::Clock clock;
    window = new sf::RenderWindow (sf::VideoMode(800, 600), "game");
    window.setFramerateLimit(20);
    sf::Event event;

    game Game;
    string key; //нажатая клавиша

    while (window.pollEvent(event))
    {

        if (event.type == sf::Event::Closed)
            window.close();


       switch (VARIABLE){
           case 1:
           {
              // menu_num
           }
           case 2:
           {

           }
           case 3:
           {

           }
       }

       key.clear();

       if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
           key="ul";
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
           key="dl";
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
           key="ur";
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
           key="dr";
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
           key="u";
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
           key="d";
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
           key="l";
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
           key="r";
       }

       if (Game.tic()) {
           n=view.paint();
           switch (condition) {
               case 1: newgame
               case 2: exit
               default:

           }
       }

       Game.tic(key, sf::Mouse::isButtonPressed(sf::Mouse::Left));


    }
    window.clear();
    window.display();
};