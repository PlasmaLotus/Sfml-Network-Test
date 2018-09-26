#ifndef _NETWORK_COMMUNICATION_
#define _NETWORK_COMMUNICATION_

#include <SFML\Network.hpp>

#define DEFAULT_BUFFER_SIZE 1024

class NetworkCommunication
{
public:
	NetworkCommunication();
	virtual ~NetworkCommunication();

	char mBuffer[DEFAULT_BUFFER_SIZE];
	int mPort;
	sf::UdpSocket mUdpSocket;
	std::size_t mRecievedLength;

};

#endif // _NETWORK_COMMUNICATION_