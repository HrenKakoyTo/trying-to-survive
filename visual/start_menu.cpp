//
// Created by Алексей on 21.01.2023.
//

#include "start_menu.h"

void start_menu::menu_screen()
{
    auto window = get_window();
    Texture new_game, back, bg;
    new_game.loadFromFile("./texture/__");
    back.loadFromFile("./texture/___");
    bg.loadFromFile("./texture/___");
    Sprite s_new_game, s_back, s_bg;
    s_new_game.setPosition(100,300);
    s_back.setPosition(100, 350);
    s_bg.setPosition(0, 0);

    window->draw(s_new_game);
    window->draw(s_back);
    window->draw(s_bg);
}

int start_menu::button_check() {

}

int start_menu::paint(vector<int> &ctrl_data) {
    int return_value = 0;
    if (ctrl_data[0]){
        return_value = button_check();
    }
    menu_screen();
    return return_value;
}