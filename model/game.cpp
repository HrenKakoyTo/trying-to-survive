//
// Created by Александр on 19.01.2023.
//

#include "game.h"

#include <utility>
#include "petr.h"

struct enemy_type{
    string type;
    int w, h;
    int hp;
    int speed;
    int damage;
};

struct map_type{
    string type;
    int complexity;
    int width, height;
    int wave_cooldown;
    int wave_count;
    list<enemy> enemy_types;
};

vector<map_type> map_types;
vector<enemy_type> enemy_types;
vector<string> hero_types = {"petr"};

void game::start(int hero_type, int map_type) {

    enemy_type pg = {"pg_right", 70, 70, 200, 10, 1}; // перечисление противников

    list<enemy> grass_enemies; // пречисление карт
    grass_enemies.push_back(enemy(pg.type, 0, 0, pg.w, pg.h, pg.speed, pg.damage, pg.hp));
    struct map_type grass = {"fon_grass", 10, 3000, 3000,
                      200, 5, grass_enemies};
    map_types.push_back(grass);
    map = world_map(map_types[map_type].type, map_types[map_type].complexity,map_types[map_type].width, map_types[map_type].height,
                    map_types[map_type].wave_cooldown,map_types[map_type].wave_count, map_types[map_type].enemy_types);


    if (hero_types[hero_type] == "petr"){
        player = new petr();
    }
    else if (!true){

    }

    vector<enemy> new_enemies = map.wave_spawn(player->get_x(), player->get_y());
    for (auto it = new_enemies.begin(); it!= new_enemies.end(); it++){
        enemy_list.push_back(*it);
    }
}

bool collision_check(bool x1, bool y1,int w1, int h1, bool x2, bool y2, int w2, int h2){
    return (x1+w1 > x2 && x2+w2 > x1 && y1+h1 > y2 && y2+h2 > y1);
}

game::game(int hero_type, int map_type, class view *&view):map() {
    start(hero_type, map_type);
    //создание персонажа
}

int game::tic(string direction, bool is_shooting, int mouse_x, int mouse_y) {
    int exit_code = (player->get_hp() < 1)?(-1):(0);  // 0-играем, -1-проигрыш, 1-вин.
    // движение персонажа
    if(exit_code == 0){
        player->move(std::move(direction), 400, map.get_height() - 400,
                     300, map.get_width() - 300);
        player->direction_to_mouse(mouse_x, mouse_y);
    // стрельба
    if (is_shooting) {
        list<projectile *> new_projectiles = player->shot();
        for (auto it = new_projectiles.begin(); it != new_projectiles.end(); it++) {
            projectile_list.push_back(*it);
        }
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
            exit_code = -1;
    }
    // проверка на поподание
    /*for (auto it1 = projectile_list.begin(); it1!=projectile_list.end(); it1++){
        bool fl = true;
        for (auto it2 = enemy_list.begin(); (it2!= enemy_list.end() && fl); it2++){
            if (collision_check((*it1)->get_x(), (*it1)->get_x(), (*it1)->get_width(), (*it1)->get_height(),
                                (it2)->get_x(), (it2)->get_x(), (it2)->get_width(), (it2)->get_height())){
                if(it2->hit((*it1)->get_damage())){
                    auto buf = it2;
                    it2++;
                    enemy_list.erase(buf);
                    it2--;
                }
                if((*it1)->hit()){
                    fl = false;
                    auto buf = it1;
                    it1++;
                    projectile_list.erase(buf);
                    if (it1 != projectile_list.end())
                    it1--;
                    else
                        break;
                }
            }
        }
    }
    */
    // проверка на победку
    if (map.get_wave_number() >= map.get_wave_count() && enemy_list.size() == 0){
        exit_code = 1;
    }
    return exit_code;
}