#include <SFML/Graphics.hpp>

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode(); //desktop resolution

    sf::RenderWindow window(desktop, "SFML Window", sf::Style::Fullscreen); //creates fullscreen window

    sf::CircleShape shape(300,100); ///test
    shape.setFillColor(sf::Color::Green); ///test

    while (window.isOpen()) //while the window is open
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        /**test*/window.clear(sf::Color::Black);
        /**test*/window.draw(shape);
        /**test*/window.display();
    }

    return 0;
}
