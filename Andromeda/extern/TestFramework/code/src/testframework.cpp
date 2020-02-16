#include <testframework.hpp>

#include <iostream>

#include <pulsar.hpp>

namespace TestFramework
{
	struct TestLogger
	{
		static uint64_t data;

		static void Print(std::ostream* os, const char* text)
		{
			*os << text << data << std::endl;
		}
	};
	uint64_t TestLogger::data = 42;

	void DoTestStuff()
	{
		Pulsar::Logger logger;

		TestLogger::data = 99;

		logger.AddOutputStream(&std::cout, &Pulsar::DefaultPrinter, &Pulsar::TimedPrinter,
			[](std::ostream* os, const char* text)
			{
				*os << text << text << std::endl;
			},
			&Pulsar::TimePrinter, &Pulsar::SeparatorPrinter, &Pulsar::DefaultPrinter,
			& TestLogger::Print);

		logger.Log("azertyuiop");
		TestLogger::data = 55;
		logger.Log("zozo");
	}
}