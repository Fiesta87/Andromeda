#include <testframework.hpp>

#include <iostream>

#include <pulsar/assert.hpp>

namespace TestFramework
{
	struct TestLogger
	{
		static uint64_t data;

		static void Print(std::ostream& outputStream, std::ostringstream& buffer)
		{
			outputStream << buffer.str() << data << std::endl;
		}
	};
	uint64_t TestLogger::data = 42;

	void DoTestStuff()
	{
		/*Pulsar::Logger logger;

		TestLogger::data = 99;

		logger.AddOutputStream(std::cout, &Pulsar::DefaultPrinter, &Pulsar::TimedPrinter,
			[](std::ostream& outputStream, std::ostringstream& buffer)
			{
				outputStream << buffer.str() << buffer.str() << std::endl;
			},
			&Pulsar::TimePrinter, &Pulsar::SeparatorPrinter, &Pulsar::DefaultPrinter,
			& TestLogger::Print);

		logger.Log("azertyuiop");
		TestLogger::data = 55;
		logger.Log("zozo");

		logger.AddOutputStream(std::cout, &Pulsar::DefaultPrinter);

		logger.Log("test ", 1, " Hiya !!! ", 5.68f);
		logger.Log("Pour le plaisir ! ", 42);

		for (int i = 0; i < 10000; i++)
		{
			logger.Log("Perf test : ", i);
		}
		__debugbreak();*/

		/*Pulsar::AssertModule assertModule;

		assertModule.Assert(false, "assert test, ", "yolo ", 42);*/

		PULSAR_ASSERT(false, "assert test, ", "yolo ", 42);
	}
}