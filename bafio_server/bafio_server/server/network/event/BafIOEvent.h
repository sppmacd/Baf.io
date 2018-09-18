#pragma once

#include "../../../stdafx.h"

// Some typedefs.
typedef bool(*BafIOEventHandlerFunc)(map<string, string> args);
typedef Uint32 EventType;

class BafIOEvent
{
	// The type of the event.
	EventType eventType;
	map<string, string> eventArgs;
	static map<EventType, BafIOEventHandlerFunc> eventHandlers;

public:
	// Constructor
	BafIOEvent(EventType type = 0);

	// Adds the Event Handler to registry.
	static void registerEventHandler(EventType type, BafIOEventHandlerFunc func);

	// Sets the event type.
	void setEventType(EventType type);

	// Retrieves the event type.
	EventType getEventType();

	// Set argument to value.
	void addOrSetArg(string name, string val);

	// Remove event argument.
	void removeArg(string name);

	// Retrieve argument value.
	string getArg(string name);

	// Get handler for a event type.
	static BafIOEventHandlerFunc getHandler(EventType type);

	// Return args array.
	map<string, string> getArgs();
};

BafIOEvent getFromPacket(Packet packet);