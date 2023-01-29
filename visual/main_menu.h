//
// Created by spacename on 22.01.2023.
//

#ifndef UNTITLED_MAIN_MENU_H
#define UNTITLED_MAIN_MENU_H
#include "start_menu.h"

class main_menu: public view {
bool is_menu = 1;
int menu_num = 0;
int click;

public:
    main_menu(RenderWindow* window): view(window){};
    virtual void draw_element(int x, int y, string texture_name, float degree) override {}
    virtual void draw_interface(int hp, int wp_now, int wp_total) override {}
    int paint(vector <int> & ctrl_data) override;

};


#endif //UNTITLED_MAIN_MENU_H
