#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "ScreenObject.h"

class Background : public ScreenObject
{
public:
    void getEvent(sf::Event event_){};    //Handles the event
    bool hit(sf::Vector2i point){return true;};         //true if the object contains (x,y) point
    void drawThis();
    ~Background(){}
    Background(const char *img, int x, int y, int z, float ratio_x);

    void followScreen(int moved);

private:
    int pos;
    float ratio_x;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif // BACKGROUND_H
