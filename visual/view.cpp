//
// Created by Алексей on 21.01.2023.
//

#include "view.h"

RenderWindow* view::get_window(){
    return window;
}

view::view(RenderWindow* window):window() {
    this->window = window;
}