#pragma once

#include "../../stdafx.h"
#include "Object.h"
#include "Entity.h"

// Class managing server World.
class World : public NonCopyable
{
	vector<Object> objects;
	vector<Entity> entities;

public:
	const Vector2f size;
	World();

	// Add obstacles etc etc
	void generate();

	// Adds the new entity
	void addEntity(Entity& entity);
	void addObject(Object& object);
	void update();
	void leftClick(Vector2f pos);
	void rightClick(Vector2f pos);
};