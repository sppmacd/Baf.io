#pragma once

#include "../../stdafx.h"

class World;

class Object : public Transformable
{
	Vector2f position;
public:
	Object(World* world, string str = "undefinedObject", Uint64 id = 0);

	Vector2f speed;
	Uint64 uuid;
	World* owner;
	string type;

	virtual void update();
	virtual void onCreate();
	virtual void onUpgrade();
	virtual void onDestroy();
	Vector2f getPosition();
	void setPosition(Vector2f pos);
};