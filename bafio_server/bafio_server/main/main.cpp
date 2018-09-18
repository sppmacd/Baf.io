#include "../stdafx.h"
#include "../server/BafIOServer.h"

// Main function. Arguments are not used yet.
int main(int argCount, char* argVal[])
{
	// Parse arguments (coming soon)
	// Create Baf.io Server object
	BafIOServer serverInstance;

	// Start network thread;
	serverInstance.startNetworkThread();

	// Start main loop
	while (serverInstance.isRunning())
	{
		// Manage server stop in Escape key
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			serverInstance.stop();

		serverInstance.mainLoop();
	}

	return serverInstance.getReturnValue();
}