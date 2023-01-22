//
// Created by Александр on 22.01.2023.
//

#include "petr.h"
#include "bullet.h"

petr::petr() {
    set_hp(100);
    set_speed(2);
    set_cooldown(20);
    set_accuracy(0.174533);
}

list<projectile*> petr::shot() {
    float angle = get_angle_of_rotation();
    int x_mult = cos(angle);
    int y_mult = sin(angle);
    list<projectile*> bullet;
    bullet.push_back(new class bullet("standard_bullet", 10, 10, 15, 20, get_x(),
            get_y(), x_mult, y_mult, 50));
    return bullet;
}