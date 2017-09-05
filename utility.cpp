#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include "gameview.h"

sf::Clock gameClock;
sf::VideoMode desktop;

sf::Time lastUpdate;  // Initializes the last update to zero
sf::Time updateTime = sf::milliseconds(50);   //Time between two

GameView gameView(0, 0, 3000, 2000);

float protagonistSpeed; //pixels / millisecond
float depthPerHeight = 2;
int introTriggerDistance = 300;
int outroTriggerDistance = 250;

void initializeUtility ()
{
    desktop = sf::VideoMode::getDesktopMode(); //desktop resolution
//Time initialization
    gameClock.restart();    // start the GameClock
    lastUpdate = sf::milliseconds(0);
    protagonistSpeed = 1;   //pixels / millisecond
}
