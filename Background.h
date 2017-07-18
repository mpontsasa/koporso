#ifndef BACKGROUND_H

#define BACKGROUND_H

#include "ScreenObject.h"

class Background : public ScreenObject
{
public:
    void getEvent(sf::Event event_){};    //Handles the event
    bool hit(sf::Vector2i point){return true;};         //true if the object contains (x,y) point
    void drawThis() const{};

    Background(char *img, int x, int y, int depth, float ratio_x);

    void followScreen(int moved);

private:
    int pos;
    float ratio_x;
    sf::Texture t;
    sf::Sprite s;
};

#endif // BACKGROUND_H
