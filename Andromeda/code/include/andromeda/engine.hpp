#pragma once

#define ANDROMEDA_VERSION_MAJOR	1
#define ANDROMEDA_VERSION_MINOR	0
#define ANDROMEDA_VERSION_PATCH	0

#include <cstdint>

#include <andromeda/world.hpp>

namespace Andromeda
{
	class Engine
	{
	public:

		static Engine& Instance()
		{
			static Engine instance;
			return instance;
		}

		int Launch(int argc, char* argv[]/*callbacks*/);
		void ShouldStop() { m_shouldStop = true; }

	private:
		Engine();
		void Initilize();
		void Loop();
		void Shutdown();

		bool m_shouldStop;
		uint64_t m_frameCount;
	};
}
