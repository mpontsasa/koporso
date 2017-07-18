#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>


sf::Clock gameClock;
sf::VideoMode desktop;

sf::Time lastUpdate;  // Initializes the last update to zero
sf::Time updateTime = sf::milliseconds(50);   //Time between two

sf::View view;

void initializeUtility ()
{
    desktop = sf::VideoMode::getDesktopMode(); //desktop resolution
//Time initialization
    gameClock.restart();    // start the GameClock
    lastUpdate = sf::milliseconds(0);
    view.reset(sf::FloatRect(0,0,desktop.width,desktop.height));
}
