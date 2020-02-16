#pragma once

#include <vector>

#include <pulsar/logger.hpp>

#define TEST_BEGIN_TESTSUITE(suiteName)	TestFramework::TestSuite suiteName##TestSuite


#define TEST_END_TESTSUITE(suiteName)	return suiteName##TestSuite.Run();


#define TEST_BEGIN_TESTMODULE(moduleName) \
class moduleName##Tests : public TestFramework::TestModule\
{\
public:\
	moduleName##Tests(TestFramework::TestSuite* suite)\
		: TestFramework::TestModule(suite)\
	{


#define TEST_ADD_UNITTEST(testName) \
TestFramework::UnitTest test##testName(#testName, this);\
m_tests.push_back(test##testName);\
m_tests[m_tests.size()-1].m_func = [](int& test_failureCount, TestFramework::UnitTest* test_test)->void


#define TEST_END_TESTMODULE(moduleName)	\
	}\
};


#define TEST_ADD_TESTMODULE(moduleName, suiteName)	\
suiteName::moduleName##Tests moduleName##TestModule(&suiteName##TestSuite);\
suiteName##TestSuite.AddTestModule(moduleName##TestModule)


#define TestAssert(condition) \
if(!(condition))\
{\
	test_test->Logger().Log("Unit test assert fail : ", test_test->m_name, " : ", #condition);\
	test_failureCount++;\
}


namespace TestFramework
{
	class UnitTest;

	using UnitTestFunc = void (*) (int& failureCount, UnitTest* test);

	class TestModule;

	class UnitTest
	{
	public:
		UnitTest(const char* name, TestModule* module);
		int Run();
		Pulsar::Logger& Logger();
		const char* m_name;
		UnitTestFunc m_func;

	private:
		TestModule* m_module;
	};

	class TestSuite;

	class TestModule
	{
	public:
		TestModule(TestSuite* suite);
		int Run();
		Pulsar::Logger& Logger();

	protected:
		std::vector<UnitTest> m_tests;
		TestSuite* m_suite;
	};

	class TestSuite
	{
	public:
		TestSuite();
		void AddTestModule(TestModule& module);
		int Run();
		Pulsar::Logger& Logger();

	private:
		std::vector<TestModule*> m_modules;
		Pulsar::Logger m_logger;
	};
}