//
// Created by Александр on 19.01.2023.
//
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
    list<projectile*> projectile_list;
    list<enemy> enemy_list;
public:
    game(int hero_type, int map_type, class view* & view);
    world_map get_map(){return map;}
    hero* get_hero(){return player;}
    list<projectile*> get_projectiles(){return projectile_list;}
    list<enemy> get_enemies(){return enemy_list;}
    int tic(string direction, bool is_shooting, int mouse_x, int mouse_y);
    void start(int hero_type, int map_type);
};


#endif //UNTITLED_GAME_H
