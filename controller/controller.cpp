#include "controller.h"
#include "../model/game.h"
#include "../visual/main_menu.h"

controller::controller():control_data(6,0), view_num(2), window(),
view(new main_menu){
    window = new sf::RenderWindow (sf::VideoMode(800, 600), "game");
    window->setFramerateLimit(20);
    game = new class game (0,0,view);
}



void controller::play() {

    sf::Clock clock;
    sf::Event event;

    string key; //нажатая клавиша

    while (window->isOpen()) {

        sf::Vector2i pixelPos = sf::Mouse::getPosition();
        sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);

        control_data[0] = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        control_data[1] = worldPos.x;
        control_data[2] = worldPos.y;

        key.clear();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            key = "ul";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            key = "dl";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            key = "ur";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            key = "dr";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            key = "u";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            key = "d";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            key = "l";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            key = "r";
        }

        while (window->pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        switch (view->paint(control_data)) {
            case 1: { // в старт-меню
                if (view_num != 1){
                    view = new start_menu;
                    view_num = 1;
                }
            }
            case 2: { // в главное меню
                if (view_num != 2){
                    view = new main_menu;
                    view_num = 2;
                }
            }
            case 3: { // новая игра
                if (view_num != 3){
                    view = new view_game;
                    class game Game(control_data[3], control_data[3], view);
                    view_num = 3;
                }
            }
            case -1: { // выход
                window->close();
                return;
            }
        }
        if (view_num == 3){
            int n = game->tic(key, control_data[0],
                             (int) worldPos.x, (int) worldPos.y);
            if (n != 0) {
                control_data[5] = n;
                switch (view->paint(control_data)) {
                    case 1:
                        view = new start_menu;
                        view_num = 1;
                    case -1:
                        window->close();
                        return;
                }
            }
        }
        window->clear();
        window->display();
    }
};