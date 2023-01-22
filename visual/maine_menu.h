//
// Created by spacename on 22.01.2023.
//

#ifndef UNTITLED_MAINE_MENU_H
#define UNTITLED_MAINE_MENU_H
#include "view_game.h"

class game_menu: public view
{
bool is_menu = 1;
int menu_num = 0;
int click;

public:
    int paint(vector <int> & ctrl_data);
    void draw();
    void menu_screen();

};


#endif //UNTITLED_MAINE_MENU_H
