//
// Created by Александр on 19.01.2023.
//
#include "world_object.h"
#include "drop.h"
#include "hero.h"
#include <vector>

#ifndef UNTITLED_ENEMY_H
#define UNTITLED_ENEMY_H


class enemy : public world_object{
private:
    int hp, speed, damage, armor;
    int distance_to_hero;
    bool is_facing_right;
    vector <drop> drop_list;
public:
    void move(hero & hero);
    int calculate_the_distance_to_hero(hero & hero);
    float direction_to_hero(hero & hero);
    bool hit(int damage); //возвращает остался ли моб жив после попадания
    virtual ~enemy();
};


#endif //UNTITLED_ENEMY_H
