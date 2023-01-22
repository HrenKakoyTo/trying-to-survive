#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "view.h"

class view_game: public view
{
public:
    void draw_element(int x, int y, int w, int h, string texture_name, float degree = 0);
    void draw_interface(int hp, int kp);
};