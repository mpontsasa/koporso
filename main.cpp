#include <SFML/Graphics.hpp>
#include "../koporso/ShapeSO.h"
#include "../koporso/SimpleImage.h"
#include "utility.h"

int main()
{
    ShapeSO sos;

    SimpleImage img("../koporso/Resources/lion.png",-100,-50,3);
    SimpleImage img2("../koporso/Resources/lion.png",100,100,4);

    ScreenRoot::access().addStaticSo(&img);
    ScreenRoot::access().addStaticSo(&img2);

// Initialiseing the screen
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode(); //desktop resolution
    ScreenRoot::access().window = new sf::RenderWindow(desktop, "SFML Window", sf::Style::Fullscreen); //creates fullscreen window
//Initialiseing the time
    gameClock.restart();    // start the GameClock
    sf::Time lastUpdate = sf::milliseconds(0);  // Initializes the last update to zero
    const sf::Time updateTime = sf::milliseconds(50);   //Time between two

    int i = 0;
    while (ScreenRoot::access().window ->isOpen()) //while the window is open
    {
        sf::Event event;
        while (ScreenRoot::access().window->pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::KeyPressed :
                {
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Escape:
                        {   ScreenRoot::access().window->close();
                            break;
                        }
                        default:
                        {
                            ///fill
                        }
                        ///more keycases (lower case, upper case...etc)
                    }

                break;
                }

                case sf::Event::MouseButtonPressed:
                {
                    if(sos.hit(sf::Mouse::getPosition()))
                    {
                        sos.getEvent(event);
                    }
                    break;
                }
                default:
                {
                    ///fill
                }
            }
        }

        //ScreenRoot::access().window->draw(sos.cs);

        if (gameClock.getElapsedTime() > lastUpdate + updateTime)
        {
            lastUpdate = gameClock.getElapsedTime();
            ScreenRoot::access().window->clear();
            ScreenRoot::access().draw();
            ScreenRoot::access().window->display();
        }



    }

    return 0;
}
