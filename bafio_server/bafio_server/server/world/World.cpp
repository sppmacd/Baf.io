#include "World.h"

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
		Object obj(this, "obstacle", objects.size()+1);
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

void World::update()
{
	// Update all objects and entities
	for (Object& o : objects)
		o.update();
	for (Entity& e : entities)
		e.update();
}
