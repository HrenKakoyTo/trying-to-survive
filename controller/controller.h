#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Controller
{
    sf::RenderWindow* window;

public:
    Controller();
    ~Controller();
    void play();

};

