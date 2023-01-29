//
// Created by Алексей on 21.01.2023.
//

#include "view_game.h"

void view_game::draw_element(int x, int y, string texture_name, float degree) {
    auto window = get_window();
    Texture game_element;
    string path = "../texture/"+texture_name+".png";
    game_element.loadFromFile(path);
    Sprite s_texture_name;
    s_texture_name.setTexture(game_element);
    s_texture_name.setPosition(x, y);
    float g_degree;
    g_degree = degree * (360/3.14);
    s_texture_name.setRotation(g_degree);
    window->draw(s_texture_name);
}

void view_game::draw_interface(int hp, int wp_now, int wp_total) {
    auto window = get_window();

    Font font;
    font.loadFromFile("C:/WINDOWS/Fonts/arial.ttf");

    string str_heal_point;
    str_heal_point = to_string(hp);
Text heal_point("", font, 20);
    heal_point.setPosition(50, 50);
    heal_point.setString(str_heal_point);
    heal_point.setColor(Color::Red);
    string str_wave_point_now;
    str_wave_point_now = to_string(wp_now);
    string str_wave_point_total;
    str_wave_point_total = to_string(wp_total);
Text wave_point("", font, 20);
    wave_point.setColor(Color::Red);
    wave_point.setPosition(50, 100);
    wave_point.setCharacterSize(25);
    wave_point.setString(L"Волна" + str_wave_point_now + L"из" + str_wave_point_total);

    window->draw(heal_point);
    window->draw(wave_point);
}

int view_game::paint(vector<int> &ctrl_data) {
    auto window = get_window();
    if (ctrl_data[5] == 1){  // win

    }
    else {  //lose

    }
     // + кнопки
    return 0;
}