//
// Created by Александр on 21.01.2023.
//

#include "creature.h"

int creature::get_speed(){
    return speed;
};
int creature::get_hp(){
    return hp;
};

void creature::set_speed(int speed) {
    this->speed = speed;
}
void creature::set_hp(int hp) {
    this->hp = hp;
}

bool creature::hit(int damage){
    int hp = get_hp() - damage;
    this->hp = hp;
};