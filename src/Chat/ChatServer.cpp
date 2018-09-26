#include "ChatServer.h"



ChatServer::ChatServer()
{
}


ChatServer::~ChatServer()
{
}

void ChatServer::init()
{
	mTcpSocket.setBlocking(false);
	mTcpListener.listen(DEFAULT_PORT);
	mTcpListener.accept(mTcpSocket);
}

void ChatServer::update()
{
	mTcpSocket.getRemoteAddress();
	mTcpSocket.receive(mPacket);
	//for
	//sf::
	//if(mPacket.
}
