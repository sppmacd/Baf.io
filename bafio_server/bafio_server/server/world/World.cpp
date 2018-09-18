#include "World.h"

World::World()
	: size(Vector2f(3000.f, 3000.f))
{

}

void World::generate()
{
	srand(time(NULL));
	for (int i = 0; i < sqrt(this->size.x*this->size.y) / 5; i++)
	{
		float locX = static_cast<float>(rand() % static_cast<int>(round(this->size.x)));
		float locY = static_cast<float>(rand() % static_cast<int>(round(this->size.y)));
		Object obj;
		obj.
		addObject();
	}
}
