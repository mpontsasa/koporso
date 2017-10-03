#include "gameview.h"
#include "ScreenObject.h"
#include "Background.h"
#include <iostream>
#include "ScreenRoot.h"

GameView gameView(0, 0, 3000, 2000);

GameView::GameView(int upperLeftX, int upperLeftY, int lowerRightX, int lowerRightY)
{
    sizeOfViewCenter = 1000;
    view.reset(sf::FloatRect(upperLeftX, upperLeftY, lowerRightX, lowerRightY));
}

void GameView::followProtagonist(Protagonist &prot)
{

        if (prot.getXValue() < view.getCenter().x - sizeOfViewCenter/2)    //if out of view center in left
        {
            int newCenterX = prot.getXValue() + sizeOfViewCenter/2;

            if(ScreenRoot::access().background) //if there is a background
                ScreenRoot::access().background ->followScreen(newCenterX - view.getCenter().x);    //move the background

            view.setCenter(newCenterX, view.getCenter().y);
            ScreenRoot::access().window->setView(view);

        }
        else if (prot.getXValue() > view.getCenter().x + sizeOfViewCenter/2 - prot.getWidth())    //if out of view center in right
        {
            int newCenterX = prot.getXValue() - sizeOfViewCenter/2 + prot.getWidth();
            if(ScreenRoot::access().background) //if there is a background
                ScreenRoot::access().background ->followScreen(newCenterX - view.getCenter().x);    //move the background
            view.setCenter(newCenterX, view.getCenter().y);
            ScreenRoot::access().window->setView(view);
        }

        ///Y axis case to come
}

int getViewLeftBorder()
{
    return gameView.view.getCenter().x - gameView.view.getSize().x / 2;
}

int getViewRightBorder()
{
    return gameView.view.getCenter().x + gameView.view.getSize().x / 2;
}

bool xInView (int x)
{
    return (x > getViewLeftBorder() && x < getViewRightBorder());
}
