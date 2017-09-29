#include <SFML/Graphics.hpp>
#include <string>
#include "../koporso/ShapeSO.h"
#include "../koporso/SimpleImage.h"
#include "../koporso/Creature.h"
#include "../koporso/Thing.h"
#include "../koporso/Protagonist.h"
#include "gameview.h"
#include "utility.h"
#include "fixedground.h"
#include "Background.h"
#include "../koporso/Animation.h"
#include "../koporso/TestingAnimation.h"
#include "sceneHandler.h"
#include "ScreenRoot.h"

int main()
{

    initializeUtility();


    ShapeSO sos;

  /*  FixedGround fg("../koporso/Resources/fixedGround.jpg",-5000,1000,0,10880,696);

    //Thing thing("../koporso/Resources/The_Thing.png",0,0,-1000);
    Creature thing("../koporso/Resources/The_Thing.png", 0, 0, -1000, 1977, 1939);

    Creature creature1("../koporso/Resources/Creature.png", 30, 800, 2, 319, 308);



    Background background("../koporso/Resources/background.jpg", 0, 0, -10000, 0.2);


    ScreenRoot::access().addBackground(&background);
    ScreenRoot::access().addStaticSo(&fg);
    ScreenRoot::access().addStaticSo(&thing);
    ScreenRoot::access().addStaticSo(&creature1);
    ///test junk being added


*/



///loadFileFromScene will call ScreenRoot::WipeRoot() and wipe junk
///then load all objects from file except the protagonist
    loadSceneFromFile("../koporso/Resources/fileLoadTest.txt");

    Protagonist protagonist("../koporso/Resources/protagonist.png",1500, 600, 10, (ScreenRoot::access()).theGround);
    ScreenRoot::access().addDinamicSo(&protagonist);

// Initializing the screen
    ScreenRoot::access().window = new sf::RenderWindow(desktop, "SFML Window", sf::Style::Fullscreen); //creates fullscreen window

    ScreenRoot::access().window->setView(gameView.view);

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
                        case sf::Keyboard::Escape :
                        {
                            ScreenRoot::access().window->close();
                            break;
                        }
                        case sf::Keyboard::Right :
                        {
                            protagonist.getEvent(event);
                            break;
                        }
                        case sf::Keyboard::Left :
                        {
                            protagonist.getEvent(event);
                            break;
                        }
                        case sf::Keyboard::Up :
                        {
                            protagonist.getEvent(event);
                            break;
                        }
                        case sf::Keyboard::Down :
                        {
                            protagonist.getEvent(event);
                            break;
                        }
                        default:
                        {
                            ///fill
                        }
                        ///more keycases (lower case, upper case...etc) /// HA-HA
                    }

                break;
                }
                case sf::Event::MouseButtonPressed:
                {
                    if(sos.hit(sf::Mouse::getPosition()))   ///test
                    {
                        sos.getEvent(event);
                    }
                    break;
                }
                case sf::Event::KeyReleased:
                {
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Escape:
                        {   ScreenRoot::access().window->close();
                            break;
                        }
                        case sf::Keyboard::Right :
                        {
                            protagonist.getEvent(event);
                            break;
                        }
                        case sf::Keyboard::Left :
                        {
                            protagonist.getEvent(event);
                            break;
                        }
                        case sf::Keyboard::Up :
                        {
                            protagonist.getEvent(event);
                            break;
                        }
                        case sf::Keyboard::Down :
                        {
                            protagonist.getEvent(event);
                            break;
                        }
                        default:
                        {
                            ///fill
                        }
                        ///more keycases (lower case, upper case...etc) /// HA-HA
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

            ScreenRoot::access().window->clear();
            ScreenRoot::access().draw();
            ScreenRoot::access().window->display();
            lastUpdate = gameClock.getElapsedTime();

        }

    }

    return 0;
}
