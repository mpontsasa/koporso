#ifndef UTILITY_H
#define UTILITY_H

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include "gameview.h"
#include <string>

const sf::Time introTime = sf::milliseconds(300);  // intro time in milliseconds
const float gravity = 10;   //pixels/sec

extern sf::Clock gameClock;
extern sf::VideoMode desktop;

extern sf::Time lastUpdate;
extern sf::Time updateTime;

void initializeUtility ();

extern GameView gameView;

std::string conv(int x);

//Game data section

extern float protagonistSpeed;
extern float depthPerHeight;

extern int triggerDistance;

int getViewRightBorder();
int getViewLeftBorder();
bool xInView (int x);
#endif //UTILITY_H
