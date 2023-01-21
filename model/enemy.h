//
// Created by Александр on 19.01.2023.
//
#include "world_object.h"
#include "hero.h"
#include <vector>

#ifndef UNTITLED_ENEMY_H
#define UNTITLED_ENEMY_H


class enemy : public world_object{
private:
    int damage;
public:
    float direction_to_hero(hero const & hero);
};


#endif //UNTITLED_ENEMY_H
