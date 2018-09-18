#pragma once

#include "../../stdafx.h"

class Entity
{
public:
	Vector2f position;
	Vector2f speed;
	Uint64 uuid;

	void move();
	virtual void update();
	virtual void onCreate();
	virtual void onDeath();
};