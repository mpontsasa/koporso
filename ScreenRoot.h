#ifndef SCREENROOT_H
#define SCREENROOT_H

#include "ScreenObject.h"
#include "Background.h"
#include "fixedground.h"


class ScreenRoot : public ScreenObject // SINGLETON!
{
public:
    ScreenRoot():background(NULL), theGround(NULL){}
    ~ScreenRoot(){}
    void getEvent(sf::Event event_){}   // Don't do anything with event
    virtual bool hit(sf::Vector2i point){return 1;} // Always hit
    virtual void drawThis(){if (background){background -> draw();}}   //Draw the background
    void addBackground(Background *background_);
    void addFixedGround(FixedGround* theGround_);
    void wipeRoot(); // Wipes the ScreenRoot lists, used in the first line of loadSceneFromFile(), REMOVES PROTAGONIST

    static ScreenRoot& access();    // Return the root object++

    sf::RenderWindow *window;

    Background *background;
    FixedGround* theGround;

};
#endif //SCREENROOT_H
