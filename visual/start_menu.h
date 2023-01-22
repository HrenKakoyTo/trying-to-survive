//
// Created by Алексей on 21.01.2023.
//

#include "view_game.h"

class start_menu: public view{
public:
    int paint(vector <int> & ctrl_data);
    vector <string> hero_icon;
    vector <string> map;
    vector <string> description;
};
