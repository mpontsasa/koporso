#include <SFML/Graphics.hpp>
#include "../koporso/ShapeSO.h"

int main()
{
    ShapeSO sos;

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode(); //desktop resolution

    sf::RenderWindow window(desktop, "SFML Window", sf::Style::Fullscreen); //creates fullscreen window

    while (window.isOpen()) //while the window is open
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::KeyPressed :
                {
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Escape:
                        {   window.close();
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

    window.draw(sos.cs);
    window.display();
    }

    return 0;
}
