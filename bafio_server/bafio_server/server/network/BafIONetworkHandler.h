#pragma once

#include "../../stdafx.h"
#include "../world/Entity.h"
#include "event/BafIOEvent.h"

class BafIONetworkHandler
{
	map<Entity*, TcpSocket*> clients;
	TcpListener listener;
public:
	void loop();
	void load();
	void addPlayer(Entity* entity, TcpSocket* socket);

	void send(Entity* player, BafIOEvent& event);
	void send(string playerName, BafIOEvent& event);
	void sendToAll(BafIOEvent event);
};