#include "server.h"
#include <SFML/Network.hpp>


Server::Server()
{
}


Server::~Server()
{
	std::map<short, sf::UdpSocket*>::iterator it;
	for (it = mSocketMap.begin(); it != mSocketMap.end(); ++it) {
		if (it->second) {
			it->second->unbind();
			delete it->second;
		}
	
	}
	mSocketMap.clear();

}
void Server::run() {

}
void Server::update() {
	handleIncomingPackets();
	handleOutgoingPackets();
}
void Server::handleIncomingPackets()
{
	std::map<short, sf::UdpSocket*>::iterator it;
	for (it = mSocketMap.begin(); it != mSocketMap.end(); ++it) {
		sf::Packet packet;
		sf::IpAddress ip;
		unsigned short portIncoming;
		unsigned short port{ static_cast<unsigned short>(it->first) };
		sf::UdpSocket* socket{ it->second };
		sf::Socket::Status status = socket->receive(packet, ip, portIncoming);
		//socket->
		switch (status)
		{
		case sf::Socket::Partial:{
			printf("Socket %d has a partial packet\n", port);

			int ttl = 10;
			while (status != sf::Socket::Status::Partial &&  ttl >= 0) {
				status = socket->receive(packet, ip, portIncoming);
				--ttl;
			}
			printf("Partial packet on Socket %d after %d loops\n", port, 10-ttl);
			break;
		}
		case sf::Socket::Disconnected: {
			printf("Socket %d is Disconnected\n", port);
			break;
		}
		case sf::Socket::Error: {
			printf("Socket %d has experienced an error\n", port);
			break;
		}
		case sf::Socket::NotReady: {
			//printf("Socket %d isn't ready\n", port);
			break;
		}
		case sf::Socket::Done : {
			printf("Socket %d has revieved a packet: Port:%d, IP:%s\n", port, portIncoming, ip.toString().c_str());
		}
		default:
			break;
		}
		
	}
}

void Server::init()
{

	for (unsigned short i = 42042; i <= 42069; ++i) {
		sf::UdpSocket* socket{ new sf::UdpSocket };
		
		socket->setBlocking(false);
		sf::Socket::Status status = socket->bind(i, sf::IpAddress::getLocalAddress());
		//printf("Socket %d bind has returned %d\n", i, static_cast<int>(status));
		
		switch (status)
		{
		case sf::Socket::Partial: {
			printf("Socket %d bind has returned Partial\n", i);
			break;
		}
		case sf::Socket::Disconnected: {
			printf("Socket %d bind has returned Disconnected\n", i);
			break;
		}
		case sf::Socket::Error: {
			printf("Socket %d bind has returned Error\n", i);
			break;
		}
		case sf::Socket::NotReady: {
			printf("Socket %d bind has returned NotReady\n", i);

			break;
		}
		case sf::Socket::Done: {
			printf("Socket %d bind Success\n", i);

			break;
		}
		default:
			break;
		}

		mSocketMap[i] = socket;
	}


}

bool Server::handleOutgoingPackets()
{
	return false;
}
