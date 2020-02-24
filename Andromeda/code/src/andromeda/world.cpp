#include <andromeda/world.hpp>

#include <andromeda/config.hpp>

namespace Andromeda
{
	World::World()
	{

	}

	void World::Initilize()
	{
		LoadMap(Config::Instance().Get("map"));
	}

	void World::Shutdown()
	{

	}

	void World::LoadMap(const char* map)
	{

	}
}
