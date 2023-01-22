#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "view.h"

class view_game: public view
{
public:
    void draw_element(int x, int y, string texture_name, float degree) override;
    void draw_interface(int hp, int wp_now, int wp_total) override;
};