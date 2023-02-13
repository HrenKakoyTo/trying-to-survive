//
// Created by Александр on 19.01.2023.
//
#include "world_object.h"
#include "enemy.h"
#include "projectile.h"
#include "hero.h"
#include "world_map.h"
#include <vector>
#include <algorithm>

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

class game {
private:
    hero* player;
    world_map map;
    list<projectile*> projectile_list;
    list<enemy> enemy_list;
public:
    game(int hero_type, int map_type, class view* & view);
    world_map get_map(){return map;}
    hero* get_hero(){return player;}
    auto get_projectile_begin(){return projectile_list.begin();}
    auto get_projectile_end(){return projectile_list.end();}
    auto get_projectile_size(){return projectile_list.size();}
    auto get_enemies_begin(){return enemy_list.begin();}
    auto get_enemies_end(){return enemy_list.end();}
    auto get_enemies_size(){return enemy_list.size();}
    int tic(string direction, bool is_shooting, int mouse_x, int mouse_y);
    void start(int hero_type, int map_type);
};


#endif //UNTITLED_GAME_H
