#pragma once

#include "../stdafx.h"
#include "network/event/BafIOEvent.h"

// Base class to manage Baf.io Server

class BafIOServer
{
	// Default instance.
	static BafIOServer* instance;

	// Running flag.
	bool running;

	// Return value of the server.
	int retval;

	// Network thread object.
	Thread networkThread;

	// The World.
	World world;
public:
	// Event mutex.
	Mutex eventMutex;

	// Vector containing incoming client events.
	vector<BafIOEvent> clientEvents;

	// Adds the specified event to the event array.
	void pushEvent(BafIOEvent& event);

	// Deletes the last element of the event array and returns it.
	BafIOEvent popEvent();

	// Constructor.
	BafIOServer();

	// Destructor.
	~BafIOServer();

	// Get default instance of the Server
	static BafIOServer* getInstance();

	// Returns true if the server instance "running" flag is set to true.
	bool isRunning();

	// Stops the server and returns the specified value.
	void stop(int returnValue = 0);

	// Retrieves the return value of the server.
	int getReturnValue();

	// Starts the network thread
	bool startNetworkThread();

	// Starts the main loop (one repeat)
	void mainLoop();

	// Starts the network loop (full loop)
	void networkLoop();
};
