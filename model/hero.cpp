//
// Created by Александр on 19.01.2023.
//
#include "hero.h"

double hero::direction_to_mouse(int x, int y) {
    double angle = ::atan2(y - get_y(), x - get_x());
    set_angle_of_rotation(angle);
    return angle;
}

void hero::set_cooldown(int tics){
    this->cooldown = tics;
}
void hero::set_accuracy(float angle){
    this->accuracy = angle;
}

int hero::get_cooldown(){
    return cooldown;
}
double hero::fet_accuracy(){
    return accuracy;
}

void hero::move(string direction, int upper_border, int lower_border, int left_border, int right_border) {
    double x = get_x();
    double y = get_y();
    int speed = get_speed();
    if (direction.size() == 1)
    if (direction == "l")
        x -= speed;
    if (direction == "r")
        x += speed;
    if (direction == "u")
        x -= speed;
    if (direction == "d")
        x += speed;
    else if (direction.size() == 2){
        move(to_string(direction[1]), upper_border, lower_border, left_border, right_border);
        move(to_string(direction[2]), upper_border, lower_border, left_border, right_border);
    }
    if (x>right_border)
        x = right_border;
    if (x<left_border)
        x = left_border;
    if (y>lower_border)
        y = lower_border;
    if (y<lower_border)
        y = upper_border;
}