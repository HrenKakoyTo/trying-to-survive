//
// Created by Александр on 21.01.2023.
//
#include "projectile.h"

int projectile::get_speed() const{
    return speed;
}
int projectile::get_damage() const{
    return damage;
}
int projectile::get_time_to_live() const{
    return time_to_live;
}

void projectile::set_speed(int speed){
    this->speed = speed;
}
void projectile::set_damage(int damage){
    this->damage = damage;
}
void projectile::set_time_to_live(int tics){
    this->time_to_live = tics;
}