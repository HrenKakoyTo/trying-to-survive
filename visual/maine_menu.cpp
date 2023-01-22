#include "maine_menu.h"



void game_menu::menu_screen()
{
    auto window = get_window();
    Texture new_game, exit, bg;
    new_game.loadFromFile("./texture/__");
    exit.loadFromFile("./texture/___");
    bg.loadFromFile("./texture/___");
    Sprite s_new_game, s_exit, s_bg;
    s_new_game.setPosition(100,300);
    s_exit.setPosition(100, 350);
    s_bg.setPosition(0, 0);









    window->draw(s_new_game);
    window->draw(s_exit);
    window->draw(s_bg);
}

