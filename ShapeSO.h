#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "../koporso/ScreenObject.h"

class ShapeSO : public ScreenObject
{
public:
    ShapeSO (): cs(100, 100){cs.setFillColor(sf::Color::Green);}

    void getEvent(sf::Event event_){std::cout << "yaay";}
    bool hit(sf::Vector2i point){return (sqrt((100 - point.x)*(100 - point.x) + (100 - point.y)*(100 - point.y)) <= 100);}
    void drawThis(){std::cout << "Draw";}
//private:
    sf::CircleShape cs;
};
