#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Photon
{
	class Window
	{
	public:
		static Window& Instance()
		{
			static Window instance;
			return instance;
		}

	private:
		Window();
	};
}
