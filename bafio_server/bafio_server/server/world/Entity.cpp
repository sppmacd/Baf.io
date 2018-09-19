#include "Entity.h"

Entity::Entity(World* world, string str, Uint64 id)
{
	this->owner = world;
	this->type = str;
	this->uuid = id;
}

void Entity::update()
{
}

void Entity::onCreate()
{
}

void Entity::onDeath()
{
}

Vector2f Entity::getPosition()
{
	return this->position;
}

void Entity::setPosition(Vector2f pos)
{
	position = pos;
}
