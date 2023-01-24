//
// Created by Алексей on 21.01.2023.
//

#ifndef UNTITLED_START_MENU_H
#define UNTITLED_START_MENU_H

#include "view_game.h"

class start_menu: public view {
public:
    virtual void draw_element(int x, int y, string texture_name, float degree) override {}
    virtual void draw_interface(int hp, int wp_now, int wp_total) override {}
    int paint(vector <int> & ctrl_data) override;
private:
    vector <string> hero_icons = {"petr"};
    vector <string> maps = {"fon_grass"};
};

#endif //UNTITLED_START_MENU_H