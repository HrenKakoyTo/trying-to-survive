#include "main_menu.h"

int main_menu::paint(vector<int> &ctrl_data) {
    auto window = get_window();
    int return_value = 0;
    Texture start, exit, bg;
    start.loadFromFile("../texture/start.png");
    exit.loadFromFile("../texture/exit.png");
    bg.loadFromFile("../texture/bg.png");
    Sprite s_start, s_exit, s_bg;
    s_start.setPosition(100,300);
    s_exit.setPosition(100, 350);
    s_bg.setPosition(0, 0);

    if(IntRect(100, 300, 150, 17).contains(ctrl_data[1], ctrl_data[2])){
        return_value = 3;
    }
    if(IntRect(100, 350, 125, 17).contains(ctrl_data[1], ctrl_data[2])){
        return_value = -1;
    }
    if(IntRect(0, 0, 0, 0).contains(ctrl_data[1], ctrl_data[2])){
        return_value = 0;
    }

    window->draw(s_bg);
    window->draw(s_start);
    window->draw(s_exit);


    return return_value;
}