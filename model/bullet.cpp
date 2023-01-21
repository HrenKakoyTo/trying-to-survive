//
// Created by Александр on 21.01.2023.
//

#include "bullet.h"

void bullet::move() {
    double new_x = get_x() + x_multiplier * get_speed();
    set_x(new_x);
    double new_y = get_y() + y_multiplier * get_speed();
    set_y(new_y);
}
bool bullet::hit(creature* & creature) {
    creature->hit(get_damage());
    return true;
}