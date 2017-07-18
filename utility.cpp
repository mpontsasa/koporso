#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>


sf::Clock gameClock;
sf::VideoMode desktop;

void initializeUtility ()
{
    desktop = sf::VideoMode::getDesktopMode(); //desktop resolution
//Time initialization
    gameClock.restart();    // start the GameClock
    sf::Time lastUpdate = sf::milliseconds(0);  // Initializes the last update to zero
    const sf::Time updateTime = sf::milliseconds(50);   //Time between two

}
