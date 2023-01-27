#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
class game;
class view;

#ifndef UNTITLED_CONTROLLER_H
#define UNTITLED_CONTROLLER_H


class controller
{
private:
    std::vector<int> control_data; // click,  mouse_x, mouse_y, hero_num, map_num, won or lost.
    int view_num;
    game* game;
    sf::RenderWindow window;
    view* view;
public:
    controller();
    void play();
};

#endif //UNTITLED_CONTROLLER_H