#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

//CLIENT

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works! - CLIENT");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	printf("Client\n");
	unsigned short port = 50000;
	unsigned short serverPort = 42069;
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::UdpSocket socket;
	socket.bind(port, ip);
	//sf::Socket::Status::
	if (socket.bind(port, ip) != sf::Socket::Done) {
		/// ERROR 
		printf("Error when binding socket to port 42069\n");
	}
	else {
		//printf("Bind succesful\n");
	}

	socket.setBlocking(true);
	sf::Packet packet;
	packet << "LMAO";
	for (int i = 10; i >= 0; --i) {
		if (socket.send(packet, ip, serverPort) != sf::Socket::Done){
			printf("Error when sending packet");
		}
		else {
			printf("Packet was sent");
		}
	}
	
	sf::Packet packet2;
	packet2 << "LMAO";
	printf("\n");
	for (int i = 10; i >= 0; --i) {
		if (socket.send(packet2, ip, serverPort) != sf::Socket::Done) {
			printf("Error when sending packet");
		}
		else {
			printf("Packet was sent");
		}
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


    }

    return 0;
}