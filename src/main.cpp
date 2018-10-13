#include <SFML/Graphics.hpp>

#include <future>
//#include <SFML\Graphics.hpp>

//Main

//#include "NetworkCommunication.h"
void debugFunction();
int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Magenta);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();





    }

	std::async(std::launch::async, debugFunction);
	std::thread t1(debugFunction);
	t1.

    return 0;
}

void debugFunction() {
	return;
}