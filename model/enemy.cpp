//
// Created by Александр on 19.01.2023.
//

#include "enemy.h"
#include <cmath>

enemy::enemy(string type, int x, int y, int w, int h, int speed, int damage, int hp) {
    set_x(x);
    set_y(y);
    set_type(type);
    set_width(w);
    set_height(h);
    set_speed(speed);
    this->damage = damage;
    set_hp(hp);
}

double enemy::direction_to_hero(hero* &hero) {
    int hero_x = hero->get_x();
    int hero_y = hero->get_y();
    int x = this->get_x();
    int y = this->get_y();
    double angle = ::atan2(hero_y - y, hero_x - x);
    return angle;
}
void enemy:: move(hero* & hero){
    int w = get_width();
    int h = get_height();
    int hero_w = hero->get_width();
    int hero_h = hero->get_height();
    double hero_x = hero->get_x();
    double hero_y = hero->get_y();
    double angle = direction_to_hero(hero);
    set_angle_of_rotation(angle);
    double new_x = get_x() + get_speed() * cos(angle);
    double new_y = get_y() + get_speed() * sin(angle);
    set_x(new_x);
    set_y(new_y);
    if (!(new_x > hero_x + hero_w || new_x + w < hero_x || new_y > hero_y + hero_h || new_y + h < hero_y)){
        hero->hit(damage);
    }
}