//
// Created by Алексей on 21.01.2023.
//

#include "view_game.h"

void view_game::draw_element(int x, int y, int w, int h, string texture_name, float degree) {
    auto window = get_window(); // в каждой функции берёшь окно на котором надо рисовать
    Texture game_element;
    game_element.loadFromFile("./texture"+texture_name+".png");
    Sprite s_texture_name;
    s_texture_name.setTexture(game_element);
    s_texture_name.setPosition(x, y);
    float g_degree;
    g_degree = degree * (180/3,14);
    s_texture_name.setRotation(g_degree);
    window->draw(s_texture_name);
  //важно ^^^  методы вызываешь через стрелочку
}
void view_game::draw_interface(int hp, int wp_now, int wp_total) {
    auto window = get_window();

    string str_heal_point;
    str_heal_point = to_string(hp);
Text heal_point;
    heal_point.setPosition(50, 50);
    heal_point.setCharacterSize(25);
    heal_point.setString(str_heal_point);

    string str_wave_point_now;
    str_wave_point_now = to_string(wp_now);
    string str_wave_point_total;
    str_wave_point_total = to_string(wp_total);
Text wave_point;
    wave_point.setPosition(50, 100);
    wave_point.setCharacterSize(25);
    wave_point.setString(L"Волна");
    wave_point.setString(str_wave_point_now);
    wave_point.setString(L"из");
    wave_point.setString(str_wave_point_total);
    window->draw(heal_point);
    window->draw(wave_point);
}



