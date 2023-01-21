//
// Created by Александр on 19.01.2023.
//
#include "world_object.h"
#include "enemy.h"
#include "projectile.h"
#include "hero.h"
#include <vector>

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H


class game {
private:
    hero player;
    //map map;
    vector<projectile> projectile_list;
    vector<enemy> enemy_list;
    //view
public:
    void tic(string direction, bool is_paused);
};


#endif //UNTITLED_GAME_H
