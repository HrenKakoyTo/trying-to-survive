//
// Created by Александр on 21.01.2023.
//

#include "enemy.h"
#include <vector>

#ifndef UNTITLED_WORLD_MAP_H
#define UNTITLED_WORLD_MAP_H


class world_map {
private:
    int complexity;
    int width, height;
    int tic_to_wave;
    int wave_cooldown;
    vector<enemy> enemy_list;
    int wave_number;
    int wave_count;
public:
    world_map(int complexity, int width, int height, int wave_cooldown, vector<enemy> enemy_list);

    int get_complexity() const;
    int get_width() const;
    int get_height() const;
    int get_tic_to_wave() const;
    int get_wave_cooldown() const;
    int get_wave_number() const;
    int get_wave_count() const;
    vector<enemy> get_enemy_list() const;

    void set_complexity(int n);
    void set_width(int w);
    void set_height(int h);
    void set_tic_to_wave(int tics);
    void set_wave_cooldown(int tics);
    void set_wave_number(int n);
    void set_wave_count(int n);
    void set_enemy_list(vector<enemy> enemy_list);

    vector<enemy> wave_spawn(int hero_x, int hero_y);
};

#endif //UNTITLED_WORLD_MAP_H