#ifndef UTILITY_H
#define UTILITY_H

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

const sf::Time introTime = sf::milliseconds(2000);  // intro time in milliseconds

extern sf::Clock gameClock;
extern sf::VideoMode desktop;

extern sf::Time lastUpdate;
extern sf::Time updateTime;

void initializeUtility ();

extern sf::View view;

//Game data section

extern float protagonistSpeed;



#endif //UTILITY_H
