//
// Created by Александр on 19.01.2023.
//

#include "enemy.h"
#include <cmath>

float enemy::direction_to_hero(creature* const &hero) {
    int hero_x = hero->get_x();
    int hero_y = hero->get_y();
    int x = this->get_x();
    int y = this->get_y();
    float angle = ::atan2(hero_y - y, hero_x - x);
    return angle;
}
void enemy:: move(creature* & hero){
    int w = get_width();
    int h = get_height();
    int hero_w = hero->get_width();
    int hero_h = hero->get_height();
    int hero_x = hero->get_x();
    int hero_y = hero->get_y();
    float angle = direction_to_hero(hero);
    set_angle_of_rotation(angle);
    int new_x = get_x() + get_speed() * cos(angle);
    int new_y = get_y() + get_speed() * sin(angle);
    set_x(new_x);
    set_y(new_y);
    if (abs(new_x-hero_x) < (w+hero_w)/2 && abs(new_y-hero_y) < (h+hero_h)/2)
        hero->hit(damage);
}