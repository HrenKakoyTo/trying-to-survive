//
// Created by Александр on 19.01.2023.
//
#include "world_object.h"

string world_object::get_type() const{
    return type;
}
double world_object::get_x() const{
    return x;
}
double world_object::get_y() const{
    return y;
}
int world_object::get_width() const{
    return width;
}
int world_object::get_height() const{
    return height;
}
double world_object::get_angle_of_rotation() const{
    return angle_of_rotation;
}

void world_object::set_type(string type) {
    this->type = type;
}
void world_object::set_x(int x) {
    this->x = x;
}
void world_object::set_y(int y) {
    this->y = y;
}
void world_object::set_height(int h) {
    this->height = h;
}
void world_object::set_width(int w) {
    this->width = w;
}
void world_object::set_angle_of_rotation(float angle) {
    this->angle_of_rotation = angle;
}