//
// Created by Александр on 21.01.2023.
//

#include "bullet.h"

bool bullet::move() {
    int ttl = get_time_to_live();
    ttl--;
    if (!ttl){
        return true;
    }
    double new_x = get_x() + x_multiplier * get_speed();
    set_x(new_x);
    double new_y = get_y() + y_multiplier * get_speed();
    set_y(new_y);
    return false;
}
bool bullet::hit() {
    return true;
}

bullet::bullet(string type, int h, int w, int speed, int damage, double x, double y, double x_mult, double y_mult,int time_to_live, double angle) {
    set_type(type);
    set_height(h);
    set_width(w);
    set_speed(speed);
    set_damage(damage);
    set_x(x);
    set_y(y);
    this->x_multiplier = x_mult;
    this->y_multiplier = y_mult;
    set_time_to_live(time_to_live);
    set_angle_of_rotation(angle);
}