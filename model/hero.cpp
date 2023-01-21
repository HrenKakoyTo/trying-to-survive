//
// Created by Александр on 19.01.2023.
//

#include "hero.h"

void hero::move(string direction, int map_h, int map_w) {
    float x = get_x();
    float y = get_y();
    int speed = get_speed();
    if (direction == "l" && x > 0)
        x -= speed;
    if (direction == "r" && x < map_w-get_width())
        x += speed;
    if (direction == "u" && y > 0)
        x -= speed;
    if (direction == "d" && y < map_h-get_height())
        x += speed;
};