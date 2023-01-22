//
// Created by spacename on 22.01.2023.
//

#ifndef UNTITLED_MAIN_MENU_H
#define UNTITLED_MAIN_MENU_H
#include "view.h"

class main_menu: public view
{
bool is_menu = 1;
int menu_num = 0;
int click;

public:
    int paint(vector <int> & ctrl_data) override;
    void draw() ;
    void menu_screen();
};


#endif //UNTITLED_MAIN_MENU_H
