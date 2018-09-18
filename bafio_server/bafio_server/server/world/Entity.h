#pragma once

#include "../../stdafx.h"

class Entity : public Transformable
{
public:
	Entity(World* world, string str = "undefinedEntity", Uint64 id = 0);

	Vector2f speed;
	Uint64 uuid;
	string type;
	World* owner;

	virtual void update();
	virtual void onCreate();
	virtual void onDeath();
};