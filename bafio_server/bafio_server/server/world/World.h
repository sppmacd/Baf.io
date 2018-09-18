#pragma once

#include "../../stdafx.h"
#include "Object.h"
#include "Entity.h"

// Class managing server World.
class World
{
	vector<Object> objects;
	vector<Entity> entities;
	const Vector2f size;

public:
	World();

	// Add obstacles etc etc
	void generate();

	// Adds the new entity
	void addEntity(Entity& entity);
	void addObject(Object& object);
	void update();
};