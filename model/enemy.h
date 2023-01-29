//
// Created by Александр on 19.01.2023.
//
#include "creature.h"
#include "hero.h"
#include <vector>

#ifndef UNTITLED_ENEMY_H
#define UNTITLED_ENEMY_H


class enemy : public creature{
private:
    int damage;
public:
    enemy(string type, int x, int y, int w, int h, int speed, int damage, int hp);
    double direction_to_hero(hero* & hero);
    void move(hero* & hero);
};


#endif //UNTITLED_ENEMY_H