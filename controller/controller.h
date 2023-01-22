#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../visual/maine_menu.h"
#include "../visual/start_menu.h"
#include "../visual/view_game.h"
#include "../model/game.h"

class controller
{
private:
    int map_num;
    int hero_num;

    sf::RenderWindow* window;
    view* view;
public:
    void play();
    void game();
};

