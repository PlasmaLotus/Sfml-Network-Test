#include <SFML/Graphics.hpp>
#include <string.h>
#include <SFML/Network.hpp>
//SERVER
#include "server.h"

void acceptNewConnection();
int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works! - SERVER");
    sf::CircleShape shape(100.f);
   
	printf("Server\n");
	Server server;
	server.init();
	
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

		////////

		server.update();


    }

    return 0;
}

void acceptNewConnection() {

}