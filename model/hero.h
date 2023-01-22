//
// Created by Александр on 19.01.2023.
//
#include <string>
#include "projectile.h"
#include <list>
#include "creature.h"

#ifndef UNTITLED_HERO_H
#define UNTITLED_HERO_H

class hero: public creature{
private:
    int time_to_shot;
    int cooldown;
    float accuracy;
public:
    virtual list<projectile*> shot();
    void move(string direction, int upper_border, int lower_border, int left_border, int right_border);
};


#endif //UNTITLED_HERO_H