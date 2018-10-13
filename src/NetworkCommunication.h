#ifndef _NETWORK_COMMUNICATION_
#define _NETWORK_COMMUNICATION_

#include <SFML\Network.hpp>

#define DEFAULT_BUFFER_SIZE 1024
#define NETWORK_DEFAULT_PORT 42069
#define NETWORK_DEFAULT_PORT2 42042

class NetworkCommunication
{
public:
	NetworkCommunication();
	virtual ~NetworkCommunication();

	char mBuffer[DEFAULT_BUFFER_SIZE];
	
	sf::UdpSocket mUdpSocket;
	std::size_t mRecievedLength;
	short mPort;
	short getRandomPort();
	bool init();
};

#endif // _NETWORK_COMMUNICATION_