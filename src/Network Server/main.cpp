#include <SFML/Graphics.hpp>
#include <string.h>
#include <SFML\Network.hpp>
//SERVER

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);


	// SFML NETWORKL
	sf::IpAddress ipPublic{ sf::IpAddress::getPublicAddress() };
	sf::IpAddress ipLocal{ sf::IpAddress::getLocalAddress() };

	printf("Public IP: %s \n", ipPublic.toString().c_str());
	printf("Public IP: %s \n", ipLocal.toString().c_str());

	sf::IpAddress senderAdress{ sf::IpAddress::getPublicAddress() };
	sf::UdpSocket socket1;
	socket1.setBlocking(false);
	if (socket1.bind(42069) != sf::Socket::Done) {
		/// ERROR 
		printf("Error when binding socket1\n");

	}
	sf::UdpSocket socket2;
	socket1.setBlocking(false);
	if (socket2.bind(42069) != sf::Socket::Done) {
		/// ERROR 
		printf("Error when binding socket2\n");
	}


	//Sending PAcket/
	std::string s{ "LMAO!" };
	sf::Packet packet1;
	sf::Packet packet2;
	packet1 << s;

	if (socket1.send(packet1, sf::IpAddress::getLocalAddress(), 54000) != sf::Socket::Done) {

		printf("Error when Sending packet\n");

	}

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

		unsigned short port = 42069;
		if (socket2.receive(packet2, senderAdress, port) != sf::Socket::Done)
		{
			// error...
		}
		else {
			printf("Something was recieved\n");
		}


    }

    return 0;
}