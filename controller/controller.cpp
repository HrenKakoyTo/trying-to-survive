#include "controller.h"
#include "../model/game.h"
#include "../visual/main_menu.h"


controller::controller():control_data(6,0), view_num(2), window(sf::VideoMode(800, 600), "trying to survive"),
view(new main_menu(&window)){
    window.setFramerateLimit(20);
    game = new class game (0,0,view);
}

void controller::play() {

    sf::Clock clock;
    sf::Event event;

    string key; //нажатая клавиша

    while (window.isOpen()) {

        window.clear();

        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

        control_data[0] = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        control_data[1] = pixelPos.x;
        control_data[2] = pixelPos.y;

        key.clear();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            key = "ul";
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            key = "dl";
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            key = "ur";
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            key = "dr";
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            key = "u";
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            key = "d";
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            key = "l";
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            key = "r";
        }

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (view_num != 3) {
            int k = view->paint(control_data);
            switch (k) {
                case 1: { // в старт-меню
                    if (view_num != 1) {
                        delete view;
                        view = new start_menu(&window);
                        view_num = 1;
                    }
                    break;
                }
                case 2: { // в главное меню
                    if (view_num != 2) {
                        delete view;
                        view = new main_menu(&window);
                        view_num = 2;
                    }
                    break;
                }
                case 3: { // новая игра
                    if (view_num != 3) {
                        delete view;
                        view = new view_game(&window, game);
                        delete game;
                        game = new class game(control_data[3], control_data[3], view);
                        view_num = 3;
                        control_data[5] = 0;
                    }
                    break;
                }
                case -1: { // выход
                    window.close();
                    return;
                }

            }
        }
        if (view_num == 3) {
            int n = game->tic(key, control_data[0],
                              (int) pixelPos.x, (int) pixelPos.y);
            control_data[5] = n;
            switch (view->paint(control_data)) {
                case 1:
                    view = new start_menu(&window);
                    view_num = 1;
                    break;
                case -1:
                    window.close();
                    return;
            }
        }
        window.display();

    }
};