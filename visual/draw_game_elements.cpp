#include "draw_game_elements.h"

void view_game::draw_element(int x, int y, int w, int h, string texture_name, float degree, bool turn) {
    auto window = get_window(); // в каждой функции берёшь окно на котором надо рисовать
    Texture game_element;
    game_element.loadFromFile("./texture"+texture_name+".png");
    Sprite s_texture_name;
    s_texture_name.setTexture(game_element);
    if(turn)
        s_texture_name.setTextureRect(sf::IntRect(x+w,y,-w,h));
    s_texture_name.setPosition(x, y);
    s_texture_name.setRotation(degree);
    window->draw(s_texture_name);
  //важно ^^^  методы вызываешь через стрелочку
}
void view_game::draw_interface(int hp, int kp) {
    string str_heal_point;
    string str_kill_point;
    str_heal_point = to_string(hp);
    str_kill_point = to_string(kp);
Text heal_point;
    heal_point.setPosition(50, 50);
    heal_point.setCharacterSize(25);
    heal_point.setString(str_heal_point);
Text kill_point;
    kill_point.setPosition(50, 100);
    kill_point.setCharacterSize(25);
    kill_point.setString(str_kill_point);
    window.draw(heal_point);
    window.draw(kill_point);
}



