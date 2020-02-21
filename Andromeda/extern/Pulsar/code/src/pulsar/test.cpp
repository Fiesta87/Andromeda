#include <pulsar/test.hpp>

namespace Pulsar
{
	UnitTest::UnitTest(const char* name, TestModule* module)
		: m_name(name)
		, m_func(nullptr)
		, m_module(module)
		, m_testCount(0)
		, m_failureCount(0)
	{}

	void UnitTest::Run()
	{
		Logger().Log(MakeLogLevel(TestLogLevel::UnitTestStep),
			"		Start Unit Test ", m_name);

		m_func(this);

		Logger().Log(MakeLogLevel(TestLogLevel::UnitTestStep),
			"		End Unit Test ", m_name);

		Logger().Log(MakeLogLevel(TestLogLevel::UnitTestResult),
			"		Unit Test ", m_name, " result : ", m_failureCount, " tests failed out of ", m_testCount, " total tests");
	}

	Logger& UnitTest::Logger()
	{
		return m_module->Logger();
	}

	TestModule::TestModule(TestSuite* suite, const char* name)
		: m_suite(suite)
		, m_name(name)
		, m_testCount(0)
		, m_failureCount(0)
	{}

	void TestModule::Run()
	{
		Logger().Log(MakeLogLevel(TestLogLevel::ModuleStep),
			"	Start Test Module ", m_name);

		for (UnitTest test : m_tests)
		{
			test.Run();
			m_testCount += test.m_testCount;
			m_failureCount += test.m_failureCount;
		}

		Logger().Log(MakeLogLevel(TestLogLevel::ModuleStep),
			"	End Test Module ", m_name);

		Logger().Log(MakeLogLevel(TestLogLevel::ModuleResult),
			"	Module ", m_name, " result : ", m_failureCount, " tests failed out of ", m_testCount, " total tests");
	}

	Logger& TestModule::Logger()
	{
		return m_suite->Logger();
	}

	TestSuite::TestSuite(const char* name, TestLogLevel levels)
		: m_name(name)
		, m_testCount(0)
		, m_failureCount(0)
	{
		m_logger.AddOutputStream(std::cout, (LogLevel)levels, &DefaultPrinter);
	}

	void TestSuite::AddTestModule(TestModule& module)
	{
		m_modules.push_back(&module);
	}

	int TestSuite::Run()
	{
		Logger().Log(MakeLogLevel(TestLogLevel::SuiteStep),
			"Start Test Suite ", m_name);

		for (TestModule* module : m_modules)
		{
			module->Run();
			m_testCount += module->m_testCount;
			m_failureCount += module->m_failureCount;
		}

		Logger().Log(MakeLogLevel(TestLogLevel::SuiteStep),
			"End Test Suite ", m_name);

		Logger().Log(MakeLogLevel(TestLogLevel::SuiteResult),
			"Suite ", m_name, " result : ", m_failureCount, " tests failed out of ", m_testCount, " total tests");

		return m_failureCount;
	}

	Logger& TestSuite::Logger()
	{
		return m_logger;
	}
}