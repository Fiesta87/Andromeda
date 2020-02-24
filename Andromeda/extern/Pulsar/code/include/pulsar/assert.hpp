#pragma once

#include <pulsar/logger.hpp>

#include <stdexcept>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

#define PULSAR_ASSERT(condition, ...) \
if(!(condition))\
{\
	Pulsar::Assert::Logger().LogCritical(#condition, " : ", __VA_ARGS__);\
	throw std::runtime_error("Assert fail.");\
}

#define PULSAR_SOFTASSERT(condition, ...) \
if(!(condition))\
{\
	Pulsar::Assert::Logger().LogWarning(#condition, " : ", __VA_ARGS__);\
	__debugbreak();\
}

namespace Pulsar
{
	class Assert
	{
	public:
		static Logger& Logger()
		{
			static Pulsar::Logger logger;
			static bool initilized = false;
			if (!initilized)
			{
				//logger.AddOutputStream(std::cerr, LogLevel::Critical, [](std::ostream& outputStream, std::ostringstream& buffer) {Assert::AssertLogPrinter(outputStream, buffer); });
				logger.AddOutputStream(std::cerr, LogLevel::Critical, &Assert::AssertLogPrinter);
				logger.AddOutputStream(std::cerr, LogLevel::Warning, &Assert::SoftAssertLogPrinter);
				initilized = true;
			}
			return logger;
		}

		static void AssertLogPrinter(std::ostream& outputStream, std::ostringstream& buffer)
		{
			std::time_t t = std::time(nullptr);
			outputStream << std::put_time(std::localtime(&t), "%d-%m-%Y.%X") << " Assert Fail : " << buffer.str() << std::endl;
		}

		static void SoftAssertLogPrinter(std::ostream& outputStream, std::ostringstream& buffer)
		{
			std::time_t t = std::time(nullptr);
			outputStream << std::put_time(std::localtime(&t), "%d-%m-%Y.%X") << " Soft Assert Fail : " << buffer.str() << std::endl;
		}
		
	};
}
