#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include <string>

using namespace std;
using namespace sf;
class view_game
{
private:
    RenderWindow window;
public:
    void draw_element(int x, int y, int w, int h, string texture_name, float degree = 0, bool turn = 0);
    void draw_interface(int hp, int kp);
};