//
// Created by Алексей on 21.01.2023.
//

#include "start_menu.h"

int start_menu::paint(vector<int> &ctrl_data) {
    auto window = get_window();
    int return_value = 0;
    int x, y;
    Texture start, back, bg, map, hero;
    start.loadFromFile("../texture/start.png");
    back.loadFromFile("../texture/back.png");
    map.loadFromFile("../texture/mini_fon_grass.png");
    hero.loadFromFile("../texture/gg_mini.png");
    bg.loadFromFile("../texture/bg.png");

    Sprite s_start, s_back, s_bg, s_map, s_hero;
    s_start.setPosition(100,300);
    s_back.setPosition(100, 350);
    s_map.setPosition(50, 50);
    s_hero.setPosition(120, 50);
    s_bg.setPosition(0, 0);

    s_start.setTexture(start);
    s_back.setTexture(back);
    s_bg.setTexture(bg);
    s_map.setTexture(map);
    s_hero.setTexture(hero);

    if(IntRect(100, 300, 150, 17).contains(ctrl_data[1], ctrl_data[2] )&& ctrl_data[0]){
        return_value =  3;
    }
    else if(IntRect(100, 350, 130, 17).contains(ctrl_data[1], ctrl_data[2] )&& ctrl_data[0]){
        return_value =  2;
    }
    else if(IntRect(50, 50, 50, 50).contains(ctrl_data[1], ctrl_data[2] )&& ctrl_data[0]){
        ctrl_data[4] = 0; //если будут другие карты, то мы допишем
    }
    else if(IntRect(120, 50, 50, 50).contains(ctrl_data[1], ctrl_data[2])&& ctrl_data[0]){
        ctrl_data[3] = 0; //если будут другие герои, то мы допишем
    }
    else if(IntRect(0, 0, 0, 0).contains(ctrl_data[1], ctrl_data[2]) && ctrl_data[0]){
        return_value = 0;
    }
    window->draw(s_bg);
    window->draw(s_start);
    window->draw(s_back);
    window->draw(s_map);
    window->draw(s_hero);


    return return_value;
}