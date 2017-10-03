#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>



sf::Clock gameClock;
sf::VideoMode desktop;

sf::Time lastUpdate;  // Initializes the last update to zero
sf::Time updateTime = sf::milliseconds(50);   //Time between two

float protagonistSpeed; //pixels / millisecond
float depthPerHeight = 2;
int triggerDistance = 320;

void initializeUtility ()
{
    desktop = sf::VideoMode::getDesktopMode(); //desktop resolution
//Time initialization
    gameClock.restart();    // start the GameClock
    lastUpdate = sf::milliseconds(0);
    protagonistSpeed = 0.5;   //pixels / millisecond
}

