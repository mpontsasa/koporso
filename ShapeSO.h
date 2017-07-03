#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class ShapeSO : public ScreenObject
{
public:
    ShapeSO (): cs(100, 100){}

    void GetEvent(float x, float y){std::cout << "yaay";}
    bool Hit(float x, float y){return (sqrt((100 - x)*(100 - x) + (100 - y)*(100 - y)) <= 100);}
    void Draw(float , float ){std::cout << "Draw";}
private:
    sf::CircleShape cs;
};
