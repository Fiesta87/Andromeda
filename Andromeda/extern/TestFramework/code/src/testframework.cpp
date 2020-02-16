#include <testframework.hpp>

namespace TestFramework
{
	UnitTest::UnitTest(const char* name, TestModule* module)
		: m_name(name)
		, m_func(nullptr)
		, m_module(module)
	{}

	int UnitTest::Run()
	{
		int failureCount = 0;
		m_func(failureCount, this);
		return failureCount;
	}

	Pulsar::Logger& UnitTest::Logger()
	{
		return m_module->Logger();
	}

	TestModule::TestModule(TestSuite* suite)
		: m_suite(suite)
	{}

	int TestModule::Run()
	{
		int result = 0;
		for (UnitTest test : m_tests)
		{
			result += test.Run();
		}
		return result;
	}

	Pulsar::Logger& TestModule::Logger()
	{
		return m_suite->Logger();
	}

	TestSuite::TestSuite()
	{
		m_logger.AddOutputStream(std::cout, &Pulsar::DefaultPrinter);
	}

	void TestSuite::AddTestModule(TestModule& module)
	{
		m_modules.push_back(&module);
	}

	int TestSuite::Run()
	{
		int result = 0;
		for (TestModule* module : m_modules)
		{
			result += module->Run();
		}
		return result;
	}

	Pulsar::Logger& TestSuite::Logger()
	{
		return m_logger;
	}
}