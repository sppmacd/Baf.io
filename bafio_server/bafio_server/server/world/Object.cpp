#include "Object.h"

Object::Object(World * world, string str, Uint64 id)
{
	this->owner = world;
	this->type = str;
	this->uuid = id;
}

void Object::update()
{
}

void Object::onCreate()
{
}

void Object::onUpgrade()
{
}

void Object::onDestroy()
{
}
