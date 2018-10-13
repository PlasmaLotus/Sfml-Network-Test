
#ifndef __SERVER__
#define __SERVER__

#include <map>
#include <SFML/Network.hpp>

class ClientInfo;
class Server
{

public:
	Server();
	virtual ~Server();

	std::map<uint32_t, sf::IpAddress> mIPMapByUserID;
	void update();
};

#endif // __SERVER__
