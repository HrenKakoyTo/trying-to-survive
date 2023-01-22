//
// Created by Александр on 19.01.2023.
//
#include "../visual/view.h"
#include "world_object.h"
#include "enemy.h"
#include "projectile.h"
#include "hero.h"
#include "world_map.h"
#include <vector>

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H


class game {
private:
    hero* player = new hero;
    world_map map;
    vector<projectile*> projectile_list;
    vector<enemy> enemy_list;
    view* view;
public:
    bool tic(string direction, bool is_shooting, int mouse_x, int mouse_y);
};


#endif //UNTITLED_GAME_H
