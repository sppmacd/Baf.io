#include "BafIONetworkHandler.h"
#include "../BafIOServer.h"

void BafIONetworkHandler::loop()
{
	// Create temporary socket used to check connect etc.
	TcpSocket* temp = new TcpSocket();

	// Handle connect
	Socket::Status status = listener.accept(*temp);

	switch (status)
	{
	case Socket::Done: //connected successfully
	{
		Uint8 uuid = BafIOServer::getInstance()->getWorld()->getNextUUID();
		Entity* player = new Entity(BafIOServer::getInstance()->getWorld(), "player", uuid);
		player->setPosition(Vector2f(rand() % 80 - 40, rand() % 80 - 40));
		BafIOServer::getInstance()->getWorld()->addEntity(*player);
		addPlayer(player, temp);
		BafIOEvent e1 = BafIOEvent(ServerEventType::RequestUserData);
		send(player, e1);
		send(player, BafIOServer::getInstance()->getWorld()->createEntityEvent(player));
		BafIOEvent e2 = BafIOEvent(ServerEventType::Chat);
		break;
	}
	case Socket::Disconnected:
		cout << "Error: the client was disconnected" << endl;
		break;
	case Socket::Error:
		cout << "Error: " << to_string(errno) << endl;
		break;
	default:
		break;
	}

	// handle received packets
	{
		Lock lock(BafIOServer::getInstance()->eventMutex);
		for (auto it = clients.begin(); it != clients.end(); it++)
		{
			TcpSocket* socket = it->second;
			Packet packet;
			status = socket->receive(packet);
			switch (status)
			{
			case Socket::Done:
				BafIOEvent& e = getEventFromPacket(packet);
				BafIOServer::getInstance()->pushEvent(e);
				break;
			}
		}
	}
}

void BafIONetworkHandler::load()
{
	listener.setBlocking(false);
	Socket::Status status = listener.listen(30450);

	if (status != Socket::Done)
		cout << "Listening error: " << status << endl;
}

void BafIONetworkHandler::addPlayer(Entity* entity, TcpSocket* socket)
{
	this->clients.insert(make_pair(entity, socket));
}
