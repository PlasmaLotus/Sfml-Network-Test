#include <SFML/Graphics.hpp>
#include <string.h>
#include <SFML/Network.hpp>
//SERVER


void acceptNewConnection();
int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works! - SERVER");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);
	unsigned short port = 42069;
	unsigned short remotePort = 80;
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
	if (socket2.bind(42042) != sf::Socket::Done) {
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

		acceptNewConnection();
		//socket1.setBlocking(false);
		if (socket1.receive(packet1, senderAdress, remotePort) != sf::Socket::Done)
		{
			// error...
			//printf("Error?\n");
		}
		else {
			printf("Something was recieved on socket1\n");
			packet1 = sf::Packet();
			//
		}

		


    }

    return 0;
}

void acceptNewConnection() {

}