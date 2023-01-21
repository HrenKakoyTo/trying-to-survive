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
bool creature::hit(int damage){
    int hp = get_hp() - damage;
    this->hp = hp;
};