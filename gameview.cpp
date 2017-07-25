#include "gameview.h"
#include "ScreenObject.h"
#include <iostream>

GameView::GameView(int upperLeftX, int upperLeftY, int lowerRightX, int lowerRightY)
{
    sizeOfViewCenter = 1200;
    view.reset(sf::FloatRect(upperLeftX, upperLeftY, lowerRightX, lowerRightY));
}

void GameView::followProtagonist(Protagonist &prot)
{

        if (prot.getXValue() < view.getCenter().x - sizeOfViewCenter/2)    //if out of view center in left
        {
            view.setCenter(prot.getXValue() + sizeOfViewCenter/2, view.getCenter().y);
            ScreenRoot::access().window->setView(view);

        }
        else if (prot.getXValue() > view.getCenter().x + sizeOfViewCenter/2 - prot.getWidth())    //if out of view center in right
        {
            view.setCenter(prot.getXValue() - sizeOfViewCenter/2 + prot.getWidth(), view.getCenter().y);
            ScreenRoot::access().window->setView(view);
        }

        ///Y axis case to come

}
