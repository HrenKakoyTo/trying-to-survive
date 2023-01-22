//
// Created by Александр on 19.01.2023.
//

#include "game.h"


bool collision_check(bool x1, bool y1,int w1, int h1, bool x2, bool y2, int w2, int h2){
    return x1+w1 > x2 && x2+w2 > x1 && y1+h1 > y2 && y2+h2 > y1;
}

bool game::tic(string direction, bool is_shooting, int mouse_x, int mouse_y) {
    bool is_plaer_dead = player->get_hp() < 1;
    // движение персонажа
    if (!is_plaer_dead)
        player->move(direction, map.get_height(), map.get_width());
    // стрельба
    if (is_shooting){
        list<projectile*> new_projectiles = player->shot();
        for(auto it = new_projectiles.begin(); it!=new_projectiles.end(); it++) {
            projectile_list.push_back(*it);
        }
    }
    // спавн противников
    vector<enemy> new_enemies = map.wave_spawn(player->get_x(), player->get_y());
    for (auto it = new_enemies.begin(); it!= new_enemies.end(); it++){
        enemy_list.push_back(*it);
    }
    // движение противников + их атака
    for (auto it = enemy_list.begin(); it!=enemy_list.end(); it++){
        it->move(player);
        if(player->get_hp() < 1)
            is_plaer_dead = 1;
    }
    // проверка на поподание
    for (auto it1 = projectile_list.begin(); it1!=projectile_list.end(); it1++){
        for (auto it2 = enemy_list.begin(); it2!= enemy_list.end(); it2++){
            if (collision_check((*it1)->get_x(), (*it1)->get_x(), (*it1)->get_width(), (*it1)->get_height(),
                                (it2)->get_x(), (it2)->get_x(), (it2)->get_width(), (it2)->get_height())){
                if(it2->hit((*it1)->get_damage())){
                    auto buf = it2;
                    it2++;
                    enemy_list.erase(buf);
                    it2--;
                }
                if((*it1)->hit()){
                    auto buf = it1;
                    it1++;
                    projectile_list.erase(buf);
                    it1--;
                }
            }
        }
    }
}