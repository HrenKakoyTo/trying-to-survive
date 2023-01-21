#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class view {
private:
    RenderWindow window;
public:
    virtual int paint(vector <int> ctrl_data);
    RenderWindow* get_window();
    void set_window(RenderWindow window);
};