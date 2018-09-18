#include "BafIOEvent.h"

map<EventType, BafIOEventHandlerFunc> BafIOEvent::eventHandlers;

void BafIOEvent::registerEventHandler(EventType type, BafIOEventHandlerFunc func)
{
	eventHandlers.insert(make_pair(type, func));
}

// Sets the event type.
void BafIOEvent::setEventType(EventType type)
{
	this->eventType = type;
}

// Retrieves the event type.
EventType BafIOEvent::getEventType()
{
	return this->eventType;
}

// Set argument to value.
void BafIOEvent::addOrSetArg(string name, string val)
{
	this->eventArgs.insert_or_assign(name, val);
}

// Remove event argument.
void BafIOEvent::removeArg(string name)
{
	this->eventArgs.erase(name);
}

// Retrieve argument value.
string BafIOEvent::getArg(string name)
{
	return this->eventArgs[name];
}

// Get handler for a event type.
BafIOEventHandlerFunc BafIOEvent::getHandler(EventType type)
{
	return eventHandlers[type];
}

// Parse event from packet.
BafIOEvent getFromPacket(Packet packet)
{
	EventType type;
	packet >> type;
	BafIOEvent event;
	event.setEventType(type);

	for (int i = 0; !packet.endOfPacket(); i++)
	{
		string s,t;
		packet >> s >> t;
		event.addOrSetArg(s,t);
	}

	return event;
}