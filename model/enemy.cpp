//
// Created by Александр on 19.01.2023.
//

#include "enemy.h"
#include <cmath>

float enemy::direction_to_hero(hero const &hero) {
    double pi = 3.14159;
    int hero_x = hero.get_x();
    int hero_y = hero.get_y();
    int x = this->get_x();
    int y = this->get_y();
    float angle = pi / 180 * ::atan2(hero_y - y, hero_x - x);
    return angle;

}