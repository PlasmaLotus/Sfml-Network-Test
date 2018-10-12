#ifndef __xXxSERVERxXx__
#define __xXxSERVERxXx__

#include <SFML/Network.hpp>
#include <map>
#include <vector>

class ClientInfo;
class Server
{
public:
	Server();
	virtual ~Server();


	/*
	std::map<uint32_t, ClientInfo> mClients;
	ClientInfo getClientInfo(uint32_t id);
	ClientInfo getClientInfo(sf::IpAddress, short port);
	uint32_t getClientID(std::string username);
	uint32_t getClientID(sf::IpAddress, short port);
	*/

	void run();
	void update();
	void handleIncomingPackets();
	void init();
	std::map<short, sf::UdpSocket*> mSocketMap;
	void send(const sf::Packet& packet);
	bool handleOutgoingPackets();
	std::vector<sf::Packet> pending_packets;


};



#endif