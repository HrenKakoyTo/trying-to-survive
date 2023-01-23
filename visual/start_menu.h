//
// Created by Алексей on 21.01.2023.
//

#include "view.h"

class start_menu: public view_module{
public:
    int paint(vector <int> & ctrl_data) override;
    void menu_screen() override;
    int button_check() override;
private:
    vector <string> hero_icons = {"petr"};
    vector <string> maps = {"fon_grass"};
};