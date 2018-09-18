#pragma once

class Object
{
public:
	Vector2f position;
	Vector2f speed;
	Uint64 uuid;

	void move();
	virtual void update();
	virtual void onCreate();
	virtual void onUpgrade();
	virtual void onDestroy();
};