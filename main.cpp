#include <SFML/Graphics.hpp>
#include "../koporso/ShapeSO.h"
#include "../koporso/SimpleImage.h"

int main()
{
    ShapeSO sos;

    SimpleImage img("../koporso/Resources/BG.JPG",100,100,1);
    SimpleImage img2("../koporso/Resources/BG.JPG",300,300,2);

    ScreenRoot::access().addStaticSo(&img);
    ScreenRoot::access().addStaticSo(&img2);

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode(); //desktop resolution

    ScreenRoot::access().window = new sf::RenderWindow(desktop, "SFML Window", sf::Style::Fullscreen); //creates fullscreen window

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

    ScreenRoot::access().window->clear();
    //ScreenRoot::access().window->draw(sos.cs);
    //img.drawThis();
    //img2.drawThis();

    ScreenRoot::access().draw();

    ScreenRoot::access().window->display();

    }

    return 0;
}
