#ifndef UTILITY_H
#define UTILITY_H

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

extern sf::Clock gameClock;
extern sf::VideoMode desktop;

extern sf::Time lastUpdate;
extern sf::Time updateTime;

void initializeUtility ();


#endif //UTILITY_H
