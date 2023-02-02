#ifndef UNTITLED_VIEW_GAME_H
#define UNTITLED_VIEW_GAME_H

#include "list"
#include <string>
#include "view.h"
#include "../model/game.h"

struct texture {
    Sprite sprite = Sprite();
    string type = "";
};


class view_game: public view {
private: game* model;
    list <texture> enemies;
    list <texture> proj_tile;
    Sprite map;
    Sprite player;
    View View;
    void check_enemy();
    void check_projectile();
    void draw_enemy();
    void draw_projectile();

public:
    view_game(RenderWindow* window, game* model);
    view_game(RenderWindow* window): view(window){};
    void draw_interface(int hp, int wp_now, int wp_total) override;
    int paint(vector <int> & ctrl_data)override;

};



#endif //UNTITLED_VIEW_GAME_H