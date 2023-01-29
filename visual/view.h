//
// Created by Алексей on 21.01.2023.
//

#ifndef UNTITLED_VIEW_H
#define UNTITLED_VIEW_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>


using namespace std;
using namespace sf;

class view {
private:
    RenderWindow* window;
public:
    view(RenderWindow* window);
    virtual void draw_element(int x, int y, string texture_name, float degree) = 0;
    virtual void draw_interface(int hp, int wp_now, int wp_total) = 0;
    virtual int paint(vector <int> & ctrl_data) = 0;
    RenderWindow* get_window();
};

#endif //UNTITLED_VIEW_H