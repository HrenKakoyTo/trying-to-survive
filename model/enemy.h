//
// Created by Александр on 19.01.2023.
//
#include "creature.h"
#include <vector>

#ifndef UNTITLED_ENEMY_H
#define UNTITLED_ENEMY_H


class enemy : public creature{
private:
    int damage;
public:
    float direction_to_hero(creature* const & hero);
    void move(creature* & hero);
};


#endif //UNTITLED_ENEMY_H