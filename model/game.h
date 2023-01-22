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
    hero* player;
    world_map map;
    vector<projectile*> projectile_list;
    vector<enemy> enemy_list;
    view* view;
public:
    game(int hero_type, int map_type, class view* & view);
    int tic(string direction, bool is_shooting, int mouse_x, int mouse_y);
    void throwing_data_into_the_view();
};


#endif //UNTITLED_GAME_H
