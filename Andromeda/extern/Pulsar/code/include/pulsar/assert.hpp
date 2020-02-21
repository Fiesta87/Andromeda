#pragma once

#include <pulsar/logger.hpp>

#include <stdexcept>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

#define PULSAR_ASSERT(condition, ...) \
if(!condition)\
{\
	Pulsar::g_assertLogger.LogCritical(#condition, " : ", __VA_ARGS__);\
	throw std::runtime_error("Assert fail.");\
}

#define PULSAR_SOFTASSERT(condition, ...) \
if(!condition)\
{\
	Pulsar::g_assertLogger.LogWarning(#condition, " : ", __VA_ARGS__);\
	__debugbreak();\
}

namespace Pulsar
{
	void AssertLogPrinter(std::ostream& outputStream, std::ostringstream& buffer)
	{
		std::time_t t = std::time(nullptr);
		outputStream << std::put_time(std::localtime(&t), "%d-%m-%Y.%X") << " Assert Fail : " << buffer.str() << std::endl;
	}

	void SoftAssertLogPrinter(std::ostream& outputStream, std::ostringstream& buffer)
	{
		std::time_t t = std::time(nullptr);
		outputStream << std::put_time(std::localtime(&t), "%d-%m-%Y.%X") << " Soft Assert Fail : " << buffer.str() << std::endl;
	}

	Logger g_assertLogger;

	struct AssertInitializer
	{
		AssertInitializer()
		{
			g_assertLogger.AddOutputStream(std::cerr, LogLevel::Critical, &AssertLogPrinter);
			g_assertLogger.AddOutputStream(std::cerr, LogLevel::Warning, &SoftAssertLogPrinter);
		}
	};

	AssertInitializer g_AssertInitializer;
}