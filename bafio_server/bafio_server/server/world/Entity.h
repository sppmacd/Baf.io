#pragma once

#include "../../stdafx.h"

class World;

class Entity
{
	Vector2f position;
public:
	Entity(World* world, string str = "undefinedEntity", Uint64 id = 0);

	Vector2f speed;
	Uint64 uuid;
	string type;
	World* owner;
	string name;

	virtual void update();
	virtual void onCreate();
	virtual void onDeath();
	Vector2f getPosition();
	void setPosition(Vector2f pos);
};