#pragma once

namespace Andromeda
{
	class World
	{
	public:
		static World& Instance()
		{
			static World instance;
			return instance;
		}

		void Initilize();
		void Shutdown();

	private:
		World();

		void LoadMap(const char* map);
	};
}
