#include "main_menu.h"

int main_menu::paint(vector<int> &ctrl_data) {
    auto window = get_window();
    int return_value = 0;

    Texture start, exit, bg;
    start.loadFromFile("../texture/start.png");
    exit.loadFromFile("../texture/exit.png");
    bg.loadFromFile("../texture/bg.png");

    Sprite s_start, s_exit, s_bg;
    s_start.setPosition(300,290);
    s_exit.setPosition(300, 380);
    s_bg.setPosition(0, 0);
    s_start.setTexture(start);
    s_exit.setTexture(exit);
    s_bg.setTexture(bg);

    if(IntRect(300, 290, 150, 17).contains(ctrl_data[1], ctrl_data[2]) && ctrl_data[0]){
        return_value = 1;
    }
    else if(IntRect(300, 380, 125, 17).contains(ctrl_data[1], ctrl_data[2]) && ctrl_data[0]){
        return_value = -1;
    }
    else if(IntRect(0, 0, 0, 0).contains(ctrl_data[1], ctrl_data[2])){
        return_value = 0;
    }

    window->draw(s_bg);
    window->draw(s_start);
    window->draw(s_exit);


    return return_value;
}