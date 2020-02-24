#include <andromeda/engine.hpp>

#include <andromeda/config.hpp>
#include <andromeda/world.hpp>
#include <photon/window.hpp>

namespace Andromeda
{
	Engine::Engine()
		: m_shouldStop(false)
		, m_frameCount(0)
	{

	}

	int Engine::Launch(int argc, char* argv[]/*callbacks*/)
	{
		Config::Instance().AddCmdLineArgs(argc, argv);
		Initilize();
		Loop();
		Shutdown();
		return 0;
	}

	void Engine::Initilize()
	{
		World::Instance().Initilize();
		Photon::Window::Instance();
	}

	void Engine::Loop()
	{
		while (!m_shouldStop)
		{
			// get input
			// update gameplay
			// update physics
			// draw world
			// draw UI
			m_frameCount++;
			if (m_frameCount > 10)
			{
				ShouldStop();
			}
		}
	}

	void Engine::Shutdown()
	{
		World::Instance().Shutdown();
	}
}
