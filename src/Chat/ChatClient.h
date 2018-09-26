#ifndef _CHAT_CLIENT_
#define _CHAT_CLIENT_

#include <SFML\Network.hpp>

#define DEFAULT_BUFFER_SIZE 8192
#define DEFAULT_PORT 42069
#define DEFAULT_SECONDARY_PORT 42042
#include <list>

class ChatClient
{
public:
	ChatClient();
	virtual ~ChatClient();
	sf::IpAddress ip;
	sf::TcpSocket tcpSocket;
	sf::UdpSocket udpSocket;
	short chatRoomID;
	std::string username;

	void init();

	void connectToServer();
	void disconnectFromServer();
	void update();


	std::list<std::string> chatMessageList;
};

#endif //_CHAT_CLIENT_