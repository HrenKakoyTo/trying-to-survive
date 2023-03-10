//
// Created by Александр on 21.01.2023.
//

#include <time.h>
#include "world_map.h"

world_map::world_map(string map_name, int complexity, int width, int height, int wave_cooldown, int wave_count, list<enemy> enemy_types):
complexity(complexity), width(width), height(height), wave_cooldown(wave_cooldown), wave_count(wave_count), enemy_list(),
wave_number(0), tic_to_wave(0), map_name(map_name){
    for (auto & enemy_type : enemy_types){
        enemy_list.push_back(enemy_type);
    }
}

string world_map::get_map_name() const {
    return map_name;
}
int world_map::get_complexity() const {
    return complexity;
}
int world_map::get_width() const{
    return width;
}
int world_map::get_height() const{
    return height;
}
int world_map::get_tic_to_wave() const{
    return tic_to_wave;
}
int world_map::get_wave_cooldown() const{
    return wave_cooldown;
}
int world_map::get_wave_number() const {
    return wave_number;
}
int world_map::get_wave_count() const {
    return wave_count;
}
vector<enemy> world_map::get_enemy_list() const{
    return enemy_list;
}

void world_map::set_map_name(string name) {
    this->map_name = name;
}
void world_map::set_complexity(int n) {
    this->complexity = n;
}
void world_map::set_width(int w){
    this->width = w;
}
void world_map::set_height(int h){
    this->height = h;
}
void world_map::set_tic_to_wave(int tics){
    this->tic_to_wave = tics;
}
void world_map::set_wave_cooldown(int tics){
    this->wave_cooldown = tics;
}
void world_map::set_wave_number(int n) {
    this->wave_number = n;
}
void world_map::set_wave_count(int n) {
    this->wave_count = n;
}
void world_map::set_enemy_list(vector<enemy> enemy_list){
    this->enemy_list = enemy_list;
}
vector<enemy> world_map::wave_spawn(int hero_x, int hero_y) {
    vector<enemy> new_enemies;
    if (tic_to_wave > 1 || wave_number == wave_count){
        tic_to_wave -= 1;
        return new_enemies;
    }
    tic_to_wave = wave_cooldown;
    wave_number += 1;
    for (int i=0; i<complexity*(1+wave_number*0.2); i++){
        enemy new_enemy = enemy_list[rand()%enemy_list.size()];
        if (rand()%2){ // 1 left or right
            if (rand()%2){ // left side
                new_enemy.set_x(hero_x - 420);
                new_enemy.set_y(hero_y + rand()%600 - 300);
            }
            else { // right side
                new_enemy.set_x(hero_x + 450);
                new_enemy.set_y(hero_y + rand()%600 - 300);
            }
        }
        else { // 0 up or down
            if (rand()%2){ // up
                new_enemy.set_x(hero_x + rand()%800 - 400);
                new_enemy.set_y(hero_y - 350);
            }
            else { // down
                new_enemy.set_x(hero_x + rand()%800 - 400);
                new_enemy.set_y(hero_y + 310);
            }
        }
        new_enemies.push_back(new_enemy);
    }
    return new_enemies;
}