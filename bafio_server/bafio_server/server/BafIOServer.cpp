#include "BafIOServer.h"

BafIOServer* BafIOServer::instance;

void BafIOServer::pushEvent(BafIOEvent & event)
{
	Lock lock(eventMutex);
	clientEvents.push_back(event);
}

BafIOEvent BafIOServer::popEvent()
{
	if (!clientEvents.empty())
	{
		BafIOEvent event = clientEvents.back();
		clientEvents.pop_back();
		return event;
	}
	else
	{
		return BafIOEvent();
	}
}

BafIOServer::BafIOServer()
	: networkThread(&BafIOServer::networkLoop, this)
{
	cout << "Creating Server..." << endl;
	// Assign instance to this.
	instance = this;

	// Set running flag to true.
	running = true;
}

BafIOServer::~BafIOServer()
{
	this->networkThread.wait();
}

BafIOServer * BafIOServer::getInstance()
{
	return instance;
}

bool BafIOServer::isRunning()
{
	return this->running;
}

void BafIOServer::stop(int returnValue)
{
	cout << "Stopping server..." << endl;
	this->running = false;
	this->retval = returnValue;
}

int BafIOServer::getReturnValue()
{
	return this->retval;
}

bool BafIOServer::startNetworkThread()
{
	cout << "Starting network thread" << endl;
	this->networkThread.launch();
	return true;
}

void BafIOServer::mainLoop()
{
	// Network thread cannot add new events while processing existing, so we lock it.
	eventMutex.lock();
	for (;;)
	{
		BafIOEvent event = this->popEvent();

		// Break if the event array is empty
		if (event.getEventType() == 0)
			break;

		// Call event handler
		BafIOEvent::getHandler(event.getEventType())(event.getArgs());
	}
	eventMutex.unlock();

	// Update the world
	this->world.update();
}

void BafIOServer::networkLoop()
{
	while (this->running)
	{
		BafIOEvent event(1);
		this->pushEvent(event);
	}
}
