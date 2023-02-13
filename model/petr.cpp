//
// Created by Александр on 22.01.2023.
//

#include "petr.h"
#include "bullet.h"

petr::petr() {
    set_type("petr_right");
    set_hp(100);
    set_speed(2);
    set_cooldown(3);
    set_accuracy(0.174533);
    set_width(100);
    set_height(70);
    set_time_to_shot(0);
    set_x(1500);
    set_y(1500);
}

list<projectile*> petr::shot() {
    double angle = get_angle_of_rotation();
    double x_mult = cos(angle);
    double y_mult = sin(angle);
    list<projectile*> bullets;
    if (get_time_to_shot() < 1) {
        set_time_to_shot(get_cooldown());
        bullets.push_back(new bullet("standard_bullet", 10, 10, 15, 50, get_x(),
                                     get_y(), x_mult, y_mult, 10, angle));
    }
    return bullets;
}