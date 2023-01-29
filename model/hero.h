//
// Created by Александр on 19.01.2023.
//
#include <cmath>
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
    double accuracy;
public:
    void set_cooldown(int tics);
    void set_accuracy(float angle);

    int get_cooldown();
    double fet_accuracy();

    double direction_to_mouse(int x, int y);
    virtual list<projectile*> shot() = 0;
    void move(string direction, int upper_border, int lower_border, int left_border, int right_border);
};


#endif //UNTITLED_HERO_H