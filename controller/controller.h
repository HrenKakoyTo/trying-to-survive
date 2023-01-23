#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../visual/main_menu.h"
#include "../visual/start_menu.h"
#include "../visual/view_game.h"
#include "../visual/view.h"
#include "../model/game.h"

class controller
{
private:
    vector<int> control_data; // click,  mouse_x, mouse_y, hero_num, map_num, won or lost.
    int view_num;
    game game;
    sf::RenderWindow* window;
    view* view;
public:
    controller();
    void play();
};

