#include "World.h"
#include "../BafIOServer.h"

World::World()
	: size(Vector2f(3000.f, 3000.f))
{
	cout << "Creating world..." << endl;
}

void World::generate()
{
	cout << "Generating world..." << endl;

	srand(time(NULL));
	for (int i = 0; i < sqrt(this->size.x*this->size.y) / 5; i++)
	{
		float locX = static_cast<float>(rand() % static_cast<int>(round(this->size.x)));
		float locY = static_cast<float>(rand() % static_cast<int>(round(this->size.y)));
		Object obj(this, "obstacle", getNextUUID());
		obj.setPosition(Vector2f(locX, locY));
		addObject(obj);
	}
}

void World::addEntity(Entity & entity)
{
	entity.onCreate();
	
	int i = 0;
	for (Entity& e : entities)
	{
		if (e.uuid = entity.uuid)
		{
			entities[i] = e;
		}
		i++;
	}
	entities.push_back(entity);
}

void World::addObject(Object & object)
{
	object.onCreate();

	int i = 0;
	for (Object& o : objects)
	{
		if (o.uuid = object.uuid)
		{
			objects[i] = o;
		}
		i++;
	}
	objects.push_back(object);
}

Entity& World::getEntityByUUID(Uint64 uuid)
{
	for (Entity& e : entities)
	{
		if (e.uuid == uuid)
			return e;
	}
}

void World::update()
{
	// Update all objects and entities
	for (Object& o : objects)
		o.update();
	for (Entity& e : entities)
		e.update();
}

void World::leftClick(Vector2f pos)
{

}

Uint64 World::getNextUUID()
{
	return (objects.size() << 32) + entities.size() + 1;
}

BafIOEvent& World::createEntityEvent(Entity* entity)
{
	BafIOEvent event(ServerEventType::UpdateEntity);
	event["uuid"] = entity->uuid;
	event["posx"] = entity->getPosition().x;
	event["posy"] = entity->getPosition().y;
	event["spdx"] = entity->speed.x;
	event["spdy"] = entity->speed.y;
	event["type"] = entity->type;
	event["name"] = entity->name;
	return event;
}
