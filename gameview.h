#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include "Protagonist.h"
#include "Background.h"

class GameView
{
public:
    GameView(int upperLeftX, int upperLeftY, int lowerRightX, int lowerRightY);

    void followProtagonist(Protagonist &prot);

    sf::View view;
    int sizeOfViewCenter; //size of the part in which the protagonist can move without view scrolls
};

extern GameView gameView;

int getViewRightBorder();
int getViewLeftBorder();
bool xInView (int x);

#endif // GAMEVIEW_H
