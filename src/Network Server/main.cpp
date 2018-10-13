#include <SFML/Graphics.hpp>
<<<<<<< HEAD
#include <string>
#include <SFML\Network.hpp>
#include <iostream>

=======
#include <string.h>
#include <SFML/Network.hpp>
>>>>>>> eb0a7963ca780d7942b8b3dd7267994876e00a85
//SERVER
<<<<<<< HEAD
//Blue

void checkConnection();

=======
#include "server.h"
>>>>>>> 0f12cd91332d68092fb9c3cf5bfd2c007872e337

void acceptNewConnection();
int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works! - SERVER");
    sf::CircleShape shape(100.f);
<<<<<<< HEAD
    shape.setFillColor(sf::Color::Blue);
<<<<<<< HEAD
	sf::Clock clock;
	sf::Time time;

	clock.restart();

=======
	unsigned short port = 42069;
	unsigned short remotePort = 80;
>>>>>>> eb0a7963ca780d7942b8b3dd7267994876e00a85
	// SFML NETWORKL
	sf::IpAddress ipPublic{ sf::IpAddress::getPublicAddress() };
	sf::IpAddress ipLocal{ sf::IpAddress::getLocalAddress() };
	printf("Server\n");
	printf("Public IP: %s \n", ipPublic.toString().c_str());
	printf("Local IP: %s \n", ipLocal.toString().c_str());

	sf::IpAddress senderAdress{ sf::IpAddress::getPublicAddress() };
	sf::UdpSocket socket1;
	socket1.setBlocking(false);
	if (socket1.bind(port, ipLocal) != sf::Socket::Done) {
		/// ERROR 
		printf("Error when binding socket1 to port %d\n", port);

	}
	else {
		printf("Binding to port %d complete\n", port);
	}
	sf::UdpSocket socket2;
	socket1.setBlocking(false);
<<<<<<< HEAD
	if (socket2.bind(420) != sf::Socket::Done) {
=======
	if (socket2.bind(42042) != sf::Socket::Done) {
>>>>>>> eb0a7963ca780d7942b8b3dd7267994876e00a85
		/// ERROR 
		printf("Error when binding socket2 to port 42042\n");
	}


	//Sending PAcket/
	std::string s{ "LMAO!" };
	sf::Packet packet1;
	sf::Packet packet2;
	packet1 << s;
	/*
	if (socket1.send(packet1, sf::IpAddress::getLocalAddress(), 54000) != sf::Socket::Done) {
		printf("Error when Sending packet\n");
	}
	*/

=======
   
	printf("Server\n");
	Server server;
	server.init();
>>>>>>> 0f12cd91332d68092fb9c3cf5bfd2c007872e337
	
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
		checkConnection();

		////////

		server.update();


    }

    return 0;
}

<<<<<<< HEAD
void checkConnection() {
=======
void acceptNewConnection() {
>>>>>>> eb0a7963ca780d7942b8b3dd7267994876e00a85

}