//
// Created by Александр on 21.01.2023.
//

#include "enemy.h"
#include <vector>

#ifndef UNTITLED_WORLD_MAP_H
#define UNTITLED_WORLD_MAP_H


class world_map {
private:
    int width, height;
    int tic_to_wave;
    int wave_cooldown;
    vector<enemy> enemy_list;
    int wave_count;

};


#endif //UNTITLED_WORLD_MAP_H
