#pragma once

#include <pulsar/logger.hpp>

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

#define PULSAR_ASSERT(condition, ...) Pulsar::assertModule.Assert(condition, #condition, " : ", __VA_ARGS__)

namespace Pulsar
{
	void AssertLogPrinter(std::ostream& outputStream, std::ostringstream& buffer)
	{
		std::time_t t = std::time(nullptr);
		outputStream << std::put_time(std::localtime(&t), "%d-%m-%Y.%X") << " Assert Fail : " << buffer.str() << std::endl;
	}

	class AssertModule
	{
	public:

		AssertModule()
		{
			m_logger.AddOutputStream(std::cerr, &AssertLogPrinter);
		}

		template<typename... Printables>
		void Assert(bool condition, Printables... printables)
		{
			if (!condition)
			{
				m_logger.Log(printables...);
				__debugbreak();
			}
		}

	private:

		Logger m_logger;
	};

	AssertModule assertModule;
}