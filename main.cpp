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
#include "scene.h"
#include "../koporso/Animation.h"

int main()
{
    initializeUtility();

    ShapeSO sos;

    Animation stickman("../koporso/Resources/Stickman",2,10,5);

    FixedGround fg(-500,1000,0,4344,704, "../koporso/Resources/fixedGround.jpg");

    Thing thing("../koporso/Resources/The_Thing.png",0,0,-1000);

    Creature creature1("../koporso/Resources/Creature.png", 30, 800, 2, 319, 308);

    Protagonist protagonist("../koporso/Resources/protagonist.png",1500, 600, 10, &fg);

    ///SimpleImage img("../koporso/Resources/lion.png",-100,-50,3);
    ///SimpleImage img2("../koporso/Resources/lion.png",100,100,5);
    ///ScreenRoot::access().addStaticSo(&img);
    ///ScreenRoot::access().addStaticSo(&img2);
    ScreenRoot::access().addStaticSo(&fg);
    ScreenRoot::access().addStaticSo(&thing);
    ScreenRoot::access().addDinamicSo(&protagonist);
    ScreenRoot::access().addDinamicSo(&creature1);
    //ScreenRoot::access().addStaticSo(stickman.get_current_frame());


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
                    if(sos.hit(sf::Mouse::getPosition()))
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
