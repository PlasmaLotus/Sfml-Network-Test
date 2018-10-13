#ifndef __xXxSERVERxXx__
#define __xXxSERVERxXx__

<<<<<<< HEAD
#ifndef __SERVER__
#define __SERVER__

#include <map>
#include <SFML/Network.hpp>
=======
#include <SFML/Network.hpp>
#include <map>
#include <vector>
>>>>>>> 0f12cd91332d68092fb9c3cf5bfd2c007872e337

class ClientInfo;
class Server
{

public:
	Server();
	virtual ~Server();

<<<<<<< HEAD
	std::map<uint32_t, sf::IpAddress> mIPMapByUserID;
	void update();
};

#endif // __SERVER__
=======

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
>>>>>>> 0f12cd91332d68092fb9c3cf5bfd2c007872e337
