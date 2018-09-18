#include "BafIOServer.h"

BafIOServer* BafIOServer::instance;

void BafIOServer::pushEvent(BafIOEvent & event)
{
	Lock lock(eventMutex);
	clientEvents.push_back(event);
}

BafIOEvent BafIOServer::popEvent()
{
	Lock lock(eventMutex);
	BafIOEvent& event = clientEvents.back();
	clientEvents.pop_back();
	return event;
}

BafIOServer::BafIOServer()
	: networkThread(&BafIOServer::networkLoop, this)
{
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
	this->networkThread.launch();
	return true;
}

void BafIOServer::mainLoop()
{
	BafIOEvent event = this->popEvent();
}

void BafIOServer::networkLoop()
{
	while (this->running)
	{
		BafIOEvent event;
		this->pushEvent(event);
	}
}
