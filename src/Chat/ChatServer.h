#ifndef _CHAT_SERVER_
#define _CHAT_SERVER_

#include <SFML\Network.hpp>

#define DEFAULT_BUFFER_SIZE 8192
#define DEFAULT_PORT 42069
#define DEFAULT_SECONDARY_PORT 42042
#define TEST_IP_ADRESS
#include <list>
#include <map>

/*
	ChatServer();
	virtual ~ChatServer();
	sf::IpAddress ip;
	sf::TcpSocket tcpSocket;
	sf::UdpSocket udpSocket;
	short chatRoomID;
	std::string username;

	void connectToServer();
	void disconnectFromServer();
*/
class ChatServer
{
public:
	ChatServer();
	~ChatServer();
	std::map<std::string, int> mUserIDMap;
	std::list<sf::TcpSocket> mTcpSocketList;
	sf::IpAddress IPAdress{ sf::IpAddress::LocalHost };
	sf::TcpListener mTcpListener;
	sf::TcpSocket mTcpSocket;
	char mBuffer[DEFAULT_BUFFER_SIZE];
	sf::Packet mPacket;
	std::size_t mRecievedSize;
	void init();
	void update();
	int getUserID(std::string username);
	int getUserId(sf::IpAddress);
	std::list<std::string> chatMessageList;
};

#endif //_CHAT_SERVER_


class ChatMessage
{
public:
	ChatMessage();
	ChatMessage(std::string username, std::string message, sf::Time timestamp);
	~ChatMessage();

	std::string mUsername;
	sf::Time mTimeStamp;
	std::string mMessage;


	std::string message();
};